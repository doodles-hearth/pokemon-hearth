#include "global.h"
#include "data.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "event_scripts.h"
#include "field_screen_effect.h"
#include "global.fieldmap.h"
#include "overworld.h"
#include "pokemon.h"
#include "random.h"
#include "follower_helper.h"
#include "field_camera.h"
#include "field_weather.h"
#include "script_pokemon_util.h"
#include "string_util.h"
#include "constants/event_objects.h"
#include "constants/abilities.h"
#include "constants/flags.h"
#include "constants/maps.h"
#include "constants/species.h"
#include "constants/vars.h"

// Used for storing conditional emotes
struct SpecialEmote
{
    u16 index;
    u8 emotion;
};

static void TryShowPlayerPokemonAtCampfire(void);
u8 GetCampfirePokemonLocalId(u8 campfireIndex);
const u8 *GetRandomCampfireScriptForPokemon(struct Pokemon *mon, struct ObjectEvent *objEvent);
static void TryRemoveCampfireObjects(void);

/**
 * Determines whether a Campfire is currently active.
 */
bool8 CampfireIsActive(void)
{
    return !FlagGet(FLAG_HIDE_CAMPFIRE_PARTY_MON_1);
}

/**
 * Heals and places the player's party around the campfire.
 */
void RestAtCampfire(void)
{
    FlagSet(OW_FLAG_PAUSE_TIME);
    HealPlayerParty();
    TryShowPlayerPokemonAtCampfire();
    DrawWholeMapView();

    // Moving player north of the campfire, facing down
    u8 mapGroup = gSaveBlock1Ptr->location.mapGroup;
    u8 mapNum = gSaveBlock1Ptr->location.mapNum;
    u8 warpId = WARP_ID_NONE;

    u32 pX = gSaveBlock1Ptr->pos.x;
    u32 pY = gSaveBlock1Ptr->pos.y;

    switch (gSpecialVar_Facing)
    {
    case DIR_EAST:
        pX += 1;
        pY -= 1;
        break;
    case DIR_NORTH:
        pY -= 2;
        break;
    case DIR_WEST:
        pX -= 1;
        pY -= 1;
        break;
    }

    SetWarpDestination(mapGroup, mapNum, warpId, pX, pY);
    DoDiveWarp();
    ResetInitialPlayerAvatarState();

    // Hide follower
    FlagSet(FLAG_TEMP_HIDE_FOLLOWER);
    UpdateFollowingPokemon();

    gSaveBlock1Ptr->campfire.x = pX;
    gSaveBlock1Ptr->campfire.y = pY + 1;

    // TODO EVA: slightly increase the friendship of the whole party? Or create another function that increases
    //  the friendship of one Pokémon when given some item like a marshmallow?
    return;
}

static void TryShowPlayerPokemonAtCampfire(void)
{
    // Placing player's Pokémon in the field (VAR_OBJ_GFX_ID_A to F)
    for (s32 i = 0; i < PARTY_SIZE; i++)
    {
        u8 localId;
        const u8 *script;
        u32 specGfx;
        bool32 shiny;
        bool32 female;
        struct ObjectEvent *pokemonObjEvent;
        GetMonInfo(&gPlayerParty[i], &specGfx, &shiny, &female);

        if (specGfx == SPECIES_NONE || specGfx == SPECIES_EGG)
            continue;

        // Displaying object event
        FlagClear(FLAG_HIDE_CAMPFIRE_PARTY_MON_1 + i);

        // Assemble gfx ID like FollowerSetGraphics
        specGfx = specGfx + OBJ_EVENT_MON;
        if (shiny)
            specGfx += OBJ_EVENT_MON_SHINY;
        if (female)
            specGfx += OBJ_EVENT_MON_FEMALE;
        VarSet((VAR_OBJ_GFX_ID_A + i), (u16)specGfx);
        DebugPrintfLevel(MGBA_LOG_WARN, "loading Pokémon %d: %d", i, specGfx);

        localId = GetCampfirePokemonLocalId(i);
        if (localId)
        {
            pokemonObjEvent = &gObjectEvents[GetObjectEventIdByLocalIdAndMap(localId, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup)];
            script = GetRandomCampfireScriptForPokemon(&gPlayerParty[i], pokemonObjEvent);
            if (script != EventScript_FollowerEnd)
                OverrideObjectEventTemplateScript(pokemonObjEvent, script);
        }
    }
}

u8 GetCampfirePokemonLocalId(u8 campfireIndex)
{
    u8 i;

    for (i = 0; i < gMapHeader.events->objectEventCount; i++)
    {
        if (gMapHeader.events->objectEvents[i].flagId == FLAG_HIDE_CAMPFIRE_PARTY_MON_1 + campfireIndex)
        {
            return gMapHeader.events->objectEvents[i].localId;
        }
    }

    return 0;
}

const u8 *GetRandomCampfireScriptForPokemon(struct Pokemon *mon, struct ObjectEvent *objEvent)
{
    u32 species;
    s32 multi;
    struct SpecialEmote condEmotes[16] = {0};
    const u8 *basicScript = EventScript_FollowerEnd;
    u32 condCount = 0;
    u32 emotion;
    u8 emotion_weight[FOLLOWER_EMOTION_LENGTH] =
    {
        [FOLLOWER_EMOTION_HAPPY] = 10,
        [FOLLOWER_EMOTION_NEUTRAL] = 15,
        [FOLLOWER_EMOTION_SAD] = 5,
        [FOLLOWER_EMOTION_UPSET] = 15,
        [FOLLOWER_EMOTION_ANGRY] = 15,
        [FOLLOWER_EMOTION_PENSIVE] = 15,
        [FOLLOWER_EMOTION_LOVE] = 0,
        [FOLLOWER_EMOTION_SURPRISE] = 10,
        [FOLLOWER_EMOTION_CURIOUS] = 10,
        [FOLLOWER_EMOTION_MUSIC] = 15,
        [FOLLOWER_EMOTION_POISONED] = 0,
    };
    u32 i, j;
    bool32 pickedCondition = FALSE;
    species = GetMonData(mon, MON_DATA_SPECIES);
    multi = GetMonData(mon, MON_DATA_FRIENDSHIP);
    GetMonData(mon, MON_DATA_NICKNAME, gStringVar1);
    // Damn, guess your Pokémon really hates you huh
    if (multi < 80)
    {
        emotion_weight[FOLLOWER_EMOTION_HAPPY] = 5;
        emotion_weight[FOLLOWER_EMOTION_UPSET] = 20;
        emotion_weight[FOLLOWER_EMOTION_ANGRY] = 20;
        emotion_weight[FOLLOWER_EMOTION_PENSIVE] = 20;
        emotion_weight[FOLLOWER_EMOTION_MUSIC] = 5;
    }
    // Your Pokémon kinda likes you
    if (multi > 100)
    {
        emotion_weight[FOLLOWER_EMOTION_HAPPY] = 20;
        emotion_weight[FOLLOWER_EMOTION_UPSET] = 5;
        emotion_weight[FOLLOWER_EMOTION_ANGRY] = 5;
        emotion_weight[FOLLOWER_EMOTION_LOVE] = 20;
        emotion_weight[FOLLOWER_EMOTION_MUSIC] = 20;
    }
    // Your Pokémon likes you
    if (multi > 170)
    {
        emotion_weight[FOLLOWER_EMOTION_HAPPY] = 30;
        emotion_weight[FOLLOWER_EMOTION_LOVE] = 30;
    }

    // Health & status-related
    multi = SAFE_DIV(mon->hp * 100, mon->maxHP);
    if (multi < 20)
    {
        emotion_weight[FOLLOWER_EMOTION_SAD] = 30;
        condEmotes[condCount++] = (struct SpecialEmote) {.emotion = FOLLOWER_EMOTION_SAD, .index = 4};
        condEmotes[condCount++] = (struct SpecialEmote) {.emotion = FOLLOWER_EMOTION_SAD, .index = 5};
    }
    if (multi < 50 || mon->status & STATUS1_PARALYSIS)
    {
        emotion_weight[FOLLOWER_EMOTION_SAD] = 30;
        condEmotes[condCount++] = (struct SpecialEmote) {.emotion = FOLLOWER_EMOTION_SAD, .index = 6};
    }

    emotion = RandomWeightedIndex(emotion_weight, FOLLOWER_EMOTION_LENGTH);
    if ((mon->status & STATUS1_PSN_ANY) && GetMonAbility(mon) != ABILITY_POISON_HEAL)
        emotion = FOLLOWER_EMOTION_POISONED;

    // roll for basic/unconditional message
    multi = Random() % gFollowerBasicMessages[emotion].length;
    // (50% chance) Select special condition using reservoir sampling
    for (i = (Random() & 1) ? condCount : 0, j = 1; i < condCount; i++)
    {
        if (condEmotes[i].emotion == emotion && (Random() < 0x10000 / (j++)))  // Replace each item with 1/j chance
            multi = condEmotes[i].index;
    }
    // (50% chance) Match *scripted* conditional messages, from follower_helper.c
    for (i = (Random() & 1) ? COND_MSG_COUNT : 0, j = 1; i < COND_MSG_COUNT; i++)
    {
        const struct FollowerMsgInfoExtended *info = &gFollowerConditionalMessages[i];
        if (!CheckMsgInfo(info, mon, species, objEvent))
            continue;

        // replace choice with weight/j chance
        if (Random() < (0x10000 / (j++)) * (info->weight ? info->weight : 1))
        {
            multi = i;
            pickedCondition = TRUE;
        }
    }

    // 50/50 whether to use a basic follower message, or the location based (default) script
    if (Random() % 2)
        basicScript = gFollowerBasicMessages[emotion].script;

    // condition message was chosen
    if (pickedCondition)
    {
        emotion = gFollowerConditionalMessages[multi].emotion;
        return gFollowerConditionalMessages[multi].script ? gFollowerConditionalMessages[multi].script : basicScript;
    }
    // otherwise, a basic or C-based message was picked
    return gFollowerBasicMessages[emotion].messages[multi].script ? gFollowerBasicMessages[emotion].messages[multi].script : basicScript;
}

bool8 MovedTooFarFromCampfire(u16 x, u16 y)
{
    u32 campX = gSaveBlock1Ptr->campfire.x;
    u32 campY = gSaveBlock1Ptr->campfire.y;
    return x > campX + 3 || x < campX - 3 || y > campY + 3 || y < campY - 3;
}

void LeaveCampfire(void)
{
    // Resume RTC
    FlagClear(OW_FLAG_PAUSE_TIME);

    // Hide campfire objects
    FlagSet(FLAG_HIDE_CAMPFIRE_PARTY_MON_1);
    FlagSet(FLAG_HIDE_CAMPFIRE_PARTY_MON_2);
    FlagSet(FLAG_HIDE_CAMPFIRE_PARTY_MON_3);
    FlagSet(FLAG_HIDE_CAMPFIRE_PARTY_MON_4);
    FlagSet(FLAG_HIDE_CAMPFIRE_PARTY_MON_5);
    FlagSet(FLAG_HIDE_CAMPFIRE_PARTY_MON_6);

    // Display follower
    FlagClear(FLAG_TEMP_HIDE_FOLLOWER);
    UpdateFollowingPokemon();

    // Erase campfire coords
    gSaveBlock1Ptr->campfire.x = 0;
    gSaveBlock1Ptr->campfire.y = 0;
    
    TryRemoveCampfireObjects();
}

static void TryRemoveCampfireObjects(void)
{
    struct ObjectEventTemplate *template;

    if (gMapHeader.events != NULL)
    {
        for (u32 i = 0; i < gMapHeader.events->objectEventCount; i++)
        {
            template = &gSaveBlock1Ptr->objectEventTemplates[i];
            if (FlagGet(template->flagId))
            {
                RemoveObjectEventByLocalIdAndMap(template->localId, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
            }
        }
    }
}

void Native_Campfire(void)
{
    RestAtCampfire();
}

void Native_LeaveCampfire(void)
{
    LeaveCampfire();
}
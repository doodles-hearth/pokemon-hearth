#include "global.h"
#include "campfire.h"
#include "data.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "event_scripts.h"
#include "field_screen_effect.h"
#include "global.fieldmap.h"
#include "overworld.h"
#include "palette.h"
#include "pokemon.h"
#include "random.h"
#include "follower_helper.h"
#include "field_camera.h"
#include "field_weather.h"
#include "fieldmap.h"
#include "script_pokemon_util.h"
#include "string_util.h"
#include "sound.h"
#include "task.h"
#include "constants/event_objects.h"
#include "constants/abilities.h"
#include "constants/flags.h"
#include "constants/maps.h"
#include "constants/species.h"
#include "constants/songs.h"
#include "constants/vars.h"

EWRAM_DATA const u8 *gSavedFollowerMessagePtr = NULL;
static const u8 EventScript_CampfireMessageNone[] = _("");
static const s8 sFacingOffset[5][2] =
{
    [DIR_NONE]  = { 0,  0 },
    [DIR_SOUTH] = { 0,  1 },
    [DIR_NORTH] = { 0, -1 },
    [DIR_WEST]  = { 1,  0 },
    [DIR_EAST]  = { -1, 0 },
};

struct CampfireDailyEvents
{
    s8 mapGroup;
    s8 mapNum;
    u16 campfireVar;
};

const struct CampfireDailyEvents sCampfireDailyEvents[CAMPFIRE_COUNT] =
{
    [CAMPFIRE_GINKO_WOODS] =
    {
        .mapGroup = MAP_GROUP(MAP_GINKO_WOODS),
        .mapNum = MAP_NUM(MAP_GINKO_WOODS),
        .campfireVar = VAR_GINKO_WOODS_CAMPFIRE,
    },
};

struct CampfirePartyMonEvent
{
    const u8 *script;
    u8 emotion;
    u16 item;
};

const struct CampfirePartyMonEvent sCampfirePartyMonEvents[CAMPFIRE_EVENT_COUNT] =
{
    [CAMPFIRE_EVENT_1] = 
    {
        .script = EventScript_PokemonGaveYouAnItem,
        .emotion = MOVEMENT_ACTION_EMOTE_HEART,
        .item = ITEM_HEART_SCALE,
    },
    [CAMPFIRE_EVENT_2] = 
    {
        .script = EventScript_PokemonGaveYouAnItem,
        .emotion = MOVEMENT_ACTION_EMOTE_MUSIC,
        .item = ITEM_THROAT_SPRAY,
    }
};

struct CampfireEncounterEvent
{
    const u8 *script;
    u16 graphicsId;
};

const struct CampfireEncounterEvent sCampfireFriendlyEncounter[CAMPFIRE_EVENT_COUNT] =
{
    [CAMPFIRE_EVENT_1] = 
    {
        .script = EventScript_OldForagingBloke,
        .graphicsId = OBJ_EVENT_GFX_MOUNTAIN_OLD_MAN,
    },
    [CAMPFIRE_EVENT_2] = 
    {
        .script = EventScript_PokemonHandsYouAnOran,
        .graphicsId = OBJ_EVENT_GFX_SPECIES(PIKACHU),
    }
};

const struct CampfireEncounterEvent sCampfireOpponentEncounter[CAMPFIRE_EVENT_COUNT] =
{
    [CAMPFIRE_EVENT_1] = 
    {
        .script = EventScript_CamperWantsToBattle,
        .graphicsId = OBJ_EVENT_GFX_HIKER,
    },
    [CAMPFIRE_EVENT_2] = 
    {
        .script = EventScript_PokemonWantsToBattle,
        .graphicsId = OBJ_EVENT_GFX_SPECIES(PIKACHU),
    }
};

static void Task_ShowMonAndStartCampfire(u8 taskId);
static void Task_SetUpPreCampfireEvent(u8 taskId);
static void Task_WaitShortTimeForFade(u8 taskId);
static void Task_DoPreCampfireEvent(u8 taskId);
static void TryShowPlayerPokemonAtCampfire(void);
static UNUSED void GetLocationCampfireAction(struct ScriptContext *ctx, struct ObjectEvent *objEvent, u8 mapGroup, u8 mapNum);
static void GetDailyCampfireAction(struct ScriptContext *ctx, struct ObjectEvent *objEvent, s32 friendship);
static void TryRemoveCampfireObjects(void);

/**
 * Determines whether a Campfire is currently active.
 */
bool8 CampfireIsActive(void)
{
    return !FlagGet(FLAG_HIDE_CAMPFIRE_PARTY_MON_1);
}

void RollDailyCampfireEvents(u16 days)
{
    u8 group, event;
    u16 var = 0;

    for (u32 i = 0; i < CAMPFIRE_COUNT; i++)
    {
        // Zatsu TODO: make this roll an actual random event instead of fudging it for testing
        group = CAMPFIRE_EVENT_GROUP_FRIENDLY;
        event = 0;

        var = (group << 8) | event;
        VarSet(sCampfireDailyEvents[i].campfireVar, var);
    }
}

#define gMapGroup   gSaveBlock1Ptr->location.mapGroup
#define gMapNum     gSaveBlock1Ptr->location.mapNum
#define tEventGroup data[0]
#define tEventNum   data[1]
#define tTurnPlayer data[2]
#define tVObjectId  data[3]
#define tTimer      data[4]
#define tFuncHi     data[5]
#define tFuncLo     data[6]

u16 GetDailyCampfireEvent(u8 mapGroup, u8 mapNum)
{
    for (u32 i = 0; i < CAMPFIRE_COUNT; i++)
    {
        if (mapGroup == sCampfireDailyEvents[i].mapGroup
           && mapNum == sCampfireDailyEvents[i].mapNum)
           return VarGet(sCampfireDailyEvents[i].campfireVar);
    }
    return 0;
}

static void SetDailyCampfireEventDone(u8 mapGroup, u8 mapNum)
{
    for (u32 i = 0; i < CAMPFIRE_COUNT; i++)
    {
        if (mapGroup == sCampfireDailyEvents[i].mapGroup
           && mapNum == sCampfireDailyEvents[i].mapNum)
            VarSet(sCampfireDailyEvents[i].campfireVar, 0);
    }
}

void Native_CampfireEventDoneAtPlayerLoc(void)
{
    for (u32 i = 0; i < CAMPFIRE_COUNT; i++)
    {
        if (gMapGroup == sCampfireDailyEvents[i].mapGroup
           && gMapNum == sCampfireDailyEvents[i].mapNum)
            VarSet(sCampfireDailyEvents[i].campfireVar, 0);
    }
}

void Task_RestAtCampfire(u8 taskId)
{
    FlagSet(OW_FLAG_PAUSE_TIME);
    LockPlayerFieldControls();
    FreezeObjectEvents();

    u16 campfireEvent = GetDailyCampfireEvent(gMapGroup, gMapNum);
    gTasks[taskId].tEventGroup = (campfireEvent >> 8) & 0xFF;
    gTasks[taskId].tEventNum = campfireEvent & 0xFF;
    gTasks[taskId].tTurnPlayer = -1;

    if (gTasks[taskId].tEventGroup == CAMPFIRE_EVENT_GROUP_FRIENDLY
     || gTasks[taskId].tEventGroup == CAMPFIRE_EVENT_GROUP_OPPONENT)
    {
        FadeScreen(FADE_TO_BLACK, 0);
        gTasks[taskId].func = Task_SetUpPreCampfireEvent;
        return;
    }

    gSaveBlock1Ptr->campfire.scriptTargetMon = -1;
    if (gTasks[taskId].tEventGroup == CAMPFIRE_EVENT_GROUP_PARTYMON)
        gSaveBlock1Ptr->campfire.scriptTargetMon = Random() % gPlayerPartyCount;

    gTasks[taskId].func = Task_ShowMonAndStartCampfire;
}

static void Task_SetUpPreCampfireEvent(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        const u8 *script = 0;
        u16 graphicsId = 0;
        u8 eventGroup = gTasks[taskId].tEventGroup;
        u8 eventNum = gTasks[taskId].tEventNum;
        u8 elevation = 0, direction = 0;
        s16 x = 0, y = 0;

        u8 directions[4] =
        {
            DIR_SOUTH,
            DIR_NORTH,
            DIR_WEST,
            DIR_EAST,
        };

        if (eventGroup == CAMPFIRE_EVENT_GROUP_FRIENDLY)
        {
            script = sCampfireFriendlyEncounter[eventNum].script;
            graphicsId = sCampfireFriendlyEncounter[eventNum].graphicsId;
        }
        else if (eventGroup == CAMPFIRE_EVENT_GROUP_OPPONENT)
        {
            script = sCampfireOpponentEncounter[eventNum].script;
            graphicsId = sCampfireOpponentEncounter[eventNum].graphicsId;
        }

        if (script == 0 || graphicsId == 0) // Something went wrong just do the campfire
        {
            gTasks[taskId].func = Task_ShowMonAndStartCampfire;
            return;
        }

        Shuffle(directions, 4, sizeof(directions[0]));

        for (u32 i = 0; i < 4; i++)
        {
            direction = directions[i];
            if (direction == gSpecialVar_Facing)
                continue;

            x = gSaveBlock1Ptr->pos.x + sFacingOffset[direction][0];
            y = gSaveBlock1Ptr->pos.y + sFacingOffset[direction][1];

            if (MapGridGetCollisionAt(x, y) || GetMapBorderIdAt(x, y) == -1
            || IsElevationMismatchAt(gObjectEvents[gPlayerAvatar.spriteId].currentElevation, x, y))
                continue;

            break;
        }

        gTasks[taskId].tVObjectId = CreateVirtualObject(graphicsId, MAX_SPRITES - 1, x, y, elevation, GetOppositeDirection(direction));
        gTasks[taskId].tTurnPlayer = direction;
        gTasks[taskId].tFuncHi = (uintptr_t)script >> 16;
        gTasks[taskId].tFuncLo = (uintptr_t)script;

        gTasks[taskId].func = Task_WaitShortTimeForFade;
    }
}

static void Task_WaitShortTimeForFade(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        gTasks[taskId].tTimer++;
        if (gTasks[taskId].tTimer > 40)
        {
            FadeScreen(FADE_FROM_BLACK, 0);
            gTasks[taskId].func = Task_DoPreCampfireEvent;
            gTasks[taskId].tTimer = 0;
        }
    }
}

static void Task_DoPreCampfireEvent(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        struct ObjectEvent *playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];
        const u8 *script = (const u8 *)(
            ((uintptr_t)(gTasks[taskId].tFuncHi & 0xFFFF) << 16) |
            (uintptr_t)(gTasks[taskId].tFuncLo & 0xFFFF)
        );

        gTasks[taskId].tTimer++;
        if (gTasks[taskId].tTimer == 30)
        {
            ObjectEventEmote(playerObjEvent, FOLLOWER_EMOTION_SURPRISE);
            PlaySE(SE_PIN);
        }
        else if (gTasks[taskId].tTimer == 60)
        {
            if (gTasks[taskId].tTurnPlayer != -1)
                ObjectEventTurn(playerObjEvent, gTasks[taskId].tTurnPlayer);
        }
        else if (gTasks[taskId].tTimer > 100)
        {
            ScriptContext_SetupScript(script);
            UnfreezeObjectEvents();
            UnlockPlayerFieldControls();
            DestroyTask(taskId);
        }
    }
}

/**
 * Heals and places the player's party around the campfire.
 */
static void Task_ShowMonAndStartCampfire(u8 taskId)
{
    HealPlayerParty();
    TryShowPlayerPokemonAtCampfire();
    DrawWholeMapView();

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

    gSaveBlock1Ptr->campfire.x = pX;
    gSaveBlock1Ptr->campfire.y = pY + 1;

    SetWarpDestination(gMapGroup, gMapNum, WARP_ID_NONE, pX, pY);
    DoDiveWarp();
    ResetInitialPlayerAvatarState();
    FlagSet(FLAG_TEMP_HIDE_FOLLOWER);
    UpdateFollowingPokemon();

    // TODO EVA: slightly increase the friendship of the whole party? Or create another function that increases
    //  the friendship of one Pokémon when given some item like a marshmallow?

    UnfreezeObjectEvents();
    UnlockPlayerFieldControls();
    DestroyTask(taskId);
}

static void TryShowPlayerPokemonAtCampfire(void)
{
    // Placing player's Pokémon in the field (VAR_OBJ_GFX_ID_A to F)
    for (s32 i = 0; i < PARTY_SIZE; i++)
    {
        u32 specGfx;
        bool32 shiny;
        bool32 female;
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
    }
}

void GetCampfireAction(struct ScriptContext *ctx)
{
    u8 partyIndex = ScriptReadByte(ctx);
    struct Pokemon *mon = &gPlayerParty[partyIndex];
    struct ObjectEvent *objEvent = &gObjectEvents[GetObjectEventIdByLocalIdAndMap(gSpecialVar_LastTalked, gMapNum, gMapGroup)];
    struct SpecialEmote condEmotes[16] = {0};
    u32 i, j, emotion, condCount = 0;
    bool32 pickedCondition = FALSE;

    u32 species = GetMonData(mon, MON_DATA_SPECIES);
    s32 multi = GetMonData(mon, MON_DATA_FRIENDSHIP);
    GetMonData(mon, MON_DATA_NICKNAME, gStringVar1);
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

    // This mon was selected as the Daily event mon, go there instead
    if (partyIndex == gSaveBlock1Ptr->campfire.scriptTargetMon)
        GetDailyCampfireAction(ctx, objEvent, multi);

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

    /* (20% chance) Select a location-based message
    /  I never ended up creating this as it seemed unecessary
    /  But if you would like, here's where you'd put this
    if (!(Random() % 4))
    {
        GetLocationCampfireAction(ctx, objEvent, gMapGroup, gMapNum);
    }
    */

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

    // condition message was chosen
    if (pickedCondition)
    {
        emotion = gFollowerConditionalMessages[multi].emotion;
        ObjectEventEmote(objEvent, emotion);
        ctx->data[0] = (u32)gFollowerConditionalMessages[multi].text;
        // text choices are spread across array; pick a random one
        if (gFollowerConditionalMessages[multi].textSpread)
        {
            for (i = 0; i < 4; i++)
            {
                if (!((u32*)gFollowerConditionalMessages[multi].text)[i])
                    break;
            }
            ctx->data[0] = i ? ((u32*)gFollowerConditionalMessages[multi].text)[Random() % i] : 0;
        }
        ScriptCall(ctx, gFollowerConditionalMessages[multi].script ? gFollowerConditionalMessages[multi].campfireScript : gFollowerBasicMessages[emotion].campfireScript);
        return;
    }

    // otherwise, a basic or C-based message was picked
    ObjectEventEmote(objEvent, emotion);
    ctx->data[0] = (u32)gFollowerBasicMessages[emotion].messages[multi].text; // Load message text
    ScriptCall(ctx, gFollowerBasicMessages[emotion].messages[multi].campfireScript ?
                        gFollowerBasicMessages[emotion].messages[multi].campfireScript :
                        gFollowerBasicMessages[emotion].campfireScript);
}

static UNUSED void GetLocationCampfireAction(struct ScriptContext *ctx, struct ObjectEvent *objEvent, u8 mapGroup, u8 mapNum)
{
    // This will get actions based on the specific location of the campfire
    // Needs to be populated with some code that gets a random script from an array
}

static void GetDailyCampfireAction(struct ScriptContext *ctx, struct ObjectEvent *objEvent, s32 friendship)
{
    u8 random = Random() % CAMPFIRE_EVENT_COUNT; 
    // ^ Currently this just rolls at random but I'd like to add logic that makes the script it gets be highly custom to your Pokémon's current mood
    // Event from the Campfire's rolled daily variable is not honoured in PartyMon events because of this it would be impossible to predict the Pokémon's campfire mood at the time it was rolled
    const u8 *script = sCampfirePartyMonEvents[random].script;
    u8 emotion = sCampfirePartyMonEvents[random].emotion;
    u16 item = sCampfirePartyMonEvents[random].item;

    gSaveBlock1Ptr->campfire.scriptTargetMon = -1;
    SetDailyCampfireEventDone(gMapGroup, gMapNum);

    ObjectEventEmote(objEvent, emotion);
    ctx->data[1] = (u32)item;
    ScriptCall(ctx, script);
}

bool8 MovedTooFarFromCampfire(u16 x, u16 y)
{
    u32 campX = gSaveBlock1Ptr->campfire.x;
    u32 campY = gSaveBlock1Ptr->campfire.y;
    return x > campX + 3 || x < campX - 3 || y > campY + 3 || y < campY - 3;
}

void Task_LeaveCampfire(u8 taskId)
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
    gSaveBlock1Ptr->campfire.scriptTargetMon = -1;
    
    TryRemoveCampfireObjects();
    DestroyTask(taskId);
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
                RemoveObjectEventByLocalIdAndMap(template->localId, gMapNum, gMapGroup);
            }
        }
    }
}

#undef gMapGroup
#undef gMapNum
#undef tEventGroup
#undef tEventNum
#undef tTurnPlayer
#undef tEvntScript
#undef tVObjectId
#undef tTimer
#undef tFuncHi
#undef tFuncLo

void Native_Campfire(void)
{
    CreateTask(Task_RestAtCampfire, 5);
}

void Native_LeaveCampfire(void)
{
    CreateTask(Task_LeaveCampfire, 5);
}
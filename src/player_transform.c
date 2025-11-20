#include "global.h"
#include "script.h"
#include "field_weather.h"
#include "field_screen_effect.h"
#include "field_player_avatar.h"
#include "event_object_movement.h"
#include "constants/event_objects.h"
#include "event_data.h"
#include "palette.h"
#include "party_menu.h"
#include "overworld.h"
#include "constants/party_menu.h"
#include "player_transform.h"
static void SetPlayerTransformState(bool32 state);
static void Task_PartyMenuWaitForFade(u8 taskId);
static bool8 CB2_FadeFromPartyMenuAfterTransform(void);

struct Pokemon *gPlayerTransformPokemon; // This points to the pokemon the player is currently transformed intos


bool8 CB2_FadeFromPartyMenuAfterTransform(void)
{
    FadeInFromBlack();
    CreateTask(Task_PartyMenuWaitForFade, 10);
    CreateTask(Task_StartPokemonAvatarBob, 9);
    return TRUE;

}

static void Task_PartyMenuWaitForFade(u8 taskId)
{
    if (IsWeatherNotFadingIn())
    {
        gTasks[taskId].func = Task_StartPokemonAvatarBob;
        UnlockPlayerFieldControls();
        ScriptContext_Enable();
    }
}

void CB2_TransformPlayerFromParty(void) // Callback passed to the ChooseMonForTransform function
{
    u32 index;
    index = GetCursorSelectionMonId();
    if (index >= PARTY_SIZE)
    {
        index = PARTY_NOTHING_CHOSEN;
    }
    else
    {
        
        gSaveBlock1Ptr->transformMonIndex = index;
        gPlayerTransformPokemon = &gPlayerParty[gSaveBlock1Ptr->transformMonIndex];
        TransformPlayerToPokemon();
    }
    gFieldCallback2 = CB2_FadeFromPartyMenuAfterTransform;
    SetMainCallback2(CB2_ReturnToField);
    UnfreezeObjectEvents();
}

bool32 IsPlayerTransformed()
{
    if (gSaveBlock1Ptr->isPlayerTransformed)
    {
        return TRUE;
    }
        
    return FALSE;
}

static void SetPlayerTransformState(bool32 state)
{
    gSaveBlock1Ptr->isPlayerTransformed = state;
}

u16 SpeciesToGraphicsId(struct Pokemon *pokemon)
{
    u32 species = GetMonData(pokemon, MON_DATA_SPECIES);
    bool32 shiny = GetMonData(pokemon, MON_DATA_IS_SHINY);
    bool32 female = GetMonGender(pokemon) == MON_FEMALE;

    u16 graphicsId = species + OBJ_EVENT_MON;
    if (shiny)
        graphicsId += OBJ_EVENT_MON_SHINY;
    if (female)
        graphicsId += OBJ_EVENT_MON_FEMALE;
    return graphicsId;
}

u16 GetPlayerTransformGfxFromSaveblock()
{
    u32 slot = gSaveBlock1Ptr->transformMonIndex;
    if(slot >= PARTY_SIZE)
    {
        return 0xFFFF;
    }

    struct Pokemon *playerTransformPokemon = &gPlayerParty[slot];
    u16 graphicsId = SpeciesToGraphicsId(playerTransformPokemon);
    return graphicsId;
}

void BeginPlayerTransform(void)
{
    if (IsPlayerTransformed())
    {
        TransformPlayerToDefault();
    }
        
    else
    {
        ChooseMonForTransform();
    }
        
        
}

void UpdateTransformedPlayerPalette(struct ObjectEvent *playerObj)
{
    u16 species = GetMonData(gPlayerTransformPokemon, MON_DATA_SPECIES);
    struct Sprite *sprite = &gSprites[playerObj->spriteId];
    struct SpritePalette spritePalette;
    u16 palTag = species + OBJ_EVENT_MON;
    spritePalette.data = gSpeciesInfo[species].overworldPalette;
    spritePalette.tag = palTag;
    sprite->oam.paletteNum = LoadSpritePalette(&spritePalette);
}

void TransformPlayerToPokemon()
{
    struct ObjectEvent *playerObj = &gObjectEvents[gPlayerAvatar.objectEventId];
    FlagSet(FLAG_DISABLE_FOLLOWERS);
    SetPlayerTransformState(TRUE);
    ObjectEventSetGraphicsId(playerObj, SpeciesToGraphicsId(gPlayerTransformPokemon));
    UpdateTransformedPlayerPalette(playerObj);
    ResetInitialPlayerAvatarState();
    PlayerFaceDirection(GetPlayerFacingDirection());
    RemoveFollowingPokemon();
}

void TransformPlayerToDefault()
{
    struct ObjectEvent *playerObj = &gObjectEvents[gPlayerAvatar.objectEventId];
    SetPlayerTransformState(FALSE);
    ResetInitialPlayerAvatarState();
    ObjectEventSetGraphicsId(playerObj, GetPlayerAvatarGraphicsIdByStateId(PLAYER_AVATAR_STATE_NORMAL));
    PlayerFaceDirection(GetPlayerFacingDirection());
    FlagClear(FLAG_DISABLE_FOLLOWERS);
    UpdateFollowingPokemon();
}

void TryStartPokemonAvatarBob(void)
{
    if (!(FuncIsActiveTask(Task_StartPokemonAvatarBob) || FuncIsActiveTask(Task_PokemonAvatar_HandleBob)))
    {
        CreateTask(Task_StartPokemonAvatarBob, 10);
    }
}

void Task_StartPokemonAvatarBob(u8 taskId)
{
    if(gMain.callback2 == CB2_Overworld)
    {   
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].func = Task_PokemonAvatar_HandleBob;

    }
}

#define STEP_FRAME_DURATION 8
#define FP_SHIFT 8
#define FIXED_POINT(n) ((int)((n) * (1 << FP_SHIFT)))

#define tFrameCounter data[0]
#define tSubpixelOffset data[1]
void Task_PokemonAvatar_HandleBob(u8 taskId)
{
    if (IsPlayerTransformed())
    {
        struct Sprite *playerSprite = &gSprites[gObjectEvents[gPlayerAvatar.objectEventId].spriteId];
        s16 *data = gTasks[taskId].data;

        if (tFrameCounter == 0)
        {
            tSubpixelOffset = FIXED_POINT(1); // 1.0 in 8.8 fixed-point
        }

        if (tFrameCounter == STEP_FRAME_DURATION)
        {
            tSubpixelOffset -= FIXED_POINT(0.5); // -0.5
        }

        if (tFrameCounter == STEP_FRAME_DURATION * 2)
        {
            tSubpixelOffset += FIXED_POINT(0.5); // +0.5
            tFrameCounter = 0;
            return;
        }

        playerSprite->y2 = tSubpixelOffset >> FP_SHIFT; // convert to integer for display
        tFrameCounter++;
    }
}
#undef tFrameCounter
#undef tSubpixelOffset

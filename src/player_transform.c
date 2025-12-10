#include "global.h"
#include "constants/field_weather.h"
#include "constants/global.h"
#include "constants/party_menu.h"
#include "constants/pokemon.h"
#include "event_data.h"
#include "constants/flags.h"
#include "constants/species.h"
#include "event_object_movement.h"
#include "fieldmap.h"
#include "constants/event_objects.h"
#include "main.h"
#include "overworld.h"
#include "palette.h"
#include "pokemon.h"
#include "party_menu.h"
#include "script.h"
#include "sprite.h"
#include "player_transform.h"
#include "field_player_avatar.h"

#define STEP_FRAME_DURATION 8

struct Pokemon* gPlayerTransformPokemon;
EWRAM_DATA struct PlayerAvatarBobState gPlayerAvatarBobState = {0};

static void UNUSED UpdateTransformedPlayerPalette(struct ObjectEvent* playerObj);
static void ResetPlayerAvatar();
static void TransformPlayerToPokemonByIndex(u8 index);
static void SetPlayerTransformFlags();
static void ClearPlayerTransformFlags();

struct Pokemon* GetCurrentlyTransformedPokemon()
{
    bool32 isPlayerTransformed = FlagGet(FLAG_PLAYER_IS_POKEMON);
    if (isPlayerTransformed && !gPlayerTransformPokemon)
        gPlayerTransformPokemon = &gPlayerParty[gSaveBlock1Ptr->playerTransformPokemonIndex];
    return gPlayerTransformPokemon;
}

void CB2_TransformPlayerToPokemonFromParty()
{
    u8 index;
    index = GetCursorSelectionMonId();
    if (index >= PARTY_SIZE) {
        index = PARTY_NOTHING_CHOSEN;
    }
    else {
        gSaveBlock1Ptr->playerTransformPokemonIndex = index;
        gPlayerTransformPokemon = &gPlayerParty[index];
        TransformPlayerToPokemon();
    }

    gFieldCallback2 = CB2_FadeFromPartyMenu;
    SetMainCallback2(CB2_ReturnToField);
}

u16 PokemonToGraphicsId(struct Pokemon* pokemon)
{
    u32 species = GetMonData(pokemon, MON_DATA_SPECIES);
    bool32 isShiny = GetMonData(pokemon, MON_DATA_IS_SHINY);
    bool32 isFemale = GetMonGender(pokemon) == MON_FEMALE;

    u16 graphicsId = species + OBJ_EVENT_MON;
    if (isShiny)
        graphicsId += OBJ_EVENT_MON_SHINY;
    if (isFemale)
        graphicsId += OBJ_EVENT_MON_FEMALE;

    return graphicsId;
}

static void UNUSED UpdateTransformedPlayerPalette(struct ObjectEvent* playerObj)
{
    u32 species = GetMonData(gPlayerTransformPokemon, MON_DATA_SPECIES);
    struct SpritePalette spritePalette;
    spritePalette.data = gSpeciesInfo[species].overworldPalette;
    spritePalette.tag = species + OBJ_EVENT_MON;
    struct Sprite* sprite = &gSprites[playerObj->spriteId];
    sprite->oam.paletteNum = LoadSpritePalette(&spritePalette);
}

void ResetPlayerAvatar()
{
    u16 x, y;
    GetCameraFocusCoords(&x, &y);
    u8 direction = GetPlayerFacingDirection();
    struct ObjectEvent* playerObj = &gObjectEvents[gPlayerAvatar.objectEventId];
    RemoveObjectEvent(playerObj);
    ClearPlayerAvatarInfo();
    InitPlayerAvatar(x, y, direction, gSaveBlock2Ptr->playerGender);
}

static void SetPlayerTransformFlags()
{
    FlagSet(FLAG_PLAYER_IS_POKEMON);
    FlagSet(FLAG_DISABLE_FOLLOWERS);
}

static void ClearPlayerTransformFlags()
{
    FlagClear(FLAG_PLAYER_IS_POKEMON);
    FlagClear(FLAG_DISABLE_FOLLOWERS);
}

void TransformPlayerToPokemon()
{
    SetPlayerTransformFlags();
    ResetPlayerAvatar();
}

void TransformPlayerToHuman()
{
    ClearPlayerTransformFlags();
    ResetPlayerAvatar();
    UpdateFollowingPokemon();
}

void TransformPlayer(struct ScriptContext* ctx)
{
    u16 index = ScriptReadHalfword(ctx);
    bool32 readvar = ScriptReadByte(ctx);
    bool32 defer = ScriptReadByte(ctx);

    if (readvar)
        index = VarGet(gSpecialVar_0x8004);

    if (index == 0xFF) {
        ChooseMonForTransform();
        return;
    }

    if (index == PARTY_SIZE) {
        if (defer)
            ClearPlayerTransformFlags();
        else
            TransformPlayerToHuman();
        return;
    }

    if (defer) {
        gPlayerTransformPokemon = &gPlayerParty[index];
        SetPlayerTransformFlags();
    }
    else
        TransformPlayerToPokemonByIndex(index);
}

static void TransformPlayerToPokemonByIndex(u8 index)
{
    gSaveBlock1Ptr->playerTransformPokemonIndex = index;
    gPlayerTransformPokemon = &gPlayerParty[index];
    TransformPlayerToPokemon();
    UpdateFollowingPokemon();
}

void PlayerAvatarHandleBob()
{
    if (FlagGet(FLAG_PLAYER_IS_POKEMON)) {
        struct Sprite* playerSprite = &gSprites[gPlayerAvatar.spriteId];

        if (gPlayerAvatarBobState.frameCounter == 0)
            gPlayerAvatarBobState.spriteOffset = Q_4_12(1.0);

        if (gPlayerAvatarBobState.frameCounter == STEP_FRAME_DURATION)
            gPlayerAvatarBobState.spriteOffset -= Q_4_12(0.5);

        if (gPlayerAvatarBobState.frameCounter == STEP_FRAME_DURATION * 2) {
            gPlayerAvatarBobState.spriteOffset += Q_4_12(0.5);
            gPlayerAvatarBobState.frameCounter = 0;
            return;
        }

        playerSprite->y2 = Q_4_12_TO_INT(gPlayerAvatarBobState.spriteOffset);
        gPlayerAvatarBobState.frameCounter++;
    }
}


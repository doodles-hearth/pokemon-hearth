#include "global.h"
#include "player_transform.h"
#include "field_player_avatar.h"
#include "event_object_movement.h"
#include "constants/event_objects.h"
#include "event_data.h"
#include "palette.h"
#include "party_menu.h"
#include "constants/party_menu.h"
#include "overworld.h"

/*STATIC FUNCTIONS*/
static void setPlayerTransformState(bool32 state);

struct Pokemon *gPlayerTransformPokemon; // This points to the pokemon the player is currently transformed intos

void CB2_TransformPlayerFromParty(void) // Callback passed to the ChooseMonForTransform function
{
    u8 index;
    index = GetCursorSelectionMonId();
    if (index >= PARTY_SIZE)
        index = PARTY_NOTHING_CHOSEN;
    else
    {
        gSaveBlock1Ptr->playerTransformData.slot = index;
        gPlayerTransformPokemon = &gPlayerParty[index];
        TransformPlayerToPokemon();
    }
    gFieldCallback2 = CB2_FadeFromPartyMenu;
    SetMainCallback2(CB2_ReturnToField);
    UnfreezeObjectEvents();
}

bool32 isPlayerTransformed()
{
    if (gSaveBlock1Ptr->playerTransformData.isPokemon)
        return TRUE;
    return FALSE;
}

static void setPlayerTransformState(bool32 state)
{
    gSaveBlock1Ptr->playerTransformData.isPokemon = state;
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
    struct PlayerTransformData *data = &gSaveBlock1Ptr->playerTransformData;

    if(data->slot >= PARTY_SIZE)
        return 0xFFFF;

    struct Pokemon *playerTransformPokemon = &gPlayerParty[data->slot];
    u16 graphicsId = SpeciesToGraphicsId(playerTransformPokemon);
    return graphicsId;
}

void BeginPlayerTransform(void)
{

    if (isPlayerTransformed())
        TransformPlayerToDefault();
    else
        ChooseMonForTransform();
        
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
    setPlayerTransformState(TRUE);
    ObjectEventSetGraphicsId(playerObj, SpeciesToGraphicsId(gPlayerTransformPokemon));
    UpdateTransformedPlayerPalette(playerObj);
    ResetInitialPlayerAvatarState();
    PlayerFaceDirection(GetPlayerFacingDirection());
    RemoveFollowingPokemon();
}

void TransformPlayerToDefault()
{
    struct ObjectEvent *playerObj = &gObjectEvents[gPlayerAvatar.objectEventId];
    setPlayerTransformState(FALSE);
    ResetInitialPlayerAvatarState();
    ObjectEventSetGraphicsId(playerObj, GetPlayerAvatarGraphicsIdByStateId(PLAYER_AVATAR_STATE_NORMAL));
    PlayerFaceDirection(GetPlayerFacingDirection());
    FlagClear(FLAG_DISABLE_FOLLOWERS);
    UpdateFollowingPokemon();
}

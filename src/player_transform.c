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

// Bit layout:
// [15:11] padding (5 bits)
// [10:6]  slot (5 bits)
// [5:2]   boxId (4 bits)
// [1]     inBox (1 bit)
// [0]     isPokemon (1 bit)

#define TRANSFORM_IS_POKEMON_SHIFT 0
#define TRANSFORM_IN_BOX_SHIFT     1
#define TRANSFORM_BOX_ID_SHIFT     2
#define TRANSFORM_SLOT_SHIFT       6

#define TRANSFORM_IS_POKEMON_BITS  1
#define TRANSFORM_IN_BOX_BITS      1
#define TRANSFORM_BOX_ID_BITS      4
#define TRANSFORM_SLOT_BITS        5

#define BITMASK(width, shift)      (((1u << (width)) - 1) << (shift))

#define TRANSFORM_IS_POKEMON_MASK  BITMASK(TRANSFORM_IS_POKEMON_BITS, TRANSFORM_IS_POKEMON_SHIFT)
#define TRANSFORM_IN_BOX_MASK      BITMASK(TRANSFORM_IN_BOX_BITS, TRANSFORM_IN_BOX_SHIFT)
#define TRANSFORM_BOX_ID_MASK      BITMASK(TRANSFORM_BOX_ID_BITS, TRANSFORM_BOX_ID_SHIFT)
#define TRANSFORM_SLOT_MASK        BITMASK(TRANSFORM_SLOT_BITS, TRANSFORM_SLOT_SHIFT)

static inline bool32 IsPokemon(u16 data)
{
    return (data >> TRANSFORM_IS_POKEMON_SHIFT) & 1;
}

static inline bool32 InBox(u16 data)
{
    return (data >> TRANSFORM_IN_BOX_SHIFT) & 1;
}

static inline u8 GetBoxId(u16 data)
{
    return (data & TRANSFORM_BOX_ID_MASK) >> TRANSFORM_BOX_ID_SHIFT;
}

static inline u8 GetSlot(u16 data)
{
    return (data & TRANSFORM_SLOT_MASK) >> TRANSFORM_SLOT_SHIFT;
}

static inline void SetIsPokemon(u16 *data, bool32 val)
{
    *data = (*data & ~TRANSFORM_IS_POKEMON_MASK) |
            ((val & BITMASK(TRANSFORM_IS_POKEMON_BITS, 0)) << TRANSFORM_IS_POKEMON_SHIFT);
}

static inline void SetInBox(u16 *data, bool32 val)
{
    *data = (*data & ~TRANSFORM_IN_BOX_MASK) |
            ((val & BITMASK(TRANSFORM_IN_BOX_BITS, 0)) << TRANSFORM_IN_BOX_SHIFT);
}

static inline void SetBoxId(u16 *data, u8 box)
{
    *data = (*data & ~TRANSFORM_BOX_ID_MASK) |
            ((box & BITMASK(TRANSFORM_BOX_ID_BITS, 0)) << TRANSFORM_BOX_ID_SHIFT);
}

static inline void SetSlot(u16 *data, u8 slot)
{
    *data = (*data & ~TRANSFORM_SLOT_MASK) |
            ((slot & BITMASK(TRANSFORM_SLOT_BITS, 0)) << TRANSFORM_SLOT_SHIFT);
}

static void SetPlayerTransformState(bool32 state);

struct Pokemon *gPlayerTransformPokemon; // This points to the pokemon the player is currently transformed intos

void CB2_TransformPlayerFromParty(void) // Callback passed to the ChooseMonForTransform function
{
    u8 index;
    index = GetCursorSelectionMonId();
    if (index >= PARTY_SIZE)
    {
        index = PARTY_NOTHING_CHOSEN;
    }
    else
    {
        SetSlot(&gSaveBlock1Ptr->playerTransformData, index);
        gPlayerTransformPokemon = &gPlayerParty[index];
        TransformPlayerToPokemon();
    }
    gFieldCallback2 = CB2_FadeFromPartyMenu;
    SetMainCallback2(CB2_ReturnToField);
    UnfreezeObjectEvents();
}

bool32 IsPlayerTransformed()
{
    if (IsPokemon(gSaveBlock1Ptr->playerTransformData))
    {
        return TRUE;
    }
        
    return FALSE;
}

static void SetPlayerTransformState(bool32 state)
{
    SetIsPokemon(&gSaveBlock1Ptr->playerTransformData, state);
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
    u16 slot = GetSlot(gSaveBlock1Ptr->playerTransformData);
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

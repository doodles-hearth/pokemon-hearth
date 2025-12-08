#include "global.h"
#include "constants/field_weather.h"
#include "constants/global.h"
#include "constants/party_menu.h"
#include "constants/pokemon.h"
#include "event_data.h"
#include "constants/flags.h"
#include "constants/species.h"
#include "event_object_movement.h"
#include "constants/event_objects.h"
#include "main.h"
#include "overworld.h"
#include "palette.h"
#include "pokemon.h"
#include "party_menu.h"
#include "sprite.h"
#include "player_transform.h"
#include "field_player_avatar.h"

struct Pokemon* gPlayerTransformPokemon;

static void UpdateTransformedPlayerPalette(struct ObjectEvent* playerObj);

void CB2_TransformPlayerToPokemonFromParty()
{
    u8 index;
    index = GetCursorSelectionMonId();
    if (index >= PARTY_SIZE) {
        index = PARTY_NOTHING_CHOSEN;
    }
    else {
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

static void UpdateTransformedPlayerPalette(struct ObjectEvent* playerObj)
{
    u32 species = GetMonData(gPlayerTransformPokemon, MON_DATA_SPECIES);
    struct SpritePalette spritePalette;
    spritePalette.data = gSpeciesInfo[species].overworldPalette;
    spritePalette.tag = species + OBJ_EVENT_MON;
    struct Sprite* sprite = &gSprites[playerObj->spriteId];
    sprite->oam.paletteNum = LoadSpritePalette(&spritePalette);
}

void TransformPlayerToPokemon()
{
    FlagSet(FLAG_PLAYER_IS_POKEMON);
    FlagSet(FLAG_DISABLE_FOLLOWERS);
    struct ObjectEvent* playerObj = &gObjectEvents[gPlayerAvatar.objectEventId];
    ObjectEventSetGraphicsId(playerObj, PokemonToGraphicsId(gPlayerTransformPokemon));
    UpdateTransformedPlayerPalette(playerObj);
    UpdateFollowingPokemon();
}

void TransformPlayerToHuman()
{
    FlagClear(FLAG_PLAYER_IS_POKEMON);
    FlagClear(FLAG_DISABLE_FOLLOWERS);
    SetPlayerAvatarTransitionFlags(PLAYER_AVATAR_FLAG_ON_FOOT);
    UpdateFollowingPokemon();
}

void TransformPlayerToPokemonFromParty()
{
    ChooseMonForTransform();
}

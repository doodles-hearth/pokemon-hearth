#include "global.h"
#include "event_data.h"
#include "overworld.h"
#include "field_screen_effect.h"
#include "script_pokemon_util.h"
#include "field_camera.h"
#include "field_weather.h"
#include "constants/event_objects.h"
#include "event_object_movement.h"

/**
 * Heals and places the player's party around the campfire.
 */
void restAtCampfireWithParty()
{
    // Pause RTC
    FlagSet(OW_FLAG_PAUSE_TIME);

    // Healing party
    HealPlayerParty();

    // Placing player's Pokémon in the field (VAR_OBJ_GFX_ID_A to F)
    for (int i = 0; i < PARTY_SIZE; i += 1)
    {
        u16 speciesGfx;
        u8 form;
        u8 shiny;
        GetMonInfo(&gPlayerParty[i], &speciesGfx, &form, &shiny);

        if (speciesGfx == SPECIES_NONE || speciesGfx == SPECIES_EGG)
        {
            break;
        }

        // Displaying object event
        FlagClear(FLAG_HIDE_CAMPFIRE_PARTY_MON_1 + i);

        // Assemble gfx ID like FollowerSetGraphics
        speciesGfx = (OBJ_EVENT_GFX_MON_BASE + speciesGfx) & OBJ_EVENT_GFX_SPECIES_MASK;
        speciesGfx |= form << OBJ_EVENT_GFX_SPECIES_BITS;
        VarSet((VAR_OBJ_GFX_ID_A + i), speciesGfx);
        DebugPrintfLevel(MGBA_LOG_WARN, "loading Pokémon %d: %d", i, speciesGfx);
    }

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

    // Storing campfire coordinates to be able to detect when the player walks away from it
    VarSet(VAR_CAMPFIRE_X, pX);
    VarSet(VAR_CAMPFIRE_Y, pY + 1);

    // TODO EVA: slightly increase the friendship of the whole party? Or create another function that increases
    //  the friendship of one Pokémon when given some item like a marshmallow?

    return;
}

void TryRemoveObjectEvents(void)
{
    struct ObjectEventTemplate *template;

    if (gMapHeader.events != NULL)
    {
        for (u32 i = 0; i < gMapHeader.events->objectEventCount; i += 1)
        {
            template = &gSaveBlock1Ptr->objectEventTemplates[i];
            if (FlagGet(template->flagId))
            {
                RemoveObjectEventByLocalIdAndMap(template->localId, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
            }
        }
    }
}

void leaveCampfire() {
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

    // Resetting campfire coordinates
    VarSet(VAR_CAMPFIRE_X, 0);
    VarSet(VAR_CAMPFIRE_Y, 0);
    
    TryRemoveObjectEvents();
}

void Script_Campfire() {
    restAtCampfireWithParty();
}

void Script_LeaveCampfire() {
    leaveCampfire();
}
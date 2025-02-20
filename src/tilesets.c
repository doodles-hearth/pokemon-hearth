#include "global.h"
#include "tilesets.h"
#include "tileset_anims.h"

#include "data/tilesets/graphics.h"
#include "data/tilesets/metatiles.h"
#include "data/tilesets/headers.h"

u16 GetPrimaryTilesetIdCurrentMap(void)
{
    if (gMapHeader.mapLayout->primaryTileset == &gTileset_PorytilesPrimaryTutorial)
        return TILESET_EXTERIOR_GENERIC;
    else
        return TILESET_PRIMARY_VANILLA;
}

u16 GetSecondaryTilesetIdCurrentMap(void)
{
    if (gMapHeader.mapLayout->secondaryTileset == &gTileset_SilverTunnel)
        return TILESET_SILVER_TUNNEL;
    if (gMapHeader.mapLayout->secondaryTileset == &gTileset_GinkoWoods)
        return TILESET_GINKO_WOODS;
    else
        return TILESET_SECONDARY_VANILLA;
}
#ifndef GUARD_tilesets_H
#define GUARD_tilesets_H

extern const u32 gTilesetTiles_General[];
extern const u16 gTilesetPalettes_General[][16];

extern const struct Tileset * const gTilesetPointer_SecretBase;
extern const struct Tileset * const gTilesetPointer_SecretBaseRedCave;

extern const struct Tileset gTileset_Building;
extern const struct Tileset gTileset_BrendansMaysHouse;

// Hearth tilesets
extern const struct Tileset gTileset_PorytilesPrimaryTutorial;
extern const struct Tileset gTileset_SilverTunnel;
extern const struct Tileset gTileset_GinkoWoods;

enum TilesetsPrimary
{
    TILESET_PRIMARY_VANILLA,
    TILESET_EXTERIOR_GENERIC,
};

enum TilesetsSecondary
{
    TILESET_SECONDARY_VANILLA,
    TILESET_SILVER_TUNNEL,
    TILESET_GINKO_WOODS,
};

#endif //GUARD_tilesets_H

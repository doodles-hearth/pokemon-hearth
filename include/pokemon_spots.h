#ifndef GUARD_POKEMON_SPOTS_H
#define GUARD_POKEMON_SPOTS_H

enum SpotAnimFrame {
    FRAME_1,
    FRAME_2
};

union MonSpotImage {
    const u16* rows16;
    const u32* rows32;
};

struct MonSpot {
    u8 x, y;
    u8 width;
    u8 height;
    union MonSpotImage image;
};

struct MonSpotTemplate {
    const struct MonSpot* spots;
    u8 count;
    u8 scale;
    s8 xOffset;
    s8 yOffset;
    u8 firstColor;
    u8 lastColor;
    u8 colorAdjust;
};


bool32 ShouldDrawSpotsOnSpecies(u16 species);
void DrawPokemonSpots(u32 personality, const struct MonSpotTemplate* spotTemplate, u8 *dest, enum SpotAnimFrame SpotAnimFrame);
void DrawPokemonSpotsBothFrames(u32 personality, const struct MonSpotTemplate* spotTemplate, u8* dest);

#endif /* end of include guard: GUARD_POKEMON_SPOTS_H */

#ifndef GUARD_POKEMON_SPOTS_H
#define GUARD_POKEMON_SPOTS_H

enum SpotAnimFrame {
    FRAME_1,
    FRAME_2
};

struct MonSpot {
    u8 x, y;
    const u32* image;
};

struct MonSpotTemplate {
    const struct MonSpot* spots;
    u8 count;
    u8 scale;
    s8 xOffsetFrame2;
    s8 yOffsetFrame2;
    u8 firstColor;
    u8 lastColor;
    u8 colorAdjust;
};

bool32 ShouldDrawSpotsOnSpecies(u16 species);
void DrawPokemonSpots(u32 personality, const struct MonSpotTemplate* spotTemplate, u8 *dest, enum SpotAnimFrame SpotAnimFrame);
void DrawPokemonSpotsBothFrames(u32 personality, const struct MonSpotTemplate* spotTemplate, u8* dest);

#endif /* end of include guard: GUARD_POKEMON_SPOTS_H */

#ifndef GUARD_POKEMON_SPOT_TEMPLATES_H
#define GUARD_POKEMON_SPOT_TEMPLATES_H

#include "global.h"
#include "pokemon_spots.h"

typedef u16 SpotRow16[16];
typedef u32 SpotRow32[32];

static const SpotRow16 sSpindaSpotImages[4] = {
    INCBIN_U16("graphics/pokemon/spinda/spots/spot_0.1bpp"),
    INCBIN_U16("graphics/pokemon/spinda/spots/spot_1.1bpp"),
    INCBIN_U16("graphics/pokemon/spinda/spots/spot_2.1bpp"),
    INCBIN_U16("graphics/pokemon/spinda/spots/spot_3.1bpp")};

static const struct MonSpot sSpindaSpots[] = {
    { .x = 16, .y = 7,  .image.rows16 = sSpindaSpotImages[0] },
    { .x = 40, .y = 8,  .image.rows16 = sSpindaSpotImages[1] },
    { .x = 22, .y = 25, .image.rows16 = sSpindaSpotImages[2] },
    { .x = 34, .y = 26, .image.rows16 = sSpindaSpotImages[3] },
};

const struct MonSpotTemplate gSpindaSpotTemplate = {
    .spots = sSpindaSpots,
    .count = ARRAY_COUNT(sSpindaSpots),
    .scale = 1,
    .xOffsetFrame2 = -4,
    .yOffsetFrame2 = 0,
    .firstColor = 1,
    .lastColor = 3,
    .colorAdjust = 4,
};

static const SpotRow32 sGyaradosSpotImages[4] = {
    INCBIN_U32("graphics/pokemon/gyarados/spots/spot_0.1bpp"),
    INCBIN_U32("graphics/pokemon/gyarados/spots/spot_1.1bpp"),
    INCBIN_U32("graphics/pokemon/gyarados/spots/spot_2.1bpp"),
    INCBIN_U32("graphics/pokemon/gyarados/spots/spot_3.1bpp")};

static const struct MonSpot sGyaradosSpots[] = {
    { .x = 16, .y = 32, .image.rows32 = sGyaradosSpotImages[0] },
    { .x = 32, .y = 8, .image.rows32 = sGyaradosSpotImages[1] },
    { .x = 54, .y = 40, .image.rows32 = sGyaradosSpotImages[2] },
    { .x = 34, .y = 26, .image.rows32 = sGyaradosSpotImages[3] },
};

const struct MonSpotTemplate gGyaradosSpotTemplate = {
    .spots = sGyaradosSpots,
    .count = ARRAY_COUNT(sGyaradosSpots),
    .scale = 2,
    .xOffsetFrame2 = 4,
    .yOffsetFrame2 = 8,
    .firstColor = 8,
    .lastColor = 9,
    .colorAdjust = 2,
};

#endif /* end of include guard: GUARD_POKEMON_SPOT_TEMPLATES_H */

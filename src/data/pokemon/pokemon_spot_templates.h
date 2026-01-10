#ifndef GUARD_POKEMON_SPOT_TEMPLATES_H
#define GUARD_POKEMON_SPOT_TEMPLATES_H

#include "global.h"
#include "pokemon_spots.h"

#define MON_SPOT(name, idx, _x, _y) \
    {.x = _x, .y =_y, .image = s##name##SpotImages[idx]},

/* Define Spots Below */

// SPECIES_SPINDA
static const u32 sSpindaSpotImages[4][8] = {
    INCBIN_U32("graphics/pokemon/spinda/spots/spot_0.1bpp"),
    INCBIN_U32("graphics/pokemon/spinda/spots/spot_1.1bpp"),
    INCBIN_U32("graphics/pokemon/spinda/spots/spot_2.1bpp"),
    INCBIN_U32("graphics/pokemon/spinda/spots/spot_3.1bpp"),
};
static const struct MonSpot sSpindaSpots[] = {
    MON_SPOT(Spinda, 0, 16, 7)
    MON_SPOT(Spinda, 1, 40, 8)
    MON_SPOT(Spinda, 2, 22, 27)
    MON_SPOT(Spinda, 3, 34, 26)
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

//SPECIES_GYARADOS
static const u32 sGyaradosSpotImages[4][32] = {
    INCBIN_U32("graphics/pokemon/gyarados/spots/spot_0.1bpp"),
    INCBIN_U32("graphics/pokemon/gyarados/spots/spot_1.1bpp"),
    INCBIN_U32("graphics/pokemon/gyarados/spots/spot_2.1bpp"),
    INCBIN_U32("graphics/pokemon/gyarados/spots/spot_3.1bpp"),
};
static const struct MonSpot sGyaradosSpots[] = {
    MON_SPOT(Gyarados, 0, 16, 32)
    MON_SPOT(Gyarados, 1, 32, 8)
    MON_SPOT(Gyarados, 2, 54, 40)
    MON_SPOT(Gyarados, 3, 26, 26)
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

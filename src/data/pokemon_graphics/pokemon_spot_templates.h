#ifndef GUARD_POKEMON_SPOT_TEMPLATES_H
#define GUARD_POKEMON_SPOT_TEMPLATES_H

#include "global.h"
#include "metaprogram.h"
#include "pokemon_spots.h"
#include "repeat_macros.h"

#define GEN_SPOT_IMAGES(tag, idx, size)                                                            \
    INCBIN_U##size("graphics/pokemon/" STR(tag) "/spots/spot_" STR(idx) ".1bpp"),

#define GEN_SPOT_IMAGES_16(tag, idx) GEN_SPOT_IMAGES(tag, idx, 16)
#define GEN_SPOT_IMAGES_32(tag, idx) GEN_SPOT_IMAGES(tag, idx, 32)

#define SPOT_ARRAY_16(name, tag,  count) \
    static const SpotRow16 s##name##SpotImages[count] = { \
    RECURSIVELY(R_ZIP(GEN_SPOT_IMAGES_16, REPEAT_N(count, tag), NUMBERS_16)) \
    }

#define SPOT_ARRAY_32(name, tag,  count) \
    static const SpotRow32 s##name##SpotImages[count] = { \
    RECURSIVELY(R_ZIP(GEN_SPOT_IMAGES_32, REPEAT_N(count, tag), NUMBERS_16)) \
    }

#define MON_SPOT_16(name, idx, _x, _y) \
    { .x = _x, .y = _y, .image.rows16 = s##name##SpotImages[idx] },

#define MON_SPOT_32(name, idx, _x, _y) \
    { .x = _x, .y = _y, .image.rows32 = s##name##SpotImages[idx] },

#define MON_SPOT_TEMPLATE(name, _scale, _x, _y, first, last, adjust) \
    const struct MonSpotTemplate g##name##SpotTemplate = { \
        .spots = s##name##Spots, \
        .count = ARRAY_COUNT(s##name##Spots), \
        .scale = _scale, \
        .xOffsetFrame2 = _x, \
        .yOffsetFrame2 = _y, \
        .firstColor = first, \
        .lastColor = last, \
        .colorAdjust = adjust, \
    };

typedef u16 SpotRow16[16];
typedef u32 SpotRow32[32];

/* Define Spots Below*/

SPOT_ARRAY_16(Spinda, spinda, 4);

static const struct MonSpot sSpindaSpots[] = {
MON_SPOT_16(Spinda, 0, 16, 7)
MON_SPOT_16(Spinda, 1, 40, 8)
MON_SPOT_16(Spinda, 2, 22, 27)
MON_SPOT_16(Spinda, 3, 34, 26)
};
MON_SPOT_TEMPLATE(Spinda, 1, -4, 0, 1, 3, 4)


SPOT_ARRAY_32(Gyarados, gyarados, 4);
static const struct MonSpot sGyaradosSpots[] = {
    MON_SPOT_32(Gyarados, 0, 16, 32)
    MON_SPOT_32(Gyarados, 1, 32, 8)
    MON_SPOT_32(Gyarados, 2, 54, 40)
    MON_SPOT_32(Gyarados, 3, 26, 26)
};
MON_SPOT_TEMPLATE(Gyarados, 2, 4, 8, 8, 9, 2)

#endif /* end of include guard: GUARD_POKEMON_SPOT_TEMPLATES_H */

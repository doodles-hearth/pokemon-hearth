#include "global.h"
#include "pokemon.h"
#include "pokemon_spots.h"

#define EVEN_PIXEL_SHIFT 0
#define ODD_PIXEL_SHIFT 4
#define FRAME_SIZE 64

static inline void TryDrawSpotPixel(u8* pixels, u8 pixelShift, u8 firstColor, u8 lastColor, u8 spotColorAdjust)
{
    u8 pixel = (*pixels >> pixelShift) & 0xF;
    if ((u8)(pixel - firstColor) <= (lastColor - firstColor))
        *pixels += (spotColorAdjust << pixelShift);
}

static inline u32 GetColumnPixelShift(u32 column) { return (column & 1) ? 4 : 0; }

bool32 ShouldDrawSpotsOnSpecies(u16 species)
{
    if (gSpeciesInfo[SanitizeSpeciesId(species)].monSpotTemplate)
        return TRUE;
    else
        return FALSE;
}

void DrawPokemonSpots(u32 personality, const struct MonSpotTemplate* spotTemplate, u8* dest,
                      enum SpotAnimFrame spotAnimFrame)
{
    u8 size = 16 * spotTemplate->scale;  // We only expect square spots
    u32 i;
    for (i = 0; i < spotTemplate->count; i++) {
        const struct MonSpot* spot = &spotTemplate->spots[i];
        u32 row;
        u16 x = spot->x + (personality & 0x0F) * spotTemplate->scale;
        u8 y = spot->y + ((personality & 0xF0) >> 4) * spotTemplate->scale;

        switch (spotAnimFrame) {
            case FRAME_1:
                x -= size / 2;
                y -= size / 2;
                break;

            case FRAME_2:
                x += spotTemplate->xOffsetFrame2 - size / 2;
                y += FRAME_SIZE + spotTemplate->yOffsetFrame2 - size / 2;
                break;

            default:
                break;
        }

        for (row = 0; row < size; row++) {
            u32 column;
            u32 spotPixelRow = size == 16 ? spot->image.rows16[row] : spot->image.rows32[row];

            for (column = x; column < x + size; column++) {
                u8* destPixels = dest + ((column / 8) * TILE_SIZE_4BPP) + ((column % 8) / 2) +
                                 ((y / 8) * TILE_SIZE_4BPP * 8) + ((y % 8) * 4);

                if (spotPixelRow & 1) {
                    TryDrawSpotPixel(destPixels, (column & 1 ? 4 : 0 ), spotTemplate->firstColor, spotTemplate->lastColor,
                                     spotTemplate->colorAdjust);
                }

                spotPixelRow >>= 1;
            }

            y++;
        }

        personality >>= 8;
    }
}

void DrawPokemonSpotsBothFrames(u32 personality, const struct MonSpotTemplate* spotTemplate, u8* dest)
{
    DrawPokemonSpots(personality, spotTemplate, dest, FALSE);
    DrawPokemonSpots(personality, spotTemplate, dest, TRUE);
}

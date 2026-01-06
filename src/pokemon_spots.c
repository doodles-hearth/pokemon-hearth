#include "global.h"
#include "pokemon.h"
#include "pokemon_spots.h"

static inline void TryDrawSpotPixel(u8* pixels, u8 pixelShift, u8 firstColor, u8 lastColor,
                                    u8 spotColorAdjust)
{
    u8 pixel = (*pixels >> pixelShift) & 0xF;
    if ((u8)(pixel - firstColor) <= (lastColor - firstColor))
        *pixels += (spotColorAdjust << pixelShift);
}

static inline u32 GetMonSpotRow(const struct MonSpot* spot, u32 row)
{
    return (spot->width == 16) ? spot->image.rows16[row] : spot->image.rows32[row];
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
    u32 i;
    for (i = 0; i < spotTemplate->count; i++) {
        const struct MonSpot* spot = &spotTemplate->spots[i];
        u32 row;
        u8 x = spot->x + (personality & 0x0F) * spotTemplate->scale;
        u8 y = spot->y + ((personality & 0xF0) >> 4) * spotTemplate->scale;

        switch (spotAnimFrame) {
            case FRAME_1:
                x -= spotTemplate->xOffset;
                y -= spotTemplate->yOffset;
                break;

            case FRAME_2:
                x -= 12;
                y += 56;
                break;

            default:
                break;
        }

        for (row = 0; row < spot->height; row++) {
            u32 column;
            u32 spotPixelRow = GetMonSpotRow(spot, row);

            for (column = x; column < x + spot->width; column++) {
                u8* destPixels = dest + ((column / 8) * TILE_SIZE_4BPP) + ((column % 8) / 2) +
                                 ((y / 8) * TILE_SIZE_4BPP * 8) + ((y % 8) * 4);

                if (spotPixelRow & 1) {
                    TryDrawSpotPixel(destPixels, GetColumnPixelShift(column),
                                     spotTemplate->firstColor, spotTemplate->lastColor,
                                     spotTemplate->colorAdjust);
                }

                spotPixelRow >>= 1;
            }

            y++;
        }

        personality >>= 8;
    }
}

void DrawPokemonSpotsBothFrames(u32 personality, const struct MonSpotTemplate* spotTemplate,
                                u8* dest)
{
    DrawPokemonSpots(personality, spotTemplate, dest, FALSE);
    DrawPokemonSpots(personality, spotTemplate, dest, TRUE);
}

#include "global.h"
#include "util.h"
#include "sprite.h"
#include "palette.h"
#include "random.h"
#include "constants/rgb.h"

static const struct SpriteTemplate sInvisibleSpriteTemplate =
{
    .tileTag = 0,
    .paletteTag = 0,
    .oam = &gDummyOamData,
};

static const u8 sSpriteDimensions[3][4][2] =
{
    // square
    {
        {1, 1},
        {2, 2},
        {4, 4},
        {8, 8},
    },

    // horizontal rectangle
    {
        {2, 1},
        {4, 1},
        {4, 2},
        {8, 4},
    },

    // vertical rectangle
    {
        {1, 2},
        {1, 4},
        {2, 4},
        {4, 8},
    },
};

static const u16 sCrc16Table[] =
{
    0x0000, 0x1189, 0x2312, 0x329B, 0x4624, 0x57AD, 0x6536, 0x74BF,
    0x8C48, 0x9DC1, 0xAF5A, 0xBED3, 0xCA6C, 0xDBE5, 0xE97E, 0xF8F7,
    0x1081, 0x0108, 0x3393, 0x221A, 0x56A5, 0x472C, 0x75B7, 0x643E,
    0x9CC9, 0x8D40, 0xBFDB, 0xAE52, 0xDAED, 0xCB64, 0xF9FF, 0xE876,
    0x2102, 0x308B, 0x0210, 0x1399, 0x6726, 0x76AF, 0x4434, 0x55BD,
    0xAD4A, 0xBCC3, 0x8E58, 0x9FD1, 0xEB6E, 0xFAE7, 0xC87C, 0xD9F5,
    0x3183, 0x200A, 0x1291, 0x0318, 0x77A7, 0x662E, 0x54B5, 0x453C,
    0xBDCB, 0xAC42, 0x9ED9, 0x8F50, 0xFBEF, 0xEA66, 0xD8FD, 0xC974,
    0x4204, 0x538D, 0x6116, 0x709F, 0x0420, 0x15A9, 0x2732, 0x36BB,
    0xCE4C, 0xDFC5, 0xED5E, 0xFCD7, 0x8868, 0x99E1, 0xAB7A, 0xBAF3,
    0x5285, 0x430C, 0x7197, 0x601E, 0x14A1, 0x0528, 0x37B3, 0x263A,
    0xDECD, 0xCF44, 0xFDDF, 0xEC56, 0x98E9, 0x8960, 0xBBFB, 0xAA72,
    0x6306, 0x728F, 0x4014, 0x519D, 0x2522, 0x34AB, 0x0630, 0x17B9,
    0xEF4E, 0xFEC7, 0xCC5C, 0xDDD5, 0xA96A, 0xB8E3, 0x8A78, 0x9BF1,
    0x7387, 0x620E, 0x5095, 0x411C, 0x35A3, 0x242A, 0x16B1, 0x0738,
    0xFFCF, 0xEE46, 0xDCDD, 0xCD54, 0xB9EB, 0xA862, 0x9AF9, 0x8B70,
    0x8408, 0x9581, 0xA71A, 0xB693, 0xC22C, 0xD3A5, 0xE13E, 0xF0B7,
    0x0840, 0x19C9, 0x2B52, 0x3ADB, 0x4E64, 0x5FED, 0x6D76, 0x7CFF,
    0x9489, 0x8500, 0xB79B, 0xA612, 0xD2AD, 0xC324, 0xF1BF, 0xE036,
    0x18C1, 0x0948, 0x3BD3, 0x2A5A, 0x5EE5, 0x4F6C, 0x7DF7, 0x6C7E,
    0xA50A, 0xB483, 0x8618, 0x9791, 0xE32E, 0xF2A7, 0xC03C, 0xD1B5,
    0x2942, 0x38CB, 0x0A50, 0x1BD9, 0x6F66, 0x7EEF, 0x4C74, 0x5DFD,
    0xB58B, 0xA402, 0x9699, 0x8710, 0xF3AF, 0xE226, 0xD0BD, 0xC134,
    0x39C3, 0x284A, 0x1AD1, 0x0B58, 0x7FE7, 0x6E6E, 0x5CF5, 0x4D7C,
    0xC60C, 0xD785, 0xE51E, 0xF497, 0x8028, 0x91A1, 0xA33A, 0xB2B3,
    0x4A44, 0x5BCD, 0x6956, 0x78DF, 0x0C60, 0x1DE9, 0x2F72, 0x3EFB,
    0xD68D, 0xC704, 0xF59F, 0xE416, 0x90A9, 0x8120, 0xB3BB, 0xA232,
    0x5AC5, 0x4B4C, 0x79D7, 0x685E, 0x1CE1, 0x0D68, 0x3FF3, 0x2E7A,
    0xE70E, 0xF687, 0xC41C, 0xD595, 0xA12A, 0xB0A3, 0x8238, 0x93B1,
    0x6B46, 0x7ACF, 0x4854, 0x59DD, 0x2D62, 0x3CEB, 0x0E70, 0x1FF9,
    0xF78F, 0xE606, 0xD49D, 0xC514, 0xB1AB, 0xA022, 0x92B9, 0x8330,
    0x7BC7, 0x6A4E, 0x58D5, 0x495C, 0x3DE3, 0x2C6A, 0x1EF1, 0x0F78,
};

const u8 gMiscBlank_Gfx[] = INCBIN_U8("graphics/interface/blank.4bpp");

u8 CreateInvisibleSpriteWithCallback(void (*callback)(struct Sprite *))
{
    u8 sprite = CreateSprite(&sInvisibleSpriteTemplate, DISPLAY_WIDTH + 8, DISPLAY_HEIGHT + 8, 14);
    gSprites[sprite].invisible = TRUE;
    gSprites[sprite].callback = callback;
    return sprite;
}

void StoreWordInTwoHalfwords(u16 *h, u32 w)
{
    h[0] = (u16)(w);
    h[1] = (u16)(w >> 16);
}

void LoadWordFromTwoHalfwords(u16 *h, u32 *w)
{
    *w = h[0] | (s16)h[1] << 16;
}

void SetBgAffineStruct(struct BgAffineSrcData *src, u32 texX, u32 texY, s16 scrX, s16 scrY, s16 sx, s16 sy, u16 alpha)
{
    src->texX = texX;
    src->texY = texY;
    src->scrX = scrX;
    src->scrY = scrY;
    src->sx = sx;
    src->sy = sy;
    src->alpha = alpha;
}

void DoBgAffineSet(struct BgAffineDstData *dest, u32 texX, u32 texY, s16 scrX, s16 scrY, s16 sx, s16 sy, u16 alpha)
{
    struct BgAffineSrcData src;

    SetBgAffineStruct(&src, texX, texY, scrX, scrY, sx, sy, alpha);
    BgAffineSet(&src, dest, 1);
}

void CopySpriteTiles(u8 shape, u8 size, u8 *tiles, u16 *tilemap, u8 *output)
{
    u8 x, y;
    s8 i, j;
    u8 ALIGNED(4) xflip[32];
    u8 h = sSpriteDimensions[shape][size][1];
    u8 w = sSpriteDimensions[shape][size][0];

    for (y = 0; y < h; y++)
    {
        for (x = 0; x < w; x++)
        {
            int tile = (*tilemap & 0x3ff) * 32;

            if ((*tilemap & 0xc00) == 0)
            {
                CpuCopy32(tiles + tile, output, 32);
            }
            else if ((*tilemap & 0xc00) == 0x800)  // yflip
            {
                for (i = 0; i < 8; i++)
                    CpuCopy32(tiles + (tile + (7 - i) * 4), output + i * 4, 4);
            }
            else  // xflip
            {
                for (i = 0; i < 8; i++)
                {
                    for (j = 0; j < 4; j++)
                    {
                        u8 i2 = i * 4;
                        xflip[i2 + (3-j)] = (tiles[tile + i2 + j] & 0xf) << 4;
                        xflip[i2 + (3-j)] |= tiles[tile + i2 + j] >> 4;
                    }
                }
                if (*tilemap & 0x800)  // yflip
                {
                    for (i = 0; i < 8; i++)
                        CpuCopy32(xflip + (7 - i) * 4, output + i * 4, 4);
                }
                else
                {
                    CpuCopy32(xflip, output, 32);
                }
            }
            tilemap++;
            output += 32;
        }
        tilemap += (32 - w);
    }
}

int CountTrailingZeroBits(u32 value)
{
    u8 i;

    for (i = 0; i < 32; i++)
    {
        if ((value & 1) == 0)
            value >>= 1;
        else
            return i;
    }
    return 0;
}

u16 CalcCRC16(const u8 *data, s32 length)
{
    u16 i, j;
    u16 crc = 0x1121;

    for (i = 0; i < length; i++)
    {
        crc ^= data[i];
        for (j = 0; j < 8; j++)
        {
            if (crc & 1)
                crc = (crc >> 1) ^ 0x8408;
            else
                crc >>= 1;
        }
    }
    return ~crc;
}

u16 CalcCRC16WithTable(const u8 *data, u32 length)
{
    u16 i;
    u16 crc = 0x1121;
    u8 byte;

    for (i = 0; i < length; i++)
    {
        byte = crc >> 8;
        crc ^= data[i];
        crc = byte ^ sCrc16Table[(u8)crc];
    }
    return ~crc;
}

u32 CalcByteArraySum(const u8 *data, u32 length)
{
    u32 sum, i;
    for (sum = 0, i = 0; i < length; i++)
        sum += data[i];
    return sum;
}

void BlendPalette(u16 palOffset, u16 numEntries, u8 coeff, u32 blendColor)
{
    u16 i;
    struct PlttData *data2 = (struct PlttData *) & blendColor;
    for (i = 0; i < numEntries; i++)
    {
        u16 index = i + palOffset;
        struct PlttData *data1 = (struct PlttData *)&gPlttBufferUnfaded[index];
        s8 r = data1->r;
        s8 g = data1->g;
        s8 b = data1->b;

        gPlttBufferFaded[index] = RGB(r + (((data2->r - r) * coeff) >> 4),
                                      g + (((data2->g - g) * coeff) >> 4),
                                      b + (((data2->b - b) * coeff) >> 4));
    }
}

#define HUE_SHIFT_NORMAL_RANGE 40
#define HUE_SHIFT_SHINY_RANGE  30
#define RGB_ADJUST_RANGE       124

#define LIMITMODE_NORMAL_HUE_POS_SHINY_HUE_NEG       1
#define LIMITMODE_NORMAL_HUE_NEG_SHINY_HUE_POS      -1
#define LIMITMODE_NORMAL_HUE_BOTH_SHINY_HUE_BOTH     0
#define LIMITMODE_NORMAL_RGB_ADJSUT_SHINY_HUE_BOTH   2
#define LIMITMODE_NORMAL_HUE_BOTH_SHINY_RGB_ADJSUT   3
#define LIMITMODE_NORMAL_RGB_ADJSUT_SHINY_RGB_ADJSUT 4

// Limit Mode is inverted for shinies
// Limit mode determines if the hue shift can be positive, negative or both. 
// It also determines if rgb modulation is done instead of proper hsl conversion


// if a mon is not in this list, the limit is zero
static const s8 sHueShiftSpeciesLimit[NUM_SPECIES] =
{
    [SPECIES_CHARIZARD]   = LIMITMODE_NORMAL_HUE_BOTH_SHINY_HUE_BOTH,
    [SPECIES_PIKACHU]     = LIMITMODE_NORMAL_HUE_POS_SHINY_HUE_NEG,
    [SPECIES_RAICHU]      = LIMITMODE_NORMAL_HUE_POS_SHINY_HUE_NEG,
    [SPECIES_CLEFAIRY]    = LIMITMODE_NORMAL_HUE_BOTH_SHINY_HUE_BOTH,
    [SPECIES_CLEFABLE]    = LIMITMODE_NORMAL_HUE_BOTH_SHINY_HUE_BOTH,
    [SPECIES_VULPIX]      = LIMITMODE_NORMAL_HUE_BOTH_SHINY_HUE_BOTH,
    [SPECIES_NINETALES]   = LIMITMODE_NORMAL_HUE_BOTH_SHINY_HUE_BOTH,
    [SPECIES_JIGGLYPUFF]  = LIMITMODE_NORMAL_HUE_BOTH_SHINY_HUE_BOTH,
    [SPECIES_WIGGLYTUFF]  = LIMITMODE_NORMAL_HUE_BOTH_SHINY_HUE_BOTH,
    [SPECIES_PARAS]       = LIMITMODE_NORMAL_HUE_POS_SHINY_HUE_NEG,
    [SPECIES_PARASECT]    = LIMITMODE_NORMAL_HUE_NEG_SHINY_HUE_POS,
    [SPECIES_MEOWTH]      = LIMITMODE_NORMAL_HUE_POS_SHINY_HUE_NEG,
    [SPECIES_PERSIAN]     = LIMITMODE_NORMAL_HUE_NEG_SHINY_HUE_POS,
    [SPECIES_PSYDUCK]     = LIMITMODE_NORMAL_HUE_BOTH_SHINY_HUE_BOTH,
    [SPECIES_GOLDUCK]     = LIMITMODE_NORMAL_HUE_BOTH_SHINY_HUE_BOTH,
    [SPECIES_GROWLITHE]   = LIMITMODE_NORMAL_HUE_POS_SHINY_HUE_NEG,
    [SPECIES_ARCANINE]    = LIMITMODE_NORMAL_HUE_POS_SHINY_HUE_NEG,
    [SPECIES_POLIWAG]     = LIMITMODE_NORMAL_HUE_POS_SHINY_HUE_NEG,
    [SPECIES_POLIWHIRL]   = LIMITMODE_NORMAL_HUE_POS_SHINY_HUE_NEG,
    [SPECIES_ABRA]        = LIMITMODE_NORMAL_HUE_NEG_SHINY_HUE_POS,
    [SPECIES_KADABRA]     = LIMITMODE_NORMAL_HUE_NEG_SHINY_HUE_POS,
    [SPECIES_MACHOP]      = LIMITMODE_NORMAL_RGB_ADJSUT_SHINY_RGB_ADJSUT,
    [SPECIES_MACHOKE]     = LIMITMODE_NORMAL_RGB_ADJSUT_SHINY_RGB_ADJSUT,
    [SPECIES_MACHAMP]     = LIMITMODE_NORMAL_RGB_ADJSUT_SHINY_RGB_ADJSUT,
    [SPECIES_MAGNEMITE]   = LIMITMODE_NORMAL_RGB_ADJSUT_SHINY_RGB_ADJSUT,
    [SPECIES_MAGNETON]    = LIMITMODE_NORMAL_RGB_ADJSUT_SHINY_RGB_ADJSUT,
    [SPECIES_SEEL]        = LIMITMODE_NORMAL_RGB_ADJSUT_SHINY_RGB_ADJSUT,
    [SPECIES_DEWGONG]     = LIMITMODE_NORMAL_RGB_ADJSUT_SHINY_RGB_ADJSUT,
    [SPECIES_GRIMER]      = LIMITMODE_NORMAL_RGB_ADJSUT_SHINY_HUE_BOTH,
    [SPECIES_MUK]         = LIMITMODE_NORMAL_RGB_ADJSUT_SHINY_HUE_BOTH,
    [SPECIES_SHELLDER]    = LIMITMODE_NORMAL_RGB_ADJSUT_SHINY_HUE_BOTH,
    [SPECIES_CLOYSTER]    = LIMITMODE_NORMAL_RGB_ADJSUT_SHINY_HUE_BOTH,
    [SPECIES_GASTLY]      = LIMITMODE_NORMAL_RGB_ADJSUT_SHINY_RGB_ADJSUT,
    [SPECIES_HAUNTER]     = LIMITMODE_NORMAL_RGB_ADJSUT_SHINY_RGB_ADJSUT,
    [SPECIES_GENGAR]      = LIMITMODE_NORMAL_RGB_ADJSUT_SHINY_RGB_ADJSUT,
    [SPECIES_ONIX]        = LIMITMODE_NORMAL_RGB_ADJSUT_SHINY_RGB_ADJSUT,
    [SPECIES_RHYHORN]     = LIMITMODE_NORMAL_RGB_ADJSUT_SHINY_HUE_BOTH,
    [SPECIES_RHYDON]      = LIMITMODE_NORMAL_RGB_ADJSUT_SHINY_HUE_BOTH,
    [SPECIES_SCYTHER]     = LIMITMODE_NORMAL_HUE_POS_SHINY_HUE_NEG,
    [SPECIES_ELECTABUZZ]  = LIMITMODE_NORMAL_HUE_POS_SHINY_HUE_NEG,
    [SPECIES_MAGIKARP]    = LIMITMODE_NORMAL_HUE_NEG_SHINY_HUE_POS,
    [SPECIES_LAPRAS]      = LIMITMODE_NORMAL_HUE_NEG_SHINY_HUE_POS,
    [SPECIES_DITTO]       = LIMITMODE_NORMAL_RGB_ADJSUT_SHINY_RGB_ADJSUT,
    [SPECIES_EEVEE]       = LIMITMODE_NORMAL_HUE_BOTH_SHINY_HUE_BOTH,
    [SPECIES_FLAREON]     = LIMITMODE_NORMAL_HUE_NEG_SHINY_HUE_POS,
    [SPECIES_AERODACTYL]  = LIMITMODE_NORMAL_RGB_ADJSUT_SHINY_HUE_BOTH,
    [SPECIES_SNORLAX]     = LIMITMODE_NORMAL_HUE_POS_SHINY_HUE_NEG,
    [SPECIES_ZAPDOS]      = LIMITMODE_NORMAL_HUE_POS_SHINY_HUE_NEG,
    [SPECIES_MEWTWO]      = LIMITMODE_NORMAL_RGB_ADJSUT_SHINY_HUE_BOTH,
    [SPECIES_HOOTHOOT]    = LIMITMODE_NORMAL_HUE_NEG_SHINY_HUE_POS,
    [SPECIES_NOCTOWL]     = LIMITMODE_NORMAL_HUE_NEG_SHINY_HUE_POS,
    [SPECIES_LEDYBA]      = LIMITMODE_NORMAL_HUE_NEG_SHINY_HUE_POS,
    [SPECIES_LEDIAN]      = LIMITMODE_NORMAL_HUE_NEG_SHINY_HUE_POS,
    [SPECIES_PICHU]       = LIMITMODE_NORMAL_HUE_POS_SHINY_HUE_NEG,
    [SPECIES_TOGEPI]      = LIMITMODE_NORMAL_RGB_ADJSUT_SHINY_RGB_ADJSUT,
    [SPECIES_TOGETIC]     = LIMITMODE_NORMAL_RGB_ADJSUT_SHINY_RGB_ADJSUT,
    [SPECIES_SUNKERN]     = LIMITMODE_NORMAL_HUE_POS_SHINY_HUE_NEG,
    [SPECIES_UMBREON]     = LIMITMODE_NORMAL_HUE_BOTH_SHINY_HUE_BOTH,
    [SPECIES_MURKROW]     = LIMITMODE_NORMAL_RGB_ADJSUT_SHINY_HUE_BOTH,
    [SPECIES_MISDREAVUS]  = LIMITMODE_NORMAL_RGB_ADJSUT_SHINY_HUE_BOTH,
    [SPECIES_UNOWN]       = LIMITMODE_NORMAL_RGB_ADJSUT_SHINY_RGB_ADJSUT,
    [SPECIES_STEELIX]     = LIMITMODE_NORMAL_RGB_ADJSUT_SHINY_RGB_ADJSUT,
    [SPECIES_SHUCKLE]     = LIMITMODE_NORMAL_HUE_BOTH_SHINY_HUE_BOTH,
    [SPECIES_SNEASEL]     = LIMITMODE_NORMAL_RGB_ADJSUT_SHINY_HUE_BOTH,
    [SPECIES_SWINUB]      = LIMITMODE_NORMAL_HUE_BOTH_SHINY_HUE_BOTH,
    [SPECIES_PILOSWINE]   = LIMITMODE_NORMAL_HUE_NEG_SHINY_HUE_POS,
    [SPECIES_MANTINE]     = LIMITMODE_NORMAL_RGB_ADJSUT_SHINY_HUE_BOTH,
    [SPECIES_PHANPY]      = LIMITMODE_NORMAL_RGB_ADJSUT_SHINY_HUE_BOTH,
    [SPECIES_DONPHAN]     = LIMITMODE_NORMAL_RGB_ADJSUT_SHINY_HUE_BOTH,
    [SPECIES_SMEARGLE]    = LIMITMODE_NORMAL_RGB_ADJSUT_SHINY_RGB_ADJSUT,
    [SPECIES_ELEKID]      = LIMITMODE_NORMAL_HUE_POS_SHINY_HUE_NEG,
    [SPECIES_MILTANK]     = LIMITMODE_NORMAL_HUE_BOTH_SHINY_HUE_BOTH,
    [SPECIES_LARVITAR]    = LIMITMODE_NORMAL_HUE_POS_SHINY_HUE_NEG,
    [SPECIES_PUPITAR]     = LIMITMODE_NORMAL_HUE_NEG_SHINY_HUE_POS,
    [SPECIES_LUGIA]       = LIMITMODE_NORMAL_RGB_ADJSUT_SHINY_RGB_ADJSUT,
    [SPECIES_POOCHYENA]   = LIMITMODE_NORMAL_RGB_ADJSUT_SHINY_HUE_BOTH,
    [SPECIES_MIGHTYENA]   = LIMITMODE_NORMAL_RGB_ADJSUT_SHINY_HUE_BOTH,
    [SPECIES_ZIGZAGOON]   = LIMITMODE_NORMAL_RGB_ADJSUT_SHINY_HUE_BOTH,
    [SPECIES_LINOONE]     = LIMITMODE_NORMAL_RGB_ADJSUT_SHINY_HUE_BOTH,
    [SPECIES_SABLEYE]     = LIMITMODE_NORMAL_RGB_ADJSUT_SHINY_RGB_ADJSUT,
    [SPECIES_ARON]        = LIMITMODE_NORMAL_RGB_ADJSUT_SHINY_RGB_ADJSUT,
    [SPECIES_LAIRON]      = LIMITMODE_NORMAL_RGB_ADJSUT_SHINY_RGB_ADJSUT,
    [SPECIES_AGGRON]      = LIMITMODE_NORMAL_RGB_ADJSUT_SHINY_RGB_ADJSUT,
    [SPECIES_SPOINK]      = LIMITMODE_NORMAL_RGB_ADJSUT_SHINY_HUE_BOTH,
    [SPECIES_GRUMPIG]     = LIMITMODE_NORMAL_RGB_ADJSUT_SHINY_HUE_BOTH,
    [SPECIES_TRAPINCH]    = LIMITMODE_NORMAL_HUE_BOTH_SHINY_HUE_BOTH,
    [SPECIES_CRAWDAUNT]   = LIMITMODE_NORMAL_HUE_NEG_SHINY_HUE_POS,
    [SPECIES_FEEBAS]      = LIMITMODE_NORMAL_HUE_BOTH_SHINY_HUE_BOTH,
    [SPECIES_CASTFORM]    = LIMITMODE_NORMAL_RGB_ADJSUT_SHINY_RGB_ADJSUT,
    [SPECIES_SHUPPET]     = LIMITMODE_NORMAL_RGB_ADJSUT_SHINY_HUE_BOTH,
    [SPECIES_BANETTE]     = LIMITMODE_NORMAL_RGB_ADJSUT_SHINY_HUE_BOTH,
    [SPECIES_DUSKULL]     = LIMITMODE_NORMAL_RGB_ADJSUT_SHINY_HUE_BOTH,
    [SPECIES_DUSCLOPS]    = LIMITMODE_NORMAL_RGB_ADJSUT_SHINY_HUE_BOTH,
    [SPECIES_ABSOL]       = LIMITMODE_NORMAL_RGB_ADJSUT_SHINY_RGB_ADJSUT,
    [SPECIES_REGISTEEL]   = LIMITMODE_NORMAL_RGB_ADJSUT_SHINY_RGB_ADJSUT,
    [SPECIES_LATIAS]      = LIMITMODE_NORMAL_HUE_NEG_SHINY_HUE_POS,
    [SPECIES_RAYQUAZA]    = LIMITMODE_NORMAL_HUE_BOTH_SHINY_HUE_BOTH,
    // todo - add limits for any mons after gen3 that need them
};

u32 GetMaxColorationRange(u16 species, bool8 isShiny)
{
    s8 limitMode = sHueShiftSpeciesLimit[species];
    u32 range;
    if (isShiny)
    {
        if (limitMode == LIMITMODE_NORMAL_HUE_BOTH_SHINY_RGB_ADJSUT
         || limitMode == LIMITMODE_NORMAL_RGB_ADJSUT_SHINY_RGB_ADJSUT)
            range = RGB_ADJUST_RANGE;
        else if (limitMode == LIMITMODE_NORMAL_HUE_POS_SHINY_HUE_NEG
              || limitMode == LIMITMODE_NORMAL_HUE_NEG_SHINY_HUE_POS)
            range = HUE_SHIFT_SHINY_RANGE;
        else
            range = 2 * HUE_SHIFT_SHINY_RANGE;
    }
    else
    {
        if (limitMode == LIMITMODE_NORMAL_RGB_ADJSUT_SHINY_HUE_BOTH
         || limitMode == LIMITMODE_NORMAL_RGB_ADJSUT_SHINY_RGB_ADJSUT)
            range = RGB_ADJUST_RANGE;
        else if (limitMode == LIMITMODE_NORMAL_HUE_POS_SHINY_HUE_NEG
              || limitMode == LIMITMODE_NORMAL_HUE_NEG_SHINY_HUE_POS)
            range = HUE_SHIFT_NORMAL_RANGE;
        else
            range = 2 * HUE_SHIFT_NORMAL_RANGE;
    }
    return range;
}

u32 CreateNewColoration(u16 species, bool8 isShiny)
{
    u32 range = GetMaxColorationRange(species, isShiny);
    return (Random32() % (range + 1));
}

void MakePaletteUnique(u16 palOffset, u16 species, u32 value, bool8 isShiny)
{
    // System made by Citrus Bolt :')
    u16 i, range;
    s32 shift;
    s8 limitMode = sHueShiftSpeciesLimit[species];

    if (isShiny)
        range = HUE_SHIFT_SHINY_RANGE;
    else
        range = HUE_SHIFT_NORMAL_RANGE;

    if (limitMode == -1)
        shift = value - range;
    else if (limitMode == 1)
        shift = value;
    else
        shift = value - range;

    if ((limitMode == LIMITMODE_NORMAL_RGB_ADJSUT_SHINY_HUE_BOTH && !isShiny)
    || (limitMode == LIMITMODE_NORMAL_HUE_BOTH_SHINY_RGB_ADJSUT && isShiny)
    || limitMode == LIMITMODE_NORMAL_RGB_ADJSUT_SHINY_RGB_ADJSUT)
    {
        s8 dr = (value / 25) % 5;
        s8 dg = (value / 5) % 5;
        s8 db = value % 5;

        for (i = 0; i < 16; i++)
        {
            u16 index = i + palOffset;
            struct PlttData *data1 = (struct PlttData *)&gPlttBufferUnfaded[index];
            s8 r = data1->r + dr - 2;
            s8 g = data1->g + dg - 2;
            s8 b = data1->b + db - 2;

            if (r > 31)
                r = 31 - dr / 2;
            if (g > 31)
                g = 31 - dg / 2;
            if (b > 31)
                b = 31 - db / 2;
            if (r < 0)
                r = dr / 2;
            if (g < 0)
                g = dg / 2;
            if (b < 0)
                b = db / 2;

            gPlttBufferFaded[index] = RGB(r, g, b);
        }
    }
    else
    {
        for (i = 0; i < 16; i++)
        {
            u16 index = i + palOffset;
            struct PlttData *data1 = (struct PlttData *)&gPlttBufferUnfaded[index];
            s32 r = (data1->r * 1000) / 31;
            s32 g = (data1->g * 1000) / 31;
            s32 b = (data1->b * 1000) / 31;
            s32 maxv, minv, d, h, s, l, o, p, q;

            if (r > g)
                maxv = r;
            else
                maxv = g;
            if (b > maxv)
                maxv = b;
            if (r < g)
                minv = r;
            else
                minv = g;
            if (b < minv)
                minv = b;

            d = maxv - minv;
            h = 0;
            s = 0;
            l = (maxv + minv) / 2;

            if  (maxv != minv)
            {
                if (l > 500)
                    s = 1000 * d / (2000 - maxv - minv);
                else
                    s = 1000 * d / (maxv + minv);
                if (maxv == r)
                {
                    if (g < b)
                        h = 1000 * (g - b) / d + 6000;
                    else
                        h = 1000 * (g - b) / d;
                }
                else if (maxv == g)
                {
                    h = 1000 * (b - r) / d + 2000;
                }
                else
                {
                    h = 1000 * (r - g) / d + 4000;
                }
                h /= 6;
            }

            h = (h + shift + 1000) % 1000;

            if (s != 0)
            {
                o = (h + 333) % 1000;

                if (l < 500)
                    p = l * (s + 1000) / 1000;
                else
                    p = l + s - l * s / 1000;

                q = l * 2 - p;

                if (o < 167)
                    r = q + (p - q) * o * 6 / 1000;
                else if (o < 500)
                    r = p;
                else if (o < 667)
                    r = q + (p - q) * (667 - o) * 6 / 1000;
                else
                    r = q;

                o = h;

                if (o < 167)
                    g = q + (p - q) * o * 6 / 1000;
                else if (o < 500)
                    g = p;
                else if (o < 667)
                    g = q + (p - q) * (667 - o) * 6 / 1000;
                else
                    g = q;

                o = (h + 1000 - 333) % 1000;

                if (o < 167)
                    b = q + (p - q) * o * 6 / 1000;
                else if (o < 500)
                    b = p;
                else if (o < 667)
                    b = q + (p - q) * (667 - o) * 6 / 1000;
                else
                    b = q;
            }
            else
            {
                r = l;
                g = l;
                b = l;
            }

            gPlttBufferFaded[index] = RGB((u8)(r * 31 / 1000), (u8)(g * 31 / 1000), (u8)(b * 31 / 1000));
        }
    }
}

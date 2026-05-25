#include "global.h"
#include "palette.h"
#include "pokemon.h"
#include "sprite.h"

EWRAM_DATA u16 gDiverseEggPalette[16] = {0};

const u32 sMonsterGroupEggGfx[] = INCGFX_U32("graphics/eggs/monster.png", ".4bpp.smol");
const u32 sWater1GroupEggGfx[] = INCGFX_U32("graphics/eggs/water1.png", ".4bpp.smol");
const u32 sBugGroupEggGfx[] = INCGFX_U32("graphics/eggs/bug.png", ".4bpp.smol");
const u32 sFlyingGroupEggGfx[] = INCGFX_U32("graphics/eggs/flying.png", ".4bpp.smol");
const u32 sFieldGroupEggGfx[] = INCGFX_U32("graphics/eggs/field.png", ".4bpp.smol");
const u32 sFairyGroupEggGfx[] = INCGFX_U32("graphics/eggs/fairy.png", ".4bpp.smol");
const u32 sGrassGroupEggGfx[] = INCGFX_U32("graphics/eggs/grass.png", ".4bpp.smol");
const u32 sHumanLikeGroupEggGfx[] = INCGFX_U32("graphics/eggs/human_like.png", ".4bpp.smol");
const u32 sWater3GroupEggGfx[] = INCGFX_U32("graphics/eggs/water3.png", ".4bpp.smol");
const u32 sMineralGroupEggGfx[] = INCGFX_U32("graphics/eggs/rock.png", ".4bpp.smol");
const u32 sAmorphousGroupEggGfx[] = INCGFX_U32("graphics/eggs/amorphous.png", ".4bpp.smol");
const u32 sDragonGroupEggGfx[] = INCGFX_U32("graphics/eggs/dragon.png", ".4bpp.smol");
const u32 sWater2GroupEggGfx[] = INCGFX_U32("graphics/eggs/water2.png", ".4bpp.smol");

const u16 sNormalTypeEggPal[] = INCGFX_U16("graphics/eggs/normal.pal", ".gbapal");
const u16 sFightingTypeEggPal[] = INCGFX_U16("graphics/eggs/fighting.pal", ".gbapal");
const u16 sFlyingTypeEggPal[] = INCGFX_U16("graphics/eggs/flying.pal", ".gbapal");
const u16 sPoisonTypeEggPal[] = INCGFX_U16("graphics/eggs/poison.pal", ".gbapal");
const u16 sGroundTypeEggPal[] = INCGFX_U16("graphics/eggs/ground.pal", ".gbapal");
const u16 sRockTypeEggPal[] = INCGFX_U16("graphics/eggs/rock.pal", ".gbapal");
const u16 sBugTypeEggPal[] = INCGFX_U16("graphics/eggs/bug.pal", ".gbapal");
const u16 sGhostTypeEggPal[] = INCGFX_U16("graphics/eggs/ghost.pal", ".gbapal");
const u16 sSteelTypeEggPal[] = INCGFX_U16("graphics/eggs/steel.pal", ".gbapal");
const u16 sFireTypeEggPal[] = INCGFX_U16("graphics/eggs/fire.pal", ".gbapal");
const u16 sWaterTypeEggPal[] = INCGFX_U16("graphics/eggs/water.pal", ".gbapal");
const u16 sGrassTypeEggPal[] = INCGFX_U16("graphics/eggs/grass.pal", ".gbapal");
const u16 sElectricTypeEggPal[] = INCGFX_U16("graphics/eggs/electric.pal", ".gbapal");
const u16 sPsychicTypeEggPal[] = INCGFX_U16("graphics/eggs/psychic.pal", ".gbapal");
const u16 sIceTypeEggPal[] = INCGFX_U16("graphics/eggs/ice.pal", ".gbapal");
const u16 sDragonTypeEggPal[] = INCGFX_U16("graphics/eggs/dragon.pal", ".gbapal");
const u16 sDarkTypeEggPal[] = INCGFX_U16("graphics/eggs/dark.pal", ".gbapal");
const u16 sFairyTypeEggPal[] = INCGFX_U16("graphics/eggs/fairy.pal", ".gbapal");

const u16 *const sEggTypePalettes[NUMBER_OF_MON_TYPES] =
{
    [TYPE_NONE]     = sWaterTypeEggPal,
    [TYPE_NORMAL]   = sNormalTypeEggPal,
    [TYPE_FIGHTING] = sFightingTypeEggPal,
    [TYPE_FLYING]   = sFlyingTypeEggPal,
    [TYPE_POISON]   = sPoisonTypeEggPal,
    [TYPE_GROUND]   = sGroundTypeEggPal,
    [TYPE_ROCK]     = sRockTypeEggPal,
    [TYPE_BUG]      = sBugTypeEggPal,
    [TYPE_GHOST]    = sGhostTypeEggPal,
    [TYPE_STEEL]    = sSteelTypeEggPal,
    [TYPE_MYSTERY]  = sWaterTypeEggPal,
    [TYPE_FIRE]     = sFireTypeEggPal,
    [TYPE_WATER]    = sWaterTypeEggPal,
    [TYPE_GRASS]    = sGrassTypeEggPal,
    [TYPE_ELECTRIC] = sElectricTypeEggPal,
    [TYPE_PSYCHIC]  = sPsychicTypeEggPal,
    [TYPE_ICE]      = sIceTypeEggPal,
    [TYPE_DRAGON]   = sDragonTypeEggPal,
    [TYPE_DARK]     = sDarkTypeEggPal,
    [TYPE_FAIRY]    = sFairyTypeEggPal,
    [TYPE_STELLAR]  = sWaterTypeEggPal,
};

/*
void LoadEggPalette(enum Species species)
{
    u32 palIndex = 0;
    enum Type type0 = GetSpeciesType(species, 0);
    palIndex = LoadSpritePaletteWithTag(sEggTypePalettes[type0], SPECIES_EGG);

    enum Type type1 = GetSpeciesType(species, 1);
    for (u32 i = 7; i <= 11; i++)
    {
        gPlttBufferUnfaded[OBJ_PLTT_ID(palIndex) + i] = sEggTypePalettes[type1][i];
        gPlttBufferFaded[OBJ_PLTT_ID(palIndex) + i] = sEggTypePalettes[type1][i];
    }
}
*/

u16 *LoadEggPalette(enum Species species)
{
    enum Type type0 = GetSpeciesType(species, 0);
    memcpy(gDiverseEggPalette, sEggTypePalettes[type0], 32);
    enum Type type1 = GetSpeciesType(species, 1);
    for (u32 i = 7; i <= 11; i++)
    {
        gDiverseEggPalette[i] = sEggTypePalettes[type1][i];
    }
    return gDiverseEggPalette;
}

const u32 *GetEggSpriteData(enum Species species)
{
    u32 eggGroup = gSpeciesInfo[species].eggGroups[0];
    switch (eggGroup)
    {
    case EGG_GROUP_MONSTER:
        return sMonsterGroupEggGfx;
    case EGG_GROUP_WATER_1:
        return sWater1GroupEggGfx;
    case EGG_GROUP_BUG:
        return sBugGroupEggGfx;
    case EGG_GROUP_FLYING:
        return sFlyingGroupEggGfx;
    case EGG_GROUP_FIELD:
        return sFieldGroupEggGfx;
    case EGG_GROUP_FAIRY:
        return sFairyGroupEggGfx;
    case EGG_GROUP_GRASS:
        return sGrassGroupEggGfx;
    case EGG_GROUP_HUMAN_LIKE:
        return sHumanLikeGroupEggGfx;
    case EGG_GROUP_WATER_3:
        return sWater3GroupEggGfx;
    case EGG_GROUP_MINERAL:
        return sMineralGroupEggGfx;
    case EGG_GROUP_AMORPHOUS:
        return sAmorphousGroupEggGfx;
    case EGG_GROUP_WATER_2:
        return sWater2GroupEggGfx;
    case EGG_GROUP_DITTO:
        return gSpeciesInfo[SPECIES_EGG].frontPic;
    case EGG_GROUP_DRAGON:
        return sDragonGroupEggGfx;
    default:
        errorf("Trying to show picture of egg from species %d in unknown group %d", species, eggGroup);
        return gSpeciesInfo[SPECIES_EGG].frontPic;
    }

}

bool32 IsKnownEggGroup(enum Species species)
{
    u32 eggGroup = gSpeciesInfo[species].eggGroups[0];
    if (eggGroup == EGG_GROUP_DITTO)
        return FALSE;
    if (eggGroup > EGG_GROUP_NONE && eggGroup < EGG_GROUP_NO_EGGS_DISCOVERED)
        return TRUE;
    return FALSE;
}
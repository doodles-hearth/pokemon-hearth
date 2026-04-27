#include "global.h"
#include "palette.h"
#include "pokemon.h"
#include "sprite.h"

EWRAM_DATA u16 gDiverseEggPalette[16] = {0};

const u32 sMonsterGroupEggGfx[] = INCBIN_U32("graphics/eggs/monster.4bpp.smol");
const u32 sWater1GroupEggGfx[] = INCBIN_U32("graphics/eggs/water1.4bpp.smol");
const u32 sBugGroupEggGfx[] = INCBIN_U32("graphics/eggs/bug.4bpp.smol");
const u32 sFlyingGroupEggGfx[] = INCBIN_U32("graphics/eggs/flying.4bpp.smol");
const u32 sFieldGroupEggGfx[] = INCBIN_U32("graphics/eggs/field.4bpp.smol");
const u32 sFairyGroupEggGfx[] = INCBIN_U32("graphics/eggs/fairy.4bpp.smol");
const u32 sGrassGroupEggGfx[] = INCBIN_U32("graphics/eggs/grass.4bpp.smol");
const u32 sHumanLikeGroupEggGfx[] = INCBIN_U32("graphics/eggs/human_like.4bpp.smol");
const u32 sWater3GroupEggGfx[] = INCBIN_U32("graphics/eggs/water3.4bpp.smol");
const u32 sMineralGroupEggGfx[] = INCBIN_U32("graphics/eggs/rock.4bpp.smol");
const u32 sAmorphousGroupEggGfx[] = INCBIN_U32("graphics/eggs/amorphous.4bpp.smol");
const u32 sDragonGroupEggGfx[] = INCBIN_U32("graphics/eggs/dragon.4bpp.smol");
const u32 sWater2GroupEggGfx[] = INCBIN_U32("graphics/eggs/water2.4bpp.smol");

const u32 sMonsterGroupEggHatchGfx[] = INCBIN_U32("graphics/eggs/hatch/monster.4bpp.smol");
const u32 sWater1GroupEggHatchGfx[] = INCBIN_U32("graphics/eggs/hatch/water1.4bpp.smol");
const u32 sBugGroupEggHatchGfx[] = INCBIN_U32("graphics/eggs/hatch/bug.4bpp.smol");
const u32 sFlyingGroupEggHatchGfx[] = INCBIN_U32("graphics/eggs/hatch/flying.4bpp.smol");
const u32 sFieldGroupEggHatchGfx[] = INCBIN_U32("graphics/eggs/hatch/field.4bpp.smol");
const u32 sFairyGroupEggHatchGfx[] = INCBIN_U32("graphics/eggs/hatch/fairy.4bpp.smol");
const u32 sGrassGroupEggHatchGfx[] = INCBIN_U32("graphics/eggs/hatch/grass.4bpp.smol");
const u32 sHumanLikeGroupEggHatchGfx[] = INCBIN_U32("graphics/eggs/hatch/human_like.4bpp.smol");
const u32 sWater3GroupEggHatchGfx[] = INCBIN_U32("graphics/eggs/hatch/water3.4bpp.smol");
const u32 sMineralGroupEggHatchGfx[] = INCBIN_U32("graphics/eggs/hatch/rock.4bpp.smol");
const u32 sAmorphousGroupEggHatchGfx[] = INCBIN_U32("graphics/eggs/hatch/amorphous.4bpp.smol");
const u32 sDragonGroupEggHatchGfx[] = INCBIN_U32("graphics/eggs/hatch/dragon.4bpp.smol");
const u32 sWater2GroupEggHatchGfx[] = INCBIN_U32("graphics/eggs/hatch/water2.4bpp.smol");

const u16 sNormalTypeEggPal[] = INCBIN_U16("graphics/eggs/normal.gbapal");
const u16 sFightingTypeEggPal[] = INCBIN_U16("graphics/eggs/fighting.gbapal");
const u16 sFlyingTypeEggPal[] = INCBIN_U16("graphics/eggs/flying.gbapal");
const u16 sPoisonTypeEggPal[] = INCBIN_U16("graphics/eggs/poison.gbapal");
const u16 sGroundTypeEggPal[] = INCBIN_U16("graphics/eggs/ground.gbapal");
const u16 sRockTypeEggPal[] = INCBIN_U16("graphics/eggs/rock.gbapal");
const u16 sBugTypeEggPal[] = INCBIN_U16("graphics/eggs/bug.gbapal");
const u16 sGhostTypeEggPal[] = INCBIN_U16("graphics/eggs/ghost.gbapal");
const u16 sSteelTypeEggPal[] = INCBIN_U16("graphics/eggs/steel.gbapal");
const u16 sFireTypeEggPal[] = INCBIN_U16("graphics/eggs/fire.gbapal");
const u16 sWaterTypeEggPal[] = INCBIN_U16("graphics/eggs/water.gbapal");
const u16 sGrassTypeEggPal[] = INCBIN_U16("graphics/eggs/grass.gbapal");
const u16 sElectricTypeEggPal[] = INCBIN_U16("graphics/eggs/electric.gbapal");
const u16 sPsychicTypeEggPal[] = INCBIN_U16("graphics/eggs/psychic.gbapal");
const u16 sIceTypeEggPal[] = INCBIN_U16("graphics/eggs/ice.gbapal");
const u16 sDragonTypeEggPal[] = INCBIN_U16("graphics/eggs/dragon.gbapal");
const u16 sDarkTypeEggPal[] = INCBIN_U16("graphics/eggs/dark.gbapal");
const u16 sFairyTypeEggPal[] = INCBIN_U16("graphics/eggs/fairy.gbapal");

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
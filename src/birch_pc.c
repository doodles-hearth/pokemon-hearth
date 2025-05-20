#include "global.h"
#include "event_data.h"
#include "field_message_box.h"
#include "pokedex.h"
#include "strings.h"

bool16 ScriptGetPokedexInfo(void)
{
    if (gSpecialVar_0x8004 == 0) // is national dex not present?
    {
        gSpecialVar_0x8005 = GetHoennPokedexCount(FLAG_GET_SEEN);
        gSpecialVar_0x8006 = GetHoennPokedexCount(FLAG_GET_CAUGHT);
    }
    else
    {
        gSpecialVar_0x8005 = GetNationalPokedexCount(FLAG_GET_SEEN);
        gSpecialVar_0x8006 = GetNationalPokedexCount(FLAG_GET_CAUGHT);
    }

    return IsNationalPokedexEnabled();
}

#define BIRCH_DEX_STRINGS 21

static const u8 *const sBirchDexRatingTexts[BIRCH_DEX_STRINGS] =
{
    gHearthDexRatingText_LessThan10,
    gHearthDexRatingText_LessThan20,
    gHearthDexRatingText_LessThan30,
    gHearthDexRatingText_LessThan40,
    gHearthDexRatingText_LessThan50,
    gHearthDexRatingText_LessThan60,
    gHearthDexRatingText_LessThan70,
    gHearthDexRatingText_LessThan80,
    gHearthDexRatingText_LessThan90,
    gHearthDexRatingText_LessThan100,
    gHearthDexRatingText_LessThan110,
    gHearthDexRatingText_LessThan120,
    gHearthDexRatingText_LessThan130,
    gHearthDexRatingText_LessThan140,
    gHearthDexRatingText_LessThan150,
    gHearthDexRatingText_LessThan160,
    gHearthDexRatingText_LessThan170,
    gHearthDexRatingText_LessThan180,
    gHearthDexRatingText_LessThan190,
    gHearthDexRatingText_LessThan200,
    gHearthDexRatingText_DexCompleted,
};

// This shows your Hoenn Pokédex rating and not your National Dex.
const u8 *GetPokedexRatingText(u32 count)
{
    u32 i, j;
    u16 maxDex = HOENN_DEX_COUNT - 1;
    // doesNotCountForRegionalPokedex
    for(i = 0; i < HOENN_DEX_COUNT; i++)
    {
        j = NationalPokedexNumToSpecies(HoennToNationalOrder(i + 1));
        if (gSpeciesInfo[j].isMythical && !gSpeciesInfo[j].dexForceRequired)
        {
            if (GetSetPokedexFlag(j, FLAG_GET_CAUGHT))
                count--;
            maxDex--;
        }
    }
    return sBirchDexRatingTexts[(count * (BIRCH_DEX_STRINGS - 1)) / maxDex];
}

void ShowPokedexRatingMessage(void)
{
    ShowFieldMessage(GetPokedexRatingText(gSpecialVar_0x8004));
}

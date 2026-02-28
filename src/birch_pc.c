#include "global.h"
#include "event_data.h"
#include "field_message_box.h"
#include "pokedex.h"
#include "strings.h"

bool16 ScriptGetPokedexInfo(void)
{
    if (gSpecialVar_0x8004 == 0) // is national dex not present?
    {
        gSpecialVar_0x8005 = GetRegionalPokedexCount(FLAG_GET_SEEN);
        gSpecialVar_0x8006 = GetRegionalPokedexCount(FLAG_GET_CAUGHT);
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
    u16 maxDex = REGIONAL_DEX_COUNT - 1;
    // doesNotCountForRegionalPokedex
    for (i = 0; i < REGIONAL_DEX_COUNT; i++)
    {
        j = NationalPokedexNumToSpecies(RegionalToNationalOrder(i + 1));
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

// FRLG
extern const u8 PokedexRating_Text_LessThan10[];
extern const u8 PokedexRating_Text_LessThan20[];
extern const u8 PokedexRating_Text_LessThan30[];
extern const u8 PokedexRating_Text_LessThan40[];
extern const u8 PokedexRating_Text_LessThan50[];
extern const u8 PokedexRating_Text_LessThan60[];
extern const u8 PokedexRating_Text_LessThan70[];
extern const u8 PokedexRating_Text_LessThan80[];
extern const u8 PokedexRating_Text_LessThan90[];
extern const u8 PokedexRating_Text_LessThan100[];
extern const u8 PokedexRating_Text_LessThan110[];
extern const u8 PokedexRating_Text_LessThan120[];
extern const u8 PokedexRating_Text_LessThan130[];
extern const u8 PokedexRating_Text_LessThan140[];
extern const u8 PokedexRating_Text_LessThan150[];
extern const u8 PokedexRating_Text_Complete[];

u16 GetFrlgPokedexCount(void)
{
    if (gSpecialVar_0x8004 == 0)
    {
        gSpecialVar_0x8005 = GetKantoPokedexCount(FLAG_GET_SEEN);
        gSpecialVar_0x8006 = GetKantoPokedexCount(FLAG_GET_CAUGHT);
    }
    else
    {
        gSpecialVar_0x8005 = GetNationalPokedexCount(FLAG_GET_SEEN);
        gSpecialVar_0x8006 = GetNationalPokedexCount(FLAG_GET_CAUGHT);
    }
    return IsNationalPokedexEnabled();
}

static const u8 *GetProfOaksRatingMessageByCount(u16 count)
{
    gSpecialVar_Result = FALSE;

    if (count > 0 && GetSetPokedexFlag(NATIONAL_DEX_MEW, FLAG_GET_CAUGHT))
        count--;

    if (count < 10)
        return PokedexRating_Text_LessThan10;

    if (count < 20)
        return PokedexRating_Text_LessThan20;

    if (count < 30)
        return PokedexRating_Text_LessThan30;

    if (count < 40)
        return PokedexRating_Text_LessThan40;

    if (count < 50)
        return PokedexRating_Text_LessThan50;

    if (count < 60)
        return PokedexRating_Text_LessThan60;

    if (count < 70)
        return PokedexRating_Text_LessThan70;

    if (count < 80)
        return PokedexRating_Text_LessThan80;

    if (count < 90)
        return PokedexRating_Text_LessThan90;

    if (count < 100)
        return PokedexRating_Text_LessThan100;

    if (count < 110)
        return PokedexRating_Text_LessThan110;

    if (count < 120)
        return PokedexRating_Text_LessThan120;

    if (count < 130)
        return PokedexRating_Text_LessThan130;

    if (count < 140)
        return PokedexRating_Text_LessThan140;

    if (count < KANTO_DEX_COUNT - 1)
        return PokedexRating_Text_LessThan150;

    gSpecialVar_Result = TRUE;
    return PokedexRating_Text_Complete;
}

void GetProfOaksRatingMessage(void)
{
    ShowFieldMessage(GetProfOaksRatingMessageByCount(gSpecialVar_0x8004));
}


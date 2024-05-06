#include "constants/abilities.h"
#include "species_info/shared_dex_text.h"

// Macros for ease of use.

#define EVOLUTION(...) (const struct Evolution[]) { __VA_ARGS__, { EVOLUTIONS_END }, }

#if P_FOOTPRINTS
#define FOOTPRINT(sprite) .footprint = gMonFootprint_## sprite,
#else
#define FOOTPRINT(sprite)
#endif

#define SIZE_32x32 1
#define SIZE_64x64 0

// Set .compressed = OW_GFX_COMPRESS
#define COMP OW_GFX_COMPRESS

#if OW_FOLLOWERS_ENABLED
#if OW_FOLLOWERS_SHARE_PALETTE == FALSE
#define FOLLOWER_PAL(...)                                   \
    .followerPalette = DEFAULT(NULL, __VA_ARGS__),          \
    .followerShinyPalette = DEFAULT_2(NULL, __VA_ARGS__),
#else
#define FOLLOWER_PAL(...)
#endif

#define FOLLOWER(name, _size, shadow, _tracks, ...)                                         \
.followerData = {                                                                           \
    .tileTag = TAG_NONE,                                                                    \
    .paletteTag = OBJ_EVENT_PAL_TAG_DYNAMIC,                                                \
    .reflectionPaletteTag = OBJ_EVENT_PAL_TAG_NONE,                                         \
    .size = (_size == SIZE_32x32 ? 512 : 2048),                                             \
    .width = (_size == SIZE_32x32 ? 32 : 64),                                               \
    .height = (_size == SIZE_32x32 ? 32 : 64),                                              \
    .paletteSlot = PALSLOT_NPC_1,                                                           \
    .shadowSize = shadow,                                                                   \
    .inanimate = FALSE,                                                                     \
    .compressed = COMP,                                                                     \
    .tracks = _tracks,                                                                      \
    .oam = (_size == SIZE_32x32 ? &gObjectEventBaseOam_32x32 : &gObjectEventBaseOam_64x64), \
    .subspriteTables = (_size == SIZE_32x32 ? sOamTables_32x32 : sOamTables_64x64),         \
    .anims = sAnimTable_Following,                                                          \
    .images = sPicTable_##name,                                                             \
    .affineAnims = gDummySpriteAffineAnimTable,                                             \
},                                                                                          \
    FOLLOWER_PAL(__VA_ARGS__)
#else
#define FOLLOWER(name, _size, shadow, _tracks, ...)
#endif

// Maximum value for a female Pokémon is 254 (MON_FEMALE) which is 100% female.
// 255 (MON_GENDERLESS) is reserved for genderless Pokémon.
#define PERCENT_FEMALE(percent) min(254, ((percent * 255) / 100))

#define MON_TYPES(type1, ...) { type1, DEFAULT(type1, __VA_ARGS__) }
#define MON_EGG_GROUPS(group1, ...) { group1, DEFAULT(group1, __VA_ARGS__) }

#define FLIP    0
#define NO_FLIP 1

#if POKEMON_NAME_LENGTH >= 12
#define HANDLE_EXPANDED_SPECIES_NAME(_name, ...) _(DEFAULT(_name, __VA_ARGS__))
#else
#define HANDLE_EXPANDED_SPECIES_NAME(_name, ...) _(_name)
#endif

const struct SpeciesInfo gSpeciesInfo[] =
{
    [SPECIES_NONE] =
    {
        .speciesName = _("??????????"),
        .cryId = CRY_NONE,
        .natDexNum = NATIONAL_DEX_NONE,
        .categoryName = _("Unknown"),
        .height = 0,
        .weight = 0,
        .description = COMPOUND_STRING(
            "This is a newly discovered Pokémon.\n"
            "It is currently under investigation.\n"
            "No detailed information is available\n"
            "at this time."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_CircledQuestionMark,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_None,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_CircledQuestionMark,
        .backPicSize = MON_COORDS_SIZE(40, 40),
        .backPicYOffset = 12,
        .backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_CircledQuestionMark,
        .shinyPalette = gMonShinyPalette_CircledQuestionMark,
        .iconSprite = gMonIcon_QuestionMark,
        .iconPalIndex = 0,
    #if OW_FOLLOWERS_ENABLED
        .followerData = {TAG_NONE, OBJ_EVENT_PAL_TAG_SUBSTITUTE, OBJ_EVENT_PAL_TAG_NONE, 512, 32, 32, 2, SHADOW_SIZE_M, FALSE, COMP, TRACKS_FOOT, &gObjectEventBaseOam_32x32, sOamTables_32x32, sAnimTable_Following, sPicTable_Substitute, gDummySpriteAffineAnimTable},
    #endif
        .levelUpLearnset = sNoneLevelUpLearnset,
        .teachableLearnset = sNoneTeachableLearnset,
    },

    #include "species_info/gen_1_families.h"
    #include "species_info/gen_2_families.h"
    #include "species_info/gen_3_families.h"
    #include "species_info/gen_4_families.h"
    #include "species_info/gen_5_families.h"
    #include "species_info/gen_6_families.h"
    #include "species_info/gen_7_families.h"
    #include "species_info/gen_8_families.h"
    #include "species_info/gen_9_families.h"

    [SPECIES_EGG] =
    {
        .frontPic = gMonFrontPic_Egg,
        .frontPicSize = MON_COORDS_SIZE(24, 24),
        .frontPicYOffset = 20,
        .backPic = gMonFrontPic_Egg,
        .backPicSize = MON_COORDS_SIZE(24, 24),
        .backPicYOffset = 20,
        .palette = gMonPalette_Egg,
        .shinyPalette = gMonPalette_Egg,
        .iconSprite = gMonIcon_Egg,
        .iconPalIndex = 1,
    },

    /* You may add any custom species below this point based on the following structure: */

    [SPECIES_KOTORA] =
    {
        .baseHP        = 45,
        .baseAttack    = 65,
        .baseDefense   = 34,
        .baseSpeed     = 45,
        .baseSpAttack  = 40,
        .baseSpDefense = 34,
        .types = MON_TYPES(TYPE_ELECTRIC),
        .catchRate = 235,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 53 : 60,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_RIVALRY, ABILITY_INTIMIDATE, ABILITY_GUTS },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Kotora"),
        .cryId = CRY_JOLTIK,
        .natDexNum = NATIONAL_DEX_KOTORA,
        .categoryName = _("Tiny Tiger"),
        .height = 5,
        .weight = 95,
        .description = COMPOUND_STRING(
            "TODO EVA\n"
            "It rapidly contracts and relaxes its\n"
            "muscles to generate electricity. Its\n"
            "body shines if endangered. It flees\n"
            "while the foe is momentarily blinded."),
        .pokemonScale = 432,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Kotora,
        .frontPicSize = MON_COORDS_SIZE(48, 40),
        .frontPicYOffset = 6,
        .frontAnimFrames = sAnims_Kotora,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Kotora,
        .backPicSize = MON_COORDS_SIZE(64, 48),
        .backPicYOffset = 15,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        .palette = gMonPalette_Kotora,
        .shinyPalette = gMonShinyPalette_Kotora,
        .iconPalIndex = 0,
        .iconSprite = gMonIcon_Kotora,
        FOOTPRINT(Shinx)
        FOLLOWER(Kotora, SIZE_32x32, SHADOW_SIZE_M, TRACKS_FOOT)
        .levelUpLearnset = sKotoraLevelUpLearnset,
        .teachableLearnset = sKotoraTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 15, SPECIES_RAITORA}),
    },

    [SPECIES_RAITORA] =
    {
        .baseHP        = 60,
        .baseAttack    = 85,
        .baseDefense   = 49,
        .baseSpeed     = 60,
        .baseSpAttack  = 60,
        .baseSpDefense = 49,
        .types = MON_TYPES(TYPE_ELECTRIC),
        .catchRate = 120,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 127 : 117,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = 100,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_RIVALRY, ABILITY_INTIMIDATE, ABILITY_GUTS },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Raitora"),
        .cryId = CRY_LUXIO,
        .natDexNum = NATIONAL_DEX_RAITORA,
        .categoryName = _("Static"),
        .height = 9,
        .weight = 305,
        .description = COMPOUND_STRING(
            "TODO EVA\n"
            "Strong electricity courses through the\n"
            "tips of its sharp claws. A light scratch\n"
            "has enough amperage to cause fainting\n"
            "in foes."),
        .pokemonScale = 338,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Raitora,
        .frontPicSize = MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_Raitora,
        .frontAnimId = ANIM_H_STRETCH,
        .backPic = gMonBackPic_Raitora,
        .backPicSize = MON_COORDS_SIZE(48, 48),
        .backPicYOffset = 4,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        .palette = gMonPalette_Raitora,
        .shinyPalette = gMonShinyPalette_Raitora,
        .iconPalIndex = 0,
        .iconSprite = gMonIcon_Raitora,
        FOOTPRINT(Luxio)
        FOLLOWER(Raitora, SIZE_32x32, SHADOW_SIZE_M, TRACKS_FOOT)
        .levelUpLearnset = sRaitoraLevelUpLearnset,
        .teachableLearnset = sRaitoraTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_GAOTORA}),
    },

    [SPECIES_GAOTORA] =
    {
        .baseHP        = 80,
        .baseAttack    = 120,
        .baseDefense   = 79,
        .baseSpeed     = 70,
        .baseSpAttack  = 95,
        .baseSpDefense = 79,
        .types = MON_TYPES(TYPE_ELECTRIC),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 262,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 235,
    #else
        .expYield = 194,
    #endif
        .evYield_Attack = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_RIVALRY, ABILITY_INTIMIDATE, ABILITY_GUTS },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Gaotora"),
        .cryId = CRY_LUXRAY,
        .natDexNum = NATIONAL_DEX_GAOTORA,
        .categoryName = _("Thunder"),
        .height = 14,
        .weight = 420,
        .description = COMPOUND_STRING(
            "TODO EVA\n"
            "It has eyes which can see through\n"
            "anything. Luxray's ability to see\n"
            "through objects comes in handy when\n"
            "it's scouting for danger."),
        .pokemonScale = 265,
        .pokemonOffset = 2,
        .trainerScale = 262,
        .trainerOffset = 0,


        .frontPic = gMonFrontPic_Gaotora,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_Gaotora,
        .frontAnimId = ANIM_GLOW_YELLOW,
        .backPic = gMonBackPic_Gaotora,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 4,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        .palette = gMonPalette_Gaotora,
        .shinyPalette = gMonShinyPalette_Gaotora,
        .iconPalIndex = 0,
        .iconSprite = gMonIcon_Gaotora,
        FOOTPRINT(Luxio)
        FOLLOWER(Gaotora, SIZE_32x32, SHADOW_SIZE_M, TRACKS_FOOT)
        .levelUpLearnset = sGaotoraLevelUpLearnset,
        .teachableLearnset = sGaotoraTeachableLearnset
    },

    /*
    [SPECIES_NONE] =
    {
        .baseHP        = 1,
        .baseAttack    = 1,
        .baseDefense   = 1,
        .baseSpeed     = 1,
        .baseSpAttack  = 1,
        .baseSpDefense = 1,
        .types = MON_TYPES(TYPE_MYSTERY),
        .catchRate = 255,
        .expYield = 67,
        .evYield_HP = 1,
        .evYield_Defense = 1,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_NONE, ABILITY_CURSED_BODY, ABILITY_DAMP },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("??????????"),
        .cryId = CRY_NONE,
        .natDexNum = NATIONAL_DEX_NONE,
        .categoryName = _("Unknown"),
        .height = 0,
        .weight = 0,
        .description = COMPOUND_STRING(
            "This is a newly discovered Pokémon.\n"
            "It is currently under investigation.\n"
            "No detailed information is available\n"
            "at this time."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_CircledQuestionMark,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        //.frontPicFemale = gMonFrontPic_CircledQuestionMark,
        //.frontPicSizeFemale = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_None,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_CircledQuestionMark,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        //.backPicFemale = gMonBackPic_CircledQuestionMarkF,
        //.backPicSizeFemale = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_CircledQuestionMark,
        .shinyPalette = gMonShinyPalette_CircledQuestionMark,
        //.paletteFemale = gMonPalette_CircledQuestionMarkF,
        .shinyPaletteFemale = gMonShinyPalette_CircledQuestionMarkF,
        .iconSprite = gMonIcon_QuestionMark,
        .iconPalIndex = 0,
        //.iconSpriteFemale = gMonIcon_QuestionMarkF,
        //.iconPalIndexFemale = 1,
        //FOOTPRINT(None)
        .levelUpLearnset = sNoneLevelUpLearnset,
        .teachableLearnset = sNoneTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 100, SPECIES_NONE},
                                {EVO_ITEM, ITEM_MOOMOO_MILK, SPECIES_NONE}),
        //.formSpeciesIdTable = sNoneFormSpeciesIdTable,
        //.formChangeTable = sNoneFormChangeTable,
        .allPerfectIVs = TRUE,
    },
    */
};

#include "object_event_graphics.h"

static const u32 sFieldMugshotGfx_TestNormal[] = INCBIN_U32("graphics/field_mugshots/test/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_TestAlt[] = INCBIN_U32("graphics/field_mugshots/test/alt.4bpp.smol");
static const u16 sFieldMugshotPal_TestNormal[] = INCBIN_U16("graphics/field_mugshots/test/normal.gbapal");
static const u16 sFieldMugshotPal_TestAlt[] = INCBIN_U16("graphics/field_mugshots/test/alt.gbapal");

static const u32 sFieldMugshotGfx_HarikoNormal[] = INCBIN_U32("graphics/field_mugshots/hariko/normal.4bpp.smol");

static const u32 sFieldMugshotGfx_NatsukiNormal[] = INCBIN_U32("graphics/field_mugshots/natsuki/normal.4bpp.smol");

static const u32 sFieldMugshotGfx_KabaNormal[] = INCBIN_U32("graphics/field_mugshots/elder_kaba/normal.4bpp.smol");

static const u32 sFieldMugshotGfx_KoishiNormal[] = INCBIN_U32("graphics/field_mugshots/leader_koishi/normal.4bpp.smol");

static const u32 sFieldMugshotGfx_HanaNormal[] = INCBIN_U32("graphics/field_mugshots/leader_hana/normal.4bpp.smol");

static const u32 sFieldMugshotGfx_YutakaNormal[] = INCBIN_U32("graphics/field_mugshots/leader_yutaka/normal.4bpp.smol");

static const u32 sFieldMugshotGfx_CrobatNormal[] = INCBIN_U32("graphics/field_mugshots/crobat/normal.4bpp.smol");

static const u32 sFieldMugshotGfx_ZubatNormal[] = INCBIN_U32("graphics/field_mugshots/zubat/normal.4bpp.smol");

static const u32 sFieldMugshotGfx_ClerkNormal[] = INCBIN_U32("graphics/field_mugshots/clerk/normal.4bpp.smol");

static const u32 sFieldMugshotGfx_IncenseNormal[] = INCBIN_U32("graphics/field_mugshots/incense/normal.4bpp.smol");

static const u32 sFieldMugshotGfx_OkadaNormal[] = INCBIN_U32("graphics/field_mugshots/okada/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_OkadaSexy[] = INCBIN_U32("graphics/field_mugshots/okada/sexy.4bpp.smol");

static const u32 sFieldMugshotGfx_MasquerainGirlNormal[] = INCBIN_U32("graphics/field_mugshots/masquerain_girl/normal.4bpp.smol");

static const u32 sFieldMugshotGfx_YoungsterNormal[] = INCBIN_U32("graphics/field_mugshots/youngster/normal.4bpp.smol");

static const u32 sFieldMugshotGfx_SchoolKidFNormal[] = INCBIN_U32("graphics/field_mugshots/school_kid_f/normal.4bpp.smol");

static const u32 sFieldMugshotGfx_SchoolKidMNormal[] = INCBIN_U32("graphics/field_mugshots/school_kid_m/normal.4bpp.smol");

static const u32 sFieldMugshotGfx_BugCatcherMNormal[] = INCBIN_U32("graphics/field_mugshots/bug_catcher/normal.4bpp.smol");

static const u32 sFieldMugshotGfx_AromaLadyNormal[] = INCBIN_U32("graphics/field_mugshots/aroma_lady/normal.4bpp.smol");

static const u32 sFieldMugshotGfx_MonkNormal[] = INCBIN_U32("graphics/field_mugshots/monk/normal.4bpp.smol");

static const u32 sFieldMugshotGfx_LassNormal[] = INCBIN_U32("graphics/field_mugshots/lass/normal.4bpp.smol");

static const u32 sFieldMugshotGfx_NinjaBoyNormal[] = INCBIN_U32("graphics/field_mugshots/ninja_boy/normal.4bpp.smol");

static const u32 sFieldMugshotGfx_HexManiacNormal[] = INCBIN_U32("graphics/field_mugshots/hex_maniac/normal.4bpp.smol");

static const u32 sFieldMugshotGfx_ArtistNormal[] = INCBIN_U32("graphics/field_mugshots/artist/normal.4bpp.smol");

static const u32 sFieldMugshotGfx_BattleGirlNormal[] = INCBIN_U32("graphics/field_mugshots/battle_girl/normal.4bpp.smol");

static const u32 sFieldMugshotGfx_HotSpringFNormal[] = INCBIN_U32("graphics/field_mugshots/hot_spring_f/normal.4bpp.smol");

static const u32 sFieldMugshotGfx_BreederMNormal[] = INCBIN_U32("graphics/field_mugshots/breeder_m/normal.4bpp.smol");

static const u32 sFieldMugshotGfx_BreederFNormal[] = INCBIN_U32("graphics/field_mugshots/breeder_f/normal.4bpp.smol");

static const u32 sFieldMugshotGfx_SamuraiNormal[] = INCBIN_U32("graphics/field_mugshots/samurai/normal.4bpp.smol");

static const u32 sFieldMugshotGfx_ShamisenGreenNormal[] = INCBIN_U32("graphics/field_mugshots/shamisen_green/normal.4bpp.smol");

static const u32 sFieldMugshotGfx_ShamisenRedNormal[] = INCBIN_U32("graphics/field_mugshots/shamisen_red/normal.4bpp.smol");

static const u32 sFieldMugshotGfx_ShamisenBlueNormal[] = INCBIN_U32("graphics/field_mugshots/shamisen_blue/normal.4bpp.smol");

// Sunrise

static const u32 sFieldMugshotGfx_BigSisNormal[] = INCBIN_U32("graphics/field_mugshots/sunrise/big_sis/normal.4bpp.smol");

static const u32 sFieldMugshotGfx_SunriseWoman1Normal[] = INCBIN_U32("graphics/field_mugshots/sunrise/woman_1/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_SunriseWoman2Normal[] = INCBIN_U32("graphics/field_mugshots/sunrise/woman_2/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_SunriseMan1Normal[] = INCBIN_U32("graphics/field_mugshots/sunrise/man_1/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_SunriseMan2Normal[] = INCBIN_U32("graphics/field_mugshots/sunrise/man_2/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_SunriseOldManNormal[] = INCBIN_U32("graphics/field_mugshots/sunrise/old_man/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_SunriseOldWomanNormal[] = INCBIN_U32("graphics/field_mugshots/sunrise/old_woman/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_SunriseLittleBoyNormal[] = INCBIN_U32("graphics/field_mugshots/sunrise/little_boy/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_SunriseLittleGirlNormal[] = INCBIN_U32("graphics/field_mugshots/sunrise/little_girl/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_SunriseGirl1Normal[] = INCBIN_U32("graphics/field_mugshots/sunrise/girl_1/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_SunriseGirl2Normal[] = INCBIN_U32("graphics/field_mugshots/sunrise/girl_2/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_SunriseBoy1Normal[] = INCBIN_U32("graphics/field_mugshots/sunrise/boy_1/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_SunriseBoy2Normal[] = INCBIN_U32("graphics/field_mugshots/sunrise/boy_2/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_SunriseFatGuyNormal[] = INCBIN_U32("graphics/field_mugshots/sunrise/fat_guy/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_SunriseNurseNormal[] = INCBIN_U32("graphics/field_mugshots/sunrise/nurse/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_SunriseValetNormal[] = INCBIN_U32("graphics/field_mugshots/sunrise/valet/normal.4bpp.smol");

// Sakura

static const u32 sFieldMugshotGfx_SakuraWoman1Normal[] = INCBIN_U32("graphics/field_mugshots/sakura/woman_1/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_SakuraWoman2Normal[] = INCBIN_U32("graphics/field_mugshots/sakura/woman_2/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_SakuraMan1Normal[] = INCBIN_U32("graphics/field_mugshots/sakura/man_1/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_SakuraMan2Normal[] = INCBIN_U32("graphics/field_mugshots/sakura/man_2/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_SakuraOldManNormal[] = INCBIN_U32("graphics/field_mugshots/sakura/old_man/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_SakuraOldWomanNormal[] = INCBIN_U32("graphics/field_mugshots/sakura/old_woman/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_SakuraLittleBoyNormal[] = INCBIN_U32("graphics/field_mugshots/sakura/little_boy/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_SakuraLittleGirlNormal[] = INCBIN_U32("graphics/field_mugshots/sakura/little_girl/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_SakuraGirl1Normal[] = INCBIN_U32("graphics/field_mugshots/sakura/girl_1/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_SakuraGirl2Normal[] = INCBIN_U32("graphics/field_mugshots/sakura/girl_2/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_SakuraBoy1Normal[] = INCBIN_U32("graphics/field_mugshots/sakura/boy_1/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_SakuraBoy2Normal[] = INCBIN_U32("graphics/field_mugshots/sakura/boy_2/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_SakuraFatGuyNormal[] = INCBIN_U32("graphics/field_mugshots/sakura/fat_guy/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_SakuraNurseNormal[] = INCBIN_U32("graphics/field_mugshots/sakura/nurse/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_SakuraValetNormal[] = INCBIN_U32("graphics/field_mugshots/sakura/valet/normal.4bpp.smol");

// Mountain

static const u32 sFieldMugshotGfx_MountainWoman1Normal[] = INCBIN_U32("graphics/field_mugshots/mountain/woman_1/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_MountainWoman2Normal[] = INCBIN_U32("graphics/field_mugshots/mountain/woman_2/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_MountainMan1Normal[] = INCBIN_U32("graphics/field_mugshots/mountain/man_1/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_MountainMan2Normal[] = INCBIN_U32("graphics/field_mugshots/mountain/man_2/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_MountainOldManNormal[] = INCBIN_U32("graphics/field_mugshots/mountain/old_man/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_MountainOldWomanNormal[] = INCBIN_U32("graphics/field_mugshots/mountain/old_woman/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_MountainLittleBoyNormal[] = INCBIN_U32("graphics/field_mugshots/mountain/little_boy/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_MountainLittleGirlNormal[] = INCBIN_U32("graphics/field_mugshots/mountain/little_girl/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_MountainGirl1Normal[] = INCBIN_U32("graphics/field_mugshots/mountain/girl_1/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_MountainGirl2Normal[] = INCBIN_U32("graphics/field_mugshots/mountain/girl_2/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_MountainBoy1Normal[] = INCBIN_U32("graphics/field_mugshots/mountain/boy_1/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_MountainBoy2Normal[] = INCBIN_U32("graphics/field_mugshots/mountain/boy_2/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_MountainFatGuyNormal[] = INCBIN_U32("graphics/field_mugshots/mountain/fat_guy/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_MountainNurseNormal[] = INCBIN_U32("graphics/field_mugshots/mountain/nurse/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_MountainValetNormal[] = INCBIN_U32("graphics/field_mugshots/mountain/valet/normal.4bpp.smol");

// Uume

static const u32 sFieldMugshotGfx_UumeWoman1Normal[] = INCBIN_U32("graphics/field_mugshots/uume/woman_1/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_UumeWoman2Normal[] = INCBIN_U32("graphics/field_mugshots/uume/woman_2/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_UumeMan1Normal[] = INCBIN_U32("graphics/field_mugshots/uume/man_1/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_UumeMan2Normal[] = INCBIN_U32("graphics/field_mugshots/uume/man_2/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_UumeOldManNormal[] = INCBIN_U32("graphics/field_mugshots/uume/old_man/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_UumeOldWomanNormal[] = INCBIN_U32("graphics/field_mugshots/uume/old_woman/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_UumeLittleBoyNormal[] = INCBIN_U32("graphics/field_mugshots/uume/little_boy/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_UumeLittleGirlNormal[] = INCBIN_U32("graphics/field_mugshots/uume/little_girl/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_UumeGirl1Normal[] = INCBIN_U32("graphics/field_mugshots/uume/girl_1/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_UumeGirl2Normal[] = INCBIN_U32("graphics/field_mugshots/uume/girl_2/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_UumeBoy1Normal[] = INCBIN_U32("graphics/field_mugshots/uume/boy_1/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_UumeBoy2Normal[] = INCBIN_U32("graphics/field_mugshots/uume/boy_2/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_UumeFatGuyNormal[] = INCBIN_U32("graphics/field_mugshots/uume/fat_guy/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_UumeNurseNormal[] = INCBIN_U32("graphics/field_mugshots/uume/nurse/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_UumeValetNormal[] = INCBIN_U32("graphics/field_mugshots/uume/valet/normal.4bpp.smol");

// Cold

static const u32 sFieldMugshotGfx_ColdWoman1Normal[] = INCBIN_U32("graphics/field_mugshots/cold/woman_1/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_ColdWoman2Normal[] = INCBIN_U32("graphics/field_mugshots/cold/woman_2/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_ColdMan1Normal[] = INCBIN_U32("graphics/field_mugshots/cold/man_1/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_ColdMan2Normal[] = INCBIN_U32("graphics/field_mugshots/cold/man_2/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_ColdOldManNormal[] = INCBIN_U32("graphics/field_mugshots/cold/old_man/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_ColdOldWomanNormal[] = INCBIN_U32("graphics/field_mugshots/cold/old_woman/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_ColdLittleBoyNormal[] = INCBIN_U32("graphics/field_mugshots/cold/little_boy/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_ColdLittleGirlNormal[] = INCBIN_U32("graphics/field_mugshots/cold/little_girl/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_ColdGirl1Normal[] = INCBIN_U32("graphics/field_mugshots/cold/girl_1/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_ColdGirl2Normal[] = INCBIN_U32("graphics/field_mugshots/cold/girl_2/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_ColdBoy1Normal[] = INCBIN_U32("graphics/field_mugshots/cold/boy_1/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_ColdBoy2Normal[] = INCBIN_U32("graphics/field_mugshots/cold/boy_2/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_ColdFatGuyNormal[] = INCBIN_U32("graphics/field_mugshots/cold/fat_guy/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_ColdNurseNormal[] = INCBIN_U32("graphics/field_mugshots/cold/nurse/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_ColdValetNormal[] = INCBIN_U32("graphics/field_mugshots/cold/valet/normal.4bpp.smol");

// Seaside

static const u32 sFieldMugshotGfx_SeasideWoman1Normal[] = INCBIN_U32("graphics/field_mugshots/seaside/woman_1/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_SeasideWoman2Normal[] = INCBIN_U32("graphics/field_mugshots/seaside/woman_2/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_SeasideMan1Normal[] = INCBIN_U32("graphics/field_mugshots/seaside/man_1/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_SeasideMan2Normal[] = INCBIN_U32("graphics/field_mugshots/seaside/man_2/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_SeasideOldManNormal[] = INCBIN_U32("graphics/field_mugshots/seaside/old_man/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_SeasideOldWomanNormal[] = INCBIN_U32("graphics/field_mugshots/seaside/old_woman/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_SeasideLittleBoyNormal[] = INCBIN_U32("graphics/field_mugshots/seaside/little_boy/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_SeasideLittleGirlNormal[] = INCBIN_U32("graphics/field_mugshots/seaside/little_girl/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_SeasideGirl1Normal[] = INCBIN_U32("graphics/field_mugshots/seaside/girl_1/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_SeasideGirl2Normal[] = INCBIN_U32("graphics/field_mugshots/seaside/girl_2/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_SeasideBoy1Normal[] = INCBIN_U32("graphics/field_mugshots/seaside/boy_1/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_SeasideBoy2Normal[] = INCBIN_U32("graphics/field_mugshots/seaside/boy_2/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_SeasideFatGuyNormal[] = INCBIN_U32("graphics/field_mugshots/seaside/fat_guy/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_SeasideNurseNormal[] = INCBIN_U32("graphics/field_mugshots/seaside/nurse/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_SeasideValetNormal[] = INCBIN_U32("graphics/field_mugshots/seaside/valet/normal.4bpp.smol");

// Hot
static const u32 sFieldMugshotGfx_HotMan1Normal[] = INCBIN_U32("graphics/field_mugshots/hot/man_1/normal.4bpp.smol");

struct MugshotGfx
{
    const u32 *gfx;
    const u16 *pal; // custom palette
    u32 tag;        // object event-based palette (tag)
};

static const struct MugshotGfx sFieldMugshots[MUGSHOT_COUNT][EMOTE_COUNT] =
{
    [MUGSHOT_HARIKO] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_HarikoNormal,
            .tag = OBJ_EVENT_PAL_TAG_COLD,
        },
    },
    [MUGSHOT_NATSUKI] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_NatsukiNormal,
            .tag = OBJ_EVENT_PAL_TAG_HOT,
        },
    },
    [MUGSHOT_BIG_SIS] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_BigSisNormal,
            .tag = OBJ_EVENT_PAL_TAG_SUNRISE,
        },
    },
    [MUGSHOT_KABA] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_KabaNormal,
            .tag = OBJ_EVENT_PAL_TAG_PURPLISH,
        },
    },
    [MUGSHOT_CLERK] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_ClerkNormal,
            .tag = OBJ_EVENT_PAL_TAG_PURPLISH,
        },
    },
    [MUGSHOT_CROBAT] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_CrobatNormal,
            .tag = OBJ_EVENT_PAL_TAG_CROBAT_SHADOWS_BOSS,
        },
    },
    [MUGSHOT_ZUBAT] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_ZubatNormal,
            .tag = OBJ_EVENT_PAL_TAG_CROBAT_SHADOWS,
        },
    },
    [MUGSHOT_INCENSE] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_IncenseNormal,
            .tag = OBJ_EVENT_PAL_TAG_PURPLISH,
        },
    },
    [MUGSHOT_HANA] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_HanaNormal,
            .tag = OBJ_EVENT_PAL_TAG_WOODY,
        },
    },
    [MUGSHOT_KOISHI] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_KoishiNormal,
            .tag = OBJ_EVENT_PAL_TAG_PURPLISH,
        },
    },
    [MUGSHOT_YUTAKA] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_YutakaNormal,
            .tag = OBJ_EVENT_PAL_TAG_WOODY,
        },
    },
    [MUGSHOT_MASQUERAIN_GIRL] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_MasquerainGirlNormal,
            .tag = OBJ_EVENT_PAL_TAG_PURPLISH,
        },
    },
    [MUGSHOT_OKADA] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_OkadaNormal,
            .tag = OBJ_EVENT_PAL_TAG_COLD,
        },
        [EMOTE_SEXY] =
        {
            .gfx = sFieldMugshotGfx_OkadaSexy,
            .tag = OBJ_EVENT_PAL_TAG_COLD,
        },
    },
    [MUGSHOT_YOUNGSTER] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_YoungsterNormal,
            .tag = OBJ_EVENT_PAL_TAG_PURPLISH,
        },
    },
    [MUGSHOT_SCHOOL_KID_F] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SchoolKidFNormal,
            .tag = OBJ_EVENT_PAL_TAG_GREENISH,
        },
    },
    [MUGSHOT_SCHOOL_KID_M] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SchoolKidMNormal,
            .tag = OBJ_EVENT_PAL_TAG_GREENISH,
        },
    },
    [MUGSHOT_BUG_CATCHER] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_BugCatcherMNormal,
            .tag = OBJ_EVENT_PAL_TAG_PURPLISH,
        },
    },
    [MUGSHOT_AROMA_LADY] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_AromaLadyNormal,
            .tag = OBJ_EVENT_PAL_TAG_GREENISH,
        },
    },
    [MUGSHOT_MONK] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_MonkNormal,
            .tag = OBJ_EVENT_PAL_TAG_WOODY,
        },
    },
    [MUGSHOT_LASS] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_LassNormal,
            .tag = OBJ_EVENT_PAL_TAG_GREENISH,
        },
    },
    [MUGSHOT_NINJA_BOY] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_NinjaBoyNormal,
            .tag = OBJ_EVENT_PAL_TAG_PURPLISH,
        },
    },
    [MUGSHOT_HEX_MANIAC] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_HexManiacNormal,
            .tag = OBJ_EVENT_PAL_TAG_PURPLISH,
        },
    },
    [MUGSHOT_ARTIST] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_ArtistNormal,
            .tag = OBJ_EVENT_PAL_TAG_PURPLISH,
        },
    },
    [MUGSHOT_BATTLE_GIRL] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_BattleGirlNormal,
            .tag = OBJ_EVENT_PAL_TAG_PURPLISH,
        },
    },

    [MUGSHOT_HOT_SPRING_F] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_HotSpringFNormal,
            .tag = OBJ_EVENT_PAL_TAG_GREENISH,
        },
    },

    [MUGSHOT_BREEDER_M] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_BreederMNormal,
            .tag = OBJ_EVENT_PAL_TAG_PURPLISH,
        },
    },

    [MUGSHOT_BREEDER_F] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_BreederFNormal,
            .tag = OBJ_EVENT_PAL_TAG_PURPLISH,
        },
    },

    [MUGSHOT_SAMURAI] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SamuraiNormal,
            .tag = OBJ_EVENT_PAL_TAG_PURPLISH,
        },
    },

    [MUGSHOT_SHAMISEN_GREEN] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_ShamisenGreenNormal,
            .pal = gObjectEventPal_Npc_Greenish,
        },
    },

    [MUGSHOT_SHAMISEN_RED] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_ShamisenRedNormal,
            .pal = gObjectEventPal_Npc_Greenish,
        },
    },

    [MUGSHOT_SHAMISEN_BLUE] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_ShamisenBlueNormal,
            .pal = gObjectEventPal_Npc_Greenish,
        },
    },

    [MUGSHOT_SUNRISE_WOMAN_1] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SunriseWoman1Normal,
            .tag = OBJ_EVENT_PAL_TAG_SUNRISE,
        }
    },

    [MUGSHOT_SUNRISE_WOMAN_2] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SunriseWoman2Normal,
            .tag = OBJ_EVENT_PAL_TAG_SUNRISE,
        }
    },

    [MUGSHOT_SUNRISE_MAN_1] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SunriseMan1Normal,
            .tag = OBJ_EVENT_PAL_TAG_SUNRISE,
        }
    },

    [MUGSHOT_SUNRISE_MAN_2] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SunriseMan2Normal,
            .tag = OBJ_EVENT_PAL_TAG_SUNRISE,
        }
    },

    [MUGSHOT_SUNRISE_OLD_MAN] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SunriseOldManNormal,
            .tag = OBJ_EVENT_PAL_TAG_SUNRISE,
        }
    },

    [MUGSHOT_SUNRISE_OLD_WOMAN] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SunriseOldWomanNormal,
            .tag = OBJ_EVENT_PAL_TAG_SUNRISE,
        }
    },

    [MUGSHOT_SUNRISE_LITTLE_BOY] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SunriseLittleBoyNormal,
            .tag = OBJ_EVENT_PAL_TAG_SUNRISE,
        }
    },

    [MUGSHOT_SUNRISE_LITTLE_GIRL] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SunriseLittleGirlNormal,
            .tag = OBJ_EVENT_PAL_TAG_SUNRISE,
        }
    },

    [MUGSHOT_SUNRISE_GIRL_1] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SunriseGirl1Normal,
            .tag = OBJ_EVENT_PAL_TAG_SUNRISE,
        }
    },

    [MUGSHOT_SUNRISE_GIRL_2] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SunriseGirl2Normal,
            .tag = OBJ_EVENT_PAL_TAG_SUNRISE,
        }
    },

    [MUGSHOT_SUNRISE_BOY_1] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SunriseBoy1Normal,
            .tag = OBJ_EVENT_PAL_TAG_SUNRISE,
        }
    },

    [MUGSHOT_SUNRISE_BOY_2] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SunriseBoy2Normal,
            .tag = OBJ_EVENT_PAL_TAG_SUNRISE,
        }
    },

    [MUGSHOT_SUNRISE_FAT_GUY] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SunriseFatGuyNormal,
            .tag = OBJ_EVENT_PAL_TAG_SUNRISE,
        }
    },

    [MUGSHOT_SUNRISE_NURSE] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SunriseNurseNormal,
            .tag = OBJ_EVENT_PAL_TAG_SUNRISE,
        }
    },

    [MUGSHOT_SUNRISE_VALET] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SunriseValetNormal,
            .tag = OBJ_EVENT_PAL_TAG_SUNRISE,
        }
    },

    // Sakura

    [MUGSHOT_SAKURA_WOMAN_1] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SakuraWoman1Normal,
            .tag = OBJ_EVENT_PAL_TAG_SAKURA,
        }
    },
    [MUGSHOT_SAKURA_WOMAN_2] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SakuraWoman2Normal,
            .tag = OBJ_EVENT_PAL_TAG_SAKURA,
        }
    },
    [MUGSHOT_SAKURA_MAN_1] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SakuraMan1Normal,
            .tag = OBJ_EVENT_PAL_TAG_SAKURA,
        }
    },
    [MUGSHOT_SAKURA_MAN_2] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SakuraMan2Normal,
            .tag = OBJ_EVENT_PAL_TAG_SAKURA,
        }
    },
    [MUGSHOT_SAKURA_OLD_MAN] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SakuraOldManNormal,
            .tag = OBJ_EVENT_PAL_TAG_SAKURA,
        }
    },
    [MUGSHOT_SAKURA_OLD_WOMAN] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SakuraOldWomanNormal,
            .tag = OBJ_EVENT_PAL_TAG_SAKURA,
        }
    },
    [MUGSHOT_SAKURA_LITTLE_BOY] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SakuraLittleBoyNormal,
            .tag = OBJ_EVENT_PAL_TAG_SAKURA,
        }
    },
    [MUGSHOT_SAKURA_LITTLE_GIRL] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SakuraLittleGirlNormal,
            .tag = OBJ_EVENT_PAL_TAG_SAKURA,
        }
    },
    [MUGSHOT_SAKURA_GIRL_1] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SakuraGirl1Normal,
            .tag = OBJ_EVENT_PAL_TAG_SAKURA,
        }
    },
    [MUGSHOT_SAKURA_GIRL_2] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SakuraGirl2Normal,
            .tag = OBJ_EVENT_PAL_TAG_SAKURA,
        }
    },
    [MUGSHOT_SAKURA_BOY_1] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SakuraBoy1Normal,
            .tag = OBJ_EVENT_PAL_TAG_SAKURA,
        }
    },
    [MUGSHOT_SAKURA_BOY_2] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SakuraBoy2Normal,
            .tag = OBJ_EVENT_PAL_TAG_SAKURA,
        }
    },
    [MUGSHOT_SAKURA_FAT_GUY] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SakuraFatGuyNormal,
            .tag = OBJ_EVENT_PAL_TAG_SAKURA,
        }
    },
    [MUGSHOT_SAKURA_NURSE] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SakuraNurseNormal,
            .tag = OBJ_EVENT_PAL_TAG_SAKURA,
        }
    },
    [MUGSHOT_SAKURA_VALET] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SakuraValetNormal,
            .tag = OBJ_EVENT_PAL_TAG_SAKURA,
        }
    },

    // Seaside

    [MUGSHOT_SEASIDE_WOMAN_1] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SeasideWoman1Normal,
            .tag = OBJ_EVENT_PAL_TAG_SEASIDE,
        }
    },

    [MUGSHOT_SEASIDE_WOMAN_2] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SeasideWoman2Normal,
            .tag = OBJ_EVENT_PAL_TAG_SEASIDE,
        }
    },

    [MUGSHOT_SEASIDE_MAN_1] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SeasideMan1Normal,
            .tag = OBJ_EVENT_PAL_TAG_SEASIDE,
        }
    },

    [MUGSHOT_SEASIDE_MAN_2] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SeasideMan2Normal,
            .tag = OBJ_EVENT_PAL_TAG_SEASIDE,
        }
    },

    [MUGSHOT_SEASIDE_OLD_MAN] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SeasideOldManNormal,
            .tag = OBJ_EVENT_PAL_TAG_SEASIDE,
        }
    },

    [MUGSHOT_SEASIDE_OLD_WOMAN] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SeasideOldWomanNormal,
            .tag = OBJ_EVENT_PAL_TAG_SEASIDE,
        }
    },

    [MUGSHOT_SEASIDE_LITTLE_BOY] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SeasideLittleBoyNormal,
            .tag = OBJ_EVENT_PAL_TAG_SEASIDE,
        }
    },

    [MUGSHOT_SEASIDE_LITTLE_GIRL] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SeasideLittleGirlNormal,
            .tag = OBJ_EVENT_PAL_TAG_SEASIDE,
        }
    },

    [MUGSHOT_SEASIDE_GIRL_1] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SeasideGirl1Normal,
            .tag = OBJ_EVENT_PAL_TAG_SEASIDE,
        }
    },

    [MUGSHOT_SEASIDE_GIRL_2] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SeasideGirl2Normal,
            .tag = OBJ_EVENT_PAL_TAG_SEASIDE,
        }
    },

    [MUGSHOT_SEASIDE_BOY_1] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SeasideBoy1Normal,
            .tag = OBJ_EVENT_PAL_TAG_SEASIDE,
        }
    },

    [MUGSHOT_SEASIDE_BOY_2] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SeasideBoy2Normal,
            .tag = OBJ_EVENT_PAL_TAG_SEASIDE,
        }
    },

    [MUGSHOT_SEASIDE_FAT_GUY] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SeasideFatGuyNormal,
            .tag = OBJ_EVENT_PAL_TAG_SEASIDE,
        }
    },

    [MUGSHOT_SEASIDE_NURSE] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SeasideNurseNormal,
            .tag = OBJ_EVENT_PAL_TAG_SEASIDE,
        }
    },

    [MUGSHOT_SEASIDE_VALET] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SeasideValetNormal,
            .tag = OBJ_EVENT_PAL_TAG_SEASIDE,
        }
    },


    // Hot

    [MUGSHOT_HOT_MAN_1] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_HotMan1Normal,
            .tag = OBJ_EVENT_PAL_TAG_HOT,
        }
    },

    [MUGSHOT_MOUNTAIN_WOMAN_1] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_MountainWoman1Normal,
            .tag = OBJ_EVENT_PAL_TAG_MOUNTAIN,
        }
    },
    [MUGSHOT_MOUNTAIN_WOMAN_2] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_MountainWoman2Normal,
            .tag = OBJ_EVENT_PAL_TAG_MOUNTAIN,
        }
    },
    [MUGSHOT_MOUNTAIN_MAN_1] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_MountainMan1Normal,
            .tag = OBJ_EVENT_PAL_TAG_MOUNTAIN,
        }
    },
    [MUGSHOT_MOUNTAIN_MAN_2] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_MountainMan2Normal,
            .tag = OBJ_EVENT_PAL_TAG_MOUNTAIN,
        }
    },
    [MUGSHOT_MOUNTAIN_OLD_MAN] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_MountainOldManNormal,
            .tag = OBJ_EVENT_PAL_TAG_MOUNTAIN,
        }
    },
    [MUGSHOT_MOUNTAIN_OLD_WOMAN] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_MountainOldWomanNormal,
            .tag = OBJ_EVENT_PAL_TAG_MOUNTAIN,
        }
    },
    [MUGSHOT_MOUNTAIN_LITTLE_BOY] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_MountainLittleBoyNormal,
            .tag = OBJ_EVENT_PAL_TAG_MOUNTAIN,
        }
    },
    [MUGSHOT_MOUNTAIN_LITTLE_GIRL] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_MountainLittleGirlNormal,
            .tag = OBJ_EVENT_PAL_TAG_MOUNTAIN,
        }
    },
    [MUGSHOT_MOUNTAIN_GIRL_1] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_MountainGirl1Normal,
            .tag = OBJ_EVENT_PAL_TAG_MOUNTAIN,
        }
    },
    [MUGSHOT_MOUNTAIN_GIRL_2] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_MountainGirl2Normal,
            .tag = OBJ_EVENT_PAL_TAG_MOUNTAIN,
        }
    },
    [MUGSHOT_MOUNTAIN_BOY_1] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_MountainBoy1Normal,
            .tag = OBJ_EVENT_PAL_TAG_MOUNTAIN,
        }
    },
    [MUGSHOT_MOUNTAIN_BOY_2] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_MountainBoy2Normal,
            .tag = OBJ_EVENT_PAL_TAG_MOUNTAIN,
        }
    },
    [MUGSHOT_MOUNTAIN_FAT_GUY] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_MountainFatGuyNormal,
            .tag = OBJ_EVENT_PAL_TAG_MOUNTAIN,
        }
    },
    [MUGSHOT_MOUNTAIN_NURSE] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_MountainNurseNormal,
            .tag = OBJ_EVENT_PAL_TAG_MOUNTAIN,
        }
    },
    [MUGSHOT_MOUNTAIN_VALET] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_MountainValetNormal,
            .tag = OBJ_EVENT_PAL_TAG_MOUNTAIN,
        }
    },

    [MUGSHOT_UUME_WOMAN_1] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_UumeWoman1Normal,
            .tag = OBJ_EVENT_PAL_TAG_UUME,
        }
    },

    [MUGSHOT_UUME_WOMAN_2] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_UumeWoman2Normal,
            .tag = OBJ_EVENT_PAL_TAG_UUME,
        }
    },

    [MUGSHOT_UUME_MAN_1] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_UumeMan1Normal,
            .tag = OBJ_EVENT_PAL_TAG_UUME,
        }
    },

    [MUGSHOT_UUME_MAN_2] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_UumeMan2Normal,
            .tag = OBJ_EVENT_PAL_TAG_UUME,
        }
    },

    [MUGSHOT_UUME_OLD_MAN] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_UumeOldManNormal,
            .tag = OBJ_EVENT_PAL_TAG_UUME,
        }
    },

    [MUGSHOT_UUME_OLD_WOMAN] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_UumeOldWomanNormal,
            .tag = OBJ_EVENT_PAL_TAG_UUME,
        }
    },

    [MUGSHOT_UUME_LITTLE_BOY] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_UumeLittleBoyNormal,
            .tag = OBJ_EVENT_PAL_TAG_UUME,
        }
    },

    [MUGSHOT_UUME_LITTLE_GIRL] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_UumeLittleGirlNormal,
            .tag = OBJ_EVENT_PAL_TAG_UUME,
        }
    },

    [MUGSHOT_UUME_GIRL_1] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_UumeGirl1Normal,
            .tag = OBJ_EVENT_PAL_TAG_UUME,
        }
    },

    [MUGSHOT_UUME_GIRL_2] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_UumeGirl2Normal,
            .tag = OBJ_EVENT_PAL_TAG_UUME,
        }
    },

    [MUGSHOT_UUME_BOY_1] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_UumeBoy1Normal,
            .tag = OBJ_EVENT_PAL_TAG_UUME,
        }
    },

    [MUGSHOT_UUME_BOY_2] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_UumeBoy2Normal,
            .tag = OBJ_EVENT_PAL_TAG_UUME,
        }
    },

    [MUGSHOT_UUME_FAT_GUY] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_UumeFatGuyNormal,
            .tag = OBJ_EVENT_PAL_TAG_UUME,
        }
    },

    [MUGSHOT_UUME_NURSE] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_UumeNurseNormal,
            .tag = OBJ_EVENT_PAL_TAG_UUME,
        }
    },

    [MUGSHOT_UUME_VALET] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_UumeValetNormal,
            .tag = OBJ_EVENT_PAL_TAG_UUME,
        }
    },


    [MUGSHOT_COLD_WOMAN_1] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_ColdWoman1Normal,
            .tag = OBJ_EVENT_PAL_TAG_COLD,
        }
    },

    [MUGSHOT_COLD_WOMAN_2] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_ColdWoman2Normal,
            .tag = OBJ_EVENT_PAL_TAG_COLD,
        }
    },

    [MUGSHOT_COLD_MAN_1] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_ColdMan1Normal,
            .tag = OBJ_EVENT_PAL_TAG_COLD,
        }
    },

    [MUGSHOT_COLD_MAN_2] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_ColdMan2Normal,
            .tag = OBJ_EVENT_PAL_TAG_COLD,
        }
    },

    [MUGSHOT_COLD_OLD_MAN] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_ColdOldManNormal,
            .tag = OBJ_EVENT_PAL_TAG_COLD,
        }
    },

    [MUGSHOT_COLD_OLD_WOMAN] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_ColdOldWomanNormal,
            .tag = OBJ_EVENT_PAL_TAG_COLD,
        }
    },

    [MUGSHOT_COLD_LITTLE_BOY] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_ColdLittleBoyNormal,
            .tag = OBJ_EVENT_PAL_TAG_COLD,
        }
    },

    [MUGSHOT_COLD_LITTLE_GIRL] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_ColdLittleGirlNormal,
            .tag = OBJ_EVENT_PAL_TAG_COLD,
        }
    },

    [MUGSHOT_COLD_GIRL_1] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_ColdGirl1Normal,
            .tag = OBJ_EVENT_PAL_TAG_COLD,
        }
    },

    [MUGSHOT_COLD_GIRL_2] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_ColdGirl2Normal,
            .tag = OBJ_EVENT_PAL_TAG_COLD,
        }
    },

    [MUGSHOT_COLD_BOY_1] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_ColdBoy1Normal,
            .tag = OBJ_EVENT_PAL_TAG_COLD,
        }
    },

    [MUGSHOT_COLD_BOY_2] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_ColdBoy2Normal,
            .tag = OBJ_EVENT_PAL_TAG_COLD,
        }
    },

    [MUGSHOT_COLD_FAT_GUY] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_ColdFatGuyNormal,
            .tag = OBJ_EVENT_PAL_TAG_COLD,
        }
    },

    [MUGSHOT_COLD_NURSE] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_ColdNurseNormal,
            .tag = OBJ_EVENT_PAL_TAG_COLD,
        }
    },

    [MUGSHOT_COLD_VALET] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_ColdValetNormal,
            .tag = OBJ_EVENT_PAL_TAG_COLD,
        }
    },

};

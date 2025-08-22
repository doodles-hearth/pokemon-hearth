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

// Hot
static const u32 sFieldMugshotGfx_HotMan2Normal[] = INCBIN_U32("graphics/field_mugshots/hot/man_2/normal.4bpp.smol");

struct MugshotGfx
{
    const u32 *gfx;
    const u16 *pal;
};

static const struct MugshotGfx sFieldMugshots[MUGSHOT_COUNT][EMOTE_COUNT] =
{
    [MUGSHOT_HARIKO] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_HarikoNormal,
            .pal = gObjectEventPal_Npc_Cold,
        },
    },
    [MUGSHOT_NATSUKI] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_NatsukiNormal,
            .pal = gObjectEventPal_Npc_Hot,
        },
    },
    [MUGSHOT_BIG_SIS] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_BigSisNormal,
            .pal = gObjectEventPal_Npc_Sunrise,
        },
    },
    [MUGSHOT_KABA] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_KabaNormal,
            .pal = gObjectEventPal_Npc_Purplish,
        },
    },
    [MUGSHOT_CLERK] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_ClerkNormal,
            .pal = gObjectEventPal_Npc_Purplish,
        },
    },
    [MUGSHOT_CROBAT] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_CrobatNormal,
            .pal = gObjectEventPal_CrobatShadowsCrobat,
        },
    },
    [MUGSHOT_ZUBAT] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_ZubatNormal,
            .pal = gObjectEventPal_CrobatShadowsGolbat,
        },
    },
    [MUGSHOT_INCENSE] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_IncenseNormal,
            .pal = gObjectEventPal_Npc_Purplish,
        },
    },
    [MUGSHOT_HANA] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_HanaNormal,
            .pal = gObjectEventPal_Npc_Woody,
        },
    },
    [MUGSHOT_KOISHI] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_KoishiNormal,
            .pal = gObjectEventPal_Npc_Purplish,
        },
    },
    [MUGSHOT_YUTAKA] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_YutakaNormal,
            .pal = gObjectEventPal_Npc_Woody,
        },
    },
    [MUGSHOT_MASQUERAIN_GIRL] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_MasquerainGirlNormal,
            .pal = gObjectEventPal_Npc_Purplish,
        },
    },
    [MUGSHOT_OKADA] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_OkadaNormal,
            .pal = gObjectEventPal_Npc_Cold,
        },
        [EMOTE_SEXY] =
        {
            .gfx = sFieldMugshotGfx_OkadaSexy,
            .pal = gObjectEventPal_Npc_Cold,
        },
    },
    [MUGSHOT_YOUNGSTER] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_YoungsterNormal,
            .pal = gObjectEventPal_Npc_Purplish,
        },
    },
    [MUGSHOT_SCHOOL_KID_F] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SchoolKidFNormal,
            .pal = gObjectEventPal_Npc_Greenish,
        },
    },
    [MUGSHOT_SCHOOL_KID_M] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SchoolKidMNormal,
            .pal = gObjectEventPal_Npc_Greenish,
        },
    },
    [MUGSHOT_BUG_CATCHER] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_BugCatcherMNormal,
            .pal = gObjectEventPal_Npc_Purplish,
        },
    },
    [MUGSHOT_AROMA_LADY] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_AromaLadyNormal,
            .pal = gObjectEventPal_Npc_Greenish,
        },
    },
    [MUGSHOT_MONK] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_MonkNormal,
            .pal = gObjectEventPal_Npc_Woody,
        },
    },
    [MUGSHOT_LASS] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_LassNormal,
            .pal = gObjectEventPal_Npc_Greenish,
        },
    },
    [MUGSHOT_NINJA_BOY] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_NinjaBoyNormal,
            .pal = gObjectEventPal_Npc_Purplish,
        },
    },
    [MUGSHOT_HEX_MANIAC] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_HexManiacNormal,
            .pal = gObjectEventPal_Npc_Purplish,
        },
    },
    [MUGSHOT_ARTIST] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_ArtistNormal,
            .pal = gObjectEventPal_Npc_Purplish,
        },
    },
    [MUGSHOT_BATTLE_GIRL] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_BattleGirlNormal,
            .pal = gObjectEventPal_Npc_Purplish,
        },
    },
    [MUGSHOT_HOT_SPRING_F] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_HotSpringFNormal,
            .pal = gObjectEventPal_Npc_Greenish,
        },
    },

    [MUGSHOT_SUNRISE_WOMAN_1] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SunriseWoman1Normal,
            .pal = gObjectEventPal_Npc_Sunrise,
        }
    },

    [MUGSHOT_SUNRISE_WOMAN_2] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SunriseWoman2Normal,
            .pal = gObjectEventPal_Npc_Sunrise,
        }
    },

    [MUGSHOT_SUNRISE_MAN_1] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SunriseMan1Normal,
            .pal = gObjectEventPal_Npc_Sunrise,
        }
    },

    [MUGSHOT_SUNRISE_MAN_2] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SunriseMan2Normal,
            .pal = gObjectEventPal_Npc_Sunrise,
        }
    },

    [MUGSHOT_SUNRISE_OLD_MAN] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SunriseOldManNormal,
            .pal = gObjectEventPal_Npc_Sunrise,
        }
    },

    [MUGSHOT_SUNRISE_OLD_WOMAN] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SunriseOldWomanNormal,
            .pal = gObjectEventPal_Npc_Sunrise,
        }
    },

    [MUGSHOT_SUNRISE_LITTLE_BOY] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SunriseLittleBoyNormal,
            .pal = gObjectEventPal_Npc_Sunrise,
        }
    },

    [MUGSHOT_SUNRISE_LITTLE_GIRL] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SunriseLittleGirlNormal,
            .pal = gObjectEventPal_Npc_Sunrise,
        }
    },

    [MUGSHOT_SUNRISE_GIRL_1] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SunriseGirl1Normal,
            .pal = gObjectEventPal_Npc_Sunrise,
        }
    },

    [MUGSHOT_SUNRISE_GIRL_2] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SunriseGirl2Normal,
            .pal = gObjectEventPal_Npc_Sunrise,
        }
    },

    [MUGSHOT_SUNRISE_BOY_1] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SunriseBoy1Normal,
            .pal = gObjectEventPal_Npc_Sunrise,
        }
    },

    [MUGSHOT_SUNRISE_BOY_2] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SunriseBoy2Normal,
            .pal = gObjectEventPal_Npc_Sunrise,
        }
    },

    [MUGSHOT_SUNRISE_FAT_GUY] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SunriseFatGuyNormal,
            .pal = gObjectEventPal_Npc_Sunrise,
        }
    },

    [MUGSHOT_SUNRISE_NURSE] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SunriseNurseNormal,
            .pal = gObjectEventPal_Npc_Sunrise,
        }
    },

    [MUGSHOT_SUNRISE_VALET] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SunriseValetNormal,
            .pal = gObjectEventPal_Npc_Sunrise,
        }
    },

    // Sakura

    [MUGSHOT_SAKURA_WOMAN_1] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SakuraWoman1Normal,
            .pal = gObjectEventPal_Npc_Sakura,
        }
    },
    [MUGSHOT_SAKURA_WOMAN_2] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SakuraWoman2Normal,
            .pal = gObjectEventPal_Npc_Sakura,
        }
    },
    [MUGSHOT_SAKURA_MAN_1] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SakuraMan1Normal,
            .pal = gObjectEventPal_Npc_Sakura,
        }
    },
    [MUGSHOT_SAKURA_MAN_2] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SakuraMan2Normal,
            .pal = gObjectEventPal_Npc_Sakura,
        }
    },
    [MUGSHOT_SAKURA_OLD_MAN] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SakuraOldManNormal,
            .pal = gObjectEventPal_Npc_Sakura,
        }
    },
    [MUGSHOT_SAKURA_OLD_WOMAN] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SakuraOldWomanNormal,
            .pal = gObjectEventPal_Npc_Sakura,
        }
    },
    [MUGSHOT_SAKURA_LITTLE_BOY] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SakuraLittleBoyNormal,
            .pal = gObjectEventPal_Npc_Sakura,
        }
    },
    [MUGSHOT_SAKURA_LITTLE_GIRL] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SakuraLittleGirlNormal,
            .pal = gObjectEventPal_Npc_Sakura,
        }
    },
    [MUGSHOT_SAKURA_GIRL_1] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SakuraGirl1Normal,
            .pal = gObjectEventPal_Npc_Sakura,
        }
    },
    [MUGSHOT_SAKURA_GIRL_2] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SakuraGirl2Normal,
            .pal = gObjectEventPal_Npc_Sakura,
        }
    },
    [MUGSHOT_SAKURA_BOY_1] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SakuraBoy1Normal,
            .pal = gObjectEventPal_Npc_Sakura,
        }
    },
    [MUGSHOT_SAKURA_BOY_2] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SakuraBoy2Normal,
            .pal = gObjectEventPal_Npc_Sakura,
        }
    },
    [MUGSHOT_SAKURA_FAT_GUY] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SakuraFatGuyNormal,
            .pal = gObjectEventPal_Npc_Sakura,
        }
    },
    [MUGSHOT_SAKURA_NURSE] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SakuraNurseNormal,
            .pal = gObjectEventPal_Npc_Sakura,
        }
    },
    [MUGSHOT_SAKURA_VALET] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SakuraValetNormal,
            .pal = gObjectEventPal_Npc_Sakura,
        }
    },

    // Hot

    [MUGSHOT_HOT_MAN_2] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_HotMan2Normal,
            .pal = gObjectEventPal_Npc_Hot,
        }
    },

    [MUGSHOT_MOUNTAIN_WOMAN_1] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_MountainWoman1Normal,
            .pal = gObjectEventPal_Npc_Mountain,
        }
    },
    [MUGSHOT_MOUNTAIN_WOMAN_2] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_MountainWoman2Normal,
            .pal = gObjectEventPal_Npc_Mountain,
        }
    },
    [MUGSHOT_MOUNTAIN_MAN_1] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_MountainMan1Normal,
            .pal = gObjectEventPal_Npc_Mountain,
        }
    },
    [MUGSHOT_MOUNTAIN_MAN_2] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_MountainMan2Normal,
            .pal = gObjectEventPal_Npc_Mountain,
        }
    },
    [MUGSHOT_MOUNTAIN_OLD_MAN] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_MountainOldManNormal,
            .pal = gObjectEventPal_Npc_Mountain,
        }
    },
    [MUGSHOT_MOUNTAIN_OLD_WOMAN] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_MountainOldWomanNormal,
            .pal = gObjectEventPal_Npc_Mountain,
        }
    },
    [MUGSHOT_MOUNTAIN_LITTLE_BOY] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_MountainLittleBoyNormal,
            .pal = gObjectEventPal_Npc_Mountain,
        }
    },
    [MUGSHOT_MOUNTAIN_LITTLE_GIRL] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_MountainLittleGirlNormal,
            .pal = gObjectEventPal_Npc_Mountain,
        }
    },
    [MUGSHOT_MOUNTAIN_GIRL_1] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_MountainGirl1Normal,
            .pal = gObjectEventPal_Npc_Mountain,
        }
    },
    [MUGSHOT_MOUNTAIN_GIRL_2] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_MountainGirl2Normal,
            .pal = gObjectEventPal_Npc_Mountain,
        }
    },
    [MUGSHOT_MOUNTAIN_BOY_1] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_MountainBoy1Normal,
            .pal = gObjectEventPal_Npc_Mountain,
        }
    },
    [MUGSHOT_MOUNTAIN_BOY_2] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_MountainBoy2Normal,
            .pal = gObjectEventPal_Npc_Mountain,
        }
    },
    [MUGSHOT_MOUNTAIN_FAT_GUY] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_MountainFatGuyNormal,
            .pal = gObjectEventPal_Npc_Mountain,
        }
    },
    [MUGSHOT_MOUNTAIN_NURSE] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_MountainNurseNormal,
            .pal = gObjectEventPal_Npc_Mountain,
        }
    },
    [MUGSHOT_MOUNTAIN_VALET] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_MountainValetNormal,
            .pal = gObjectEventPal_Npc_Mountain,
        }
    },

};

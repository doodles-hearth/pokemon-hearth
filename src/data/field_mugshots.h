#include "object_event_graphics.h"

static const u32 sFieldMugshotGfx_TestNormal[] = INCBIN_U32("graphics/field_mugshots/test/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_TestAlt[] = INCBIN_U32("graphics/field_mugshots/test/alt.4bpp.smol");
static const u16 sFieldMugshotPal_TestNormal[] = INCBIN_U16("graphics/field_mugshots/test/normal.gbapal");
static const u16 sFieldMugshotPal_TestAlt[] = INCBIN_U16("graphics/field_mugshots/test/alt.gbapal");

static const u32 sFieldMugshotGfx_HarikoNormal[] = INCBIN_U32("graphics/field_mugshots/hariko/normal.4bpp.smol");

static const u32 sFieldMugshotGfx_NatsukiNormal[] = INCBIN_U32("graphics/field_mugshots/natsuki/normal.4bpp.smol");

static const u32 sFieldMugshotGfx_BigSisNormal[] = INCBIN_U32("graphics/field_mugshots/big_sis/normal.4bpp.smol");

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
};

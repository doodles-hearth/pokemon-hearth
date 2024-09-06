static const u32 sFieldMugshotGfx_Archie_Normal[] = INCBIN_U32("graphics/field_mugshots/archie/normal.4bpp.lz");
static const u32 sFieldMugshotGfx_Archie_Grinning[] = INCBIN_U32("graphics/field_mugshots/archie/grinning.4bpp.lz");
static const u32 sFieldMugshotGfx_Archie_Shocked[] = INCBIN_U32("graphics/field_mugshots/archie/shocked.4bpp.lz");
static const u32 sFieldMugshotGfx_Archie_Disgusted[] = INCBIN_U32("graphics/field_mugshots/archie/disgusted.4bpp.lz");
static const u32 sFieldMugshotGfx_Archie_Embarrassed[] = INCBIN_U32("graphics/field_mugshots/archie/embarrassed.4bpp.lz");
static const u32 sFieldMugshotGfx_Archie_Excited[] = INCBIN_U32("graphics/field_mugshots/archie/excited.4bpp.lz");
static const u32 sFieldMugshotGfx_Archie_Sad[] = INCBIN_U32("graphics/field_mugshots/archie/sad.4bpp.lz");

static const u32 sFieldMugshotGfx_Mom_Normal[] = INCBIN_U32("graphics/field_mugshots/mom/normal.4bpp.lz");
static const u32 sFieldMugshotGfx_Mom_Happy[] = INCBIN_U32("graphics/field_mugshots/mom/happy.4bpp.lz");
static const u32 sFieldMugshotGfx_Mom_Angry[] = INCBIN_U32("graphics/field_mugshots/mom/angry.4bpp.lz");

static const u32 sFieldMugshotGfx_Lass_Normal[] = INCBIN_U32("graphics/field_mugshots/lass/normal.4bpp.lz");
static const u32 sFieldMugshotGfx_Lass_Happy[] = INCBIN_U32("graphics/field_mugshots/lass/happy.4bpp.lz");
static const u32 sFieldMugshotGfx_Lass_Sweat[] = INCBIN_U32("graphics/field_mugshots/lass/sweat.4bpp.lz");
static const u32 sFieldMugshotGfx_Lass_Surprised[] = INCBIN_U32("graphics/field_mugshots/lass/surprised.4bpp.lz");

static const u32 sFieldMugshotGfx_Man_Normal[] = INCBIN_U32("graphics/field_mugshots/man/normal.4bpp.lz");
static const u32 sFieldMugshotGfx_Man_Sad[] = INCBIN_U32("graphics/field_mugshots/man/sad.4bpp.lz");

static const u32 sFieldMugshotGfx_LittleBoy_Normal[] = INCBIN_U32("graphics/field_mugshots/littleboy/normal.4bpp.lz");

static const u32 sFieldMugshotGfx_LittleGirl_Normal[] = INCBIN_U32("graphics/field_mugshots/littlegirl/normal.4bpp.lz");
static const u32 sFieldMugshotGfx_LittleGirl_Pensive[] = INCBIN_U32("graphics/field_mugshots/littlegirl/pensive.4bpp.lz");

static const u32 sFieldMugshotGfx_Sunbather_Normal[] = INCBIN_U32("graphics/field_mugshots/sunbather/normal.4bpp.lz");
static const u32 sFieldMugshotGfx_Sunbather_Pensive[] = INCBIN_U32("graphics/field_mugshots/sunbather/pensive.4bpp.lz");

static const u16 sFieldMugshotPal_DarkBg[] = INCBIN_U16("graphics/object_events/palettes/comp_npc_darkbg.gbapal");
static const u16 sFieldMugshotPal_BrownBg[] = INCBIN_U16("graphics/object_events/palettes/comp_npc_brownbg.gbapal");

struct MugshotGfx
{
    const u32 *gfx;
    const u16 *pal;
};

static const struct MugshotGfx sFieldMugshots[MUGSHOT_COUNT][EMOTE_COUNT] =
{
    [MUGSHOT_ARCHIE] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_Archie_Normal,
            .pal = sFieldMugshotPal_BrownBg,
        },

        [EMOTE_GRINNING] =
        {
            .gfx = sFieldMugshotGfx_Archie_Grinning,
            .pal = sFieldMugshotPal_BrownBg,
        },

        [EMOTE_THINKING] =
        {
            .gfx = sFieldMugshotGfx_Archie_Normal,
            .pal = sFieldMugshotPal_BrownBg,
        },

        [EMOTE_DISGUSTED] =
        {
            .gfx = sFieldMugshotGfx_Archie_Disgusted,
            .pal = sFieldMugshotPal_BrownBg,
        },

        [EMOTE_SAD] =
        {
            .gfx = sFieldMugshotGfx_Archie_Sad,
            .pal = sFieldMugshotPal_BrownBg,
        },

        [EMOTE_ANGRY] =
        {
            .gfx = sFieldMugshotGfx_Archie_Normal,
            .pal = sFieldMugshotPal_BrownBg,
        },

        [EMOTE_SURPRISED] =
        {
            .gfx = sFieldMugshotGfx_Archie_Normal,
            .pal = sFieldMugshotPal_BrownBg,
        },

        [EMOTE_SHOCKED] =
        {
            .gfx = sFieldMugshotGfx_Archie_Shocked,
            .pal = sFieldMugshotPal_BrownBg,
        },

        [EMOTE_BLIND] =
        {
            .gfx = sFieldMugshotGfx_Archie_Normal,
            .pal = sFieldMugshotPal_BrownBg,
        },

        [EMOTE_EMBARRASSED] =
        {
            .gfx = sFieldMugshotGfx_Archie_Embarrassed,
            .pal = sFieldMugshotPal_BrownBg,
        },

        [EMOTE_EXCITED] =
        {
            .gfx = sFieldMugshotGfx_Archie_Excited,
            .pal = sFieldMugshotPal_BrownBg,
        },
    },
    [MUGSHOT_MOM] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_Mom_Normal,
            .pal = sFieldMugshotPal_BrownBg,
        },

        [EMOTE_HAPPY] =
        {
            .gfx = sFieldMugshotGfx_Mom_Happy,
            .pal = sFieldMugshotPal_BrownBg,
        },

        [EMOTE_ANGRY] =
        {
            .gfx = sFieldMugshotGfx_Mom_Angry,
            .pal = sFieldMugshotPal_BrownBg,
        },
    },
    [MUGSHOT_LASS] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_Lass_Normal,
            .pal = sFieldMugshotPal_BrownBg,
        },

        [EMOTE_HAPPY] =
        {
            .gfx = sFieldMugshotGfx_Lass_Happy,
            .pal = sFieldMugshotPal_BrownBg,
        },

        [EMOTE_SWEAT] =
        {
            .gfx = sFieldMugshotGfx_Lass_Sweat,
            .pal = sFieldMugshotPal_BrownBg,
        },

        [EMOTE_SURPRISED] =
        {
            .gfx = sFieldMugshotGfx_Lass_Surprised,
            .pal = sFieldMugshotPal_BrownBg,
        },
    },
    [MUGSHOT_MAN] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_Man_Normal,
            .pal = sFieldMugshotPal_BrownBg,
        },

        [EMOTE_SAD] =
        {
            .gfx = sFieldMugshotGfx_Man_Sad,
            .pal = sFieldMugshotPal_BrownBg,
        },
    },
    [MUGSHOT_LITTLE_BOY] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_LittleBoy_Normal,
            .pal = sFieldMugshotPal_BrownBg,
        },
    },
    [MUGSHOT_LITTLE_GIRL] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_LittleGirl_Normal,
            .pal = sFieldMugshotPal_BrownBg,
        },

        [EMOTE_PENSIVE] =
        {
            .gfx = sFieldMugshotGfx_LittleGirl_Pensive,
            .pal = sFieldMugshotPal_BrownBg,
        },
    },
    [MUGSHOT_SUNBATHER] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_Sunbather_Normal,
            .pal = sFieldMugshotPal_DarkBg,
        },

        [EMOTE_PENSIVE] =
        {
            .gfx = sFieldMugshotGfx_Sunbather_Pensive,
            .pal = sFieldMugshotPal_DarkBg,
        },
    },
};

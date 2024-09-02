static const u32 sFieldMugshotGfx_Archie_Normal[] = INCBIN_U32("graphics/field_mugshots/archie/normal.4bpp.lz");
static const u32 sFieldMugshotGfx_Archie_Grinning[] = INCBIN_U32("graphics/field_mugshots/archie/grinning.4bpp.lz");
static const u32 sFieldMugshotGfx_Archie_Shocked[] = INCBIN_U32("graphics/field_mugshots/archie/shocked.4bpp.lz");
static const u32 sFieldMugshotGfx_Archie_Disgusted[] = INCBIN_U32("graphics/field_mugshots/archie/disgusted.4bpp.lz");
static const u32 sFieldMugshotGfx_Archie_Embarrassed[] = INCBIN_U32("graphics/field_mugshots/archie/embarrassed.4bpp.lz");
static const u32 sFieldMugshotGfx_Archie_Excited[] = INCBIN_U32("graphics/field_mugshots/archie/excited.4bpp.lz");
static const u32 sFieldMugshotGfx_Archie_Sad[] = INCBIN_U32("graphics/field_mugshots/archie/sad.4bpp.lz");

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
};
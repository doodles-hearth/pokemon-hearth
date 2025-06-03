static const u32 sFieldMugshotGfx_TestNormal[] = INCBIN_U32("graphics/field_mugshots/test/normal.4bpp.smol");
static const u32 sFieldMugshotGfx_TestAlt[] = INCBIN_U32("graphics/field_mugshots/test/alt.4bpp.smol");
static const u16 sFieldMugshotPal_TestNormal[] = INCBIN_U16("graphics/field_mugshots/test/normal.gbapal");
static const u16 sFieldMugshotPal_TestAlt[] = INCBIN_U16("graphics/field_mugshots/test/alt.gbapal");

static const u32 sFieldMugshotGfx_HarikoNormal[] = INCBIN_U32("graphics/field_mugshots/hariko/normal.4bpp.smol");
static const u16 sFieldMugshotPal_HarikoNormal[] = INCBIN_U16("graphics/field_mugshots/hariko/normal.gbapal");

static const u32 sFieldMugshotGfx_NatsukiNormal[] = INCBIN_U32("graphics/field_mugshots/natsuki/normal.4bpp.smol");
static const u16 sFieldMugshotPal_NatsukiNormal[] = INCBIN_U16("graphics/field_mugshots/natsuki/normal.gbapal");

struct MugshotGfx
{
    const u32 *gfx;
    const u16 *pal;
};

static const struct MugshotGfx sFieldMugshots[MUGSHOT_COUNT][EMOTE_COUNT] =
{
    [MUGSHOT_TEST] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_TestNormal,
            .pal = sFieldMugshotPal_TestNormal,
        },

        [EMOTE_ALT] =
        {
            .gfx = sFieldMugshotGfx_TestAlt,
            .pal = sFieldMugshotPal_TestAlt,
        },
    },
    [MUGSHOT_HARIKO] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_HarikoNormal,
            .pal = sFieldMugshotPal_HarikoNormal,
        },
    },
    [MUGSHOT_NATSUKI] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_NatsukiNormal,
            .pal = sFieldMugshotPal_NatsukiNormal,
        },
    },
};

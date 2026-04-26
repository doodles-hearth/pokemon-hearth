const struct LiveEventData sLiveEvents[LIVE_EVENT_COUNT] =
{
    [LIVE_EVENT_HELLO] =
    {
        .func = HelloFunc,
        .retriggerDelay = 0,
        .duration = 120,
        .triggerRange = 2,
    },
    [LIVE_EVENT_HALT] =
    {
        .func = LiveHaltFunc,
        .retriggerDelay = 600,
        .duration = 120,
        .triggerRange = 0,
    },
    [LIVE_EVENT_WOOBAT_FLEE] =
    {
        .func = LiveWoobatFlee,
        .retriggerDelay = 0,
        .duration = 240,
        .triggerRange = 2,
    },
    [LIVE_EVENT_SIGH] =
    {
        .func = LiveSigh,
        .retriggerDelay = 800,
        .duration = 500,
        .triggerRange = 2,
    },
    [LIVE_EVENT_CHATOT] =
    {
        .func = LiveChatot,
        .retriggerDelay = 600,
        .duration = 200,
        .triggerRange = 3,
    },
    [LIVE_EVENT_CROBAT_SHOP] =
    {
        .func = LiveCrobatShop,
        .retriggerDelay = 600,
        .duration = 200,
        .triggerRange = 3,
    },
};

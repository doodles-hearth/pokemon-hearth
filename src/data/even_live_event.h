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
};

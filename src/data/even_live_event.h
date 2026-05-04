const struct LiveEventData sLiveEvents[LIVE_EVENT_COUNT] =
{
    [LIVE_EVENT_HALT] =
    {
        .func = LiveHaltFunc,
        .retriggerDelay = 600,
        .duration = 120,
        .triggerRange = 0,
    },
    [LIVE_EVENT_DEERLING1_FLEE] =
    {
        .func = LiveDeerling1Flee,
        .retriggerDelay = 0,
        .duration = 240,
        .triggerRange = 2,
    },
    [LIVE_EVENT_DEERLING2_FLEE] =
    {
        .func = LiveDeerling2Flee,
        .retriggerDelay = 0,
        .duration = 240,
        .triggerRange = 2,
    },
    [LIVE_EVENT_SIGH] =
    {
        .func = LiveSigh,
        .retriggerDelay = 800,
        .duration = 200,
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

#ifndef GUARD_CAMPFIRE_H
#define GUARD_CAMPFIRE_H

bool8 CampfireIsActive(void);
void RollDailyCampfireEvents(u16 days);
bool8 MovedTooFarFromCampfire(u16 x, u16 y);

enum CampfireCount
{
    CAMPFIRE_GINKO_WOODS,
    CAMPFIRE_COUNT,
};

enum CampfireEventGroups
{
    CAMPFIRE_EVENT_GROUP_NONE,
    CAMPFIRE_EVENT_GROUP_OPPONENT,
    CAMPFIRE_EVENT_GROUP_FRIENDLY,
    CAMPFIRE_EVENT_GROUP_PARTYMON,
};

enum CampfireEventCount
{
    CAMPFIRE_EVENT_1,
    CAMPFIRE_EVENT_2,
    CAMPFIRE_EVENT_COUNT,
};

#endif //GUARD_CAMPFIRE_H
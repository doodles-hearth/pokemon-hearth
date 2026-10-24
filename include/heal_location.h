#ifndef GUARD_HEAL_LOCATION_H
#define GUARD_HEAL_LOCATION_H

struct HealLocation
{
    u8 mapGroup;
    u8 mapNum;
    u16 x;
    u16 y;
};

u32 GetHealLocationIndexByMap(u8 mapGroup, u8 mapNum);
u32 GetHealLocationIndexByWarpData(struct WarpData *warp);
const struct HealLocation *GetHealLocationByMap(u8 mapGroup, u8 mapNum);
const struct HealLocation *GetHealLocation(u32 index);
bool32 IsLastHealLocationPlayerHouse();
void SetWhiteoutRespawnWarpAndHealerNPC(struct WarpData * warp);
u32 GetHealNpcLocalId(u32 healLocationId);

#endif // GUARD_HEAL_LOCATION_H

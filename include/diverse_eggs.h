#ifndef GUARD_DIVERSE_EGGS_H
#define GUARD_DIVERSE_EGGS_H

extern u16 gDiverseEggPalette[16];

u16 *LoadEggPalette(enum Species species);
const u32 *GetEggSpriteData(enum Species species);
bool32 IsKnownEggGroup(enum Species species);

#endif // GUARD_DIVERSE_EGGS_H
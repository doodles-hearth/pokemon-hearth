#ifndef GUARD_TARC_SPEEDUP
#define GUARD_TARC_SPEEDUP

#include "global.h"
#include "gba/types.h"

#define MAX_SPEEDUP 10
#define BATTLE_SPEED_NORMAL 0
#define BATTLE_SPEED_MID    1
#define BATTLE_SPEED_FAST   2

void StartSpeedup(void);
void StopSpeedup(void);
void CheckSpeedupControls(void);
bool32 SpeedupShouldSkip(void);
bool32 SpeedupIsPaused(void);

#endif
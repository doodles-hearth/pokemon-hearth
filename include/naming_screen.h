#ifndef GUARD_NAMING_SCREEN_H
#define GUARD_NAMING_SCREEN_H

#include "main.h"

enum {
    NAMING_SCREEN_PLAYER,
    NAMING_SCREEN_BOX,
    NAMING_SCREEN_CAUGHT_MON,
    NAMING_SCREEN_NICKNAME,
    NAMING_SCREEN_WALDA,
    NAMING_SCREEN_RIVAL,
    NAMING_SCREEN_DEX_RIDDLE,
};

void DoNamingScreen(u8 templateNum, u8 *destBuffer, u16 monSpecies, u16 monGender, u32 monPersonality, MainCallback returnCallback);

// TODO EVA for tests only
void NameRival(void);

#endif // GUARD_NAMING_SCREEN_H

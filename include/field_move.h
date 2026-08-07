#ifndef GUARD_FIELD_MOVE_H
#define GUARD_FIELD_MOVE_H

#include "global.h"
#include "constants/field_move.h"

typedef bool32 (*FieldMoveUnlockFunc)(u32);

struct FieldMoveUnlock
{
   bool32 (*isUnlockedFunc)(enum FieldMove);
   const u8 *lockedMessage;
};

enum FieldMoveUnlockType
{
    CANT_UNLOCK,
    ALWAYS_UNLOCKED,
    BADGE_UNLOCK,
    BADGE_ITEM_UNLOCK,
    FIELD_MOVE_UNLOCK_COUNT
};

struct FieldMoveInfo
{
    bool32 (*fieldMoveFunc)(void);
    enum FieldMoveUnlockType unlockType:3;
    enum Move moveID:11;
    u8 partyMsgID:7;
    u8 hideIfLocked:1;
    u32 padding:11;
    union {
        u32 arg32;
        u16 arg16[2];
        u8 arg8[4];
    };
    FieldMoveUnlockFunc func;
};

bool32 KnowsFieldMove(struct Pokemon *mon, u32 fieldMoveType);
bool32 IsFieldMoveKnownByAnotherPartyMon(u32 fieldMoveType, u32 monPartyIndex, struct Pokemon * mons);

extern const struct FieldMoveInfo gFieldMoveInfo[];
extern const struct FieldMoveUnlock gFieldMoveUnlocks[];

static inline bool32 SetUpFieldMove(enum FieldMove fieldMove)
{
    return gFieldMoveInfo[fieldMove].fieldMoveFunc();
}

static inline bool32 IsFieldMoveUnlocked(enum FieldMove fieldMove)
{
    return gFieldMoveUnlocks[gFieldMoveInfo[fieldMove].unlockType].isUnlockedFunc(fieldMove);
}

static inline const u8 *FieldMove_GetLockedMessage(enum FieldMove fieldMove)
{
    return gFieldMoveUnlocks[gFieldMoveInfo[fieldMove].unlockType].lockedMessage;
}

static inline enum Move FieldMove_GetMoveId(enum FieldMove fieldMove)
{
    return gFieldMoveInfo[fieldMove].moveID;
}

static inline u32 FieldMove_GetPartyMsgID(enum FieldMove fieldMove)
{
    return gFieldMoveInfo[fieldMove].partyMsgID;
}

static inline bool32 FieldMove_IsVisible(enum FieldMove fieldMove)
{
    return !gFieldMoveInfo[fieldMove].hideIfLocked || IsFieldMoveUnlocked(fieldMove);
}

#endif //GUARD_FIELD_MOVE_H

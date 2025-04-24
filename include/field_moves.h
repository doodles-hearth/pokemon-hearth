#ifndef FIELD_MOVES_DEFINES_H
#define FIELD_MOVES_DEFINES_H

#include "constants/field_moves.h"

struct FieldMoveGrant {
    u32 fieldMoveType;
    u32 grantFlag;
};

extern const struct FieldMoveGrant gFieldMoveGrant[];

u32 FindFieldMoveGrantIndexByType(u32 fieldMoveType);
u32 FindFieldMoveTypeByMove(u32 moveId);
bool32 KnowsFieldMove(struct Pokemon *mon, u32 fieldMoveType);
bool32 IsFieldMoveKnownByAnotherPartyMon(u32 fieldMoveType, u32 monPartyIndex, struct Pokemon * mons);

#endif // FIELD_MOVES_DEFINES_H

#include "global.h"
#include "field_moves.h"
#include "move.h"

// Associates each field move type with the flag that is set once
// the player is granted that field move
const struct FieldMoveGrant gFieldMoveGrant[] =
    {
        {IS_FIELD_MOVE_CUT, FLAG_RECEIVED_HM_CUT},
        {IS_FIELD_MOVE_SMASH, FLAG_RECEIVED_HM_ROCK_SMASH},
        {IS_FIELD_MOVE_PUSH, FLAG_RECEIVED_HM_STRENGTH},
        {IS_FIELD_MOVE_SURF, FLAG_RECEIVED_HM_SURF},
        {IS_FIELD_MOVE_WATERFALL, FLAG_RECEIVED_HM_WATERFALL},
        {IS_FIELD_MOVE_DIVE, FLAG_RECEIVED_HM_DIVE},
        {IS_FIELD_MOVE_DIG, FLAG_RECEIVED_TM_DIG},
        {IS_FIELD_MOVE_FLASH, FLAG_RECEIVED_HM_FLASH},
        {IS_FIELD_MOVE_FLY, FLAG_RECEIVED_HM_FLY},
        {IS_FIELD_MOVE_SECRET_POWER, FLAG_GOT_SECRET_POWER},
        {FIELD_MOVE_COUNT, NULL},
};

u32 FindFieldMoveGrantIndexByType(u32 fieldMoveType)
{
    for (u32 i = 0; gFieldMoveGrant[i].fieldMoveType != FIELD_MOVE_COUNT; i += 1)
    {
        if (gFieldMoveGrant[i].fieldMoveType == fieldMoveType)
        {
            return i;
        }
    }
    return 0xFF;
}

u32 FindFieldMoveTypeByMove(u32 moveId)
{
    for (enum FieldMoveType fieldMoveType = IS_FIELD_MOVE_CUT; fieldMoveType < FIELD_MOVE_COUNT; fieldMoveType = fieldMoveType << 1)
    {
        if (gMovesInfo[moveId].fieldMoveFlags & fieldMoveType)
        {
            return fieldMoveType;
        }
    }
    return FIELD_MOVE_COUNT;
}
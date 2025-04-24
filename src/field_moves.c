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

/**
 * Checks if the given Pokémon knows at least one move of the given field move type.
 *
 * @param mon           Pokémon
 * @param fieldMoveType field move type
 * @return true if the Pokémon knows the field move, false otherwise
 */
bool32 KnowsFieldMove(struct Pokemon *mon, u32 fieldMoveType)
{
    if (GetMonData(mon, MON_DATA_IS_EGG)) {
        return FALSE;
    }

    // Check the field move flags of each of the Pokémon's 4 moves
    for (u32 iMoveSlot = 0; iMoveSlot < MAX_MON_MOVES; iMoveSlot += 1)
    {
        u16 move = GetMonData(mon, MON_DATA_MOVE1 + iMoveSlot, NULL);

        if (move == MOVE_NONE)
        {
            break;
        }

        if (gMovesInfo[move].fieldMoveFlags & fieldMoveType)
        {
            return TRUE;
        }
    }
    
    return FALSE;
}

/**
 * Checks if the given field move is known by at least one Pokémon other than the given one.
 *
 * @param fieldMoveType field move type
 * @param monPartyIndex index of the selected Pokémon in the party
 * @param mons          party mons
 * @return true if the field move is known by another party mon, false otherwise
 */
bool32 IsFieldMoveKnownByAnotherPartyMon(u32 fieldMoveType, u32 monPartyIndex, struct Pokemon * mons)
{
    bool32 otherMonAlsoKnowsFieldMove = FALSE;
    // For each of the other mons in the party
    for (u32 j = 0; j < PARTY_SIZE; j += 1)
    {
        if (
            monPartyIndex != j
            && GetMonData(&mons[j], MON_DATA_SPECIES_OR_EGG) != SPECIES_NONE
            && GetMonData(&mons[j], MON_DATA_SPECIES_OR_EGG) != SPECIES_EGG
        )
        {
            // If the mon knows the field move, we're good
            if (KnowsFieldMove(&mons[j], fieldMoveType))
            {
                otherMonAlsoKnowsFieldMove = TRUE;
                break;
            }
        }
    }
    
    // No other mon knows this field move, so the move has to stay
    if (!otherMonAlsoKnowsFieldMove) {
        return FALSE;
    }

    return TRUE;
}

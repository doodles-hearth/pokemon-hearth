#include "global.h"
#include "constants/items.h"
#include "event_data.h"
#include "field_move.h"
#include "fldeff.h"
#include "fldeff_misc.h"
#include "item.h"
#include "move.h"
#include "party_menu.h"
#include "strings.h"
#include "constants/field_move.h"
#include "constants/moves.h"
#include "constants/party_menu.h"

static bool32 IsAlwaysFalse(enum FieldMove fieldMove)
{
    return FALSE;
}

static bool32 IsAlwaysTrue(enum FieldMove fieldMove)
{
    return TRUE;
}

static bool32 HasBadgeForFieldMove(enum FieldMove fieldMove)
{
    return FlagGet(gFieldMoveInfo[fieldMove].arg32 + FLAG_BADGE01_GET);
}

static bool32 HasBadgeAndItemForFieldMove(enum FieldMove fieldMove)
{
    bool32 hasBadge = FlagGet(gFieldMoveInfo[fieldMove].arg16[0] + FLAG_BADGE01_GET);
    bool32 hasItem = CheckBagHasItem(gFieldMoveInfo[fieldMove].arg16[1], 1);
    return hasBadge && hasItem;
}

const struct FieldMoveUnlock gFieldMoveUnlocks[FIELD_MOVE_UNLOCK_COUNT] =
{
    [CANT_UNLOCK] =
    {
        .isUnlockedFunc = IsAlwaysFalse,
        .lockedMessage = gText_EmptyString2,
    },
    [ALWAYS_UNLOCKED] =
    {
        .isUnlockedFunc = IsAlwaysTrue,
        .lockedMessage = gText_EmptyString2,
    },
    [BADGE_UNLOCK] =
    {
        .isUnlockedFunc = HasBadgeForFieldMove,
        .lockedMessage = gText_CantUseUntilNewBadge,
    },
    [BADGE_ITEM_UNLOCK] =
    {
        .isUnlockedFunc = HasBadgeAndItemForFieldMove,
        .lockedMessage = gText_CantUseUntilNewBadge,
    }
};

#define FLAG_TO_BADGE(flag) flag - FLAG_BADGE01_GET

const struct FieldMoveInfo gFieldMoveInfo[FIELD_MOVES_COUNT] =
{
    [FIELD_MOVE_CUT] =
    {
        .fieldMoveFunc = SetUpFieldMove_Cut,
        .unlockType = BADGE_UNLOCK,
        .moveID = MOVE_CUT,
        .partyMsgID = PARTY_MSG_NOTHING_TO_CUT,
        .arg16 = { IS_FRLG ? FLAG_TO_BADGE(FLAG_BADGE02_GET) : FLAG_TO_BADGE(FLAG_BADGE01_GET), ITEM_SECRET_CUT },
    },

    [FIELD_MOVE_FLASH] =
    {
        .fieldMoveFunc = SetUpFieldMove_Flash,
        .unlockType = BADGE_UNLOCK,
        .moveID = MOVE_FLASH,
        .partyMsgID = PARTY_MSG_CANT_USE_HERE,
        .arg16 = { IS_FRLG ? FLAG_TO_BADGE(FLAG_BADGE01_GET) : FLAG_TO_BADGE(FLAG_BADGE02_GET), ITEM_SECRET_FLASH },
    },

    [FIELD_MOVE_ROCK_SMASH] =
    {
        .fieldMoveFunc = SetUpFieldMove_RockSmash,
        .unlockType = BADGE_UNLOCK,
        .moveID = MOVE_ROCK_SMASH,
        .partyMsgID = PARTY_MSG_CANT_USE_HERE,
        .arg16 = { IS_FRLG ? FLAG_TO_BADGE(FLAG_BADGE06_GET) : FLAG_TO_BADGE(FLAG_BADGE03_GET), ITEM_SECRET_SMASH },
    },

    [FIELD_MOVE_STRENGTH] =
    {
        .fieldMoveFunc = SetUpFieldMove_Strength,
        .unlockType = BADGE_UNLOCK,
        .moveID = MOVE_STRENGTH,
        .partyMsgID = PARTY_MSG_CANT_USE_HERE,
        .arg16 = { FLAG_TO_BADGE(FLAG_BADGE04_GET), ITEM_SECRET_STRENGTH },
    },

    [FIELD_MOVE_SURF] =
    {
        .fieldMoveFunc = SetUpFieldMove_Surf,
        .unlockType = BADGE_UNLOCK,
        .moveID = MOVE_SURF,
        .partyMsgID = PARTY_MSG_CANT_SURF_HERE,
        .arg16 = { FLAG_TO_BADGE(FLAG_BADGE05_GET), ITEM_SECRET_SURF },
    },

    [FIELD_MOVE_FLY] =
    {
        .fieldMoveFunc = SetUpFieldMove_Fly,
        .unlockType = BADGE_UNLOCK,
        .moveID = MOVE_FLY,
        .partyMsgID = PARTY_MSG_CANT_USE_HERE,
        .arg16 = { IS_FRLG ? FLAG_TO_BADGE(FLAG_BADGE03_GET) : FLAG_TO_BADGE(FLAG_BADGE06_GET), ITEM_SECRET_FLY },
    },

    [FIELD_MOVE_DIVE] =
    {
        .fieldMoveFunc = SetUpFieldMove_Dive,
        .unlockType = BADGE_UNLOCK,
        .moveID = MOVE_DIVE,
        .partyMsgID = PARTY_MSG_CANT_USE_HERE,
        .arg16 = { FLAG_TO_BADGE(FLAG_BADGE07_GET), ITEM_SECRET_DIVE},
    },

    [FIELD_MOVE_WATERFALL] =
    {
        .fieldMoveFunc = SetUpFieldMove_Waterfall,
        .unlockType = BADGE_UNLOCK,
        .moveID = MOVE_WATERFALL,
        .partyMsgID = PARTY_MSG_CANT_USE_HERE,
        .arg16 = { IS_FRLG ? FLAG_TO_BADGE(FLAG_BADGE07_GET) : FLAG_TO_BADGE(FLAG_BADGE08_GET), ITEM_SECRET_WATERFALL},
    },

    [FIELD_MOVE_TELEPORT] =
    {
        .fieldMoveFunc = SetUpFieldMove_Teleport,
        .unlockType = ALWAYS_UNLOCKED,
        .moveID = MOVE_TELEPORT,
        .partyMsgID = PARTY_MSG_CANT_USE_HERE,
    },

    [FIELD_MOVE_DIG] =
    {
        .fieldMoveFunc = SetUpFieldMove_Dig,
        .unlockType = ALWAYS_UNLOCKED,
        .moveID = MOVE_DIG,
        .partyMsgID = PARTY_MSG_CANT_USE_HERE,
    },

    [FIELD_MOVE_SECRET_POWER] =
    {
        .fieldMoveFunc = SetUpFieldMove_SecretPower,
        .unlockType = ALWAYS_UNLOCKED,
        .moveID = MOVE_SECRET_POWER,
        .partyMsgID = PARTY_MSG_CANT_USE_HERE,
    },

    [FIELD_MOVE_MILK_DRINK] =
    {
        .fieldMoveFunc = SetUpFieldMove_SoftBoiled,
        .unlockType = ALWAYS_UNLOCKED,
        .moveID = MOVE_MILK_DRINK, .partyMsgID = PARTY_MSG_NOT_ENOUGH_HP,
    },

    [FIELD_MOVE_SOFT_BOILED] =
    {
        .fieldMoveFunc = SetUpFieldMove_SoftBoiled,
        .unlockType = ALWAYS_UNLOCKED,
        .moveID = MOVE_SOFT_BOILED,
        .partyMsgID = PARTY_MSG_NOT_ENOUGH_HP,
    },

    [FIELD_MOVE_SWEET_SCENT] =
    {
        .fieldMoveFunc = SetUpFieldMove_SweetScent,
        .unlockType = ALWAYS_UNLOCKED,
        .moveID = MOVE_SWEET_SCENT,
        .partyMsgID = PARTY_MSG_CANT_USE_HERE,
    },
    [FIELD_MOVE_ROCK_CLIMB] =
    {
        .fieldMoveFunc = SetUpFieldMove_RockClimb,
#if OW_ROCK_CLIMB_FIELD_MOVE
        .unlockType = ALWAYS_UNLOCKED,
#else
        .unlockType = CANT_UNLOCK,
#endif
        .moveID = MOVE_ROCK_CLIMB,
        .partyMsgID = PARTY_MSG_CANT_USE_HERE,
        .hideIfLocked = TRUE,
    },
    [FIELD_MOVE_DEFOG] =
    {
        .fieldMoveFunc = SetUpFieldMove_Defog,
#if OW_DEFOG_FIELD_MOVE
        .unlockType = ALWAYS_UNLOCKED,
#else
        .unlockType = CANT_UNLOCK,
#endif
        .moveID = MOVE_DEFOG,
        .partyMsgID = PARTY_MSG_CANT_USE_HERE,
        .hideIfLocked = TRUE,
    },
};


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

        if (gMovesInfo[move].fieldMove == fieldMoveType)
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

#include "global.h"
#include "battle_anim.h"
#include "constants/battle_anim.h"
#include "constants/items.h"
#include "test/battle.h"
#include "test/test.h"

ASSUMPTIONS {
    ASSUME(gItemsInfo[ITEM_RAIKOU_BALM].battleUsage == EFFECT_ITEM_RAIKOU_BALM);
}

SINGLE_BATTLE_TEST("Raikou Balm will wake up a sleeping battler")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_RAIKOU_BALM].battleUsage == EFFECT_ITEM_RAIKOU_BALM);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_SLEEP); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_RAIKOU_BALM, partyIndex: 0); }
    } SCENE {
        MESSAGE("Wobbuffet woke up!");
    } THEN {
        EXPECT_EQ(player->status1, STATUS1_NONE);
    }
}

SINGLE_BATTLE_TEST("Raikou Balm will wake up a sleeping battler and raise its Attack stat", s16 damage)
{
    bool32 raikouBalm;

    PARAMETRIZE { raikouBalm = FALSE; }
    PARAMETRIZE { raikouBalm = TRUE; }

    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_SLEEP); }
        OPPONENT(SPECIES_WOBBUFFET);
    }
    WHEN {
        if (raikouBalm) {
            TURN { USE_ITEM(player, ITEM_RAIKOU_BALM, partyIndex : 0); }
        }
        else {
            TURN { USE_ITEM(player, ITEM_CHESTO_BERRY, partyIndex : 0); }
        }
        TURN { MOVE(player, MOVE_SCRATCH); }
    }
    SCENE {
        if (raikouBalm) {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
            MESSAGE("Wobbuffet woke up!");
        }
        else {
            NOT MESSAGE("Wobbuffet woke up!");
        }

        HP_BAR(opponent, captureDamage: &results[i].damage);
    }
    THEN {
            EXPECT_EQ(player->status1, STATUS1_NONE);
    }
    FINALLY {
            EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
    }
}

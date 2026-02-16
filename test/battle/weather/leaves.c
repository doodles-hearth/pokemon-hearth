#include "global.h"
#include "battle_anim.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/species.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Falling Leaves increase healing by 50%", s16 healing)
{
    u16 weatherMove;
    PARAMETRIZE {weatherMove = MOVE_CELEBRATE;}
    PARAMETRIZE {weatherMove = MOVE_BLOSSOM;}
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    }
    WHEN {
        TURN { MOVE(player, weatherMove); }
        TURN { MOVE(player, MOVE_RECOVER); }
    }
    SCENE {
        ANIMATION(ANIM_TYPE_MOVE, weatherMove);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RECOVER);
        HP_BAR(player, captureDamage: &results[i].healing);
    }
    FINALLY {
        EXPECT_MUL_EQ(results[0].healing, Q_4_12(1.5), results[1].healing);
    };
}

SINGLE_BATTLE_TEST("Falling Leaves causes Leftovers to recover 3/32 HP at end of turn")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { MaxHP(100); HP(1); Item(ITEM_LEFTOVERS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {MOVE(player, MOVE_BLOSSOM);}
    } SCENE {
        s32 maxHP = GetMonData(&PLAYER_PARTY[0], MON_DATA_MAX_HP);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        MESSAGE("Wobbuffet restored a little HP using its Leftovers!");
        HP_BAR(player, damage: -maxHP * 3 / 32);
    }
}

SINGLE_BATTLE_TEST("Falling Leaves multiply the power of Fairy and Grass type moves by 1.5x", s16 fairyDmg, s16 grassDmg)
{
    u32 setupMove;
    PARAMETRIZE { setupMove = MOVE_CELEBRATE; }
    PARAMETRIZE { setupMove = MOVE_BLOSSOM; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, setupMove); }
        TURN { MOVE(player, MOVE_FAIRY_WIND); }
        TURN { MOVE(player, MOVE_LEAFAGE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FAIRY_WIND, player);
        HP_BAR(opponent, captureDamage: &results[i].fairyDmg);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LEAFAGE, player);
        HP_BAR(opponent, captureDamage: &results[i].grassDmg);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].fairyDmg, Q_4_12(1.5), results[1].fairyDmg);
        EXPECT_MUL_EQ(results[0].grassDmg, Q_4_12(1.5), results[1].grassDmg);
    }
}

SINGLE_BATTLE_TEST("Falling Leaves multiply the power of Poison-type moves by 0.5x", s16 damage)
{
    u32 setupMove;
    PARAMETRIZE { setupMove = MOVE_CELEBRATE; }
    PARAMETRIZE { setupMove = MOVE_BLOSSOM; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, setupMove); }
        TURN { MOVE(player, MOVE_ACID); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ACID, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.5), results[1].damage);
    }
}


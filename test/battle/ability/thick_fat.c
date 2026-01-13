#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveType(MOVE_EMBER) == TYPE_FIRE);
    ASSUME(GetMoveType(MOVE_POWDER_SNOW) == TYPE_ICE);
    ASSUME(GetMoveEffect(MOVE_WORRY_SEED) == EFFECT_OVERWRITE_ABILITY);
}

SINGLE_BATTLE_TEST("Thick Fat halves damage from smoke explosion", s16 damage)
{
    u16 ability;
    PARAMETRIZE { ability = ABILITY_IMMUNITY; }
    PARAMETRIZE { ability = ABILITY_THICK_FAT; }

    GIVEN
    {
        PLAYER(SPECIES_VULPIX);
        OPPONENT(SPECIES_BRONZONG) { Ability(ability); }
    }
    WHEN
    {
        TURN { MOVE(player, MOVE_SMOKE_BOMB); }
        TURN { MOVE(opponent, MOVE_EMBER); }
    }
    SCENE
    {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_EXPLOSION);
        HP_BAR(opponent, captureDamage : &results[i].damage);
    }
    FINALLY { EXPECT_MUL_EQ(results[0].damage, UQ_4_12(0.5), results[1].damage); }
}

SINGLE_BATTLE_TEST("Thick Fat halves damage from fire and ice type moves", s16 damage[2])
{
    u16 move;

    PARAMETRIZE { move = MOVE_POWDER_SNOW; }
    PARAMETRIZE { move = MOVE_EMBER; }

    GIVEN {
        PLAYER (SPECIES_WOBBUFFET);
        OPPONENT (SPECIES_SNORLAX) { Ability(ABILITY_THICK_FAT); }
    }
    WHEN {
        TURN { MOVE(player, move); }
        TURN { MOVE(player, MOVE_WORRY_SEED); }
        TURN { MOVE(player, move); }
    }
    SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent, captureDamage: &results[i].damage[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WORRY_SEED, player);
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent, captureDamage: &results[i].damage[1]);
    }
    FINALLY {
        EXPECT_MUL_EQ(results[0].damage[0], Q_4_12(2), results[0].damage[1]);
        EXPECT_MUL_EQ(results[1].damage[0], Q_4_12(2), results[1].damage[1]);
    }
}


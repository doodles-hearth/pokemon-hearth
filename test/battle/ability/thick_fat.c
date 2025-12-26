#include "global.h"
#include "test/battle.h"

TO_DO_BATTLE_TEST("TODO: Write Thick Fat (Ability) test titles")

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

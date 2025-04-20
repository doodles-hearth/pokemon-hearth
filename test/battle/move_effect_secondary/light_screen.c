#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(MoveHasAdditionalEffect(MOVE_GLITZY_GLOW, MOVE_EFFECT_LIGHT_SCREEN) == TRUE);
}

SINGLE_BATTLE_TEST("Glitzy Glow sets up Light Screen when it was succesful")
{
    bool32 moveSuccess;
    PARAMETRIZE { moveSuccess = FALSE; }
    PARAMETRIZE { moveSuccess = TRUE; }

    GIVEN {
        // TODO EVA prevent tests from failing
        ASSUME(B_UPDATED_MOVE_DATA > GEN_6);

        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_GLITZY_GLOW, hit: moveSuccess); }
    } SCENE {
        if (moveSuccess == TRUE)
        {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_GLITZY_GLOW, player);
            MESSAGE("Light Screen made your team stronger against special moves!");
        } else {
            NONE_OF {
                ANIMATION(ANIM_TYPE_MOVE, MOVE_GLITZY_GLOW, player);
                MESSAGE("Light Screen made your team stronger against special moves!");
            }
        }
    }
}

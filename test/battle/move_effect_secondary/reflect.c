#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(MoveHasAdditionalEffect(MOVE_BADDY_BAD, MOVE_EFFECT_REFLECT) == TRUE);
}

SINGLE_BATTLE_TEST("Baddy Bad sets up Reflect when it was succesful")
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
        TURN { MOVE(player, MOVE_BADDY_BAD, hit: moveSuccess); }
    } SCENE {
        if (moveSuccess == TRUE)
        {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_BADDY_BAD, player);
            MESSAGE("Reflect made your team stronger against physical moves!");
        } else {
            NONE_OF {
                ANIMATION(ANIM_TYPE_MOVE, MOVE_BADDY_BAD, player);
                MESSAGE("Reflect made your team stronger against physical moves!");
            }
        }
    }
}

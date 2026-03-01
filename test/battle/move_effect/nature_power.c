#include "global.h"
#include "config/battle.h"
#include "test/battle.h"
#include "battle_environment.h"
#include "test/test.h"

//TO_DO_BATTLE_TEST("TODO: Write Nature Power (Move Effect) test titles")

SINGLE_BATTLE_TEST("Nature power plays a move correctly in any background")
{
    u32 environment = 0;
    enum Move move = MOVE_TRI_ATTACK;

    for (u32 j = 0; j < BATTLE_ENVIRONMENT_COUNT; j++) {
        PARAMETRIZE { environment = i; }
    }

    GIVEN {
        WITH_CONFIG(B_NATURE_POWER_MOVES, GEN_LATEST);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        Environment(environment);
        if (gBattleEnvironmentInfo[environment].naturePower)
            move = gBattleEnvironmentInfo[environment].naturePower;
    } WHEN {
        TURN { MOVE(player, MOVE_NATURE_POWER); }
    } SCENE {
        NOT MESSAGE("Nature Power turned into Nature Power!");
        ANIMATION(ANIM_TYPE_MOVE, move, player);
    }
}

#if B_UPDATED_MOVE_FLAGS >= GEN_6
DOUBLE_BATTLE_TEST("Nature Power can target ally (Gen6+)")
{

    if(B_NATURE_POWER_MOVES < GEN_4)
        KNOWN_FAILING;

    GIVEN {
        WITH_CONFIG(B_NATURE_POWER_MOVES, GEN_LATEST);
        PLAYER(SPECIES_WYNAUT);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_NATURE_POWER, target: playerRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRI_ATTACK, playerLeft);
    }
}
#endif

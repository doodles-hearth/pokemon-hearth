#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Dream Sleep passes randomly based on HP")
{
    u32 passes, hp;
    u32 maxHp = 9999;
    PARAMETRIZE { hp = 1; passes = DEFAULT_DREAM_CHANCE;}
    PARAMETRIZE { hp = maxHp; passes = DEFAULT_DREAM_CHANCE / 3;}
    PASSES_RANDOMLY(passes, 256, RNG_DREAM_SLEEP);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); };
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); MaxHP(maxHp); HP(hp);};
    } WHEN {
        TURN { MOVE(player, MOVE_SPORE); MOVE(opponent, MOVE_CELEBRATE); }
    } THEN {
        EXPECT(opponent->volatiles.dreamSleep);
    }
}

SINGLE_BATTLE_TEST("Dream Sleep is removed when waking up")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); };
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); };
    } WHEN {
        TURN { MOVE(player, MOVE_SPORE, WITH_RNG(RNG_SLEEP_TURNS, 1)); MOVE(opponent, MOVE_CELEBRATE); }
        TURN;
    } SCENE {
        NOT MESSAGE("The opposing Wobbuffet is fast asleep.");
        MESSAGE("The opposing Wobbuffet is deep in a dream.");
        MESSAGE("The opposing Wobbuffet woke up!");
    } THEN {
        EXPECT(!opponent->volatiles.dreamSleep);
    }
}

SINGLE_BATTLE_TEST("Dream Sleep works for player and opponent")
{
    u32 playerTarget;
    PARAMETRIZE { playerTarget = FALSE;}
    PARAMETRIZE { playerTarget = TRUE;}
    GIVEN {
        if (playerTarget)
        {
            PLAYER(SPECIES_WOBBUFFET) { Speed(1); };
            OPPONENT(SPECIES_WOBBUFFET) { Speed(2); };
        }
        else
        {
            PLAYER(SPECIES_WOBBUFFET) { Speed(2); };
            OPPONENT(SPECIES_WOBBUFFET) { Speed(1); };
        }
        
    } WHEN {
        if (playerTarget)
            TURN { MOVE(opponent, MOVE_SPORE); MOVE(player, MOVE_CELEBRATE, WITH_RNG(RNG_DREAM_SLEEP, TRUE)); }
        else
            TURN { MOVE(player, MOVE_SPORE); MOVE(opponent, MOVE_CELEBRATE, WITH_RNG(RNG_DREAM_SLEEP, TRUE)); }
    } SCENE {
        if (playerTarget)
        {
            NOT MESSAGE("Wobbuffet is fast asleep.");
            MESSAGE("Wobbuffet is deep in a dream.");
        }
        else
        {
            NOT MESSAGE("The opposing Wobbuffet is fast asleep.");
            MESSAGE("The opposing Wobbuffet is deep in a dream.");
        }
    } THEN {
        if (playerTarget)
            EXPECT(player->volatiles.dreamSleep);
        else
            EXPECT(opponent->volatiles.dreamSleep);
    }
}

SINGLE_BATTLE_TEST("Dream Sleep messages play properly whatever move is used")
{
    //s16 damage[2];
    u32 dreaming, move;
    u32 movesList[3] = {MOVE_CELEBRATE, MOVE_SNORE, MOVE_SLEEP_TALK};
    dreaming = FALSE;move = 0;
    for (u32 i = 0; i < 3; i++)
    {
        PARAMETRIZE { dreaming = FALSE; move = movesList[i]; }
        PARAMETRIZE { dreaming = TRUE; move = movesList[i]; }
    }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); };
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); };
    } WHEN {
        TURN { MOVE(player, MOVE_SPORE); MOVE(opponent, move, WITH_RNG(RNG_DREAM_SLEEP, dreaming));}
    } SCENE {
        if (dreaming)
        {
            NOT MESSAGE("The opposing Wobbuffet is fast asleep.");
            MESSAGE("The opposing Wobbuffet is deep in a dream.");
        }
        else
        {
            MESSAGE("The opposing Wobbuffet is fast asleep.");
            NOT MESSAGE("The opposing Wobbuffet is deep in a dream.");
        }
    } THEN {
        if (dreaming)
            EXPECT(opponent->volatiles.dreamSleep);
        else
            EXPECT(!opponent->volatiles.dreamSleep);
    }
}

WILD_BATTLE_TEST("Dream Sleep make dream ball work 100%")
{
    // TODO Pokémon can breed with Ditto test breaks this one
    KNOWN_FAILING;

    u32 dreaming;
    dreaming = FALSE;
    PARAMETRIZE { dreaming = FALSE;}
    PARAMETRIZE { dreaming = TRUE;}

    
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); };
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); };
    } WHEN {
        TURN { MOVE(player, MOVE_SPORE); MOVE(opponent, MOVE_CELEBRATE, WITH_RNG(RNG_DREAM_SLEEP, dreaming));}
        TURN { USE_ITEM(player, ITEM_DREAM_BALL, WITH_RNG(RNG_BALLTHROW_SHAKE, MAX_u16) ); MOVE(opponent, MOVE_CELEBRATE, WITH_RNG(RNG_DREAM_SLEEP, dreaming));}
    } SCENE {
        if (dreaming)
        {
            MESSAGE("The wild Wobbuffet is deep in a dream.");
            MESSAGE("Gotcha! Wobbuffet was caught!{WAIT_SE}{PLAY_BGM MUS_CAUGHT}\p");
            NOT MESSAGE("Oh no! The Pokémon broke free!");
        }
        else
        {

            MESSAGE("The wild Wobbuffet is fast asleep.");
            NOT MESSAGE("Gotcha! Wobbuffet was caught!");
            MESSAGE("Oh no! The Pokémon broke free!");
        }
    } THEN {
        if (dreaming)
            EXPECT(gBattleOutcome == B_OUTCOME_CAUGHT);
        else
            EXPECT(gBattleOutcome != B_OUTCOME_CAUGHT);
    }
}

WILD_BATTLE_TEST("Dream Sleep: Dream Eater deals 100% HP damage on dreaming targets")
{
    u32 dreaming;
    dreaming = FALSE;
    PARAMETRIZE { dreaming = FALSE;}
    PARAMETRIZE { dreaming = TRUE;}

    
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); };
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); };
    } WHEN {
        TURN { MOVE(player, MOVE_SPORE); MOVE(opponent, MOVE_CELEBRATE, WITH_RNG(RNG_DREAM_SLEEP, dreaming));}
        TURN { MOVE(player, MOVE_DREAM_EATER); MOVE(opponent, MOVE_CELEBRATE, WITH_RNG(RNG_DREAM_SLEEP, dreaming));}
    } SCENE {
        if (dreaming)
            MESSAGE("The wild Wobbuffet is deep in a dream.");
        else
            MESSAGE("The wild Wobbuffet is fast asleep.");
    } THEN {
        if (dreaming)
            EXPECT(opponent->hp == 0);
        else
            EXPECT(opponent->hp > 0);
    }
}

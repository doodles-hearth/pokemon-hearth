#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveType(MOVE_EMBER) == TYPE_FIRE);
    ASSUME(GetMoveEffect(MOVE_SMOKE_BOMB) == EFFECT_SMOKE_BOMB);
    ASSUME(GetSpeciesType(SPECIES_WOBBUFFET, 0) == TYPE_PSYCHIC);
    ASSUME(GetSpeciesType(SPECIES_CHARMANDER, 0) == TYPE_FIRE);
    ASSUME(GetSpeciesType(SPECIES_VOLCANION, 0) == TYPE_FIRE);
    ASSUME(GetSpeciesType(SPECIES_VOLCANION, 1) == TYPE_WATER);
    ASSUME(GetSpeciesType(SPECIES_TANGELA, 0) == TYPE_GRASS);
    ASSUME(GetSpeciesType(SPECIES_PARASECT, 0) == TYPE_BUG);
    ASSUME(GetSpeciesType(SPECIES_PARASECT, 1) == TYPE_GRASS);
}

SINGLE_BATTLE_TEST("Smoke explodes when a fire type move is used")
{
    GIVEN {
        PLAYER(SPECIES_VULPIX);
        OPPONENT(SPECIES_WOBBUFFET);
    }
    WHEN {
        TURN { MOVE(player, MOVE_SMOKE_BOMB); }
        TURN { MOVE(player, MOVE_EMBER); }
    }
    SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_EXPLOSION);
    }
}

SINGLE_BATTLE_TEST("Smoke explosion damage depends on target type")
{
    u16 species;
    PARAMETRIZE { species = SPECIES_WOBBUFFET; }
    PARAMETRIZE { species = SPECIES_CHARMANDER; }
    PARAMETRIZE { species = SPECIES_VOLCANION; }
    PARAMETRIZE { species = SPECIES_TANGELA; }
    PARAMETRIZE { species = SPECIES_PARASECT; }

    GIVEN {
        PLAYER(SPECIES_CHARMANDER);
        OPPONENT(species);
    }
    WHEN {
        TURN { MOVE(opponent, MOVE_SMOKE_BOMB); }
        TURN { MOVE(opponent, MOVE_EMBER); }
    }
    SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_EXPLOSION);
        s32 maxHP = GetMonData(&OPPONENT_PARTY[0], MON_DATA_MAX_HP);
        s32 dmg = 0;
        switch (i) {
            case 0:
                dmg = (maxHP / 4) + 1;
                break;
            case 1:
                dmg = ((maxHP / 4) + 1) / 2;
                break;
            case 2:
                dmg = ((maxHP / 4) + 1) / 4;
                break;
            case 3:
                dmg = ((maxHP / 4) + 1) * 2;
                break;
            case 4:
                dmg = maxHP;
                break;
        }
        HP_BAR(opponent, damage : dmg);
    }
}

DOUBLE_BATTLE_TEST("Smoke explosion hits all targets in a double battle")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    }
    WHEN {
        TURN { MOVE(playerLeft, MOVE_SMOKE_BOMB); }
        TURN { MOVE(playerLeft, MOVE_EMBER, target:opponentRight); }
    }
    SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SMOKE_BOMB, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, playerLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_EXPLOSION);

        HP_BAR(playerLeft);
        HP_BAR(opponentLeft);
        HP_BAR(playerRight);
        HP_BAR(opponentRight);
    }
}


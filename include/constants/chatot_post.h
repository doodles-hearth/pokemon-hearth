#ifndef GUARD_CHATOT_POST_CONSTANTS_H
#define GUARD_CHATOT_POST_CONSTANTS_H

#define POST_NONE 0
#define POST_FROM_BIG_SIS 1
#define POST_NATSUKI_RARE_CANDY 2
#define POST_FROM_BIG_SIS_LEFTOVERS 3
// Must always be equal to the last mail value + 1
#define NUM_CHATOT_POST 4

#define POST_TRAINER_TEMPLATE (NUM_CHATOT_POST + 1)

// The maximum amount of mail that can be active at one time
#define NUM_ACTIVE_POST_SLOTS 3

#define NUM_SCRIPTS_PER_TRAINER_CLASS 2
#define NUM_BATTLE_ME_SCRIPTS_PER_TRAINER_CLASS 1

#endif // GUARD_CHATOT_POST_CONSTANTS_H
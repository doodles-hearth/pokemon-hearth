#ifndef FIELD_MOVES_DEFINES_H
#define FIELD_MOVES_DEFINES_H

enum FieldMoveType
{
    IS_FIELD_MOVE_CUT       = 1 << 0,   // 0x0001  Cut
    IS_FIELD_MOVE_SMASH     = 1 << 1,   // 0x0002  Rock Smash
    IS_FIELD_MOVE_SHAKE     = 1 << 2,   // 0x0004  Headbutt
    IS_FIELD_MOVE_PUSH      = 1 << 3,   // 0x0008  Strength
    IS_FIELD_MOVE_CLIMB     = 1 << 4,   // 0x0010  Rock Climb
    IS_FIELD_MOVE_SURF      = 1 << 5,   // 0x0020  Surf
    IS_FIELD_MOVE_WATERFALL = 1 << 6,   // 0x0040  Waterfall
    IS_FIELD_MOVE_DIVE      = 1 << 7,   // 0x0080  Dive
    IS_FIELD_MOVE_DIG       = 1 << 8,   // 0x0100  Access Underground - not implemented
    IS_FIELD_MOVE_SOAR      = 1 << 9,   // 0x0200  Eon Flute - needs linking
    IS_FIELD_MOVE_WHIRLPOOL = 1 << 10,  // 0x0400  Whilrpool - not implemented
    IS_FIELD_MOVE_FLASH     = 1 << 11,  // 0x0800  Flash
    IS_FIELD_MOVE_LAVA      = 1 << 12,  // 0x1000  Lava Plume - lava surfing, needs implementing
    IS_FIELD_MOVE_HP        = 1 << 13,  // 0x2000  Softboiled/Milk Drink - currently has no effect
    IS_FIELD_MOVE_JUMP      = 1 << 14,  // 0x4000  Jump up ledges - not implemented
    IS_FIELD_MOVE_FLY       = 1 << 15,  // 0x8000  Warp to known locations - currently has no effect
    IS_FIELD_MOVE_HACK      = 1 << 16,  // 0x10000  Charge Beam - open locked electronic doors, not implemented
    IS_FIELD_MOVE_DEFOG     = 1 << 17,  // 0x20000  Defog - not implemented
};

#endif

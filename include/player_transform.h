#ifndef GUARD_PLAYER_TRANSFORM_H
#define GUARD_PLAYER_TRANSFORM_H

#include "gba/gba.h"

struct PlayerTransformData // This stores the entire player transform data into a single u16
{
    u16 isPokemon : 1;
    u16 inBox : 1;
    u16 boxId : 4;    // 0–13 (14 Boxes)
    u16 slot : 5;     // 0–29 if in box, else 0–5 if party
    u16 padding : 5; // padding
};

extern struct Pokemon *gPlayerTransformPokemon;

bool32 isPlayerTransformed(void);
void BeginPlayerTransform(void);
void TransformPlayerToPokemon(void);
void TransformPlayerToDefault(void);
void UpdateTransformedPlayerPalette(struct ObjectEvent *playerObj);
void CB2_TransformPlayerFromParty(void);
u16 GetPlayerTransformGfxFromSaveblock();
u16 SpeciesToGraphicsId(struct Pokemon *pokemon);

#endif // GUARD_PLAYER_TRANSFORM_H
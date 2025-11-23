#ifndef GUARD_PLAYER_TRANSFORM_H
#define GUARD_PLAYER_TRANSFORM_H

#include "global.h"

extern struct Pokemon *gPlayerTransformPokemon;

bool32 IsPlayerTransformed(void);
void BeginPlayerTransform(void);
void TransformPlayerToPokemon(void);
void TransformPlayerToDefault(void);
void UpdateTransformedPlayerPalette(struct ObjectEvent *playerObj);
void CB2_TransformPlayerFromParty(void);
u16 GetPlayerTransformGfxFromSaveblock();
u16 SpeciesToGraphicsId(struct Pokemon *pokemon);

#endif // GUARD_PLAYER_TRANSFORM_H

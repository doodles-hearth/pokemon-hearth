#ifndef GUARD_PLAYER_TRANSFORM_H
#define GUARD_PLAYER_TRANSFORM_H

#include "global.h"

extern struct Pokemon *gPlayerTransformPokemon;

bool32 IsPlayerTransformed(void);
void BeginPlayerTransform(void);
void TransformPlayerToPokemon(void);
void TransformPlayerToDefault(void);
void Task_PokemonAvatar_HandleBob(u8 taskId);
void UpdateTransformedPlayerPalette(struct ObjectEvent *playerObj);
void CB2_TransformPlayerFromParty(void);
u16 GetPlayerTransformGfxFromSaveblock();
u16 SpeciesToGraphicsId(struct Pokemon *pokemon);
void Task_StartPokemonAvatarBob(u8 taskId);
void TryStartPokemonAvatarBob(void);

#endif // GUARD_PLAYER_TRANSFORM_H

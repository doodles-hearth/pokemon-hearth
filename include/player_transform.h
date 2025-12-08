#ifndef GUARD_PLAYER_TRANSFORM_H
#define GUARD_PLAYER_TRANSFORM_H

extern struct Pokemon *gPlayerTransformPokemon;

void GetCurrentPlayerTransformPokemon();
u16 PokemonToGraphicsId(struct Pokemon *pokemon);
void TransformPlayerToPokemon();
void TransformPlayerToHumasn();
void TransformPlayerToPokemonFromParty();
void CB2_TransformPlayerToPokemonFromParty();

#endif //GUARD_PLAYER_TRANSFORM_H

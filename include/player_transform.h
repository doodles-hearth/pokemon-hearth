#ifndef GUARD_PLAYER_TRANSFORM_H
#define GUARD_PLAYER_TRANSFORM_H

extern struct ScriptContext *ctx;
extern struct Pokemon *gPlayerTransformPokemon;
extern struct PlayerAvatarBobState gPlayerAvatarBobState;

struct PlayerAvatarBobState {
    u16 frameCounter;
    u16 spriteOffset;
};

struct Pokemon* GetCurrentlyTransformedPokemon();
u16 PokemonToGraphicsId(struct Pokemon *pokemon);
void TransformPlayerToPokemon();
void TransformPlayerToHumasn();
void TransformPlayer(struct ScriptContext *ctx);
void CB2_TransformPlayerToPokemonFromParty();
void PlayerAvatarHandleBob();

#endif //GUARD_PLAYER_TRANSFORM_H

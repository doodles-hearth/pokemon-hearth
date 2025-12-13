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
void TransformPlayerToHuman();
void TransformPlayerFromScriptByIndex(struct ScriptContext* ctx);
void TransformPlayer(struct ScriptContext *ctx);
void DetransformPlayer(struct ScriptContext *ctx);
void TransformPlayerFromParty();

void CB2_TransformPlayerToPokemonFromParty();
void PlayerAvatarHandleBob(void);
void PlayerAvatarForceIdleAnim(void);

#endif //GUARD_PLAYER_TRANSFORM_H

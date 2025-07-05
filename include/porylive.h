#ifndef GUARD_PORYLIVE_H
#define GUARD_PORYLIVE_H

#if PORYLIVE
#include "global.h"
#define PORYLIVE_SCRIPT_BUFFER_SIZE 102400 // 100kb buffer
#define PORYLIVE_MAX_OVERRIDES 200

struct PoryLiveOverride
{
  const u8* key;
  const u8* scriptPtr;
};

// porylive vars
extern volatile const u8 gPoryLiveScriptBuffer[PORYLIVE_SCRIPT_BUFFER_SIZE]; // Contains actual script data
extern volatile struct PoryLiveOverride gPoryLiveOverrides[PORYLIVE_MAX_OVERRIDES]; // Contains pointers to the overrides
extern volatile bool32 gPoryLiveScriptInitialized; // Whether the Lua script has been initialized

const u8* PoryLive_GetScriptPointer(const u8* key);
#endif // PORYLIVE

#endif // GUARD_PORYLIVE_H

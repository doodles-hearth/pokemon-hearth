#include "porylive.h"

#if PORYLIVE
__attribute__((used)) volatile const u8 gPoryLiveScriptBuffer[PORYLIVE_SCRIPT_BUFFER_SIZE] = {0}; // Passed from Lua to memory
EWRAM_DATA volatile struct PoryLiveOverride gPoryLiveOverrides[PORYLIVE_MAX_OVERRIDES] = {0}; // Contains pointers to the overrides
EWRAM_DATA volatile bool32 gPoryLiveScriptInitialized = FALSE; // Whether the Lua script has been initialized

/**
 * @brief Get the script pointer for the current script.
 * If an override is found, return the override pointer, otherwise return the original pointer.
 * 
 * @param key The original address to the script
 * @return const u8*
 */
const u8* PoryLive_GetScriptPointer(const u8* key)
{
  if (!gPoryLiveScriptInitialized) {
    return key;
  }

  for (u32 i = 0; i < PORYLIVE_MAX_OVERRIDES; i++) {
    // Check if the pointer addresses match
    if (gPoryLiveOverrides[i].key == key) {
      return gPoryLiveOverrides[i].scriptPtr;
    }
  }
  return key; // Use the original pointer if no override is found
}

// Prevents gPoryLiveScriptBuffer from being optimized out
static inline void __attribute__((used)) PoryLive_PreventOptimization(void)
{
  (void)gPoryLiveScriptBuffer[0]; // Dummy reference
}

#endif // PORYLIVE

#ifndef GUARD_POKEMON_MEMORIES_H
#define GUARD_POKEMON_MEMORIES_H

void SetMemoryWithRules(struct Pokemon *slot, u8 memory);
void SetMemoryAllWithRules(u8 memory);
void ResolveMemoriesAfterTrade(u8 partyIdx);
void StartMemoryGirlReading(void);
u16 NextMemoryGirlReading(void);

#endif // GUARD_POKEMON_MEMORIES_H

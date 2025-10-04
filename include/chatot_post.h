#ifndef GUARD_CHATOT_POST_H
#define GUARD_CHATOT_POST_H

#define INITIAL_POST_CHANCE 2 //%
#define POST_CHANCE_INCREMENT 2 //%

enum ChatotPostTypes
{
    POST_TYPE_NONE, // Default
    POST_TYPE_IMMEDIATE, // Post appears as soon as its condition is true
    POST_TYPE_RANDOM, // Post can appear at random once its condition is true
};

extern const u8 gText_ChatotPostSender_BigSis[];
extern const u8 gText_ChatotPostSender_Hariko[];
extern const u8 gText_ChatotPostSender_Natsuki[];
extern const u8 gText_ChatotPostSender_Okada[];
extern const u8 gText_ChatotPostSender_Kaba[];

struct ChatotPost
{
    const u8 *script;
    u8 importance;
    u8 condition;
    enum ChatotPostTypes type;
    const u8 *senderName;
};

extern const struct ChatotPost gChatotPost[];

void SpawnPostChatot(void);
void ClearPostChatot(void);
bool8 PlayerHasChatotPost(void);
bool8 ChatotIsOnPerch(void);
void SetChatotPostFlag(u8 postId);
bool8 CheckChatotPostFlag(u8 postId);
bool8 SetChatotPostActive(u8 postId);
void ClearFirstPostSlotAndCompressPostQueue(void);
void ResetChatotPost(void);
bool32 TryGetChatotPost(void);

#endif // GUARD_CHATOT_POST_H
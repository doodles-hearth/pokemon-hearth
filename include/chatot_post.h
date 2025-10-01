#ifndef GUARD_CHATOT_POST_H
#define GUARD_CHATOT_POST_H

enum ChatotPostTypes
{
    POST_TYPE_NONE, // Default
    POST_TYPE_IMMEDIATE, // Post appears as soon as its condition is true
    POST_TYPE_RANDOM, // Post can appear at random once its condition is true
};

struct ChatotPost
{
    const u8 *script;
    u8 importance;
    u8 condition;
    enum ChatotPostTypes type;
};

extern const struct ChatotPost gChatotPost[];

void SpawnPostChatot(void);
void ClearPostChatot(void);
bool8 PlayerHasChatotPost(void);
void SetChatotPostFlag(u8 postId);
bool8 CheckChatotPostFlag(u8 postId);
bool8 SetChatotPostActive(u8 postId);
void ResetChatotPost(void);

#endif // GUARD_CHATOT_POST_H
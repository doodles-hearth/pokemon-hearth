#ifndef GUARD_CHATOT_POST_H
#define GUARD_CHATOT_POST_H

struct ChatotPost
{
    const u8 *postMessage;
    u8 importance;
};

extern const struct ChatotPost gChatotPost[];

void SpawnPostChatot(void);
bool8 PlayerHasChatotPost(void);
void SetChatotPostFlag(u8 postId);
bool8 CheckChatotPostFlag(u8 postId);
bool8 SetChatotPostActive(u8 postId);
void ResetChatotPost(void);

#endif // GUARD_CHATOT_POST_H
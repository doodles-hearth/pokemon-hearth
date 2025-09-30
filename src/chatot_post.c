#include "global.h"
#include "chatot_post.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "sprite.h"
#include "constants/chatot_post.h"
#include "constants/event_objects.h"
#include "constants/flags.h"
#include "constants/global.h"

#include "data/chatot_post.h"

// Makes Chatot appear
void SpawnPostChatot(void)
{
    FlagClear(FLAG_POST_CHATOT);
}

// Checks if the player has any post
bool8 PlayerHasChatotPost(void)
{
    for (u8 i = 0; i < NUM_ACTIVE_POST_SLOTS; i++)
    {
        if (gSaveBlock1Ptr->activePost[i])
            return TRUE;
    }
    return FALSE;
}

// Get the u8 associated with the post flag
static u8 *GetChatotPostFlagPointer(u8 postId)
{
    if (postId < NUM_CHATOT_POST)
        return &gSaveBlock1Ptr->postFlags[postId / 8];
    else
        return NULL;
}

// Sets the flag so the post can't come up again
void SetChatotPostFlag(u8 postId)
{
    if (postId == 0)
        return;
    u8 *ptr = GetChatotPostFlagPointer(postId);
    if (!ptr)
        return;
    if (ptr)
        *ptr |= 1 << (postId & 7);
}

// Checks if the flag is set to prevent post coming up again
bool8 CheckChatotPostFlag(u8 postId)
{
    if (postId == 0)
        return FALSE;
    u8 *ptr = GetChatotPostFlagPointer(postId);
    if (!ptr)
        return FALSE;
    if (!(((*ptr) >> (postId & 7)) & 1))
        return FALSE;
    return TRUE;
}

// Puts the post at the back of the mail queue, replacing less important mail if necessary
bool8 SetChatotPostActive(u8 postId)
{
    u8 i;
    for (i = 0; i < NUM_ACTIVE_POST_SLOTS; i++)
    {
        if (!gSaveBlock1Ptr->activePost[i])
        {
            gSaveBlock1Ptr->activePost[i] = postId;
            return TRUE;
        }
    }

    for (i = NUM_ACTIVE_POST_SLOTS; i > 0; i--)
    {
        u8 storedMail = gSaveBlock1Ptr->activePost[i-1];
        if (gChatotPost[postId].importance > gChatotPost[storedMail].importance)
        {
            gSaveBlock1Ptr->activePost[i-1] = postId;
            return TRUE;
        }
    }
    return FALSE;
}

// Resets all saveblock elements for a new game
void ResetChatotPost(void)
{
    memset(gSaveBlock1Ptr->postFlags, 0, sizeof(gSaveBlock1Ptr->postFlags));
    memset(gSaveBlock1Ptr->activePost, 0, sizeof(gSaveBlock1Ptr->activePost));
}
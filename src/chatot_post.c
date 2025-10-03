#include "global.h"
#include "chatot_post.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "field_player_avatar.h"
#include "fldeff.h"
#include "random.h"
#include "script.h"
#include "sprite.h"
#include "task.h"
#include "constants/chatot_post.h"
#include "constants/event_objects.h"
#include "constants/flags.h"
#include "constants/global.h"

#include "data/chatot_post.h"

// Starts the post
void InitialisePost(void)
{
    gSaveBlock1Ptr->postChance = INITIAL_POST_CHANCE;
}

// Makes Chatot appear
void SpawnPostChatot(void)
{
    FlagClear(FLAG_POST_CHATOT);
}

// Makes Chatot disappear
void ClearPostChatot(void)
{
    FlagSet(FLAG_POST_CHATOT);
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

// Checks if the Chatot obj event is on the perch
// (this avoids the post script to trigger even though Chatot hasn't been spawned)
bool8 ChatotIsOnPerch(void)
{
    return !FlagGet(FLAG_POST_CHATOT);
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
        u8 storedPost = gSaveBlock1Ptr->activePost[i-1];
        if (gChatotPost[postId].importance > gChatotPost[storedPost].importance)
        {
            gSaveBlock1Ptr->activePost[i-1] = postId;
            return TRUE;
        }
    }
    return FALSE;
}

static void CompressPostQueue(void)
{
    for (u8 i = 1; i < NUM_ACTIVE_POST_SLOTS; i++)
    {
        u8 postToMove = gSaveBlock1Ptr->activePost[i];
        if (postToMove)
        {
            gSaveBlock1Ptr->activePost[i] = POST_NONE;
            gSaveBlock1Ptr->activePost[i-1] = postToMove;
        }
    }
}

void ClearFirstPostSlotAndCompressPostQueue(void)
{
    gSaveBlock1Ptr->activePost[0] = POST_NONE;
    CompressPostQueue();
}

static void Task_TryFindAndActivatePost(u8 taskId)
{
    const u8 postCount = ARRAY_COUNT(gChatotPost);
    if (postCount == 0)
        return;

    // Build an index array
    u8 indices[postCount];
    for (u8 i = 0; i < postCount; ++i)
        indices[i] = i;
    Shuffle(indices, postCount, sizeof(indices[0]));

    // Iterate shuffled order, pick immediate if found, else first eligible random
    u8 storedIndex = 0; // index into gChatotPost for first eligible random-type post
    for (u8 j = 0; j < postCount; ++j)
    {
        u8 postIdx = indices[j];
        const struct ChatotPost *post = &gChatotPost[postIdx];

        // Skip none-type posts for now & skip the null value post
        if (post->type == POST_TYPE_NONE || postIdx == 0)
            continue;

        bool8 alreadyUsed = CheckChatotPostFlag(postIdx);
        if (alreadyUsed)
            continue;

        bool8 condSatisfied = (post->condition == 0) ? TRUE : FlagGet(post->condition);
        if (!condSatisfied)
            continue;

        if (post->type == POST_TYPE_IMMEDIATE)
        {
            // Guaranteed - activate immediately and return.
            SetChatotPostActive(postIdx);
            return;
        }

        // For random-type posts, store the first eligible one (so we can pick it if
        // we don't find any immediate/guaranteed ones)
        if (post->type == POST_TYPE_RANDOM && storedIndex == 0)
            storedIndex = postIdx;
    }

    // If no immediate was found, but we stored an eligible random, try activate it
    if (storedIndex != 0)
    {
        gSaveBlock1Ptr->postStepCounter = 0;
        if (gSaveBlock1Ptr->postChance > (Random() % 100))
        {
            SetChatotPostActive(storedIndex);
            gSaveBlock1Ptr->postChance = INITIAL_POST_CHANCE;
        }
        else
        {
            gSaveBlock1Ptr->postChance += POST_CHANCE_INCREMENT;
        }
    }

    return;
}

bool8 TrySetRandomPostActive(void)
{
    // Do nothing if postChance is not initialised yet
    if ((gSaveBlock1Ptr->postChance = 0))
        return FALSE;

    // Has an increasing chance of succeeding every 255 steps
    gSaveBlock1Ptr->postStepCounter++;
    if (gSaveBlock1Ptr->postStepCounter >= 255)
    {
        CreateTask(Task_TryFindAndActivatePost, 9);
        return TRUE;
    }
    return FALSE;
}

void Debug_PutPostFromHaruInQueue(void)
{
    SetChatotPostActive(POST_FROM_HARU);
}

bool8 Native_SetChatotLastSpeaker(struct ScriptContext *ctx)
{
    u8 objEventId;

    GetXYCoordsTwoStepsInFrontOfPlayer(&gPlayerFacingPosition.x, &gPlayerFacingPosition.y);
    objEventId = GetObjectEventIdByPosition(gPlayerFacingPosition.x, gPlayerFacingPosition.y, 0);
    if (gObjectEvents[objEventId].graphicsId != OBJ_EVENT_GFX_SPECIES(CHATOT))
    {
        return FALSE;
    }
    else
    {
        gSpecialVar_LastTalked = gObjectEvents[objEventId].localId;
        return TRUE;
    }
}

bool8 Native_CheckChatotPost(struct ScriptContext *ctx)
{
    Script_RequestEffects(SCREFF_V1);
    gSpecialVar_Result = FALSE;

    if (gSaveBlock1Ptr->activePost[0])
        gSpecialVar_Result = TRUE;
    return FALSE;
}

bool8 Native_CheckChatotPostNumber(struct ScriptContext *ctx)
{
    Script_RequestEffects(SCREFF_V1);

    gSpecialVar_Result = 0;

    u32 i = 0;
    while (i < NUM_ACTIVE_POST_SLOTS)
    {
        if (gSaveBlock1Ptr->activePost[i])
            gSpecialVar_Result += 1;

        i += 1;
    }

    return FALSE;
}

bool8 Native_ReadChatotPost(struct ScriptContext *ctx)
{
    Script_RequestEffects(SCREFF_V1);
    const u8 *script = ChatotPost_EventScript_None;
    
    u8 storedPost = gSaveBlock1Ptr->activePost[0];
    if (storedPost)
        script = gChatotPost[storedPost].script;

    SetChatotPostFlag(storedPost);
    ClearFirstPostSlotAndCompressPostQueue();
    ScriptCall(ctx, script);
    return FALSE;
}

// Resets all saveblock elements for a new game
void ResetChatotPost(void)
{
    gSaveBlock1Ptr->postChance = 0;
    gSaveBlock1Ptr->postStepCounter = 0;
    memset(gSaveBlock1Ptr->postFlags, 0, sizeof(gSaveBlock1Ptr->postFlags));
    memset(gSaveBlock1Ptr->activePost, 0, sizeof(gSaveBlock1Ptr->activePost));
}
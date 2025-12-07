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
#include "string_util.h"
#include "match_call.h"
#include "data.h"

const u8 gText_ChatotPostSender_BigSis[] = _("Big Sister");
const u8 gText_ChatotPostSender_Hariko[] = _("Hariko");
const u8 gText_ChatotPostSender_Natsuki[] = _("Natsuki");
const u8 gText_ChatotPostSender_Okada[] = _("Okada");
const u8 gText_ChatotPostSender_Kaba[] = _("Elder Kaba");
const u8 gText_ChatotPostSender_Anon[] = _("Anonymous");

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
        u8 storedPost = gSaveBlock1Ptr->activePost[i - 1];
        if (postId != POST_TRAINER_TEMPLATE && gChatotPost[postId].importance > gChatotPost[storedPost].importance)
        {
            gSaveBlock1Ptr->activePost[i - 1] = postId;
            return TRUE;
        }
    }
    return FALSE;
}

// Checks if the post is already in the queue
bool8 IsPostInQueue(u8 postId)
{
    u32 i;
    for (i = 0; i < NUM_ACTIVE_POST_SLOTS; i++)
    {
        if (gSaveBlock1Ptr->activePost[i] == postId)
        {
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
            gSaveBlock1Ptr->activePost[i - 1] = postToMove;
        }
    }
}

void ClearFirstPostSlotAndCompressPostQueue(void)
{
    gSaveBlock1Ptr->activePost[0] = POST_NONE;
    CompressPostQueue();
}

bool32 TryGetRandomTrainerPost()
{
    u32 trainerId = SelectMatchCallTrainerId();
    if (trainerId != 0)
    {
        SetChatotPostActive(POST_TRAINER_TEMPLATE);
        gSaveBlock1Ptr->chatotPostRematchTrainerId = trainerId;

        return TRUE;
    }

    return FALSE;
}

bool32 TryGetNonTrainerPost(u32 postType)
{
    // DebugPrintf("TryGetNonTrainerPost");
    const u8 postCount = ARRAY_COUNT(gChatotPost);
    if (postCount == 0)
        return FALSE;

    // Build an index array
    u8 indices[postCount];
    for (u8 i = 0; i < postCount; ++i)
        indices[i] = i;
    Shuffle(indices, postCount, sizeof(indices[0]));

    // DebugPrintf("Looping %dx", postCount);
    for (u8 j = 0; j < postCount; ++j)
    {
        // DebugPrintf("  %d", j);
        u8 postIdx = indices[j];
        const struct ChatotPost *post = &gChatotPost[postIdx];

        // Skip none-type posts for now & skip the null value post
        if (post->type == POST_TYPE_NONE || postIdx == 0)
        {
            // DebugPrintf("  Skipping post NONE");
            continue;
        }

        // Already read msg
        if (CheckChatotPostFlag(postIdx))
        {
            // DebugPrintf("  Skipping already used");
            continue;
        }

        bool8 condSatisfied = (post->condition == 0) ? TRUE : FlagGet(post->condition);
        // DebugPrintf("  Cond satisfied? %d", condSatisfied);
        if (!condSatisfied)
            continue;

        if (postType == post->type && !IsPostInQueue(postIdx))
        {
            // DebugPrintf("   Post idx %d is active", postIdx);
            SetChatotPostActive(postIdx);
            return TRUE;
        }
    }

    return FALSE;
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
    
    u32 activePostId = gSaveBlock1Ptr->activePost[0];

    if (activePostId)
    {
        gSpecialVar_Result = TRUE;

        if (activePostId == POST_TRAINER_TEMPLATE)
        {
            u16 trainerId = gSaveBlock1Ptr->chatotPostRematchTrainerId;
            // DebugPrintf("SENDER=%S", GetTrainerNameFromId(trainerId));
            StringCopy(gStringVar1, GetTrainerClassNameFromId(trainerId));
            StringAppend(gStringVar1, COMPOUND_STRING(" "));
            StringAppend(gStringVar1, GetTrainerNameFromId(trainerId));
        }
        else
        {
            // DebugPrintf("SENDER=%S", gChatotPost[activePostId].senderName);
            StringCopy(gStringVar1, gChatotPost[activePostId].senderName);
        }
    }

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
        {
            gSpecialVar_Result += 1;
        }
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
    {
        if (storedPost == POST_TRAINER_TEMPLATE)
        {
            /* // DebugPrintf("  trainer"); */
            SelectMatchCallMessage(gSaveBlock1Ptr->chatotPostRematchTrainerId, gStringVar4);
            /* // DebugPrintf("  msg selected"); */
            script = ChatotPost_EventScript_TrainerMessage;
            /* // DebugPrintf("  script selected"); */
            gSaveBlock1Ptr->chatotPostRematchTrainerId = 0;
        }
        else
        {
            // DebugPrintf("  non trainer");
            script = gChatotPost[storedPost].script;
        }
    }
    
    // DebugPrintf("flag=%d", CheckChatotPostFlag(storedPost));
    SetChatotPostFlag(storedPost);
    // DebugPrintf("flag=%d", CheckChatotPostFlag(storedPost));
    ClearFirstPostSlotAndCompressPostQueue();
    ScriptCall(ctx, script);
    return FALSE;
}

bool8 Native_TrySetChatotPostActive(struct ScriptContext *ctx)
{
    Script_RequestEffects(SCREFF_V1);
    
    u32 idPost = ScriptReadHalfword(ctx);

    if (!IsPostInQueue(idPost) && !CheckChatotPostFlag(idPost)) {
        SetChatotPostActive(idPost);
    }

    return FALSE;
}

bool8 Native_ResetChatotPost(struct ScriptContext *ctx) {
    Script_RequestEffects(SCREFF_V1);
    
    memset(gSaveBlock1Ptr->postFlags, 0, sizeof(gSaveBlock1Ptr->postFlags));
    memset(gSaveBlock1Ptr->activePost, 0, sizeof(gSaveBlock1Ptr->activePost));

    return FALSE;
}

// Resets all saveblock elements for a new game
void ResetChatotPost(void)
{
    memset(gSaveBlock1Ptr->postFlags, 0, sizeof(gSaveBlock1Ptr->postFlags));
    memset(gSaveBlock1Ptr->activePost, 0, sizeof(gSaveBlock1Ptr->activePost));
}

/*
    One message can be added to the queue
    - Every 10th step
    - Every 10 minutes
    - 1/3 of the time
    Immediate messages
*/
bool32 TryGetChatotPost(void)
{
    if (UpdateMatchCallStepCounter() && UpdateMatchCallMinutesCounter())
    {
        // DebugPrintf("I'm in");
        if (TryGetNonTrainerPost(POST_TYPE_IMMEDIATE))
        {
            // DebugPrintf("Immediate NPC");
            return TRUE;
        }
        else
        {
            if (CheckMatchCallChance()) 
            {
                if (gSaveBlock1Ptr->chatotPostRematchTrainerId == 0 && Random() % 2 != 0)
                {
                    // DebugPrintf("Random trainer");
                    return TryGetRandomTrainerPost();
                }
                else
                {
                    // DebugPrintf("Random NPC");
                    return TryGetNonTrainerPost(POST_TYPE_RANDOM);
                }
            }
        }
    }

    return FALSE;
}

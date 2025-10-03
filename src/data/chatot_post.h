extern const u8 ChatotPost_EventScript_None[];
extern const u8 ChatotPost_EventScript_FromHariko[];

const struct ChatotPost gChatotPost[] =
{
    [POST_NONE] =
    {
        // Do not remove
        .script = ChatotPost_EventScript_None, // Script to be executed for the post
        .importance = 2, // Higher importance post can overwrite lower importance post if queue is full
        .condition = 0, // The flag required to be true for post to be able to appear, if no condition, can appear immediately
        .type = POST_TYPE_NONE, // Determines how the post appears, for more info search "ChatotPostTypes"
    },
    [POST_FROM_HARIKO] =
    {
        .script = ChatotPost_EventScript_FromHariko,
        .importance = 0,
        .type = POST_TYPE_RANDOM,
        .senderName = gText_ChatotPostSender_Hariko,
    },
};
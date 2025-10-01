extern const u8 ChatotPost_EventScript_None[];
extern const u8 ChatotPost_EventScript_FromHaru[];

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
    [POST_FROM_HARU] =
    {
        .script = ChatotPost_EventScript_FromHaru,
        .importance = 0,
    },
};
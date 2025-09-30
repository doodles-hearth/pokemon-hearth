const u8 gPostNoneMessage[] = _("Example post used as Null value");
const u8 gPostFromHaru[] = _("Hello!");

const struct ChatotPost gChatotPost[] =
{
    [POST_NONE] =
    {
        // Do not remove
        .postMessage = gPostNoneMessage,
        .importance = 1,
    },
    [POST_FROM_HARU] =
    {
        .postMessage = gPostFromHaru,
        .importance = 0,
    },
};
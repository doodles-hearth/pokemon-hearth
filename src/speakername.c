#include "global.h"
#include "script.h"
#include "field_message_box.h"
#include "field_specials.h"
#include "constants/speakername.h"
#include "data/speakername.h"

void SetSpeakerNameById(const u32 id)
{
    SetSpeakerName(sSpeakerNames[id]);
}

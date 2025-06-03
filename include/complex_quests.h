#ifndef GUARD_COMPLEX_QUESTS_H
#define GUARD_COMPLEX_QUESTS_H

#include "global.h"
#include "strings.h"
#include "bg.h"
#include "data.h"
#include "decompress.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "item.h"
#include "item_icon.h"
#include "item_menu.h"
#include "item_menu_icons.h"
#include "list_menu.h"
#include "item_use.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "palette.h"
#include "party_menu.h"
#include "scanline_effect.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text_window.h"
#include "quests.h"
#include "overworld.h"
#include "event_data.h"
#include "constants/items.h"
#include "constants/field_weather.h"
#include "constants/songs.h"
#include "constants/rgb.h"
#include "constants/event_objects.h"
#include "event_object_movement.h"
#include "pokemon_icon.h"

////////////////////////////////////////
///////////BEGIN QUEST ARRAYS///////////

//Main Campaign Arrays
const u8 *const gTable_MainCampaignDescs[3] = {
    COMPOUND_STRING("Go see Elder Kaba and become\n a Pokémon wielder!"),
    COMPOUND_STRING("Deliver Elder Kaba's letter to\n Elder Iwa in Silveridge!"),
    COMPOUND_STRING("Filler desc"),
};

const u8 *const gTable_MainCampaignMaps[3] = {
    COMPOUND_STRING("Elder Kaba's House"),
    COMPOUND_STRING("Silveridge"),
    COMPOUND_STRING("Uume Forest"),
};

static const u16 MainCampaignSprites[3]={
	OBJ_EVENT_GFX_KABA,
    OBJ_EVENT_GFX_ELDER2,
	OBJ_EVENT_GFX_NATSUKI,
};

static const u8 MainCampaignSpriteTypes[3]={
	OBJECT,
	OBJECT,
	OBJECT,
};

////////////END QUEST ARRAYS////////////
////////////////////////////////////////

#endif
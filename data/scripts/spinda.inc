Spinda_SpinClockwise::
# 3 "data/scripts/spinda.pory"
	goto_if_set FLAG_TOOK_SPINDA, Spinda_SpinClockwise_1
	return

Spinda_SpinClockwise_1:
# 4 "data/scripts/spinda.pory"
	setwarpnextmapclockwise
	return


Spinda_SpinCounterclockwise::
# 9 "data/scripts/spinda.pory"
	goto_if_set FLAG_TOOK_SPINDA, Spinda_SpinCounterclockwise_1
	return

Spinda_SpinCounterclockwise_1:
# 10 "data/scripts/spinda.pory"
	setwarpnextmapcounterclockwise
	return


Spinda_TurnPlayerClockwise::
# 15 "data/scripts/spinda.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 16 "data/scripts/spinda.pory"
	switch VAR_RESULT
# 17 "data/scripts/spinda.pory"
	case DIR_SOUTH, Spinda_TurnPlayerClockwise_2
# 19 "data/scripts/spinda.pory"
	case DIR_WEST, Spinda_TurnPlayerClockwise_3
# 21 "data/scripts/spinda.pory"
	case DIR_NORTH, Spinda_TurnPlayerClockwise_4
# 23 "data/scripts/spinda.pory"
	case DIR_EAST, Spinda_TurnPlayerClockwise_5
	return

Spinda_TurnPlayerClockwise_2:
# 18 "data/scripts/spinda.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	return

Spinda_TurnPlayerClockwise_3:
# 20 "data/scripts/spinda.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	return

Spinda_TurnPlayerClockwise_4:
# 22 "data/scripts/spinda.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	return

Spinda_TurnPlayerClockwise_5:
# 24 "data/scripts/spinda.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	return


Spinda_TurnPlayerCounterclockwise::
# 29 "data/scripts/spinda.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 30 "data/scripts/spinda.pory"
	switch VAR_RESULT
# 31 "data/scripts/spinda.pory"
	case DIR_SOUTH, Spinda_TurnPlayerCounterclockwise_2
# 33 "data/scripts/spinda.pory"
	case DIR_EAST, Spinda_TurnPlayerCounterclockwise_3
# 35 "data/scripts/spinda.pory"
	case DIR_NORTH, Spinda_TurnPlayerCounterclockwise_4
# 37 "data/scripts/spinda.pory"
	case DIR_WEST, Spinda_TurnPlayerCounterclockwise_5
	return

Spinda_TurnPlayerCounterclockwise_2:
# 32 "data/scripts/spinda.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	return

Spinda_TurnPlayerCounterclockwise_3:
# 34 "data/scripts/spinda.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	return

Spinda_TurnPlayerCounterclockwise_4:
# 36 "data/scripts/spinda.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	return

Spinda_TurnPlayerCounterclockwise_5:
# 38 "data/scripts/spinda.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	return


SpindaIsland_Common_CantReadSign::
# 44 "data/scripts/spinda.pory"
	lock
# 46 "data/scripts/spinda.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 47 "data/scripts/spinda.pory"
	speakername SpindaIsland_Common_CantReadSign_Text_0
# 48 "data/scripts/spinda.pory"
	msgbox SpindaIsland_Common_CantReadSign_Text_1
# 51 "data/scripts/spinda.pory"
	closemessage
# 52 "data/scripts/spinda.pory"
	removefieldmugshot
# 54 "data/scripts/spinda.pory"
	release
	return


SpindaIsland_Common_CantTakeStairs::
# 58 "data/scripts/spinda.pory"
	lock
# 60 "data/scripts/spinda.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 61 "data/scripts/spinda.pory"
	speakername SpindaIsland_Common_CantReadSign_Text_0
# 62 "data/scripts/spinda.pory"
	msgbox SpindaIsland_Common_CantTakeStairs_Text_0
# 65 "data/scripts/spinda.pory"
	closemessage
# 66 "data/scripts/spinda.pory"
	removefieldmugshot
# 68 "data/scripts/spinda.pory"
	speakername SpindaIsland_Common_CantTakeStairs_Text_1
# 69 "data/scripts/spinda.pory"
	msgbox SpindaIsland_Common_CantTakeStairs_Text_2
# 73 "data/scripts/spinda.pory"
	closemessage
# 74 "data/scripts/spinda.pory"
	release
	return


SpindaIsland_Common_EmptyChest::
# 78 "data/scripts/spinda.pory"
	lock
# 80 "data/scripts/spinda.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 81 "data/scripts/spinda.pory"
	speakername SpindaIsland_Common_CantReadSign_Text_0
# 82 "data/scripts/spinda.pory"
	msgbox SpindaIsland_Common_EmptyChest_Text_0
# 85 "data/scripts/spinda.pory"
	closemessage
# 86 "data/scripts/spinda.pory"
	removefieldmugshot
# 87 "data/scripts/spinda.pory"
	release
	return


SpindaIsland_Common_RegularSeashell::
# 91 "data/scripts/spinda.pory"
	lock
# 93 "data/scripts/spinda.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 94 "data/scripts/spinda.pory"
	speakername SpindaIsland_Common_CantReadSign_Text_0
# 95 "data/scripts/spinda.pory"
	msgbox SpindaIsland_Common_RegularSeashell_Text_0
# 98 "data/scripts/spinda.pory"
	closemessage
# 99 "data/scripts/spinda.pory"
	removefieldmugshot
# 100 "data/scripts/spinda.pory"
	release
	return


SpindaIsland_Common_HiddenItem::
# 104 "data/scripts/spinda.pory"
	lock
# 106 "data/scripts/spinda.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 107 "data/scripts/spinda.pory"
	speakername SpindaIsland_Common_CantReadSign_Text_0
# 108 "data/scripts/spinda.pory"
	msgbox SpindaIsland_Common_HiddenItem_Text_0
# 111 "data/scripts/spinda.pory"
	closemessage
# 112 "data/scripts/spinda.pory"
	removefieldmugshot
# 114 "data/scripts/spinda.pory"
	release
	return


SpindaIsland_Common_HiddenObstacle::
# 118 "data/scripts/spinda.pory"
	lock
# 120 "data/scripts/spinda.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 121 "data/scripts/spinda.pory"
	speakername SpindaIsland_Common_CantReadSign_Text_0
# 122 "data/scripts/spinda.pory"
	msgbox SpindaIsland_Common_HiddenObstacle_Text_0
# 125 "data/scripts/spinda.pory"
	closemessage
# 126 "data/scripts/spinda.pory"
	removefieldmugshot
# 128 "data/scripts/spinda.pory"
	release
	return


SpindaIsland_Common_CantOpenFromThisSide::
# 132 "data/scripts/spinda.pory"
	lock
# 134 "data/scripts/spinda.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 135 "data/scripts/spinda.pory"
	speakername SpindaIsland_Common_CantReadSign_Text_0
# 136 "data/scripts/spinda.pory"
	msgbox SpindaIsland_Common_CantOpenFromThisSide_Text_0
# 139 "data/scripts/spinda.pory"
	closemessage
# 140 "data/scripts/spinda.pory"
	removefieldmugshot
# 142 "data/scripts/spinda.pory"
	release
	return


SpindaIsland_Common_CantSeeFromSide::
# 146 "data/scripts/spinda.pory"
	lock
# 148 "data/scripts/spinda.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 149 "data/scripts/spinda.pory"
	speakername SpindaIsland_Common_CantReadSign_Text_0
# 150 "data/scripts/spinda.pory"
	msgbox SpindaIsland_Common_CantSeeFromSide_Text_0
# 153 "data/scripts/spinda.pory"
	closemessage
# 154 "data/scripts/spinda.pory"
	removefieldmugshot
# 156 "data/scripts/spinda.pory"
	release
	return


SpindaIsland_Common_CantUseFromSide::
# 160 "data/scripts/spinda.pory"
	lock
# 162 "data/scripts/spinda.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 163 "data/scripts/spinda.pory"
	speakername SpindaIsland_Common_CantReadSign_Text_0
# 164 "data/scripts/spinda.pory"
	msgbox SpindaIsland_Common_CantUseFromSide_Text_0
# 167 "data/scripts/spinda.pory"
	closemessage
# 168 "data/scripts/spinda.pory"
	removefieldmugshot
# 170 "data/scripts/spinda.pory"
	release
	return


SpindaIsland_Common_CantEnterFromSide::
# 174 "data/scripts/spinda.pory"
	lock
# 176 "data/scripts/spinda.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 177 "data/scripts/spinda.pory"
	speakername SpindaIsland_Common_CantReadSign_Text_0
# 178 "data/scripts/spinda.pory"
	msgbox SpindaIsland_Common_CantEnterFromSide_Text_0
# 181 "data/scripts/spinda.pory"
	closemessage
# 182 "data/scripts/spinda.pory"
	removefieldmugshot
# 184 "data/scripts/spinda.pory"
	release
	return


SpindaIsland_Common_UseToyCamera::
# 188 "data/scripts/spinda.pory"
	lock
# 190 "data/scripts/spinda.pory"
	playse SE_SWITCH
# 191 "data/scripts/spinda.pory"
	waitse
# 192 "data/scripts/spinda.pory"
	playse SE_M_LEER
# 193 "data/scripts/spinda.pory"
	fadescreenspeed FADE_TO_WHITE, 0
# 194 "data/scripts/spinda.pory"
	fadescreenspeed FADE_FROM_WHITE, 0
# 195 "data/scripts/spinda.pory"
	waitse
# 197 "data/scripts/spinda.pory"
	release
	return


SpindaIsland_Common_CheckGotAllItemsForNewFaucet::
# 201 "data/scripts/spinda.pory"
	goto_if_set FLAG_FAUCET_QUEST_STARTED, SpindaIsland_Common_CheckGotAllItemsForNewFaucet_3
	return

SpindaIsland_Common_CheckGotAllItemsForNewFaucet_1:
# 202 "data/scripts/spinda.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 203 "data/scripts/spinda.pory"
	speakername SpindaIsland_Common_CantReadSign_Text_0
# 204 "data/scripts/spinda.pory"
	msgbox SpindaIsland_Common_CheckGotAllItemsForNewFaucet_Text_0
# 208 "data/scripts/spinda.pory"
	closemessage
# 209 "data/scripts/spinda.pory"
	removefieldmugshot
	return

SpindaIsland_Common_CheckGotAllItemsForNewFaucet_2:
	checkitem ITEM_PRECIOUS_BOLT
# 0 "data/scripts/spinda.pory"
	compare VAR_RESULT, 0
	goto_if_ne SpindaIsland_Common_CheckGotAllItemsForNewFaucet_7
	return

SpindaIsland_Common_CheckGotAllItemsForNewFaucet_3:
	checkitem ITEM_TOUGH_BOLT
# 0 "data/scripts/spinda.pory"
	compare VAR_RESULT, 0
	goto_if_ne SpindaIsland_Common_CheckGotAllItemsForNewFaucet_2
	return

SpindaIsland_Common_CheckGotAllItemsForNewFaucet_6:
	checkitem ITEM_BORROWED_PLIERS
# 0 "data/scripts/spinda.pory"
	compare VAR_RESULT, 0
	goto_if_ne SpindaIsland_Common_CheckGotAllItemsForNewFaucet_11
	return

SpindaIsland_Common_CheckGotAllItemsForNewFaucet_7:
	checkitem ITEM_RUSTY_BOLT
# 0 "data/scripts/spinda.pory"
	compare VAR_RESULT, 0
	goto_if_ne SpindaIsland_Common_CheckGotAllItemsForNewFaucet_6
	return

SpindaIsland_Common_CheckGotAllItemsForNewFaucet_10:
	checkitem ITEM_PB_AND_J
# 0 "data/scripts/spinda.pory"
	compare VAR_RESULT, 0
	goto_if_ne SpindaIsland_Common_CheckGotAllItemsForNewFaucet_1
	return

SpindaIsland_Common_CheckGotAllItemsForNewFaucet_11:
	checkitem ITEM_COOKING_OIL
# 0 "data/scripts/spinda.pory"
	compare VAR_RESULT, 0
	goto_if_ne SpindaIsland_Common_CheckGotAllItemsForNewFaucet_10
	return


SpindaIsland_Common_CantReadSign_Text_0:
# 47 "data/scripts/spinda.pory"
	.string "Little Archie$"

SpindaIsland_Common_CantReadSign_Text_1:
# 49 "data/scripts/spinda.pory"
	.string "Can't read the sign from here.$"

SpindaIsland_Common_CantTakeStairs_Text_0:
# 63 "data/scripts/spinda.pory"
	.string "Man, if only there was a way to climb\n"
	.string "stairs when they are sideways…$"

SpindaIsland_Common_CantTakeStairs_Text_1:
# 68 "data/scripts/spinda.pory"
	.string "God$"

SpindaIsland_Common_CantTakeStairs_Text_2:
# 70 "data/scripts/spinda.pory"
	.string "“ALAS, THERE IS NOT.”\p"
	.string "“I TOTALLY WASN'T TOO LAZY TO\n"
	.string "IMPLEMENT A CERTAIN FEATURE.”$"

SpindaIsland_Common_EmptyChest_Text_0:
# 83 "data/scripts/spinda.pory"
	.string "Chest is empty.$"

SpindaIsland_Common_RegularSeashell_Text_0:
# 96 "data/scripts/spinda.pory"
	.string "A good old regular-looking seashell.$"

SpindaIsland_Common_HiddenItem_Text_0:
# 109 "data/scripts/spinda.pory"
	.string "There's something hidden here.$"

SpindaIsland_Common_HiddenObstacle_Text_0:
# 123 "data/scripts/spinda.pory"
	.string "Something's blocking the way.$"

SpindaIsland_Common_CantOpenFromThisSide_Text_0:
# 137 "data/scripts/spinda.pory"
	.string "Can't open the door from this side.$"

SpindaIsland_Common_CantSeeFromSide_Text_0:
# 151 "data/scripts/spinda.pory"
	.string "Can't see anything from this side.$"

SpindaIsland_Common_CantUseFromSide_Text_0:
# 165 "data/scripts/spinda.pory"
	.string "Can't use that from this side.$"

SpindaIsland_Common_CantEnterFromSide_Text_0:
# 179 "data/scripts/spinda.pory"
	.string "Can't enter from this side.$"

SpindaIsland_Common_CheckGotAllItemsForNewFaucet_Text_0:
# 205 "data/scripts/spinda.pory"
	.string "Wait, this means I have everything\n"
	.string "the faucet shop owner needs!!\p"
	.string "Let's go get that faucet\n"
	.string "replacement!$"

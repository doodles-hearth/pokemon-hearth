Spinda_SpinClockwise::
# 3 "data/scripts/spinda.pory"
	goto_if_set FLAG_RECEIVED_STARTER, Spinda_SpinClockwise_1
	return

Spinda_SpinClockwise_1:
# 4 "data/scripts/spinda.pory"
	setwarpnextmapclockwise
	return


Spinda_SpinCounterclockwise::
# 9 "data/scripts/spinda.pory"
	goto_if_set FLAG_RECEIVED_STARTER, Spinda_SpinCounterclockwise_1
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
	release
	return


SpindaIsland_Common_EmptyChest::
# 77 "data/scripts/spinda.pory"
	lock
# 79 "data/scripts/spinda.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 80 "data/scripts/spinda.pory"
	speakername SpindaIsland_Common_CantReadSign_Text_0
# 81 "data/scripts/spinda.pory"
	msgbox SpindaIsland_Common_EmptyChest_Text_0
# 84 "data/scripts/spinda.pory"
	closemessage
# 85 "data/scripts/spinda.pory"
	removefieldmugshot
# 86 "data/scripts/spinda.pory"
	release
	return


SpindaIsland_Common_RegularSeashell::
# 90 "data/scripts/spinda.pory"
	lock
# 92 "data/scripts/spinda.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 93 "data/scripts/spinda.pory"
	speakername SpindaIsland_Common_CantReadSign_Text_0
# 94 "data/scripts/spinda.pory"
	msgbox SpindaIsland_Common_RegularSeashell_Text_0
# 97 "data/scripts/spinda.pory"
	closemessage
# 98 "data/scripts/spinda.pory"
	removefieldmugshot
# 99 "data/scripts/spinda.pory"
	release
	return


SpindaIsland_Common_HiddenItem::
# 103 "data/scripts/spinda.pory"
	lock
# 105 "data/scripts/spinda.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 106 "data/scripts/spinda.pory"
	speakername SpindaIsland_Common_CantReadSign_Text_0
# 107 "data/scripts/spinda.pory"
	msgbox SpindaIsland_Common_HiddenItem_Text_0
# 110 "data/scripts/spinda.pory"
	closemessage
# 111 "data/scripts/spinda.pory"
	removefieldmugshot
# 113 "data/scripts/spinda.pory"
	release
	return


SpindaIsland_Common_HiddenObstacle::
# 117 "data/scripts/spinda.pory"
	lock
# 119 "data/scripts/spinda.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 120 "data/scripts/spinda.pory"
	speakername SpindaIsland_Common_CantReadSign_Text_0
# 121 "data/scripts/spinda.pory"
	msgbox SpindaIsland_Common_HiddenObstacle_Text_0
# 124 "data/scripts/spinda.pory"
	closemessage
# 125 "data/scripts/spinda.pory"
	removefieldmugshot
# 127 "data/scripts/spinda.pory"
	release
	return


SpindaIsland_Common_CantOpenFromThisSide::
# 131 "data/scripts/spinda.pory"
	lock
# 133 "data/scripts/spinda.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 134 "data/scripts/spinda.pory"
	speakername SpindaIsland_Common_CantReadSign_Text_0
# 135 "data/scripts/spinda.pory"
	msgbox SpindaIsland_Common_CantOpenFromThisSide_Text_0
# 138 "data/scripts/spinda.pory"
	closemessage
# 139 "data/scripts/spinda.pory"
	removefieldmugshot
# 141 "data/scripts/spinda.pory"
	release
	return


SpindaIsland_Common_CantSeeFromSide::
# 145 "data/scripts/spinda.pory"
	lock
# 147 "data/scripts/spinda.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 148 "data/scripts/spinda.pory"
	speakername SpindaIsland_Common_CantReadSign_Text_0
# 149 "data/scripts/spinda.pory"
	msgbox SpindaIsland_Common_CantSeeFromSide_Text_0
# 152 "data/scripts/spinda.pory"
	closemessage
# 153 "data/scripts/spinda.pory"
	removefieldmugshot
# 155 "data/scripts/spinda.pory"
	release
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
# 82 "data/scripts/spinda.pory"
	.string "Chest is empty.$"

SpindaIsland_Common_RegularSeashell_Text_0:
# 95 "data/scripts/spinda.pory"
	.string "A good old regular-looking seashell.$"

SpindaIsland_Common_HiddenItem_Text_0:
# 108 "data/scripts/spinda.pory"
	.string "There's something hidden here.$"

SpindaIsland_Common_HiddenObstacle_Text_0:
# 122 "data/scripts/spinda.pory"
	.string "Something's blocking the way.$"

SpindaIsland_Common_CantOpenFromThisSide_Text_0:
# 136 "data/scripts/spinda.pory"
	.string "Can't open the door from this side.$"

SpindaIsland_Common_CantSeeFromSide_Text_0:
# 150 "data/scripts/spinda.pory"
	.string "Can't see anything from this side.$"

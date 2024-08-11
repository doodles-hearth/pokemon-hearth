Spinda_SpinClockwise::
# 3 "data/scripts/spinda.pory"
	setwarpnextmapclockwise
	return


Spinda_SpinCounterclockwise::
# 7 "data/scripts/spinda.pory"
	setwarpnextmapcounterclockwise
	return


Spinda_TurnPlayerClockwise::
# 11 "data/scripts/spinda.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 12 "data/scripts/spinda.pory"
	switch VAR_RESULT
# 13 "data/scripts/spinda.pory"
	case DIR_SOUTH, Spinda_TurnPlayerClockwise_2
# 15 "data/scripts/spinda.pory"
	case DIR_WEST, Spinda_TurnPlayerClockwise_3
# 17 "data/scripts/spinda.pory"
	case DIR_NORTH, Spinda_TurnPlayerClockwise_4
# 19 "data/scripts/spinda.pory"
	case DIR_EAST, Spinda_TurnPlayerClockwise_5
	return

Spinda_TurnPlayerClockwise_2:
# 14 "data/scripts/spinda.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	return

Spinda_TurnPlayerClockwise_3:
# 16 "data/scripts/spinda.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	return

Spinda_TurnPlayerClockwise_4:
# 18 "data/scripts/spinda.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	return

Spinda_TurnPlayerClockwise_5:
# 20 "data/scripts/spinda.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	return


Spinda_TurnPlayerCounterclockwise::
# 25 "data/scripts/spinda.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 26 "data/scripts/spinda.pory"
	switch VAR_RESULT
# 27 "data/scripts/spinda.pory"
	case DIR_SOUTH, Spinda_TurnPlayerCounterclockwise_2
# 29 "data/scripts/spinda.pory"
	case DIR_EAST, Spinda_TurnPlayerCounterclockwise_3
# 31 "data/scripts/spinda.pory"
	case DIR_NORTH, Spinda_TurnPlayerCounterclockwise_4
# 33 "data/scripts/spinda.pory"
	case DIR_WEST, Spinda_TurnPlayerCounterclockwise_5
	return

Spinda_TurnPlayerCounterclockwise_2:
# 28 "data/scripts/spinda.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	return

Spinda_TurnPlayerCounterclockwise_3:
# 30 "data/scripts/spinda.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	return

Spinda_TurnPlayerCounterclockwise_4:
# 32 "data/scripts/spinda.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	return

Spinda_TurnPlayerCounterclockwise_5:
# 34 "data/scripts/spinda.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	return


SpindaIsland_Common_CantReadSign::
# 40 "data/scripts/spinda.pory"
	lock
# 42 "data/scripts/spinda.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 43 "data/scripts/spinda.pory"
	speakername SpindaIsland_Common_CantReadSign_Text_0
# 44 "data/scripts/spinda.pory"
	msgbox SpindaIsland_Common_CantReadSign_Text_1
# 47 "data/scripts/spinda.pory"
	closemessage
# 48 "data/scripts/spinda.pory"
	removefieldmugshot
# 50 "data/scripts/spinda.pory"
	release
	return


SpindaIsland_Common_CantTakeStairs::
# 54 "data/scripts/spinda.pory"
	lock
# 56 "data/scripts/spinda.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 57 "data/scripts/spinda.pory"
	speakername SpindaIsland_Common_CantReadSign_Text_0
# 58 "data/scripts/spinda.pory"
	msgbox SpindaIsland_Common_CantTakeStairs_Text_0
# 61 "data/scripts/spinda.pory"
	closemessage
# 62 "data/scripts/spinda.pory"
	removefieldmugshot
# 64 "data/scripts/spinda.pory"
	speakername SpindaIsland_Common_CantTakeStairs_Text_1
# 65 "data/scripts/spinda.pory"
	msgbox SpindaIsland_Common_CantTakeStairs_Text_2
# 69 "data/scripts/spinda.pory"
	release
	return


SpindaIsland_Common_EmptyChest::
# 73 "data/scripts/spinda.pory"
	lock
# 75 "data/scripts/spinda.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 76 "data/scripts/spinda.pory"
	speakername SpindaIsland_Common_CantReadSign_Text_0
# 77 "data/scripts/spinda.pory"
	msgbox SpindaIsland_Common_EmptyChest_Text_0
# 80 "data/scripts/spinda.pory"
	closemessage
# 81 "data/scripts/spinda.pory"
	removefieldmugshot
# 82 "data/scripts/spinda.pory"
	release
	return


SpindaIsland_Common_RegularSeashell::
# 86 "data/scripts/spinda.pory"
	lock
# 88 "data/scripts/spinda.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 89 "data/scripts/spinda.pory"
	speakername SpindaIsland_Common_CantReadSign_Text_0
# 90 "data/scripts/spinda.pory"
	msgbox SpindaIsland_Common_RegularSeashell_Text_0
# 93 "data/scripts/spinda.pory"
	closemessage
# 94 "data/scripts/spinda.pory"
	removefieldmugshot
# 95 "data/scripts/spinda.pory"
	release
	return


SpindaIsland_Common_HiddenItem::
# 99 "data/scripts/spinda.pory"
	lock
# 101 "data/scripts/spinda.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 102 "data/scripts/spinda.pory"
	speakername SpindaIsland_Common_CantReadSign_Text_0
# 103 "data/scripts/spinda.pory"
	msgbox SpindaIsland_Common_HiddenItem_Text_0
# 106 "data/scripts/spinda.pory"
	closemessage
# 107 "data/scripts/spinda.pory"
	removefieldmugshot
# 109 "data/scripts/spinda.pory"
	release
	return


SpindaIsland_Common_HiddenObstacle::
# 113 "data/scripts/spinda.pory"
	lock
# 115 "data/scripts/spinda.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 116 "data/scripts/spinda.pory"
	speakername SpindaIsland_Common_CantReadSign_Text_0
# 117 "data/scripts/spinda.pory"
	msgbox SpindaIsland_Common_HiddenObstacle_Text_0
# 120 "data/scripts/spinda.pory"
	closemessage
# 121 "data/scripts/spinda.pory"
	removefieldmugshot
# 123 "data/scripts/spinda.pory"
	release
	return


SpindaIsland_Common_CantOpenFromThisSide::
# 127 "data/scripts/spinda.pory"
	lock
# 129 "data/scripts/spinda.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 130 "data/scripts/spinda.pory"
	speakername SpindaIsland_Common_CantReadSign_Text_0
# 131 "data/scripts/spinda.pory"
	msgbox SpindaIsland_Common_CantOpenFromThisSide_Text_0
# 134 "data/scripts/spinda.pory"
	closemessage
# 135 "data/scripts/spinda.pory"
	removefieldmugshot
# 137 "data/scripts/spinda.pory"
	release
	return


SpindaIsland_Common_CantSeeFromSide::
# 141 "data/scripts/spinda.pory"
	lock
# 143 "data/scripts/spinda.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 144 "data/scripts/spinda.pory"
	speakername SpindaIsland_Common_CantReadSign_Text_0
# 145 "data/scripts/spinda.pory"
	msgbox SpindaIsland_Common_CantSeeFromSide_Text_0
# 148 "data/scripts/spinda.pory"
	closemessage
# 149 "data/scripts/spinda.pory"
	removefieldmugshot
# 151 "data/scripts/spinda.pory"
	release
	return


SpindaIsland_Common_CantReadSign_Text_0:
# 43 "data/scripts/spinda.pory"
	.string "Little Archie$"

SpindaIsland_Common_CantReadSign_Text_1:
# 45 "data/scripts/spinda.pory"
	.string "Can't read the sign from here.$"

SpindaIsland_Common_CantTakeStairs_Text_0:
# 59 "data/scripts/spinda.pory"
	.string "Man, if only there was a way to climb\n"
	.string "stairs when they are sideways…$"

SpindaIsland_Common_CantTakeStairs_Text_1:
# 64 "data/scripts/spinda.pory"
	.string "God$"

SpindaIsland_Common_CantTakeStairs_Text_2:
# 66 "data/scripts/spinda.pory"
	.string "“ALAS, THERE IS NOT.”\p"
	.string "“I TOTALLY WASN'T TOO LAZY TO\n"
	.string "IMPLEMENT A CERTAIN FEATURE.”$"

SpindaIsland_Common_EmptyChest_Text_0:
# 78 "data/scripts/spinda.pory"
	.string "Chest is empty.$"

SpindaIsland_Common_RegularSeashell_Text_0:
# 91 "data/scripts/spinda.pory"
	.string "A good old regular-looking seashell.$"

SpindaIsland_Common_HiddenItem_Text_0:
# 104 "data/scripts/spinda.pory"
	.string "There's something hidden here.$"

SpindaIsland_Common_HiddenObstacle_Text_0:
# 118 "data/scripts/spinda.pory"
	.string "Something's blocking the way.$"

SpindaIsland_Common_CantOpenFromThisSide_Text_0:
# 132 "data/scripts/spinda.pory"
	.string "Can't open the door from this side.$"

SpindaIsland_Common_CantSeeFromSide_Text_0:
# 146 "data/scripts/spinda.pory"
	.string "Can't see anything from this side.$"

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
	setvar VAR_0x8000, MUGSHOT_ARCHIE
# 43 "data/scripts/spinda.pory"
	callnative DrawMugshot
# 44 "data/scripts/spinda.pory"
	speakername SpindaIsland_Common_CantReadSign_Text_0
# 45 "data/scripts/spinda.pory"
	msgbox SpindaIsland_Common_CantReadSign_Text_1
# 48 "data/scripts/spinda.pory"
	closemessage
# 49 "data/scripts/spinda.pory"
	callnative ClearMugshot
# 51 "data/scripts/spinda.pory"
	release
	return


SpindaIsland_Common_CantTakeStairs::
# 55 "data/scripts/spinda.pory"
	lock
# 57 "data/scripts/spinda.pory"
	setvar VAR_0x8000, MUGSHOT_ARCHIE
# 58 "data/scripts/spinda.pory"
	callnative DrawMugshot
# 59 "data/scripts/spinda.pory"
	speakername SpindaIsland_Common_CantReadSign_Text_0
# 60 "data/scripts/spinda.pory"
	msgbox SpindaIsland_Common_CantTakeStairs_Text_0
# 63 "data/scripts/spinda.pory"
	closemessage
# 64 "data/scripts/spinda.pory"
	callnative ClearMugshot
# 66 "data/scripts/spinda.pory"
	speakername SpindaIsland_Common_CantTakeStairs_Text_1
# 67 "data/scripts/spinda.pory"
	msgbox SpindaIsland_Common_CantTakeStairs_Text_2
# 71 "data/scripts/spinda.pory"
	release
	return


SpindaIsland_Common_HiddenObstacle::
# 75 "data/scripts/spinda.pory"
	lock
# 77 "data/scripts/spinda.pory"
	setvar VAR_0x8000, MUGSHOT_ARCHIE
# 78 "data/scripts/spinda.pory"
	callnative DrawMugshot
# 79 "data/scripts/spinda.pory"
	speakername SpindaIsland_Common_CantReadSign_Text_0
# 80 "data/scripts/spinda.pory"
	msgbox SpindaIsland_Common_HiddenObstacle_Text_0
# 83 "data/scripts/spinda.pory"
	closemessage
# 84 "data/scripts/spinda.pory"
	callnative ClearMugshot
# 86 "data/scripts/spinda.pory"
	release
	return


SpindaIsland_Common_CantReadSign_Text_0:
# 44 "data/scripts/spinda.pory"
	.string "Little Archie$"

SpindaIsland_Common_CantReadSign_Text_1:
# 46 "data/scripts/spinda.pory"
	.string "Can't read the sign from here.$"

SpindaIsland_Common_CantTakeStairs_Text_0:
# 61 "data/scripts/spinda.pory"
	.string "Man, if only there was a way to climb\n"
	.string "stairs when they are sideways…$"

SpindaIsland_Common_CantTakeStairs_Text_1:
# 66 "data/scripts/spinda.pory"
	.string "God$"

SpindaIsland_Common_CantTakeStairs_Text_2:
# 68 "data/scripts/spinda.pory"
	.string "“ALAS, THERE IS NOT.\p"
	.string "” “I TOTALLY WASN'T TOO LAZY TO\n"
	.string "IMPLEMENT A CERTAIN FEATURE.”$"

SpindaIsland_Common_HiddenObstacle_Text_0:
# 81 "data/scripts/spinda.pory"
	.string "Something's blocking the way.$"

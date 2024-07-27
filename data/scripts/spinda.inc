Spinda_SpinClockwise::
# 7 "data/scripts/spinda.pory"
	rotateplayerxyclockwise
# 8 "data/scripts/spinda.pory"
	buffernumberstring STR_VAR_1, VAR_0x8000
# 9 "data/scripts/spinda.pory"
	buffernumberstring STR_VAR_2, VAR_0x8001
# 11 "data/scripts/spinda.pory"
	warpsilent MAP_SPINDA_ISLAND_HOME_CLOCK1, VAR_0x8000, VAR_0x8001
# 12 "data/scripts/spinda.pory"
	call Spinda_TurnPlayerClockwise
	return


Spinda_SpinCounterclockwise::
# 16 "data/scripts/spinda.pory"
	rotateplayerxycounterclockwise
# 17 "data/scripts/spinda.pory"
	warpsilent MAP_SPINDA_ISLAND_HOME_CLOCK1, VAR_0x8000, VAR_0x8001
# 18 "data/scripts/spinda.pory"
	call Spinda_TurnPlayerCounterclockwise
	return


Spinda_TurnPlayerClockwise::
# 22 "data/scripts/spinda.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 23 "data/scripts/spinda.pory"
	switch VAR_RESULT
# 24 "data/scripts/spinda.pory"
	case DIR_SOUTH, Spinda_TurnPlayerClockwise_2
# 26 "data/scripts/spinda.pory"
	case DIR_WEST, Spinda_TurnPlayerClockwise_3
# 28 "data/scripts/spinda.pory"
	case DIR_NORTH, Spinda_TurnPlayerClockwise_4
# 30 "data/scripts/spinda.pory"
	case DIR_EAST, Spinda_TurnPlayerClockwise_5
	return

Spinda_TurnPlayerClockwise_2:
# 25 "data/scripts/spinda.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	return

Spinda_TurnPlayerClockwise_3:
# 27 "data/scripts/spinda.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	return

Spinda_TurnPlayerClockwise_4:
# 29 "data/scripts/spinda.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	return

Spinda_TurnPlayerClockwise_5:
# 31 "data/scripts/spinda.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	return


Spinda_TurnPlayerCounterclockwise::
# 36 "data/scripts/spinda.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 37 "data/scripts/spinda.pory"
	switch VAR_RESULT
# 38 "data/scripts/spinda.pory"
	case DIR_SOUTH, Spinda_TurnPlayerCounterclockwise_2
# 40 "data/scripts/spinda.pory"
	case DIR_EAST, Spinda_TurnPlayerCounterclockwise_3
# 42 "data/scripts/spinda.pory"
	case DIR_NORTH, Spinda_TurnPlayerCounterclockwise_4
# 44 "data/scripts/spinda.pory"
	case DIR_WEST, Spinda_TurnPlayerCounterclockwise_5
	return

Spinda_TurnPlayerCounterclockwise_2:
# 39 "data/scripts/spinda.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	return

Spinda_TurnPlayerCounterclockwise_3:
# 41 "data/scripts/spinda.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	return

Spinda_TurnPlayerCounterclockwise_4:
# 43 "data/scripts/spinda.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	return

Spinda_TurnPlayerCounterclockwise_5:
# 45 "data/scripts/spinda.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	return


SpindaIsland_Common_CantReadSign::
# 51 "data/scripts/spinda.pory"
	lock
# 53 "data/scripts/spinda.pory"
	setvar VAR_0x8000, MUGSHOT_ARCHIE
# 54 "data/scripts/spinda.pory"
	callnative DrawMugshot
# 55 "data/scripts/spinda.pory"
	speakername SpindaIsland_Common_CantReadSign_Text_0
# 56 "data/scripts/spinda.pory"
	msgbox SpindaIsland_Common_CantReadSign_Text_1
# 59 "data/scripts/spinda.pory"
	closemessage
# 60 "data/scripts/spinda.pory"
	callnative ClearMugshot
# 62 "data/scripts/spinda.pory"
	release
	return


SpindaIsland_Common_CantTakeStairs::
# 66 "data/scripts/spinda.pory"
	lock
# 68 "data/scripts/spinda.pory"
	setvar VAR_0x8000, MUGSHOT_ARCHIE
# 69 "data/scripts/spinda.pory"
	callnative DrawMugshot
# 70 "data/scripts/spinda.pory"
	speakername SpindaIsland_Common_CantReadSign_Text_0
# 71 "data/scripts/spinda.pory"
	msgbox SpindaIsland_Common_CantTakeStairs_Text_0
# 74 "data/scripts/spinda.pory"
	closemessage
# 75 "data/scripts/spinda.pory"
	callnative ClearMugshot
# 77 "data/scripts/spinda.pory"
	speakername SpindaIsland_Common_CantTakeStairs_Text_1
# 78 "data/scripts/spinda.pory"
	msgbox SpindaIsland_Common_CantTakeStairs_Text_2
# 81 "data/scripts/spinda.pory"
	release
	return


SpindaIsland_Common_CantReadSign_Text_0:
# 55 "data/scripts/spinda.pory"
	.string "Little Archie$"

SpindaIsland_Common_CantReadSign_Text_1:
# 57 "data/scripts/spinda.pory"
	.string "Can't read the sign from here.$"

SpindaIsland_Common_CantTakeStairs_Text_0:
# 72 "data/scripts/spinda.pory"
	.string "Man, if only there was a way to climb\n"
	.string "stairs when they are sideways…$"

SpindaIsland_Common_CantTakeStairs_Text_1:
# 77 "data/scripts/spinda.pory"
	.string "God$"

SpindaIsland_Common_CantTakeStairs_Text_2:
# 79 "data/scripts/spinda.pory"
	.string "“ALAS, THERE IS NOT.”$"

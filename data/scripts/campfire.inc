EventScript_Campfire::
# 2 "data/scripts/campfire.pory"
	lock
# 4 "data/scripts/campfire.pory"
	goto_if_set FLAG_HIDE_CAMPFIRE_PARTY_MON_1, EventScript_Campfire_2
# 15 "data/scripts/campfire.pory"
	msgbox EventScript_Campfire_Text_1, MSGBOX_YESNO
# 19 "data/scripts/campfire.pory"
	compare VAR_RESULT, YES
	goto_if_eq EventScript_Campfire_7
EventScript_Campfire_1:
# 24 "data/scripts/campfire.pory"
	release
	return

EventScript_Campfire_2:
# 5 "data/scripts/campfire.pory"
	msgbox EventScript_Campfire_Text_0, MSGBOX_YESNO
# 9 "data/scripts/campfire.pory"
	compare VAR_RESULT, YES
	goto_if_eq EventScript_Campfire_5
	goto EventScript_Campfire_1

EventScript_Campfire_5:
# 11 "data/scripts/campfire.pory"
	campfire
	goto EventScript_Campfire_1

EventScript_Campfire_7:
# 20 "data/scripts/campfire.pory"
	call EventScript_LeaveCampfire
	goto EventScript_Campfire_1


EventScript_WalkAwayFromCampfire::
# 28 "data/scripts/campfire.pory"
	lock
# 30 "data/scripts/campfire.pory"
	msgbox EventScript_Campfire_Text_1, MSGBOX_YESNO
# 34 "data/scripts/campfire.pory"
	compare VAR_RESULT, YES
	goto_if_eq EventScript_WalkAwayFromCampfire_2
# 37 "data/scripts/campfire.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 38 "data/scripts/campfire.pory"
	buffernumberstring STR_VAR_1, VAR_RESULT
# 42 "data/scripts/campfire.pory"
	switch VAR_RESULT
# 43 "data/scripts/campfire.pory"
	case DIR_NORTH, EventScript_WalkAwayFromCampfire_7
# 46 "data/scripts/campfire.pory"
	case DIR_SOUTH, EventScript_WalkAwayFromCampfire_8
# 49 "data/scripts/campfire.pory"
	case DIR_EAST, EventScript_WalkAwayFromCampfire_9
# 52 "data/scripts/campfire.pory"
	case DIR_WEST, EventScript_WalkAwayFromCampfire_10
EventScript_WalkAwayFromCampfire_5:
# 56 "data/scripts/campfire.pory"
	waitmovement 0
EventScript_WalkAwayFromCampfire_1:
# 59 "data/scripts/campfire.pory"
	release
	return

EventScript_WalkAwayFromCampfire_2:
# 35 "data/scripts/campfire.pory"
	call EventScript_LeaveCampfire
	goto EventScript_WalkAwayFromCampfire_1

EventScript_WalkAwayFromCampfire_7:
# 45 "data/scripts/campfire.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_ComeBackToCampfire_Down
	goto EventScript_WalkAwayFromCampfire_5

EventScript_WalkAwayFromCampfire_8:
# 48 "data/scripts/campfire.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_ComeBackToCampfire_Up
	goto EventScript_WalkAwayFromCampfire_5

EventScript_WalkAwayFromCampfire_9:
# 51 "data/scripts/campfire.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_ComeBackToCampfire_Left
	goto EventScript_WalkAwayFromCampfire_5

EventScript_WalkAwayFromCampfire_10:
# 54 "data/scripts/campfire.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_ComeBackToCampfire_Right
	goto EventScript_WalkAwayFromCampfire_5


# 62 "data/scripts/campfire.pory"
Movement_ComeBackToCampfire_Down:
# 63 "data/scripts/campfire.pory"
	walk_down
	step_end

# 66 "data/scripts/campfire.pory"
Movement_ComeBackToCampfire_Up:
# 67 "data/scripts/campfire.pory"
	walk_up
	step_end

# 70 "data/scripts/campfire.pory"
Movement_ComeBackToCampfire_Left:
# 71 "data/scripts/campfire.pory"
	walk_left
	step_end

# 74 "data/scripts/campfire.pory"
Movement_ComeBackToCampfire_Right:
# 75 "data/scripts/campfire.pory"
	walk_right
	step_end

EventScript_LeaveCampfire::
# 79 "data/scripts/campfire.pory"
	msgbox EventScript_LeaveCampfire_Text_0
# 82 "data/scripts/campfire.pory"
	closemessage
# 84 "data/scripts/campfire.pory"
	fadescreen FADE_TO_BLACK
# 85 "data/scripts/campfire.pory"
	leavecampfire
# 86 "data/scripts/campfire.pory"
	fadescreen FADE_FROM_BLACK
	return


EventScript_Campfire_Text_0:
# 6 "data/scripts/campfire.pory"
	.string "Rest at the campfire?$"

EventScript_Campfire_Text_1:
# 16 "data/scripts/campfire.pory"
	.string "Leave the campfire?$"

EventScript_LeaveCampfire_Text_0:
# 80 "data/scripts/campfire.pory"
	.string "Your Pokémon are well-rested.\n"
	.string "Time to go!$"

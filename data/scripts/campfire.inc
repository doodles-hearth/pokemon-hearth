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
# 33 "data/scripts/campfire.pory"
	closemessage
# 35 "data/scripts/campfire.pory"
	compare VAR_RESULT, YES
	goto_if_eq EventScript_WalkAwayFromCampfire_2
# 38 "data/scripts/campfire.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 39 "data/scripts/campfire.pory"
	buffernumberstring STR_VAR_1, VAR_RESULT
# 43 "data/scripts/campfire.pory"
	switch VAR_RESULT
# 44 "data/scripts/campfire.pory"
	case DIR_NORTH, EventScript_WalkAwayFromCampfire_7
# 47 "data/scripts/campfire.pory"
	case DIR_SOUTH, EventScript_WalkAwayFromCampfire_8
# 50 "data/scripts/campfire.pory"
	case DIR_EAST, EventScript_WalkAwayFromCampfire_9
# 53 "data/scripts/campfire.pory"
	case DIR_WEST, EventScript_WalkAwayFromCampfire_10
EventScript_WalkAwayFromCampfire_5:
# 57 "data/scripts/campfire.pory"
	waitmovement 0
EventScript_WalkAwayFromCampfire_1:
# 60 "data/scripts/campfire.pory"
	release
	return

EventScript_WalkAwayFromCampfire_2:
# 36 "data/scripts/campfire.pory"
	call EventScript_LeaveCampfire
	goto EventScript_WalkAwayFromCampfire_1

EventScript_WalkAwayFromCampfire_7:
# 46 "data/scripts/campfire.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_ComeBackToCampfire_Down
	goto EventScript_WalkAwayFromCampfire_5

EventScript_WalkAwayFromCampfire_8:
# 49 "data/scripts/campfire.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_ComeBackToCampfire_Up
	goto EventScript_WalkAwayFromCampfire_5

EventScript_WalkAwayFromCampfire_9:
# 52 "data/scripts/campfire.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_ComeBackToCampfire_Left
	goto EventScript_WalkAwayFromCampfire_5

EventScript_WalkAwayFromCampfire_10:
# 55 "data/scripts/campfire.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_ComeBackToCampfire_Right
	goto EventScript_WalkAwayFromCampfire_5


# 63 "data/scripts/campfire.pory"
Movement_ComeBackToCampfire_Down:
# 64 "data/scripts/campfire.pory"
	walk_down
	step_end

# 67 "data/scripts/campfire.pory"
Movement_ComeBackToCampfire_Up:
# 68 "data/scripts/campfire.pory"
	walk_up
	step_end

# 71 "data/scripts/campfire.pory"
Movement_ComeBackToCampfire_Left:
# 72 "data/scripts/campfire.pory"
	walk_left
	step_end

# 75 "data/scripts/campfire.pory"
Movement_ComeBackToCampfire_Right:
# 76 "data/scripts/campfire.pory"
	walk_right
	step_end

EventScript_LeaveCampfire::
# 80 "data/scripts/campfire.pory"
	msgbox EventScript_LeaveCampfire_Text_0
# 83 "data/scripts/campfire.pory"
	closemessage
# 85 "data/scripts/campfire.pory"
	fadescreen FADE_TO_BLACK
# 86 "data/scripts/campfire.pory"
	leavecampfire
# 87 "data/scripts/campfire.pory"
	fadescreen FADE_FROM_BLACK
	return


EventScript_Campfire_Text_0:
# 6 "data/scripts/campfire.pory"
	.string "Rest at the campfire?$"

EventScript_Campfire_Text_1:
# 16 "data/scripts/campfire.pory"
	.string "Leave the campfire?$"

EventScript_LeaveCampfire_Text_0:
# 81 "data/scripts/campfire.pory"
	.string "Your Pokémon are well-rested.\n"
	.string "Time to go!$"

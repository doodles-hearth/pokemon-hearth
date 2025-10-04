EventScript_Campfire::
	lock
	goto_if_set FLAG_HIDE_CAMPFIRE_PARTY_MON_1, EventScript_Campfire_2
	msgbox EventScript_Campfire_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EventScript_Campfire_7
EventScript_Campfire_1:
	release
	return

EventScript_Campfire_2:
	msgbox EventScript_Campfire_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EventScript_Campfire_5
	goto EventScript_Campfire_1

EventScript_Campfire_5:
	campfire
	goto EventScript_Campfire_1

EventScript_Campfire_7:
	call EventScript_LeaveCampfire
	goto EventScript_Campfire_1


EventScript_WalkAwayFromCampfire::
	lock
	msgbox EventScript_Campfire_Text_1, MSGBOX_YESNO
	closemessage
	compare VAR_RESULT, YES
	goto_if_eq EventScript_WalkAwayFromCampfire_2
	specialvar VAR_RESULT, GetPlayerFacingDirection
	buffernumberstring STR_VAR_1, VAR_RESULT
	switch VAR_RESULT
	case DIR_NORTH, EventScript_WalkAwayFromCampfire_7
	case DIR_SOUTH, EventScript_WalkAwayFromCampfire_8
	case DIR_EAST, EventScript_WalkAwayFromCampfire_9
	case DIR_WEST, EventScript_WalkAwayFromCampfire_10
EventScript_WalkAwayFromCampfire_5:
	waitmovement 0
EventScript_WalkAwayFromCampfire_1:
	release
	return

EventScript_WalkAwayFromCampfire_2:
	call EventScript_LeaveCampfire
	goto EventScript_WalkAwayFromCampfire_1

EventScript_WalkAwayFromCampfire_7:
	applymovement OBJ_EVENT_ID_PLAYER, Movement_ComeBackToCampfire_Down
	goto EventScript_WalkAwayFromCampfire_5

EventScript_WalkAwayFromCampfire_8:
	applymovement OBJ_EVENT_ID_PLAYER, Movement_ComeBackToCampfire_Up
	goto EventScript_WalkAwayFromCampfire_5

EventScript_WalkAwayFromCampfire_9:
	applymovement OBJ_EVENT_ID_PLAYER, Movement_ComeBackToCampfire_Left
	goto EventScript_WalkAwayFromCampfire_5

EventScript_WalkAwayFromCampfire_10:
	applymovement OBJ_EVENT_ID_PLAYER, Movement_ComeBackToCampfire_Right
	goto EventScript_WalkAwayFromCampfire_5


Movement_ComeBackToCampfire_Down:
	walk_down
	step_end

Movement_ComeBackToCampfire_Up:
	walk_up
	step_end

Movement_ComeBackToCampfire_Left:
	walk_left
	step_end

Movement_ComeBackToCampfire_Right:
	walk_right
	step_end

EventScript_LeaveCampfire::
	msgbox EventScript_LeaveCampfire_Text_0
	closemessage
	fadescreen FADE_TO_BLACK
	leaveCampfire
	fadescreen FADE_FROM_BLACK
	return


EventScript_Campfire_Text_0:
	.string "Rest at the campfire?$"

EventScript_Campfire_Text_1:
	.string "Leave the campfire?$"

EventScript_LeaveCampfire_Text_0:
	.string "Your Pokémon are well-rested.\n"
	.string "Time to go!$"

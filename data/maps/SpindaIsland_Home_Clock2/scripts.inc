SpindaIsland_Home_Clock2_MapScripts::
# 4 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SpindaIsland_Home_Clock2_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

SpindaIsland_Home_Clock2_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 5 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	goto_if_set FLAG_SLOWPOKE_EVOLVED, SpindaIsland_Home_Clock2_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
# 8 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( SLOWPOKE )
	return

SpindaIsland_Home_Clock2_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 6 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( SLOWBRO )
	return


SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome::
# 14 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	lock
# 15 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	faceplayer
# 16 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_0
# 17 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_1
# 22 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	closemessage
# 24 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	playse SE_PIN
# 25 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	applymovement 3, Common_Movement_ExclamationMark
# 26 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	waitmovement 0
# 27 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay 48
# 29 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	applymovement 3, SpindaIsland_Home_Clock2_Movement_SadManSurprise
# 30 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	waitmovement 0
# 32 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_0
# 33 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_2
# 37 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	closemessage
# 39 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	faceplayer
# 40 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_0
# 41 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_3
# 45 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	dynmultichoice 16, 6, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_4, SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_5
# 55 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	closemessage
# 57 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_0
# 58 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_6
# 63 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	closemessage
# 67 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	switch VAR_FACING
# 68 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	case DIR_NORTH, SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_3
# 70 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	case DIR_SOUTH, SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_4
# 72 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	case DIR_WEST, SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_5
# 74 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	case DIR_EAST, SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_6
SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_1:
# 78 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	waitmovement 0
# 79 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removeobject 3
# 80 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	setflag FLAG_HIDE_MAN_CANT_GO_HOME
# 82 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	release
	return

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_3:
# 69 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	applymovement 3, SpindaIsland_Home_Clock2_Movement_SadManEntersHome
	goto SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_1

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_4:
# 71 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	applymovement 3, SpindaIsland_Home_Clock2_Movement_SadManEntersHome
	goto SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_1

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_5:
# 73 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	applymovement 3, SpindaIsland_Home_Clock2_Movement_SadManEntersHome
	goto SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_1

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_6:
# 75 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	applymovement 3, SpindaIsland_Home_Clock2_Movement_SadManEntersHome
	goto SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_1


SpindaIsland_Home_Clock2_EventScript_FindSeashell::
# 86 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	lock
# 87 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_SURPRISED
# 88 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_FindSeashell_Text_0
# 89 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_FindSeashell_Text_1
# 93 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
# 95 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	giveitem ITEM_WHITE_SEASHELL
# 96 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	setflag FLAG_FOUND_WHITE_SEASHELL
# 97 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removeobject VAR_LAST_TALKED
# 99 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	release
	return


SpindaIsland_Home_Clock2_EventScript_NoteBehindFaucetSign::
# 103 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_NoteBehindFaucetSign_Text_0, MSGBOX_SIGN
	return


SpindaIsland_Home_Clock2_EventScript_ExplanationSign::
# 109 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_ExplanationSign_Text_0, MSGBOX_SIGN
	return


# 119 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
SpindaIsland_Home_Clock2_Movement_SadManEntersHome:
# 120 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	walk_left
# 120 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	walk_left
# 120 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	walk_left
# 121 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	walk_up
# 121 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	walk_up
	step_end

# 124 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
SpindaIsland_Home_Clock2_Movement_SadManEntersHomeAroundPlayer:
# 125 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	walk_up
# 126 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	walk_left
# 126 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	walk_left
# 126 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	walk_left
# 127 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	walk_up
	step_end

# 130 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
SpindaIsland_Home_Clock2_Movement_SadManSurprise:
# 131 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 131 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 131 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 132 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	face_right
# 133 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 133 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 134 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	face_down
# 135 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 135 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 136 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	face_up
# 137 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 137 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 138 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	face_left
# 139 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 139 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 140 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	jump_in_place_left
# 141 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 141 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 141 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
	step_end

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_0:
# 16 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "Sad man$"

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_1:
# 18 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "Curse the architect that built my\n"
	.string "house facing the wrong direction!!\p"
	.string "I can never go home!\p"
	.string "… …$"

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_2:
# 34 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "My house! It's facing the right\n"
	.string "direction!\p"
	.string "But what… how…$"

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_3:
# 42 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "Did… did you do something?$"

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_4:
# 52 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "I didn't do anything special…$"

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_5:
# 53 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "I… turned around?$"

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_6:
# 59 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "Don't be modest, kid!\p"
	.string "I don't know how you did it, but you\n"
	.string "saved me from a life of endless\l"
	.string "waiting and suffering!\p"
	.string "Here, take this at least.$"

SpindaIsland_Home_Clock2_EventScript_FindSeashell_Text_0:
# 88 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "Little Archie$"

SpindaIsland_Home_Clock2_EventScript_FindSeashell_Text_1:
# 90 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "Woah, what's this?\p"
	.string "This seashell's completely white! So\n"
	.string "cool!!$"

SpindaIsland_Home_Clock2_EventScript_NoteBehindFaucetSign_Text_0:
# 104 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "“look down”$"

SpindaIsland_Home_Clock2_EventScript_ExplanationSign_Text_0:
# 110 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "“This world is a little strange.\n"
	.string "When an object is turned to the side,\l"
	.string "you cannot interact with it.\l"
	.string "It has to face {COLOR RED}you{COLOR DARK_GRAY}.\l"
	.string "Not your body, but your very soul.\l"
	.string "What could be called the {COLOR RED}true you{COLOR DARK_GRAY}.”$"

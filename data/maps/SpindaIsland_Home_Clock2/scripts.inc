SpindaIsland_Home_Clock2_MapScripts::
# 4 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SpindaIsland_Home_Clock2_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 11 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SpindaIsland_Home_Clock2_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
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

SpindaIsland_Home_Clock2_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 12 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	map_script_2 VAR_SPINDA_ISLAND_INTRO_STATE, 2, SpindaIsland_Home_EventScript_MainQuestRecap
	.2byte 0


SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome::
# 17 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	lock
# 18 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	faceplayer
# 19 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_SAD
# 20 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_0
# 21 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_1
# 26 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
# 27 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	closemessage
# 29 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	playse SE_PIN
# 30 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	applymovement 3, Common_Movement_ExclamationMark
# 31 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	waitmovement 0
# 32 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay 48
# 34 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	applymovement 3, SpindaIsland_Home_Clock2_Movement_SadManSurprise
# 35 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	waitmovement 0
# 37 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_NORMAL
# 38 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_0
# 39 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_2
# 43 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
# 44 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	closemessage
# 46 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	faceplayer
# 47 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_NORMAL
# 48 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_0
# 49 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_3
# 53 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_4, SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_5
# 63 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	closemessage
# 65 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_0
# 66 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_6
# 71 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
# 72 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	closemessage
# 76 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	switch VAR_FACING
# 77 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	case DIR_NORTH, SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_3
# 79 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	case DIR_SOUTH, SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_4
# 81 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	case DIR_WEST, SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_5
# 83 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	case DIR_EAST, SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_6
SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_1:
# 87 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	waitmovement 0
# 88 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	playse SE_EXIT
# 89 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	waitse
# 90 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removeobject 3
# 91 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	setflag FLAG_HIDE_MAN_CANT_GO_HOME
# 93 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	release
	return

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_3:
# 78 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	applymovement 3, SpindaIsland_Home_Clock2_Movement_SadManEntersHome
	goto SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_1

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_4:
# 80 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	applymovement 3, SpindaIsland_Home_Clock2_Movement_SadManEntersHome
	goto SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_1

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_5:
# 82 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	applymovement 3, SpindaIsland_Home_Clock2_Movement_SadManEntersHome
	goto SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_1

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_6:
# 84 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	applymovement 3, SpindaIsland_Home_Clock2_Movement_SadManEntersHomeAroundPlayer
	goto SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_1


SpindaIsland_Home_Clock2_EventScript_FindSeashell::
# 97 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	lock
# 98 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 99 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_FindSeashell_Text_0
# 100 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_FindSeashell_Text_1
# 104 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
# 106 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	giveitem ITEM_WHITE_SEASHELL
# 107 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	setflag FLAG_FOUND_WHITE_SEASHELL
# 108 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removeobject VAR_LAST_TALKED
# 110 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	release
	return


SpindaIsland_Home_Clock2_EventScript_NoteBehindFaucetSign::
# 114 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_NoteBehindFaucetSign_Text_0, MSGBOX_SIGN
	return


SpindaIsland_Home_Clock2_EventScript_ExplanationSign::
# 120 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_ExplanationSign_Text_0, MSGBOX_SIGN
	return


# 130 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
SpindaIsland_Home_Clock2_Movement_SadManEntersHome:
# 131 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	walk_left
# 131 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	walk_left
# 131 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	walk_left
# 132 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	walk_up
# 132 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	walk_up
	step_end

# 135 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
SpindaIsland_Home_Clock2_Movement_SadManEntersHomeAroundPlayer:
# 136 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	walk_up
# 137 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	walk_left
# 137 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	walk_left
# 137 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	walk_left
# 138 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	walk_up
	step_end

# 141 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
SpindaIsland_Home_Clock2_Movement_SadManSurprise:
# 142 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 142 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 142 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 143 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	face_right
# 144 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 144 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 145 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	face_down
# 146 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 146 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 147 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	face_up
# 148 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 148 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 149 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	face_left
# 150 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 150 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 151 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	jump_in_place_left
# 152 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 152 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 152 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
	step_end

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_0:
# 20 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "Sad man$"

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_1:
# 22 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "Curse the architect that built my\n"
	.string "house facing the wrong direction!!\p"
	.string "I can never go home!\p"
	.string "… …$"

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_2:
# 40 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "My house! It's facing the right\n"
	.string "direction!\p"
	.string "But what… how…$"

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_3:
# 50 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "Did… did you do something?$"

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_4:
# 60 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "I didn't do anything special…$"

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_5:
# 61 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "I… turned around?$"

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_6:
# 67 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "Don't be modest, kid!\p"
	.string "I don't know how you did it, but you\n"
	.string "saved me from a life of endless\l"
	.string "waiting and suffering!\p"
	.string "Here, take this at least.$"

SpindaIsland_Home_Clock2_EventScript_FindSeashell_Text_0:
# 99 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "Little Archie$"

SpindaIsland_Home_Clock2_EventScript_FindSeashell_Text_1:
# 101 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "Woah, what's this?\p"
	.string "This seashell's completely white! So\n"
	.string "cool!!$"

SpindaIsland_Home_Clock2_EventScript_NoteBehindFaucetSign_Text_0:
# 115 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "“look down”$"

SpindaIsland_Home_Clock2_EventScript_ExplanationSign_Text_0:
# 121 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "“This world is a little strange.\n"
	.string "When an object is turned to the side,\l"
	.string "you cannot interact with it.\l"
	.string "It has to face {COLOR RED}you{COLOR DARK_GRAY}.\l"
	.string "Not your body, but your very soul.\l"
	.string "What could be called the {COLOR RED}true you{COLOR DARK_GRAY}.”$"

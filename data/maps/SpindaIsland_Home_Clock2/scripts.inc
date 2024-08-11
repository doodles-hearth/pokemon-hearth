SpindaIsland_Home_Clock2_MapScripts::
	.byte 0


SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome::
# 8 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	lock
# 9 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	faceplayer
# 10 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_0
# 11 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_1
# 16 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	closemessage
# 18 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	applymovement 3, Common_Movement_ExclamationMark
# 19 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	waitmovement 0
# 20 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	applymovement 3, SpindaIsland_Home_Clock2_Movement_SadManSurprise
# 22 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_0
# 23 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_2
# 27 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	closemessage
# 29 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	faceplayer
# 30 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_0
# 31 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_3
# 34 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	closemessage
# 36 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	dynmultichoice 16, 6, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_4, SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_5
# 47 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_0
# 48 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_6
# 53 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	closemessage
# 57 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	switch VAR_FACING
# 58 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	case DIR_NORTH, SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_3
# 60 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	case DIR_SOUTH, SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_4
# 62 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	case DIR_WEST, SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_5
# 64 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	case DIR_EAST, SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_6
SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_1:
# 68 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removeobject 3
# 69 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	setflag FLAG_HIDE_MAN_CANT_GO_HOME
# 71 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	release
	return

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_3:
# 59 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	applymovement 3, SpindaIsland_Home_Clock2_Movement_SadManEntersHome
	goto SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_1

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_4:
# 61 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	applymovement 3, SpindaIsland_Home_Clock2_Movement_SadManEntersHome
	goto SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_1

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_5:
# 63 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	applymovement 3, SpindaIsland_Home_Clock2_Movement_SadManEntersHome
	goto SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_1

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_6:
# 65 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	applymovement 3, SpindaIsland_Home_Clock2_Movement_SadManEntersHome
	goto SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_1


SpindaIsland_Home_Clock2_EventScript_FindSeashell::
# 75 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	lock
# 76 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_SURPRISED
# 77 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_FindSeashell_Text_0
# 78 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_FindSeashell_Text_1
# 82 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
# 84 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	giveitem ITEM_WHITE_SEASHELL
# 86 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	release
	return


# 89 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
SpindaIsland_Home_Clock2_Movement_SadManEntersHome:
# 90 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	walk_left
# 90 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	walk_left
# 90 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	walk_left
# 91 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	walk_up
# 91 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	walk_up
	step_end

# 94 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
SpindaIsland_Home_Clock2_Movement_SadManEntersHomeAroundPlayer:
# 95 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	walk_up
# 96 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	walk_left
# 96 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	walk_left
# 96 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	walk_left
# 97 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	walk_up
	step_end

# 100 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
SpindaIsland_Home_Clock2_Movement_SadManSurprise:
# 101 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 101 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 101 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 102 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	face_right
# 103 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 103 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 104 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	face_down
# 105 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 105 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 106 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	face_up
# 107 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 107 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 108 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	face_left
# 109 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 109 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 110 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	jump_in_place_left
# 111 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 111 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 111 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
	step_end

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_0:
# 10 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "Sad man$"

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_1:
# 12 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "Curse the architect that built my\n"
	.string "house facing the wrong direction!!\p"
	.string "I can never go home!\p"
	.string "… …$"

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_2:
# 24 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "My house! It's facing the right\n"
	.string "direction!\p"
	.string "But what… how…$"

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_3:
# 32 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "Did… did you do something?$"

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_4:
# 43 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "I didn't do anything special…$"

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_5:
# 44 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "I… turned around?$"

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_6:
# 49 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "Don't be modest, kid!\p"
	.string "I don't know how you did it, but you\n"
	.string "saved me from a life of endless\l"
	.string "waiting and suffering!\p"
	.string "Here, take this at least.$"

SpindaIsland_Home_Clock2_EventScript_FindSeashell_Text_0:
# 77 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "Little Archie$"

SpindaIsland_Home_Clock2_EventScript_FindSeashell_Text_1:
# 79 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "Woah, what's this?\p"
	.string "This seashell's completely white! So\n"
	.string "cool!!$"

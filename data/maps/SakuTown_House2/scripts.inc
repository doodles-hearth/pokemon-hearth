SakuTown_House2_MapScripts::
	.byte 0


SakuTown_House2_EventScript_EspeonsMaster::
# 10 "data/maps/SakuTown_House2/scripts.pory"
	lock
# 11 "data/maps/SakuTown_House2/scripts.pory"
	faceplayer
# 14 "data/maps/SakuTown_House2/scripts.pory"
	compare VAR_SAKU_KURA_QUEST_ESPEON_STATE, 0
	goto_if_eq SakuTown_House2_EventScript_EspeonsMaster_2
# 21 "data/maps/SakuTown_House2/scripts.pory"
	compare VAR_SAKU_KURA_QUEST_ESPEON_STATE, 1
	goto_if_eq SakuTown_House2_EventScript_EspeonsMaster_3
# 30 "data/maps/SakuTown_House2/scripts.pory"
	compare VAR_SAKU_KURA_QUEST_ESPEON_STATE, 2
	goto_if_eq SakuTown_House2_EventScript_EspeonsMaster_4
# 37 "data/maps/SakuTown_House2/scripts.pory"
	compare VAR_SAKU_KURA_QUEST_ESPEON_STATE, 3
	goto_if_eq SakuTown_House2_EventScript_EspeonsMaster_5
# 44 "data/maps/SakuTown_House2/scripts.pory"
	compare VAR_SAKU_KURA_QUEST_ESPEON_STATE, 4
	goto_if_eq SakuTown_House2_EventScript_EspeonsMaster_6
# 48 "data/maps/SakuTown_House2/scripts.pory"
	compare VAR_SAKU_KURA_QUEST_ESPEON_STATE, 5
	goto_if_eq SakuTown_House2_EventScript_EspeonsMaster_7
SakuTown_House2_EventScript_EspeonsMaster_1:
# 55 "data/maps/SakuTown_House2/scripts.pory"
	release
	return

SakuTown_House2_EventScript_EspeonsMaster_2:
# 15 "data/maps/SakuTown_House2/scripts.pory"
	msgbox SakuTown_House2_EventScript_EspeonsMaster_Text_0
# 18 "data/maps/SakuTown_House2/scripts.pory"
	closemessage
# 20 "data/maps/SakuTown_House2/scripts.pory"
	setvar VAR_SAKU_KURA_QUEST_ESPEON_STATE, 2
	goto SakuTown_House2_EventScript_EspeonsMaster_1

SakuTown_House2_EventScript_EspeonsMaster_3:
# 22 "data/maps/SakuTown_House2/scripts.pory"
	msgbox SakuTown_House2_EventScript_EspeonsMaster_Text_1
# 26 "data/maps/SakuTown_House2/scripts.pory"
	closemessage
# 29 "data/maps/SakuTown_House2/scripts.pory"
	setvar VAR_SAKU_KURA_QUEST_ESPEON_STATE, 3
	goto SakuTown_House2_EventScript_EspeonsMaster_1

SakuTown_House2_EventScript_EspeonsMaster_4:
# 31 "data/maps/SakuTown_House2/scripts.pory"
	msgbox SakuTown_House2_EventScript_EspeonsMaster_Text_2
# 34 "data/maps/SakuTown_House2/scripts.pory"
	closemessage
	goto SakuTown_House2_EventScript_EspeonsMaster_1

SakuTown_House2_EventScript_EspeonsMaster_5:
# 38 "data/maps/SakuTown_House2/scripts.pory"
	msgbox SakuTown_House2_EventScript_EspeonsMaster_Text_3
# 41 "data/maps/SakuTown_House2/scripts.pory"
	closemessage
	goto SakuTown_House2_EventScript_EspeonsMaster_1

SakuTown_House2_EventScript_EspeonsMaster_6:
# 45 "data/maps/SakuTown_House2/scripts.pory"
	call SakuTown_House2_EventScript_Reunited
	goto SakuTown_House2_EventScript_EspeonsMaster_1

SakuTown_House2_EventScript_EspeonsMaster_7:
# 49 "data/maps/SakuTown_House2/scripts.pory"
	msgbox SakuTown_House2_EventScript_EspeonsMaster_Text_4
# 52 "data/maps/SakuTown_House2/scripts.pory"
	closemessage
	goto SakuTown_House2_EventScript_EspeonsMaster_1


SakuTown_House2_EventScript_Reunited::
# 60 "data/maps/SakuTown_House2/scripts.pory"
	setvar VAR_SAKU_KURA_QUEST_ESPEON_STATE, 5
# 61 "data/maps/SakuTown_House2/scripts.pory"
	clearflag FLAG_SAKU_KURA_HIDE_ESPEON_MASTERS_HOME
# 63 "data/maps/SakuTown_House2/scripts.pory"
	msgbox SakuTown_House2_EventScript_EspeonsMaster_Text_3
# 66 "data/maps/SakuTown_House2/scripts.pory"
	closemessage
# 68 "data/maps/SakuTown_House2/scripts.pory"
	delay 30
# 70 "data/maps/SakuTown_House2/scripts.pory"
	playse SE_DOOR
# 71 "data/maps/SakuTown_House2/scripts.pory"
	waitse
# 72 "data/maps/SakuTown_House2/scripts.pory"
	addobject 2
# 73 "data/maps/SakuTown_House2/scripts.pory"
	setobjectxy 2, 5, 7
# 74 "data/maps/SakuTown_House2/scripts.pory"
	turnobject 2, DIR_NORTH
# 77 "data/maps/SakuTown_House2/scripts.pory"
	applymovement 1, Common_Movement_FaceDown
# 78 "data/maps/SakuTown_House2/scripts.pory"
	applymovement 3, Common_Movement_FaceDown
# 79 "data/maps/SakuTown_House2/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
# 80 "data/maps/SakuTown_House2/scripts.pory"
	playse SE_PIN
# 81 "data/maps/SakuTown_House2/scripts.pory"
	applymovement 1, Common_Movement_ExclamationMark
# 82 "data/maps/SakuTown_House2/scripts.pory"
	applymovement 3, Common_Movement_ExclamationMark
# 83 "data/maps/SakuTown_House2/scripts.pory"
	delay 48
# 85 "data/maps/SakuTown_House2/scripts.pory"
	msgbox SakuTown_House2_EventScript_Reunited_Text_0
# 88 "data/maps/SakuTown_House2/scripts.pory"
	closemessage
# 91 "data/maps/SakuTown_House2/scripts.pory"
	switch VAR_FACING
# 92 "data/maps/SakuTown_House2/scripts.pory"
	case DIR_WEST, SakuTown_House2_EventScript_Reunited_3
# 94 "data/maps/SakuTown_House2/scripts.pory"
	case DIR_NORTH, SakuTown_House2_EventScript_Reunited_4
# 95 "data/maps/SakuTown_House2/scripts.pory"
	case DIR_SOUTH, SakuTown_House2_EventScript_Reunited_4
SakuTown_House2_EventScript_Reunited_1:
# 102 "data/maps/SakuTown_House2/scripts.pory"
	delay 40
# 104 "data/maps/SakuTown_House2/scripts.pory"
	playmoncry SPECIES_ESPEON, CRY_MODE_NORMAL
# 105 "data/maps/SakuTown_House2/scripts.pory"
	waitmoncry
# 107 "data/maps/SakuTown_House2/scripts.pory"
	msgbox SakuTown_House2_EventScript_Reunited_Text_1
# 112 "data/maps/SakuTown_House2/scripts.pory"
	closemessage
# 114 "data/maps/SakuTown_House2/scripts.pory"
	switch VAR_FACING
# 115 "data/maps/SakuTown_House2/scripts.pory"
	case DIR_WEST, SakuTown_House2_EventScript_Reunited_7
# 118 "data/maps/SakuTown_House2/scripts.pory"
	case DIR_NORTH, SakuTown_House2_EventScript_Reunited_8
# 121 "data/maps/SakuTown_House2/scripts.pory"
	case DIR_SOUTH, SakuTown_House2_EventScript_Reunited_9
SakuTown_House2_EventScript_Reunited_5:
# 125 "data/maps/SakuTown_House2/scripts.pory"
	delay 30
# 127 "data/maps/SakuTown_House2/scripts.pory"
	msgbox SakuTown_House2_EventScript_Reunited_Text_2
# 139 "data/maps/SakuTown_House2/scripts.pory"
	giveitem ITEM_THUNDER_STONE
	return

SakuTown_House2_EventScript_Reunited_3:
# 93 "data/maps/SakuTown_House2/scripts.pory"
	applymovement 2, SakuTown_House2_Movement_EspeonWalksUpSouth
	goto SakuTown_House2_EventScript_Reunited_1

SakuTown_House2_EventScript_Reunited_4:
# 96 "data/maps/SakuTown_House2/scripts.pory"
	applymovement 2, SakuTown_House2_Movement_EspeonWalksUpEast
# 97 "data/maps/SakuTown_House2/scripts.pory"
	turnobject 1, DIR_EAST
# 98 "data/maps/SakuTown_House2/scripts.pory"
	turnobject 3, DIR_WEST
# 99 "data/maps/SakuTown_House2/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	goto SakuTown_House2_EventScript_Reunited_1

SakuTown_House2_EventScript_Reunited_7:
# 116 "data/maps/SakuTown_House2/scripts.pory"
	turnobject 1, DIR_EAST
# 117 "data/maps/SakuTown_House2/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	goto SakuTown_House2_EventScript_Reunited_5

SakuTown_House2_EventScript_Reunited_8:
# 119 "data/maps/SakuTown_House2/scripts.pory"
	turnobject 1, DIR_SOUTH
# 120 "data/maps/SakuTown_House2/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	goto SakuTown_House2_EventScript_Reunited_5

SakuTown_House2_EventScript_Reunited_9:
# 122 "data/maps/SakuTown_House2/scripts.pory"
	turnobject 1, DIR_NORTH
# 123 "data/maps/SakuTown_House2/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	goto SakuTown_House2_EventScript_Reunited_5


SakuTown_House2_EventScript_Espeon::
# 144 "data/maps/SakuTown_House2/scripts.pory"
	lock
# 145 "data/maps/SakuTown_House2/scripts.pory"
	faceplayer
# 146 "data/maps/SakuTown_House2/scripts.pory"
	playmoncry SPECIES_ESPEON, CRY_MODE_NORMAL
# 147 "data/maps/SakuTown_House2/scripts.pory"
	msgbox SakuTown_House2_EventScript_Espeon_Text_0
# 150 "data/maps/SakuTown_House2/scripts.pory"
	waitmoncry
# 151 "data/maps/SakuTown_House2/scripts.pory"
	closemessage
# 152 "data/maps/SakuTown_House2/scripts.pory"
	release
	return


SakuTown_House2_EventScript_Sister::
# 157 "data/maps/SakuTown_House2/scripts.pory"
	lock
# 158 "data/maps/SakuTown_House2/scripts.pory"
	faceplayer
# 159 "data/maps/SakuTown_House2/scripts.pory"
	goto_if_set FLAG_SAKU_KURA_HIDE_ESPEON_MASTERS_HOME, SakuTown_House2_EventScript_Sister_2
# 165 "data/maps/SakuTown_House2/scripts.pory"
	msgbox SakuTown_House2_EventScript_Sister_Text_1
SakuTown_House2_EventScript_Sister_1:
# 170 "data/maps/SakuTown_House2/scripts.pory"
	closemessage
# 171 "data/maps/SakuTown_House2/scripts.pory"
	applymovement 3, Common_Movement_FaceOriginalDirection
# 172 "data/maps/SakuTown_House2/scripts.pory"
	release
	return

SakuTown_House2_EventScript_Sister_2:
# 160 "data/maps/SakuTown_House2/scripts.pory"
	msgbox SakuTown_House2_EventScript_Sister_Text_0
	goto SakuTown_House2_EventScript_Sister_1


# 176 "data/maps/SakuTown_House2/scripts.pory"
SakuTown_House2_Movement_EspeonWalksUpEast:
# 177 "data/maps/SakuTown_House2/scripts.pory"
	walk_fast_up
# 178 "data/maps/SakuTown_House2/scripts.pory"
	walk_fast_right
# 178 "data/maps/SakuTown_House2/scripts.pory"
	walk_fast_right
# 179 "data/maps/SakuTown_House2/scripts.pory"
	walk_fast_up
# 179 "data/maps/SakuTown_House2/scripts.pory"
	walk_fast_up
# 180 "data/maps/SakuTown_House2/scripts.pory"
	face_left
# 181 "data/maps/SakuTown_House2/scripts.pory"
	jump_in_place_left
# 181 "data/maps/SakuTown_House2/scripts.pory"
	jump_in_place_left
	step_end

# 185 "data/maps/SakuTown_House2/scripts.pory"
SakuTown_House2_Movement_EspeonWalksUpSouth:
# 186 "data/maps/SakuTown_House2/scripts.pory"
	walk_fast_up
# 187 "data/maps/SakuTown_House2/scripts.pory"
	walk_fast_right
# 188 "data/maps/SakuTown_House2/scripts.pory"
	walk_fast_up
# 189 "data/maps/SakuTown_House2/scripts.pory"
	jump_in_place_up
# 189 "data/maps/SakuTown_House2/scripts.pory"
	jump_in_place_up
	step_end

SakuTown_House2_EventScript_EspeonsMaster_Text_0:
# 16 "data/maps/SakuTown_House2/scripts.pory"
	.string "I hope Eevee comes home soon…$"

SakuTown_House2_EventScript_EspeonsMaster_Text_1:
# 23 "data/maps/SakuTown_House2/scripts.pory"
	.string "I hope Eevee comes home soon…\p"
	.string "What? Someone found my Eevee? Oh,\n"
	.string "please, can you tell them to bring it\l"
	.string "back?$"

SakuTown_House2_EventScript_EspeonsMaster_Text_2:
# 32 "data/maps/SakuTown_House2/scripts.pory"
	.string "… …$"

SakuTown_House2_EventScript_EspeonsMaster_Text_3:
# 39 "data/maps/SakuTown_House2/scripts.pory"
	.string "Where's my Eevee?$"

SakuTown_House2_EventScript_EspeonsMaster_Text_4:
# 50 "data/maps/SakuTown_House2/scripts.pory"
	.string "How are you doing? Espeon looks happy\n"
	.string "to see you!$"

SakuTown_House2_EventScript_Reunited_Text_0:
# 86 "data/maps/SakuTown_House2/scripts.pory"
	.string "Is… Is that Eevee?$"

SakuTown_House2_EventScript_Reunited_Text_1:
# 108 "data/maps/SakuTown_House2/scripts.pory"
	.string "It's you! It's really you! Oh, Eevee, I've\n"
	.string "missed you so much!\p"
	.string "… …\p"
	.string "Wait, you look a little different…$"

SakuTown_House2_EventScript_Reunited_Text_2:
# 128 "data/maps/SakuTown_House2/scripts.pory"
	.string "You say it was a woman from Kura Village\n"
	.string "that found him?\p"
	.string "She took such good care of him!\p"
	.string "His fur is so shiny and well-groomed,\n"
	.string "too…\p"
	.string "… …\p"
	.string "Looks like there are actually some nice\n"
	.string "people too in Kura Village…\p"
	.string "… …\p"
	.string "Anyway, thank you so much for helping\n"
	.string "me out. I'm so grateful.\p"
	.string "Please take this.$"

SakuTown_House2_EventScript_Espeon_Text_0:
# 148 "data/maps/SakuTown_House2/scripts.pory"
	.string "Eeeoon!$"

SakuTown_House2_EventScript_Sister_Text_0:
# 161 "data/maps/SakuTown_House2/scripts.pory"
	.string "My brother's been feeling really down\n"
	.string "lately.\p"
	.string "His precious Pokémon disappeared\n"
	.string "during the big storm we had a while ago.$"

SakuTown_House2_EventScript_Sister_Text_1:
# 166 "data/maps/SakuTown_House2/scripts.pory"
	.string "Thank you for your kindness! It's nice\n"
	.string "to see my brother smiling again.\p"
	.string "I wish I could thank whoever took such\n"
	.string "good care of Eevee, too!$"

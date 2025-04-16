SakuTown_House2_MapScripts::
	.byte 0


SakuTown_House2_EventScript_EspeonsMaster::
	lock
	faceplayer
	compare VAR_SAKU_KURA_QUEST_ESPEON_STATE, 0
	goto_if_eq SakuTown_House2_EventScript_EspeonsMaster_2
	compare VAR_SAKU_KURA_QUEST_ESPEON_STATE, 1
	goto_if_eq SakuTown_House2_EventScript_EspeonsMaster_3
	compare VAR_SAKU_KURA_QUEST_ESPEON_STATE, 2
	goto_if_eq SakuTown_House2_EventScript_EspeonsMaster_4
	compare VAR_SAKU_KURA_QUEST_ESPEON_STATE, 3
	goto_if_eq SakuTown_House2_EventScript_EspeonsMaster_5
	compare VAR_SAKU_KURA_QUEST_ESPEON_STATE, 4
	goto_if_eq SakuTown_House2_EventScript_EspeonsMaster_6
	compare VAR_SAKU_KURA_QUEST_ESPEON_STATE, 5
	goto_if_eq SakuTown_House2_EventScript_EspeonsMaster_7
SakuTown_House2_EventScript_EspeonsMaster_1:
	release
	return

SakuTown_House2_EventScript_EspeonsMaster_2:
	setnamedmon SPECIES_EEVEE
	speakername SakuTown_House2_EventScript_EspeonsMaster_Text_0
	msgbox SakuTown_House2_EventScript_EspeonsMaster_Text_1
	closemessage
	setvar VAR_SAKU_KURA_QUEST_ESPEON_STATE, 2
	goto SakuTown_House2_EventScript_EspeonsMaster_1

SakuTown_House2_EventScript_EspeonsMaster_3:
	setnamedmon SPECIES_EEVEE
	speakername SakuTown_House2_EventScript_EspeonsMaster_Text_0
	msgbox SakuTown_House2_EventScript_EspeonsMaster_Text_2
	closemessage
	setvar VAR_SAKU_KURA_QUEST_ESPEON_STATE, 3
	goto SakuTown_House2_EventScript_EspeonsMaster_1

SakuTown_House2_EventScript_EspeonsMaster_4:
	speakername SakuTown_House2_EventScript_EspeonsMaster_Text_0
	msgbox SakuTown_House2_EventScript_EspeonsMaster_Text_3
	closemessage
	goto SakuTown_House2_EventScript_EspeonsMaster_1

SakuTown_House2_EventScript_EspeonsMaster_5:
	speakername SakuTown_House2_EventScript_EspeonsMaster_Text_0
	msgbox SakuTown_House2_EventScript_EspeonsMaster_Text_4
	closemessage
	goto SakuTown_House2_EventScript_EspeonsMaster_1

SakuTown_House2_EventScript_EspeonsMaster_6:
	call SakuTown_House2_EventScript_Reunited
	goto SakuTown_House2_EventScript_EspeonsMaster_1

SakuTown_House2_EventScript_EspeonsMaster_7:
	goto_if_set FLAG_TEMP_1, SakuTown_House2_EventScript_EspeonsMaster_14
	goto_if_set FLAG_SAKU_ESPEON_QUEST_RECEIVED_EVO_STONE, SakuTown_House2_EventScript_EspeonsMaster_17
	call SakuTown_House2_EventScript_GiveEvoStone
	goto SakuTown_House2_EventScript_EspeonsMaster_1

SakuTown_House2_EventScript_EspeonsMaster_14:
	speakername SakuTown_House2_EventScript_EspeonsMaster_Text_0
	msgbox SakuTown_House2_EventScript_EspeonsMaster_Text_5
	closemessage
	goto SakuTown_House2_EventScript_EspeonsMaster_1

SakuTown_House2_EventScript_EspeonsMaster_17:
	setnamedmon SPECIES_ESPEON
	speakername SakuTown_House2_EventScript_EspeonsMaster_Text_0
	msgbox SakuTown_House2_EventScript_EspeonsMaster_Text_6
	closemessage
	goto SakuTown_House2_EventScript_EspeonsMaster_1


SakuTown_House2_EventScript_Reunited::
	setvar VAR_SAKU_KURA_QUEST_ESPEON_STATE, 5
	clearflag FLAG_SAKU_KURA_HIDE_ESPEON_MASTERS_HOME
	speakername SakuTown_House2_EventScript_EspeonsMaster_Text_0
	msgbox SakuTown_House2_EventScript_EspeonsMaster_Text_4
	closemessage
	delay 30
	playse SE_DOOR
	waitse
	addobject 2
	setobjectxy 2, 5, 7
	turnobject 2, DIR_NORTH
	applymovement 1, Common_Movement_FaceDown
	applymovement 3, Common_Movement_FaceDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	applymovement 3, Common_Movement_ExclamationMark
	waitmovement 0
	delay 48
	msgbox SakuTown_House2_EventScript_Reunited_Text_0
	closemessage
	switch VAR_FACING
	case DIR_WEST, SakuTown_House2_EventScript_Reunited_3
	case DIR_NORTH, SakuTown_House2_EventScript_Reunited_4
	case DIR_SOUTH, SakuTown_House2_EventScript_Reunited_5
SakuTown_House2_EventScript_Reunited_1:
	delay 40
	setseenmon SPECIES_ESPEON
	playmoncry SPECIES_ESPEON, CRY_MODE_NORMAL
	waitmoncry
	speakername SakuTown_House2_EventScript_EspeonsMaster_Text_0
	msgbox SakuTown_House2_EventScript_Reunited_Text_1
	closemessage
	switch VAR_FACING
	case DIR_WEST, SakuTown_House2_EventScript_Reunited_8
	case DIR_NORTH, SakuTown_House2_EventScript_Reunited_9
	case DIR_SOUTH, SakuTown_House2_EventScript_Reunited_10
SakuTown_House2_EventScript_Reunited_6:
	delay 30
	speakername SakuTown_House2_EventScript_EspeonsMaster_Text_0
	msgbox SakuTown_House2_EventScript_Reunited_Text_2
	call SakuTown_House2_EventScript_GiveEvoStone
	return

SakuTown_House2_EventScript_Reunited_3:
	applymovement 2, SakuTown_House2_Movement_EspeonWalksUpSouth
	goto SakuTown_House2_EventScript_Reunited_1

SakuTown_House2_EventScript_Reunited_4:
	applymovement 2, SakuTown_House2_Movement_EspeonWalksUpEast
	turnobject 1, DIR_EAST
	turnobject 3, DIR_WEST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	goto SakuTown_House2_EventScript_Reunited_1

SakuTown_House2_EventScript_Reunited_5:
	applymovement 2, SakuTown_House2_Movement_EspeonWalksUpEast
	turnobject 1, DIR_EAST
	turnobject 3, DIR_WEST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	goto SakuTown_House2_EventScript_Reunited_1

SakuTown_House2_EventScript_Reunited_8:
	turnobject 1, DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	goto SakuTown_House2_EventScript_Reunited_6

SakuTown_House2_EventScript_Reunited_9:
	turnobject 1, DIR_SOUTH
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	goto SakuTown_House2_EventScript_Reunited_6

SakuTown_House2_EventScript_Reunited_10:
	turnobject 1, DIR_NORTH
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	goto SakuTown_House2_EventScript_Reunited_6


SakuTown_House2_EventScript_GiveEvoStone::
	msgbox SakuTown_House2_EventScript_GiveEvoStone_Text_0
	closemessage
	dynmultichoice 16, 6, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SakuTown_House2_EventScript_GiveEvoStone_Text_1, SakuTown_House2_EventScript_GiveEvoStone_Text_2, SakuTown_House2_EventScript_GiveEvoStone_Text_3
	speakername SakuTown_House2_EventScript_EspeonsMaster_Text_0
	switch VAR_RESULT
	case 0, SakuTown_House2_EventScript_GiveEvoStone_3
	case 1, SakuTown_House2_EventScript_GiveEvoStone_4
	case 2, SakuTown_House2_EventScript_GiveEvoStone_5
SakuTown_House2_EventScript_GiveEvoStone_1:
	closemessage
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
	setflag FLAG_SAKU_ESPEON_QUEST_RECEIVED_EVO_STONE
	release
	return

SakuTown_House2_EventScript_GiveEvoStone_3:
	giveitem ITEM_FIRE_STONE
	goto SakuTown_House2_EventScript_GiveEvoStone_1

SakuTown_House2_EventScript_GiveEvoStone_4:
	giveitem ITEM_WATER_STONE
	goto SakuTown_House2_EventScript_GiveEvoStone_1

SakuTown_House2_EventScript_GiveEvoStone_5:
	giveitem ITEM_THUNDER_STONE
	goto SakuTown_House2_EventScript_GiveEvoStone_1


SakuTown_House2_EventScript_Espeon::
	lock
	faceplayer
	setseenmon SPECIES_ESPEON
	playmoncry SPECIES_ESPEON, CRY_MODE_NORMAL
	setspeakertomonname SPECIES_ESPEON
	msgbox SakuTown_House2_EventScript_Espeon_Text_0
	waitmoncry
	closemessage
	release
	return


SakuTown_House2_EventScript_Sister::
	lock
	faceplayer
	speakername SakuTown_House2_EventScript_Sister_Text_0
	goto_if_set FLAG_SAKU_KURA_HIDE_ESPEON_MASTERS_HOME, SakuTown_House2_EventScript_Sister_2
	msgbox SakuTown_House2_EventScript_Sister_Text_2
	closemessage
SakuTown_House2_EventScript_Sister_1:
	release
	return

SakuTown_House2_EventScript_Sister_2:
	msgbox SakuTown_House2_EventScript_Sister_Text_1
	closemessage
	applymovement 3, Common_Movement_FaceOriginalDirection
	goto SakuTown_House2_EventScript_Sister_1


SakuTown_House2_Movement_EspeonWalksUpEast:
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	face_left
	jump_in_place_left
	jump_in_place_left
	step_end

SakuTown_House2_Movement_EspeonWalksUpSouth:
	walk_fast_up
	walk_fast_right
	walk_fast_up
	jump_in_place_up
	jump_in_place_up
	step_end

SakuTown_House2_EventScript_EspeonsMaster_Text_0:
	.string "Boy$"

SakuTown_House2_EventScript_EspeonsMaster_Text_1:
	.string "I hope Eevee comes home soon…$"

SakuTown_House2_EventScript_EspeonsMaster_Text_2:
	.string "I hope Eevee comes home soon…\p"
	.string "What? Someone found my Eevee? Oh,\n"
	.string "please, can you tell them to bring it\l"
	.string "back?$"

SakuTown_House2_EventScript_EspeonsMaster_Text_3:
	.string "… …$"

SakuTown_House2_EventScript_EspeonsMaster_Text_4:
	.string "Where's my Eevee?$"

SakuTown_House2_EventScript_EspeonsMaster_Text_5:
	.string "Thanks again!$"

SakuTown_House2_EventScript_EspeonsMaster_Text_6:
	.string "How are you doing? Espeon looks\n"
	.string "happy to see you!$"

SakuTown_House2_EventScript_Reunited_Text_0:
	.string "Is… Is that Eevee?$"

SakuTown_House2_EventScript_Reunited_Text_1:
	.string "It's you! It's really you! Oh, Eevee,\n"
	.string "I've missed you so much!\p"
	.string "… …\p"
	.string "Wait, you look a little different…$"

SakuTown_House2_EventScript_Reunited_Text_2:
	.string "You say it was a woman from Kura\n"
	.string "Village that found him?\p"
	.string "She took such good care of him!\p"
	.string "His fur is so shiny and well-groomed,\n"
	.string "too…\p"
	.string "… …\p"
	.string "Looks like there are actually some\n"
	.string "nice people too in Kura Village…\p"
	.string "… …\p"
	.string "Anyway, thank you so much for helping\n"
	.string "me out. I'm so grateful.\p"
	.string "As a thanks, you can have your pick\n"
	.string "from my cool rock collection!$"

SakuTown_House2_EventScript_GiveEvoStone_Text_0:
	.string "Which rock would you like?$"

SakuTown_House2_EventScript_GiveEvoStone_Text_1:
	.string "The red rock$"

SakuTown_House2_EventScript_GiveEvoStone_Text_2:
	.string "The blue rock$"

SakuTown_House2_EventScript_GiveEvoStone_Text_3:
	.string "The yellow rock$"

SakuTown_House2_EventScript_Espeon_Text_0:
	.string "Eeeoon!$"

SakuTown_House2_EventScript_Sister_Text_0:
	.string "Girl$"

SakuTown_House2_EventScript_Sister_Text_1:
	.string "My brother's been feeling really down\n"
	.string "lately.\p"
	.string "His precious Pokémon disappeared\n"
	.string "during the big storm we had a while\l"
	.string "ago.$"

SakuTown_House2_EventScript_Sister_Text_2:
	.string "Thank you for your kindness! It's\n"
	.string "nice to see my brother smiling again.\p"
	.string "I wish I could thank whoever took\n"
	.string "such good care of Eevee, too!$"

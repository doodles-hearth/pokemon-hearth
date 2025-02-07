MaguroHarbor_Refuge_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MaguroHarbor_Refuge_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

MaguroHarbor_Refuge_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setrespawn HEAL_LOCATION_MAGURO_HARBOR
	return


MaguroHarbor_Refuge_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse_CutTheBullshit
	waitmessage
	waitbuttonpress
	release
	end


MaguroHarbor_Refuge_EventScript_Hariko::
	lock
	faceplayer
	speakername MaguroHarbor_Refuge_EventScript_Hariko_Text_0
	msgbox MaguroHarbor_Refuge_EventScript_Hariko_Text_1
	closemessage
	applymovement 4, MaguroHarbor_Refuge_EventScript_Hariko_Movement_0
	waitmovement 4
	delay 60
	playse SE_LEDGE
	applymovement 5, MaguroHarbor_Refuge_EventScript_Hariko_Movement_1
	waitmovement 5
	playmoncry SPECIES_SLOWPOKE, CRY_MODE_NORMAL
	speakername MaguroHarbor_Refuge_EventScript_Hariko_Text_2
	msgbox MaguroHarbor_Refuge_EventScript_Hariko_Text_3
	closemessage
	applymovement 4, MaguroHarbor_Refuge_EventScript_Hariko_Movement_2
	waitmovement 4
	speakername MaguroHarbor_Refuge_EventScript_Hariko_Text_0
	msgbox MaguroHarbor_Refuge_EventScript_Hariko_Text_4
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, MaguroHarbor_Refuge_EventScript_Hariko_Text_5, MaguroHarbor_Refuge_EventScript_Hariko_Text_6
	closemessage
	switch VAR_RESULT
	case 0, MaguroHarbor_Refuge_EventScript_Hariko_3
	case 1, MaguroHarbor_Refuge_EventScript_Hariko_3
MaguroHarbor_Refuge_EventScript_Hariko_1:
	setflag FLAG_TALKED_TO_HARIKO_IN_MAGURO_REFUGE
	release
	return

MaguroHarbor_Refuge_EventScript_Hariko_3:
	speakername MaguroHarbor_Refuge_EventScript_Hariko_Text_0
	msgbox MaguroHarbor_Refuge_EventScript_Hariko_Text_7
	closemessage
	goto MaguroHarbor_Refuge_EventScript_Hariko_1


MaguroHarbor_Refuge_EventScript_Slowpoke::
	lock
	faceplayer
	playmoncry SPECIES_SLOWPOKE, CRY_MODE_NORMAL
	goto_if_set FLAG_TALKED_TO_HARIKO_IN_MAGURO_REFUGE, MaguroHarbor_Refuge_EventScript_Slowpoke_2
	setspeakertomonname SPECIES_SLOWPOKE
MaguroHarbor_Refuge_EventScript_Slowpoke_1:
	msgbox MaguroHarbor_Refuge_EventScript_Slowpoke_Text_0
	waitmoncry
	closemessage
	release
	return

MaguroHarbor_Refuge_EventScript_Slowpoke_2:
	speakername MaguroHarbor_Refuge_EventScript_Hariko_Text_2
	goto MaguroHarbor_Refuge_EventScript_Slowpoke_1


MaguroHarbor_Refuge_EventScript_Hariko_Movement_0:
	walk_in_place_fast_left
	step_end

MaguroHarbor_Refuge_EventScript_Hariko_Movement_1:
	jump_in_place_down
	step_end

MaguroHarbor_Refuge_EventScript_Hariko_Movement_2:
	walk_in_place_fast_down
	step_end

MaguroHarbor_Refuge_EventScript_Hariko_Text_0:
	.string "Hariko$"

MaguroHarbor_Refuge_EventScript_Hariko_Text_1:
	.string "Oh, hello there, {PLAYER}.\n"
	.string "Fancy meeting you here, as they say.\p"
	.string "I assume you are here to challenge\n"
	.string "the Maguro Harbor Dojo?\p"
	.string "Me? I am not particularly interested\n"
	.string "in becoming a great wielder.\p"
	.string "I travel to learn as much as I can\n"
	.string "about Pokémon!\p"
	.string "You've not met my companion yet, have\n"
	.string "you? Meet Bean!$"

MaguroHarbor_Refuge_EventScript_Hariko_Text_2:
	.string "Bean$"

MaguroHarbor_Refuge_EventScript_Hariko_Text_3:
	.string "Hurr…$"

MaguroHarbor_Refuge_EventScript_Hariko_Text_4:
	.string "Bean is a little slow, but he is happy\n"
	.string "to meet you!\p"
	.string "He may not look like a fighter, but he\n"
	.string "enjoys battles, too. Would you like to\l"
	.string "have a friendly battle, Bean against\l"
	.string "one of your Pokémon?$"

MaguroHarbor_Refuge_EventScript_Hariko_Text_5:
	.string "Yes!$"

MaguroHarbor_Refuge_EventScript_Hariko_Text_6:
	.string "Maybe later.$"

MaguroHarbor_Refuge_EventScript_Hariko_Text_7:
	.string "No problem. I will be here a while\n"
	.string "before I continue my journey.$"

MaguroHarbor_Refuge_EventScript_Slowpoke_Text_0:
	.string "Duh…$"

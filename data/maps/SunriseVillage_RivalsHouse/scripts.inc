SunriseVillage_RivalsHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SunriseVillage_RivalsHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

SunriseVillage_RivalsHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	compare VAR_SUNRISE_VILLAGE_INTRO_STATE, 7
	goto_if_ne SunriseVillage_RivalsHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return

SunriseVillage_RivalsHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	setflag FLAG_TEMP_1
	return


SunriseVillage_RivalsHouse_EventScript_Woman::
	lock
	faceplayer
	speakername SunriseVillage_RivalsHouse_EventScript_Woman_Text_0
	compare VAR_SUNRISE_VILLAGE_INTRO_STATE, 8
	goto_if_ge SunriseVillage_RivalsHouse_EventScript_Woman_2
	msgbox SunriseVillage_RivalsHouse_EventScript_Woman_Text_2
SunriseVillage_RivalsHouse_EventScript_Woman_1:
	release
	return

SunriseVillage_RivalsHouse_EventScript_Woman_2:
	msgbox SunriseVillage_RivalsHouse_EventScript_Woman_Text_1
	goto SunriseVillage_RivalsHouse_EventScript_Woman_1


SunriseVillage_RivalsHouse_EventScript_Natsuki::
	lock
	applymovement 5, Common_Movement_FaceUp
	waitmovement 0
	goto_if_set FLAG_TEMP_2, SunriseVillage_RivalsHouse_EventScript_Natsuki_2
	speakername SunriseVillage_RivalsHouse_EventScript_Natsuki_Text_0
	msgbox SunriseVillage_RivalsHouse_EventScript_Natsuki_Text_2
	closemessage
	delay 48
	faceplayer
	speakername SunriseVillage_RivalsHouse_EventScript_Natsuki_Text_0
	msgbox SunriseVillage_RivalsHouse_EventScript_Natsuki_Text_3
	closemessage
	applymovement 5, Common_Movement_FaceUp
	waitmovement 0
	setflag FLAG_TEMP_2
SunriseVillage_RivalsHouse_EventScript_Natsuki_1:
	release
	return

SunriseVillage_RivalsHouse_EventScript_Natsuki_2:
	speakername SunriseVillage_RivalsHouse_EventScript_Natsuki_Text_0
	msgbox SunriseVillage_RivalsHouse_EventScript_Natsuki_Text_1
	closemessage
	setnamedmon SPECIES_JOLTIK
	goto SunriseVillage_RivalsHouse_EventScript_Natsuki_1


SunriseVillage_RivalsHouse_EventScript_Man::
	lock
	faceplayer
	speakername SunriseVillage_RivalsHouse_EventScript_Man_Text_0
	compare VAR_SUNRISE_VILLAGE_INTRO_STATE, 7
	goto_if_eq SunriseVillage_RivalsHouse_EventScript_Man_2
	compare VAR_SUNRISE_VILLAGE_INTRO_STATE, 8
	goto_if_ge SunriseVillage_RivalsHouse_EventScript_Man_3
	msgbox SunriseVillage_RivalsHouse_EventScript_Man_Text_3
SunriseVillage_RivalsHouse_EventScript_Man_1:
	release
	return

SunriseVillage_RivalsHouse_EventScript_Man_2:
	msgbox SunriseVillage_RivalsHouse_EventScript_Man_Text_1
	goto SunriseVillage_RivalsHouse_EventScript_Man_1

SunriseVillage_RivalsHouse_EventScript_Man_3:
	msgbox SunriseVillage_RivalsHouse_EventScript_Man_Text_2
	goto SunriseVillage_RivalsHouse_EventScript_Man_1


SunriseVillage_RivalsHouse_EventScript_Meowth::
	setseenmon SPECIES_MEOWTH
	setspeakertomonname SPECIES_MEOWTH
	msgbox SunriseVillage_RivalsHouse_EventScript_Meowth_Text_0, MSGBOX_NPC
	return


SunriseVillage_RivalsHouse_EventScript_Meowth2::
	lock
	faceplayer
	setseenmon SPECIES_MEOWTH
	playmoncry SPECIES_MEOWTH, CRY_MODE_NORMAL
	setspeakertomonname SPECIES_MEOWTH
	msgbox SunriseVillage_RivalsHouse_EventScript_Meowth2_Text_0
	waitmoncry
	release
	end


SunriseVillage_RivalsHouse_EventScript_Woman_Text_0:
	.string "Natsuki's mom$"

SunriseVillage_RivalsHouse_EventScript_Woman_Text_1:
	.string "The house feels a little empty\n"
	.string "now that Natsuki has left home.\p"
	.string "I'm glad for our Pokémon and the\n"
	.string "companionship they provide us.$"

SunriseVillage_RivalsHouse_EventScript_Woman_Text_2:
	.string "Good morning, {PLAYER}!\n"
	.string "Today's the big day, huh?\p"
	.string "Break a leg! Don't talk to strangers!$"

SunriseVillage_RivalsHouse_EventScript_Natsuki_Text_0:
	.string "Natsuki$"

SunriseVillage_RivalsHouse_EventScript_Natsuki_Text_1:
	.string "Region map, check…\n"
	.string "Joltik plushie, check…$"

SunriseVillage_RivalsHouse_EventScript_Natsuki_Text_2:
	.string "Poké Balls, check…\n"
	.string "Medicine, check…\l"
	.string "Spare pair of underwear, check…$"

SunriseVillage_RivalsHouse_EventScript_Natsuki_Text_3:
	.string "Oh, hey, {PLAYER}. I'm just sorting\n"
	.string "out my stuff for the journey.\p"
	.string "I'm traveling as light as possible!\p"
	.string "See you around, yeah?$"

SunriseVillage_RivalsHouse_EventScript_Man_Text_0:
	.string "Natsuki's dad$"

SunriseVillage_RivalsHouse_EventScript_Man_Text_1:
	.string "Hello, {PLAYER}.\n"
	.string "How is your adventure going?\p"
	.string "Make sure you come back home\n"
	.string "to see your sister sometimes,\l"
	.string "I'm sure she misses you.$"

SunriseVillage_RivalsHouse_EventScript_Man_Text_2:
	.string "It was tough when Natsuki and I\n"
	.string "first moved all the way down here.\p"
	.string "Things are better now.\n"
	.string "We both needed a fresh start.$"

SunriseVillage_RivalsHouse_EventScript_Man_Text_3:
	.string "Hello, {PLAYER}! How are you doing?\n"
	.string "Off to some trouble with Natsuki, I\l"
	.string "bet?$"

SunriseVillage_RivalsHouse_EventScript_Meowth_Text_0:
	.string "Purrr…$"

SunriseVillage_RivalsHouse_EventScript_Meowth2_Text_0:
	.string "Meow!$"

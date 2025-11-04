Silveridge_House1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Silveridge_House1_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Silveridge_House1_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	getweekday
	switch VAR_RESULT
	case WEEKDAY_TUE, Silveridge_House1_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
	case WEEKDAY_THU, Silveridge_House1_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
	case WEEKDAY_SAT, Silveridge_House1_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
	return

Silveridge_House1_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
	setflag FLAG_TEMP_1
	return


Silveridge_House1_EventScript_Woman::
	lock
	faceplayer
	setspeaker SP_NAME_WOMAN
	goto_if_set FLAG_TEMP_1, Silveridge_House1_EventScript_Woman_2
	msgbox Silveridge_House1_EventScript_Woman_Text_1
Silveridge_House1_EventScript_Woman_1:
	closemessage
	release
	return

Silveridge_House1_EventScript_Woman_2:
	msgbox Silveridge_House1_EventScript_Woman_Text_0
	goto Silveridge_House1_EventScript_Woman_1


Silveridge_House1_EventScript_FirebringerFangirl::
	lock
	faceplayer
	setspeaker SP_NAME_GIRL
	msgbox Silveridge_House1_EventScript_FirebringerFangirl_Text_0
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setnamedmon SPECIES_SLUGMA
	setdescribedmon SPECIES_SLUGMA
	release
	return


Silveridge_House1_EventScript_Sandslash::
	lock
	faceplayer
	setseenmon SPECIES_SANDSLASH
	playmoncry SPECIES_SANDSLASH, CRY_MODE_NORMAL
	setspeakertomonname SPECIES_SANDSLASH
	msgbox Silveridge_House1_EventScript_Sandslash_Text_0
	waitmoncry
	closemessage
	release
	return


Silveridge_House1_EventScript_Man::
	lock
	faceplayer
	setspeaker SP_NAME_MINER
	goto_if_set FLAG_OBTAINED_EVERSTONE, Silveridge_House1_EventScript_Man_2
	msgbox Silveridge_House1_EventScript_Man_Text_1
	closemessage
	giveitem ITEM_EVERSTONE
	setflag FLAG_OBTAINED_EVERSTONE
	setspeaker SP_NAME_MINER
	msgbox Silveridge_House1_EventScript_Man_Text_2
	closemessage
Silveridge_House1_EventScript_Man_1:
	release
	return

Silveridge_House1_EventScript_Man_2:
	msgbox Silveridge_House1_EventScript_Man_Text_0
	closemessage
	goto Silveridge_House1_EventScript_Man_1


Silveridge_House1_EventScript_Woman_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_MOUNTAIN_WOMAN_1 EMOTE_NORMAL}I wonder where my daughter is at.\n"
	.string "I bet the Firebringers are in town.$"

Silveridge_House1_EventScript_Woman_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_MOUNTAIN_WOMAN_1 EMOTE_NORMAL}You came all the way from Kura Village?\nYou have good legs!$"

Silveridge_House1_EventScript_FirebringerFangirl_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_MOUNTAIN_GIRL_1 EMOTE_NORMAL}It gets pretty cold here when the\nwind blows strong into the valley.\p"
	.string "I don't know what we would do\nwithout those brave Firebringers.\p"
	.string "They carry live Slugma on their back all\nthe way down from Mt Kazan to here!\p"
	.string "Slugma cools and hardens up fast, so\nthey basically run the whole way down!\lI could never!\p"
	.string "Sigh… I hope a handsome Firebringer\nnotices me one day…$"

Silveridge_House1_EventScript_Sandslash_Text_0:
	.string "Sahaaah!$"

Silveridge_House1_EventScript_Man_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_MINER EMOTE_NORMAL}You think some Pokémon prefer to\n"
	.string "remain small forever?$"

Silveridge_House1_EventScript_Man_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_MINER EMOTE_NORMAL}My job is to mine ore in Silver Tunnel,\nall day long.\lI love it!\p"
	.string "Wouldn't trade it for the world.\nI'm fine being a simple miner forever.\p"
	.string "Speaking of… I often find interesting\nrocks in there.\lLook at this!$"

Silveridge_House1_EventScript_Man_Text_2:
	.string "{CREATE_MUGSHOT MUGSHOT_MINER EMOTE_NORMAL}Apparently as long as a Pokémon holds\non to this stone, it'll stop growing.\p"
	.string "Sandy here is already fully grown,\nso I don't need it.$"

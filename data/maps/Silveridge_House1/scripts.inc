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
	msgbox Silveridge_House1_EventScript_Woman_Text_0
	closemessage
	release
	return


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
	setnamedmon SPECIES_SANDSLASH
Silveridge_House1_EventScript_Man_1:
	release
	return

Silveridge_House1_EventScript_Man_2:
	msgbox Silveridge_House1_EventScript_Man_Text_0
	closemessage
	goto Silveridge_House1_EventScript_Man_1


Silveridge_House1_EventScript_Woman_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_MOUNTAIN_WOMAN_1 EMOTE_NORMAL}Oh, you came all the way from Kura\n"
	.string "Village? You have good legs!$"

Silveridge_House1_EventScript_FirebringerFangirl_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_MOUNTAIN_GIRL_1 EMOTE_NORMAL}This place gets pretty cold,\n"
	.string "especially when the winds blow strong\l"
	.string "into the valley.\p"
	.string "I don't know what we would do without\n"
	.string "those brave Firebringers.\p"
	.string "They bring us live Slugma, carrying\n"
	.string "them on their back all the way down Mt\l"
	.string "Kazan!\p"
	.string "Slugma cools and hardens up pretty\n"
	.string "fast, so they basically run the whole\l"
	.string "way down! I could never!\p"
	.string "Sigh… I hope a handsome Firebringer\n"
	.string "notices me one day…$"

Silveridge_House1_EventScript_Sandslash_Text_0:
	.string "Sahaaah!$"

Silveridge_House1_EventScript_Man_Text_0:
	.string "You think some Pokémon prefer to\n"
	.string "remain small forever?$"

Silveridge_House1_EventScript_Man_Text_1:
	.string "My job is to mine ore in Silver Tunnel,\n"
	.string "all day long.\p"
	.string "I love it! I wouldn't trade it for the\n"
	.string "world. I'm fine with being a simple\l"
	.string "miner forever.\p"
	.string "Speaking of… I often find interesting\n"
	.string "rocks in there. Look at this!$"

Silveridge_House1_EventScript_Man_Text_2:
	.string "Apparently as long as a Pokémon holds\n"
	.string "on to this stone, it'll stop growing.\p"
	.string "My helper Sandslash is already fully\n"
	.string "grown, so I don't need it.$"

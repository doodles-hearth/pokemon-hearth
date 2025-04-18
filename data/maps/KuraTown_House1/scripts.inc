KuraTown_House1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, KuraTown_House1_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

KuraTown_House1_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setrespawn HEAL_LOCATION_KURA_TOWN
	return


KuraTown_House1_OldWoman::
	lock
	faceplayer
	speakername KuraTown_House1_OldWoman_Text_0
	msgbox KuraTown_House1_OldWoman_Text_1
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	speakername KuraTown_House1_OldWoman_Text_0
	msgbox KuraTown_House1_OldWoman_Text_2
	closemessage
	release
	return


KuraTown_House1_OldWomansSon::
	speakername KuraTown_House1_OldWomansSon_Text_0
	msgbox KuraTown_House1_OldWomansSon_Text_1, MSGBOX_NPC
	return


KuraTown_House1_Growlithe::
	lock
	faceplayer
	setseenmon SPECIES_GROWLITHE
	setspeakertomonname SPECIES_GROWLITHE
	playmoncry SPECIES_GROWLITHE, CRY_MODE_NORMAL
	msgbox KuraTown_House1_Growlithe_Text_0
	waitmoncry
	release
	return


KuraTown_House1_OldWoman_Text_0:
	.string "Old woman$"

KuraTown_House1_OldWoman_Text_1:
	.string "You look like you're tired, young one.\n"
	.string "Please rest a while.$"

KuraTown_House1_OldWoman_Text_2:
	.string "I wish you strength on your journey.$"

KuraTown_House1_OldWomansSon_Text_0:
	.string "Guy$"

KuraTown_House1_OldWomansSon_Text_1:
	.string "The Pokémon league organization\n"
	.string "didn't see fit to build a Pokémon\l"
	.string "refuge in our village, but those jerks\l"
	.string "over at Saku Village won't let us use\l"
	.string "theirs.\p"
	.string "So my mother has to work hard to heal\n"
	.string "all the villager's Pokémon.\p"
	.string "It's not fair!$"

KuraTown_House1_Growlithe_Text_0:
	.string "Wah!$"

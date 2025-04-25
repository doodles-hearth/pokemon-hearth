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
	compare VAR_SAKU_KURA_QUEST_SCYTHER_STATE, 2
	goto_if_eq KuraTown_House1_OldWoman_2
	call OldWomanRegularScript
KuraTown_House1_OldWoman_1:
	release
	return

KuraTown_House1_OldWoman_2:
	call OldWomanQuestScript
	goto KuraTown_House1_OldWoman_1


OldWomanRegularScript:
	msgbox OldWomanRegularScript_Text_0
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	speakername KuraTown_House1_OldWoman_Text_0
	msgbox OldWomanRegularScript_Text_1
	closemessage
	return


OldWomanQuestScript:
	msgbox OldWomanQuestScript_Text_0
	waitmessage
	closemessage
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

OldWomanRegularScript_Text_0:
	.string "You look like you're tired, young one.\n"
	.string "Please rest a while.$"

OldWomanRegularScript_Text_1:
	.string "I wish you strength on your journey.$"

OldWomanQuestScript_Text_0:
	.string "Hello, dearie. Do you need to rest\n"
	.string "yourself and your Pokémon?\p"
	.string "…\p"
	.string "I see… Can you take me to the ill\n"
	.string "Pokémon?$"

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

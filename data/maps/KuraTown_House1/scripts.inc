KuraTown_House1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, KuraTown_House1_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

KuraTown_House1_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setrespawn HEAL_LOCATION_KURA_TOWN
	compare VAR_SAKU_KURA_QUEST_SCYTHER_STATE, 4
	goto_if_lt KuraTown_House1_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	setvar VAR_SAKU_KURA_QUEST_SCYTHER_STATE, 5
	return

KuraTown_House1_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	return


KuraTown_House1_OldWoman::
	lock
	faceplayer
	speakername KuraTown_House1_OldWoman_Text_0
	switch VAR_SAKU_KURA_QUEST_SCYTHER_STATE
	case 2, KuraTown_House1_OldWoman_3
	case 3, KuraTown_House1_OldWoman_4
	case 4, KuraTown_House1_OldWoman_5
	case 5, KuraTown_House1_OldWoman_6
	case 6, KuraTown_House1_OldWoman_7
	call OldWomanRegularScript
KuraTown_House1_OldWoman_1:
	release
	return

KuraTown_House1_OldWoman_3:
	call OldWomanQuestScript
	goto KuraTown_House1_OldWoman_1

KuraTown_House1_OldWoman_4:
	call OldWomanQuest2Script
	goto KuraTown_House1_OldWoman_1

KuraTown_House1_OldWoman_5:
	msgbox KuraTown_House1_OldWoman_Text_1
	waitmessage
	closemessage
	goto KuraTown_House1_OldWoman_1

KuraTown_House1_OldWoman_6:
	setvar VAR_SAKU_KURA_QUEST_SCYTHER_STATE, 6
	msgbox KuraTown_House1_OldWoman_Text_2
	waitmessage
	closemessage
	giveitem ITEM_SPECIAL_MEDICINE, 1
	setvar VAR_SAKU_KURA_QUEST_SCYTHER_STATE, 6
	goto KuraTown_House1_OldWoman_1

KuraTown_House1_OldWoman_7:
	msgbox KuraTown_House1_OldWoman_Text_3
	waitmessage
	closemessage
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
	mcdialogue OldWomanQuestScript_Text_1
	msgbox OldWomanQuestScript_Text_2
	mcdialogue OldWomanQuestScript_Text_3
	msgbox OldWomanQuestScript_Text_4
	waitmessage
	closemessage
	applymovement 1, OldWomanQuestScript_Movement_0
	waitmovement 0
	speakername KuraTown_House1_OldWoman_Text_0
	msgbox OldWomanQuestScript_Text_5
	waitmessage
	closemessage
	mcdialogue OldWomanQuestScript_Text_6, OldWomanQuestScript_Text_7, OldWomanQuestScript_Text_8
	speakername KuraTown_House1_OldWoman_Text_0
	msgbox OldWomanQuestScript_Text_9
	waitmessage
	closemessage
	setvar VAR_SAKU_KURA_QUEST_SCYTHER_STATE, 3
	return


OldWomanQuest2Script::
	checkitem ITEM_FISHCAKE, 1
	copyvar VAR_TEMP_0, VAR_RESULT
	checkitem ITEM_ORAN_BERRY, 1
	copyvar VAR_TEMP_1, VAR_RESULT
	checkitem ITEM_REVIVAL_POWDER, 1
	copyvar VAR_TEMP_2, VAR_RESULT
	msgbox OldWomanQuest2Script_Text_0
	compare VAR_TEMP_0, 1
	goto_if_ge OldWomanQuest2Script_4
OldWomanQuest2Script_2:
	msgbox OldWomanQuest2Script_Text_2
	waitmessage
	closemessage
	return

OldWomanQuest2Script_1:
	applymovement 1, OldWomanQuest2Script_Movement_0
	playse SE_PIN
	waitmovement 0
	msgbox OldWomanQuest2Script_Text_1
	waitmessage
	closemessage
	setvar VAR_SAKU_KURA_QUEST_SCYTHER_STATE, 4
	return

OldWomanQuest2Script_3:
	compare VAR_TEMP_2, 1
	goto_if_ge OldWomanQuest2Script_1
	goto OldWomanQuest2Script_2

OldWomanQuest2Script_4:
	compare VAR_TEMP_1, 1
	goto_if_ge OldWomanQuest2Script_3
	goto OldWomanQuest2Script_2


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


OldWomanQuestScript_Movement_0:
	face_away_player
	delay_16
	delay_16
	delay_16
	face_player
	step_end

OldWomanQuest2Script_Movement_0:
	emote_exclamation_mark
	delay_16
	step_end

KuraTown_House1_OldWoman_Text_0:
	.string "Old woman$"

KuraTown_House1_OldWoman_Text_1:
	.string "Come back later for the medicine.$"

KuraTown_House1_OldWoman_Text_2:
	.string "It's good to see you! I've finished\n"
	.string "the medicine. Here, take it to the\l"
	.string "ailing Pokémon. Once it drinks it, it\l"
	.string "should feel good as new.$"

KuraTown_House1_OldWoman_Text_3:
	.string "Once the ill Pokémon drinks the\n"
	.string "medicine I gave you, it should feel\l"
	.string "right as rain.$"

OldWomanRegularScript_Text_0:
	.string "You look like you're tired, young one.\n"
	.string "Please rest a while.$"

OldWomanRegularScript_Text_1:
	.string "I wish you strength on your journey.$"

OldWomanQuestScript_Text_0:
	.string "Hello, dearie. Do you need to rest\n"
	.string "yourself and your Pokémon?$"

OldWomanQuestScript_Text_1:
	.string "A Pokémon needs your help.$"

OldWomanQuestScript_Text_2:
	.string "Oh my. Take me, please. Where is it?$"

OldWomanQuestScript_Text_3:
	.string "It's in the Saku village Refuge.$"

OldWomanQuestScript_Text_4:
	.string "Saku village…? Oh dear…\p"
	.string "As much as I'd like to help, I won't be\n"
	.string "allowed to go through the gate by the\l"
	.string "guard.$"

OldWomanQuestScript_Text_5:
	.string "While I can't go to Saku village\n"
	.string "myself, I can create an healing elixir\l"
	.string "here for the Pokémon.\p"
	.string "I only need three: an Oran Berry, a\n"
	.string "fishcake from Maguro Harbor, and a\l"
	.string "Revival Powder.\p"
	.string "Can you be a dear and help me?$"

OldWomanQuestScript_Text_6:
	.string "Of course!$"

OldWomanQuestScript_Text_7:
	.string "I'll try…$"

OldWomanQuestScript_Text_8:
	.string "Sure.$"

OldWomanQuestScript_Text_9:
	.string "You're such a wonderful child. I'll\n"
	.string "wait here until you come back with the\l"
	.string "necessary ingredients.$"

OldWomanQuest2Script_Text_0:
	.string "Hello, child. Do you have the\n"
	.string "ingredients I need for the elixir,\l"
	.string "yet?$"

OldWomanQuest2Script_Text_1:
	.string "Wonderful! Give me a moment, alright?\n"
	.string "You can come back later for it.$"

OldWomanQuest2Script_Text_2:
	.string "Well, I'll stay here until you do.\n"
	.string "Remember, I need an Oran Berry, a\l"
	.string "Maguro Fishcake, and a Revival\l"
	.string "Powder.$"

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

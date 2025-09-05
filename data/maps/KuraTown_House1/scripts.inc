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
	applymovement VAR_LAST_TALKED, KuraTown_House1_OldWoman_Movement_0
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
	applymovement VAR_LAST_TALKED, OldWomanQuestScript_Movement_1
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
	lock
	applymovement VAR_LAST_TALKED, KuraTown_House1_OldWomansSon_Movement_0
	faceplayer
	speakername KuraTown_House1_OldWomansSon_Text_0
	msgbox KuraTown_House1_OldWomansSon_Text_1
	closemessage
	release
	return


KuraTown_House1_Growlithe::
	lock
	faceplayer
	setseenmon SPECIES_GROWLITHE
	setspeakertomonname SPECIES_GROWLITHE
	applymovement VAR_LAST_TALKED, KuraTown_House1_OldWoman_Movement_0
	playmoncry SPECIES_GROWLITHE, CRY_MODE_NORMAL
	msgbox KuraTown_House1_Growlithe_Text_0
	waitmoncry
	release
	return


KuraTown_House1_OldWoman_Movement_0:
	emote_happy
	step_end

OldWomanQuestScript_Movement_0:
	face_away_player
	emote_pensive
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_player
	step_end

OldWomanQuestScript_Movement_1:
	emote_heart
	step_end

OldWomanQuest2Script_Movement_0:
	emote_exclamation_mark
	delay_16
	step_end

KuraTown_House1_OldWomansSon_Movement_0:
	emote_angry
	step_end

KuraTown_House1_OldWoman_Text_0:
	.string "Old woman$"

KuraTown_House1_OldWoman_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_OLD_WOMAN EMOTE_NORMAL}Come back later for the medicine.$"

KuraTown_House1_OldWoman_Text_2:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_OLD_WOMAN EMOTE_NORMAL}There you are! The medicine is ready.\p"
	.string "Take it to the ailing Pokémon. It\n"
	.string "should feel good as new.$"

KuraTown_House1_OldWoman_Text_3:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_OLD_WOMAN EMOTE_NORMAL} Once the ill Pokémon drinks that\n"
	.string "medicine, it should feel right as rain.$"

OldWomanRegularScript_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_OLD_WOMAN EMOTE_NORMAL}You look tired, young one.\n"
	.string "Please rest a while.$"

OldWomanRegularScript_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_OLD_WOMAN EMOTE_NORMAL}I wish you strength on your journey.$"

OldWomanQuestScript_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_OLD_WOMAN EMOTE_NORMAL}Hello, dearie. Do you need to rest\n"
	.string "yourself and your Pokémon?$"

OldWomanQuestScript_Text_1:
	.string "A Pokémon needs your help.$"

OldWomanQuestScript_Text_2:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_OLD_WOMAN EMOTE_NORMAL}Oh my. Take me, please. Where is it?$"

OldWomanQuestScript_Text_3:
	.string "In the Saku village Refuge.$"

OldWomanQuestScript_Text_4:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_OLD_WOMAN EMOTE_NORMAL}Saku village…? Oh dear…\p"
	.string "As much as I'd like to help, I won't be\n"
	.string "allowed to go through the gate by the\l"
	.string "guard.$"

OldWomanQuestScript_Text_5:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_OLD_WOMAN EMOTE_NORMAL} While I can't go to Saku village\n"
	.string "myself, I can create an healing elixir.\p"
	.string "I'll need an Oran Berry, a fishcake\n"
	.string "from Maguro Harbor, and a Revival\l"
	.string "Powder.\p"
	.string "Be a dear and fetch these things for\n"
	.string "me!$"

OldWomanQuestScript_Text_6:
	.string "Of course!$"

OldWomanQuestScript_Text_7:
	.string "I'll try…$"

OldWomanQuestScript_Text_8:
	.string "Sure.$"

OldWomanQuestScript_Text_9:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_OLD_WOMAN EMOTE_NORMAL}Such a wonderful child. I'll wait here\n"
	.string "for the ingredients.$"

OldWomanQuest2Script_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_OLD_WOMAN EMOTE_NORMAL}Do you have the ingredients I need\n"
	.string "for the elixir, child?$"

OldWomanQuest2Script_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_OLD_WOMAN EMOTE_NORMAL}Wonderful! Give me a moment, alright?\n"
	.string "You can come back later for it.$"

OldWomanQuest2Script_Text_2:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_OLD_WOMAN EMOTE_NORMAL}Well, off you go, then. Remember, I\n"
	.string "need an Oran Berry, a Maguro Fishcake,\l"
	.string "and a Revival Powder.$"

KuraTown_House1_OldWomansSon_Text_0:
	.string "Guy$"

KuraTown_House1_OldWomansSon_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_FAT_GUY EMOTE_NORMAL}The Pokémon Council didn't see fit to\n"
	.string "build a Refuge in our town. But those\l"
	.string "jerks over at Saku Village won't let\l"
	.string "us use theirs!\p"
	.string "So my mother has to work hard to heal\n"
	.string "all the villager's Pokémon.\p"
	.string "It's not fair!$"

KuraTown_House1_Growlithe_Text_0:
	.string "Wah!$"

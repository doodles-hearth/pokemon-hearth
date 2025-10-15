Silveridge_House2_MapScripts::
	.byte 0


Silveridge_House2_EventScript_Woman::
	lock
	faceplayer
	setspeaker SP_NAME_WOMAN
	msgbox Silveridge_House2_EventScript_Woman_Text_0
	closemessage
	applymovement LOCALID_SILVERIDGE_MINING_NERD, Silveridge_House2_EventScript_Woman_Movement_0
	waitmovement 0
	setspeaker SP_NAME_MINER
	msgbox Silveridge_House2_EventScript_Woman_Text_1
	closemessage
	applymovement VAR_LAST_TALKED, Silveridge_House2_EventScript_Woman_Movement_1
	setspeaker SP_NAME_WOMAN
	msgbox Silveridge_House2_EventScript_Woman_Text_2
	closemessage
	release
	return


Silveridge_House2_EventScript_Miner::
	lock
	faceplayer
	setspeaker SP_NAME_MINER
	msgbox Silveridge_House2_EventScript_Miner_Text_0
	closemessage
	release
	return


Silveridge_House2_EventScript_Makuhita::
	lock
	faceplayer
	setseenmon SPECIES_MAKUHITA
	setspeakertomonname SPECIES_MAKUHITA
	playmoncry SPECIES_MAKUHITA, CRY_MODE_NORMAL
	msgbox Silveridge_House2_EventScript_Makuhita_Text_0
	waitmoncry
	release
	return


Silveridge_House2_EventScript_Woman_Movement_0:
	delay_16
	delay_16
	walk_in_place_fast_left
	step_end

Silveridge_House2_EventScript_Woman_Movement_1:
	face_right
	delay_16
	delay_16
	step_end

Silveridge_House2_EventScript_Woman_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_MOUNTAIN_WOMAN_2 EMOTE_NORMAL}I wish my husband would stop talking\n"
	.string "about rocks…$"

Silveridge_House2_EventScript_Woman_Text_1:
	.string "But honey, steel isn't a rock!$"

Silveridge_House2_EventScript_Woman_Text_2:
	.string "{CREATE_MUGSHOT MUGSHOT_MOUNTAIN_WOMAN_2 EMOTE_NORMAL}… …{FONT_SMALL}Sigh{FONT_NORMAL}…$"

Silveridge_House2_EventScript_Miner_Text_0:
	.string "The region's finest steel is found in\n"
	.string "the quarry near Saberside Town.\p"
	.string "When my Makuhita is strong enough,\n"
	.string "we'll go see it for ourselves!$"

Silveridge_House2_EventScript_Makuhita_Text_0:
	.string "Ku!$"

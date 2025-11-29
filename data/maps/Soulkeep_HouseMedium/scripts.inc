Soulkeep_HouseMedium_MapScripts::
	.byte 0


Soulkeep_EventScript_Medium::
	lock
	goto_if_set FLAG_ASKED_SABLEYE_RUBY, Soulkeep_EventScript_Medium_2
	msgbox Soulkeep_EventScript_Medium_Text_1
	closemessage
	goto_if_set FLAG_ENCOUNTERED_INVISIBLE_CRYPT_WALLS, Soulkeep_EventScript_Medium_5
Soulkeep_EventScript_Medium_1:
	release
	return

Soulkeep_EventScript_Medium_2:
	faceplayer
	msgbox Soulkeep_EventScript_Medium_Text_0
	closemessage
	goto Soulkeep_EventScript_Medium_1

Soulkeep_EventScript_Medium_5:
	playse SE_PIN
	applymovement VAR_LAST_TALKED, Soulkeep_EventScript_Medium_Movement_0
	waitmovement VAR_LAST_TALKED
	waitse
	msgbox Soulkeep_EventScript_Medium_Text_2
	mcdialogueB Soulkeep_EventScript_Medium_Text_3, Soulkeep_EventScript_Medium_Text_4
	closemessage
	compare VAR_RESULT, 0
	goto_if_eq Soulkeep_EventScript_Medium_7
	goto Soulkeep_EventScript_Medium_1

Soulkeep_EventScript_Medium_7:
	playse SE_PIN
	applymovement VAR_LAST_TALKED, Soulkeep_EventScript_Medium_Movement_1
	waitmovement VAR_LAST_TALKED
	waitse
	msgbox Soulkeep_EventScript_Medium_Text_5
	closemessage
	setflag FLAG_ASKED_SABLEYE_RUBY
	goto Soulkeep_EventScript_Medium_1


Soulkeep_EventScript_MediumApprentice::
	lock
	faceplayer
	msgbox Soulkeep_EventScript_MediumApprentice_Text_0
	closemessage
	release
	return


Soulkeep_EventScript_Medium_Movement_0:
	face_player
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

Soulkeep_EventScript_Medium_Movement_1:
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

Soulkeep_EventScript_Medium_Text_0:
	.string "{SPEAKER NAME_MEDIUM}Please, child. Bring me a Sableye Ruby,\nso that I can finish this lens.$"

Soulkeep_EventScript_Medium_Text_1:
	.string "{SPEAKER NAME_MEDIUM}{FONT_SMALL}The power to see the truth unmasked…\n"
	.string "The power to reveal the invisible…\l"
	.string "I'm almost there, I can feel it…{FONT_NORMAL}$"

Soulkeep_EventScript_Medium_Text_2:
	.string "{SPEAKER NAME_MEDIUM}I'm sure an unruly-looking child such\n"
	.string "as yourself has had the guts to visit\l"
	.string "the crypt in Soulkeep graveyard…\p"
	.string "Tell me, child…\p"
	.string "In the crypt, have you struggled in\nvain against invisible walls?\p"
	.string "Do you also seek to see the unseen,\nand find your way through the maze?$"

Soulkeep_EventScript_Medium_Text_3:
	.string "I do!$"

Soulkeep_EventScript_Medium_Text_4:
	.string "I'm good…$"

Soulkeep_EventScript_Medium_Text_5:
	.string "{SPEAKER NAME_MEDIUM}So you saw it too!\nI knew it! I knew I wasn't mad!\p"
	.string "Child… I am crafting a lens that\nwould allow one to see the truth.\p"
	.string "But alas…\nI am missing a key component!\p"
	.string "I need a Sableye Ruby.\p"
	.string "But with all the ghosts haunting this\nsad town, I've not seen one Sableye!\p"
	.string "Please, please child.\nBring me a Sableye Ruby.$"

Soulkeep_EventScript_MediumApprentice_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_UUME_BOY_1 EMOTE_NORMAL}{SPEAKER NAME_BOY}I'm training to become a Medium!\p"
	.string "But my master is busy with the ghost\n"
	.string "infestation and whatever's happening\l"
	.string "in the crypt, so…\p"
	.string "She really doesn't teach me much…$"

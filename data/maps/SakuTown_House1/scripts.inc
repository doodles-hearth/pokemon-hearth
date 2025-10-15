SakuTown_House1_MapScripts::
	.byte 0


SakuTown_House1_EventScript_Tama::
	lock
	compare VAR_SAKU_KURA_QUEST_TAMA_ASHII_STATE, 0
	goto_if_eq SakuTown_House1_EventScript_Tama_2
	compare VAR_SAKU_KURA_QUEST_TAMA_ASHII_STATE, 1
	goto_if_eq SakuTown_House1_EventScript_Tama_3
	compare VAR_SAKU_KURA_QUEST_TAMA_ASHII_STATE, 2
	goto_if_ge SakuTown_House1_EventScript_Tama_4
	compare VAR_SAKU_KURA_QUEST_TAMA_ASHII_STATE, 9
	goto_if_lt SakuTown_House1_EventScript_Tama_4
	faceplayer
	setspeaker SP_NAME_TAMA
	msgbox SakuTown_House1_EventScript_Tama_Text_17
	waitmessage
	closemessage
SakuTown_House1_EventScript_Tama_1:
	release
	return

SakuTown_House1_EventScript_Tama_2:
	call TamaScript1
	goto SakuTown_House1_EventScript_Tama_1

SakuTown_House1_EventScript_Tama_3:
	setspeaker SP_NAME_MAN
	msgbox SakuTown_House1_EventScript_Tama_Text_0
	mcdialogue SakuTown_House1_EventScript_Tama_Text_1, SakuTown_House1_EventScript_Tama_Text_2
	closemessage
	switch VAR_RESULT
	case 0, SakuTown_House1_EventScript_Tama_13
	case 1, SakuTown_House1_EventScript_Tama_14
SakuTown_House1_EventScript_Tama_11:
	mcdialogue SakuTown_House1_EventScript_Tama_Text_5, SakuTown_House1_EventScript_Tama_Text_6
	closemessage
	delay 32
	setspeaker SP_NAME_TAMA
	msgbox SakuTown_House1_EventScript_Tama_Text_7
	delay 32
	mcdialogue SakuTown_House1_EventScript_Tama_Text_8
	closemessage
	delay 24
	playse SE_PIN
	applymovement 1, Common_Movement_FacePlayer
	waitmovement 0
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	setspeaker SP_NAME_TAMA
	msgbox SakuTown_House1_EventScript_Tama_Text_9
	closemessage
	playfanfare MUS_OBTAIN_ITEM
	msgbox SakuTown_House1_EventScript_Tama_Text_10
	waitfanfare
	removeitem ITEM_ASHIIS_SCARF
	closemessage
	playse SE_LEDGE
	applymovement 1, SakuTown_House1_EventScript_Tama_Movement_0
	waitmovement 1
	setspeaker SP_NAME_TAMA
	msgbox SakuTown_House1_EventScript_Tama_Text_11
	closemessage
	playse SE_PIN
	applymovement 1, SakuTown_House1_EventScript_Tama_Movement_1
	waitmovement 1
	waitse
	setspeaker SP_NAME_TAMA
	msgbox SakuTown_House1_EventScript_Tama_Text_12
	closemessage
	applymovement 1, SakuTown_House1_EventScript_Tama_Movement_2
	waitmovement 1
	setspeaker SP_NAME_TAMA
	msgbox SakuTown_House1_EventScript_Tama_Text_13
	closemessage
	delay 24
	faceplayer
	setspeaker SP_NAME_TAMA
	msgbox SakuTown_House1_EventScript_Tama_Text_14
	closemessage
	applymovement 1, Common_Movement_FaceAwayPlayer
	waitmovement 1
	delay 60
	faceplayer
	setspeaker SP_NAME_TAMA
	msgbox SakuTown_House1_EventScript_Tama_Text_15
	closemessage
	addvar VAR_SAKU_KURA_QUEST_TAMA_ASHII_STATE, 1
	goto SakuTown_House1_EventScript_Tama_1

SakuTown_House1_EventScript_Tama_4:
	faceplayer
	setspeaker SP_NAME_TAMA
	msgbox SakuTown_House1_EventScript_Tama_Text_16
	waitmessage
	closemessage
	goto SakuTown_House1_EventScript_Tama_1

SakuTown_House1_EventScript_Tama_13:
	setspeaker SP_NAME_TAMA
	msgbox SakuTown_House1_EventScript_Tama_Text_3
	goto SakuTown_House1_EventScript_Tama_11

SakuTown_House1_EventScript_Tama_14:
	setspeaker SP_NAME_TAMA
	msgbox SakuTown_House1_EventScript_Tama_Text_4
	goto SakuTown_House1_EventScript_Tama_11


TamaScript1:
	setspeaker SP_NAME_MAN
	msgbox SakuTown_House1_EventScript_Tama_Text_0
	closemessage
	return


SakuTown_House1_EventScript_Tama_Movement_0:
	lock_facing_direction
	jump_in_place_down
	unlock_facing_direction
	step_end

SakuTown_House1_EventScript_Tama_Movement_1:
	emote_question_mark
	delay_16
	delay_16
	delay_16
	step_end

SakuTown_House1_EventScript_Tama_Movement_2:
	face_down
	step_end

SakuTown_House1_EventScript_Tama_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_MAN_1 EMOTE_NORMAL}Please go away.\n"
	.string "Leave me alone.$"

SakuTown_House1_EventScript_Tama_Text_1:
	.string "Excuse me!$"

SakuTown_House1_EventScript_Tama_Text_2:
	.string "Are you Tama?$"

SakuTown_House1_EventScript_Tama_Text_3:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_MAN_1 EMOTE_NORMAL}… … … … … …\n"
	.string "… … … … …What?$"

SakuTown_House1_EventScript_Tama_Text_4:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_MAN_1 EMOTE_NORMAL}… … … … … …\n"
	.string "… … … … …Yeah, so?$"

SakuTown_House1_EventScript_Tama_Text_5:
	.string "I have something!$"

SakuTown_House1_EventScript_Tama_Text_6:
	.string "This is for you!$"

SakuTown_House1_EventScript_Tama_Text_7:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_MAN_1 EMOTE_NORMAL}… … … … … …\n"
	.string "… … … … … …$"

SakuTown_House1_EventScript_Tama_Text_8:
	.string "It's from Ashii.$"

SakuTown_House1_EventScript_Tama_Text_9:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_MAN_1 EMOTE_NORMAL}WHAT?! Let me see!$"

SakuTown_House1_EventScript_Tama_Text_10:
	.string "{PLAYER} gave Tama the scarf.$"

SakuTown_House1_EventScript_Tama_Text_11:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_MAN_1 EMOTE_NORMAL}I… I can't believe it!\n"
	.string "She really does love me!$"

SakuTown_House1_EventScript_Tama_Text_12:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_MAN_1 EMOTE_NORMAL}Eh? There's a letter inside!\n"
	.string "Whatever for?$"

SakuTown_House1_EventScript_Tama_Text_13:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_MAN_1 EMOTE_NORMAL}Ahem…\n"
	.string "“My dear Tama,\l"
	.string "It pains me that you aren't by my side\l"
	.string "each night.\l"
	.string "The sweet chirping of birds pales in\l"
	.string "comparison to your hearty laugh.\l"
	.string "I would move Heaven and Earth for us\l"
	.string "to be together.\l"
	.string "If your heart still rings true for\l"
	.string "mine, meet me under pale moonlight, in\l"
	.string "the vale betwixt our homes.\p"
	.string "Sincerely yours,\n"
	.string "-Ashii {EMOJI_HEART}”\p"
	.string "… … … … … …\n"
	.string "… … … … … …$"

SakuTown_House1_EventScript_Tama_Text_14:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_MAN_1 EMOTE_NORMAL}…Ahem. Sorry, this is a little\n"
	.string "embarrassing…\p"
	.string "What does she mean with that “vale”,\n"
	.string "though?…\p"
	.string "Oh!\n"
	.string "She must be talking about the small\l"
	.string "valley east of here!\p"
	.string "And “pale moonlight”…\n"
	.string "That must be tonight!\p"
	.string "Of course! Why else ask you to deliver\n"
	.string "this now?$"

SakuTown_House1_EventScript_Tama_Text_15:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_MAN_1 EMOTE_NORMAL}Wielder! I owe you my thanks.\n"
	.string "Please, tell her I'll meet her tonight!$"

SakuTown_House1_EventScript_Tama_Text_16:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_MAN_1 EMOTE_NORMAL}Please, tell Ashii I'll meet her\n"
	.string "tonight!$"

SakuTown_House1_EventScript_Tama_Text_17:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_MAN_1 EMOTE_NORMAL}One day our villages will stand\n"
	.string "together, and we will love each other\l"
	.string "in broad daylight!$"

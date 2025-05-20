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
	compare VAR_SAKU_KURA_QUEST_TAMA_ASHII_STATE, 6
	goto_if_le SakuTown_House1_EventScript_Tama_4
	speakername SakuTown_House1_EventScript_Tama_Text_4
	msgbox SakuTown_House1_EventScript_Tama_Text_19
	waitmessage
	closemessage
SakuTown_House1_EventScript_Tama_1:
	release
	return

SakuTown_House1_EventScript_Tama_2:
	call TamaScript1
	goto SakuTown_House1_EventScript_Tama_1

SakuTown_House1_EventScript_Tama_3:
	speakername SakuTown_House1_EventScript_Tama_Text_0
	msgbox SakuTown_House1_EventScript_Tama_Text_1
	mcdialogue SakuTown_House1_EventScript_Tama_Text_2, SakuTown_House1_EventScript_Tama_Text_3
	closemessage
	switch VAR_RESULT
	case 0, SakuTown_House1_EventScript_Tama_13
	case 1, SakuTown_House1_EventScript_Tama_14
SakuTown_House1_EventScript_Tama_11:
	mcdialogue SakuTown_House1_EventScript_Tama_Text_7, SakuTown_House1_EventScript_Tama_Text_8
	closemessage
	delay 32
	speakername SakuTown_House1_EventScript_Tama_Text_4
	msgbox SakuTown_House1_EventScript_Tama_Text_9
	delay 32
	mcdialogue SakuTown_House1_EventScript_Tama_Text_10
	closemessage
	delay 24
	playse SE_PIN
	applymovement 1, Common_Movement_FacePlayer
	waitmovement 0
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	speakername SakuTown_House1_EventScript_Tama_Text_4
	msgbox SakuTown_House1_EventScript_Tama_Text_11
	closemessage
	playfanfare MUS_OBTAIN_ITEM
	msgbox SakuTown_House1_EventScript_Tama_Text_12
	waitfanfare
	removeitem ITEM_ASHIIS_SCARF
	closemessage
	playse SE_LEDGE
	applymovement 1, SakuTown_House1_EventScript_Tama_Movement_0
	waitmovement 1
	speakername SakuTown_House1_EventScript_Tama_Text_4
	msgbox SakuTown_House1_EventScript_Tama_Text_13
	closemessage
	playse SE_PIN
	applymovement 1, SakuTown_House1_EventScript_Tama_Movement_1
	waitmovement 1
	waitse
	speakername SakuTown_House1_EventScript_Tama_Text_4
	msgbox SakuTown_House1_EventScript_Tama_Text_14
	closemessage
	applymovement 1, SakuTown_House1_EventScript_Tama_Movement_2
	waitmovement 1
	speakername SakuTown_House1_EventScript_Tama_Text_4
	msgbox SakuTown_House1_EventScript_Tama_Text_15
	closemessage
	faceplayer
	speakername SakuTown_House1_EventScript_Tama_Text_4
	msgbox SakuTown_House1_EventScript_Tama_Text_16
	closemessage
	applymovement 1, Common_Movement_FaceAwayPlayer
	waitmovement 1
	delay 60
	applymovement 1, SakuTown_House1_EventScript_Tama_Movement_3
	waitmovement 1
	speakername SakuTown_House1_EventScript_Tama_Text_4
	msgbox SakuTown_House1_EventScript_Tama_Text_17
	closemessage
	addvar VAR_SAKU_KURA_QUEST_TAMA_ASHII_STATE, 1
	goto SakuTown_House1_EventScript_Tama_1

SakuTown_House1_EventScript_Tama_4:
	speakername SakuTown_House1_EventScript_Tama_Text_4
	msgbox SakuTown_House1_EventScript_Tama_Text_18
	waitmessage
	closemessage
	goto SakuTown_House1_EventScript_Tama_1

SakuTown_House1_EventScript_Tama_13:
	speakername SakuTown_House1_EventScript_Tama_Text_4
	msgbox SakuTown_House1_EventScript_Tama_Text_5
	goto SakuTown_House1_EventScript_Tama_11

SakuTown_House1_EventScript_Tama_14:
	speakername SakuTown_House1_EventScript_Tama_Text_4
	msgbox SakuTown_House1_EventScript_Tama_Text_6
	goto SakuTown_House1_EventScript_Tama_11


TamaScript1:
	speakername SakuTown_House1_EventScript_Tama_Text_0
	msgbox SakuTown_House1_EventScript_Tama_Text_1
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

SakuTown_House1_EventScript_Tama_Movement_3:
	face_player
	lock_facing_direction
	walk_in_place_fast_down
	unlock_facing_direction
	step_end

SakuTown_House1_EventScript_Tama_Text_0:
	.string "Man$"

SakuTown_House1_EventScript_Tama_Text_1:
	.string "Please go away.\n"
	.string "Leave me alone.$"

SakuTown_House1_EventScript_Tama_Text_2:
	.string "Excuse me!$"

SakuTown_House1_EventScript_Tama_Text_3:
	.string "Are you Tama?$"

SakuTown_House1_EventScript_Tama_Text_4:
	.string "Tama$"

SakuTown_House1_EventScript_Tama_Text_5:
	.string "… … … … … …\n"
	.string "… … … … …What?$"

SakuTown_House1_EventScript_Tama_Text_6:
	.string "… … … … … …\n"
	.string "… … … … …Yeah, so?$"

SakuTown_House1_EventScript_Tama_Text_7:
	.string "I have something!$"

SakuTown_House1_EventScript_Tama_Text_8:
	.string "This is for you!$"

SakuTown_House1_EventScript_Tama_Text_9:
	.string "… … … … … …\n"
	.string "… … … … … …$"

SakuTown_House1_EventScript_Tama_Text_10:
	.string "It's from Ashii.$"

SakuTown_House1_EventScript_Tama_Text_11:
	.string "WHAT?! Let me see!$"

SakuTown_House1_EventScript_Tama_Text_12:
	.string "{PLAYER} gave Tama the scarf.$"

SakuTown_House1_EventScript_Tama_Text_13:
	.string "I… I can't believe it!\n"
	.string "She really does love me!\l"
	.string "Thank you so much for this!$"

SakuTown_House1_EventScript_Tama_Text_14:
	.string "Eh? There's a letter inside!\n"
	.string "Whatever for?$"

SakuTown_House1_EventScript_Tama_Text_15:
	.string "Ahem… “My dear Tama,\n"
	.string "It pains me that you're not by my side\l"
	.string "each night.\l"
	.string "The sweet chirping of birds pales in\l"
	.string "comparison to your hearty laugh.\p"
	.string "I would move Heaven and Earth if it\n"
	.string "meant we could be together.\p"
	.string "If your heart still rings true for\n"
	.string "mine, will you meet me under pale\l"
	.string "moonlight, in the vale betwixt our\l"
	.string "homes?\p"
	.string "Sincerely yours,\n"
	.string "-Ashii {EMOJI_HEART}”\p"
	.string "… … … … … …\n"
	.string "… … … … … …$"

SakuTown_House1_EventScript_Tama_Text_16:
	.string "…Ahem. Sorry if this was embarrassing\n"
	.string "for you…\p"
	.string "What does she mean with that “vale”,\n"
	.string "though?…\p"
	.string "Oh!\n"
	.string "She must be talking about the small\l"
	.string "valley to the east of here!\p"
	.string "And “pale moonlight”…\n"
	.string "That must be tonight!\p"
	.string "Of course! Why else ask you to\n"
	.string "deliver this now?$"

SakuTown_House1_EventScript_Tama_Text_17:
	.string "Wielder! I owe you my thanks.\n"
	.string "Please, tell her I'll meet her tonight!$"

SakuTown_House1_EventScript_Tama_Text_18:
	.string "Please, tell Ashii I'll meet her\n"
	.string "tonight!$"

SakuTown_House1_EventScript_Tama_Text_19:
	.string "I can't wait to see Ashii again\n"
	.string "tonight!$"

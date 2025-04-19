KuraTown_House2_MapScripts::
	.byte 0


KuraTown_House2_EventScript_Ashii::
	lock
	switch VAR_SAKU_KURA_QUEST_TAMA_ASHII_STATE
	case 0, KuraTown_House2_EventScript_Ashii_3
	case 1, KuraTown_House2_EventScript_Ashii_4
	case 2, KuraTown_House2_EventScript_Ashii_5
KuraTown_House2_EventScript_Ashii_1:
	release
	return

KuraTown_House2_EventScript_Ashii_3:
	call AshiiScript1
	goto KuraTown_House2_EventScript_Ashii_1

KuraTown_House2_EventScript_Ashii_4:
	call AshiiScript2
	goto KuraTown_House2_EventScript_Ashii_1

KuraTown_House2_EventScript_Ashii_5:
	call AshiiScript3
	goto KuraTown_House2_EventScript_Ashii_1


AshiiScript1:
	compare VAR_SAKU_KURA_QUEST_TAMA_ASHII_STATE, 0
	goto_if_eq AshiiScript1_1
	return

AshiiScript1_1:
	speakername AshiiScript1_Text_0
	msgbox AshiiScript1_Text_1
	closemessage
	delay 30
	playse SE_PIN
	applymovement 1, Common_Movement_FacePlayer
	waitmovement 0
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	speakername AshiiScript1_Text_0
	msgbox AshiiScript1_Text_2
	closemessage
	delay 30
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	msgbox AshiiScript1_Text_3
	closemessage
	speakername AshiiScript1_Text_4
	msgbox AshiiScript1_Text_5
	closemessage
	giveitem ITEM_ASHIIS_SCARF
	setvar VAR_SAKU_KURA_QUEST_TAMA_ASHII_STATE, 1
	startquest QUEST_KURALOVERS
	return


AshiiScript2:
	faceplayer
	speakername AshiiScript1_Text_4
	msgbox AshiiScript2_Text_0
	closemessage
	return


AshiiScript3:
	faceplayer
	speakername AshiiScript1_Text_4
	msgbox AshiiScript3_Text_0
	closemessage
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, AshiiScript3_Text_1, AshiiScript3_Text_2, AshiiScript3_Text_3
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_FaceAwayPlayer
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, AshiiScript3_Movement_0
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_FacePlayer
	waitmovement 0
	speakername AshiiScript1_Text_4
	msgbox AshiiScript3_Text_4
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, AshiiScript3_Text_5, AshiiScript3_Text_6, AshiiScript3_Text_7
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	callnative CallnativeForPurposes
	applymovement 1, AshiiScript3_Movement_1
	waitmovement 0
	callnative CallnativeForPurposes
	closemessage
	addvar VAR_SAKU_KURA_QUEST_TAMA_ASHII_STATE, 1
	return


AshiiScript3_Movement_0:
	emote_heart
	step_end

AshiiScript3_Movement_1:
	jump_in_place_down
	delay_4
	jump_in_place_down
	delay_4
	jump_in_place_down
	delay_4
	step_end

AshiiScript1_Text_0:
	.string "Girl$"

AshiiScript1_Text_1:
	.string "Sigh… Oh, Tama… Why must life be so\n"
	.string "complicated?$"

AshiiScript1_Text_2:
	.string "Hey, what are you doing in my house?\n"
	.string "Were you eavesdropping?\p"
	.string "…It doesn't matter anyway. The boy I\n"
	.string "really like lives in Saku Village, but\l"
	.string "our two villages hate each other, so I\l"
	.string "can't see him anymore.\p"
	.string "If only there was a way for him to\n"
	.string "know my feelings…$"

AshiiScript1_Text_3:
	.string "Wait, you're not from here, are you?\p"
	.string "$"

AshiiScript1_Text_4:
	.string "Ashii$"

AshiiScript1_Text_5:
	.string "My name is Ashii. I need your help. The\n"
	.string "guard won't let anyone from Kura\l"
	.string "Village enter Saku Village. But you\l"
	.string "should be fine!\p"
	.string "Please, go to Saku Village and give him\n"
	.string "this. He'll know it's from me.$"

AshiiScript2_Text_0:
	.string "The guard won't let anyone from Kura\n"
	.string "Village enter Saku Village. But you\l"
	.string "should be fine!\p"
	.string "Please, go to Saku Village and give him\n"
	.string "this. He'll know it's from me.$"

AshiiScript3_Text_0:
	.string "Were able to give the scarf to Tama\n"
	.string "yet? Did he get my message?$"

AshiiScript3_Text_1:
	.string "Yep!$"

AshiiScript3_Text_2:
	.string "He sure did!$"

AshiiScript3_Text_3:
	.string "Loud and clear.$"

AshiiScript3_Text_4:
	.string "I'm sorry. You've been an incredible\n"
	.string "help and I haven't even gotten your\l"
	.string "name yet. May i ask what it is?\p"
	.string "{PLAYER}… I see…\p"
	.string "{PLAYER}, I know this is a big thing\n"
	.string "to ask, but…\p"
	.string "I want to be sure that my meeting\n"
	.string "with Tama will be safe, especially if it\l"
	.string "might be our last. If so, can you\l"
	.string "please come with me when we go see\l"
	.string "each other again?$"

AshiiScript3_Text_5:
	.string "Of course.$"

AshiiScript3_Text_6:
	.string "Who wouldn't?$"

AshiiScript3_Text_7:
	.string "You both deserve it.$"

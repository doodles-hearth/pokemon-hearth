KuraTown_House2_MapScripts::
	.byte 0


KuraTown_House2_EventScript_Ashii::
	lock
	compare VAR_SAKU_KURA_QUEST_TAMA_ASHII_STATE, 0
	goto_if_eq KuraTown_House2_EventScript_Ashii_2
	compare VAR_SAKU_KURA_QUEST_TAMA_ASHII_STATE, 1
	goto_if_eq KuraTown_House2_EventScript_Ashii_3
KuraTown_House2_EventScript_Ashii_1:
	release
	return

KuraTown_House2_EventScript_Ashii_2:
	speakername KuraTown_House2_EventScript_Ashii_Text_0
	msgbox KuraTown_House2_EventScript_Ashii_Text_1
	closemessage
	delay 30
	playse SE_PIN
	applymovement 1, Common_Movement_FacePlayer
	waitmovement 0
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	speakername KuraTown_House2_EventScript_Ashii_Text_0
	msgbox KuraTown_House2_EventScript_Ashii_Text_2
	closemessage
	delay 30
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	msgbox KuraTown_House2_EventScript_Ashii_Text_3
	closemessage
	speakername KuraTown_House2_EventScript_Ashii_Text_4
	msgbox KuraTown_House2_EventScript_Ashii_Text_5
	closemessage
	giveitem ITEM_ASHIIS_SCARF
	setvar VAR_SAKU_KURA_QUEST_TAMA_ASHII_STATE, 1
	startquest QUEST_KURALOVERS
	goto KuraTown_House2_EventScript_Ashii_1

KuraTown_House2_EventScript_Ashii_3:
	faceplayer
	speakername KuraTown_House2_EventScript_Ashii_Text_4
	msgbox KuraTown_House2_EventScript_Ashii_Text_6
	closemessage
	goto KuraTown_House2_EventScript_Ashii_1


KuraTown_House2_EventScript_Ashii_Text_0:
	.string "Girl$"

KuraTown_House2_EventScript_Ashii_Text_1:
	.string "Sigh… Oh, Tama… Why must life be so\n"
	.string "complicated?$"

KuraTown_House2_EventScript_Ashii_Text_2:
	.string "Hey, what are you doing in my house?\n"
	.string "Were you eavesdropping?\p"
	.string "…It doesn't matter anyway. The boy I\n"
	.string "really like lives in Saku Village, but\l"
	.string "our two villages hate each other, so I\l"
	.string "can't see him anymore.\p"
	.string "If only there was a way for him to\n"
	.string "know my feelings…$"

KuraTown_House2_EventScript_Ashii_Text_3:
	.string "Wait, you're not from here, are you?\p"
	.string "$"

KuraTown_House2_EventScript_Ashii_Text_4:
	.string "Ashii$"

KuraTown_House2_EventScript_Ashii_Text_5:
	.string "My name is Ashii. I need your help. The\n"
	.string "guard won't let anyone from Kura\l"
	.string "Village enter Saku Village. But you\l"
	.string "should be fine!\p"
	.string "Please, go to Saku Village and give him\n"
	.string "this. He'll know it's from me.$"

KuraTown_House2_EventScript_Ashii_Text_6:
	.string "The guard won't let anyone from Kura\n"
	.string "Village enter Saku Village. But you\l"
	.string "should be fine!\p"
	.string "Please, go to Saku Village and give him\n"
	.string "this. He'll know it's from me.$"

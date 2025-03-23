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
	msgbox KuraTown_House2_EventScript_Ashii_Text_0
	closemessage
	delay 30
	playse SE_PIN
	applymovement 1, Common_Movement_FacePlayer
	waitmovement 0
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	msgbox KuraTown_House2_EventScript_Ashii_Text_1
	closemessage
	delay 30
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	msgbox KuraTown_House2_EventScript_Ashii_Text_2
	closemessage
	giveitem ITEM_ASHIIS_SCARF
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_SAKU_KURA_QUEST_TAMA_ASHII_STATE, 1
	goto KuraTown_House2_EventScript_Ashii_1

KuraTown_House2_EventScript_Ashii_3:
	faceplayer
	msgbox KuraTown_House2_EventScript_Ashii_Text_2
	closemessage
	goto KuraTown_House2_EventScript_Ashii_1


KuraTown_House2_EventScript_Ashii_Text_0:
	.string "Sigh… Oh, Tama… Why must life be\n"
	.string "so complicated?$"

KuraTown_House2_EventScript_Ashii_Text_1:
	.string "Hey, what are you doing in my\n"
	.string "house? Were you eavesdropping?\p"
	.string "…It doesn't matter anyway. The boy\n"
	.string "I really like lives in Saku\l"
	.string "Village, but our two villages\l"
	.string "hate each other, so I can't see\l"
	.string "him anymore.\p"
	.string "If only there was a way for him to\n"
	.string "know my feelings…$"

KuraTown_House2_EventScript_Ashii_Text_2:
	.string "Wait, you're not from here, are\n"
	.string "you?\p"
	.string "The guard won't let anyone from\n"
	.string "Kura Village enter Saku Village.\l"
	.string "But you should be fine!\p"
	.string "Please, go to Saku Village and give\n"
	.string "him this. He'll know it's from me.$"

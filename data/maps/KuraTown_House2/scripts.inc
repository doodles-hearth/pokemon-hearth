KuraTown_House2_MapScripts::
	.byte 0


KuraTown_House2_EventScript_Ashii::
# 8 "data/maps/KuraTown_House2/scripts.pory"
	lock
# 11 "data/maps/KuraTown_House2/scripts.pory"
	compare VAR_SAKU_KURA_QUEST_TAMA_ASHII_STATE, 0
	goto_if_eq KuraTown_House2_EventScript_Ashii_2
# 50 "data/maps/KuraTown_House2/scripts.pory"
	compare VAR_SAKU_KURA_QUEST_TAMA_ASHII_STATE, 1
	goto_if_eq KuraTown_House2_EventScript_Ashii_3
KuraTown_House2_EventScript_Ashii_1:
# 59 "data/maps/KuraTown_House2/scripts.pory"
	release
	return

KuraTown_House2_EventScript_Ashii_2:
# 12 "data/maps/KuraTown_House2/scripts.pory"
	msgbox KuraTown_House2_EventScript_Ashii_Text_0
# 15 "data/maps/KuraTown_House2/scripts.pory"
	closemessage
# 16 "data/maps/KuraTown_House2/scripts.pory"
	delay 30
# 18 "data/maps/KuraTown_House2/scripts.pory"
	playse SE_PIN
# 19 "data/maps/KuraTown_House2/scripts.pory"
	applymovement 1, Common_Movement_FacePlayer
# 20 "data/maps/KuraTown_House2/scripts.pory"
	waitmovement 0
# 21 "data/maps/KuraTown_House2/scripts.pory"
	applymovement 1, Common_Movement_ExclamationMark
# 22 "data/maps/KuraTown_House2/scripts.pory"
	waitmovement 0
# 23 "data/maps/KuraTown_House2/scripts.pory"
	applymovement 1, Common_Movement_Delay48
# 24 "data/maps/KuraTown_House2/scripts.pory"
	waitmovement 0
# 26 "data/maps/KuraTown_House2/scripts.pory"
	msgbox KuraTown_House2_EventScript_Ashii_Text_1
# 31 "data/maps/KuraTown_House2/scripts.pory"
	closemessage
# 32 "data/maps/KuraTown_House2/scripts.pory"
	delay 30
# 34 "data/maps/KuraTown_House2/scripts.pory"
	playse SE_PIN
# 35 "data/maps/KuraTown_House2/scripts.pory"
	applymovement 1, Common_Movement_ExclamationMark
# 36 "data/maps/KuraTown_House2/scripts.pory"
	waitmovement 0
# 37 "data/maps/KuraTown_House2/scripts.pory"
	applymovement 1, Common_Movement_Delay48
# 38 "data/maps/KuraTown_House2/scripts.pory"
	waitmovement 0
# 40 "data/maps/KuraTown_House2/scripts.pory"
	msgbox KuraTown_House2_EventScript_Ashii_Text_2
# 46 "data/maps/KuraTown_House2/scripts.pory"
	giveitem ITEM_ASHIIS_SCARF
# 47 "data/maps/KuraTown_House2/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 48 "data/maps/KuraTown_House2/scripts.pory"
	setvar VAR_SAKU_KURA_QUEST_TAMA_ASHII_STATE, 1
	goto KuraTown_House2_EventScript_Ashii_1

KuraTown_House2_EventScript_Ashii_3:
# 51 "data/maps/KuraTown_House2/scripts.pory"
	faceplayer
# 52 "data/maps/KuraTown_House2/scripts.pory"
	msgbox KuraTown_House2_EventScript_Ashii_Text_2
	goto KuraTown_House2_EventScript_Ashii_1


KuraTown_House2_EventScript_Ashii_Text_0:
# 13 "data/maps/KuraTown_House2/scripts.pory"
	.string "Sigh… Oh, Tama… Why must life be so\n"
	.string "complicated?$"

KuraTown_House2_EventScript_Ashii_Text_1:
# 27 "data/maps/KuraTown_House2/scripts.pory"
	.string "Hey, what are you doing in my house?\n"
	.string "Were you eavesdropping?\p"
	.string "…It doesn't matter anyway. The boy I\n"
	.string "really like lives in Saku Village, but our\l"
	.string "two villages hate each other, so I can't\l"
	.string "see him anymore.\p"
	.string "If only there was a way for him to know\n"
	.string "my feelings…$"

KuraTown_House2_EventScript_Ashii_Text_2:
# 41 "data/maps/KuraTown_House2/scripts.pory"
	.string "Wait, you're not from here, are you?\p"
	.string "The guard won't let anyone from Kura\n"
	.string "Village enter Saku Village. But you\l"
	.string "should be fine!\p"
	.string "Please, go to Saku Village and give him\n"
	.string "this. He'll know it's from me.$"

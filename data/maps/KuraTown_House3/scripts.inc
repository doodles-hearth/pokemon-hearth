KuraTown_House3_MapScripts::
	.byte 0


KuraTown_House3_EventScript_Lady::
# 10 "data/maps/KuraTown_House3/scripts.pory"
	lock
# 13 "data/maps/KuraTown_House3/scripts.pory"
	compare VAR_SAKU_KURA_QUEST_ESPEON_STATE, 0
	goto_if_eq KuraTown_House3_EventScript_Lady_2
# 13 "data/maps/KuraTown_House3/scripts.pory"
	compare VAR_SAKU_KURA_QUEST_ESPEON_STATE, 2
	goto_if_eq KuraTown_House3_EventScript_Lady_2
# 40 "data/maps/KuraTown_House3/scripts.pory"
	compare VAR_SAKU_KURA_QUEST_ESPEON_STATE, 1
	goto_if_eq KuraTown_House3_EventScript_Lady_3
# 48 "data/maps/KuraTown_House3/scripts.pory"
	compare VAR_SAKU_KURA_QUEST_ESPEON_STATE, 3
	goto_if_eq KuraTown_House3_EventScript_Lady_4
# 53 "data/maps/KuraTown_House3/scripts.pory"
	compare VAR_SAKU_KURA_QUEST_ESPEON_STATE, 4
	goto_if_eq KuraTown_House3_EventScript_Lady_5
# 61 "data/maps/KuraTown_House3/scripts.pory"
	compare VAR_SAKU_KURA_QUEST_ESPEON_STATE, 5
	goto_if_eq KuraTown_House3_EventScript_Lady_6
KuraTown_House3_EventScript_Lady_1:
# 70 "data/maps/KuraTown_House3/scripts.pory"
	release
	return

KuraTown_House3_EventScript_Lady_2:
# 14 "data/maps/KuraTown_House3/scripts.pory"
	faceplayer
# 15 "data/maps/KuraTown_House3/scripts.pory"
	msgbox KuraTown_House3_EventScript_Lady_Text_0
# 18 "data/maps/KuraTown_House3/scripts.pory"
	closemessage
# 19 "data/maps/KuraTown_House3/scripts.pory"
	delay 60
# 20 "data/maps/KuraTown_House3/scripts.pory"
	msgbox KuraTown_House3_EventScript_Lady_Text_1
# 26 "data/maps/KuraTown_House3/scripts.pory"
	closemessage
# 28 "data/maps/KuraTown_House3/scripts.pory"
	compare VAR_SAKU_KURA_QUEST_ESPEON_STATE, 0
	goto_if_eq KuraTown_House3_EventScript_Lady_15
# 32 "data/maps/KuraTown_House3/scripts.pory"
	compare VAR_SAKU_KURA_QUEST_ESPEON_STATE, 2
	goto_if_eq KuraTown_House3_EventScript_Lady_16
KuraTown_House3_EventScript_Lady_14:
# 38 "data/maps/KuraTown_House3/scripts.pory"
	applymovement 1, Common_Movement_FaceOriginalDirection
	goto KuraTown_House3_EventScript_Lady_1

KuraTown_House3_EventScript_Lady_3:
# 41 "data/maps/KuraTown_House3/scripts.pory"
	faceplayer
# 42 "data/maps/KuraTown_House3/scripts.pory"
	msgbox KuraTown_House3_EventScript_Lady_Text_2
# 45 "data/maps/KuraTown_House3/scripts.pory"
	closemessage
	goto KuraTown_House3_EventScript_Lady_1

KuraTown_House3_EventScript_Lady_4:
# 49 "data/maps/KuraTown_House3/scripts.pory"
	faceplayer
# 51 "data/maps/KuraTown_House3/scripts.pory"
	call KuraTown_House3_EventScript_EspeonGoesHome
	goto KuraTown_House3_EventScript_Lady_1

KuraTown_House3_EventScript_Lady_5:
# 54 "data/maps/KuraTown_House3/scripts.pory"
	faceplayer
# 55 "data/maps/KuraTown_House3/scripts.pory"
	msgbox KuraTown_House3_EventScript_Lady_Text_3
# 58 "data/maps/KuraTown_House3/scripts.pory"
	closemessage
	goto KuraTown_House3_EventScript_Lady_1

KuraTown_House3_EventScript_Lady_6:
# 62 "data/maps/KuraTown_House3/scripts.pory"
	faceplayer
# 63 "data/maps/KuraTown_House3/scripts.pory"
	msgbox KuraTown_House3_EventScript_Lady_Text_4
# 67 "data/maps/KuraTown_House3/scripts.pory"
	closemessage
	goto KuraTown_House3_EventScript_Lady_1

KuraTown_House3_EventScript_Lady_15:
# 30 "data/maps/KuraTown_House3/scripts.pory"
	setvar VAR_SAKU_KURA_QUEST_ESPEON_STATE, 1
# 31 "data/maps/KuraTown_House3/scripts.pory"
	applymovement 1, Common_Movement_FaceOriginalDirection
	goto KuraTown_House3_EventScript_Lady_14

KuraTown_House3_EventScript_Lady_16:
# 33 "data/maps/KuraTown_House3/scripts.pory"
	delay 60
# 35 "data/maps/KuraTown_House3/scripts.pory"
	call KuraTown_House3_EventScript_EspeonGoesHome
	goto KuraTown_House3_EventScript_Lady_14


KuraTown_House3_EventScript_EspeonGoesHome::
# 74 "data/maps/KuraTown_House3/scripts.pory"
	faceplayer
# 75 "data/maps/KuraTown_House3/scripts.pory"
	msgbox KuraTown_House3_EventScript_EspeonGoesHome_Text_0
# 81 "data/maps/KuraTown_House3/scripts.pory"
	closemessage
# 83 "data/maps/KuraTown_House3/scripts.pory"
	applymovement 1, Common_Movement_FaceLeft
# 84 "data/maps/KuraTown_House3/scripts.pory"
	applymovement 2, Common_Movement_FaceRight
# 86 "data/maps/KuraTown_House3/scripts.pory"
	waitmovement 0
# 87 "data/maps/KuraTown_House3/scripts.pory"
	msgbox KuraTown_House3_EventScript_EspeonGoesHome_Text_1
# 90 "data/maps/KuraTown_House3/scripts.pory"
	closemessage
# 92 "data/maps/KuraTown_House3/scripts.pory"
	applymovement 2, JumpInJoy
# 93 "data/maps/KuraTown_House3/scripts.pory"
	playmoncry SPECIES_ESPEON, CRY_MODE_NORMAL
# 94 "data/maps/KuraTown_House3/scripts.pory"
	waitmoncry
# 95 "data/maps/KuraTown_House3/scripts.pory"
	delay 40
# 97 "data/maps/KuraTown_House3/scripts.pory"
	fadescreen FADE_TO_BLACK
# 98 "data/maps/KuraTown_House3/scripts.pory"
	removeobject 2
# 99 "data/maps/KuraTown_House3/scripts.pory"
	delay 60
# 100 "data/maps/KuraTown_House3/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 101 "data/maps/KuraTown_House3/scripts.pory"
	delay 40
# 103 "data/maps/KuraTown_House3/scripts.pory"
	msgbox KuraTown_House3_EventScript_Lady_Text_3
# 106 "data/maps/KuraTown_House3/scripts.pory"
	closemessage
# 108 "data/maps/KuraTown_House3/scripts.pory"
	setvar VAR_SAKU_KURA_QUEST_ESPEON_STATE, 4
# 109 "data/maps/KuraTown_House3/scripts.pory"
	setflag FLAG_SAKU_KURA_HIDE_ESPEON_LADYS_HOUSE
	return


KuraTown_House3_EventScript_Espeon::
# 114 "data/maps/KuraTown_House3/scripts.pory"
	lock
# 115 "data/maps/KuraTown_House3/scripts.pory"
	faceplayer
# 116 "data/maps/KuraTown_House3/scripts.pory"
	playmoncry SPECIES_ESPEON, CRY_MODE_NORMAL
# 117 "data/maps/KuraTown_House3/scripts.pory"
	msgbox KuraTown_House3_EventScript_Espeon_Text_0
# 120 "data/maps/KuraTown_House3/scripts.pory"
	waitmoncry
# 121 "data/maps/KuraTown_House3/scripts.pory"
	closemessage
# 122 "data/maps/KuraTown_House3/scripts.pory"
	delay 30
# 123 "data/maps/KuraTown_House3/scripts.pory"
	msgbox KuraTown_House3_EventScript_Espeon_Text_1
# 126 "data/maps/KuraTown_House3/scripts.pory"
	release
	return


# 129 "data/maps/KuraTown_House3/scripts.pory"
JumpInJoy:
# 130 "data/maps/KuraTown_House3/scripts.pory"
	jump_in_place_right
	step_end

KuraTown_House3_EventScript_Lady_Text_0:
# 16 "data/maps/KuraTown_House3/scripts.pory"
	.string "Hello! Ah, you came for your Pokémon!$"

KuraTown_House3_EventScript_Lady_Text_1:
# 21 "data/maps/KuraTown_House3/scripts.pory"
	.string "Sorry, I thought you were someone else.\p"
	.string "See, this little one came to me a while\n"
	.string "ago. There was a thunderstorm and it\l"
	.string "looked scared and lost.\p"
	.string "So I've been taking care of it while\n"
	.string "waiting for its master to show up!\p"
	.string "Looks like it's feeling a lot better now.\n"
	.string "Look how shiny his fur is! Such a pretty\l"
	.string "color, too!$"

KuraTown_House3_EventScript_Lady_Text_2:
# 43 "data/maps/KuraTown_House3/scripts.pory"
	.string "Don't worry, kitten, we'll find your\n"
	.string "master eventually!$"

KuraTown_House3_EventScript_Lady_Text_3:
# 56 "data/maps/KuraTown_House3/scripts.pory"
	.string "Sniffle… I'm going to miss him…$"

KuraTown_House3_EventScript_Lady_Text_4:
# 64 "data/maps/KuraTown_House3/scripts.pory"
	.string "That little lost kitten is reunited with\n"
	.string "its master? Do they seem happy\l"
	.string "together?\p"
	.string "Oh, how delightful!$"

KuraTown_House3_EventScript_EspeonGoesHome_Text_0:
# 76 "data/maps/KuraTown_House3/scripts.pory"
	.string "What? You're saying its master is\n"
	.string "waiting for him in Saku Village?\p"
	.string "… …\p"
	.string "I'd rather not try going over there,\n"
	.string "folks over at Saku Village are\l"
	.string "notoriously mean…\p"
	.string "But I guess… I can make an effort for\n"
	.string "this kitten here.$"

KuraTown_House3_EventScript_EspeonGoesHome_Text_1:
# 88 "data/maps/KuraTown_House3/scripts.pory"
	.string "Good news, sweetie! You're going home!$"

KuraTown_House3_EventScript_Espeon_Text_0:
# 118 "data/maps/KuraTown_House3/scripts.pory"
	.string "Speeee!$"

KuraTown_House3_EventScript_Espeon_Text_1:
# 124 "data/maps/KuraTown_House3/scripts.pory"
	.string "It looks happy and serene.$"

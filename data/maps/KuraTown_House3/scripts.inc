KuraTown_House3_MapScripts::
	.byte 0


KuraTown_House3_EventScript_Lady::
	lock
	compare VAR_SAKU_KURA_QUEST_ESPEON_STATE, 0
	goto_if_eq KuraTown_House3_EventScript_Lady_2
	compare VAR_SAKU_KURA_QUEST_ESPEON_STATE, 2
	goto_if_eq KuraTown_House3_EventScript_Lady_2
	compare VAR_SAKU_KURA_QUEST_ESPEON_STATE, 1
	goto_if_eq KuraTown_House3_EventScript_Lady_3
	compare VAR_SAKU_KURA_QUEST_ESPEON_STATE, 3
	goto_if_eq KuraTown_House3_EventScript_Lady_4
	compare VAR_SAKU_KURA_QUEST_ESPEON_STATE, 4
	goto_if_eq KuraTown_House3_EventScript_Lady_5
	compare VAR_SAKU_KURA_QUEST_ESPEON_STATE, 5
	goto_if_eq KuraTown_House3_EventScript_Lady_6
KuraTown_House3_EventScript_Lady_1:
	release
	return

KuraTown_House3_EventScript_Lady_2:
	faceplayer
	msgbox KuraTown_House3_EventScript_Lady_Text_0
	closemessage
	delay 60
	msgbox KuraTown_House3_EventScript_Lady_Text_1
	closemessage
	compare VAR_SAKU_KURA_QUEST_ESPEON_STATE, 0
	goto_if_eq KuraTown_House3_EventScript_Lady_15
	compare VAR_SAKU_KURA_QUEST_ESPEON_STATE, 2
	goto_if_eq KuraTown_House3_EventScript_Lady_16
KuraTown_House3_EventScript_Lady_14:
	applymovement 1, Common_Movement_FaceOriginalDirection
	goto KuraTown_House3_EventScript_Lady_1

KuraTown_House3_EventScript_Lady_3:
	faceplayer
	msgbox KuraTown_House3_EventScript_Lady_Text_2
	closemessage
	goto KuraTown_House3_EventScript_Lady_1

KuraTown_House3_EventScript_Lady_4:
	faceplayer
	call KuraTown_House3_EventScript_EspeonGoesHome
	goto KuraTown_House3_EventScript_Lady_1

KuraTown_House3_EventScript_Lady_5:
	faceplayer
	msgbox KuraTown_House3_EventScript_Lady_Text_3
	closemessage
	goto KuraTown_House3_EventScript_Lady_1

KuraTown_House3_EventScript_Lady_6:
	faceplayer
	msgbox KuraTown_House3_EventScript_Lady_Text_4
	closemessage
	goto KuraTown_House3_EventScript_Lady_1

KuraTown_House3_EventScript_Lady_15:
	setvar VAR_SAKU_KURA_QUEST_ESPEON_STATE, 1
	applymovement 1, Common_Movement_FaceOriginalDirection
	goto KuraTown_House3_EventScript_Lady_14

KuraTown_House3_EventScript_Lady_16:
	delay 60
	call KuraTown_House3_EventScript_EspeonGoesHome
	goto KuraTown_House3_EventScript_Lady_14


KuraTown_House3_EventScript_EspeonGoesHome::
	faceplayer
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	delay 48
	msgbox KuraTown_House3_EventScript_EspeonGoesHome_Text_0
	closemessage
	applymovement 1, Common_Movement_FaceLeft
	applymovement 2, Common_Movement_FaceRight
	waitmovement 0
	msgbox KuraTown_House3_EventScript_EspeonGoesHome_Text_1
	closemessage
	applymovement 2, JumpInJoy
	setseenmon SPECIES_ESPEON
	playmoncry SPECIES_ESPEON, CRY_MODE_NORMAL
	waitmoncry
	delay 40
	fadescreen FADE_TO_BLACK
	removeobject 2
	delay 60
	fadescreen FADE_FROM_BLACK
	delay 40
	msgbox KuraTown_House3_EventScript_Lady_Text_3
	closemessage
	setvar VAR_SAKU_KURA_QUEST_ESPEON_STATE, 4
	setflag FLAG_SAKU_KURA_HIDE_ESPEON_LADYS_HOUSE
	return


KuraTown_House3_EventScript_Espeon::
	lock
	faceplayer
	setseenmon SPECIES_ESPEON
	playmoncry SPECIES_ESPEON, CRY_MODE_NORMAL
	msgbox KuraTown_House3_EventScript_Espeon_Text_0
	waitmoncry
	closemessage
	delay 30
	msgbox KuraTown_House3_EventScript_Espeon_Text_1
	release
	return


JumpInJoy:
	jump_in_place_right
	step_end

KuraTown_House3_EventScript_Lady_Text_0:
	.string "Hello! Ah, you came for your\n"
	.string "Pokémon!$"

KuraTown_House3_EventScript_Lady_Text_1:
	.string "Sorry, I thought you were someone\n"
	.string "else.\p"
	.string "See, this little one came to me a\n"
	.string "while ago. There was a\l"
	.string "thunderstorm and it looked scared\l"
	.string "and lost.\p"
	.string "So I've been taking care of it\n"
	.string "while waiting for its master to\l"
	.string "show up!\p"
	.string "Looks like it's feeling a lot better\n"
	.string "now. Look how shiny his fur is!\l"
	.string "Such a pretty color, too!$"

KuraTown_House3_EventScript_Lady_Text_2:
	.string "Don't worry, kitten, we'll find your\n"
	.string "master eventually!$"

KuraTown_House3_EventScript_Lady_Text_3:
	.string "Sniffle… I'm going to miss him…$"

KuraTown_House3_EventScript_Lady_Text_4:
	.string "That little lost kitten is reunited\n"
	.string "with its master? Do they seem\l"
	.string "happy together?\p"
	.string "Oh, how delightful!$"

KuraTown_House3_EventScript_EspeonGoesHome_Text_0:
	.string "What? You're saying its master is\n"
	.string "waiting for him in Saku Village?\p"
	.string "… …\p"
	.string "I'd rather not try going over\n"
	.string "there, folks over at Saku Village\l"
	.string "are notoriously mean…\p"
	.string "But I guess… I can make an effort\n"
	.string "for this kitten here.$"

KuraTown_House3_EventScript_EspeonGoesHome_Text_1:
	.string "Good news, sweetie! You're going\n"
	.string "home!$"

KuraTown_House3_EventScript_Espeon_Text_0:
	.string "Speeee!$"

KuraTown_House3_EventScript_Espeon_Text_1:
	.string "It looks happy and serene.$"

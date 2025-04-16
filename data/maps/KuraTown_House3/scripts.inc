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
	speakername KuraTown_House3_EventScript_Lady_Text_0
	msgbox KuraTown_House3_EventScript_Lady_Text_1
	closemessage
	delay 60
	speakername KuraTown_House3_EventScript_Lady_Text_0
	msgbox KuraTown_House3_EventScript_Lady_Text_2
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
	speakername KuraTown_House3_EventScript_Lady_Text_0
	msgbox KuraTown_House3_EventScript_Lady_Text_3
	closemessage
	goto KuraTown_House3_EventScript_Lady_1

KuraTown_House3_EventScript_Lady_4:
	faceplayer
	call KuraTown_House3_EventScript_EspeonGoesHome
	goto KuraTown_House3_EventScript_Lady_1

KuraTown_House3_EventScript_Lady_5:
	faceplayer
	speakername KuraTown_House3_EventScript_Lady_Text_0
	msgbox KuraTown_House3_EventScript_Lady_Text_4
	closemessage
	goto KuraTown_House3_EventScript_Lady_1

KuraTown_House3_EventScript_Lady_6:
	faceplayer
	speakername KuraTown_House3_EventScript_Lady_Text_0
	msgbox KuraTown_House3_EventScript_Lady_Text_5
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
	speakername KuraTown_House3_EventScript_Lady_Text_0
	msgbox KuraTown_House3_EventScript_EspeonGoesHome_Text_0
	closemessage
	applymovement 1, Common_Movement_FaceLeft
	applymovement 2, Common_Movement_FaceRight
	waitmovement 0
	speakername KuraTown_House3_EventScript_Lady_Text_0
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
	speakername KuraTown_House3_EventScript_Lady_Text_0
	msgbox KuraTown_House3_EventScript_EspeonGoesHome_Text_2
	closemessage
	setvar VAR_SAKU_KURA_QUEST_ESPEON_STATE, 4
	setflag FLAG_SAKU_KURA_HIDE_ESPEON_LADYS_HOUSE
	return


KuraTown_House3_EventScript_Espeon::
	lock
	faceplayer
	setseenmon SPECIES_ESPEON
	setspeakertomonname SPECIES_ESPEON
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
	.string "Woman$"

KuraTown_House3_EventScript_Lady_Text_1:
	.string "Hello! Ah, you came for your Pokémon!$"

KuraTown_House3_EventScript_Lady_Text_2:
	.string "Sorry, I thought you were someone\n"
	.string "else.\p"
	.string "See, this little one came to me a while\n"
	.string "ago. There was a thunderstorm and it\l"
	.string "looked scared and lost.\p"
	.string "So I've been taking care of it while\n"
	.string "waiting for its master to show up!\p"
	.string "Looks like it's feeling a lot better\n"
	.string "now. Look how shiny his fur is! Such a\l"
	.string "pretty color, too!$"

KuraTown_House3_EventScript_Lady_Text_3:
	.string "Don't worry, kitten, we'll find your\n"
	.string "master eventually!$"

KuraTown_House3_EventScript_Lady_Text_4:
	.string "Sniffle… I'm going to miss him…$"

KuraTown_House3_EventScript_Lady_Text_5:
	.string "That little lost kitten is reunited\n"
	.string "with its master? Do they seem happy\l"
	.string "together?\p"
	.string "Oh, how delightful!$"

KuraTown_House3_EventScript_EspeonGoesHome_Text_0:
	.string "What? You're saying its master is\n"
	.string "waiting for him in Saku Village?\p"
	.string "… …\p"
	.string "I'd rather not try going over there,\n"
	.string "folks over at Saku Village are\l"
	.string "notoriously mean…\p"
	.string "But I guess… I can make an effort for\n"
	.string "this kitten here.$"

KuraTown_House3_EventScript_EspeonGoesHome_Text_1:
	.string "Good news, sweetie! You're going home!$"

KuraTown_House3_EventScript_EspeonGoesHome_Text_2:
	.string "Sniffle… I'm going to miss that little\n"
	.string "kitten…$"

KuraTown_House3_EventScript_Espeon_Text_0:
	.string "Speeee!$"

KuraTown_House3_EventScript_Espeon_Text_1:
	.string "It looks happy and serene.$"

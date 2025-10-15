ChatotPost_EventScript_Chatot::
	lockall
	setseenmon SPECIES_CHATOT
	setchatotlastspeaker
	waitse
	playse SE_LEDGE
	applymovement VAR_LAST_TALKED, ChatotPost_EventScript_Chatot_Movement_0
	waitmovement VAR_LAST_TALKED
	waitse
	playmoncry SPECIES_CHATOT, CRY_MODE_NORMAL
	applymovement VAR_LAST_TALKED, ChatotPost_EventScript_Chatot_Movement_1
	delay 16
	checkchatotpost
	compare VAR_RESULT, 0
	goto_if_ne ChatotPost_EventScript_Chatot_2
	setspeakertomonname SPECIES_CHATOT
	msgbox ChatotPost_EventScript_Chatot_Text_2
	closemessage
	releaseall
	end

ChatotPost_EventScript_Chatot_1:
	playse SE_LEDGE
	applymovement VAR_LAST_TALKED, ChatotPost_EventScript_Chatot_Movement_0
	waitse
	playmoncry SPECIES_CHATOT, CRY_MODE_NORMAL
	setspeakertomonname SPECIES_CHATOT
	msgbox ChatotPost_EventScript_Chatot_Text_3, MSGBOX_DEFAULT
	releaseall
	end

ChatotPost_EventScript_Chatot_2:
	setspeakertomonname SPECIES_CHATOT
	checkchatotpostnumber
	compare VAR_RESULT, 1
	goto_if_eq ChatotPost_EventScript_Chatot_6
	buffernumberstring STR_VAR_2, VAR_RESULT
	msgbox ChatotPost_EventScript_Chatot_Text_1
ChatotPost_EventScript_Chatot_5:
	closemessage
	delay 24
	readchatotpost
	checkchatotpost
	compare VAR_RESULT, 0
	goto_if_ne ChatotPost_EventScript_Chatot_10
ChatotPost_EventScript_Chatot_9:
	checkchatotpost
	compare VAR_RESULT, 0
	goto_if_ne ChatotPost_EventScript_Chatot_12
	goto ChatotPost_EventScript_Chatot_1

ChatotPost_EventScript_Chatot_6:
	msgbox ChatotPost_EventScript_Chatot_Text_0
	goto ChatotPost_EventScript_Chatot_5

ChatotPost_EventScript_Chatot_10:
	call ChatotPost_EventScript_NextMessage
	goto ChatotPost_EventScript_Chatot_9

ChatotPost_EventScript_Chatot_12:
	call ChatotPost_EventScript_NextMessage
	goto ChatotPost_EventScript_Chatot_1


ChatotPost_EventScript_NextMessage:
	playmoncry SPECIES_CHATOT, CRY_MODE_NORMAL
	applymovement VAR_LAST_TALKED, ChatotPost_EventScript_Chatot_Movement_1
	setspeakertomonname SPECIES_CHATOT
	random 4
	switch VAR_RESULT
	case 0, ChatotPost_EventScript_NextMessage_3
	case 1, ChatotPost_EventScript_NextMessage_4
	case 2, ChatotPost_EventScript_NextMessage_5
	case 3, ChatotPost_EventScript_NextMessage_6
ChatotPost_EventScript_NextMessage_1:
	readchatotpost
	return

ChatotPost_EventScript_NextMessage_3:
	msgbox Text_Chatot_Next1
	goto ChatotPost_EventScript_NextMessage_1

ChatotPost_EventScript_NextMessage_4:
	msgbox Text_Chatot_Next2
	goto ChatotPost_EventScript_NextMessage_1

ChatotPost_EventScript_NextMessage_5:
	msgbox Text_Chatot_Next3
	goto ChatotPost_EventScript_NextMessage_1

ChatotPost_EventScript_NextMessage_6:
	msgbox Text_Chatot_Next4
	goto ChatotPost_EventScript_NextMessage_1


ChatotPost_EventScript_EmptyPost::
	lock
	setnamedmon SPECIES_CHATOT
	msgbox ChatotPost_EventScript_EmptyPost_Text_0
	closemessage
	release
	return


ChatotPost_EventScript_None::
	return


ChatotPost_EventScript_FromHariko::
	setspeakertomonname SPECIES_CHATOT
	msgbox ChatotPost_EventScript_FromHariko_Text_0
	fadescreen FADE_TO_BLACK
	delay 48
	closemessage
	fadescreen FADE_FROM_BLACK
	setspeakertomonname SPECIES_CHATOT
	msgbox ChatotPost_EventScript_FromHariko_Text_1
	closemessage
	setnamedmon SPECIES_CHATOT
	setnamedmon SPECIES_WAILORD
	return


ChatotPost_EventScript_FromBigSis::
	special GetPlayerBrotherSisterString
	setspeakertomonname SPECIES_CHATOT
	msgbox ChatotPost_EventScript_FromBigSis_Text_0
	closemessage
	giveitem ITEM_ENTEI_STATUETTE
	setnamedmon SPECIES_CHATOT
	return


ChatotPost_EventScript_TrainerMessage::
	setspeakertomonname SPECIES_CHATOT
	msgbox gStringVar4
	closemessage
	return


ChatotPost_EventScript_Chatot_Movement_0:
	jump_in_place_down
	step_end

ChatotPost_EventScript_Chatot_Movement_1:
	emote_music
	step_end

ChatotPost_EventScript_Chatot_Text_0:
	.string "SQWAK!{PAUSE 8} POST FOR YOU!{PAUSE 8} SQWAK!{PAUSE 8}\n"
	.string "THIS IS FROM “{STR_VAR_1}”…$"

ChatotPost_EventScript_Chatot_Text_1:
	.string "SQWAK!{PAUSE 8} POST FOR YOU!{PAUSE 8} SQWAK!{PAUSE 8}\n"
	.string "{STR_VAR_2} NEW MESSAGES!{PAUSE 8} SQWAK!\p"
	.string "FIRST MESSAGE FROM\n"
	.string "“{STR_VAR_1}”…$"

ChatotPost_EventScript_Chatot_Text_2:
	.string "SQWAK!{PAUSE 8} NO MORE POST!$"

ChatotPost_EventScript_Chatot_Text_3:
	.string "SQWAK!$"

ChatotPost_EventScript_EmptyPost_Text_0:
	.string "It reads: “Chatot Post”.\n"
	.string "… …No Chatot in sight!$"

ChatotPost_EventScript_FromHariko_Text_0:
	.string "“Hello {PLAYER}!\n"
	.string "Do you want to hear a fun fact?\p"
	.string "Did you know that Wailord aren't\n"
	.string "actually the biggest living things?\p"
	.string "The biggest living things are actually\n"
	.string "mushrooms, because…$"

ChatotPost_EventScript_FromHariko_Text_1:
	.string "…also did you know…\p"
	.string "Wait… Chatot!\p"
	.string "Come back, Chatot!”$"

ChatotPost_EventScript_FromBigSis_Text_0:
	.string "“Chatot, are you listening to me?\n"
	.string "Hey, look this way-{PAUSE 8} pspsps!\p"
	.string "Ahem, hey little {STR_VAR_1}!\n"
	.string "Hope you're missing me already!\p"
	.string "You forgot your lucky Entei\n"
	.string "Statuette when you left.\p"
	.string "I like the tradition, so indulge me,\n"
	.string "okay? Please? Everyone carries one!\p"
	.string "See you soon {PLAYER}, love you.”$"

Text_Chatot_Next1:
	.string "HERE'S ANOTHER FROM\n"
	.string "“{STR_VAR_1}”!{PAUSE 8}\n"
	.string "SQWAK!$"

Text_Chatot_Next2:
	.string "SQWAK!{PAUSE 8}\n"
	.string "NEXT MESSAGE, FROM “{STR_VAR_1}”!$"

Text_Chatot_Next3:
	.string "SQWAK!{PAUSE 8} ANOTHER MESSAGE!{PAUSE 8}\n"
	.string "FROM “{STR_VAR_1}”!{PAUSE 8} SQWAK!$"

Text_Chatot_Next4:
	.string "SQWAK SQWAK!{PAUSE 8} ONE MORE!\n"
	.string "FROM “{STR_VAR_1}”!$"

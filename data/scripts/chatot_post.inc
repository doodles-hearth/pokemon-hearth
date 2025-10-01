ChatotPost_EventScript_Post::
	msgbox ChatotPost_EventScript_Post_Text_0, MSGBOX_SIGN
	return


ChatotPost_EventScript_Chatot::
	lockall
	checkchatotpost
	compare VAR_RESULT, 0
	goto_if_ne ChatotPost_EventScript_Chatot_2
	msgbox ChatotPost_EventScript_Chatot_Text_1, MSGBOX_DEFAULT
	releaseall
	end

ChatotPost_EventScript_Chatot_1:
	checkchatotpost
	compare VAR_RESULT, 0
	goto_if_ne ChatotPost_EventScript_Chatot_6
ChatotPost_EventScript_Chatot_5:
	checkchatotpost
	compare VAR_RESULT, 0
	goto_if_ne ChatotPost_EventScript_Chatot_9
ChatotPost_EventScript_Chatot_8:
	msgbox ChatotPost_EventScript_Chatot_Text_4, MSGBOX_DEFAULT
	releaseall
	end

ChatotPost_EventScript_Chatot_2:
	msgbox ChatotPost_EventScript_Chatot_Text_0, MSGBOX_DEFAULT
	readchatotpost
	goto ChatotPost_EventScript_Chatot_1

ChatotPost_EventScript_Chatot_6:
	msgbox ChatotPost_EventScript_Chatot_Text_2, MSGBOX_DEFAULT
	readchatotpost
	goto ChatotPost_EventScript_Chatot_5

ChatotPost_EventScript_Chatot_9:
	msgbox ChatotPost_EventScript_Chatot_Text_3, MSGBOX_DEFAULT
	readchatotpost
	goto ChatotPost_EventScript_Chatot_8


ChatotPost_EventScript_None::
	return


ChatotPost_EventScript_FromHaru::
	msgbox ChatotPost_EventScript_FromHaru_Text_0, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	delay 48
	closemessage
	fadescreen FADE_FROM_BLACK
	msgbox ChatotPost_EventScript_FromHaru_Text_1, MSGBOX_DEFAULT
	return


ChatotPost_EventScript_Post_Text_0:
	.string "It's a Chatot Post.$"

ChatotPost_EventScript_Chatot_Text_0:
	.string "SQWAK! POST FOR YOU! SQWAK!$"

ChatotPost_EventScript_Chatot_Text_1:
	.string "SQWAK! NO MORE POST! SQUAK!$"

ChatotPost_EventScript_Chatot_Text_2:
	.string "SQWAK! MORE POST! SQWAK$"

ChatotPost_EventScript_Chatot_Text_3:
	.string "SQWAK! FINAL POST! SQWAK!$"

ChatotPost_EventScript_Chatot_Text_4:
	.string "SQWAK!$"

ChatotPost_EventScript_FromHaru_Text_0:
	.string "Hi bestie!\p"
	.string "Do you want to hear a fun fact?\p"
	.string "Did you know that wailord aren't\n"
	.string "actually the biggest living things?\p"
	.string "the biggest living things are actually\n"
	.string "mushrooms, because…$"

ChatotPost_EventScript_FromHaru_Text_1:
	.string "…also did you know…\p"
	.string "Wait… Chatot!\p"
	.string "Come back Chatot!$"

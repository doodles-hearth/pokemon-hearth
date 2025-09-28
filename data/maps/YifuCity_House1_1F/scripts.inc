YifuCity_House1_1F_MapScripts::
	.byte 0


YifuCity_House1_1F_EventScript_Dad::
	lock
	faceplayer
	setspeaker YifuCity_House1_1F_EventScript_Dad_Text_0
	msgbox YifuCity_House1_1F_EventScript_Dad_Text_1
	closemessage
	release
	return


YifuCity_House1_1F_EventScript_Mom::
	lock
	faceplayer
	setspeaker YifuCity_House1_1F_EventScript_Mom_Text_0
	msgbox YifuCity_House1_1F_EventScript_Mom_Text_1
	closemessage
	release
	return


YifuCity_House1_1F_EventScript_Dad_Text_0:
	.string "Man$"

YifuCity_House1_1F_EventScript_Dad_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_UUME_MAN_2 EMOTE_NORMAL}Our kids are constantly yelling and\n"
	.string "running and bickering…\p"
	.string "I can't ever get anything done!$"

YifuCity_House1_1F_EventScript_Mom_Text_0:
	.string "Woman$"

YifuCity_House1_1F_EventScript_Mom_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_UUME_WOMAN_2 EMOTE_NORMAL}I bought the children two different\n"
	.string "dolls at the festival in Hanabi City…\p"
	.string "But now they're fighting over who has\n"
	.string "which!\p"
	.string "I should have gotten two identical\n"
	.string "dolls…$"

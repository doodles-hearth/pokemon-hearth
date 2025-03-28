YifuCity_House1_1F_MapScripts::
	.byte 0


YifuCity_House1_1F_EventScript_Dad::
	lock
	faceplayer
	speakername YifuCity_House1_1F_EventScript_Dad_Text_0
	msgbox YifuCity_House1_1F_EventScript_Dad_Text_1
	closemessage
	release
	return


YifuCity_House1_1F_EventScript_Mom::
	lock
	faceplayer
	speakername YifuCity_House1_1F_EventScript_Mom_Text_0
	msgbox YifuCity_House1_1F_EventScript_Mom_Text_1
	closemessage
	release
	return


YifuCity_House1_1F_EventScript_Dad_Text_0:
	.string "Man$"

YifuCity_House1_1F_EventScript_Dad_Text_1:
	.string "Our kids are constantly yelling and\n"
	.string "running and bickering…\p"
	.string "I can't ever get anything done!$"

YifuCity_House1_1F_EventScript_Mom_Text_0:
	.string "Woman$"

YifuCity_House1_1F_EventScript_Mom_Text_1:
	.string "I bought the children two different\n"
	.string "dolls at the festival in Hanabi\l"
	.string "City…\p"
	.string "But now they're fighting over who\n"
	.string "has which!\p"
	.string "I should have gotten two identical\n"
	.string "dolls…$"

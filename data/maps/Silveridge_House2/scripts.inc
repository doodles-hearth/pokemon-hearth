Silveridge_House2_MapScripts::
	.byte 0


Silveridge_House2_EventScript_Woman::
	lock
	faceplayer
	speakername Silveridge_House2_EventScript_Woman_Text_0
	msgbox Silveridge_House2_EventScript_Woman_Text_1
	closemessage
	release
	return


Silveridge_House2_EventScript_Woman_Text_0:
	.string "Woman$"

Silveridge_House2_EventScript_Woman_Text_1:
	.string "TODO EVA$"

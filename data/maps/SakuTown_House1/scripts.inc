SakuTown_House1_MapScripts::
	.byte 0


SakuTown_House1_EventScript_Tama::
	lock
	msgbox SakuTown_House1_EventScript_Tama_Text_0
	closemessage
	release
	return


SakuTown_House1_EventScript_Tama_Text_0:
	.string "Please go away. Leave me alone.$"

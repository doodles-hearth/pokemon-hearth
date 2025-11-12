Soulkeep_Library_2F_MapScripts::
	.byte 0


Soulkeep_Library_2F_EventScript_Employee::
	lock
	faceplayer
	setspeaker Soulkeep_Library_2F_EventScript_Employee_Text_0
	msgbox Soulkeep_Library_2F_EventScript_Employee_Text_1
	closemessage
	release
	return


Soulkeep_Library_2F_EventScript_Hariko::
	return


Soulkeep_Library_2F_EventScript_Employee_Text_0:
	.string "Librarian$"

Soulkeep_Library_2F_EventScript_Employee_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_UUME_VALET EMOTE_NORMAL}{FONT_SMALL}Shhhhhh, keep it down!{FONT_NORMAL}$"

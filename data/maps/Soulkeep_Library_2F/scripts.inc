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


Soulkeep_Library_2F_EventScript_EmployeeBlocksVIPArea::
	lock
	faceplayer
	setspeaker Soulkeep_Library_2F_EventScript_Employee_Text_0
	msgbox Soulkeep_Library_2F_EventScript_EmployeeBlocksVIPArea_Text_0
	closemessage
	release
	return


Soulkeep_Library_2F_EventScript_Hariko::
	return


Soulkeep_Library_2F_EventScript_Employee_Text_0:
	.string "Librarian$"

Soulkeep_Library_2F_EventScript_Employee_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_UUME_VALET EMOTE_NORMAL}{FONT_SMALL}Shhhhhh, keep it down!{FONT_NORMAL}$"

Soulkeep_Library_2F_EventScript_EmployeeBlocksVIPArea_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_UUME_VALET EMOTE_NORMAL}The upper floor holds very old and\n"
	.string "rare books and scrolls.\p"
	.string "We can't let just any child get their\n"
	.string "dirty little paws all over the pages.\p"
	.string "As such, only holders of at least X\n"
	.string "official Tokens have access.{FONT_NORMAL}$"

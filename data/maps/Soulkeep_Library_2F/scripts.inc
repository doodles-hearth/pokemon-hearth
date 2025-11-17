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
	lock
	faceplayer
	msgbox Soulkeep_Library_2F_EventScript_Hariko_Text_0
	closemessage
	release
	return


Soulkeep_Library_2F_EventScript_Employee_Text_0:
	.string "Librarian$"

Soulkeep_Library_2F_EventScript_Employee_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_UUME_VALET EMOTE_NORMAL}{FONT_SMALL}Shhhhhh, keep it down!{FONT_NORMAL}$"

Soulkeep_Library_2F_EventScript_EmployeeBlocksVIPArea_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_UUME_VALET EMOTE_NORMAL}{FONT_SMALL}The upper floor holds very old and\n"
	.string "rare books and scrolls.\p"
	.string "We can't let just any child get their\n"
	.string "dirty little paws all over the pages.\p"
	.string "As such, only holders of at least four\n"
	.string "official Tokens have access.{FONT_NORMAL}$"

Soulkeep_Library_2F_EventScript_Hariko_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_UUME_VALET EMOTE_NORMAL}{CREATE_MUGSHOT MUGSHOT_HARIKO}{FONT_SMALL}Hello, {PLAYER}.\n"
	.string "\p"
	.string "I am looking for information on the\n"
	.string "Decay.\p"
	.string "Did it happen before?\n"
	.string "Is there a way to fix it?\l"
	.string "I am not finding anything…\p"
	.string "I wonder if the old books on the third\n"
	.string "floor would be more useful.{FONT_NORMAL}$"

Soulkeep_HouseDoll_MapScripts::
	.byte 0


Soulkeep_HouseDoll_EventScript_Mom::
	lock
	faceplayer
	setspeaker SP_NAME_WOMAN
	msgbox Soulkeep_HouseDoll_EventScript_Mom_Text_0
	closemessage
	release
	return


Soulkeep_HouseDoll_EventScript_Dad::
	lock
	faceplayer
	setspeaker SP_NAME_MAN
	msgbox Soulkeep_HouseDoll_EventScript_Dad_Text_0
	closemessage
	release
	return


Soulkeep_HouseDoll_EventScript_Mom_Text_0:
	.string "Our little girl has such a wild\n"
	.string "imagination!$"

Soulkeep_HouseDoll_EventScript_Dad_Text_0:
	.string "Our daughter's been having very vivid\n"
	.string "nightmares lately.\p"
	.string "It must be this town's awful\n"
	.string "atmosphere…$"

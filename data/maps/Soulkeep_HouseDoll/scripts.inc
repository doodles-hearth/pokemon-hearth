Soulkeep_HouseDoll_MapScripts::
	.byte 0


Soulkeep_HouseDoll_EventScript_Mom::
	lock
	faceplayer
	speakername Soulkeep_HouseDoll_EventScript_Mom_Text_0
	msgbox Soulkeep_HouseDoll_EventScript_Mom_Text_1
	closemessage
	release
	return


Soulkeep_HouseDoll_EventScript_Dad::
	lock
	faceplayer
	speakername Soulkeep_HouseDoll_EventScript_Dad_Text_0
	msgbox Soulkeep_HouseDoll_EventScript_Dad_Text_1
	closemessage
	release
	return


Soulkeep_HouseDoll_EventScript_Mom_Text_0:
	.string "Woman$"

Soulkeep_HouseDoll_EventScript_Mom_Text_1:
	.string "Our little girl has such a wild\n"
	.string "imagination!$"

Soulkeep_HouseDoll_EventScript_Dad_Text_0:
	.string "Man$"

Soulkeep_HouseDoll_EventScript_Dad_Text_1:
	.string "Our daughter's been having very\n"
	.string "vivid nightmares lately.\p"
	.string "It must be this town's awful\n"
	.string "atmosphere…$"

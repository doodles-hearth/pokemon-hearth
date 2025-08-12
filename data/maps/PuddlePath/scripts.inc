PuddlePath_MapScripts::
	.byte 0


PuddlePath_EventScript_Farmer::
	lock
	faceplayer
	speakername PuddlePath_EventScript_Farmer_Text_0
	msgbox PuddlePath_EventScript_Farmer_Text_1
	release
	return


PuddlePath_EventScript_Farmer_Text_0:
	.string "Farmer$"

PuddlePath_EventScript_Farmer_Text_1:
	.string "You're in what's probably the most\n"
	.string "fertile stretch of land in all of Toku.\p"
	.string "The nearby forest enriches the soil,\n"
	.string "and the water stream is rich with\l"
	.string "volcanic ashes.\p"
	.string "Farmers from both Soulkeep and\n"
	.string "Hanabi City share the land.$"

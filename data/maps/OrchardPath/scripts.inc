OrchardPath_MapScripts::
	.byte 0


OrchardPath_EventScript_UumeForestSoulkeepSign::
	msgbox OrchardPath_EventScript_UumeForestSoulkeepSign_Text_0, MSGBOX_SIGN
	return


OrchardPath_EventScript_GuardHouseSign::
	msgbox OrchardPath_EventScript_GuardHouseSign_Text_0, MSGBOX_SIGN
	return


OrchardPath_EventScript_Junko::
	trainerbattle_single TRAINER_JUNKO, OrchardPath_EventScript_Junko_Text_0, OrchardPath_EventScript_Junko_Text_1
	speakername OrchardPath_EventScript_Junko_Text_2
	msgbox OrchardPath_EventScript_Junko_Text_3, MSGBOX_AUTOCLOSE
	return


OrchardPath_EventScript_Mami::
	trainerbattle_single TRAINER_MAMI, OrchardPath_EventScript_Mami_Text_0, OrchardPath_EventScript_Mami_Text_1
	speakername OrchardPath_EventScript_Mami_Text_2
	msgbox OrchardPath_EventScript_Mami_Text_3, MSGBOX_AUTOCLOSE
	return


OrchardPath_EventScript_UumeForestSoulkeepSign_Text_0:
	.string "{UP_ARROW} Uume Forest\n"
	.string "{LEFT_ARROW} Soulkeep$"

OrchardPath_EventScript_GuardHouseSign_Text_0:
	.string "Guard House$"

OrchardPath_EventScript_Junko_Text_0:
	.string "I'm gathering ripe Berries to feed my\n"
	.string "Pokémon!$"

OrchardPath_EventScript_Junko_Text_1:
	.string "He ought to eat more Berries…$"

OrchardPath_EventScript_Junko_Text_2:
	.string "Junko$"

OrchardPath_EventScript_Junko_Text_3:
	.string "My Pokémon is insatiable!\n"
	.string "I need to scour my local Library for\l"
	.string "more Berry recipes!$"

OrchardPath_EventScript_Mami_Text_0:
	.string "Hehehehe… This place is haunted at\n"
	.string "night! Are you scared?$"

OrchardPath_EventScript_Mami_Text_1:
	.string "H-how could my ghosts lose to a mere\n"
	.string "mortal?$"

OrchardPath_EventScript_Mami_Text_2:
	.string "Mami$"

OrchardPath_EventScript_Mami_Text_3:
	.string "I wanted to catch some more ghosts\n"
	.string "at the Graveyard, but…\l"
	.string "It's a little TOO scary…$"

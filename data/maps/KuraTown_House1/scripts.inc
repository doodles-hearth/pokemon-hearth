KuraTown_House1_MapScripts::
	.byte 0


KuraTown_House1_OldWoman::
	lock
	faceplayer
	msgbox KuraTown_House1_OldWoman_Text_0
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox KuraTown_House1_OldWoman_Text_1
	closemessage
	release
	return


KuraTown_House1_OldWomansSon::
	msgbox KuraTown_House1_OldWomansSon_Text_0, MSGBOX_NPC
	return


KuraTown_House1_Growlithe::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_GROWLITHE, CRY_MODE_NORMAL
	msgbox KuraTown_House1_Growlithe_Text_0
	waitmoncry
	release
	return


KuraTown_House1_OldWoman_Text_0:
	.string "You look like you're tired, young one.\n"
	.string "Please rest a while.$"

KuraTown_House1_OldWoman_Text_1:
	.string "I wish you strength on your journey.$"

KuraTown_House1_OldWomansSon_Text_0:
	.string "The Pokémon league organization\n"
	.string "didn't see fit to build a Pokémon\l"
	.string "refuge in our village, but those jerks\l"
	.string "over at Saku Village won't let us use\l"
	.string "theirs.\p"
	.string "So my mother has to work hard to heal\n"
	.string "all the villager's Pokémon.\p"
	.string "It's not fair!$"

KuraTown_House1_Growlithe_Text_0:
	.string "Wah!$"

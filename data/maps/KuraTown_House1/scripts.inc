KuraTown_House1_MapScripts::
	.byte 0


KuraTown_House1_OldWoman::
# 6 "data/maps/KuraTown_House1/scripts.pory"
	lock
# 7 "data/maps/KuraTown_House1/scripts.pory"
	faceplayer
# 8 "data/maps/KuraTown_House1/scripts.pory"
	msgbox KuraTown_House1_OldWoman_Text_0
# 11 "data/maps/KuraTown_House1/scripts.pory"
	closemessage
# 12 "data/maps/KuraTown_House1/scripts.pory"
	call Common_EventScript_OutOfCenterPartyHeal
# 13 "data/maps/KuraTown_House1/scripts.pory"
	msgbox KuraTown_House1_OldWoman_Text_1
# 16 "data/maps/KuraTown_House1/scripts.pory"
	closemessage
# 17 "data/maps/KuraTown_House1/scripts.pory"
	release
	return


KuraTown_House1_OldWomansSon::
# 21 "data/maps/KuraTown_House1/scripts.pory"
	msgbox KuraTown_House1_OldWomansSon_Text_0, MSGBOX_NPC
	return


KuraTown_House1_Growlithe::
# 29 "data/maps/KuraTown_House1/scripts.pory"
	lock
# 30 "data/maps/KuraTown_House1/scripts.pory"
	faceplayer
# 31 "data/maps/KuraTown_House1/scripts.pory"
	waitse
# 32 "data/maps/KuraTown_House1/scripts.pory"
	playmoncry SPECIES_GROWLITHE, CRY_MODE_NORMAL
# 33 "data/maps/KuraTown_House1/scripts.pory"
	msgbox KuraTown_House1_Growlithe_Text_0
# 36 "data/maps/KuraTown_House1/scripts.pory"
	waitmoncry
# 37 "data/maps/KuraTown_House1/scripts.pory"
	release
	return


KuraTown_House1_OldWoman_Text_0:
# 9 "data/maps/KuraTown_House1/scripts.pory"
	.string "You look like you're tired, young one.\n"
	.string "Please rest a while.$"

KuraTown_House1_OldWoman_Text_1:
# 14 "data/maps/KuraTown_House1/scripts.pory"
	.string "I wish you strength on your journey.$"

KuraTown_House1_OldWomansSon_Text_0:
# 22 "data/maps/KuraTown_House1/scripts.pory"
	.string "The Pokémon league organization\n"
	.string "didn't see fit to build a Pokémon\l"
	.string "refuge in our village, but those jerks\l"
	.string "over at Saku Village won't let us use\l"
	.string "theirs.\p"
	.string "So my mother has to work hard to heal\n"
	.string "all the villager's Pokémon.\p"
	.string "It's not fair!$"

KuraTown_House1_Growlithe_Text_0:
# 34 "data/maps/KuraTown_House1/scripts.pory"
	.string "Wah!$"
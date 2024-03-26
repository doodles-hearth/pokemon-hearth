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
	call Common_EventScript_OutOfCenterPartyHeal
# 12 "data/maps/KuraTown_House1/scripts.pory"
	msgbox KuraTown_House1_OldWoman_Text_1
# 15 "data/maps/KuraTown_House1/scripts.pory"
	release
	return


KuraTown_House1_OldWomansSon::
# 19 "data/maps/KuraTown_House1/scripts.pory"
	lock
# 20 "data/maps/KuraTown_House1/scripts.pory"
	faceplayer
# 21 "data/maps/KuraTown_House1/scripts.pory"
	msgbox KuraTown_House1_OldWomansSon_Text_0
# 26 "data/maps/KuraTown_House1/scripts.pory"
	release
	return


KuraTown_House1_Growlithe::
# 30 "data/maps/KuraTown_House1/scripts.pory"
	lock
# 31 "data/maps/KuraTown_House1/scripts.pory"
	faceplayer
# 32 "data/maps/KuraTown_House1/scripts.pory"
	waitse
# 33 "data/maps/KuraTown_House1/scripts.pory"
	playmoncry SPECIES_GROWLITHE, CRY_MODE_NORMAL
# 34 "data/maps/KuraTown_House1/scripts.pory"
	msgbox KuraTown_House1_Growlithe_Text_0
# 37 "data/maps/KuraTown_House1/scripts.pory"
	waitmoncry
# 38 "data/maps/KuraTown_House1/scripts.pory"
	release
	return


KuraTown_House1_OldWoman_Text_0:
# 9 "data/maps/KuraTown_House1/scripts.pory"
	.string "You look like you're tired, young one.\n"
	.string "Please rest a while.$"

KuraTown_House1_OldWoman_Text_1:
# 13 "data/maps/KuraTown_House1/scripts.pory"
	.string "I wish you strength on your journey.$"

KuraTown_House1_OldWomansSon_Text_0:
# 22 "data/maps/KuraTown_House1/scripts.pory"
	.string "The Pokémon league organization didn't\n"
	.string "see fit to build a Pokémon refuge in our\l"
	.string "village, but those jerks over at Saku\l"
	.string "Village won't let us use theirs.\p"
	.string "So my mother has to work hard to heal\n"
	.string "all the villager's Pokémon.\p"
	.string "It's not fair!$"

KuraTown_House1_Growlithe_Text_0:
# 35 "data/maps/KuraTown_House1/scripts.pory"
	.string "Wah!$"

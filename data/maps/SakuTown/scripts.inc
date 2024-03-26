SakuTown_MapScripts::
	.byte 0


SakuTown_EventScript_Farmer::
# 8 "data/maps/SakuTown/scripts.pory"
	lock
# 9 "data/maps/SakuTown/scripts.pory"
	faceplayer
# 10 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_Farmer_Text_0
# 13 "data/maps/SakuTown/scripts.pory"
	release
	return


SakuTown_EventScript_Farmer2::
# 17 "data/maps/SakuTown/scripts.pory"
	lock
# 18 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_Farmer2_Text_0
# 22 "data/maps/SakuTown/scripts.pory"
	release
	return


SakuTown_EventScript_Woman::
# 26 "data/maps/SakuTown/scripts.pory"
	lock
# 27 "data/maps/SakuTown/scripts.pory"
	faceplayer
# 28 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_Woman_Text_0
# 32 "data/maps/SakuTown/scripts.pory"
	release
	return


SakuTown_EventScript_Karateka::
# 36 "data/maps/SakuTown/scripts.pory"
	lock
# 37 "data/maps/SakuTown/scripts.pory"
	faceplayer
# 38 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_Karateka_Text_0
# 41 "data/maps/SakuTown/scripts.pory"
	applymovement 6, Common_Movement_FaceRight
# 42 "data/maps/SakuTown/scripts.pory"
	waitmovement 0
# 43 "data/maps/SakuTown/scripts.pory"
	delay 30
# 44 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_Karateka_Text_1
# 47 "data/maps/SakuTown/scripts.pory"
	release
	return


SakuTown_EventScript_TownSign::
# 51 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_TownSign_Text_0, MSGBOX_SIGN
	return


SakuTown_EventScript_TrainerTips::
# 55 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_TrainerTips_Text_0, MSGBOX_SIGN
	return


SakuTown_EventScript_FloristSign::
# 59 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_FloristSign_Text_0, MSGBOX_SIGN
	return


SakuTown_EventScript_Mart::
# 63 "data/maps/SakuTown/scripts.pory"
	lock
# 64 "data/maps/SakuTown/scripts.pory"
	faceplayer
# 65 "data/maps/SakuTown/scripts.pory"
	message gText_HowMayIServeYou
# 66 "data/maps/SakuTown/scripts.pory"
	waitmessage
# 67 "data/maps/SakuTown/scripts.pory"
	pokemart SakuTown_Mart
# 68 "data/maps/SakuTown/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 69 "data/maps/SakuTown/scripts.pory"
	release
	return


	.align 2
# 72 "data/maps/SakuTown/scripts.pory"
SakuTown_Mart:
# 73 "data/maps/SakuTown/scripts.pory"
	.2byte ITEM_POKE_BALL
# 74 "data/maps/SakuTown/scripts.pory"
	.2byte ITEM_BERRY_JUICE
# 75 "data/maps/SakuTown/scripts.pory"
	.2byte ITEM_PARALYZE_HEAL
# 76 "data/maps/SakuTown/scripts.pory"
	.2byte ITEM_ANTIDOTE
# 77 "data/maps/SakuTown/scripts.pory"
	.2byte ITEM_AWAKENING
# 78 "data/maps/SakuTown/scripts.pory"
	.2byte ITEM_ESCAPE_ROPE
# 79 "data/maps/SakuTown/scripts.pory"
	.2byte ITEM_REPEL
	.2byte ITEM_NONE

SakuTown_EventScript_Makuhita::
# 83 "data/maps/SakuTown/scripts.pory"
	lock
# 84 "data/maps/SakuTown/scripts.pory"
	faceplayer
# 85 "data/maps/SakuTown/scripts.pory"
	waitse
# 86 "data/maps/SakuTown/scripts.pory"
	playmoncry SPECIES_MAKUHITA, CRY_MODE_NORMAL
# 87 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_Makuhita_Text_0
# 88 "data/maps/SakuTown/scripts.pory"
	waitmoncry
# 89 "data/maps/SakuTown/scripts.pory"
	release
	return


SakuTown_EventScript_Farmer_Text_0:
# 11 "data/maps/SakuTown/scripts.pory"
	.string "We're cultivatin' Ryss berries. Saku\n"
	.string "Village exports its berries to many\l"
	.string "towns.$"

SakuTown_EventScript_Farmer2_Text_0:
# 19 "data/maps/SakuTown/scripts.pory"
	.string "Whew…\p"
	.string "Working in the fields sure is tiring…$"

SakuTown_EventScript_Woman_Text_0:
# 29 "data/maps/SakuTown/scripts.pory"
	.string "Those thugs in Kura Village may have\n"
	.string "their own dojo, but their town is\l"
	.string "nothing but an ugly pile of rocks!\p"
	.string "They don't even have a Pokémon refuge!$"

SakuTown_EventScript_Karateka_Text_0:
# 39 "data/maps/SakuTown/scripts.pory"
	.string "I let the Pokémon League borrow my\n"
	.string "super-strong Pokémon to help build the\l"
	.string "new Pokémon refuges throughout the\l"
	.string "region.\p"
	.string "$"

SakuTown_EventScript_Karateka_Text_1:
# 45 "data/maps/SakuTown/scripts.pory"
	.string "Come on, Mama, Kuku! Daddy loves you!!\p"
	.string "$"

SakuTown_EventScript_TownSign_Text_0:
# 51 "data/maps/SakuTown/scripts.pory"
	.string "Saku Village\n"
	.string "“A village of tender flower petals.”$"

SakuTown_EventScript_TrainerTips_Text_0:
# 55 "data/maps/SakuTown/scripts.pory"
	.string "Did you know? Saku Village is in all ways\n"
	.string "superior to Kura Village!$"

SakuTown_EventScript_FloristSign_Text_0:
# 59 "data/maps/SakuTown/scripts.pory"
	.string "Humble Blossom\n"
	.string "Bonsai & flower shop$"

SakuTown_EventScript_Makuhita_Text_0:
# 87 "data/maps/SakuTown/scripts.pory"
	.string "Kuhi!$"

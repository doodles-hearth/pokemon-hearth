KuraTown_MapScripts::
# 2 "data/maps/KuraTown/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, KuraTown_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

KuraTown_MapScripts_MAP_SCRIPT_ON_LOAD:
# 4 "data/maps/KuraTown/scripts.pory"
	goto_if_set FLAG_KURA_DOJO_CLOSED, KuraTown_MapScripts_MAP_SCRIPT_ON_LOAD_1
	return

KuraTown_MapScripts_MAP_SCRIPT_ON_LOAD_1:
# 5 "data/maps/KuraTown/scripts.pory"
	setmetatile 23, 18, METATILE_SakuKura_ClosedDojoDoor, TRUE
	return


KuraTown_EventScript_DojoChallenger::
# 11 "data/maps/KuraTown/scripts.pory"
	lock
# 12 "data/maps/KuraTown/scripts.pory"
	faceplayer
# 13 "data/maps/KuraTown/scripts.pory"
	goto_if_set FLAG_KURA_DOJO_CLOSED, KuraTown_EventScript_DojoChallenger_2
# 23 "data/maps/KuraTown/scripts.pory"
	msgbox KuraTown_EventScript_DojoChallenger_Text_1, MSGBOX_DEFAULT
KuraTown_EventScript_DojoChallenger_1:
# 32 "data/maps/KuraTown/scripts.pory"
	release
	return

KuraTown_EventScript_DojoChallenger_2:
# 14 "data/maps/KuraTown/scripts.pory"
	msgbox KuraTown_EventScript_DojoChallenger_Text_0, MSGBOX_DEFAULT
	goto KuraTown_EventScript_DojoChallenger_1


KuraTown_EventScript_SingingFarmer::
# 36 "data/maps/KuraTown/scripts.pory"
	lock
# 37 "data/maps/KuraTown/scripts.pory"
	faceplayer
# 38 "data/maps/KuraTown/scripts.pory"
	msgbox KuraTown_EventScript_SingingFarmer_Text_0, MSGBOX_DEFAULT
# 44 "data/maps/KuraTown/scripts.pory"
	release
	return


KuraTown_EventScript_Guard::
# 48 "data/maps/KuraTown/scripts.pory"
	lock
# 49 "data/maps/KuraTown/scripts.pory"
	faceplayer
# 50 "data/maps/KuraTown/scripts.pory"
	msgbox KuraTown_EventScript_Guard_Text_0, MSGBOX_DEFAULT
# 58 "data/maps/KuraTown/scripts.pory"
	release
	return


SakuTown_EventScript_ClosedGymDoor::
# 63 "data/maps/KuraTown/scripts.pory"
	goto_if_set FLAG_KURA_DOJO_CLOSED, SakuTown_EventScript_ClosedGymDoor_1
	return

SakuTown_EventScript_ClosedGymDoor_1:
# 64 "data/maps/KuraTown/scripts.pory"
	msgbox SakuTown_EventScript_ClosedGymDoor_Text_0, MSGBOX_SIGN
	return


KuraTown_EventScript_TownSign::
# 72 "data/maps/KuraTown/scripts.pory"
	msgbox KuraTown_EventScript_TownSign_Text_0, MSGBOX_SIGN
	return


KuraTown_EventScript_DirectionsSign::
# 76 "data/maps/KuraTown/scripts.pory"
	msgbox KuraTown_EventScript_DirectionsSign_Text_0, MSGBOX_SIGN
	return


KuraTown_EventScript_GymSign::
# 80 "data/maps/KuraTown/scripts.pory"
	msgbox KuraTown_EventScript_GymSign_Text_0, MSGBOX_SIGN
	return


KuraTown_EventScript_DojoChallenger_Text_0:
# 16 "data/maps/KuraTown/scripts.pory"
	.string "It seems the dojo is closed again…\p"
	.string "Gah, when will I get a chance to crush\n"
	.string "Hana in a fiery battle?\p"
	.string "Could it be that she is scared of me?$"

KuraTown_EventScript_DojoChallenger_Text_1:
# 25 "data/maps/KuraTown/scripts.pory"
	.string "The dojo is open! I can finally defeat\n"
	.string "its leader in a fiery battle!\p"
	.string "…Hm? When, you ask? In… In a minute…\p"
	.string "No, go right ahead, I'm just… preparing…$"

KuraTown_EventScript_SingingFarmer_Text_0:
# 40 "data/maps/KuraTown/scripts.pory"
	.string "Doo doo… Just waterin' the crops… Yeah,\n"
	.string "waterin' the crops… Doo doo doo…$"

KuraTown_EventScript_Guard_Text_0:
# 52 "data/maps/KuraTown/scripts.pory"
	.string "Hello, young traveler. Hope you didn't\n"
	.string "have too much trouble passing the gate.\p"
	.string "That Saku Village guard is such a jerk,\n"
	.string "he won't let anyone from our village\l"
	.string "cross to theirs.\p"
	.string "So of course we're not gonna let any of\n"
	.string "them in ours! Hah!$"

SakuTown_EventScript_ClosedGymDoor_Text_0:
# 65 "data/maps/KuraTown/scripts.pory"
	.string "“BE BACK SOON\n"
	.string "- Hana”$"

KuraTown_EventScript_TownSign_Text_0:
# 72 "data/maps/KuraTown/scripts.pory"
	.string "Kura Village\n"
	.string "“A village where the mountains meet the\l"
	.string "woods.”$"

KuraTown_EventScript_DirectionsSign_Text_0:
# 76 "data/maps/KuraTown/scripts.pory"
	.string "{UP_ARROW} Silver Tunnel\n"
	.string "This way for Silveridge$"

KuraTown_EventScript_GymSign_Text_0:
# 82 "data/maps/KuraTown/scripts.pory"
	.string "Kura Village Pokémon Dojo\n"
	.string "Leader: Hana\p"
	.string "“Strong as a maple rooted in wisdom.”$"

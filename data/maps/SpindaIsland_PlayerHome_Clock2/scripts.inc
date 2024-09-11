SpindaIsland_PlayerHome_Clock2_MapScripts::
	.byte 0


SpinaIsland_PlayerHome_EventScript_SorryForBugs::
# 8 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	lock
# 9 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_SorryForBugs_Text_0
# 10 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_SorryForBugs_Text_1
# 14 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	closemessage
# 15 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	release
	return


SpinaIsland_PlayerHome_Clock2_EventScript_EnterLivingRoom::
# 19 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	lock
# 21 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	playse SE_PIN
# 22 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	applymovement 1, Common_Movement_ExclamationMark
# 23 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	waitmovement 0
# 24 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	delay 48
# 25 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	applymovement 1, Common_Movement_WalkInPlaceFasterRight
# 26 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
# 27 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	waitmovement 0
# 29 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_MOM, EMOTE_HAPPY
# 30 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	speakername SpinaIsland_PlayerHome_Clock2_EventScript_EnterLivingRoom_Text_0
# 31 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	msgbox SpinaIsland_PlayerHome_Clock2_EventScript_EnterLivingRoom_Text_1
# 35 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	removefieldmugshot
# 36 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	closemessage
# 37 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	removefieldmugshot
# 39 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 40 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	speakername SpinaIsland_PlayerHome_Clock2_EventScript_EnterLivingRoom_Text_2
# 41 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	msgbox SpinaIsland_PlayerHome_Clock2_EventScript_EnterLivingRoom_Text_3
# 44 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	removefieldmugshot
# 45 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 46 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	msgbox SpinaIsland_PlayerHome_Clock2_EventScript_EnterLivingRoom_Text_4
# 49 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	closemessage
# 50 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	removefieldmugshot
# 52 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_MOM, EMOTE_NORMAL
# 53 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	speakername SpinaIsland_PlayerHome_Clock2_EventScript_EnterLivingRoom_Text_0
# 54 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	msgbox SpinaIsland_PlayerHome_Clock2_EventScript_EnterLivingRoom_Text_5
# 59 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	removefieldmugshot
# 60 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	closemessage
# 61 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	removefieldmugshot
# 63 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	turnobject 1, DIR_SOUTH
# 64 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	delay 40
# 65 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	playse SE_PIN
# 66 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	applymovement 1, Common_Movement_ExclamationMark
# 67 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	waitmovement 0
# 68 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	delay 48
# 69 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	waitmovement 0
# 71 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_MOM, EMOTE_NORMAL
# 72 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	speakername SpinaIsland_PlayerHome_Clock2_EventScript_EnterLivingRoom_Text_0
# 73 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	msgbox SpinaIsland_PlayerHome_Clock2_EventScript_EnterLivingRoom_Text_6
# 76 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	turnobject 1, DIR_EAST
# 77 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	removefieldmugshot
# 78 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_MOM, EMOTE_HAPPY
# 79 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	msgbox SpinaIsland_PlayerHome_Clock2_EventScript_EnterLivingRoom_Text_7
# 83 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	removefieldmugshot
# 84 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	closemessage
# 87 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_SAD
# 88 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	speakername SpinaIsland_PlayerHome_Clock2_EventScript_EnterLivingRoom_Text_2
# 89 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	msgbox SpinaIsland_PlayerHome_Clock2_EventScript_EnterLivingRoom_Text_8
# 92 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	closemessage
# 93 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	removefieldmugshot
# 95 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	goto_if_unset FLAG_TOOK_SPINDA, SpinaIsland_PlayerHome_Clock2_EventScript_EnterLivingRoom_2
SpinaIsland_PlayerHome_Clock2_EventScript_EnterLivingRoom_1:
# 105 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	turnobject 1, DIR_SOUTH
# 107 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	setvar VAR_SPINDA_ISLAND_INTRO_STATE, 2
# 109 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	release
	return

SpinaIsland_PlayerHome_Clock2_EventScript_EnterLivingRoom_2:
# 96 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_MOM, EMOTE_HAPPY
# 97 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	speakername SpinaIsland_PlayerHome_Clock2_EventScript_EnterLivingRoom_Text_0
# 98 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	msgbox SpinaIsland_PlayerHome_Clock2_EventScript_EnterLivingRoom_Text_9
# 101 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	removefieldmugshot
# 102 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	closemessage
	goto SpinaIsland_PlayerHome_Clock2_EventScript_EnterLivingRoom_1


SpinaIsland_PlayerHome_EventScript_SorryForBugs_Text_0:
# 9 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	.string "God$"

SpinaIsland_PlayerHome_EventScript_SorryForBugs_Text_1:
# 11 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	.string "“THIS IS A MESSAGE FROM GOD:\p"
	.string "SORRY FOR THE BUGS. I TRIED.”$"

SpinaIsland_PlayerHome_Clock2_EventScript_EnterLivingRoom_Text_0:
# 30 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	.string "Mom$"

SpinaIsland_PlayerHome_Clock2_EventScript_EnterLivingRoom_Text_1:
# 32 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	.string "Morning, little Archie!\p"
	.string "You're quite the early bird today!$"

SpinaIsland_PlayerHome_Clock2_EventScript_EnterLivingRoom_Text_2:
# 40 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	.string "Little Archie$"

SpinaIsland_PlayerHome_Clock2_EventScript_EnterLivingRoom_Text_3:
# 42 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	.string "That's cause today's the big day!!$"

SpinaIsland_PlayerHome_Clock2_EventScript_EnterLivingRoom_Text_4:
# 47 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	.string "You haven't forgotten about my super\n"
	.string "secret thing, right?$"

SpinaIsland_PlayerHome_Clock2_EventScript_EnterLivingRoom_Text_5:
# 55 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	.string "Of course not, darling! Your super\n"
	.string "secret thing is almost finished.\p"
	.string "I'll give it to you as soon as I'm done.\p"
	.string "But first, I sure could go for a nice,\n"
	.string "big, tall glass of icy {COLOR BLUE}WATER{COLOR DARK_GRAY}…$"

SpinaIsland_PlayerHome_Clock2_EventScript_EnterLivingRoom_Text_6:
# 74 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	.string "Look at that, I forgot to turn the\n"
	.string "{COLOR BLUE}WATER{COLOR DARK_GRAY} back on…$"

SpinaIsland_PlayerHome_Clock2_EventScript_EnterLivingRoom_Text_7:
# 80 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	.string "Archie, would you be a dear and go\n"
	.string "round the house to turn the big\l"
	.string "faucet on?\p"
	.string "And then I'll give it to you, I promise!$"

SpinaIsland_PlayerHome_Clock2_EventScript_EnterLivingRoom_Text_8:
# 90 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	.string "Ughhhhhh, fine…$"

SpinaIsland_PlayerHome_Clock2_EventScript_EnterLivingRoom_Text_9:
# 99 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	.string "Oh, and where's Spinda? Take her for a\n"
	.string "little walk, will you?$"

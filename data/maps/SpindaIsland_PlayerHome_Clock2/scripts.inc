SpindaIsland_PlayerHome_Clock2_MapScripts::
	.byte 0


SpinaIsland_PlayerHome_Clock2_EventScript_EnterLivingRoom::
# 6 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	lock
# 8 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	playse SE_PIN
# 9 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	applymovement LOCALID_MOM, Common_Movement_ExclamationMark
# 10 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	waitmovement 0
# 11 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	delay 48
# 12 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	applymovement LOCALID_MOM, Common_Movement_WalkInPlaceFasterRight
# 13 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
# 14 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	waitmovement 0
# 16 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_MOM, EMOTE_HAPPY
# 17 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	speakername SpinaIsland_PlayerHome_Clock2_EventScript_EnterLivingRoom_Text_0
# 18 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	msgbox SpinaIsland_PlayerHome_Clock2_EventScript_EnterLivingRoom_Text_1
# 22 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	removefieldmugshot
# 23 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	closemessage
# 24 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	removefieldmugshot
# 26 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 27 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	speakername SpinaIsland_PlayerHome_Clock2_EventScript_EnterLivingRoom_Text_2
# 28 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	msgbox SpinaIsland_PlayerHome_Clock2_EventScript_EnterLivingRoom_Text_3
# 31 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	removefieldmugshot
# 32 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 33 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	msgbox SpinaIsland_PlayerHome_Clock2_EventScript_EnterLivingRoom_Text_4
# 36 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	closemessage
# 37 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	removefieldmugshot
# 39 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_MOM, EMOTE_NORMAL
# 40 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	speakername SpinaIsland_PlayerHome_Clock2_EventScript_EnterLivingRoom_Text_0
# 41 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	msgbox SpinaIsland_PlayerHome_Clock2_EventScript_EnterLivingRoom_Text_5
# 46 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	removefieldmugshot
# 47 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	closemessage
# 48 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	removefieldmugshot
# 50 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	turnobject LOCALID_MOM, DIR_SOUTH
# 51 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	delay 40
# 52 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	playse SE_PIN
# 53 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	applymovement LOCALID_MOM, Common_Movement_ExclamationMark
# 54 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	waitmovement 0
# 55 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	delay 48
# 56 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	waitmovement 0
# 58 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_MOM, EMOTE_NORMAL
# 59 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	speakername SpinaIsland_PlayerHome_Clock2_EventScript_EnterLivingRoom_Text_0
# 60 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	msgbox SpinaIsland_PlayerHome_Clock2_EventScript_EnterLivingRoom_Text_6
# 63 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	turnobject LOCALID_MOM, DIR_EAST
# 64 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	removefieldmugshot
# 65 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_MOM, EMOTE_HAPPY
# 66 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	msgbox SpinaIsland_PlayerHome_Clock2_EventScript_EnterLivingRoom_Text_7
# 70 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	removefieldmugshot
# 71 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	closemessage
# 74 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_SAD
# 75 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	speakername SpinaIsland_PlayerHome_Clock2_EventScript_EnterLivingRoom_Text_2
# 76 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	msgbox SpinaIsland_PlayerHome_Clock2_EventScript_EnterLivingRoom_Text_8
# 79 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	closemessage
# 80 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	removefieldmugshot
# 82 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	goto_if_unset FLAG_TOOK_SPINDA, SpinaIsland_PlayerHome_Clock2_EventScript_EnterLivingRoom_2
SpinaIsland_PlayerHome_Clock2_EventScript_EnterLivingRoom_1:
# 92 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	turnobject LOCALID_MOM, DIR_SOUTH
# 94 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	setvar VAR_SPINDA_ISLAND_INTRO_STATE, 2
# 96 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	release
	return

SpinaIsland_PlayerHome_Clock2_EventScript_EnterLivingRoom_2:
# 83 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_MOM, EMOTE_HAPPY
# 84 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	speakername SpinaIsland_PlayerHome_Clock2_EventScript_EnterLivingRoom_Text_0
# 85 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	msgbox SpinaIsland_PlayerHome_Clock2_EventScript_EnterLivingRoom_Text_9
# 88 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	removefieldmugshot
# 89 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	closemessage
	goto SpinaIsland_PlayerHome_Clock2_EventScript_EnterLivingRoom_1


SpinaIsland_PlayerHome_Clock2_EventScript_EnterLivingRoom_Text_0:
# 17 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	.string "Mom$"

SpinaIsland_PlayerHome_Clock2_EventScript_EnterLivingRoom_Text_1:
# 19 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	.string "Morning, little Archie!\p"
	.string "You're quite the early bird today!$"

SpinaIsland_PlayerHome_Clock2_EventScript_EnterLivingRoom_Text_2:
# 27 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	.string "Little Archie$"

SpinaIsland_PlayerHome_Clock2_EventScript_EnterLivingRoom_Text_3:
# 29 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	.string "That's cause today's the big day!!$"

SpinaIsland_PlayerHome_Clock2_EventScript_EnterLivingRoom_Text_4:
# 34 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	.string "You haven't forgotten about my super\n"
	.string "secret thing, right?$"

SpinaIsland_PlayerHome_Clock2_EventScript_EnterLivingRoom_Text_5:
# 42 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	.string "Of course not, darling! Your super\n"
	.string "secret thing is almost finished.\p"
	.string "I'll give it to you as soon as I'm done.\p"
	.string "But first, I sure could go for a nice,\n"
	.string "big, tall glass of icy {COLOR BLUE}WATER{COLOR DARK_GRAY}…$"

SpinaIsland_PlayerHome_Clock2_EventScript_EnterLivingRoom_Text_6:
# 61 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	.string "Look at that, I forgot to turn the\n"
	.string "{COLOR BLUE}WATER{COLOR DARK_GRAY} back on…$"

SpinaIsland_PlayerHome_Clock2_EventScript_EnterLivingRoom_Text_7:
# 67 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	.string "Archie, would you be a dear and go\n"
	.string "round the house to turn the big\l"
	.string "faucet on?\p"
	.string "And then I'll give it to you, I promise!$"

SpinaIsland_PlayerHome_Clock2_EventScript_EnterLivingRoom_Text_8:
# 77 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	.string "Ughhhhhh, fine…$"

SpinaIsland_PlayerHome_Clock2_EventScript_EnterLivingRoom_Text_9:
# 86 "data/maps/SpindaIsland_PlayerHome_Clock2/scripts.pory"
	.string "Oh, and where's Spinda? Take her for a\n"
	.string "little walk, will you?$"

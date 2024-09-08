SpindaIsland_Home_Clock3_MapScripts::
# 2 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SpindaIsland_Home_Clock3_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 12 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, SpindaIsland_Home_Clock3_MapScripts_MAP_SCRIPT_ON_LOAD
# 9 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SpindaIsland_Home_Clock3_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

SpindaIsland_Home_Clock3_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	goto_if_set FLAG_SLOWPOKE_EVOLVED, SpindaIsland_Home_Clock3_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
# 6 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( SLOWPOKE )
	return

SpindaIsland_Home_Clock3_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 4 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( SLOWBRO )
	return

SpindaIsland_Home_Clock3_MapScripts_MAP_SCRIPT_ON_LOAD:
# 13 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	goto_if_set FLAG_CAMERA_EXPLODED, SpindaIsland_Home_Clock3_MapScripts_MAP_SCRIPT_ON_LOAD_2
SpindaIsland_Home_Clock3_MapScripts_MAP_SCRIPT_ON_LOAD_1:
# 17 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	goto_if_set FLAG_OPENED_CHEST, SpindaIsland_Home_Clock3_MapScripts_MAP_SCRIPT_ON_LOAD_4
	return

SpindaIsland_Home_Clock3_MapScripts_MAP_SCRIPT_ON_LOAD_2:
# 14 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	setmetatile 28, 44, METATILE_SpindaIslandSecondary_PathBottom, FALSE
# 15 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	setmetatile 28, 45, METATILE_SpindaIsland_Grass, FALSE
	goto SpindaIsland_Home_Clock3_MapScripts_MAP_SCRIPT_ON_LOAD_1

SpindaIsland_Home_Clock3_MapScripts_MAP_SCRIPT_ON_LOAD_4:
# 18 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	setmetatile 27, 6, METATILE_SpindaIsland_EmptyChestSide, TRUE
	return

SpindaIsland_Home_Clock3_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 10 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	map_script_2 VAR_SPINDA_ISLAND_INTRO_STATE, 2, SpindaIsland_Home_EventScript_MainQuestRecap
	.2byte 0


SpindaIsland_Home_Clock3_EventScript_OldWoman::
# 24 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	lock
# 25 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	faceplayer
# 26 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	goto_if_unset FLAG_SHUPPET_QUEST_STARTED, SpindaIsland_Home_Clock3_EventScript_OldWoman_2
# 37 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	goto_if_unset FLAG_HIDE_SHUPPETS, SpindaIsland_Home_Clock3_EventScript_OldWoman_3
SpindaIsland_Home_Clock3_EventScript_OldWoman_1:
# 48 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	goto_if_set FLAG_HIDE_SHUPPETS, SpindaIsland_Home_Clock3_EventScript_OldWoman_7
SpindaIsland_Home_Clock3_EventScript_OldWoman_6:
# 105 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	release
	return

SpindaIsland_Home_Clock3_EventScript_OldWoman_2:
# 27 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	faceplayer
# 28 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_NORMAL
# 29 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	speakername SpindaIsland_Home_Clock3_EventScript_OldWoman_Text_0
# 30 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	msgbox SpindaIsland_Home_Clock3_EventScript_OldWoman_Text_1
# 34 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	removefieldmugshot
# 35 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	closemessage
# 36 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	setflag FLAG_SHUPPET_QUEST_STARTED
	goto SpindaIsland_Home_Clock3_EventScript_OldWoman_1

SpindaIsland_Home_Clock3_EventScript_OldWoman_3:
# 38 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	faceplayer
# 39 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_NORMAL
# 40 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	speakername SpindaIsland_Home_Clock3_EventScript_OldWoman_Text_0
# 41 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	msgbox SpindaIsland_Home_Clock3_EventScript_OldWoman_Text_2
# 44 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	removefieldmugshot
# 45 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	closemessage
	goto SpindaIsland_Home_Clock3_EventScript_OldWoman_1

SpindaIsland_Home_Clock3_EventScript_OldWoman_7:
# 49 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_NORMAL
# 50 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	speakername SpindaIsland_Home_Clock3_EventScript_OldWoman_Text_0
# 51 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	msgbox SpindaIsland_Home_Clock3_EventScript_OldWoman_Text_2
# 54 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	removefieldmugshot
# 55 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	closemessage
# 57 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 58 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	speakername SpindaIsland_Home_Clock3_EventScript_OldWoman_Text_3
# 59 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	msgbox SpindaIsland_Home_Clock3_EventScript_OldWoman_Text_4
# 62 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	removefieldmugshot
# 63 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	closemessage
# 65 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_NORMAL
# 66 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	speakername SpindaIsland_Home_Clock3_EventScript_OldWoman_Text_0
# 67 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	msgbox SpindaIsland_Home_Clock3_EventScript_OldWoman_Text_5
# 70 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_HAPPY
# 71 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	msgbox SpindaIsland_Home_Clock3_EventScript_OldWoman_Text_6
# 76 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	removefieldmugshot
# 77 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	closemessage
# 79 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	giveitem ITEM_PB_AND_J
# 81 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_HAPPY
# 82 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	msgbox SpindaIsland_Home_Clock3_EventScript_OldWoman_Text_7
# 85 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	removefieldmugshot
# 86 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	closemessage
# 88 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_WEST
# 89 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	removeobject VAR_LAST_TALKED
# 90 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	playse SE_EXIT
# 91 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	waitse
# 92 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	setflag FLAG_HIDE_OLD_WOMAN
# 94 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 95 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	speakername SpindaIsland_Home_Clock3_EventScript_OldWoman_Text_3
# 96 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	msgbox SpindaIsland_Home_Clock3_EventScript_OldWoman_Text_8
# 100 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	removefieldmugshot
# 101 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	closemessage
# 103 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	call SpindaIsland_Common_CheckGotAllItemsForNewFaucet
	goto SpindaIsland_Home_Clock3_EventScript_OldWoman_6


SpindaIsland_Home_Clock3_EventScript_EmptyHouseSign::
# 109 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	lock
# 110 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	msgbox SpindaIsland_Home_Clock3_EventScript_EmptyHouseSign_Text_0
# 114 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 115 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	speakername SpindaIsland_Home_Clock3_EventScript_OldWoman_Text_3
# 116 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	msgbox SpindaIsland_Home_Clock3_EventScript_EmptyHouseSign_Text_1
# 120 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	removefieldmugshot
# 121 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	closemessage
# 122 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	release
	return


SpindaIsland_Home_Clock3_EventScript_EmptyHouseDoor::
# 126 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	lock
# 127 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	speakername SpindaIsland_Home_Clock3_EventScript_EmptyHouseDoor_Text_0
# 128 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	msgbox SpindaIsland_Home_Clock3_EventScript_EmptyHouseDoor_Text_1
# 133 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	release
	return


SpindaIsland_Home_Clock3_EventScript_OldWoman_Text_0:
# 29 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	.string "Old woman$"

SpindaIsland_Home_Clock3_EventScript_OldWoman_Text_1:
# 31 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	.string "I think my house is haunted. There's\n"
	.string "something living in my attic.\p"
	.string "I don't know what to do…$"

SpindaIsland_Home_Clock3_EventScript_OldWoman_Text_2:
# 42 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	.string "Oh, I'm too scared to go back inside…$"

SpindaIsland_Home_Clock3_EventScript_OldWoman_Text_3:
# 58 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	.string "Little Archie$"

SpindaIsland_Home_Clock3_EventScript_OldWoman_Text_4:
# 60 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	.string "Don't worry granny! There were some\n"
	.string "Shuppet in your attic, but I chased\l"
	.string "them away!$"

SpindaIsland_Home_Clock3_EventScript_OldWoman_Text_5:
# 68 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	.string "Shuppet, you say?$"

SpindaIsland_Home_Clock3_EventScript_OldWoman_Text_6:
# 72 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	.string "How adorable of you to help out a poor\n"
	.string "old lady…\p"
	.string "How can I repay you?\p"
	.string "You look like you're hungry… Let me\n"
	.string "fix you a little snack!$"

SpindaIsland_Home_Clock3_EventScript_OldWoman_Text_7:
# 83 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	.string "Have a good day, child.$"

SpindaIsland_Home_Clock3_EventScript_OldWoman_Text_8:
# 97 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	.string "Cool! Lemme pack this up for later.\p"
	.string "Let's hope it doesn't taste like old\n"
	.string "people or something.$"

SpindaIsland_Home_Clock3_EventScript_EmptyHouseSign_Text_0:
# 111 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	.string "$"

SpindaIsland_Home_Clock3_EventScript_EmptyHouseSign_Text_1:
# 117 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	.string "… …\p"
	.string "A blank sign?$"

SpindaIsland_Home_Clock3_EventScript_EmptyHouseDoor_Text_0:
# 127 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	.string "God$"

SpindaIsland_Home_Clock3_EventScript_EmptyHouseDoor_Text_1:
# 129 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	.string "“YEAH, DON'T BOTHER.”\p"
	.string "“I CREATED A CRAPTON OF HOUSES AND\n"
	.string "DIDN'T HAVE TIME TO FILL THEM ALL UP.\p"
	.string "“SORRY ABOUT THAT, HOPE YOU'RE\n"
	.string "HAVING FUN AND ALL.”$"

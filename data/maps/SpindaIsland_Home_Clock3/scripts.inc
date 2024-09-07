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
	goto_if_set FLAG_CAMERA_EXPLODED, SpindaIsland_Home_Clock3_MapScripts_MAP_SCRIPT_ON_LOAD_1
	return

SpindaIsland_Home_Clock3_MapScripts_MAP_SCRIPT_ON_LOAD_1:
# 14 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	setmetatile 28, 44, METATILE_SpindaIslandSecondary_PathBottom, FALSE
# 15 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	setmetatile 28, 45, METATILE_SpindaIsland_Grass, FALSE
	return

SpindaIsland_Home_Clock3_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 10 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	map_script_2 VAR_SPINDA_ISLAND_INTRO_STATE, 2, SpindaIsland_Home_EventScript_MainQuestRecap
	.2byte 0


SpindaIsland_Home_Clock3_EventScript_OldWoman::
# 21 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	lock
# 22 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	faceplayer
# 23 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	goto_if_unset FLAG_SHUPPET_QUEST_STARTED, SpindaIsland_Home_Clock3_EventScript_OldWoman_2
# 34 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	goto_if_unset FLAG_HIDE_SHUPPETS, SpindaIsland_Home_Clock3_EventScript_OldWoman_3
SpindaIsland_Home_Clock3_EventScript_OldWoman_1:
# 45 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	goto_if_set FLAG_HIDE_SHUPPETS, SpindaIsland_Home_Clock3_EventScript_OldWoman_7
SpindaIsland_Home_Clock3_EventScript_OldWoman_6:
# 91 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	release
	return

SpindaIsland_Home_Clock3_EventScript_OldWoman_2:
# 24 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	faceplayer
# 25 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_NORMAL
# 26 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	speakername SpindaIsland_Home_Clock3_EventScript_OldWoman_Text_0
# 27 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	msgbox SpindaIsland_Home_Clock3_EventScript_OldWoman_Text_1
# 31 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	removefieldmugshot
# 32 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	closemessage
# 33 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	setflag FLAG_SHUPPET_QUEST_STARTED
	goto SpindaIsland_Home_Clock3_EventScript_OldWoman_1

SpindaIsland_Home_Clock3_EventScript_OldWoman_3:
# 35 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	faceplayer
# 36 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_NORMAL
# 37 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	speakername SpindaIsland_Home_Clock3_EventScript_OldWoman_Text_0
# 38 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	msgbox SpindaIsland_Home_Clock3_EventScript_OldWoman_Text_2
# 41 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	removefieldmugshot
# 42 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	closemessage
	goto SpindaIsland_Home_Clock3_EventScript_OldWoman_1

SpindaIsland_Home_Clock3_EventScript_OldWoman_7:
# 46 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_NORMAL
# 47 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	speakername SpindaIsland_Home_Clock3_EventScript_OldWoman_Text_0
# 48 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	msgbox SpindaIsland_Home_Clock3_EventScript_OldWoman_Text_2
# 51 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	removefieldmugshot
# 52 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	closemessage
# 54 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 55 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	speakername SpindaIsland_Home_Clock3_EventScript_OldWoman_Text_3
# 56 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	msgbox SpindaIsland_Home_Clock3_EventScript_OldWoman_Text_4
# 59 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	removefieldmugshot
# 60 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	closemessage
# 62 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_NORMAL
# 63 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	speakername SpindaIsland_Home_Clock3_EventScript_OldWoman_Text_0
# 64 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	msgbox SpindaIsland_Home_Clock3_EventScript_OldWoman_Text_5
# 67 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_HAPPY
# 68 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	msgbox SpindaIsland_Home_Clock3_EventScript_OldWoman_Text_6
# 72 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	removefieldmugshot
# 73 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	closemessage
# 77 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_HAPPY
# 78 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	msgbox SpindaIsland_Home_Clock3_EventScript_OldWoman_Text_7
# 81 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	removefieldmugshot
# 82 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	closemessage
# 84 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceLeft
# 85 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	waitmovement 0
# 86 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	removeobject VAR_LAST_TALKED
# 87 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	playse SE_EXIT
# 88 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	waitse
# 89 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	setflag FLAG_HIDE_OLD_WOMAN
	goto SpindaIsland_Home_Clock3_EventScript_OldWoman_6


SpindaIsland_Home_Clock3_EventScript_OldWoman_Text_0:
# 26 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	.string "Old woman$"

SpindaIsland_Home_Clock3_EventScript_OldWoman_Text_1:
# 28 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	.string "I think my house is haunted. There's\n"
	.string "something living in my attic.\p"
	.string "I don't know what to do…$"

SpindaIsland_Home_Clock3_EventScript_OldWoman_Text_2:
# 39 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	.string "Oh, I'm too scared to go back inside…$"

SpindaIsland_Home_Clock3_EventScript_OldWoman_Text_3:
# 55 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	.string "Little Archie$"

SpindaIsland_Home_Clock3_EventScript_OldWoman_Text_4:
# 57 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	.string "Don't worry granny! There were some\n"
	.string "Shuppet in your attic, but I chased\l"
	.string "them away!$"

SpindaIsland_Home_Clock3_EventScript_OldWoman_Text_5:
# 65 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	.string "Shuppet, you say?$"

SpindaIsland_Home_Clock3_EventScript_OldWoman_Text_6:
# 69 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	.string "How adorable of you to help out a poor\n"
	.string "old lady…\p"
	.string "Please take this, for your trouble!$"

SpindaIsland_Home_Clock3_EventScript_OldWoman_Text_7:
# 79 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	.string "Have a good day, child.$"

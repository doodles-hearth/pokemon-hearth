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
	goto_if_set FLAG_HIDE_SHUPPETS, SpindaIsland_Home_Clock3_EventScript_OldWoman_2
# 69 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	faceplayer
# 70 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_NORMAL
# 71 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	speakername SpindaIsland_Home_Clock3_EventScript_OldWoman_Text_0
# 72 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	msgbox SpindaIsland_Home_Clock3_EventScript_OldWoman_Text_7
# 76 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	removefieldmugshot
# 77 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	closemessage
SpindaIsland_Home_Clock3_EventScript_OldWoman_1:
# 79 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	release
	return

SpindaIsland_Home_Clock3_EventScript_OldWoman_2:
# 23 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	faceplayer
# 24 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_NORMAL
# 25 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	speakername SpindaIsland_Home_Clock3_EventScript_OldWoman_Text_0
# 26 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	msgbox SpindaIsland_Home_Clock3_EventScript_OldWoman_Text_1
# 29 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	removefieldmugshot
# 30 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	closemessage
# 32 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 33 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	speakername SpindaIsland_Home_Clock3_EventScript_OldWoman_Text_2
# 34 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	msgbox SpindaIsland_Home_Clock3_EventScript_OldWoman_Text_3
# 37 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	removefieldmugshot
# 38 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	closemessage
# 40 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_NORMAL
# 41 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	speakername SpindaIsland_Home_Clock3_EventScript_OldWoman_Text_0
# 42 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	msgbox SpindaIsland_Home_Clock3_EventScript_OldWoman_Text_4
# 45 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_HAPPY
# 46 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	msgbox SpindaIsland_Home_Clock3_EventScript_OldWoman_Text_5
# 50 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	removefieldmugshot
# 51 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	closemessage
# 55 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_HAPPY
# 56 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	msgbox SpindaIsland_Home_Clock3_EventScript_OldWoman_Text_6
# 59 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	removefieldmugshot
# 60 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	closemessage
# 62 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceLeft
# 63 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	waitmovement 0
# 64 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	removeobject VAR_LAST_TALKED
# 65 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	playse SE_EXIT
# 66 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	waitse
# 67 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	setflag FLAG_HIDE_OLD_WOMAN
	goto SpindaIsland_Home_Clock3_EventScript_OldWoman_1


SpindaIsland_Home_Clock3_EventScript_OldWoman_Text_0:
# 25 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	.string "Old woman$"

SpindaIsland_Home_Clock3_EventScript_OldWoman_Text_1:
# 27 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	.string "Oh, I'm too scared to go back inside…$"

SpindaIsland_Home_Clock3_EventScript_OldWoman_Text_2:
# 33 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	.string "Little Archie$"

SpindaIsland_Home_Clock3_EventScript_OldWoman_Text_3:
# 35 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	.string "Don't worry granny! There were some\n"
	.string "Shuppet in your attic, but I chased\l"
	.string "them away!$"

SpindaIsland_Home_Clock3_EventScript_OldWoman_Text_4:
# 43 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	.string "Shuppet, you say?$"

SpindaIsland_Home_Clock3_EventScript_OldWoman_Text_5:
# 47 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	.string "How adorable of you to help out a poor\n"
	.string "old lady…\p"
	.string "Please take this, for your trouble!$"

SpindaIsland_Home_Clock3_EventScript_OldWoman_Text_6:
# 57 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	.string "Have a good day, child.$"

SpindaIsland_Home_Clock3_EventScript_OldWoman_Text_7:
# 73 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	.string "I think my house is haunted. There's\n"
	.string "something living in my attic.\p"
	.string "I don't know what to do…$"

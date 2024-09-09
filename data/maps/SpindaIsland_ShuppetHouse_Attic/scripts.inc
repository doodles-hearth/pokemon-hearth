SpindaIsland_ShuppetHouse_Attic_MapScripts::
# 5 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SpindaIsland_ShuppetHouse_Attic_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

SpindaIsland_ShuppetHouse_Attic_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 6 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, MyScript
	.2byte 0


MyScript::
# 11 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	setvar VAR_TEMP_0, 1
# 13 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, HidePlayer
# 14 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	waitmovement 0
# 15 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	special SpawnCameraObject
# 16 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LandHoMotherfuckers
# 17 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	applymovement 2, LandHoMotherfuckers
# 18 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, LandHoMotherfuckers
# 19 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	waitmovement 0
# 20 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	special RemoveCameraObject
# 22 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PlayerAppears
# 23 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	waitmovement 0
# 25 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	playmoncry SPECIES_WAILMER, CRY_MODE_NORMAL
# 26 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	addobject 1
# 27 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	applymovement 1, WailmerAppears
# 28 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	delay 20
# 29 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
# 30 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	delay 20
# 31 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PlayerWalksToWailmer
# 32 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	waitmovement 0
# 33 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	waitmovement 1
# 35 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 36 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	speakername MyScript_Text_0
# 37 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	msgbox MyScript_Text_1
# 42 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	removefieldmugshot
# 43 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	closemessage
# 45 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	applymovement 1, WailmerJumps
# 46 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	playmoncry SPECIES_WAILMER, CRY_MODE_NORMAL
# 47 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	waitmoncry
# 49 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	delay 48
# 51 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 52 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	speakername MyScript_Text_0
# 53 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	msgbox MyScript_Text_2
# 56 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	removefieldmugshot
# 57 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	closemessage
# 59 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	delay 180
# 61 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	fadescreenspeed FADE_TO_BLACK, 16
# 62 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	delay 200
# 63 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	callnative StartCredits
	end


# 67 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
WailmerJumps:
# 68 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	jump_in_place_left
	step_end

# 71 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
PlayerAppears:
# 72 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	set_visible
# 73 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	walk_down
# 73 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	walk_down
# 73 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	walk_down
# 74 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	delay_16
# 74 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	delay_16
# 74 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	delay_16
# 74 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	delay_16
	step_end

# 77 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
HidePlayer:
# 78 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	set_invisible
	step_end

# 81 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
WailmerAppears:
# 82 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	walk_left
# 82 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	walk_left
# 82 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	walk_left
# 82 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	walk_left
# 82 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	walk_left
# 82 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	walk_left
	step_end

# 85 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
PlayerWalksToWailmer:
# 86 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	walk_slow_right
# 86 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	walk_slow_right
# 86 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	walk_slow_right
	step_end

# 89 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
LandHoMotherfuckers:
# 90 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	lock_anim
# 91 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	lock_facing_direction
# 92 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	walk_down
# 92 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	walk_down
# 92 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	walk_down
# 92 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	walk_down
# 92 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	walk_down
# 92 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	walk_down
# 92 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	walk_down
# 92 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	walk_down
# 92 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	walk_down
# 92 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	walk_down
# 92 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	walk_down
# 93 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	unlock_anim
# 94 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	unlock_facing_direction
# 95 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	face_down
	step_end

MyScript_Text_0:
# 36 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	.string "Little Archie$"

MyScript_Text_1:
# 38 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	.string "Hello, big friend.\p"
	.string "Good to see you.\p"
	.string "It's nice and quiet here, isn't it?$"

MyScript_Text_2:
# 54 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	.string "…$"

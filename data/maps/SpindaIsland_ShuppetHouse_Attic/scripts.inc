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
	applymovement 1, WailmerAppears
# 27 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	delay 20
# 28 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
# 29 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	delay 20
# 30 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PlayerWalksToWailmer
# 31 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	waitmovement 0
# 32 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	waitmovement 1
# 34 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 35 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	speakername MyScript_Text_0
# 36 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	msgbox MyScript_Text_1
# 42 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	removefieldmugshot
# 44 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	delay 180
# 46 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	fadescreenspeed FADE_TO_BLACK, 16
# 47 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	delay 100
# 48 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	callnative StartCredits
	end


# 52 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
PlayerAppears:
# 53 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	set_visible
# 54 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	walk_down
# 54 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	walk_down
# 54 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	walk_down
# 55 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	delay_16
# 55 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	delay_16
# 55 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	delay_16
# 55 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	delay_16
	step_end

# 58 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
HidePlayer:
# 59 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	set_invisible
	step_end

# 62 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
WailmerAppears:
# 63 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	walk_slow_left
# 63 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	walk_slow_left
# 63 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	walk_slow_left
# 63 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	walk_slow_left
# 63 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	walk_slow_left
# 63 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	walk_slow_left
	step_end

# 66 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
PlayerWalksToWailmer:
# 67 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	walk_slow_right
# 67 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	walk_slow_right
# 67 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	walk_slow_right
	step_end

# 70 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
LandHoMotherfuckers:
# 71 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	lock_anim
# 72 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	lock_facing_direction
# 73 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	walk_down
# 73 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	walk_down
# 73 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	walk_down
# 73 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	walk_down
# 73 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	walk_down
# 73 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	walk_down
# 73 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	walk_down
# 73 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	walk_down
# 73 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	walk_down
# 73 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	walk_down
# 73 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	walk_down
# 74 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	unlock_anim
# 75 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	unlock_facing_direction
# 76 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	face_down
	step_end

MyScript_Text_0:
# 35 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	.string "Little Archie$"

MyScript_Text_1:
# 37 "data/maps/SpindaIsland_ShuppetHouse_Attic/scripts.pory"
	.string "Hello, big friend.\p"
	.string "Good to see you.\p"
	.string "It's nice and quiet here, isn't it?\p"
	.string "…$"

SpindaIsland_Home_MapScripts::
# 2 "data/maps/SpindaIsland_Home/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SpindaIsland_Home_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

SpindaIsland_Home_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 3 "data/maps/SpindaIsland_Home/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, SpindaIsland_Home_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0
	.2byte 0

SpindaIsland_Home_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0:
# 4 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_unset FLAG_SPINDA_GIVEN_MON, SpindaIsland_Home_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_1
	return

SpindaIsland_Home_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_1:
# 5 "data/maps/SpindaIsland_Home/scripts.pory"
	givemon SPECIES_SPINDA, 20
# 6 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_RECEIVED_STARTER
# 7 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
	return


SpindaIsland_Home_EventScript_HidingBoy::
# 14 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_HidingBoy_Text_0, MSGBOX_NPC
	return


testytesto::
# 20 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 21 "data/maps/SpindaIsland_Home/scripts.pory"
	call Spinda_SpinClockwise
# 22 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_HidingBoy_Text_0:
# 15 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Something is blocking the way.$"

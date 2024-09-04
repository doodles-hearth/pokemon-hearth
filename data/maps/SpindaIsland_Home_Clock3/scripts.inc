SpindaIsland_Home_Clock3_MapScripts::
# 2 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SpindaIsland_Home_Clock3_MapScripts_MAP_SCRIPT_ON_TRANSITION
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

SpindaIsland_Home_Clock3_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 10 "data/maps/SpindaIsland_Home_Clock3/scripts.pory"
	map_script_2 VAR_SPINDA_ISLAND_INTRO_STATE, 2, SpindaIsland_Home_EventScript_MainQuestRecap
	.2byte 0


SabersideQuarry_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SabersideQuarry_B1F_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

SabersideQuarry_B1F_MapScripts_MAP_SCRIPT_ON_LOAD:
	goto_if_unset FLAG_SPOOKED_SABLEYE, SabersideQuarry_B1F_MapScripts_MAP_SCRIPT_ON_LOAD_1
	return

SabersideQuarry_B1F_MapScripts_MAP_SCRIPT_ON_LOAD_1:
	setmetatile 71, 15, METATILE_Quarry_Sand, FALSE
	setmetatile 71, 16, METATILE_Quarry_SandBottomEdge, FALSE
	return


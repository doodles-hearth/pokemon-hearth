SabersideQuarry_B1F_Part2_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SabersideQuarry_B1F_Part2_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

SabersideQuarry_B1F_Part2_MapScripts_MAP_SCRIPT_ON_LOAD:
	goto_if_unset FLAG_SPOOKED_SABLEYE, SabersideQuarry_B1F_Part2_MapScripts_MAP_SCRIPT_ON_LOAD_1
	return

SabersideQuarry_B1F_Part2_MapScripts_MAP_SCRIPT_ON_LOAD_1:
	setmetatile 23, 26, METATILE_Quarry_SandTopEdge, FALSE
	setmetatile 23, 27, METATILE_Quarry_Sand, FALSE
	setmetatile 22, 28, METATILE_Quarry_Sand, FALSE
	setmetatile 21, 28, METATILE_Quarry_Sand, FALSE
	setmetatile 20, 28, METATILE_Quarry_Sand, FALSE
	setmetatile 19, 28, METATILE_Quarry_Sand, FALSE
	setmetatile 18, 28, METATILE_Quarry_SandLeftEdge, FALSE
	return


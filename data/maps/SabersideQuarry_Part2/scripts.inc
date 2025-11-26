SabersideQuarry_Part2_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SabersideQuarry_Part2_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

SabersideQuarry_Part2_MapScripts_MAP_SCRIPT_ON_LOAD:
	goto_if_unset FLAG_SPOOKED_SABLEYE, SabersideQuarry_Part2_MapScripts_MAP_SCRIPT_ON_LOAD_1
	return

SabersideQuarry_Part2_MapScripts_MAP_SCRIPT_ON_LOAD_1:
	setmetatile 24, 30, METATILE_Quarry_Sand, FALSE
	setmetatile 24, 31, METATILE_Quarry_Sand, FALSE
	setmetatile 23, 31, METATILE_Quarry_Sand, FALSE
	setmetatile 26, 42, METATILE_Quarry_SandTopEdge, FALSE
	setmetatile 26, 43, METATILE_Quarry_Sand, FALSE
	setmetatile 26, 44, METATILE_Quarry_Sand, FALSE
	setmetatile 25, 44, METATILE_Quarry_Sand, FALSE
	setmetatile 24, 44, METATILE_Quarry_SandLeftEdge, FALSE
	return


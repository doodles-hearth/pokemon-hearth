SunriseVillage_PlayersHouse_Bedroom_MapScripts::
# 2 "data/maps/SunriseVillage_PlayersHouse_Bedroom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, SunriseVillage_PlayersHouse_Bedroom_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

SunriseVillage_PlayersHouse_Bedroom_MapScripts_MAP_SCRIPT_ON_LOAD:
# 3 "data/maps/SunriseVillage_PlayersHouse_Bedroom/scripts.pory"
	compare VAR_SUNRISE_VILLAGE_INTRO_STATE, 1
	goto_if_lt SunriseVillage_PlayersHouse_Bedroom_MapScripts_MAP_SCRIPT_ON_LOAD_1
	return

SunriseVillage_PlayersHouse_Bedroom_MapScripts_MAP_SCRIPT_ON_LOAD_1:
# 4 "data/maps/SunriseVillage_PlayersHouse_Bedroom/scripts.pory"
	setvar VAR_SUNRISE_VILLAGE_INTRO_STATE, 1
	return


SunriseVillage_PlayersHouse_Bedroom_Event_BigSisCalling::
# 11 "data/maps/SunriseVillage_PlayersHouse_Bedroom/scripts.pory"
	lock
# 12 "data/maps/SunriseVillage_PlayersHouse_Bedroom/scripts.pory"
	msgbox SunriseVillage_PlayersHouse_Bedroom_Event_BigSisCalling_Text_0
# 16 "data/maps/SunriseVillage_PlayersHouse_Bedroom/scripts.pory"
	setvar VAR_SUNRISE_VILLAGE_INTRO_STATE, 2
# 17 "data/maps/SunriseVillage_PlayersHouse_Bedroom/scripts.pory"
	release
	end


SunriseVillage_PlayersHouse_Bedroom_Event_BigSisCalling_Text_0:
# 13 "data/maps/SunriseVillage_PlayersHouse_Bedroom/scripts.pory"
	.string "{PLAYER}! {PLAYER}! Are you still\n"
	.string "sleeping?\p"
	.string "Get up and get ready!$"

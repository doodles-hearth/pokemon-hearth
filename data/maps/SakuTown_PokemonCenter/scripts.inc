SakuTown_PokemonCenter_MapScripts::
# 2 "data/maps/SakuTown_PokemonCenter/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SakuTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

SakuTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data/maps/SakuTown_PokemonCenter/scripts.pory"
	setrespawn HEAL_LOCATION_SAKU_TOWN
# 5 "data/maps/SakuTown_PokemonCenter/scripts.pory"
	compare VAR_RIVAL_ENCOUNTER_STATE, 0
	goto_if_eq SakuTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return

SakuTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 6 "data/maps/SakuTown_PokemonCenter/scripts.pory"
	setvar VAR_RIVAL_ENCOUNTER_STATE, 1
	return


SakuTown_PokemonCenter_EventScript_Nurse::
# 12 "data/maps/SakuTown_PokemonCenter/scripts.pory"
	setvar VAR_0x800B, LOCALID_NURSE
# 13 "data/maps/SakuTown_PokemonCenter/scripts.pory"
	call Common_EventScript_PkmnCenterNurse
# 14 "data/maps/SakuTown_PokemonCenter/scripts.pory"
	waitmessage
# 15 "data/maps/SakuTown_PokemonCenter/scripts.pory"
	waitbuttonpress
# 16 "data/maps/SakuTown_PokemonCenter/scripts.pory"
	release
	end


SakuTown_PokemonCenter_EventScript_Traveler::
# 21 "data/maps/SakuTown_PokemonCenter/scripts.pory"
	lock
# 22 "data/maps/SakuTown_PokemonCenter/scripts.pory"
	msgbox SakuTown_PokemonCenter_EventScript_Traveler_Text_0
# 27 "data/maps/SakuTown_PokemonCenter/scripts.pory"
	release
	end


SakuTown_PokemonCenter_EventScript_Traveler_Text_0:
# 23 "data/maps/SakuTown_PokemonCenter/scripts.pory"
	.string "This Pokémon refuge is brand-new,\n"
	.string "courtesy of the Pokémon League!\p"
	.string "As you can see, it's still being built.\n"
	.string "Watch out for the falling bricks, ha ha,\l"
	.string "just kidding!\p"
	.string "Seriously though, do watch out. We're\n"
	.string "held responsible if anything happens to\l"
	.string "you.$"

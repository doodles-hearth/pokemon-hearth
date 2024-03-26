ChiiTown_PokemonCenter_MapScripts::
# 5 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, ChiiTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

ChiiTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 6 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	setrespawn HEAL_LOCATION_CHII_TOWN
	end


ChiiTown_PokemonCenter_EventScript_Nurse::
# 12 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	setvar VAR_0x800B, 1
# 13 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	call Common_EventScript_PkmnCenterNurse
# 14 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	waitmessage
# 15 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	waitbuttonpress
# 16 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	release
	end


ChiiTown_PokemonCenter_EventScript_WhereShamisen::
# 22 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	lock
# 23 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	faceplayer
# 24 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	msgbox ChiiTown_PokemonCenter_EventScript_WhereShamisen_Text_0
# 27 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	closemessage
# 28 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	release
	end


ChiiTown_PokemonCenter_EventScript_IveComeALongWay::
# 33 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	lock
# 34 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	faceplayer
# 35 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	msgbox ChiiTown_PokemonCenter_EventScript_IveComeALongWay_Text_0
# 39 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	closemessage
# 40 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	release
	end


ChiiTown_PokemonCenter_EventScript_Snorunt::
# 45 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	lock
# 46 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	faceplayer
# 47 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	playmoncry SPECIES_SNORUNT, CRY_MODE_NORMAL
# 48 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	msgbox ChiiTown_PokemonCenter_EventScript_Snorunt_Text_0
# 51 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	waitmoncry
# 52 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	closemessage
# 53 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	release
	end


ChiiTown_PokemonCenter_EventScript_NeedMarket::
# 58 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	lock
# 59 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	faceplayer
# 60 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	msgbox ChiiTown_PokemonCenter_EventScript_NeedMarket_Text_0
# 63 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	closemessage
# 64 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	release
	end


ChiiTown_PokemonCenter_EventScript_RefugePresentation::
# 69 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	lock
# 70 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	faceplayer
# 71 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	msgbox ChiiTown_PokemonCenter_EventScript_RefugePresentation_Text_0
# 77 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	closemessage
# 78 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	goto_if_set FLAG_TEMP_1, ChiiTown_PokemonCenter_EventScript_RefugePresentation_2
# 82 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	applymovement 2, ChiiTown_PokemonCenter_Movement_LeaveWhenFromBottom
ChiiTown_PokemonCenter_EventScript_RefugePresentation_1:
# 84 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	waitmovement 0
# 85 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	playse SE_EXIT
# 86 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	waitse
# 87 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	removeobject 2
# 89 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	setflag FLAG_POKEMON_REFUGE_PRESENTATION
# 90 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	release
	end

ChiiTown_PokemonCenter_EventScript_RefugePresentation_2:
# 79 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	applymovement 2, ChiiTown_PokemonCenter_Movement_Leave
	goto ChiiTown_PokemonCenter_EventScript_RefugePresentation_1


ChiiTown_PokemonCenter_EventScript_SetFlagRight::
# 95 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	setflag FLAG_TEMP_1
	return


ChiiTown_PokemonCenter_EventScript_SetFlagBottom::
# 99 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	clearflag FLAG_TEMP_1
	return


# 102 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
ChiiTown_PokemonCenter_Movement_LeaveWhenFromBottom:
# 103 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	walk_right
# 104 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	walk_down
# 105 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	walk_down
# 106 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	walk_down
# 107 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	walk_down
# 108 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	walk_down
# 109 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	walk_down
	step_end

# 112 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
ChiiTown_PokemonCenter_Movement_Leave:
# 113 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	walk_down
# 114 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	walk_down
# 115 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	walk_down
# 116 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	walk_down
# 117 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	walk_down
# 118 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	walk_down
	step_end

ChiiTown_PokemonCenter_EventScript_WhereShamisen_Text_0:
# 25 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	.string "Where's that cute shamisen player that\n"
	.string "was here last night?$"

ChiiTown_PokemonCenter_EventScript_IveComeALongWay_Text_0:
# 36 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	.string "I'm so glad I found this refuge. I've\n"
	.string "come a long way and my feet hurt.\p"
	.string "My Pokémon and I can rest for a while.$"

ChiiTown_PokemonCenter_EventScript_Snorunt_Text_0:
# 49 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	.string "Glaglaglaglagla!$"

ChiiTown_PokemonCenter_EventScript_NeedMarket_Text_0:
# 61 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	.string "Berries, potions… Oh, right, I should get\n"
	.string "a few more Pokéballs from the town\l"
	.string "market!$"

ChiiTown_PokemonCenter_EventScript_RefugePresentation_Text_0:
# 72 "data/maps/ChiiTown_PokemonCenter/scripts.pory"
	.string "Isn't it amazing? This is one of the\n"
	.string "many brand-new Pokémon refuges that\l"
	.string "the Pokémon league council has decided\l"
	.string "to build in towns across all Toku!\p"
	.string "With traveling alone becoming more\n"
	.string "dangerous, many people have chosen to\l"
	.string "train a Pokémon of their own for\l"
	.string "protection.\p"
	.string "Towns were starting to be in dire need\n"
	.string "of proper healing and rest spots for\l"
	.string "Pokémon.\p"
	.string "Oh, sorry, I'll get out of your hair now.\n"
	.string "Talk to the nurse whenever you want her\l"
	.string "to heal your Pokémon!$"

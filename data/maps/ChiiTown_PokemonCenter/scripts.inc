ChiiTown_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ChiiTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

ChiiTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setrespawn HEAL_LOCATION_CHII_TOWN
	gettime
	compare VAR_0x8000, 5
	goto_if_ge ChiiTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION_3
ChiiTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
	setflag FLAG_TEMP_1
	clearflag FLAG_TEMP_2
	random 3
	switch VAR_RESULT
	case 0, ChiiTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION_7
	case 1, ChiiTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION_8
	case 2, ChiiTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION_9
	return

ChiiTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	clearflag FLAG_TEMP_1
	setflag FLAG_TEMP_2
	return

ChiiTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION_3:
	compare VAR_0x8000, 17
	goto_if_le ChiiTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	goto ChiiTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION_2

ChiiTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION_7:
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SHAMISEN_RED
	return

ChiiTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION_8:
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SHAMISEN_BLUE
	return

ChiiTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION_9:
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SHAMISEN_GREEN
	return


ChiiTown_PokemonCenter_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE_CHII
	setvar VAR_0x800A, LOCALID_CHANSEY_CHII
	call Common_EventScript_PkmnCenterNurse_CutTheBullshit
	waitmessage
	waitbuttonpress
	release
	end


ChiiTown_PokemonCenter_EventScript_Shamisen::
	lock
	faceplayer
	speakername ChiiTown_PokemonCenter_EventScript_Shamisen_Text_0
	msgbox ChiiTown_PokemonCenter_EventScript_Shamisen_Text_1
	closemessage
	release
	end


ChiiTown_PokemonCenter_EventScript_ShamisenFan::
	lock
	faceplayer
	speakername ChiiTown_PokemonCenter_EventScript_ShamisenFan_Text_0
	msgbox ChiiTown_PokemonCenter_EventScript_ShamisenFan_Text_1
	closemessage
	release
	end


ChiiTown_PokemonCenter_EventScript_Boy::
	lock
	faceplayer
	speakername ChiiTown_PokemonCenter_EventScript_Boy_Text_0
	msgbox ChiiTown_PokemonCenter_EventScript_Boy_Text_1
	closemessage
	release
	end


ChiiTown_PokemonCenter_EventScript_Mom::
	lock
	faceplayer
	speakername ChiiTown_PokemonCenter_EventScript_Mom_Text_0
	msgbox ChiiTown_PokemonCenter_EventScript_Mom_Text_1
	closemessage
	release
	end


ChiiTown_PokemonCenter_EventScript_WhereShamisen::
	lock
	faceplayer
	speakername ChiiTown_PokemonCenter_EventScript_WhereShamisen_Text_0
	msgbox ChiiTown_PokemonCenter_EventScript_WhereShamisen_Text_1
	closemessage
	release
	end


ChiiTown_PokemonCenter_EventScript_IveComeALongWay::
	lock
	faceplayer
	speakername ChiiTown_PokemonCenter_EventScript_IveComeALongWay_Text_0
	msgbox ChiiTown_PokemonCenter_EventScript_IveComeALongWay_Text_1
	closemessage
	release
	end


ChiiTown_PokemonCenter_EventScript_Snorunt::
	lock
	faceplayer
	setseenmon SPECIES_SNORUNT
	playmoncry SPECIES_SNORUNT, CRY_MODE_NORMAL
	setspeakertomonname SPECIES_SNORUNT
	msgbox ChiiTown_PokemonCenter_EventScript_Snorunt_Text_0
	waitmoncry
	closemessage
	release
	end


ChiiTown_PokemonCenter_EventScript_NeedMarket::
	lock
	faceplayer
	speakername ChiiTown_PokemonCenter_EventScript_NeedMarket_Text_0
	msgbox ChiiTown_PokemonCenter_EventScript_NeedMarket_Text_1
	closemessage
	release
	end


ChiiTown_PokemonCenter_EventScript_RefugePresentation::
	lock
	faceplayer
	speakername ChiiTown_PokemonCenter_EventScript_RefugePresentation_Text_0
	msgbox ChiiTown_PokemonCenter_EventScript_RefugePresentation_Text_1
	closemessage
	setnamedmon SPECIES_CHANSEY
	switch VAR_FACING
	case DIR_NORTH, ChiiTown_PokemonCenter_EventScript_RefugePresentation_3
	case DIR_WEST, ChiiTown_PokemonCenter_EventScript_RefugePresentation_4
	case DIR_EAST, ChiiTown_PokemonCenter_EventScript_RefugePresentation_5
ChiiTown_PokemonCenter_EventScript_RefugePresentation_1:
	waitmovement 0
	removeobject VAR_LAST_TALKED
	playse SE_EXIT
	waitse
	setflag FLAG_POKEMON_REFUGE_PRESENTATION
	release
	end

ChiiTown_PokemonCenter_EventScript_RefugePresentation_3:
	applymovement VAR_LAST_TALKED, ChiiTown_PokemonCenter_EventScript_RefugePresentation_Movement_0
	goto ChiiTown_PokemonCenter_EventScript_RefugePresentation_1

ChiiTown_PokemonCenter_EventScript_RefugePresentation_4:
	applymovement VAR_LAST_TALKED, ChiiTown_PokemonCenter_EventScript_RefugePresentation_Movement_1
	goto ChiiTown_PokemonCenter_EventScript_RefugePresentation_1

ChiiTown_PokemonCenter_EventScript_RefugePresentation_5:
	applymovement VAR_LAST_TALKED, ChiiTown_PokemonCenter_EventScript_RefugePresentation_Movement_1
	goto ChiiTown_PokemonCenter_EventScript_RefugePresentation_1


ChiiTown_PokemonCenter_Movement_LeaveWhenFromBottom:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

ChiiTown_PokemonCenter_Movement_Leave:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

ChiiTown_PokemonCenter_EventScript_MakeNamesUp::
	lock
	faceplayer
	speakername ChiiTown_PokemonCenter_EventScript_MakeNamesUp_Text_0
	msgbox ChiiTown_PokemonCenter_EventScript_MakeNamesUp_Text_1
	closemessage
	release
	end


ChiiTown_PokemonCenter_EventScript_RefugePresentation_Movement_0:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

ChiiTown_PokemonCenter_EventScript_RefugePresentation_Movement_1:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

ChiiTown_PokemonCenter_EventScript_Shamisen_Text_0:
	.string "Shamisen Player$"

ChiiTown_PokemonCenter_EventScript_Shamisen_Text_1:
	.string "Good evening.\p"
	.string "We blind shamisen players sing to\n"
	.string "survive.\p"
	.string "These Pokémon refuges give us a safe\n"
	.string "place to spend the night.$"

ChiiTown_PokemonCenter_EventScript_ShamisenFan_Text_0:
	.string "Shamisen Fan$"

ChiiTown_PokemonCenter_EventScript_ShamisenFan_Text_1:
	.string "Such a beautiful voice…\p"
	.string "Such sorrowful melodies…\p"
	.string "Such ethereal beauty…\p"
	.string "I could listen to her forever…\p"
	.string "Even though she can't see me, I sure\n"
	.string "hope she'll notice me one day…$"

ChiiTown_PokemonCenter_EventScript_Boy_Text_0:
	.string "Little boy$"

ChiiTown_PokemonCenter_EventScript_Boy_Text_1:
	.string "I'm here with my mama!\p"
	.string "The music lady's nice!$"

ChiiTown_PokemonCenter_EventScript_Mom_Text_0:
	.string "Little boy's mom$"

ChiiTown_PokemonCenter_EventScript_Mom_Text_1:
	.string "Traveling shamisen players take\n"
	.string "shelter in Pokémon refuges when the\l"
	.string "night falls.\p"
	.string "Their singing makes for such a cosy\n"
	.string "atmosphere!$"

ChiiTown_PokemonCenter_EventScript_WhereShamisen_Text_0:
	.string "Weird man$"

ChiiTown_PokemonCenter_EventScript_WhereShamisen_Text_1:
	.string "Where's that cute shamisen player\n"
	.string "that was here last night?$"

ChiiTown_PokemonCenter_EventScript_IveComeALongWay_Text_0:
	.string "Weary traveler$"

ChiiTown_PokemonCenter_EventScript_IveComeALongWay_Text_1:
	.string "I'm so glad I found this refuge. I've\n"
	.string "come a long way and my feet hurt.\p"
	.string "My Pokémon and I will rest here for a\n"
	.string "while.$"

ChiiTown_PokemonCenter_EventScript_Snorunt_Text_0:
	.string "Glaglaglaglagla!$"

ChiiTown_PokemonCenter_EventScript_NeedMarket_Text_0:
	.string "Woman$"

ChiiTown_PokemonCenter_EventScript_NeedMarket_Text_1:
	.string "Berries, ointments… Oh, right, I\n"
	.string "should get a few more Poké Balls from\l"
	.string "the town market!$"

ChiiTown_PokemonCenter_EventScript_RefugePresentation_Text_0:
	.string "Talkative man$"

ChiiTown_PokemonCenter_EventScript_RefugePresentation_Text_1:
	.string "Isn't it amazing? This is one of the\n"
	.string "many brand-new Pokémon refuges that\l"
	.string "the Pokémon league council has\l"
	.string "decided to build in towns across all\l"
	.string "Toku!\p"
	.string "With traveling alone becoming more\n"
	.string "dangerous, many people are now\l"
	.string "training a Pokémon of their own for\l"
	.string "protection.\p"
	.string "Towns were starting to be in dire need\n"
	.string "of proper healing and rest spots for\l"
	.string "Pokémon.\p"
	.string "Oh, sorry, I'll get out of your hair\n"
	.string "now. Talk to the nurse and her\l"
	.string "Chansey whenever you want her to\l"
	.string "heal your Pokémon!$"

ChiiTown_PokemonCenter_EventScript_MakeNamesUp_Text_0:
	.string "Little Boy$"

ChiiTown_PokemonCenter_EventScript_MakeNamesUp_Text_1:
	.string "You know what happens if I see a\n"
	.string "Pokémon and I don't know its name?\p"
	.string "I just make it right up!\n"
	.string "I don't care about any silly “real”\l"
	.string "names!\p"
	.string "And neither should you! Be free of\n"
	.string "the diktat of naming accuracy!$"

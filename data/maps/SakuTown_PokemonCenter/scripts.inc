SakuTown_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SakuTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

SakuTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setrespawn HEAL_LOCATION_SAKU_TOWN
	return


SakuTown_PokemonCenter_EventScript_Nurse::
	lock
	faceplayer
	speakername SakuTown_PokemonCenter_EventScript_Nurse_Text_0
	msgbox SakuTown_PokemonCenter_EventScript_Nurse_Text_1
	fadescreenswapbuffers FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	fadescreenswapbuffers FADE_FROM_BLACK
	speakername SakuTown_PokemonCenter_EventScript_Nurse_Text_0
	msgbox SakuTown_PokemonCenter_EventScript_Nurse_Text_2
	turnobject VAR_LAST_TALKED, DIR_SOUTH
	release
	end


SakuTown_PokemonCenter_EventScript_BewareOfFallingBricks::
	lock
	faceplayer
	speakername SakuTown_PokemonCenter_EventScript_Nurse_Text_0
	msgbox SakuTown_PokemonCenter_EventScript_BewareOfFallingBricks_Text_0
	closemessage
	release
	end


SakuTown_PokemonCenter_EventScript_Pushing::
	delay 30
	faceplayer
	speakername SakuTown_PokemonCenter_EventScript_Pushing_Text_0
	msgbox SakuTown_PokemonCenter_EventScript_Pushing_Text_1
	closemessage
	switch VAR_FACING
	case DIR_EAST, SakuTown_PokemonCenter_EventScript_Pushing_3
	case DIR_SOUTH, SakuTown_PokemonCenter_EventScript_Pushing_4
SakuTown_PokemonCenter_EventScript_Pushing_1:
	waitmovement VAR_LAST_TALKED
	waitmovement OBJ_EVENT_ID_PLAYER
	return

SakuTown_PokemonCenter_EventScript_Pushing_3:
	applymovement VAR_LAST_TALKED, SakuTown_PokemonCenter_Movement_PushesPlayer
	applymovement OBJ_EVENT_ID_PLAYER, SakuTown_PokemonCenter_Movement_PlayerPushed
	goto SakuTown_PokemonCenter_EventScript_Pushing_1

SakuTown_PokemonCenter_EventScript_Pushing_4:
	applymovement VAR_LAST_TALKED, SakuTown_PokemonCenter_Movement_PushesPlayerUp
	applymovement OBJ_EVENT_ID_PLAYER, SakuTown_PokemonCenter_Movement_PlayerPushedUp
	goto SakuTown_PokemonCenter_EventScript_Pushing_1


SakuTown_PokemonCenter_EventScript_Grunt1::
	lock
	speakername SakuTown_PokemonCenter_EventScript_Pushing_Text_0
	msgbox SakuTown_PokemonCenter_EventScript_Grunt1_Text_0
	closemessage
	call SakuTown_PokemonCenter_EventScript_Pushing
	release
	end


SakuTown_PokemonCenter_EventScript_Grunt2::
	lock
	speakername SakuTown_PokemonCenter_EventScript_Pushing_Text_0
	msgbox SakuTown_PokemonCenter_EventScript_Grunt2_Text_0
	closemessage
	call SakuTown_PokemonCenter_EventScript_Pushing
	release
	end


SakuTown_PokemonCenter_EventScript_Grunt3::
	lock
	speakername SakuTown_PokemonCenter_EventScript_Pushing_Text_0
	msgbox SakuTown_PokemonCenter_EventScript_Grunt3_Text_0
	closemessage
	call SakuTown_PokemonCenter_EventScript_Pushing
	release
	end


SakuTown_PokemonCenter_Movement_PlayerPushed:
	lock_facing_direction
	jump_2_left
	unlock_facing_direction
	step_end

SakuTown_PokemonCenter_Movement_PushesPlayer:
	walk_left
	delay_16
	walk_right
	face_original_direction
	step_end

SakuTown_PokemonCenter_Movement_PlayerPushedUp:
	lock_facing_direction
	jump_2_up
	unlock_facing_direction
	step_end

SakuTown_PokemonCenter_Movement_PushesPlayerUp:
	walk_up
	delay_16
	walk_down
	face_original_direction
	step_end

SakuTown_PokemonCenter_EventScript_Makuhita::
	lock
	setseenmon SPECIES_MAKUHITA
	setspeakertomonname SPECIES_MAKUHITA
	playmoncry SPECIES_MAKUHITA, CRY_MODE_WEAK
	msgbox SakuTown_PokemonCenter_EventScript_Makuhita_Text_0
	waitmoncry
	waitmessage
	speakername NULL
	msgbox SakuTown_PokemonCenter_EventScript_Makuhita_Text_1
	release
	return


SakuTown_PokemonCenter_EventScript_Nurse_Text_0:
	.string "Nurse$"

SakuTown_PokemonCenter_EventScript_Nurse_Text_1:
	.string "Hello! Apologies for the mess, we're\n"
	.string "not fully set up yet!\p"
	.string "Let me heal your Pokémon!$"

SakuTown_PokemonCenter_EventScript_Nurse_Text_2:
	.string "Come back soon!$"

SakuTown_PokemonCenter_EventScript_BewareOfFallingBricks_Text_0:
	.string "This Pokémon refuge is brand-new,\n"
	.string "courtesy of the Toku Council!\p"
	.string "As you can see, it's still being built.\n"
	.string "Watch out for the falling bricks, ha\l"
	.string "ha, just kidding!\p"
	.string "Seriously though, do watch out. We're\n"
	.string "held responsible if anything happens\l"
	.string "to you.$"

SakuTown_PokemonCenter_EventScript_Pushing_Text_0:
	.string "Shady man$"

SakuTown_PokemonCenter_EventScript_Pushing_Text_1:
	.string "Watchu lookin' at? Scram!$"

SakuTown_PokemonCenter_EventScript_Grunt1_Text_0:
	.string "Great plan…$"

SakuTown_PokemonCenter_EventScript_Grunt2_Text_0:
	.string "We should do this next…$"

SakuTown_PokemonCenter_EventScript_Grunt3_Text_0:
	.string "On Beachbound Route…$"

SakuTown_PokemonCenter_EventScript_Makuhita_Text_0:
	.string "Kuhu…$"

SakuTown_PokemonCenter_EventScript_Makuhita_Text_1:
	.string "The Pokémon is resting.$"

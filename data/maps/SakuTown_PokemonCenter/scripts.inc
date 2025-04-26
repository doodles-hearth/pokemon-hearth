SakuTown_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SakuTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SakuTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

SakuTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setrespawn HEAL_LOCATION_SAKU_TOWN
	returnqueststate QUEST_KURALOVERS
	copyvar VAR_TEMP_0, VAR_RESULT
	returnqueststate QUEST_KURAESPEON
	copyvar VAR_TEMP_1, VAR_RESULT
	returnqueststate QUEST_KURASCYTHER
	copyvar VAR_TEMP_2, VAR_RESULT
	compare VAR_TEMP_0, 4
	goto_if_eq SakuTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION_9
SakuTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION_7:
	compare VAR_SAKU_KURA_QUEST_SCYTHER_STATE, 2
	goto_if_eq SakuTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
	compare VAR_TEMP_2, 3
	goto_if_eq SakuTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION_3
	compare VAR_TEMP_2, 4
	goto_if_eq SakuTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION_3
	return

SakuTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	clearflag FLAG_HIDE_SAKU_REFUGE_FARMERS_1
	setflag FLAG_HIDE_SAKU_REFUGE_FARMERS_2
	return

SakuTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
	clearflag FLAG_HIDE_SAKU_REFUGE_FARMERS_2
	setflag FLAG_HIDE_SAKU_REFUGE_FARMERS_1
	return

SakuTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION_3:
	setflag FLAG_HIDE_SAKU_REFUGE_FARMERS_1
	setflag FLAG_HIDE_SAKU_REFUGE_FARMERS_2
	return

SakuTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION_8:
	compare VAR_TEMP_2, 1
	goto_if_eq SakuTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	goto SakuTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION_7

SakuTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION_9:
	compare VAR_TEMP_1, 4
	goto_if_eq SakuTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION_8
	goto SakuTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION_7

SakuTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_SAKU_KURA_QUEST_SCYTHER_STATE, 1, SakuTown_PokemonCenter_EventScript_ScytherQuest
	.2byte 0


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


SakuTown_PokemonCenter_EventScript_ScytherQuest::
	lock
	setvar VAR_SAKU_KURA_QUEST_SCYTHER_STATE, 2
	applymovement 1, SakuTown_PokemonCenter_EventScript_ScytherQuest_Movement_0
	waitmovement 0
	speakername SakuTown_PokemonCenter_EventScript_Nurse_Text_0
	msgbox SakuTown_PokemonCenter_EventScript_ScytherQuest_Text_0
	waitmessage
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, SakuTown_PokemonCenter_EventScript_ScytherQuest_Movement_1
	speakername SakuTown_PokemonCenter_EventScript_ScytherQuest_Text_1
	msgbox SakuTown_PokemonCenter_EventScript_ScytherQuest_Text_2
	waitmessage
	closemessage
	applymovement 1, SakuTown_PokemonCenter_EventScript_ScytherQuest_Movement_2
	waitmovement 0
	speakername SakuTown_PokemonCenter_EventScript_Nurse_Text_0
	msgbox SakuTown_PokemonCenter_EventScript_ScytherQuest_Text_3
	waitmessage
	closemessage
	return


SakuTown_PokemonCenter_EventScript_Farmer1::
	lock
	faceplayer
	speakername SakuTown_PokemonCenter_EventScript_ScytherQuest_Text_1
	returnqueststate QUEST_KURASCYTHER
	switch VAR_RESULT
	case 1, SakuTown_PokemonCenter_EventScript_Farmer1_3
	case 2, SakuTown_PokemonCenter_EventScript_Farmer1_4
SakuTown_PokemonCenter_EventScript_Farmer1_1:
	release
	end

SakuTown_PokemonCenter_EventScript_Farmer1_3:
	call FarmerGivesQuest
	goto SakuTown_PokemonCenter_EventScript_Farmer1_1

SakuTown_PokemonCenter_EventScript_Farmer1_4:
	call FarmerWaitsMedicine
	goto SakuTown_PokemonCenter_EventScript_Farmer1_1


FarmerGivesQuest:
	msgbox FarmerGivesQuest_Text_0
	startquest QUEST_KURASCYTHER
	applymovement 9, FarmerGivesQuest_Movement_0
	return


FarmerWaitsMedicine:
	msgbox FarmerWaitsMedicine_Text_0
	return


SakuTown_PokemonCenter_EventScript_Farmer2::
	lock
	speakername SakuTown_PokemonCenter_EventScript_ScytherQuest_Text_1
	msgbox SakuTown_PokemonCenter_EventScript_Farmer2_Text_0
	closemessage
	playmoncry SPECIES_SCYTHER, CRY_MODE_NORMAL
	setspeakertomonname SPECIES_SCYTHER
	msgbox SakuTown_PokemonCenter_EventScript_Farmer2_Text_1
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


SakuTown_PokemonCenter_EventScript_ScytherQuest_Movement_0:
	face_right
	step_end

SakuTown_PokemonCenter_EventScript_ScytherQuest_Movement_1:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SakuTown_PokemonCenter_EventScript_ScytherQuest_Movement_2:
	walk_in_place_down
	step_end

FarmerGivesQuest_Movement_0:
	face_original_direction
	step_end

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

SakuTown_PokemonCenter_EventScript_ScytherQuest_Text_0:
	.string "I'm sorry, but there's nothing I can\n"
	.string "do yet. We haven't received the tools\l"
	.string "that allow us to heal a Pokémon in\l"
	.string "this dire of a state.$"

SakuTown_PokemonCenter_EventScript_ScytherQuest_Text_1:
	.string "Farmer$"

SakuTown_PokemonCenter_EventScript_ScytherQuest_Text_2:
	.string "Well y'have to do somet'in'! Can'tcha\n"
	.string "see she's in pain?!$"

SakuTown_PokemonCenter_EventScript_ScytherQuest_Text_3:
	.string "She can stay here for as long as she\n"
	.string "needs to. I'll try to keep her in as\l"
	.string "good of a shape as I can.$"

FarmerGivesQuest_Text_0:
	.string "The nurse 'ere said that the new\n"
	.string "fangled technology from the Toku\l"
	.string "Council isn't here yet. As such, she\l"
	.string "can't be cured of whatever's ailin'\l"
	.string "her.\p"
	.string "Please! If you can spare some time,\n"
	.string "can you help us find someone or\l"
	.string "something to cure our girl?$"

FarmerWaitsMedicine_Text_0:
	.string "So? Have ya found anythin' yet?$"

SakuTown_PokemonCenter_EventScript_Farmer2_Text_0:
	.string "There, there, girl… It'll be okay…$"

SakuTown_PokemonCenter_EventScript_Farmer2_Text_1:
	.string "{FONT_SMALL} Gyooo…$"

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

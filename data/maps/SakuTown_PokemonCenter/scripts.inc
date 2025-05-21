SakuTown_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SakuTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SakuTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

SakuTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setrespawn HEAL_LOCATION_SAKU_TOWN
	returnqueststate QUEST_SAKURALOVERS
	copyvar VAR_TEMP_0, VAR_RESULT
	returnqueststate QUEST_SAKURAESPEON
	copyvar VAR_TEMP_1, VAR_RESULT
	returnqueststate QUEST_SAKURASCYTHER
	copyvar VAR_TEMP_2, VAR_RESULT
	setflag FLAG_HIDE_SAKU_REFUGE_FARMERS_1
	setflag FLAG_HIDE_SAKU_REFUGE_FARMERS_2
	compare VAR_TEMP_0, 4
	goto_if_eq SakuTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION_9
SakuTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION_6:
	compare VAR_TEMP_2, 3
	goto_if_eq SakuTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
	compare VAR_TEMP_2, 4
	goto_if_eq SakuTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
	compare VAR_SAKU_KURA_QUEST_SCYTHER_STATE, 2
	goto_if_ge SakuTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION_3
	return

SakuTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	clearflag FLAG_HIDE_SAKU_REFUGE_FARMERS_1
	setflag FLAG_HIDE_SAKU_REFUGE_FARMERS_2
	return

SakuTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
	setflag FLAG_HIDE_SAKU_REFUGE_FARMERS_1
	setflag FLAG_HIDE_SAKU_REFUGE_FARMERS_2
	return

SakuTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION_3:
	clearflag FLAG_HIDE_SAKU_REFUGE_FARMERS_2
	setflag FLAG_HIDE_SAKU_REFUGE_FARMERS_1
	return

SakuTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION_8:
	compare VAR_TEMP_2, 1
	goto_if_eq SakuTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	goto SakuTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION_6

SakuTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION_9:
	compare VAR_TEMP_1, 4
	goto_if_eq SakuTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION_8
	goto SakuTown_PokemonCenter_MapScripts_MAP_SCRIPT_ON_TRANSITION_6

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
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, SakuTown_PokemonCenter_EventScript_ScytherQuest_Movement_1
	speakername SakuTown_PokemonCenter_EventScript_ScytherQuest_Text_1
	msgbox SakuTown_PokemonCenter_EventScript_ScytherQuest_Text_2
	closemessage
	applymovement 1, SakuTown_PokemonCenter_EventScript_ScytherQuest_Movement_2
	waitmovement 0
	speakername SakuTown_PokemonCenter_EventScript_Nurse_Text_0
	msgbox SakuTown_PokemonCenter_EventScript_ScytherQuest_Text_3
	closemessage
	applymovement 9, SakuTown_PokemonCenter_EventScript_ScytherQuest_Movement_0
	waitmovement 0
	return


SakuTown_PokemonCenter_EventScript_Farmer1::
	lock
	faceplayer
	speakername SakuTown_PokemonCenter_EventScript_ScytherQuest_Text_1
	returnqueststate QUEST_SAKURASCYTHER
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
	startquest QUEST_SAKURASCYTHER
	applymovement 9, FarmerGivesQuest_Movement_0
	return


FarmerWaitsMedicine:
	msgbox FarmerWaitsMedicine_Text_0
	checkitem ITEM_SPECIAL_MEDICINE, 1
	compare VAR_SAKU_KURA_QUEST_SCYTHER_STATE, 6
	goto_if_eq FarmerWaitsMedicine_4
FarmerWaitsMedicine_3:
	closemessage
FarmerWaitsMedicine_1:
	return

FarmerWaitsMedicine_2:
	call HealedScytherScript
	goto FarmerWaitsMedicine_1

FarmerWaitsMedicine_4:
	compare VAR_RESULT, TRUE
	goto_if_eq FarmerWaitsMedicine_2
	goto FarmerWaitsMedicine_3


HealedScytherScript:
	mcdialogue HealedScytherScript_Text_0, HealedScytherScript_Text_1
	closemessage
	playse SE_PIN
	applymovement 11, HealedScytherScript_Movement_0
	waitmovement 0
	waitse
	speakername SakuTown_PokemonCenter_EventScript_ScytherQuest_Text_1
	msgbox HealedScytherScript_Text_2
	closemessage
	playfanfare MUS_OBTAIN_ITEM
	msgbox HealedScytherScript_Text_3
	waitfanfare
	removeitem ITEM_SPECIAL_MEDICINE
	closemessage
	applymovement 11, HealedScytherScript_Movement_1
	waitmovement 0
	speakername SakuTown_PokemonCenter_EventScript_ScytherQuest_Text_1
	msgbox HealedScytherScript_Text_4
	closemessage
	applymovement 13, HealedScytherScript_Movement_2
	playmoncry SPECIES_SCYTHER, CRY_MODE_WEAK
	setspeakertomonname SPECIES_SCYTHER
	msgbox HealedScytherScript_Text_5
	closemessage
	playse SE_USE_ITEM
	applymovement 13, HealedScytherScript_Movement_3
	waitmovement 0
	applymovement 11, HealedScytherScript_Movement_4
	applymovement 12, HealedScytherScript_Movement_5
	waitmovement 11
	waitmovement 12
	speakername SakuTown_PokemonCenter_EventScript_ScytherQuest_Text_1
	msgbox HealedScytherScript_Text_6
	closemessage
	mcdialogue HealedScytherScript_Text_7
	speakername SakuTown_PokemonCenter_EventScript_ScytherQuest_Text_1
	msgbox HealedScytherScript_Text_8
	applymovement 11, HealedScytherScript_Movement_6
	waitmovement 0
	applymovement 13, HealedScytherScript_Movement_7
	playmoncry SPECIES_SCYTHER, CRY_MODE_NORMAL
	setspeakertomonname SPECIES_SCYTHER
	msgbox HealedScytherScript_Text_9
	waitmoncry
	closemessage
	speakername SakuTown_PokemonCenter_EventScript_ScytherQuest_Text_1
	msgbox HealedScytherScript_Text_10
	closemessage
	applymovement 11, HealedScytherScript_Movement_8
	waitmovement 0
	speakername SakuTown_PokemonCenter_EventScript_ScytherQuest_Text_1
	msgbox HealedScytherScript_Text_11
	closemessage
	applymovement 12, HealedScytherScript_Movement_9
	applymovement 13, HealedScytherScript_Movement_10
	applymovement 11, HealedScytherScript_Movement_11
	waitmovement 12
	waitmovement 13
	waitmovement 11
	removeobject 12
	removeobject 13
	removeobject 11
	questmenu QUEST_MENU_SET_REWARD, QUEST_SAKURASCYTHER
	setvar VAR_SAKU_KURA_QUEST_SCYTHER_STATE, 7
	return


SakuTown_PokemonCenter_EventScript_Farmer2::
	lock
	speakername SakuTown_PokemonCenter_EventScript_ScytherQuest_Text_1
	msgbox SakuTown_PokemonCenter_EventScript_Farmer2_Text_0
	closemessage
	playmoncry SPECIES_SCYTHER, CRY_MODE_WEAK
	setspeakertomonname SPECIES_SCYTHER
	msgbox HealedScytherScript_Text_5
	waitmoncry
	closemessage
	release
	return


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
	closemessage
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
	walk_in_place_fast_down
	step_end

FarmerGivesQuest_Movement_0:
	face_original_direction
	step_end

HealedScytherScript_Movement_0:
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	step_end

HealedScytherScript_Movement_1:
	walk_in_place_fast_right
	step_end

HealedScytherScript_Movement_2:
	face_left
	step_end

HealedScytherScript_Movement_3:
	emote_double_exclamation_mark
	delay_16
	delay_16
	delay_16
	jump_in_place_down
	jump_in_place_down
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	face_down
	delay_16
	emote_heart
	delay_16
	delay_16
	delay_16
	step_end

HealedScytherScript_Movement_4:
	walk_in_place_fast_left
	step_end

HealedScytherScript_Movement_5:
	walk_up
	face_left
	step_end

HealedScytherScript_Movement_6:
	face_up
	step_end

HealedScytherScript_Movement_7:
	face_up
	delay_4
	face_left
	delay_4
	face_down
	delay_4
	face_right
	delay_4
	step_end

HealedScytherScript_Movement_8:
	face_player
	step_end

HealedScytherScript_Movement_9:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

HealedScytherScript_Movement_10:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

HealedScytherScript_Movement_11:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	walk_right
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
	.string "do yet.\p"
	.string "We haven't tools that allow us to heal\n"
	.string "a Pokémon in this dire a state.$"

SakuTown_PokemonCenter_EventScript_ScytherQuest_Text_1:
	.string "Farmer$"

SakuTown_PokemonCenter_EventScript_ScytherQuest_Text_2:
	.string "Y'have to do somet'in', miss!\n"
	.string "Cantcha see she's in pain?!$"

SakuTown_PokemonCenter_EventScript_ScytherQuest_Text_3:
	.string "She can stay here for as long as she\n"
	.string "needs.\p"
	.string "I'll keep her in as good a shape as I\n"
	.string "can.$"

FarmerGivesQuest_Text_0:
	.string "The nurse 'ere said the newfangled\n"
	.string "medical technology from the Toku\l"
	.string "Council isn't here yet.\p"
	.string "As such, Scyther can't be cured of\n"
	.string "whatever's ailin' her.\p"
	.string "Please! If you can spare some time,\n"
	.string "help us find someone or something to\l"
	.string "cure our girl!$"

FarmerWaitsMedicine_Text_0:
	.string "So? Have ya found anythin' yet?$"

HealedScytherScript_Text_0:
	.string "Right here.$"

HealedScytherScript_Text_1:
	.string "I have this medicine.$"

HealedScytherScript_Text_2:
	.string "That's it! Please, Wielder, quickly!$"

HealedScytherScript_Text_3:
	.string "{PLAYER} gave the Special Medicine.$"

HealedScytherScript_Text_4:
	.string "Here, girl…\n"
	.string "This'll make ya feel better…$"

HealedScytherScript_Text_5:
	.string "{FONT_SMALL} Gyooo…$"

HealedScytherScript_Text_6:
	.string "Wielder… I don't know how to thank ya.\n"
	.string "We were so worried…\p"
	.string "Where did you get this medicine?$"

HealedScytherScript_Text_7:
	.string "The healer in Kura Village!$"

HealedScytherScript_Text_8:
	.string "Kura Village, eh…$"

HealedScytherScript_Text_9:
	.string "Gyaaa!$"

HealedScytherScript_Text_10:
	.string "{FONT_SMALL} Maybe they ain't s'bad afta' all…$"

HealedScytherScript_Text_11:
	.string "Thank you, Wielder. I can give ye a\n"
	.string "reward for your effors. Just meet us\l"
	.string "in the fields outside.$"

SakuTown_PokemonCenter_EventScript_Farmer2_Text_0:
	.string "There, there, girl…\n"
	.string "It'll be okay…$"

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

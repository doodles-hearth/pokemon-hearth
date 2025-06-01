WhiteslateRoute_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, WhiteslateRoute_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

WhiteslateRoute_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	getroutechallengestate ROUTE_CHALLENGE_WHITESLATE_YIFU
	compare VAR_RESULT, ROUTE_CHALLENGE_STATE_INITIAL
	goto_if_ne WhiteslateRoute_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
	return

WhiteslateRoute_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	setvar VAR_TEMP_2, 1
	setflag FLAG_TEMP_1
	return

WhiteslateRoute_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
	compare VAR_RESULT, ROUTE_CHALLENGE_STATE_EXPLAINED
	goto_if_ne WhiteslateRoute_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return


WhiteslateRoute_Trigger_ShamisenPlayerTop::
	lockall
	call WhiteslateRoute_EventScript_ShamisenCallsOut
	applymovement OBJ_EVENT_ID_PLAYER, WhiteslateRoute_Trigger_ShamisenPlayerTop_Movement_0
	waitmovement OBJ_EVENT_ID_PLAYER
	getroutechallengestate ROUTE_CHALLENGE_WHITESLATE_YIFU
	compare VAR_RESULT, ROUTE_CHALLENGE_STATE_EXPLAINED
	goto_if_eq WhiteslateRoute_Trigger_ShamisenPlayerTop_2
	call WhiteslateRoute_EventScript_ShamisenChallenge
WhiteslateRoute_Trigger_ShamisenPlayerTop_1:
	releaseall
	return

WhiteslateRoute_Trigger_ShamisenPlayerTop_2:
	call WhiteslateRoute_EventScript_ShamisenChallengeAreYouReady
	goto WhiteslateRoute_Trigger_ShamisenPlayerTop_1


WhiteslateRoute_Trigger_ShamisenPlayerBottom::
	lockall
	call WhiteslateRoute_EventScript_ShamisenCallsOut
	applymovement OBJ_EVENT_ID_PLAYER, WhiteslateRoute_Trigger_ShamisenPlayerBottom_Movement_0
	waitmovement OBJ_EVENT_ID_PLAYER
	getroutechallengestate ROUTE_CHALLENGE_WHITESLATE_YIFU
	compare VAR_RESULT, ROUTE_CHALLENGE_STATE_EXPLAINED
	goto_if_eq WhiteslateRoute_Trigger_ShamisenPlayerBottom_2
	call WhiteslateRoute_EventScript_ShamisenChallenge
WhiteslateRoute_Trigger_ShamisenPlayerBottom_1:
	releaseall
	return

WhiteslateRoute_Trigger_ShamisenPlayerBottom_2:
	call WhiteslateRoute_EventScript_ShamisenChallengeAreYouReady
	goto WhiteslateRoute_Trigger_ShamisenPlayerBottom_1


WhiteslateRoute_EventScript_ShamisenChallengeAreYouReady::
	speakername WhiteslateRoute_EventScript_ShamisenChallengeAreYouReady_Text_0
	msgbox WhiteslateRoute_EventScript_ShamisenChallengeAreYouReady_Text_1
	call WhiteslateRoute_EventScript_ShamisenPlayerChoice
	return


WhiteslateRoute_EventScript_ShamisenChallenge::
	speakername WhiteslateRoute_EventScript_ShamisenChallengeAreYouReady_Text_0
	msgbox WhiteslateRoute_EventScript_ShamisenChallenge_Text_0
	call WhiteslateRoute_EventScript_ShamisenPlayerChoice
	return


WhiteslateRoute_EventScript_ShamisenCallsOut::
	applymovement 23, WhiteslateRoute_EventScript_ShamisenCallsOut_Movement_0
	waitmovement 23
	speakername WhiteslateRoute_EventScript_ShamisenChallengeAreYouReady_Text_0
	msgbox WhiteslateRoute_EventScript_ShamisenCallsOut_Text_0
	closemessage
	return


WhiteslateRoute_EventScript_ShamisenPlayer::
	lock
	applymovement 23, WhiteslateRoute_EventScript_ShamisenPlayer_Movement_0
	waitmovement 23
	speakername WhiteslateRoute_EventScript_ShamisenChallengeAreYouReady_Text_0
	msgbox WhiteslateRoute_EventScript_ShamisenChallenge_Text_0
	call WhiteslateRoute_EventScript_ShamisenPlayerChoice
	release
	return


WhiteslateRoute_EventScript_ShamisenPlayerChoice::
	mcdialogue WhiteslateRoute_EventScript_ShamisenPlayerChoice_Text_0, WhiteslateRoute_EventScript_ShamisenPlayerChoice_Text_1
	closemessage
	switch VAR_RESULT
	case 0, WhiteslateRoute_EventScript_ShamisenPlayerChoice_2
	case 1, WhiteslateRoute_EventScript_ShamisenPlayerChoice_3
	return

WhiteslateRoute_EventScript_ShamisenPlayerChoice_2:
	speakername WhiteslateRoute_EventScript_ShamisenChallengeAreYouReady_Text_0
	msgbox WhiteslateRoute_EventScript_ShamisenPlayerChoice_Text_2
	closemessage
	applymovement 24, WhiteslateRoute_EventScript_ShamisenPlayerChoice_Movement_0
	applymovement 23, WhiteslateRoute_EventScript_ShamisenPlayerChoice_Movement_1
	delay 16
	applymovement OBJ_EVENT_ID_PLAYER, WhiteslateRoute_EventScript_ShamisenPlayerChoice_Movement_2
	waitmovement 23
	waitmovement 24
	removeobject 23
	removeobject 24
	setroutechallengestate ROUTE_CHALLENGE_WHITESLATE_YIFU, ROUTE_CHALLENGE_STATE_STARTED
	setvar VAR_TEMP_2, 1
	setflag FLAG_TEMP_1
	return

WhiteslateRoute_EventScript_ShamisenPlayerChoice_3:
	speakername WhiteslateRoute_EventScript_ShamisenChallengeAreYouReady_Text_0
	msgbox WhiteslateRoute_EventScript_ShamisenPlayerChoice_Text_3
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, WhiteslateRoute_EventScript_ShamisenPlayerChoice_Movement_3
	waitmovement OBJ_EVENT_ID_PLAYER
	setroutechallengestate ROUTE_CHALLENGE_WHITESLATE_YIFU, ROUTE_CHALLENGE_STATE_EXPLAINED
	return


WhiteslateRoute_EventScript_ShamisenPlayerPokemon::
	lock
	faceplayer
	setseenmon SPECIES_GROWLITHE
	setspeakertomonname SPECIES_GROWLITHE
	playmoncry SPECIES_GROWLITHE, CRY_MODE_NORMAL
	msgbox WhiteslateRoute_EventScript_ShamisenPlayerPokemon_Text_0
	waitmoncry
	release
	return


WhiteslateRoute_EventScript_Itsumi::
	trainerbattle_single TRAINER_ITSUMI, WhiteslateRoute_EventScript_Itsumi_Text_0, WhiteslateRoute_EventScript_Itsumi_Text_1
	speakername WhiteslateRoute_EventScript_Itsumi_Text_2
	msgbox WhiteslateRoute_EventScript_Itsumi_Text_3, MSGBOX_AUTOCLOSE
	end


WhiteslateRoute_EventScript_Ryosuke::
	trainerbattle_single TRAINER_RYOSUKE, WhiteslateRoute_EventScript_Ryosuke_Text_0, WhiteslateRoute_EventScript_Ryosuke_Text_1
	speakername WhiteslateRoute_EventScript_Ryosuke_Text_2
	msgbox WhiteslateRoute_EventScript_Ryosuke_Text_3, MSGBOX_AUTOCLOSE
	end


WhiteslateRoute_EventScript_Riku::
	trainerbattle_single TRAINER_RIKU, WhiteslateRoute_EventScript_Riku_Text_0, WhiteslateRoute_EventScript_Riku_Text_1
	speakername WhiteslateRoute_EventScript_Riku_Text_2
	msgbox WhiteslateRoute_EventScript_Riku_Text_3, MSGBOX_AUTOCLOSE
	end


WhiteslateRoute_EventScript_Tomomi::
	trainerbattle_single TRAINER_TOMOMI, WhiteslateRoute_EventScript_Tomomi_Text_0, WhiteslateRoute_EventScript_Tomomi_Text_1
	speakername WhiteslateRoute_EventScript_Tomomi_Text_2
	msgbox WhiteslateRoute_EventScript_Tomomi_Text_3, MSGBOX_AUTOCLOSE
	end


WhiteslateRoute_EventScript_Yono::
	trainerbattle_single TRAINER_YONO, WhiteslateRoute_EventScript_Yono_Text_0, WhiteslateRoute_EventScript_Yono_Text_1
	speakername WhiteslateRoute_EventScript_Yono_Text_2
	msgbox WhiteslateRoute_EventScript_Yono_Text_3, MSGBOX_AUTOCLOSE
	end


WhiteslateRoute_EventScript_Sumi::
	trainerbattle_single TRAINER_SUMI, WhiteslateRoute_EventScript_Sumi_Text_0, WhiteslateRoute_EventScript_Sumi_Text_1
	speakername WhiteslateRoute_EventScript_Sumi_Text_2
	msgbox WhiteslateRoute_EventScript_Sumi_Text_3, MSGBOX_AUTOCLOSE
	end


WhiteslateRoute_EventScript_Tomiko::
	trainerbattle_single TRAINER_TOMIKO, WhiteslateRoute_EventScript_Tomiko_Text_0, WhiteslateRoute_EventScript_Tomiko_Text_1
	setspeakertomonname SPECIES_SPINDA
	speakername WhiteslateRoute_EventScript_Tomiko_Text_2
	msgbox WhiteslateRoute_EventScript_Tomiko_Text_3, MSGBOX_AUTOCLOSE
	end


WhiteslateRoute_EventScript_Utaro::
	trainerbattle_single TRAINER_UTARO, WhiteslateRoute_EventScript_Utaro_Text_0, WhiteslateRoute_EventScript_Utaro_Text_1
	setspeakertomonname SPECIES_SEVIPER
	speakername WhiteslateRoute_EventScript_Utaro_Text_2
	msgbox WhiteslateRoute_EventScript_Utaro_Text_3, MSGBOX_AUTOCLOSE
	end


WhiteslateRoute_EventScript_ShuckleGirl::
	setnamedmon SPECIES_SHUCKLE
	speakername WhiteslateRoute_EventScript_ShuckleGirl_Text_0
	msgbox WhiteslateRoute_EventScript_ShuckleGirl_Text_1, MSGBOX_AUTOCLOSE
	end


WhiteslateRoute_EventScript_Deerling::
	lock
	faceplayer
	setseenmon SPECIES_DEERLING
	setspeakertomonname SPECIES_DEERLING
	playmoncry SPECIES_DEERLING, CRY_MODE_NORMAL
	msgbox WhiteslateRoute_EventScript_Deerling_Text_0
	waitmoncry
	closemessage
	release
	return


WhiteslateRoute_EventScript_Shuckle::
	lock
	faceplayer
	setseenmon SPECIES_SHUCKLE
	setspeakertomonname SPECIES_SHUCKLE
	playmoncry SPECIES_SHUCKLE, CRY_MODE_NORMAL
	msgbox WhiteslateRoute_EventScript_Shuckle_Text_0
	waitmoncry
	closemessage
	goto_if_unset FLAG_DAILY_SHUCKLE_BERRY_JUICE, WhiteslateRoute_EventScript_Shuckle_2
WhiteslateRoute_EventScript_Shuckle_1:
	release
	return

WhiteslateRoute_EventScript_Shuckle_2:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	msgbox WhiteslateRoute_EventScript_Shuckle_Text_1
	closemessage
	giveitem ITEM_BERRY_JUICE
	setflag FLAG_DAILY_SHUCKLE_BERRY_JUICE
	goto WhiteslateRoute_EventScript_Shuckle_1


WhiteslateRoute_Trigger_SecretBase::
	lockall
	speakername WhiteslateRoute_Trigger_SecretBase_Text_0
	msgbox WhiteslateRoute_Trigger_SecretBase_Text_1
	closemessage
	applymovement 7, WhiteslateRoute_Trigger_SecretBase_Movement_0
	waitmovement 7
	delay 24
	playse SE_BALL_OPEN
	applymovement 8, WhiteslateRoute_Trigger_SecretBase_Movement_1
	waitmovement 8
	waitse
	playmoncry SPECIES_GROVYLE, CRY_MODE_NORMAL
	applymovement 8, WhiteslateRoute_Trigger_SecretBase_Movement_2
	waitmovement 8
	setseenmon SPECIES_GROVYLE
	playse SE_M_ROCK_THROW
	applymovement 8, WhiteslateRoute_Trigger_SecretBase_Movement_3
	waitmovement 8
	setmetatile 26, 34, METATILE_PorytilesPrimaryTutorial_CaveEntrance, TRUE
	special DrawWholeMapView
	waitse
	speakername WhiteslateRoute_Trigger_SecretBase_Text_0
	msgbox WhiteslateRoute_Trigger_SecretBase_Text_2
	closemessage
	playmoncry SPECIES_GROVYLE, CRY_MODE_NORMAL
	applymovement 8, WhiteslateRoute_Trigger_SecretBase_Movement_4
	waitmovement 8
	playse SE_BALL_OPEN
	waitmoncry
	waitse
	delay 24
	playse SE_PIN
	applymovement 7, WhiteslateRoute_Trigger_SecretBase_Movement_5
	waitmovement 7
	waitse
	delay 48
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	switch VAR_TEMP_0
	case 25, WhiteslateRoute_Trigger_SecretBase_3
	case 26, WhiteslateRoute_Trigger_SecretBase_4
	case 27, WhiteslateRoute_Trigger_SecretBase_5
WhiteslateRoute_Trigger_SecretBase_1:
	speakername WhiteslateRoute_Trigger_SecretBase_Text_0
	msgbox WhiteslateRoute_Trigger_SecretBase_Text_3
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, WhiteslateRoute_Trigger_SecretBase_Text_4, WhiteslateRoute_Trigger_SecretBase_Text_5, WhiteslateRoute_Trigger_SecretBase_Text_6
	closemessage
	switch VAR_RESULT
	case 0, WhiteslateRoute_Trigger_SecretBase_8
	case 1, WhiteslateRoute_Trigger_SecretBase_9
	case 2, WhiteslateRoute_Trigger_SecretBase_10
WhiteslateRoute_Trigger_SecretBase_6:
	closemessage
	giveitem ITEM_TM_SECRET_POWER
	speakername WhiteslateRoute_Trigger_SecretBase_Text_0
	msgbox WhiteslateRoute_Trigger_SecretBase_Text_10
	closemessage
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	switch VAR_TEMP_0
	case 25, WhiteslateRoute_Trigger_SecretBase_13
	case 26, WhiteslateRoute_Trigger_SecretBase_14
	case 27, WhiteslateRoute_Trigger_SecretBase_15
WhiteslateRoute_Trigger_SecretBase_11:
	playse SE_M_ROCK_THROW
	setmetatile 26, 34, METATILE_PorytilesPrimaryTutorial_SecretBaseCaveEntrance, TRUE
	special DrawWholeMapView
	waitse
	switch VAR_TEMP_0
	case 25, WhiteslateRoute_Trigger_SecretBase_18
	case 26, WhiteslateRoute_Trigger_SecretBase_19
	case 27, WhiteslateRoute_Trigger_SecretBase_20
WhiteslateRoute_Trigger_SecretBase_16:
	removeobject 7
	removeobject 8
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	setflag FLAG_RECEIVED_SECRET_POWER
	releaseall
	return

WhiteslateRoute_Trigger_SecretBase_3:
	applymovement 7, WhiteslateRoute_Trigger_SecretBase_Movement_6
	waitmovement 7
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	goto WhiteslateRoute_Trigger_SecretBase_1

WhiteslateRoute_Trigger_SecretBase_4:
	applymovement 7, WhiteslateRoute_Trigger_SecretBase_Movement_7
	waitmovement 7
	goto WhiteslateRoute_Trigger_SecretBase_1

WhiteslateRoute_Trigger_SecretBase_5:
	applymovement 7, WhiteslateRoute_Trigger_SecretBase_Movement_8
	waitmovement 7
	goto WhiteslateRoute_Trigger_SecretBase_1

WhiteslateRoute_Trigger_SecretBase_8:
	speakername WhiteslateRoute_Trigger_SecretBase_Text_0
	msgbox WhiteslateRoute_Trigger_SecretBase_Text_7
	goto WhiteslateRoute_Trigger_SecretBase_6

WhiteslateRoute_Trigger_SecretBase_9:
	speakername WhiteslateRoute_Trigger_SecretBase_Text_0
	msgbox WhiteslateRoute_Trigger_SecretBase_Text_8
	goto WhiteslateRoute_Trigger_SecretBase_6

WhiteslateRoute_Trigger_SecretBase_10:
	speakername WhiteslateRoute_Trigger_SecretBase_Text_0
	msgbox WhiteslateRoute_Trigger_SecretBase_Text_9
	goto WhiteslateRoute_Trigger_SecretBase_6

WhiteslateRoute_Trigger_SecretBase_13:
	applymovement 7, WhiteslateRoute_Trigger_SecretBase_Movement_9
	waitmovement 7
	goto WhiteslateRoute_Trigger_SecretBase_11

WhiteslateRoute_Trigger_SecretBase_14:
	applymovement 7, WhiteslateRoute_Trigger_SecretBase_Movement_10
	waitmovement 7
	goto WhiteslateRoute_Trigger_SecretBase_11

WhiteslateRoute_Trigger_SecretBase_15:
	applymovement 7, WhiteslateRoute_Trigger_SecretBase_Movement_11
	waitmovement 7
	goto WhiteslateRoute_Trigger_SecretBase_11

WhiteslateRoute_Trigger_SecretBase_18:
	applymovement 7, WhiteslateRoute_Trigger_SecretBase_Movement_12
	waitmovement 7
	goto WhiteslateRoute_Trigger_SecretBase_16

WhiteslateRoute_Trigger_SecretBase_19:
	applymovement 7, WhiteslateRoute_Trigger_SecretBase_Movement_13
	waitmovement 7
	goto WhiteslateRoute_Trigger_SecretBase_16

WhiteslateRoute_Trigger_SecretBase_20:
	applymovement 7, WhiteslateRoute_Trigger_SecretBase_Movement_12
	waitmovement 7
	goto WhiteslateRoute_Trigger_SecretBase_16


WhiteslateRoute_Trigger_ShamisenPlayerTop_Movement_0:
	walk_in_place_fast_up
	delay_16
	delay_16
	step_end

WhiteslateRoute_Trigger_ShamisenPlayerBottom_Movement_0:
	walk_in_place_fast_up
	delay_16
	delay_16
	walk_up
	step_end

WhiteslateRoute_EventScript_ShamisenCallsOut_Movement_0:
	lock_facing_direction
	walk_in_place_fast_down
	unlock_facing_direction
	step_end

WhiteslateRoute_EventScript_ShamisenPlayer_Movement_0:
	walk_in_place_down
	step_end

WhiteslateRoute_EventScript_ShamisenPlayerChoice_Movement_0:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

WhiteslateRoute_EventScript_ShamisenPlayerChoice_Movement_1:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

WhiteslateRoute_EventScript_ShamisenPlayerChoice_Movement_2:
	walk_in_place_fast_left
	step_end

WhiteslateRoute_EventScript_ShamisenPlayerChoice_Movement_3:
	walk_right
	step_end

WhiteslateRoute_Trigger_SecretBase_Movement_0:
	walk_right
	face_left
	step_end

WhiteslateRoute_Trigger_SecretBase_Movement_1:
	exit_pokeball
	face_up
	step_end

WhiteslateRoute_Trigger_SecretBase_Movement_2:
	jump_in_place_up
	delay_16
	delay_16
	step_end

WhiteslateRoute_Trigger_SecretBase_Movement_3:
	lock_anim
	lock_facing_direction
	walk_faster_up
	walk_faster_down
	unlock_anim
	unlock_facing_direction
	step_end

WhiteslateRoute_Trigger_SecretBase_Movement_4:
	jump_in_place_right
	delay_16
	delay_16
	enter_pokeball
	step_end

WhiteslateRoute_Trigger_SecretBase_Movement_5:
	face_down
	emote_exclamation_mark
	step_end

WhiteslateRoute_Trigger_SecretBase_Movement_6:
	walk_down
	walk_down
	walk_down
	walk_left
	step_end

WhiteslateRoute_Trigger_SecretBase_Movement_7:
	walk_down
	walk_down
	walk_left
	face_down
	step_end

WhiteslateRoute_Trigger_SecretBase_Movement_8:
	walk_down
	walk_down
	step_end

WhiteslateRoute_Trigger_SecretBase_Movement_9:
	walk_up
	walk_up
	walk_up
	step_end

WhiteslateRoute_Trigger_SecretBase_Movement_10:
	walk_up
	walk_up
	step_end

WhiteslateRoute_Trigger_SecretBase_Movement_11:
	walk_left
	walk_up
	walk_up
	step_end

WhiteslateRoute_Trigger_SecretBase_Movement_12:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

WhiteslateRoute_Trigger_SecretBase_Movement_13:
	walk_down
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

WhiteslateRoute_EventScript_ShamisenChallengeAreYouReady_Text_0:
	.string "Shamisen Player$"

WhiteslateRoute_EventScript_ShamisenChallengeAreYouReady_Text_1:
	.string "So, are you ready?$"

WhiteslateRoute_EventScript_ShamisenChallenge_Text_0:
	.string "I am a traveling blind musician.\n"
	.string "I was arrested by the aura of a brave\l"
	.string "and promising young Wielder…\l"
	.string "Are you them? Why, you must be!\l"
	.string "There's no other explanation!\p"
	.string "We Shamisen Players sing songs about\n"
	.string "the brave souls we meet on our\l"
	.string "travels.\p"
	.string "To test your worth, how about I\n"
	.string "submit you to a little challenge?\p"
	.string "If you manage to reach the next\n"
	.string "city's Refuge in one go, without\l"
	.string "running back to the previous towns', I\l"
	.string "will meet you there and give you a\l"
	.string "little something.\p"
	.string "I know we only just met, but I believe\n"
	.string "you will succeed!\p"
	.string "I can let you prepare before\n"
	.string "considering this challenge as having\l"
	.string "begun, if you wish.$"

WhiteslateRoute_EventScript_ShamisenCallsOut_Text_0:
	.string "… … …!\p"
	.string "Excuse me! Yes, you!$"

WhiteslateRoute_EventScript_ShamisenPlayerChoice_Text_0:
	.string "I'm ready!$"

WhiteslateRoute_EventScript_ShamisenPlayerChoice_Text_1:
	.string "I need to prepare first.$"

WhiteslateRoute_EventScript_ShamisenPlayerChoice_Text_2:
	.string "Go forth, bold young soul! May luck\n"
	.string "echo your steps!$"

WhiteslateRoute_EventScript_ShamisenPlayerChoice_Text_3:
	.string "Understood. Come back when you are\n"
	.string "ready.$"

WhiteslateRoute_EventScript_ShamisenPlayerPokemon_Text_0:
	.string "Arf!$"

WhiteslateRoute_EventScript_Itsumi_Text_0:
	.string "Do you nurture your Pokémon with\n"
	.string "love?$"

WhiteslateRoute_EventScript_Itsumi_Text_1:
	.string "Oh, you do!$"

WhiteslateRoute_EventScript_Itsumi_Text_2:
	.string "Itsumi$"

WhiteslateRoute_EventScript_Itsumi_Text_3:
	.string "I am glad we met! Your Pokémon seem\n"
	.string "so happy.$"

WhiteslateRoute_EventScript_Ryosuke_Text_0:
	.string "I massage my Pokémon after each\n"
	.string "battle!$"

WhiteslateRoute_EventScript_Ryosuke_Text_1:
	.string "Can somebody give me a massage?$"

WhiteslateRoute_EventScript_Ryosuke_Text_2:
	.string "Ryosuke$"

WhiteslateRoute_EventScript_Ryosuke_Text_3:
	.string "I heard there was a very talented\n"
	.string "masseur in Saberside Town.\p"
	.string "I want to see for myself!$"

WhiteslateRoute_EventScript_Riku_Text_0:
	.string "BOO!!\p"
	.string "… … …Are you surprised?$"

WhiteslateRoute_EventScript_Riku_Text_1:
	.string "My loyal Pokémon!$"

WhiteslateRoute_EventScript_Riku_Text_2:
	.string "Riku$"

WhiteslateRoute_EventScript_Riku_Text_3:
	.string "I have to work on my element of\n"
	.string "surprise.$"

WhiteslateRoute_EventScript_Tomomi_Text_0:
	.string "Attack, my loyal servants!$"

WhiteslateRoute_EventScript_Tomomi_Text_1:
	.string "Retreat! Retreat!$"

WhiteslateRoute_EventScript_Tomomi_Text_2:
	.string "Tomomi$"

WhiteslateRoute_EventScript_Tomomi_Text_3:
	.string "Deer Pokémon are my very favorite.\n"
	.string "Such strength! Such elegance!$"

WhiteslateRoute_EventScript_Yono_Text_0:
	.string "Huff… Puff… I walk several hours\n"
	.string "everyday!$"

WhiteslateRoute_EventScript_Yono_Text_1:
	.string "Let an old woman catch her breath!…$"

WhiteslateRoute_EventScript_Yono_Text_2:
	.string "Yono$"

WhiteslateRoute_EventScript_Yono_Text_3:
	.string "Walking is good for the joints. It\n"
	.string "keeps me young!$"

WhiteslateRoute_EventScript_Sumi_Text_0:
	.string "Excuse me… What's with that white\n"
	.string "hand on your shoulder?$"

WhiteslateRoute_EventScript_Sumi_Text_1:
	.string "Heeeeeee!$"

WhiteslateRoute_EventScript_Sumi_Text_2:
	.string "Sumi$"

WhiteslateRoute_EventScript_Sumi_Text_3:
	.string "You don't scare easily, do you?$"

WhiteslateRoute_EventScript_Tomiko_Text_0:
	.string "Weird Pokémon are my favorite!$"

WhiteslateRoute_EventScript_Tomiko_Text_1:
	.string "I don't care if they're not the\n"
	.string "strongest!$"

WhiteslateRoute_EventScript_Tomiko_Text_2:
	.string "Tomiko$"

WhiteslateRoute_EventScript_Tomiko_Text_3:
	.string "I love Spinda. Doesn't it look silly\n"
	.string "and adorable?$"

WhiteslateRoute_EventScript_Utaro_Text_0:
	.string "I love cool Pokémon!$"

WhiteslateRoute_EventScript_Utaro_Text_1:
	.string "At least I lost with style!$"

WhiteslateRoute_EventScript_Utaro_Text_2:
	.string "Utaro$"

WhiteslateRoute_EventScript_Utaro_Text_3:
	.string "Seviper is so darn cool! I mean, it's\n"
	.string "got a sword on its tail!$"

WhiteslateRoute_EventScript_ShuckleGirl_Text_0:
	.string "Woman$"

WhiteslateRoute_EventScript_ShuckleGirl_Text_1:
	.string "This Shuckle lives around here. I feed\n"
	.string "him fresh berries every morning!$"

WhiteslateRoute_EventScript_Deerling_Text_0:
	.string "Uhnn!$"

WhiteslateRoute_EventScript_Shuckle_Text_0:
	.string "Cklckl!$"

WhiteslateRoute_EventScript_Shuckle_Text_1:
	.string "…Oh? The Pokémon is giving you\n"
	.string "something.$"

WhiteslateRoute_Trigger_SecretBase_Text_0:
	.string "Man$"

WhiteslateRoute_Trigger_SecretBase_Text_1:
	.string "Hehe… Looks like the perfect spot!$"

WhiteslateRoute_Trigger_SecretBase_Text_2:
	.string "Good job, Grovyle!$"

WhiteslateRoute_Trigger_SecretBase_Text_3:
	.string "Oh, man! You were here this whole\n"
	.string "time? My secret base is no longer\l"
	.string "secret!$"

WhiteslateRoute_Trigger_SecretBase_Text_4:
	.string "What were you doing?$"

WhiteslateRoute_Trigger_SecretBase_Text_5:
	.string "Sorry for interrupting!$"

WhiteslateRoute_Trigger_SecretBase_Text_6:
	.string "Are you a criminal?$"

WhiteslateRoute_Trigger_SecretBase_Text_7:
	.string "Alright, you seem interested, so I'll\n"
	.string "let you in on the secret!\p"
	.string "I taught my Grovyle a secret\n"
	.string "technique to open passages to hidden\l"
	.string "natural caves!\p"
	.string "Not only that! Trees with low-hanging\n"
	.string "vines, bushes… Those kinds of places\l"
	.string "are perfect to build a secret base!\p"
	.string "I wrote this technique down just in\n"
	.string "case. Here, now you can teach your\l"
	.string "Pokémon too!$"

WhiteslateRoute_Trigger_SecretBase_Text_8:
	.string "Ah, it's alright. You look like you're a\n"
	.string "good kid. I'm sure you have what it\l"
	.string "takes to become a secret base\l"
	.string "master. I'll let you in on the secret!\p"
	.string "I taught my Grovyle a secret\n"
	.string "technique to open passages to hidden\l"
	.string "natural caves!\p"
	.string "Not only that! Trees with low-hanging\n"
	.string "vines, bushes… That kind of place is\l"
	.string "perfect to build a secret base!\p"
	.string "I wrote this technique down just in\n"
	.string "case. Here, now you can teach your\l"
	.string "Pokémon too!$"

WhiteslateRoute_Trigger_SecretBase_Text_9:
	.string "Of course not, this is perfectly\n"
	.string "legal! You know what? I'll let you in\l"
	.string "on the secret!\p"
	.string "I taught my Grovyle a secret\n"
	.string "technique to open passages to hidden\l"
	.string "natural caves!\p"
	.string "Not only that! Trees with low-hanging\n"
	.string "vines, bushes… That kind of place is\l"
	.string "perfect to build a secret base!\p"
	.string "I wrote this technique down just in\n"
	.string "case. Here, now you can teach your\l"
	.string "Pokémon too!$"

WhiteslateRoute_Trigger_SecretBase_Text_10:
	.string "I'll keep looking for the perfect\n"
	.string "secret base spot! Maybe I'll see you\l"
	.string "around!$"

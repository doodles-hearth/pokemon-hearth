WhiteslateRoute_MapScripts::
	.byte 0


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


WhiteslateRoute_EventScript_Shuckle::
	lock
	faceplayer
	waitse
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
	.string "BOO!!\n"
	.string "… … …Are you surprised?$"

WhiteslateRoute_EventScript_Riku_Text_1:
	.string "My loyal Pokémon!$"

WhiteslateRoute_EventScript_Riku_Text_2:
	.string "Riku$"

WhiteslateRoute_EventScript_Riku_Text_3:
	.string "I have to work on my element of\n"
	.string "surprise.$"

WhiteslateRoute_EventScript_Shuckle_Text_0:
	.string "Cklckl!$"

WhiteslateRoute_EventScript_Shuckle_Text_1:
	.string "…Oh? Shuckle is giving you something.$"

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

BeachboundRoute_MapScripts::
	.byte 0


BeachboundRoute_EventScript_RunningBoy::
	speakername BeachboundRoute_EventScript_RunningBoy_Text_0
	msgbox BeachboundRoute_EventScript_RunningBoy_Text_1, MSGBOX_NPC
	return


BeachboundRoute_EventScript_RunningGirl::
	speakername BeachboundRoute_EventScript_RunningGirl_Text_0
	msgbox BeachboundRoute_EventScript_RunningGirl_Text_1, MSGBOX_NPC
	return


BeachboundRoute_EventScript_AnnoyedGirl::
	gettimeofday
	speakername BeachboundRoute_EventScript_AnnoyedGirl_Text_0
	compare VAR_RESULT, TIME_EVENING
	goto_if_eq BeachboundRoute_EventScript_AnnoyedGirl_1
	msgbox BeachboundRoute_EventScript_AnnoyedGirl_Text_2, MSGBOX_NPC
	return

BeachboundRoute_EventScript_AnnoyedGirl_1:
	msgbox BeachboundRoute_EventScript_AnnoyedGirl_Text_1, MSGBOX_NPC
	return


BeachboundRoute_EventScript_AnnoyedBoy::
	speakername BeachboundRoute_EventScript_AnnoyedBoy_Text_0
	msgbox BeachboundRoute_EventScript_AnnoyedBoy_Text_1, MSGBOX_NPC
	return


BeachboundRoute_EventScript_Hoppip::
	lock
	faceplayer
	setspeakertomonname SPECIES_HOPPIP
	msgbox BeachboundRoute_EventScript_Hoppip_Text_0
	playmoncry SPECIES_HOPPIP, CRY_MODE_NORMAL
	waitmoncry
	release
	end


BeachboundRoute_EventScript_Wooloo::
	lock
	faceplayer
	setspeakertomonname SPECIES_WOOLOO
	msgbox BeachboundRoute_EventScript_Wooloo_Text_0
	playmoncry SPECIES_WOOLOO, CRY_MODE_NORMAL
	waitmoncry
	release
	end


BeachboundRoute_EventScript_Shepherd::
	speakername BeachboundRoute_EventScript_Shepherd_Text_0
	msgbox BeachboundRoute_EventScript_Shepherd_Text_1, MSGBOX_NPC
	return


BeachboundRoute_EventScript_Karu::
	trainerbattle_single TRAINER_KARU, BeachboundRoute_EventScript_Karu_Text_0, BeachboundRoute_EventScript_Karu_Text_1, BeachboundRoute_EventScript_Karu_PostBattle
	speakername BeachboundRoute_EventScript_Karu_Text_2
	msgbox BeachboundRoute_EventScript_Karu_Text_3, MSGBOX_AUTOCLOSE
	end


BeachboundRoute_EventScript_Karu_PostBattle::
	setflag FLAG_TEMP_5
	removeobject 10
	return


BeachboundRoute_EventScript_Kin::
	trainerbattle_single TRAINER_KIN_1, BeachboundRoute_EventScript_Kin_Text_0, BeachboundRoute_EventScript_Kin_Text_1
	speakername BeachboundRoute_EventScript_Kin_Text_2
	msgbox BeachboundRoute_EventScript_Kin_Text_3, MSGBOX_AUTOCLOSE
	end


BeachboundRoute_EventScript_Scrub2::
	trainerbattle_single TRAINER_SCRUB_2, BeachboundRoute_EventScript_Scrub2_Text_0, BeachboundRoute_EventScript_Scrub2_Text_1
	speakername BeachboundRoute_EventScript_Scrub2_Text_2
	msgbox BeachboundRoute_EventScript_Scrub2_Text_3
	release
	end


BeachboundRoute_EventScript_SomeoneCallingForHelp::
	lock
	speakername BeachboundRoute_EventScript_SomeoneCallingForHelp_Text_0
	msgbox BeachboundRoute_EventScript_SomeoneCallingForHelp_Text_1
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	waitse
	delay 48
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	setvar VAR_CROBAT_SHADOWS_FIRST_ENCOUNTERS_STATE, 2
	release
	return


BeachboundRoute_EventScript_WhereAreYouGoing::
	lock
	speakername BeachboundRoute_EventScript_SomeoneCallingForHelp_Text_0
	msgbox BeachboundRoute_EventScript_WhereAreYouGoing_Text_0
	specialvar VAR_RESULT, GetPlayerFacingDirection
	switch VAR_RESULT
	case DIR_EAST, BeachboundRoute_EventScript_WhereAreYouGoing_3
	case DIR_WEST, BeachboundRoute_EventScript_WhereAreYouGoing_4
	case DIR_SOUTH, BeachboundRoute_EventScript_WhereAreYouGoing_5
BeachboundRoute_EventScript_WhereAreYouGoing_1:
	waitmovement 0
	release
	return

BeachboundRoute_EventScript_WhereAreYouGoing_3:
	applymovement OBJ_EVENT_ID_PLAYER, BeachboundRoute_EventScript_WhereAreYouGoing_Movement_0
	goto BeachboundRoute_EventScript_WhereAreYouGoing_1

BeachboundRoute_EventScript_WhereAreYouGoing_4:
	applymovement OBJ_EVENT_ID_PLAYER, BeachboundRoute_EventScript_WhereAreYouGoing_Movement_1
	goto BeachboundRoute_EventScript_WhereAreYouGoing_1

BeachboundRoute_EventScript_WhereAreYouGoing_5:
	applymovement OBJ_EVENT_ID_PLAYER, BeachboundRoute_EventScript_WhereAreYouGoing_Movement_2
	goto BeachboundRoute_EventScript_WhereAreYouGoing_1


BeachboundRoute_EventScript_Mugging_Left::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, BeachboundRoute_EventScript_WhereAreYouGoing_Movement_1
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	call BeachboundRoute_EventScript_Mugging
	release
	return


BeachboundRoute_EventScript_Mugging_Right::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, BeachboundRoute_EventScript_WhereAreYouGoing_Movement_0
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	call BeachboundRoute_EventScript_Mugging
	release
	return


BeachboundRoute_EventScript_Mugging_Center::
	lock
	call BeachboundRoute_EventScript_Mugging
	release
	return


BeachboundRoute_EventScript_Mugging::
	compare VAR_CROBAT_SHADOWS_FIRST_ENCOUNTERS_STATE, 3
	goto_if_lt BeachboundRoute_EventScript_Mugging_2
	turnobject 24, DIR_SOUTH
	speakername BeachboundRoute_EventScript_Mugging_Text_14
	msgbox BeachboundRoute_EventScript_Mugging_Text_16
BeachboundRoute_EventScript_Mugging_1:
	applymovement 24, BeachboundRoute_EventScript_Mugging_Movement_0
	applymovement 23, BeachboundRoute_EventScript_Mugging_Movement_1
	applymovement 26, BeachboundRoute_EventScript_Mugging_Movement_1
	waitmovement 24
	waitmovement 23
	waitmovement 26
	trainerbattle_two_trainers TRAINER_GRUNT_BEACHBOUND_ROUTE_1, BeachboundRoute_EventScript_Mugging_Text_17, TRAINER_GRUNT_BEACHBOUND_ROUTE_2, BeachboundRoute_EventScript_Mugging_Text_18
	setvar VAR_CROBAT_SHADOWS_FIRST_ENCOUNTERS_STATE, 4
	applymovement 23, Common_Movement_WalkInPlaceFasterRight
	waitmovement 23
	speakername BeachboundRoute_EventScript_Mugging_Text_19
	msgbox BeachboundRoute_EventScript_Mugging_Text_20
	closemessage
	applymovement 26, Common_Movement_WalkInPlaceFasterRight
	waitmovement 26
	speakername BeachboundRoute_EventScript_Mugging_Text_19
	msgbox BeachboundRoute_EventScript_Mugging_Text_21
	closemessage
	delay 24
	speakername BeachboundRoute_EventScript_Mugging_Text_14
	msgbox BeachboundRoute_EventScript_Mugging_Text_22
	closemessage
	applymovement 25, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	speakername BeachboundRoute_EventScript_Mugging_Text_10
	msgbox BeachboundRoute_EventScript_Mugging_Text_23
	closemessage
	delay 24
	applymovement 24, BeachboundRoute_EventScript_Mugging_Movement_2
	waitmovement 0
	speakername BeachboundRoute_EventScript_Mugging_Text_14
	msgbox BeachboundRoute_EventScript_Mugging_Text_24
	closemessage
	delay 48
	applymovement 24, BeachboundRoute_EventScript_Mugging_Movement_3
	waitmovement 0
	speakername BeachboundRoute_EventScript_Mugging_Text_14
	msgbox BeachboundRoute_EventScript_Mugging_Text_25
	closemessage
	turnobject 24, DIR_NORTH
	speakername BeachboundRoute_EventScript_Mugging_Text_14
	msgbox BeachboundRoute_EventScript_Mugging_Text_26
	closemessage
	applymovement 23, BeachboundRoute_EventScript_Mugging_Movement_4
	applymovement 26, BeachboundRoute_EventScript_Mugging_Movement_4
	waitmovement 23
	waitmovement 26
	applymovement 23, BeachboundRoute_EventScript_Mugging_Movement_5
	applymovement 26, BeachboundRoute_EventScript_Mugging_Movement_5
	applymovement 25, BeachboundRoute_EventScript_Mugging_Movement_5
	waitmovement 23
	waitmovement 26
	waitmovement 25
	applymovement 24, BeachboundRoute_EventScript_Mugging_Movement_6
	applymovement 23, BeachboundRoute_EventScript_Mugging_Movement_7
	applymovement 26, BeachboundRoute_EventScript_Mugging_Movement_8
	applymovement 25, BeachboundRoute_EventScript_Mugging_Movement_9
	waitmovement 24
	waitmovement 23
	waitmovement 26
	waitmovement 25
	removeobject 24
	removeobject 23
	removeobject 26
	removeobject 25
	setflag FLAG_HIDE_CROBAT_SHADOWS_BEACHBOUND_RT
	delay 60
	applymovement 22, BeachboundRoute_EventScript_Mugging_Movement_10
	waitmovement 22
	speakername BeachboundRoute_EventScript_Mugging_Text_27
	msgbox BeachboundRoute_EventScript_Mugging_Text_28
	closemessage
	giveitem ITEM_WHITE_HERB
	speakername BeachboundRoute_EventScript_Mugging_Text_27
	msgbox BeachboundRoute_EventScript_Mugging_Text_29
	closemessage
	addvar VAR_PLAYER_REPUTATION, 1
	applymovement 22, BeachboundRoute_EventScript_Mugging_Movement_11
	waitmovement 22
	waitmovement 0
	return

BeachboundRoute_EventScript_Mugging_2:
	setvar VAR_CROBAT_SHADOWS_FIRST_ENCOUNTERS_STATE, 3
	applymovement 23, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	speakername BeachboundRoute_EventScript_Mugging_Text_0
	msgbox BeachboundRoute_EventScript_Mugging_Text_1
	closemessage
	applymovement 26, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	speakername BeachboundRoute_EventScript_Mugging_Text_0
	msgbox BeachboundRoute_EventScript_Mugging_Text_2
	closemessage
	delay 40
	turnobject 24, DIR_SOUTH
	playse SE_PIN
	applymovement 24, Common_Movement_ExclamationMark
	waitmovement 0
	waitse
	delay 48
	speakername BeachboundRoute_EventScript_Mugging_Text_0
	msgbox BeachboundRoute_EventScript_Mugging_Text_3
	applymovement 23, Common_Movement_FaceDown
	applymovement 26, Common_Movement_FaceDown
	applymovement 25, Common_Movement_FaceDown
	waitmovement 23
	waitmovement 26
	waitmovement 25
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, BeachboundRoute_EventScript_Mugging_Text_4, BeachboundRoute_EventScript_Mugging_Text_5, BeachboundRoute_EventScript_Mugging_Text_6
	closemessage
	speakername BeachboundRoute_EventScript_Mugging_Text_0
	switch VAR_RESULT
	case 0, BeachboundRoute_EventScript_Mugging_7
	case 1, BeachboundRoute_EventScript_Mugging_8
	case 2, BeachboundRoute_EventScript_Mugging_9
BeachboundRoute_EventScript_Mugging_5:
	closemessage
	applymovement 25, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	speakername BeachboundRoute_EventScript_Mugging_Text_10
	msgbox BeachboundRoute_EventScript_Mugging_Text_11
	closemessage
	turnobject 24, DIR_NORTH
	delay 40
	speakername BeachboundRoute_EventScript_Mugging_Text_12
	msgbox BeachboundRoute_EventScript_Mugging_Text_13
	closemessage
	turnobject 24, DIR_SOUTH
	delay 24
	speakername BeachboundRoute_EventScript_Mugging_Text_14
	msgbox BeachboundRoute_EventScript_Mugging_Text_15
	closemessage
	goto BeachboundRoute_EventScript_Mugging_1

BeachboundRoute_EventScript_Mugging_7:
	msgbox BeachboundRoute_EventScript_Mugging_Text_7
	goto BeachboundRoute_EventScript_Mugging_5

BeachboundRoute_EventScript_Mugging_8:
	msgbox BeachboundRoute_EventScript_Mugging_Text_8
	goto BeachboundRoute_EventScript_Mugging_5

BeachboundRoute_EventScript_Mugging_9:
	msgbox BeachboundRoute_EventScript_Mugging_Text_9
	goto BeachboundRoute_EventScript_Mugging_5


BeachboundRoute_EventScript_SeeDecay::
	lockall
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitse
	waitmovement 0
	setflag FLAG_SPAWN_INVISIBLE
	warpsilent MAP_BEACHBOUND_ROUTE_DECAY, 43, 17
	releaseall
	return


BeachboundRoute_EventScript_WhereAreYouGoing_Movement_0:
	walk_left
	step_end

BeachboundRoute_EventScript_WhereAreYouGoing_Movement_1:
	walk_right
	step_end

BeachboundRoute_EventScript_WhereAreYouGoing_Movement_2:
	walk_up
	step_end

BeachboundRoute_EventScript_Mugging_Movement_0:
	walk_right
	face_left
	step_end

BeachboundRoute_EventScript_Mugging_Movement_1:
	walk_down
	step_end

BeachboundRoute_EventScript_Mugging_Movement_2:
	face_up
	step_end

BeachboundRoute_EventScript_Mugging_Movement_3:
	face_right
	step_end

BeachboundRoute_EventScript_Mugging_Movement_4:
	walk_up
	face_down
	step_end

BeachboundRoute_EventScript_Mugging_Movement_5:
	face_down
	zubats_align
	delay_16
	delay_16
	step_end

BeachboundRoute_EventScript_Mugging_Movement_6:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

BeachboundRoute_EventScript_Mugging_Movement_7:
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

BeachboundRoute_EventScript_Mugging_Movement_8:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

BeachboundRoute_EventScript_Mugging_Movement_9:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

BeachboundRoute_EventScript_Mugging_Movement_10:
	walk_down
	walk_down
	step_end

BeachboundRoute_EventScript_Mugging_Movement_11:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

BeachboundRoute_EventScript_RunningBoy_Text_0:
	.string "Little boy$"

BeachboundRoute_EventScript_RunningBoy_Text_1:
	.string "Running running running!!\p"
	.string "Yaaaaaaaay!!!$"

BeachboundRoute_EventScript_RunningGirl_Text_0:
	.string "Little girl$"

BeachboundRoute_EventScript_RunningGirl_Text_1:
	.string "Wait for me!! It's not fair!!!$"

BeachboundRoute_EventScript_AnnoyedGirl_Text_0:
	.string "Annoyed girl$"

BeachboundRoute_EventScript_AnnoyedGirl_Text_1:
	.string "Hum… Could you maybe, like, leave?$"

BeachboundRoute_EventScript_AnnoyedGirl_Text_2:
	.string "I wish those kids would leave…$"

BeachboundRoute_EventScript_AnnoyedBoy_Text_0:
	.string "Annoyed boy$"

BeachboundRoute_EventScript_AnnoyedBoy_Text_1:
	.string "I brought my date to the Lover's\n"
	.string "Meadow, but I kind of thought we'd be\l"
	.string "alone…$"

BeachboundRoute_EventScript_Hoppip_Text_0:
	.string "Pip!$"

BeachboundRoute_EventScript_Wooloo_Text_0:
	.string "Bah…$"

BeachboundRoute_EventScript_Shepherd_Text_0:
	.string "Shepherd$"

BeachboundRoute_EventScript_Shepherd_Text_1:
	.string "I bring my Wooloo here to graze\n"
	.string "everyday.$"

BeachboundRoute_EventScript_Karu_Text_0:
	.string "Please allow me to introduce you to\n"
	.string "your own defeat!$"

BeachboundRoute_EventScript_Karu_Text_1:
	.string "N-nice to meet you…$"

BeachboundRoute_EventScript_Karu_Text_2:
	.string "Karu$"

BeachboundRoute_EventScript_Karu_Text_3:
	.string "You wiped me away there. How long\n"
	.string "have you been a wielder?$"

BeachboundRoute_EventScript_Kin_Text_0:
	.string "I run several hours everyday! You\n"
	.string "literally cannot defeat me!$"

BeachboundRoute_EventScript_Kin_Text_1:
	.string "Ow! I pulled a muscle!$"

BeachboundRoute_EventScript_Kin_Text_2:
	.string "Kin$"

BeachboundRoute_EventScript_Kin_Text_3:
	.string "You really don't look strong at all,\n"
	.string "and yet…$"

BeachboundRoute_EventScript_Scrub2_Text_0:
	.string "I am a scrub youngster whose sole\n"
	.string "purpose is to get stomped!$"

BeachboundRoute_EventScript_Scrub2_Text_1:
	.string "I got stomped!$"

BeachboundRoute_EventScript_Scrub2_Text_2:
	.string "Scrub2$"

BeachboundRoute_EventScript_Scrub2_Text_3:
	.string "If you lost to me you should\n"
	.string "uninstall!$"

BeachboundRoute_EventScript_SomeoneCallingForHelp_Text_0:
	.string "???$"

BeachboundRoute_EventScript_SomeoneCallingForHelp_Text_1:
	.string "Help! Someone help me!$"

BeachboundRoute_EventScript_WhereAreYouGoing_Text_0:
	.string "Hey, you! In the red and blue clothes!\p"
	.string "Are you… Are you leaving?!\p"
	.string "Can't you be a decent human being and\n"
	.string "help me out?$"

BeachboundRoute_EventScript_Mugging_Text_0:
	.string "Shady Man$"

BeachboundRoute_EventScript_Mugging_Text_1:
	.string "Stop yappin', lady! Just give us yer\n"
	.string "Pokémon already!$"

BeachboundRoute_EventScript_Mugging_Text_2:
	.string "C'mon, don't make this difficult! Just\n"
	.string "hand it over!$"

BeachboundRoute_EventScript_Mugging_Text_3:
	.string "Just what d'you think yer doin'?\p"
	.string "Can't ya see we're in the middle of\n"
	.string "something 'ere?$"

BeachboundRoute_EventScript_Mugging_Text_4:
	.string "Leave her alone!$"

BeachboundRoute_EventScript_Mugging_Text_5:
	.string "Actually, I was just leaving!$"

BeachboundRoute_EventScript_Mugging_Text_6:
	.string "Uh…$"

BeachboundRoute_EventScript_Mugging_Text_7:
	.string "Ooh, feelin' heroic today, are we?\p"
	.string "D'ya know what we do to nosy brats\n"
	.string "who're not clever enough to mind their\l"
	.string "own business?\p"
	.string "Ya have no self-preservation\n"
	.string "instinct whatsoever, do ya?\p"
	.string "D'ya even know who we are?\p"
	.string "We're the world-famous Crobat\n"
	.string "Shadows!\p"
	.string "Thievin', muggin', wreakin' havoc… Ya\n"
	.string "name it!\p"
	.string "We're basically the allegory of crime!$"

BeachboundRoute_EventScript_Mugging_Text_8:
	.string "'S a little too late fer that, don't ya\n"
	.string "think? D'ya know what we do to nosy\l"
	.string "brats who're not clever enough to\l"
	.string "mind their own business?\p"
	.string "Ya have no self-preservation\n"
	.string "instinct whatsoever, do ya?\p"
	.string "D'ya even know who we are?\p"
	.string "We're the world-famous Crobat\n"
	.string "Shadows!\p"
	.string "Thievin', muggin', wreakin' havoc… Ya\n"
	.string "name it!\p"
	.string "We're basically the allegory of crime!$"

BeachboundRoute_EventScript_Mugging_Text_9:
	.string "Got nothin' to say, huh?\p"
	.string "D'ya know what we do to nosy brats\n"
	.string "who're not clever enough to mind their\l"
	.string "own business?\p"
	.string "Ya have no self-preservation\n"
	.string "instinct whatsoever, do ya?\p"
	.string "D'ya even know who we are?\p"
	.string "We're the world-famous Crobat\n"
	.string "Shadows!\p"
	.string "Thievin', muggin', wreakin' havoc… Ya\n"
	.string "name it!\p"
	.string "We're basically the allegory of crime!$"

BeachboundRoute_EventScript_Mugging_Text_10:
	.string "Crobat Shadow$"

BeachboundRoute_EventScript_Mugging_Text_11:
	.string "Uh… What's an allergory, boss?$"

BeachboundRoute_EventScript_Mugging_Text_12:
	.string "Crobat boss$"

BeachboundRoute_EventScript_Mugging_Text_13:
	.string "…Gonna pretend ya didn't say that.$"

BeachboundRoute_EventScript_Mugging_Text_14:
	.string "Crobat Boss$"

BeachboundRoute_EventScript_Mugging_Text_15:
	.string "'Nuff yappin' already! Take care of\n"
	.string "this clown, boys!$"

BeachboundRoute_EventScript_Mugging_Text_16:
	.string "Can't believe it! Look who's back!\p"
	.string "Back fer another whoopin', are we?\p"
	.string "Take care of this clown, boys!$"

BeachboundRoute_EventScript_Mugging_Text_17:
	.string "Aw, man!$"

BeachboundRoute_EventScript_Mugging_Text_18:
	.string "Mama!$"

BeachboundRoute_EventScript_Mugging_Text_19:
	.string "Zubat Grunt$"

BeachboundRoute_EventScript_Mugging_Text_20:
	.string "Sorry, boss!$"

BeachboundRoute_EventScript_Mugging_Text_21:
	.string "We got stomped proper, boss!$"

BeachboundRoute_EventScript_Mugging_Text_22:
	.string "Ya gotta be kiddin' me…\p"
	.string "Can't even do no regular muggin' in\n"
	.string "peace anymore!\p"
	.string "Well, I ain't gonna stoop to fighting\n"
	.string "ya myself!$"

BeachboundRoute_EventScript_Mugging_Text_23:
	.string "Boss, what's a stoop?$"

BeachboundRoute_EventScript_Mugging_Text_24:
	.string "For the love of god, Kevin…$"

BeachboundRoute_EventScript_Mugging_Text_25:
	.string "Movin' on! You've not seen the last of\n"
	.string "us, ya annoying brat!\p"
	.string "Ya better steer clear of the Crobat\n"
	.string "Shadows from now on!\p"
	.string "Let's move it, boys!$"

BeachboundRoute_EventScript_Mugging_Text_26:
	.string "ZUBATS, ALIGN!!$"

BeachboundRoute_EventScript_Mugging_Text_27:
	.string "Woman$"

BeachboundRoute_EventScript_Mugging_Text_28:
	.string "Thank you so much for helping me!\p"
	.string "Those ruffians were about to steal my\n"
	.string "Pokémon!\p"
	.string "I don't have much to offer you as a\n"
	.string "thanks, but please take this!$"

BeachboundRoute_EventScript_Mugging_Text_29:
	.string "What's your name?\n"
	.string "{PLAYER}?\p"
	.string "I'll be sure to tell everyone what a\n"
	.string "hero you are!$"

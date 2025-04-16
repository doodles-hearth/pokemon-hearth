MaguroHarbor_Dojo_MapScripts::
	.byte 0


MaguroHarbor_Dojo_EventScript_Koishi::
	speakername MaguroHarbor_Dojo_EventScript_Koishi_Text_0
	trainerbattle_single TRAINER_KOISHI_1, MaguroHarbor_Dojo_EventScript_Koishi_Text_1, MaguroHarbor_Dojo_EventScript_Koishi_Text_2, MaguroHarbor_Dojo_EventScript_KoishiDefeated, NO_MUSIC
	msgbox MaguroHarbor_Dojo_EventScript_Koishi_Text_3
	end


MaguroHarbor_Dojo_EventScript_KoishiDefeated::
	message MaguroHarbor_Dojo_EventScript_KoishiDefeated_Text_0
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	speakername MaguroHarbor_Dojo_EventScript_Koishi_Text_0
	msgbox MaguroHarbor_Dojo_EventScript_KoishiDefeated_Text_1, MSGBOX_DEFAULT
	giveitem ITEM_TM_NATURE_POWER
	speakername MaguroHarbor_Dojo_EventScript_Koishi_Text_0
	msgbox MaguroHarbor_Dojo_EventScript_KoishiDefeated_Text_2, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_BADGE01_GET
	setvar VAR_0x8008, 1
	call Common_EventScript_SetGymTrainers
	addvar VAR_PLAYER_REPUTATION, 5
	setvar VAR_DECAY_BEACHBOUND_ROUTE, 1
	setflag FLAG_KURA_DOJO_CLOSED
	clearflag FLAG_HIDE_BONSAI_SHOP_OWNER
	delay 48
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 40
	setvar VAR_0x8007, 4
	special ShakeCamera
	delay 16
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	delay 16
	playse SE_PIN
	applymovement 4, Common_Movement_ExclamationMark
	waitstate
	waitmovement OBJ_EVENT_ID_PLAYER
	waitmovement 4
	delay 60
	speakername MaguroHarbor_Dojo_EventScript_Koishi_Text_0
	msgbox MaguroHarbor_Dojo_EventScript_KoishiDefeated_Text_3
	closemessage
	specialvar VAR_RESULT, GetPlayerFacingDirection
	compare VAR_RESULT, DIR_WEST
	goto_if_eq MaguroHarbor_Dojo_EventScript_KoishiDefeated_2
	applymovement 4, MaguroHarbor_Dojo_EventScript_KoishiDefeated_Movement_1
MaguroHarbor_Dojo_EventScript_KoishiDefeated_1:
	waitmovement 4
	removeobject 4
	setflag FLAG_HIDE_KOISHI
	release
	end

MaguroHarbor_Dojo_EventScript_KoishiDefeated_2:
	applymovement 4, MaguroHarbor_Dojo_EventScript_KoishiDefeated_Movement_0
	goto MaguroHarbor_Dojo_EventScript_KoishiDefeated_1


MaguroHarbor_Dojo_EventScript_Izumi::
	trainerbattle_single TRAINER_IZUMI, MaguroHarbor_Dojo_EventScript_Izumi_Text_0, MaguroHarbor_Dojo_EventScript_Izumi_Text_1
	msgbox MaguroHarbor_Dojo_EventScript_Izumi_Text_2, MSGBOX_AUTOCLOSE
	return


MaguroHarbor_Dojo_EventScript_Ren::
	trainerbattle_single TRAINER_REN, MaguroHarbor_Dojo_EventScript_Ren_Text_0, MaguroHarbor_Dojo_EventScript_Ren_Text_1
	msgbox MaguroHarbor_Dojo_EventScript_Ren_Text_2, MSGBOX_AUTOCLOSE
	return


MaguroHarbor_Dojo_EventScript_Mizu::
	trainerbattle_single TRAINER_MIZU, MaguroHarbor_Dojo_EventScript_Mizu_Text_0, MaguroHarbor_Dojo_EventScript_Mizu_Text_1
	msgbox MaguroHarbor_Dojo_EventScript_Mizu_Text_2, MSGBOX_AUTOCLOSE
	return


MaguroHarbor_Dojo_EventScript_Advice::
	lock
	faceplayer
	speakername MaguroHarbor_Dojo_EventScript_Advice_Text_0
	goto_if_set FLAG_BADGE01_GET, MaguroHarbor_Dojo_EventScript_Advice_2
	msgbox MaguroHarbor_Dojo_EventScript_Advice_Text_2
MaguroHarbor_Dojo_EventScript_Advice_1:
	release
	return

MaguroHarbor_Dojo_EventScript_Advice_2:
	msgbox MaguroHarbor_Dojo_EventScript_Advice_Text_1
	goto MaguroHarbor_Dojo_EventScript_Advice_1


MaguroHarbor_Dojo_EventScript_DojoStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, MaguroHarbor_Dojo_EventScript_DojoStatue_2
	msgbox MaguroHarbor_Dojo_EventScript_DojoStatue_Text_1, MSGBOX_SIGN
MaguroHarbor_Dojo_EventScript_DojoStatue_1:
	releaseall
	return

MaguroHarbor_Dojo_EventScript_DojoStatue_2:
	msgbox MaguroHarbor_Dojo_EventScript_DojoStatue_Text_0, MSGBOX_SIGN
	goto MaguroHarbor_Dojo_EventScript_DojoStatue_1


MaguroHarbor_Dojo_EventScript_KoishiDefeated_Movement_0:
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

MaguroHarbor_Dojo_EventScript_KoishiDefeated_Movement_1:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

MaguroHarbor_Dojo_EventScript_Koishi_Text_0:
	.string "Koishi$"

MaguroHarbor_Dojo_EventScript_Koishi_Text_1:
	.string "Welcome to Maguro's Koi Pond Dojo, one\n"
	.string "of the eight Dojos officially\l"
	.string "appointed by the Toku Council.\p"
	.string "We Dojo Masters fight wielders that\n"
	.string "have taken on the Toku Council's\l"
	.string "challenge.\p"
	.string "We each give out a different Token to\n"
	.string "anyone who succeeds in defeating us.\p"
	.string "I am Koishi. I began raising elegant,\n"
	.string "graceful Pokémon when I was even\l"
	.string "younger than you are now.\p"
	.string "I may behave and speak in a soft\n"
	.string "manner, but do not for one second\l"
	.string "mistake soft-spokenness for\l"
	.string "weakness.\p"
	.string "Now… Shall we battle?$"

MaguroHarbor_Dojo_EventScript_Koishi_Text_2:
	.string "I see…$"

MaguroHarbor_Dojo_EventScript_Koishi_Text_3:
	.string "You shall achieve great things. I hope\n"
	.string "we meet again.$"

MaguroHarbor_Dojo_EventScript_KoishiDefeated_Text_0:
	.string "{PLAYER} received the Flowing\n"
	.string "Token from Koishi.$"

MaguroHarbor_Dojo_EventScript_KoishiDefeated_Text_1:
	.string "I applaud your skill. You are still a\n"
	.string "child, yet you obviously have a\l"
	.string "natural aptitude for battle.\p"
	.string "With the Token I just gave you, your\n"
	.string "Pokémon will obey you without\l"
	.string "question, even those you trade with\l"
	.string "others.\p"
	.string "I am also supposed to give you this.$"

MaguroHarbor_Dojo_EventScript_KoishiDefeated_Text_2:
	.string "This scroll contains Nature Power, a\n"
	.string "move that changes depending on the\l"
	.string "terrain your Pokémon is standing on.\p"
	.string "Going through the Toku Council's\n"
	.string "challenge is no easy undertaking, but\l"
	.string "I can feel your spirit overflowing\l"
	.string "with determination.\p"
	.string "Good luck, {PLAYER}.$"

MaguroHarbor_Dojo_EventScript_KoishiDefeated_Text_3:
	.string "That… That was a big one!…\p"
	.string "I'm going outside to make sure\n"
	.string "everyone's alright.$"

MaguroHarbor_Dojo_EventScript_Izumi_Text_0:
	.string "My Pokémon are the daintiest there\n"
	.string "is!$"

MaguroHarbor_Dojo_EventScript_Izumi_Text_1:
	.string "My poor Feebas!$"

MaguroHarbor_Dojo_EventScript_Izumi_Text_2:
	.string "You'll go far. I can tell.$"

MaguroHarbor_Dojo_EventScript_Ren_Text_0:
	.string "Come in! The water's nice and toasty!$"

MaguroHarbor_Dojo_EventScript_Ren_Text_1:
	.string "Nooo!$"

MaguroHarbor_Dojo_EventScript_Ren_Text_2:
	.string "I l-lied. I'm f-f-freezing in h-here.$"

MaguroHarbor_Dojo_EventScript_Mizu_Text_0:
	.string "Do not disturb the koi pond!$"

MaguroHarbor_Dojo_EventScript_Mizu_Text_1:
	.string "Stop making so much noise!$"

MaguroHarbor_Dojo_EventScript_Mizu_Text_2:
	.string "These are sophisticated fish. They\n"
	.string "need peace and quiet to thrive.$"

MaguroHarbor_Dojo_EventScript_Advice_Text_0:
	.string "Man$"

MaguroHarbor_Dojo_EventScript_Advice_Text_1:
	.string "You swept me away with that battle!$"

MaguroHarbor_Dojo_EventScript_Advice_Text_2:
	.string "Hello, young challenger! Are you going\n"
	.string "to be fighting for your first Token?\p"
	.string "Welcome to the Koi Pond Dojo!\p"
	.string "Koishi, the Master of this place,\n"
	.string "favors water-type moves. Her\l"
	.string "battling style is strong, yet\l"
	.string "graceful… Sigh…\p"
	.string "I am her biggest fan! It's true! Maybe\n"
	.string "one day, I'll become your biggest fan,\l"
	.string "who knows?\p"
	.string "Go get 'em!$"

MaguroHarbor_Dojo_EventScript_DojoStatue_Text_0:
	.string "Dojo of Maguro Harbor\p"
	.string "Certified wielders:\n"
	.string "Natsuki,\l"
	.string "{PLAYER}$"

MaguroHarbor_Dojo_EventScript_DojoStatue_Text_1:
	.string "Dojo of Maguro Harbor\p"
	.string "Certified wielders:\n"
	.string "Natsuki$"

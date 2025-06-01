KuraTown_House2_MapScripts::
	.byte 0


KuraTown_House2_EventScript_Ashii::
	lock
	switch VAR_SAKU_KURA_QUEST_TAMA_ASHII_STATE
	case 0, KuraTown_House2_EventScript_Ashii_3
	case 1, KuraTown_House2_EventScript_Ashii_4
	case 2, KuraTown_House2_EventScript_Ashii_5
	case 6, KuraTown_House2_EventScript_Ashii_6
KuraTown_House2_EventScript_Ashii_1:
	release
	return

KuraTown_House2_EventScript_Ashii_3:
	call AshiiScript1
	goto KuraTown_House2_EventScript_Ashii_1

KuraTown_House2_EventScript_Ashii_4:
	call AshiiScript2
	goto KuraTown_House2_EventScript_Ashii_1

KuraTown_House2_EventScript_Ashii_5:
	call AshiiScript3
	goto KuraTown_House2_EventScript_Ashii_1

KuraTown_House2_EventScript_Ashii_6:
	call AshiiScript_Reward
	goto KuraTown_House2_EventScript_Ashii_1


AshiiScript1:
	speakername AshiiScript1_Text_0
	msgbox AshiiScript1_Text_1
	closemessage
	delay 30
	playse SE_PIN
	applymovement 1, Common_Movement_FacePlayer
	waitmovement 0
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	speakername AshiiScript1_Text_0
	msgbox AshiiScript1_Text_2
	closemessage
	delay 30
	playse SE_PIN
	applymovement 1, AshiiScript1_Movement_0
	waitmovement 0
	speakername AshiiScript1_Text_3
	msgbox AshiiScript1_Text_4
	closemessage
	giveitem ITEM_ASHIIS_SCARF
	setvar VAR_SAKU_KURA_QUEST_TAMA_ASHII_STATE, 1
	startquest QUEST_SAKURALOVERS
	return


AshiiScript2:
	faceplayer
	speakername AshiiScript1_Text_3
	msgbox AshiiScript2_Text_0
	closemessage
	return


AshiiScript3:
	faceplayer
	speakername AshiiScript1_Text_3
	msgbox AshiiScript3_Text_0
	mcdialogue AshiiScript3_Text_1, AshiiScript3_Text_2, AshiiScript3_Text_3
	closemessage
	delay 24
	playse SE_PIN
	applymovement 1, AshiiScript3_Movement_0
	waitmovement 0
	playse SE_PIN
	applymovement 1, AshiiScript3_Movement_1
	waitmovement 0
	speakername AshiiScript1_Text_3
	msgbox AshiiScript3_Text_4
	mcdialogue AshiiScript3_Text_5, AshiiScript3_Text_6, AshiiScript3_Text_7
	closemessage
	delay 24
	applymovement 1, AshiiScript3_Movement_2
	playse SE_PIN
	delay 48
	playse SE_LEDGE
	delay 16
	delay 4
	playse SE_LEDGE
	delay 16
	delay 4
	playse SE_LEDGE
	delay 16
	delay 4
	playse SE_LEDGE
	delay 16
	delay 48
	waitmovement 1
	gettimeofday
	compare VAR_0x8000, TIME_DEAD_NIGHT
	goto_if_eq AshiiScript3_2
	speakername AshiiScript1_Text_3
	msgbox AshiiScript3_Text_9
	closemessage
	delay 40
	fadescreen FADE_TO_BLACK
	msgbox AshiiScript3_Text_10
	waitmessage
	closemessage
	pausefakertc
	fwdtime 0, 0
	warpsilent MAP_KURA_TOWN, 48, 29
	setvar VAR_SAKU_KURA_QUEST_TAMA_ASHII_STATE, 3
AshiiScript3_1:
	closemessage
	return

AshiiScript3_2:
	speakername AshiiScript1_Text_3
	msgbox AshiiScript3_Text_8
	delay 40
	warp MAP_KURA_TOWN, 48, 29
	setvar VAR_SAKU_KURA_QUEST_TAMA_ASHII_STATE, 3
	goto AshiiScript3_1


AshiiScript_Reward:
	faceplayer
	speakername AshiiScript1_Text_3
	msgbox AshiiScript_Reward_Text_0
	closemessage
	giveitem ITEM_DESTINY_KNOT, 1
	completequest QUEST_SAKURALOVERS
	setvar VAR_SAKU_KURA_QUEST_TAMA_ASHII_STATE, 7
	return


AshiiScript1_Movement_0:
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	step_end

AshiiScript3_Movement_0:
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	face_away_player
	delay_16
	delay_16
	delay_16
	step_end

AshiiScript3_Movement_1:
	emote_heart
	delay_16
	delay_16
	delay_16
	face_player
	step_end

AshiiScript3_Movement_2:
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	jump_in_place_down
	delay_4
	jump_in_place_left
	delay_4
	jump_in_place_up
	delay_4
	jump_in_place_right
	delay_16
	delay_16
	delay_16
	face_player
	step_end

AshiiScript1_Text_0:
	.string "Girl$"

AshiiScript1_Text_1:
	.string "Sigh… Oh, Tama…\n"
	.string "Why must life be so complicated?$"

AshiiScript1_Text_2:
	.string "Hey, what are you doing in my house?\n"
	.string "Were you eavesdropping?\p"
	.string "…It doesn't matter anyway.\n"
	.string "The boy I really like lives in\l"
	.string "Saku Village, but our two villages\l"
	.string "hate each other, so I can't see him\l"
	.string "anymore.\p"
	.string "If only there was a way for him\n"
	.string "to know my feelings…$"

AshiiScript1_Text_3:
	.string "Ashii$"

AshiiScript1_Text_4:
	.string "Wait, you're not from here, are you?\p"
	.string "My name is Ashii. I need your help.\p"
	.string "The guard won't let anyone from\n"
	.string "Kura Village enter Saku Village.\l"
	.string "But you should be fine!\p"
	.string "Please, go to Saku Village and\n"
	.string "give him this.\p"
	.string "He'll know it's from me…$"

AshiiScript2_Text_0:
	.string "Please, give Tama my silk scarf.\n"
	.string "He'll know it's from me…$"

AshiiScript3_Text_0:
	.string "Were you able to give Tama my gift?\p"
	.string "Did…\n"
	.string "Did he get my letter?$"

AshiiScript3_Text_1:
	.string "Yep!$"

AshiiScript3_Text_2:
	.string "He sure did!$"

AshiiScript3_Text_3:
	.string "Loud and clear.$"

AshiiScript3_Text_4:
	.string "I'm sorry. You've been an incredible\n"
	.string "help, and I don't even know your name!\l"
	.string "May i ask what it is?\p"
	.string "{PLAYER}… I see…\p"
	.string "{PLAYER}, I know this is a big thing\n"
	.string "to ask, but…\p"
	.string "I want to be sure that my meeting\n"
	.string "with Tama is safe.\l"
	.string "Who knows? It might be our last.\p"
	.string "Could you please accompany me?$"

AshiiScript3_Text_5:
	.string "Of course.$"

AshiiScript3_Text_6:
	.string "Who wouldn't?$"

AshiiScript3_Text_7:
	.string "I guess?$"

AshiiScript3_Text_8:
	.string "Thank you! Thank you! Thank you!\p"
	.string "Let's make haste, then.\n"
	.string "Before the moon takes her slumber!$"

AshiiScript3_Text_9:
	.string "Thank you! Thank you! Thank you!\p"
	.string "Meet me here later tonight.$"

AshiiScript3_Text_10:
	.string "Late that night…$"

AshiiScript_Reward_Text_0:
	.string "{PLAYER}! It's you!\n"
	.string "I can't thank you enough for the\l"
	.string "night you've given us.\p"
	.string "Even if we must meet under cover of\n"
	.string "darkness, I would risk it all for Tama,\l"
	.string "again and again and again…\l"
	.string "And again… And again…\l"
	.string "And again…\p"
	.string "Here, take this.\n"
	.string "It's the least I can do…$"

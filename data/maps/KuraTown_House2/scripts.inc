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
	call AshiiScript6
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
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	msgbox AshiiScript1_Text_3
	closemessage
	speakername AshiiScript1_Text_4
	msgbox AshiiScript1_Text_5
	closemessage
	giveitem ITEM_ASHIIS_SCARF
	setvar VAR_SAKU_KURA_QUEST_TAMA_ASHII_STATE, 1
	startquest QUEST_SAKURALOVERS
	return


AshiiScript2:
	faceplayer
	speakername AshiiScript1_Text_4
	msgbox AshiiScript2_Text_0
	closemessage
	return


AshiiScript3:
	faceplayer
	speakername AshiiScript1_Text_4
	msgbox AshiiScript3_Text_0
	closemessage
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, AshiiScript3_Text_1, AshiiScript3_Text_2, AshiiScript3_Text_3
	playse SE_PIN
	applymovement 1, AshiiScript3_Movement_0
	waitmovement 0
	speakername AshiiScript1_Text_4
	msgbox AshiiScript3_Text_4
	closemessage
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, AshiiScript3_Text_5, AshiiScript3_Text_6, AshiiScript3_Text_7
	applymovement 1, AshiiScript3_Movement_1
	waitmovement 0
	faceplayer
	gettimeofday
	speakername AshiiScript1_Text_4
	compare VAR_0x8000, TIME_DEAD_NIGHT
	goto_if_eq AshiiScript3_2
	msgbox AshiiScript3_Text_9
	closemessage
	fadescreen FADE_TO_BLACK
	msgbox AshiiScript3_Text_10
	waitmessage
	closemessage
	fadescreen FADE_FROM_BLACK
	pausefakertc
	fwdtime 0, 0
	warp MAP_KURA_TOWN, 48, 29
	setvar VAR_SAKU_KURA_QUEST_TAMA_ASHII_STATE, 3
AshiiScript3_1:
	closemessage
	return

AshiiScript3_2:
	msgbox AshiiScript3_Text_8
	fadescreen FADE_TO_BLACK
	warp MAP_KURA_TOWN, 48, 29
	setvar VAR_SAKU_KURA_QUEST_TAMA_ASHII_STATE, 3
	goto AshiiScript3_1


AshiiScript6:
	faceplayer
	setvar VAR_SAKU_KURA_QUEST_TAMA_ASHII_STATE, 7
	speakername AshiiScript1_Text_4
	msgbox AshiiScript6_Text_0
	waitmessage
	closemessage
	giveitem ITEM_DESTINY_KNOT, 1
	completequest QUEST_SAKURALOVERS
	end


AshiiScript3_Movement_0:
	emote_exclamation_mark
	delay_16
	delay_16
	face_away_player
	delay_16
	delay_16
	delay_16
	emote_heart
	face_player
	step_end

AshiiScript3_Movement_1:
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	jump_in_place_down
	delay_4
	jump_in_place_down
	delay_4
	jump_in_place_down
	delay_4
	step_end

AshiiScript1_Text_0:
	.string "Girl$"

AshiiScript1_Text_1:
	.string "Sigh… Oh, Tama… Why must life be so\n"
	.string "complicated?$"

AshiiScript1_Text_2:
	.string "Hey, what are you doing in my house?\n"
	.string "Were you eavesdropping?\p"
	.string "…It doesn't matter anyway. The boy I\n"
	.string "really like lives in Saku Village, but\l"
	.string "our two villages hate each other, so I\l"
	.string "can't see him anymore.\p"
	.string "If only there was a way for him to\n"
	.string "know my feelings…$"

AshiiScript1_Text_3:
	.string "Wait, you're not from here, are you?\p"
	.string "$"

AshiiScript1_Text_4:
	.string "Ashii$"

AshiiScript1_Text_5:
	.string "My name is Ashii. I need your help. The\n"
	.string "guard won't let anyone from Kura\l"
	.string "Village enter Saku Village. But you\l"
	.string "should be fine!\p"
	.string "Please, go to Saku Village and give him\n"
	.string "this. He'll know it's from me.$"

AshiiScript2_Text_0:
	.string "The guard won't let anyone from Kura\n"
	.string "Village enter Saku Village. But you\l"
	.string "should be fine!\p"
	.string "Please, go to Saku Village and give him\n"
	.string "this. He'll know it's from me.$"

AshiiScript3_Text_0:
	.string "Were able to give the scarf to Tama\n"
	.string "yet? Did he get my message?$"

AshiiScript3_Text_1:
	.string "Yep!$"

AshiiScript3_Text_2:
	.string "He sure did!$"

AshiiScript3_Text_3:
	.string "Loud and clear.$"

AshiiScript3_Text_4:
	.string "I'm sorry. You've been an incredible\n"
	.string "help and I haven't even gotten your\l"
	.string "name yet. May i ask what it is?\p"
	.string "{PLAYER}… I see…\p"
	.string "{PLAYER}, I know this is a big thing\n"
	.string "to ask, but…\p"
	.string "I want to be sure that my meeting\n"
	.string "with Tama will be safe, especially if it\l"
	.string "might be our last. If so, can you\l"
	.string "please come with me when we go see\l"
	.string "each other again?$"

AshiiScript3_Text_5:
	.string "Of course.$"

AshiiScript3_Text_6:
	.string "Who wouldn't?$"

AshiiScript3_Text_7:
	.string "You both deserve it.$"

AshiiScript3_Text_8:
	.string "Thank you! Thank you! Thank you!\n"
	.string "Let's make haste, then. Before the\l"
	.string "moon takes her slumber in a few hours.$"

AshiiScript3_Text_9:
	.string "Thank you! Thank you! Thank you!\n"
	.string "Please come see me later tonight.$"

AshiiScript3_Text_10:
	.string "Late that night…$"

AshiiScript6_Text_0:
	.string "{PLAYER}! It's you! I can never\n"
	.string "thank you enough for the night you've\l"
	.string "given us. Even if we must meet under\l"
	.string "cover of darkness, I would risk it all\l"
	.string "for Tama again and again and again.\l"
	.string "Here, take this. It's the least I can\l"
	.string "do for all your help…$"

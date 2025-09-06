KuraTown_House2_MapScripts::
	.byte 0


KuraTown_House2_EventScript_Ashii::
	lock
	switch VAR_SAKU_KURA_QUEST_TAMA_ASHII_STATE
	case 0, KuraTown_House2_EventScript_Ashii_3
	case 1, KuraTown_House2_EventScript_Ashii_4
	case 2, KuraTown_House2_EventScript_Ashii_5
	case 3, KuraTown_House2_EventScript_Ashii_6
	case 7, KuraTown_House2_EventScript_Ashii_7
	case 8, KuraTown_House2_EventScript_Ashii_8
KuraTown_House2_EventScript_Ashii_1:
	release
	return

KuraTown_House2_EventScript_Ashii_3:
	call AshiiScript_FirstEncounter
	goto KuraTown_House2_EventScript_Ashii_1

KuraTown_House2_EventScript_Ashii_4:
	call AshiiScript_DidYouGiveTamaScarf
	goto KuraTown_House2_EventScript_Ashii_1

KuraTown_House2_EventScript_Ashii_5:
	call AshiiScript_ReportBackAfterGivingScarf
	goto KuraTown_House2_EventScript_Ashii_1

KuraTown_House2_EventScript_Ashii_6:
	call AshiiScript_EscortAshii
	goto KuraTown_House2_EventScript_Ashii_1

KuraTown_House2_EventScript_Ashii_7:
	call AshiiScript_Reward
	goto KuraTown_House2_EventScript_Ashii_1

KuraTown_House2_EventScript_Ashii_8:
	call AshiiScript_QuestOver
	goto KuraTown_House2_EventScript_Ashii_1


AshiiScript_FirstEncounter:
	applymovement 1, AshiiScript_FirstEncounter_Movement_0
	speakername AshiiScript_FirstEncounter_Text_0
	msgbox AshiiScript_FirstEncounter_Text_1
	closemessage
	delay 30
	playse SE_PIN
	applymovement 1, Common_Movement_FacePlayer
	waitmovement 0
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	speakername AshiiScript_FirstEncounter_Text_0
	msgbox AshiiScript_FirstEncounter_Text_2
	closemessage
	delay 30
	playse SE_PIN
	applymovement 1, AshiiScript_FirstEncounter_Movement_1
	waitmovement 0
	speakername AshiiScript_FirstEncounter_Text_3
	msgbox AshiiScript_FirstEncounter_Text_4
	closemessage
	giveitem ITEM_ASHIIS_SCARF
	setvar VAR_SAKU_KURA_QUEST_TAMA_ASHII_STATE, 1
	startquest QUEST_SAKURALOVERS
	return


AshiiScript_DidYouGiveTamaScarf:
	faceplayer
	speakername AshiiScript_FirstEncounter_Text_3
	msgbox AshiiScript_DidYouGiveTamaScarf_Text_0
	closemessage
	return


AshiiScript_ReportBackAfterGivingScarf:
	setvar VAR_SAKU_KURA_QUEST_TAMA_ASHII_STATE, 3
	faceplayer
	speakername AshiiScript_FirstEncounter_Text_3
	msgbox AshiiScript_ReportBackAfterGivingScarf_Text_0
	mcdialogue AshiiScript_ReportBackAfterGivingScarf_Text_1, AshiiScript_ReportBackAfterGivingScarf_Text_2, AshiiScript_ReportBackAfterGivingScarf_Text_3
	closemessage
	delay 24
	playse SE_PIN
	applymovement 1, AshiiScript_ReportBackAfterGivingScarf_Movement_0
	waitmovement 0
	playse SE_PIN
	applymovement 1, AshiiScript_ReportBackAfterGivingScarf_Movement_1
	waitmovement 0
	speakername AshiiScript_FirstEncounter_Text_3
	msgbox AshiiScript_ReportBackAfterGivingScarf_Text_4
	mcdialogue AshiiScript_ReportBackAfterGivingScarf_Text_5, AshiiScript_ReportBackAfterGivingScarf_Text_6, AshiiScript_ReportBackAfterGivingScarf_Text_7
	closemessage
	compare VAR_RESULT, 0
	goto_if_eq AshiiScript_ReportBackAfterGivingScarf_1
	compare VAR_RESULT, 1
	goto_if_eq AshiiScript_ReportBackAfterGivingScarf_1
	applymovement 1, AshiiScript_ReportBackAfterGivingScarf_Movement_2
	speakername AshiiScript_FirstEncounter_Text_3
	msgbox AshiiScript_ReportBackAfterGivingScarf_Text_8
	closemessage
	return

AshiiScript_ReportBackAfterGivingScarf_1:
	call AshiiScript_PlayerAcceptsEscort
	return


AshiiScript_EscortAshii:
	faceplayer
	speakername AshiiScript_FirstEncounter_Text_3
	msgbox AshiiScript_EscortAshii_Text_0
	mcdialogue AshiiScript_EscortAshii_Text_1, AshiiScript_ReportBackAfterGivingScarf_Text_7
	closemessage
	compare VAR_RESULT, 0
	goto_if_eq AshiiScript_EscortAshii_1
	applymovement 1, AshiiScript_ReportBackAfterGivingScarf_Movement_2
	speakername AshiiScript_FirstEncounter_Text_3
	msgbox AshiiScript_EscortAshii_Text_2
	closemessage
	return

AshiiScript_EscortAshii_1:
	call AshiiScript_PlayerAcceptsEscort
	return


AshiiScript_PlayerAcceptsEscort:
	setvar VAR_SAKU_KURA_QUEST_TAMA_ASHII_STATE, 4
	applymovement 1, AshiiScript_PlayerAcceptsEscort_Movement_0
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
	delay 4
	playse SE_LEDGE
	waitmovement 1
	faceplayer
	gettimeofday
	compare VAR_0x8000, TIME_DEAD_NIGHT
	goto_if_eq AshiiScript_PlayerAcceptsEscort_2
	applymovement 1, AshiiScript_PlayerAcceptsEscort_Movement_1
	speakername AshiiScript_FirstEncounter_Text_3
	msgbox AshiiScript_PlayerAcceptsEscort_Text_1
	closemessage
	delay 40
	fadescreen FADE_TO_BLACK
	msgbox AshiiScript_PlayerAcceptsEscort_Text_2
	waitmessage
	closemessage
	pausefakertc
	fwdtime 0, 0
	warpsilent MAP_KURA_TOWN, 48, 29
AshiiScript_PlayerAcceptsEscort_1:
	closemessage
	return

AshiiScript_PlayerAcceptsEscort_2:
	applymovement 1, AshiiScript_PlayerAcceptsEscort_Movement_1
	speakername AshiiScript_FirstEncounter_Text_3
	msgbox AshiiScript_PlayerAcceptsEscort_Text_0
	delay 40
	pausefakertc
	fwdtime 0, 0
	warp MAP_KURA_TOWN, 48, 29
	goto AshiiScript_PlayerAcceptsEscort_1


AshiiScript_Reward:
	faceplayer
	applymovement 1, AshiiScript_Reward_Movement_0
	speakername AshiiScript_FirstEncounter_Text_3
	msgbox AshiiScript_Reward_Text_0
	closemessage
	giveitem ITEM_COVERT_CLOAK
	applymovement 1, AshiiScript_Reward_Movement_1
	speakername AshiiScript_FirstEncounter_Text_3
	msgbox AshiiScript_Reward_Text_1
	closemessage
	completequest QUEST_SAKURALOVERS
	setvar VAR_SAKU_KURA_QUEST_TAMA_ASHII_STATE, 8
	return


AshiiScript_QuestOver:
	faceplayer
	speakername AshiiScript_FirstEncounter_Text_3
	msgbox AshiiScript_QuestOver_Text_0
	closemessage
	return


AshiiScript_FirstEncounter_Movement_0:
	emote_pensive
	step_end

AshiiScript_FirstEncounter_Movement_1:
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	step_end

AshiiScript_ReportBackAfterGivingScarf_Movement_0:
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	face_away_player
	delay_16
	delay_16
	delay_16
	step_end

AshiiScript_ReportBackAfterGivingScarf_Movement_1:
	emote_heart
	delay_16
	delay_16
	delay_16
	face_player
	step_end

AshiiScript_ReportBackAfterGivingScarf_Movement_2:
	emote_sad
	step_end

AshiiScript_PlayerAcceptsEscort_Movement_0:
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
	delay_4
	jump_in_place_down
	step_end

AshiiScript_PlayerAcceptsEscort_Movement_1:
	emote_heart
	step_end

AshiiScript_Reward_Movement_0:
	emote_happy
	step_end

AshiiScript_Reward_Movement_1:
	emote_sweat
	step_end

AshiiScript_FirstEncounter_Text_0:
	.string "Girl$"

AshiiScript_FirstEncounter_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_GIRL_2 EMOTE_NORMAL}Sigh… Oh, Tama…\n"
	.string "Why must life be so complicated?$"

AshiiScript_FirstEncounter_Text_2:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_GIRL_2 EMOTE_NORMAL}Hey, what are you doing in my house?\n"
	.string "Were you eavesdropping?\p"
	.string "…It doesn't matter anyway.\n"
	.string "The boy who stole my heart lives in\l"
	.string "Saku Village, but our two villages\l"
	.string "hate each other, so I can't see him\l"
	.string "anymore.\p"
	.string "If only there was a way for him\n"
	.string "to know my feelings…$"

AshiiScript_FirstEncounter_Text_3:
	.string "Ashii$"

AshiiScript_FirstEncounter_Text_4:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_GIRL_2 EMOTE_NORMAL}Wait, you're not from here, are you?\p"
	.string "My name is Ashii. I need your help.\p"
	.string "The guard won't let anyone from\n"
	.string "Kura Village enter Saku Village.\l"
	.string "But you should be fine!\p"
	.string "Please, go to Saku Village and\n"
	.string "give him this.\p"
	.string "He'll know it's from me…$"

AshiiScript_DidYouGiveTamaScarf_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_GIRL_2 EMOTE_NORMAL}Please, give Tama my silk scarf.\n"
	.string "He'll know it's from me…$"

AshiiScript_ReportBackAfterGivingScarf_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_GIRL_2 EMOTE_NORMAL}Were you able to give Tama my gift?\p"
	.string "Did…\n"
	.string "Did he get my letter?$"

AshiiScript_ReportBackAfterGivingScarf_Text_1:
	.string "Yep!$"

AshiiScript_ReportBackAfterGivingScarf_Text_2:
	.string "He sure did!$"

AshiiScript_ReportBackAfterGivingScarf_Text_3:
	.string "Loud and clear.$"

AshiiScript_ReportBackAfterGivingScarf_Text_4:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_GIRL_2 EMOTE_NORMAL}I'm sorry. You've been an incredible\n"
	.string "help, and I don't even know your name!\p"
	.string "… … …{PLAYER}. I see…\p"
	.string "{PLAYER}, I know this is a big thing\n"
	.string "to ask, but…\p"
	.string "I want to be sure that my meeting\n"
	.string "with Tama is safe.\l"
	.string "Who knows? It might be our last.\p"
	.string "Could you please escort me?$"

AshiiScript_ReportBackAfterGivingScarf_Text_5:
	.string "Who wouldn't?$"

AshiiScript_ReportBackAfterGivingScarf_Text_6:
	.string "I guess?$"

AshiiScript_ReportBackAfterGivingScarf_Text_7:
	.string "Not right now.$"

AshiiScript_ReportBackAfterGivingScarf_Text_8:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_GIRL_2 EMOTE_NORMAL}Please come back as soon as you can\n"
	.string "spare some time…$"

AshiiScript_EscortAshii_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_GIRL_2 EMOTE_NORMAL}I want to be sure that my meeting\n"
	.string "with Tama is safe.\l"
	.string "Who knows? It might be our last.\p"
	.string "Could you please escort me?$"

AshiiScript_EscortAshii_Text_1:
	.string "Let's go!$"

AshiiScript_EscortAshii_Text_2:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_GIRL_2 EMOTE_NORMAL}Please come back…\n"
	.string "Don't toy with a girl's heart…$"

AshiiScript_PlayerAcceptsEscort_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_GIRL_2 EMOTE_NORMAL}Thank you! Thank you! Thank you!\p"
	.string "Let's make haste, then.\n"
	.string "Before the moon takes her slumber!$"

AshiiScript_PlayerAcceptsEscort_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_GIRL_2 EMOTE_NORMAL}Thank you! Thank you! Thank you!\p"
	.string "Meet me here later tonight.$"

AshiiScript_PlayerAcceptsEscort_Text_2:
	.string "Later that night…$"

AshiiScript_Reward_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_GIRL_2 EMOTE_NORMAL}{PLAYER}! It's you!\p"
	.string "I can't thank you enough for the\n"
	.string "night you've given us.\p"
	.string "Even if we must meet under cover of\n"
	.string "darkness, I would risk it all for Tama,\l"
	.string "again and again and again…\l"
	.string "And again… And again…\l"
	.string "And again…\p"
	.string "Here, you can have this…\n"
	.string "For all the trouble.$"

AshiiScript_Reward_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_GIRL_2 EMOTE_NORMAL}It was supposed to conceal me so I\n"
	.string "could sneak into Saku Village, but…\p"
	.string "When the guards made fun of me, I\n"
	.string "realized it's meant for Pokémon.$"

AshiiScript_QuestOver_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_GIRL_2 EMOTE_NORMAL}If only Saku and Kura Village stopped\n"
	.string "this nonsensical rivalry…\p"
	.string "I'm sure nobody even remembers the\n"
	.string "reason!$"

Common_EventScript_PkmnCenterNurse_Chansey::
	lock
	setseenmon SPECIES_CHANSEY
	playmoncry SPECIES_CHANSEY, CRY_MODE_NORMAL
	setspeakertomonname SPECIES_CHANSEY
	msgbox Common_EventScript_PkmnCenterNurse_Chansey_Text_0
	waitse
	closemessage
	release
	return


Common_EventScript_PkmnCenterNurse_Blissey::
	lock
	setseenmon SPECIES_BLISSEY
	playmoncry SPECIES_BLISSEY, CRY_MODE_NORMAL
	setspeakertomonname SPECIES_BLISSEY
	msgbox Common_EventScript_PkmnCenterNurse_Chansey_Text_0
	waitse
	closemessage
	release
	return


Common_EventScript_PkmnCenterNurse_Sleep::
	lock
	faceplayer
	checkmoney 500
	compare VAR_RESULT, 0
	goto_if_ne Common_EventScript_PkmnCenterNurse_Sleep_2
	speakername Common_EventScript_PkmnCenterNurse_Sleep_Text_0
	msgbox Common_EventScript_PkmnCenterNurse_Sleep_Text_1
	closemessage
Common_EventScript_PkmnCenterNurse_Sleep_1:
	hidemoneybox
	release
	end

Common_EventScript_PkmnCenterNurse_Sleep_2:
	speakername Common_EventScript_PkmnCenterNurse_Sleep_Text_0
	msgbox Common_EventScript_PkmnCenterNurse_Sleep_Text_1
	closemessage
	showmoneybox 18, 0
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, Common_EventScript_PkmnCenterNurse_Sleep_Text_2, Common_EventScript_PkmnCenterNurse_Sleep_Text_3, Common_EventScript_PkmnCenterNurse_Sleep_Text_4
	switch VAR_RESULT
	case 0, Common_EventScript_PkmnCenterNurse_Sleep_6
	case 1, Common_EventScript_PkmnCenterNurse_Sleep_7
	goto Common_EventScript_PkmnCenterNurse_Sleep_1

Common_EventScript_PkmnCenterNurse_Sleep_6:
	call Common_EventScript_PkmnCenterNurse_ChooseSleep
	fadescreenswapbuffers FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	fwdtime 8, 0
	fadescreenswapbuffers FADE_FROM_BLACK
	goto Common_EventScript_PkmnCenterNurse_Sleep_1

Common_EventScript_PkmnCenterNurse_Sleep_7:
	call Common_EventScript_PkmnCenterNurse_ChooseSleep
	fadescreenswapbuffers FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	fwdtime 22, 0
	fadescreenswapbuffers FADE_FROM_BLACK
	goto Common_EventScript_PkmnCenterNurse_Sleep_1


EventScript_PkmnCenterNurse_TakeAndHealPkmn::
	hidefollower 0
	applymovement VAR_0x800A, EventScript_PkmnCenterNurse_TakeAndHealPkmn_Movement_0
	waitmovement VAR_0x800A
	applymovement VAR_0x800B, EventScript_PkmnCenterNurse_TakeAndHealPkmn_Movement_1
	waitmovement VAR_0x800B
	applymovement VAR_0x800A, EventScript_PkmnCenterNurse_TakeAndHealPkmn_Movement_2
	waitmovement VAR_0x800A
	dofieldeffect FLDEFF_POKECENTER_HEAL
	waitfieldeffect FLDEFF_POKECENTER_HEAL
	applymovement VAR_0x800A, EventScript_PkmnCenterNurse_TakeAndHealPkmn_Movement_3
	waitmovement VAR_0x800A
	applymovement VAR_0x800B, EventScript_PkmnCenterNurse_TakeAndHealPkmn_Movement_4
	waitmovement VAR_0x800B
	applymovement VAR_0x800A, EventScript_PkmnCenterNurse_TakeAndHealPkmn_Movement_4
	waitmovement VAR_0x800A
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	return


Common_EventScript_PkmnCenterNurse_ChooseSleep::
	playse SE_SHOP
	removemoney 500
	updatemoneybox
	speakername Common_EventScript_PkmnCenterNurse_Sleep_Text_0
	msgbox Common_EventScript_PkmnCenterNurse_ChooseSleep_Text_0
	closemessage
	hidemoneybox
	return


Common_EventScript_PkmnCenterNurse_CutTheBullshit::
	lock
	faceplayer
	setvar VAR_0x8004, 0
	speakername Common_EventScript_PkmnCenterNurse_Sleep_Text_0
	msgbox Common_EventScript_PkmnCenterNurse_CutTheBullshit_Text_0
	closemessage
	incrementgamestat GAME_STAT_USED_POKECENTER
	call EventScript_PkmnCenterNurse_TakeAndHealPkmn
	goto_if_unset FLAG_POKERUS_EXPLAINED, Common_EventScript_PkmnCenterNurse_CutTheBullshit_2
Common_EventScript_PkmnCenterNurse_CutTheBullshit_1:
	speakername Common_EventScript_PkmnCenterNurse_Sleep_Text_0
	msgbox Common_EventScript_PkmnCenterNurse_CutTheBullshit_Text_1
	closemessage
	applymovement VAR_0x800B, Common_EventScript_PkmnCenterNurse_CutTheBullshit_Movement_0
	waitmovement 0
	speakername Common_EventScript_PkmnCenterNurse_Sleep_Text_0
	msgbox Common_EventScript_PkmnCenterNurse_CutTheBullshit_Text_2
	closemessage
	release
	end

Common_EventScript_PkmnCenterNurse_CutTheBullshit_2:
	call EventScript_PkmnCenterNurse_CheckPokerus_CutTheBullshit
	goto Common_EventScript_PkmnCenterNurse_CutTheBullshit_1


EventScript_PkmnCenterNurse_CheckPokerus_CutTheBullshit::
	specialvar VAR_RESULT, IsPokerusInParty
	compare VAR_RESULT, TRUE
	goto_if_eq EventScript_PkmnCenterNurse_CheckPokerus_CutTheBullshit_1
	return

EventScript_PkmnCenterNurse_CheckPokerus_CutTheBullshit_1:
	message EventScript_PkmnCenterNurse_CheckPokerus_CutTheBullshit_Text_0
	setflag FLAG_POKERUS_EXPLAINED
	return


Common_EventScript_PkmnCenterNurse::
	lock
	faceplayer
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, CountPlayerTrainerStars
	goto_if_eq VAR_RESULT, 4, EventScript_PkmnCenterNurse_GoldCard
	msgbox gText_WouldYouLikeToRestYourPkmn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_PkmnCenterNurse_HealPkmn
	goto_if_eq VAR_RESULT, NO, EventScript_PkmnCenterNurse_Goodbye
	end

EventScript_PkmnCenterNurse_Goodbye::
	message gText_WeHopeToSeeYouAgain
	return

@ VAR_0x8004 is 1 when player has Gold Card; jumps are identical
EventScript_PkmnCenterNurse_HealPkmn::
	incrementgamestat GAME_STAT_USED_POKECENTER
	call_if_eq VAR_0x8004, 0, EventScript_PkmnCenterNurse_IllTakeYourPkmn
	call_if_eq VAR_0x8004, 1, EventScript_PkmnCenterNurse_IllTakeYourPkmn2
	waitmessage
	call EventScript_PkmnCenterNurse_TakeAndHealPkmn
	goto_if_unset FLAG_POKERUS_EXPLAINED, EventScript_PkmnCenterNurse_CheckPokerus
	goto EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom
	end

EventScript_PkmnCenterNurse_IllTakeYourPkmn::
	message gText_IllTakeYourPkmn
	return

EventScript_PkmnCenterNurse_IllTakeYourPkmn2::
	message gText_IllTakeYourPkmn2
	return

EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom::
	specialvar VAR_RESULT, PlayerNotAtTrainerHillEntrance
	goto_if_eq VAR_RESULT, 0, EventScript_PkmnCenterNurse_ReturnPkmn
	specialvar VAR_RESULT, BufferUnionRoomPlayerName
	copyvar VAR_0x8008, VAR_RESULT
	goto_if_eq VAR_0x8008, 0, EventScript_PkmnCenterNurse_ReturnPkmn
	goto_if_eq VAR_0x8008, 1, EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom
	end

@ VAR_0x8004 is 1 when player has Gold Card
EventScript_PkmnCenterNurse_ReturnPkmn::
	goto_if_eq VAR_0x8004, 1, EventScript_PkmnCenterNurse_ReturnPkmn2
	message gText_RestoredPkmnToFullHealth
	waitmessage
	applymovement VAR_0x800B, Movement_PkmnCenterNurse_Bow
	waitmovement 0
	message gText_WeHopeToSeeYouAgain
	return

EventScript_PkmnCenterNurse_ReturnPkmn2::
	message gText_ThankYouForWaiting
	waitmessage
	applymovement VAR_0x800B, Movement_PkmnCenterNurse_Bow
	waitmovement 0
	message gText_WeHopeToSeeYouAgain2
	return

EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom::
	goto_if_set FLAG_NURSE_UNION_ROOM_REMINDER, EventScript_PkmnCenterNurse_ReturnPkmn
	msgbox gText_RestoredPkmnToFullHealth, MSGBOX_DEFAULT
	setflag FLAG_NURSE_UNION_ROOM_REMINDER
	message CableClub_Text_PlayerIsWaiting
	waitmessage
	applymovement VAR_0x800B, Movement_PkmnCenterNurse_Bow
	waitmovement 0
	message gText_WeHopeToSeeYouAgain
	return

EventScript_PkmnCenterNurse_CheckPokerus::
	specialvar VAR_RESULT, IsPokerusInParty
	goto_if_eq VAR_RESULT, TRUE, EventScript_PkmnCenterNurse_ExplainPokerus
	goto_if_eq VAR_RESULT, FALSE, EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom
	end

EventScript_PkmnCenterNurse_ExplainPokerus::
	message gText_PokerusExplanation
	setflag FLAG_POKERUS_EXPLAINED
	return

EventScript_PkmnCenterNurse_GoldCard::
	goto_if_set FLAG_NURSE_MENTIONS_GOLD_CARD, EventScript_PkmnCenterNurse_AskForUsual
	setflag FLAG_NURSE_MENTIONS_GOLD_CARD
	msgbox gText_WelcomeCutShort, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement VAR_0x800B, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x800B, Common_Movement_Delay48
	waitmovement 0
	msgbox gText_NoticesGoldCard, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_PkmnCenterNurse_GoldCardHealPkmn
	message gText_WeHopeToSeeYouAgain2
	return

EventScript_PkmnCenterNurse_AskForUsual::
	msgbox gText_YouWantTheUsual, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_PkmnCenterNurse_GoldCardHealPkmn
	message gText_WeHopeToSeeYouAgain2
	return

EventScript_PkmnCenterNurse_GoldCardHealPkmn::
	setvar VAR_0x8004, 1
	goto EventScript_PkmnCenterNurse_HealPkmn
	end

Movement_PkmnCenterNurse_Bow:
	nurse_joy_bow
	delay_4
	step_end

Movement_PkmnCenterNurse_Turn:
	walk_in_place_faster_right
	step_end

EventScript_PkmnCenterNurse_TakeAndHealPkmn_Movement_0:
	face_left
	step_end

EventScript_PkmnCenterNurse_TakeAndHealPkmn_Movement_1:
	walk_in_place_fast_right
	delay_16
	delay_16
	step_end

EventScript_PkmnCenterNurse_TakeAndHealPkmn_Movement_2:
	face_right
	step_end

EventScript_PkmnCenterNurse_TakeAndHealPkmn_Movement_3:
	face_left
	delay_16
	delay_16
	step_end

EventScript_PkmnCenterNurse_TakeAndHealPkmn_Movement_4:
	walk_in_place_fast_down
	step_end

Common_EventScript_PkmnCenterNurse_CutTheBullshit_Movement_0:
	nurse_joy_bow
	delay_4
	step_end

Common_EventScript_PkmnCenterNurse_Chansey_Text_0:
	.string "Sey!$"

Common_EventScript_PkmnCenterNurse_Sleep_Text_0:
	.string "Nurse$"

Common_EventScript_PkmnCenterNurse_Sleep_Text_1:
	.string "Hello! For 500¥, you and your Pokémon\n"
	.string "can spend the night here.$"

Common_EventScript_PkmnCenterNurse_Sleep_Text_2:
	.string "Sleep until morning$"

Common_EventScript_PkmnCenterNurse_Sleep_Text_3:
	.string "Sleep until nighttime$"

Common_EventScript_PkmnCenterNurse_Sleep_Text_4:
	.string "Maybe later.$"

Common_EventScript_PkmnCenterNurse_ChooseSleep_Text_0:
	.string "Thank you! May you have a restful\n"
	.string "night.$"

Common_EventScript_PkmnCenterNurse_CutTheBullshit_Text_0:
	.string "Welcome to the refuge!\p"
	.string "Let me heal your Pokémon.$"

Common_EventScript_PkmnCenterNurse_CutTheBullshit_Text_1:
	.string "Your Pokémon are all healed and\n"
	.string "rested.$"

Common_EventScript_PkmnCenterNurse_CutTheBullshit_Text_2:
	.string "Please come again!$"

EventScript_PkmnCenterNurse_CheckPokerus_CutTheBullshit_Text_0:
	.string "Um, excuse me…\p"
	.string "I think your Pokémon is under some\n"
	.string "sort of spell.\p"
	.string "I'm pretty good at feeling this kind\n"
	.string "of thing. I have seen this before.\p"
	.string "I'm not sure what it is, but I have\n"
	.string "seen the Pokémon that had this aura\l"
	.string "around them grow exceptionally well\l"
	.string "for a while.$"

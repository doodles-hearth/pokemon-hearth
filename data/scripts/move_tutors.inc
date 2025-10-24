YifuCity_EventScript_WhirlpoolTutor::
	lock
	faceplayer
	goto_if_set FLAG_MOVE_TUTOR_TAUGHT_WHIRLPOOL, YifuCity_EventScript_WhirlpoolTutor_1
	setspeaker SP_NAME_FISHERMAN
	msgbox YifuCity_EventScript_WhirlpoolTutor_Text_3
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, YifuCity_EventScript_WhirlpoolTutor_Text_4, YifuCity_EventScript_WhirlpoolTutor_Text_5
	closemessage
	compare VAR_RESULT, 0
	goto_if_eq YifuCity_EventScript_WhirlpoolTutor_6
	setspeaker SP_NAME_FISHERMAN
	msgbox YifuCity_EventScript_WhirlpoolTutor_Text_6
	closemessage
	return

YifuCity_EventScript_WhirlpoolTutor_1:
	setspeaker SP_NAME_FISHERMAN
	msgbox YifuCity_EventScript_WhirlpoolTutor_Text_0
	checkitem ITEM_HEART_SCALE
	compare VAR_RESULT, 0
	goto_if_ne YifuCity_EventScript_WhirlpoolTutor_4
	return

YifuCity_EventScript_WhirlpoolTutor_4:
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, YifuCity_EventScript_WhirlpoolTutor_Text_1, YifuCity_EventScript_WhirlpoolTutor_Text_2
	closemessage
	compare VAR_RESULT, 0
	goto_if_eq YifuCity_EventScript_WhirlpoolTutor_9
	return

YifuCity_EventScript_WhirlpoolTutor_6:
	call YifuCity_EventScript_WhirlpoolTutorTeachWhirlpool
	return

YifuCity_EventScript_WhirlpoolTutor_9:
	call YifuCity_EventScript_WhirlpoolTutorTeachWhirlpool
	return


YifuCity_EventScript_WhirlpoolTutorTeachWhirlpool::
	setspeaker SP_NAME_FISHERMAN
	msgbox YifuCity_EventScript_WhirlpoolTutorTeachWhirlpool_Text_0
	setvar VAR_0x8005, MOVE_WHIRLPOOL
	call MoveTutor_EventScript_OpenPartyMenu
	compare VAR_RESULT, 0
	goto_if_eq YifuCity_EventScript_WhirlpoolTutorTeachWhirlpool_2
	goto_if_set FLAG_MOVE_TUTOR_TAUGHT_WHIRLPOOL, YifuCity_EventScript_WhirlpoolTutorTeachWhirlpool_5
	setflag FLAG_MOVE_TUTOR_TAUGHT_WHIRLPOOL
	setspeaker SP_NAME_FISHERMAN
	msgbox YifuCity_EventScript_WhirlpoolTutorTeachWhirlpool_Text_2
	closemessage
YifuCity_EventScript_WhirlpoolTutorTeachWhirlpool_1:
	release
	return

YifuCity_EventScript_WhirlpoolTutorTeachWhirlpool_2:
	setspeaker SP_NAME_FISHERMAN
	msgbox YifuCity_EventScript_WhirlpoolTutor_Text_6
	closemessage
	goto YifuCity_EventScript_WhirlpoolTutorTeachWhirlpool_1

YifuCity_EventScript_WhirlpoolTutorTeachWhirlpool_5:
	setspeaker SP_NAME_FISHERMAN
	msgbox YifuCity_EventScript_WhirlpoolTutorTeachWhirlpool_Text_1
	closemessage
	removeitem ITEM_HEART_SCALE
	goto YifuCity_EventScript_WhirlpoolTutorTeachWhirlpool_1


Saku_EventScript_ForcePalmTutor::
	lock
	faceplayer
	goto_if_set FLAG_MOVE_TUTOR_TAUGHT_FORCE_PALM, Saku_EventScript_ForcePalmTutor_1
	setspeaker SP_NAME_MAN
	msgbox Saku_EventScript_ForcePalmTutor_Text_1
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, Saku_EventScript_ForcePalmTutor_Text_2, YifuCity_EventScript_WhirlpoolTutor_Text_5
	closemessage
	compare VAR_RESULT, 0
	goto_if_eq Saku_EventScript_ForcePalmTutor_6
	setspeaker SP_NAME_MAN
	msgbox Saku_EventScript_ForcePalmTutor_Text_3
	closemessage
	return

Saku_EventScript_ForcePalmTutor_1:
	setspeaker SP_NAME_MAN
	msgbox Saku_EventScript_ForcePalmTutor_Text_0
	checkitem ITEM_HEART_SCALE
	compare VAR_RESULT, 0
	goto_if_ne Saku_EventScript_ForcePalmTutor_4
	return

Saku_EventScript_ForcePalmTutor_4:
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, YifuCity_EventScript_WhirlpoolTutor_Text_1, YifuCity_EventScript_WhirlpoolTutor_Text_2
	closemessage
	compare VAR_RESULT, 0
	goto_if_eq Saku_EventScript_ForcePalmTutor_9
	return

Saku_EventScript_ForcePalmTutor_6:
	call YifuCity_EventScript_ForcePalmTutorTeachForcePalm
	return

Saku_EventScript_ForcePalmTutor_9:
	call YifuCity_EventScript_ForcePalmTutorTeachForcePalm
	return


YifuCity_EventScript_ForcePalmTutorTeachForcePalm::
	setspeaker SP_NAME_MAN
	msgbox YifuCity_EventScript_ForcePalmTutorTeachForcePalm_Text_0
	setvar VAR_0x8005, MOVE_FORCE_PALM
	call MoveTutor_EventScript_OpenPartyMenu
	compare VAR_RESULT, 0
	goto_if_eq YifuCity_EventScript_ForcePalmTutorTeachForcePalm_2
	goto_if_set FLAG_MOVE_TUTOR_TAUGHT_FORCE_PALM, YifuCity_EventScript_ForcePalmTutorTeachForcePalm_5
	setflag FLAG_MOVE_TUTOR_TAUGHT_FORCE_PALM
	setspeaker SP_NAME_MAN
	msgbox YifuCity_EventScript_ForcePalmTutorTeachForcePalm_Text_2
	closemessage
YifuCity_EventScript_ForcePalmTutorTeachForcePalm_1:
	release
	return

YifuCity_EventScript_ForcePalmTutorTeachForcePalm_2:
	setspeaker SP_NAME_MAN
	msgbox Saku_EventScript_ForcePalmTutor_Text_3
	closemessage
	goto YifuCity_EventScript_ForcePalmTutorTeachForcePalm_1

YifuCity_EventScript_ForcePalmTutorTeachForcePalm_5:
	setspeaker SP_NAME_MAN
	msgbox YifuCity_EventScript_ForcePalmTutorTeachForcePalm_Text_1
	closemessage
	removeitem ITEM_HEART_SCALE
	goto YifuCity_EventScript_ForcePalmTutorTeachForcePalm_1



MauvilleCity_EventScript_RolloutTutor::
	lock
	faceplayer
	goto_if_set FLAG_MOVE_TUTOR_TAUGHT_WHIRLPOOL, MoveTutor_EventScript_RolloutTaught
	msgbox MoveTutor_Text_RolloutTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_RolloutDeclined
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_RolloutDeclined
	msgbox MoveTutor_Text_RolloutWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_ROLLOUT
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_RolloutDeclined
	setflag FLAG_MOVE_TUTOR_TAUGHT_WHIRLPOOL
	goto MoveTutor_EventScript_RolloutTaught
	end

MoveTutor_EventScript_RolloutDeclined::
	msgbox MoveTutor_Text_RolloutDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_RolloutTaught::
	msgbox MoveTutor_Text_RolloutTaught, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_PokemonCenter_1F_EventScript_FuryCutterTutor::
	lock
	faceplayer
	goto_if_set FLAG_MOVE_TUTOR_TAUGHT_FURY_CUTTER, MoveTutor_EventScript_FuryCutterTaught
	msgbox MoveTutor_Text_FuryCutterTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_FuryCutterDeclined
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_FuryCutterDeclined
	msgbox MoveTutor_Text_FuryCutterWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_FURY_CUTTER
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_FuryCutterDeclined
	setflag FLAG_MOVE_TUTOR_TAUGHT_FURY_CUTTER
	goto MoveTutor_EventScript_FuryCutterTaught
	end

MoveTutor_EventScript_FuryCutterDeclined::
	msgbox MoveTutor_Text_FuryCutterDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_FuryCutterTaught::
	msgbox MoveTutor_Text_FuryCutterTaught, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_House_EventScript_MimicTutor::
	lock
	faceplayer
	goto_if_set FLAG_MOVE_TUTOR_TAUGHT_MIMIC, MoveTutor_EventScript_MimicTaught
	msgbox MoveTutor_MimicTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_MimicDeclined
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_MimicDeclined
	msgbox MoveTutor_Text_MimicWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_MIMIC
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_MimicDeclined
	setflag FLAG_MOVE_TUTOR_TAUGHT_MIMIC
	goto MoveTutor_EventScript_MimicTaught
	end

MoveTutor_EventScript_MimicDeclined::
	msgbox MoveTutor_MimicDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_MimicTaught::
	msgbox MoveTutor_Text_MimicTaught, MSGBOX_DEFAULT
	release
	end

FallarborTown_Mart_EventScript_MetronomeTutor::
	lock
	faceplayer
	goto_if_set FLAG_MOVE_TUTOR_TAUGHT_METRONOME, MoveTutor_EventScript_MetronomeTaught
	msgbox MoveTutor_Text_MetronomeTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_MetronomeDeclined
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_MetronomeDeclined
	msgbox MoveTutor_Text_MetronomeWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_METRONOME
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_MetronomeDeclined
	setflag FLAG_MOVE_TUTOR_TAUGHT_METRONOME
	goto MoveTutor_EventScript_MetronomeTaught
	end

MoveTutor_EventScript_MetronomeDeclined::
	msgbox MoveTutor_Text_MetronomeDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_MetronomeTaught::
	msgbox MoveTutor_Text_MetronomeTaught, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_SleepTalkTutor::
	lock
	faceplayer
	goto_if_set FLAG_MOVE_TUTOR_TAUGHT_SLEEP_TALK, MoveTutor_EventScript_SleepTalkTaught
	msgbox MoveTutor_Text_SleepTalkTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_SleepTalkDeclined
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_SleepTalkDeclined
	msgbox MoveTutor_Text_SleepTalkWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_SLEEP_TALK
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_SleepTalkDeclined
	setflag FLAG_MOVE_TUTOR_TAUGHT_SLEEP_TALK
	goto MoveTutor_EventScript_SleepTalkTaught
	end

MoveTutor_EventScript_SleepTalkDeclined::
	msgbox MoveTutor_Text_SleepTalkDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_SleepTalkTaught::
	msgbox MoveTutor_Text_SleepTalkTaught, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_SubstituteTutor::
	lock
	faceplayer
	goto_if_set FLAG_MOVE_TUTOR_TAUGHT_SUBSTITUTE, MoveTutor_EventScript_SubstituteTaught
	msgbox MoveTutor_Text_SubstituteTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_SubstituteDeclined
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_SubstituteDeclined
	msgbox MoveTutor_Text_SubstituteWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_SUBSTITUTE
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_SubstituteDeclined
	setflag FLAG_MOVE_TUTOR_TAUGHT_SUBSTITUTE
	goto MoveTutor_EventScript_SubstituteTaught
	end

MoveTutor_EventScript_SubstituteDeclined::
	msgbox MoveTutor_Text_SubstituteDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_SubstituteTaught::
	msgbox MoveTutor_Text_SubstituteTaught, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_DynamicPunchTutor::
	lock
	faceplayer
	goto_if_set FLAG_MOVE_TUTOR_TAUGHT_DYNAMICPUNCH, MoveTutor_EventScript_DynamicPunchTaught
	msgbox MoveTutor_Text_DynamicPunchTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_DynamicPunchDeclined
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_DynamicPunchDeclined
	msgbox MoveTutor_Text_DynamicPunchWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_DYNAMIC_PUNCH
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_DynamicPunchDeclined
	setflag FLAG_MOVE_TUTOR_TAUGHT_DYNAMICPUNCH
	goto MoveTutor_EventScript_DynamicPunchTaught
	end

MoveTutor_EventScript_DynamicPunchDeclined::
	msgbox MoveTutor_Text_DynamicPunchDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_DynamicPunchTaught::
	msgbox MoveTutor_Text_DynamicPunchTaught, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_DoubleEdgeTutor::
	lock
	faceplayer
	goto_if_set FLAG_MOVE_TUTOR_TAUGHT_DOUBLE_EDGE, MoveTutor_EventScript_DoubleEdgeTaught
	msgbox MoveTutor_Text_DoubleEdgeTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_DoubleEdgeDeclined
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_DoubleEdgeDeclined
	msgbox MoveTutor_Text_DoubleEdgeWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_DOUBLE_EDGE
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_DoubleEdgeDeclined
	setflag FLAG_MOVE_TUTOR_TAUGHT_DOUBLE_EDGE
	goto MoveTutor_EventScript_DoubleEdgeTaught
	end

MoveTutor_EventScript_DoubleEdgeDeclined::
	msgbox MoveTutor_Text_DoubleEdgeDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_DoubleEdgeTaught::
	msgbox MoveTutor_Text_DoubleEdgeTaught, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_PokemonCenter_1F_EventScript_ExplosionTutor::
	lock
	faceplayer
	goto_if_set FLAG_MOVE_TUTOR_TAUGHT_EXPLOSION, MoveTutor_EventScript_ExplosionTaught
	msgbox MoveTutor_Text_ExplosionTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_ExplosionDeclined
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_ExplosionDeclined
	msgbox MoveTutor_Text_ExplosionWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_EXPLOSION
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_ExplosionDeclined
	setflag FLAG_MOVE_TUTOR_TAUGHT_EXPLOSION
	goto MoveTutor_EventScript_ExplosionTaught
	end

MoveTutor_EventScript_ExplosionDeclined::
	msgbox MoveTutor_Text_ExplosionDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_ExplosionTaught::
	msgbox MoveTutor_Text_ExplosionTaught, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_OpenPartyMenu::
	special ChooseMonForMoveTutor
	waitstate
	lock
	faceplayer
	return

MoveTutor_EventScript_CanOnlyBeLearnedOnce::
	msgbox MoveTutor_Text_ThisMoveCanOnlyBeLearnedOnce, MSGBOX_YESNO
	return

YifuCity_EventScript_WhirlpoolTutor_Text_0:
	.string "I can teach Whirlpool to your Pokémon\nagain, but make it worth my while, OK?\p"
	.string "I'm very fond of Heart Scales.\nThey remind me of the sea.\lI'll do it in exchange for one!$"

YifuCity_EventScript_WhirlpoolTutor_Text_1:
	.string "Give Heart Scale$"

YifuCity_EventScript_WhirlpoolTutor_Text_2:
	.string "Don't give$"

YifuCity_EventScript_WhirlpoolTutor_Text_3:
	.string "Hm? No, I'm not fishing.\p"
	.string "I'm just watching the tiny whirlpools\nPokémon make in the shallow water.\p"
	.string "Would you like your Pokémon to make whirlpools too?\p"
	.string "I could teach them the way of the Whirlpool!$"

YifuCity_EventScript_WhirlpoolTutor_Text_4:
	.string "Teach me the way!$"

YifuCity_EventScript_WhirlpoolTutor_Text_5:
	.string "Maybe later.$"

YifuCity_EventScript_WhirlpoolTutor_Text_6:
	.string "I see. The way of the Whirlpool hasn't\n"
	.string "made it into your heart yet.\p"
	.string "That's okay!$"

YifuCity_EventScript_WhirlpoolTutorTeachWhirlpool_Text_0:
	.string "Yes! Let's do this!\p"
	.string "Which Pokémon wants to learn\n"
	.string "Whirlpool?$"

YifuCity_EventScript_WhirlpoolTutorTeachWhirlpool_Text_1:
	.string "You can now watch your Pokémon make\n"
	.string "tiny whirlpools!\p"
	.string "You'll see, it's very relaxing.\p"
	.string "I'll take that Heart Scale you\n"
	.string "promised now, please and thank you!$"

YifuCity_EventScript_WhirlpoolTutorTeachWhirlpool_Text_2:
	.string "You can now watch your Pokémon make\n"
	.string "tiny whirlpools!\p"
	.string "You'll see, it's very relaxing.$"

Saku_EventScript_ForcePalmTutor_Text_0:
	.string "You want more Pokémon to develop\n"
	.string "strong hands, huh?\p"
	.string "I can teach them too, if you just\n"
	.string "bring me a Heart Scale!$"

Saku_EventScript_ForcePalmTutor_Text_1:
	.string "Want your Pokémon to have strong and\n"
	.string "forceful hands, too?\p"
	.string "I can teach them my Force Palm\n"
	.string "technique! What do you say?$"

Saku_EventScript_ForcePalmTutor_Text_2:
	.string "I need a hand!$"

Saku_EventScript_ForcePalmTutor_Text_3:
	.string "You're intimidated by Mama and Kuku's\n"
	.string "display of awesomeness, I get it.$"

YifuCity_EventScript_ForcePalmTutorTeachForcePalm_Text_0:
	.string "Heck yes!\nWhich Pokémon will receive this gift?$"

YifuCity_EventScript_ForcePalmTutorTeachForcePalm_Text_1:
	.string "Your Pokémon's hands are now almost\n"
	.string "as strong as Mama's and Kuku's!\p"
	.string "Now, we'd settled on a Heart Scale,\n"
	.string "right?$"

YifuCity_EventScript_ForcePalmTutorTeachForcePalm_Text_2:
	.string "Your Pokémon's hands are now almost\n"
	.string "as strong as Mama's and Kuku's!\p"
	.string "You'll join the Refuge building effort\n"
	.string "someday, right?$"

YifuCity_HotSprings_MapScripts::
	.byte 0


YifuCity_HotSprings_EventScript_OldWoman::
	trainerbattle_single TRAINER_SACHIKO, YifuCity_HotSprings_EventScript_OldWoman_Text_0, YifuCity_HotSprings_EventScript_OldWoman_Text_1
	setspeaker SP_NAME_OLD_LADY
	msgbox YifuCity_HotSprings_EventScript_OldWoman_Text_2, MSGBOX_AUTOCLOSE
	end


YifuCity_HotSprings_EventScript_OldWoman2::
	lock
	setspeaker SP_NAME_OLD_LADY
	playse SE_PIN
	applymovement LOCALID_HOT_SPRINGS_OLD_WOMAN_2, YifuCity_HotSprings_EventScript_OldWoman2_Movement_0
	msgbox YifuCity_HotSprings_EventScript_OldWoman2_Text_0
	closemessage
	release
	return


YifuCity_HotSprings_EventScript_HotSpringM::
	lock
	trainerbattle_single TRAINER_FUTOSHI, YifuCity_HotSprings_EventScript_HotSpringM_Text_0, YifuCity_HotSprings_EventScript_HotSpringM_Text_1
	setspeaker SP_NAME_HOT_SPRING_GUY
	msgbox YifuCity_HotSprings_EventScript_HotSpringM_Text_2, MSGBOX_AUTOCLOSE
	release
	return


YifuCity_HotSprings_EventScript_HotSpringF::
	lock
	trainerbattle_single TRAINER_WAKAE, YifuCity_HotSprings_EventScript_HotSpringF_Text_0, YifuCity_HotSprings_EventScript_HotSpringF_Text_1
	setspeaker SP_NAME_HOT_SPRING_GAL
	setnamedmon SPECIES_TORKOAL
	playse SE_PIN
	applymovement VAR_LAST_TALKED, YifuCity_HotSprings_EventScript_HotSpringF_Movement_0
	msgbox YifuCity_HotSprings_EventScript_HotSpringF_Text_2, MSGBOX_AUTOCLOSE
	release
	return


YifuCity_HotSprings_EventScript_Firebringer::
	lock
	trainerbattle_single TRAINER_LIHUO, YifuCity_HotSprings_EventScript_Firebringer_Text_0, YifuCity_HotSprings_EventScript_Firebringer_Text_1
	setspeaker SP_NAME_FIREBRINGER
	setnamedmon SPECIES_SLUGMA
	msgbox YifuCity_HotSprings_EventScript_Firebringer_Text_2, MSGBOX_AUTOCLOSE
	release
	return


YifuCity_HotSprings_EventScript_Torkoal::
	lock
	faceplayer
	setseenmon SPECIES_TORKOAL
	setspeakertomonname SPECIES_TORKOAL
	playmoncry SPECIES_TORKOAL, CRY_MODE_NORMAL
	msgbox YifuCity_HotSprings_EventScript_Torkoal_Text_0
	waitmoncry
	release
	return


YifuCity_HotSprings_EventScript_Slowpoke::
	lock
	faceplayer
	setseenmon SPECIES_SLOWPOKE
	setspeakertomonname SPECIES_SLOWPOKE
	playmoncry SPECIES_SLOWPOKE, CRY_MODE_NORMAL
	applymovement VAR_LAST_TALKED, YifuCity_HotSprings_EventScript_Slowpoke_Movement_0
	msgbox YifuCity_HotSprings_EventScript_Slowpoke_Text_0
	waitmoncry
	release
	return


YifuCity_HotSprings_EventScript_OldWoman2_Movement_0:
	emote_music
	step_end

YifuCity_HotSprings_EventScript_HotSpringF_Movement_0:
	emote_sweat
	step_end

YifuCity_HotSprings_EventScript_Slowpoke_Movement_0:
	emote_happy
	step_end

YifuCity_HotSprings_EventScript_OldWoman_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_UUME_OLD_WOMAN EMOTE_NORMAL}What do you mean, it burns?\n"
	.string "The water's barely warm!$"

YifuCity_HotSprings_EventScript_OldWoman_Text_1:
	.string "Ayo, what a burning defeat…$"

YifuCity_HotSprings_EventScript_OldWoman_Text_2:
	.string "{CREATE_MUGSHOT MUGSHOT_UUME_OLD_WOMAN EMOTE_NORMAL}My Pokémon need to relax a little.$"

YifuCity_HotSprings_EventScript_OldWoman2_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_UUME_OLD_WOMAN EMOTE_NORMAL}The scorching water is heaven for\n"
	.string "this old skin…$"

YifuCity_HotSprings_EventScript_HotSpringM_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_HOT_SPRING_F EMOTE_NORMAL}I come here to relax and show off my\n"
	.string "hot bod!$"

YifuCity_HotSprings_EventScript_HotSpringM_Text_1:
	.string "I take it you're not impressed?$"

YifuCity_HotSprings_EventScript_HotSpringM_Text_2:
	.string "{CREATE_MUGSHOT MUGSHOT_HOT_SPRING_F EMOTE_NORMAL}I wonder why girls never want to talk\n"
	.string "to me…$"

YifuCity_HotSprings_EventScript_HotSpringF_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_HOT_SPRING_F EMOTE_NORMAL}Don't talk to me! I forgot my towel!$"

YifuCity_HotSprings_EventScript_HotSpringF_Text_1:
	.string "Will you leave now?$"

YifuCity_HotSprings_EventScript_HotSpringF_Text_2:
	.string "{CREATE_MUGSHOT MUGSHOT_HOT_SPRING_F EMOTE_NORMAL}Maybe I can get that Torkoal to bring\n"
	.string "me a towel…$"

YifuCity_HotSprings_EventScript_Firebringer_Text_0:
	.string "Whew… Working the hot springs'\n"
	.string "furnace is hard!$"

YifuCity_HotSprings_EventScript_Firebringer_Text_1:
	.string "My Pokémon were already tired!$"

YifuCity_HotSprings_EventScript_Firebringer_Text_2:
	.string "Unlike Hanabi City's natural hot\n"
	.string "springs, this place operates on so\l"
	.string "many Slugma you wouldn't believe.$"

YifuCity_HotSprings_EventScript_Torkoal_Text_0:
	.string "Pschhhhhh…$"

YifuCity_HotSprings_EventScript_Slowpoke_Text_0:
	.string "Sloooo…$"

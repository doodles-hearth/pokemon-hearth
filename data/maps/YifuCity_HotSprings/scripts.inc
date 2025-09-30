YifuCity_HotSprings_MapScripts::
	.byte 0


YifuCity_HotSprings_EventScript_OldWoman::
	trainerbattle_single TRAINER_KODOMO, YifuCity_HotSprings_EventScript_OldWoman_Text_0, YifuCity_HotSprings_EventScript_OldWoman_Text_1
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
	trainerbattle_single TRAINER_KODOMO, YifuCity_HotSprings_EventScript_HotSpringM_Text_0, YifuCity_HotSprings_EventScript_OldWoman_Text_1
	setspeaker SP_NAME_HOT_SPRING_GAL
	msgbox YifuCity_HotSprings_EventScript_HotSpringM_Text_1, MSGBOX_AUTOCLOSE
	release
	return


YifuCity_HotSprings_EventScript_HotSpringF::
	lock
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


YifuCity_HotSprings_EventScript_OldWoman2_Movement_0:
	emote_music
	step_end

YifuCity_HotSprings_EventScript_OldWoman_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_UUME_OLD_WOMAN EMOTE_NORMAL}What do you mean, it burns?\n"
	.string "The water's barely warm!$"

YifuCity_HotSprings_EventScript_OldWoman_Text_1:
	.string "Ouchie, what a burning defeat…$"

YifuCity_HotSprings_EventScript_OldWoman_Text_2:
	.string "{CREATE_MUGSHOT MUGSHOT_UUME_OLD_WOMAN EMOTE_NORMAL}My Pokémon need to relax a little.$"

YifuCity_HotSprings_EventScript_OldWoman2_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_UUME_OLD_WOMAN EMOTE_NORMAL}The scorching water is heaven for\n"
	.string "this old skin…$"

YifuCity_HotSprings_EventScript_HotSpringM_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_HOT_SPRING_F EMOTE_NORMAL}What do you mean, it burns?\n"
	.string "The water's barely warm!$"

YifuCity_HotSprings_EventScript_HotSpringM_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_HOT_SPRING_F EMOTE_NORMAL}My Pokémon need to relax a little.$"

YifuCity_HotSprings_EventScript_Torkoal_Text_0:
	.string "Pschhhhhh…$"

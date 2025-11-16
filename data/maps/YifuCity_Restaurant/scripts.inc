YifuCity_Restaurant_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, YifuCity_Restaurant_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, YifuCity_Restaurant_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

YifuCity_Restaurant_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	getspeciesgfx VAR_STARTER_MON, VAR_OBJ_GFX_ID_0
	getnatsukistartermongfx VAR_OBJ_GFX_ID_1, 2
	compare VAR_HOTPOT_SCENE_STATE, 2
	goto_if_eq YifuCity_Restaurant_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_2
	return

YifuCity_Restaurant_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	return

YifuCity_Restaurant_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_HOTPOT_SCENE_STATE, 2, HotpotWithFriends
	.2byte 0


YifuCity_Restaurant_EventScript_UninspiredChef::
	lock
	applymovement VAR_LAST_TALKED, YifuCity_Restaurant_EventScript_UninspiredChef_Movement_0
	setspeaker SP_NAME_COOK
	msgbox YifuCity_Restaurant_EventScript_UninspiredChef_Text_0
	closemessage
	delay 48
	faceplayer
	setspeaker SP_NAME_COOK
	msgbox YifuCity_Restaurant_EventScript_UninspiredChef_Text_1
	applymovement VAR_LAST_TALKED, YifuCity_Restaurant_EventScript_UninspiredChef_Movement_1
	msgbox YifuCity_Restaurant_EventScript_UninspiredChef_Text_2
	closemessage
	release
	return


YifuCity_Restaurant_EventScript_RunningChef::
	lock
	faceplayer
	applymovement VAR_LAST_TALKED, YifuCity_Restaurant_EventScript_RunningChef_Movement_0
	setspeaker SP_NAME_COOK
	msgbox YifuCity_Restaurant_EventScript_RunningChef_Text_0
	closemessage
	release
	return


YifuCity_Restaurant_EventScript_LonelyGirl::
	lock
	faceplayer
	applymovement VAR_LAST_TALKED, YifuCity_Restaurant_EventScript_UninspiredChef_Movement_0
	setspeaker SP_NAME_GIRL
	msgbox YifuCity_Restaurant_EventScript_LonelyGirl_Text_0
	closemessage
	release
	return


YifuCity_Restaurant_EventScript_OldWomen::
	lock
	applymovement LOCALID_HOTPOT_OLD_WOMAN_1, YifuCity_Restaurant_EventScript_OldWomen_Movement_0
	waitmovement 0
	setspeaker SP_NAME_OLD_LADY
	msgbox YifuCity_Restaurant_EventScript_OldWomen_Text_0
	closemessage
	applymovement LOCALID_HOTPOT_OLD_WOMAN_2, YifuCity_Restaurant_EventScript_OldWomen_Movement_1
	waitmovement 0
	setspeaker SP_NAME_OLD_LADY
	msgbox YifuCity_Restaurant_EventScript_OldWomen_Text_1
	closemessage
	release
	return


YifuCity_Restaurant_EventScript_FatGuy::
	lock
	faceplayer
	setspeaker SP_NAME_GUY
	gettimeofday
	compare VAR_0x8000, TIME_LUNCHTIME
	goto_if_eq YifuCity_Restaurant_EventScript_FatGuy_2
	applymovement VAR_LAST_TALKED, YifuCity_Restaurant_EventScript_UninspiredChef_Movement_1
	msgbox YifuCity_Restaurant_EventScript_FatGuy_Text_1
YifuCity_Restaurant_EventScript_FatGuy_1:
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement VAR_LAST_TALKED
	closemessage
	release
	return

YifuCity_Restaurant_EventScript_FatGuy_2:
	msgbox YifuCity_Restaurant_EventScript_FatGuy_Text_0
	goto YifuCity_Restaurant_EventScript_FatGuy_1


YifuCity_Restaurant_EventScript_Munchlax::
	lock
	faceplayer
	setseenmon SPECIES_MUNCHLAX
	setspeakertomonname SPECIES_MUNCHLAX
	playmoncry SPECIES_MUNCHLAX, CRY_MODE_NORMAL
	msgbox YifuCity_Restaurant_EventScript_Munchlax_Text_0
	waitmoncry
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement VAR_LAST_TALKED
	release
	return


HotpotWithFriends:
	lockall
	call Hotpot_OrderedEverythingOnMenu
	fadescreen FADE_TO_BLACK
	turnobject LOCALID_HOTPOT_HARIKO, DIR_SOUTH
	playse SE_M_ACID_ARMOR
	message HotpotWithFriends_Text_0
	waitse
	waitmessage
	closemessage
	fadescreen FADE_FROM_BLACK
	call Hotpot_Slowpoke
	fadescreen FADE_TO_BLACK
	playse SE_M_ACID_ARMOR
	message HotpotWithFriends_Text_1
	waitse
	waitmessage
	closemessage
	fadescreen FADE_FROM_BLACK
	call Hotpot_Decay
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_HOTPOT_PLAYERS_MON
	removeobject LOCALID_HOTPOT_NATSUKIS_MON
	removeobject LOCALID_HOTPOT_SLOWPOKE
	setobjectxyperm OBJ_EVENT_ID_PLAYER, 7, 9
	setobjectxyperm LOCALID_HOTPOT_NATSUKI, 6, 10
	setobjectxyperm LOCALID_HOTPOT_HARIKO, 8, 10
	playse SE_M_ACID_ARMOR
	message HotpotWithFriends_Text_2
	waitse
	waitmessage
	closemessage
	fadescreen FADE_FROM_BLACK
	call Hotpot_End
	setvar VAR_HOTPOT_SCENE_STATE, 3
	warpsilent MAP_YIFU_CITY, 12
	releaseall
	return


Hotpot_OrderedEverythingOnMenu:
	delay 24
	applymovement LOCALID_HOTPOT_HARIKO, Hotpot_OrderedEverythingOnMenu_Movement_0
	waitmovement LOCALID_HOTPOT_HARIKO
	setspeaker SP_NAME_HARIKO
	msgbox Hotpot_OrderedEverythingOnMenu_Text_0
	applymovement LOCALID_HOTPOT_NATSUKI, YifuCity_Restaurant_EventScript_OldWomen_Movement_0
	setspeaker SP_NAME_NATSUKI
	msgbox Hotpot_OrderedEverythingOnMenu_Text_1
	applymovement LOCALID_HOTPOT_HARIKO, YifuCity_Restaurant_EventScript_OldWomen_Movement_1
	setspeaker SP_NAME_HARIKO
	msgbox Hotpot_OrderedEverythingOnMenu_Text_2
	applymovement LOCALID_HOTPOT_NATSUKI, Hotpot_OrderedEverythingOnMenu_Movement_1
	playse SE_LEDGE
	setspeaker SP_NAME_NATSUKI
	msgbox Hotpot_OrderedEverythingOnMenu_Text_3
	applymovement LOCALID_HOTPOT_HARIKO, Hotpot_OrderedEverythingOnMenu_Movement_2
	setspeaker SP_NAME_HARIKO
	msgbox Hotpot_OrderedEverythingOnMenu_Text_4
	applymovement LOCALID_HOTPOT_NATSUKI, YifuCity_Restaurant_EventScript_OldWomen_Movement_0
	setspeaker SP_NAME_NATSUKI
	msgbox Hotpot_OrderedEverythingOnMenu_Text_5
	closemessage
	return


Hotpot_Slowpoke:
	delay 24
	applymovement LOCALID_HOTPOT_NATSUKI, YifuCity_Restaurant_EventScript_OldWomen_Movement_0
	setspeaker SP_NAME_NATSUKI
	msgbox Hotpot_Slowpoke_Text_0
	applymovement LOCALID_HOTPOT_HARIKO, YifuCity_Restaurant_EventScript_OldWomen_Movement_1
	setspeaker SP_NAME_HARIKO
	msgbox Hotpot_Slowpoke_Text_1
	closemessage
	playmoncry SPECIES_SLOWPOKE, CRY_MODE_NORMAL
	applymovement LOCALID_HOTPOT_SLOWPOKE, Hotpot_Slowpoke_Movement_0
	applymovement LOCALID_HOTPOT_HARIKO, Hotpot_Slowpoke_Movement_1
	waitmovement LOCALID_HOTPOT_SLOWPOKE
	waitmoncry
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Hotpot_Slowpoke_Movement_2
	waitmovement OBJ_EVENT_ID_PLAYER
	setnamedmon SPECIES_SLOWPOKE
	setseenmon SPECIES_SLOWPOKE
	setdescribedmon SPECIES_SLOWPOKE
	applymovement LOCALID_HOTPOT_NATSUKI, Hotpot_Slowpoke_Movement_3
	setspeaker SP_NAME_NATSUKI
	msgbox Hotpot_Slowpoke_Text_2
	mcdialogue Hotpot_Slowpoke_Text_3, Hotpot_Slowpoke_Text_4
	playse SE_PIN
	applymovement LOCALID_HOTPOT_HARIKO, Hotpot_Slowpoke_Movement_4
	applymovement LOCALID_HOTPOT_NATSUKI, Hotpot_Slowpoke_Movement_5
	waitmovement LOCALID_HOTPOT_HARIKO
	setspeaker SP_NAME_HARIKO
	msgbox Hotpot_Slowpoke_Text_5
	playse SE_LEDGE
	applymovement LOCALID_HOTPOT_HARIKO, Hotpot_Slowpoke_Movement_0
	msgbox Hotpot_Slowpoke_Text_6
	applymovement LOCALID_HOTPOT_NATSUKI, YifuCity_Restaurant_EventScript_OldWomen_Movement_0
	applymovement LOCALID_HOTPOT_NATSUKI, Hotpot_Slowpoke_Movement_6
	setspeaker SP_NAME_NATSUKI
	msgbox Hotpot_Slowpoke_Text_7
	closemessage
	applymovement LOCALID_HOTPOT_NATSUKI, Hotpot_Slowpoke_Movement_7
	waitmovement LOCALID_HOTPOT_NATSUKI
	applymovement LOCALID_HOTPOT_HARIKO, Hotpot_Slowpoke_Movement_8
	setspeaker SP_NAME_HARIKO
	msgbox Hotpot_Slowpoke_Text_8
	closemessage
	return


Hotpot_Decay:
	delay 24
	applymovement LOCALID_HOTPOT_NATSUKI, YifuCity_Restaurant_EventScript_OldWomen_Movement_0
	setspeaker SP_NAME_NATSUKI
	msgbox Hotpot_Decay_Text_0
	applymovement LOCALID_HOTPOT_HARIKO, Hotpot_Decay_Movement_0
	setspeaker SP_NAME_HARIKO
	msgbox Hotpot_Decay_Text_1
	applymovement LOCALID_HOTPOT_NATSUKI, YifuCity_Restaurant_EventScript_OldWomen_Movement_0
	setspeaker SP_NAME_NATSUKI
	msgbox Hotpot_Decay_Text_2
	mcdialogue Hotpot_Decay_Text_3, Hotpot_Decay_Text_4, Hotpot_Decay_Text_5
	closemessage
	switch VAR_RESULT
	case 0, Hotpot_Decay_3
	case 1, Hotpot_Decay_4
	case 2, Hotpot_Decay_5
Hotpot_Decay_1:
	closemessage
	return

Hotpot_Decay_3:
	applymovement LOCALID_HOTPOT_NATSUKI, YifuCity_Restaurant_EventScript_OldWomen_Movement_0
	setspeaker SP_NAME_NATSUKI
	msgbox Hotpot_Decay_Text_6
	applymovement LOCALID_HOTPOT_HARIKO, Hotpot_Decay_Movement_1
	setspeaker SP_NAME_HARIKO
	msgbox Hotpot_Decay_Text_7
	applymovement LOCALID_HOTPOT_NATSUKI, YifuCity_Restaurant_EventScript_OldWomen_Movement_0
	setspeaker SP_NAME_NATSUKI
	msgbox Hotpot_Decay_Text_8
	applymovement LOCALID_HOTPOT_HARIKO, YifuCity_Restaurant_EventScript_OldWomen_Movement_1
	setspeaker SP_NAME_HARIKO
	msgbox Hotpot_Decay_Text_9
	applymovement LOCALID_HOTPOT_NATSUKI, YifuCity_Restaurant_EventScript_OldWomen_Movement_0
	setspeaker SP_NAME_NATSUKI
	msgbox Hotpot_Decay_Text_10
	applymovement LOCALID_HOTPOT_HARIKO, YifuCity_Restaurant_EventScript_OldWomen_Movement_1
	setspeaker SP_NAME_HARIKO
	msgbox Hotpot_Decay_Text_11
	goto Hotpot_Decay_1

Hotpot_Decay_4:
	applymovement LOCALID_HOTPOT_NATSUKI, YifuCity_Restaurant_EventScript_OldWomen_Movement_0
	setspeaker SP_NAME_NATSUKI
	msgbox Hotpot_Decay_Text_12
	applymovement LOCALID_HOTPOT_HARIKO, Hotpot_Decay_Movement_1
	setspeaker SP_NAME_HARIKO
	msgbox Hotpot_Decay_Text_7
	applymovement LOCALID_HOTPOT_NATSUKI, YifuCity_Restaurant_EventScript_OldWomen_Movement_0
	setspeaker SP_NAME_NATSUKI
	msgbox Hotpot_Decay_Text_8
	applymovement LOCALID_HOTPOT_HARIKO, YifuCity_Restaurant_EventScript_OldWomen_Movement_1
	setspeaker SP_NAME_HARIKO
	msgbox Hotpot_Decay_Text_9
	applymovement LOCALID_HOTPOT_NATSUKI, YifuCity_Restaurant_EventScript_OldWomen_Movement_0
	setspeaker SP_NAME_NATSUKI
	msgbox Hotpot_Decay_Text_10
	applymovement LOCALID_HOTPOT_HARIKO, YifuCity_Restaurant_EventScript_OldWomen_Movement_1
	setspeaker SP_NAME_HARIKO
	msgbox Hotpot_Decay_Text_11
	goto Hotpot_Decay_1

Hotpot_Decay_5:
	applymovement LOCALID_HOTPOT_NATSUKI, YifuCity_Restaurant_EventScript_OldWomen_Movement_0
	setspeaker SP_NAME_NATSUKI
	msgbox Hotpot_Decay_Text_13
	applymovement LOCALID_HOTPOT_HARIKO, YifuCity_Restaurant_EventScript_UninspiredChef_Movement_0
	setspeaker SP_NAME_HARIKO
	msgbox Hotpot_Decay_Text_14
	goto Hotpot_Decay_1


Hotpot_End:
	delay 24
	applymovement LOCALID_HOTPOT_NATSUKI, Hotpot_End_Movement_0
	setspeaker SP_NAME_NATSUKI
	msgbox Hotpot_End_Text_0
	applymovement LOCALID_HOTPOT_HARIKO, YifuCity_Restaurant_EventScript_OldWomen_Movement_1
	setspeaker SP_NAME_HARIKO
	msgbox Hotpot_End_Text_1
	return


YifuCity_Restaurant_EventScript_LittleBoy::
	lock
	faceplayer
	msgbox YifuCity_Restaurant_EventScript_LittleBoy_Text_0
	closemessage
	applymovement VAR_LAST_TALKED, YifuCity_Restaurant_EventScript_LittleBoy_Movement_0
	waitmovement 0
	release
	end


YifuCity_Restaurant_EventScript_LittleBoy2::
	lock
	faceplayer
	msgbox YifuCity_Restaurant_EventScript_LittleBoy2_Text_0
	applymovement VAR_LAST_TALKED, YifuCity_Restaurant_EventScript_LittleBoy2_Movement_0
	msgbox YifuCity_Restaurant_EventScript_LittleBoy2_Text_1
	waitmovement VAR_LAST_TALKED
	closemessage
	applymovement VAR_LAST_TALKED, YifuCity_Restaurant_EventScript_LittleBoy_Movement_0
	waitmovement 0
	release
	end


YifuCity_Restaurant_EventScript_OldMan::
	lock
	applymovement VAR_LAST_TALKED, YifuCity_Restaurant_EventScript_OldWomen_Movement_1
	msgbox YifuCity_Restaurant_EventScript_OldMan_Text_0
	closemessage
	release
	end


YifuCity_Restaurant_EventScript_UninspiredChef_Movement_0:
	emote_pensive
	step_end

YifuCity_Restaurant_EventScript_UninspiredChef_Movement_1:
	emote_sad
	step_end

YifuCity_Restaurant_EventScript_RunningChef_Movement_0:
	emote_sweat
	step_end

YifuCity_Restaurant_EventScript_OldWomen_Movement_0:
	walk_in_place_fast_right
	step_end

YifuCity_Restaurant_EventScript_OldWomen_Movement_1:
	walk_in_place_fast_left
	step_end

Hotpot_OrderedEverythingOnMenu_Movement_0:
	walk_down
	walk_left
	step_end

Hotpot_OrderedEverythingOnMenu_Movement_1:
	jump_in_place_right
	emote_sweat
	step_end

Hotpot_OrderedEverythingOnMenu_Movement_2:
	face_right
	emote_pensive
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_left
	step_end

Hotpot_Slowpoke_Movement_0:
	jump_in_place_left
	step_end

Hotpot_Slowpoke_Movement_1:
	face_down
	step_end

Hotpot_Slowpoke_Movement_2:
	emote_pensive
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

Hotpot_Slowpoke_Movement_3:
	walk_in_place_fast_up
	step_end

Hotpot_Slowpoke_Movement_4:
	face_left
	emote_question_mark
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

Hotpot_Slowpoke_Movement_5:
	face_right
	step_end

Hotpot_Slowpoke_Movement_6:
	emote_happy
	step_end

Hotpot_Slowpoke_Movement_7:
	lock_facing_direction
	lock_anim
	walk_fast_right
	walk_fast_left
	unlock_facing_direction
	unlock_anim
	step_end

Hotpot_Slowpoke_Movement_8:
	delay_16
	delay_16
	walk_in_place_fast_down
	step_end

Hotpot_Decay_Movement_0:
	walk_in_place_fast_left
	emote_pensive
	step_end

Hotpot_Decay_Movement_1:
	face_down
	emote_pensive
	step_end

Hotpot_End_Movement_0:
	walk_in_place_fast_right
	emote_sweat
	step_end

YifuCity_Restaurant_EventScript_LittleBoy_Movement_0:
	face_original_direction
	step_end

YifuCity_Restaurant_EventScript_LittleBoy2_Movement_0:
	shake_horizontal
	step_end

YifuCity_Restaurant_EventScript_UninspiredChef_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_COOK EMOTE_NORMAL}Hmm… No, that's not it…$"

YifuCity_Restaurant_EventScript_UninspiredChef_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_COOK EMOTE_NORMAL}You don't happen to be a culinary\n"
	.string "connoisseur, do you?\p"
	.string "What kids nowadays refer to as a\n"
	.string "“foodie”?\p"
	.string "You see, cooking was my passion. But\n"
	.string "lately I've been… uninspired!$"

YifuCity_Restaurant_EventScript_UninspiredChef_Text_2:
	.string "{CREATE_MUGSHOT MUGSHOT_COOK EMOTE_NORMAL}It's a tragedy! I desperately seek\n"
	.string "fresh, bold new recipes!\p"
	.string "If you come across interesting\n"
	.string "recipes during your travels… Come\l"
	.string "back here and tell me about them!\p"
	.string "I'll make it worth your while!$"

YifuCity_Restaurant_EventScript_RunningChef_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_COOK EMOTE_NORMAL}Huff… Huff…\n"
	.string "I wish my colleague would stop whining\l"
	.string "and get back to helping me…$"

YifuCity_Restaurant_EventScript_LonelyGirl_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_UUME_GIRL_2 EMOTE_NORMAL}I'm waiting for my date, but it seems\n"
	.string "he's late yet again…$"

YifuCity_Restaurant_EventScript_OldWomen_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_UUME_OLD_WOMAN EMOTE_NORMAL}Psst psst mumble gossip…$"

YifuCity_Restaurant_EventScript_OldWomen_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_UUME_OLD_WOMAN EMOTE_NORMAL}Gossip gossip…\n"
	.string "Ho ho ho…$"

YifuCity_Restaurant_EventScript_FatGuy_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_UUME_FAT_GUY EMOTE_NORMAL}Chomp…\n"
	.string "Just gett'n a head start on lunch…\p"
	.string "{FONT_SMALL}Burp…{FONT_NORMAL} Ahem.\n"
	.string "If you'll excuse me.$"

YifuCity_Restaurant_EventScript_FatGuy_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_UUME_FAT_GUY EMOTE_NORMAL}UHHHHG I ate too much…$"

YifuCity_Restaurant_EventScript_Munchlax_Text_0:
	.string "Chomp… Gulp!$"

HotpotWithFriends_Text_0:
	.string "The broth bubbles gently.$"

HotpotWithFriends_Text_1:
	.string "Fragrant Berry leaves arise to the\n"
	.string "surface.$"

HotpotWithFriends_Text_2:
	.string "You finally see the bottom of the pan.$"

Hotpot_OrderedEverythingOnMenu_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_HARIKO EMOTE_NORMAL}I was not sure what you two usually\n"
	.string "eat, so I ordered everything.$"

Hotpot_OrderedEverythingOnMenu_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_NATSUKI EMOTE_NORMAL}Everything? As in, every item on the\n"
	.string "menu?$"

Hotpot_OrderedEverythingOnMenu_Text_2:
	.string "{CREATE_MUGSHOT MUGSHOT_HARIKO EMOTE_NORMAL}Ah, yes. You did say you were going to\n"
	.string "have “some of everything”, correct?$"

Hotpot_OrderedEverythingOnMenu_Text_3:
	.string "{CREATE_MUGSHOT MUGSHOT_NATSUKI EMOTE_NORMAL}That- That's not a thing normal\n"
	.string "people do, Hariko!$"

Hotpot_OrderedEverythingOnMenu_Text_4:
	.string "{CREATE_MUGSHOT MUGSHOT_HARIKO EMOTE_NORMAL}You know, other people often tell me\n"
	.string "that.$"

Hotpot_OrderedEverythingOnMenu_Text_5:
	.string "{CREATE_MUGSHOT MUGSHOT_NATSUKI EMOTE_NORMAL}Well gee, I sure wonder why…$"

Hotpot_Slowpoke_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_NATSUKI EMOTE_NORMAL}Chomp, chomp…\n"
	.string "What does a Slowpoke even eat?$"

Hotpot_Slowpoke_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_HARIKO EMOTE_NORMAL}Mainly shellfish, but did you know\n"
	.string "they aren't very good hunters?\p"
	.string "Luckily for them, they have a very\n"
	.string "slow metabolism.$"

Hotpot_Slowpoke_Text_2:
	.string "{CREATE_MUGSHOT MUGSHOT_NATSUKI EMOTE_NORMAL}Whatcha doing, {PLAYER}?$"

Hotpot_Slowpoke_Text_3:
	.string "Filling my PokéDex!$"

Hotpot_Slowpoke_Text_4:
	.string "Writing about Slowpoke!$"

Hotpot_Slowpoke_Text_5:
	.string "{CREATE_MUGSHOT MUGSHOT_HARIKO EMOTE_NORMAL}A PokéDex?$"

Hotpot_Slowpoke_Text_6:
	.string "You two are writing a Pokémon\n"
	.string "encyclopedia?!$"

Hotpot_Slowpoke_Text_7:
	.string "{CREATE_MUGSHOT MUGSHOT_NATSUKI EMOTE_NORMAL}Yeah, here, have a look at mine!$"

Hotpot_Slowpoke_Text_8:
	.string "{CREATE_MUGSHOT MUGSHOT_HARIKO EMOTE_NORMAL}That's… That's amazing!\n"
	.string "So many useful notes…\p"
	.string "Wow, you draw really well, Natsuki…$"

Hotpot_Decay_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_NATSUKI EMOTE_NORMAL}I heard rumors the Decay' spreading\n"
	.string "again in Uume Forest, west of here.$"

Hotpot_Decay_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_HARIKO EMOTE_NORMAL}I wonder what it is.\n"
	.string "It feels unnatural…$"

Hotpot_Decay_Text_2:
	.string "{CREATE_MUGSHOT MUGSHOT_NATSUKI EMOTE_NORMAL}You mean… Someone could be behind\n"
	.string "this mess?\p"
	.string "Who'd do something like this?$"

Hotpot_Decay_Text_3:
	.string "The Crobat Shadows?$"

Hotpot_Decay_Text_4:
	.string "The New Moon Order?$"

Hotpot_Decay_Text_5:
	.string "Entei?$"

Hotpot_Decay_Text_6:
	.string "{CREATE_MUGSHOT MUGSHOT_NATSUKI EMOTE_NORMAL}That bunch is definitely up to no\n"
	.string "good…\p"
	.string "They strike me as dumb more than evil,\n"
	.string "but we ought to keep an eye on them!$"

Hotpot_Decay_Text_7:
	.string "{CREATE_MUGSHOT MUGSHOT_HARIKO EMOTE_NORMAL}…$"

Hotpot_Decay_Text_8:
	.string "{CREATE_MUGSHOT MUGSHOT_NATSUKI EMOTE_NORMAL}You okay there, Hariko?\n"
	.string "Why the long face?$"

Hotpot_Decay_Text_9:
	.string "{CREATE_MUGSHOT MUGSHOT_HARIKO EMOTE_NORMAL}I just- I hope Entei is alright…$"

Hotpot_Decay_Text_10:
	.string "{CREATE_MUGSHOT MUGSHOT_NATSUKI EMOTE_NORMAL}What do you mean?$"

Hotpot_Decay_Text_11:
	.string "{CREATE_MUGSHOT MUGSHOT_HARIKO EMOTE_NORMAL}Well, Mt Kazan has been grumbling,\n"
	.string "after all.\p"
	.string "Let us hope it doesn't erupt like in\n"
	.string "the old legend…$"

Hotpot_Decay_Text_12:
	.string "{CREATE_MUGSHOT MUGSHOT_NATSUKI EMOTE_NORMAL}What are you on about, {PLAYER}?\p"
	.string "You know I wanna become a Samurai\n"
	.string "someday!\l"
	.string "They've been protecting us forever!$"

Hotpot_Decay_Text_13:
	.string "{CREATE_MUGSHOT MUGSHOT_NATSUKI EMOTE_NORMAL}But… Entei is the spirit of the island!\p"
	.string "Why would he do something like this?$"

Hotpot_Decay_Text_14:
	.string "{CREATE_MUGSHOT MUGSHOT_HARIKO EMOTE_NORMAL}Maybe Entei is mad, or hurt…\p"
	.string "Mt Kazan has been grumbling, after\n"
	.string "all.\p"
	.string "Let us hope it doesn't erupt like in\n"
	.string "the old legend…$"

Hotpot_End_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_NATSUKI EMOTE_NORMAL}Man, I think I ate too much…$"

Hotpot_End_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_HARIKO EMOTE_NORMAL}This was very fun.\n"
	.string "I am glad to have you two as friends.$"

YifuCity_Restaurant_EventScript_LittleBoy_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_UUME_LITTLE_BOY EMOTE_NORMAL}{SPEAKER NAME_LITTLE_BOY}I saw it! I saw that black oozing\n"
	.string "stuff in the Forest!\p"
	.string "What is that thing?!$"

YifuCity_Restaurant_EventScript_LittleBoy2_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_UUME_LITTLE_BOY EMOTE_NORMAL}{SPEAKER NAME_LITTLE_BOY} My brother dared me to go into the\n"
	.string "Forest alone!\p"
	.string "Huh? Yeah, of COURSE I did!\n"
	.string "I'm not a wimp!$"

YifuCity_Restaurant_EventScript_LittleBoy2_Text_1:
	.string "{FONT_SMALL}(Shiver shiver…){FONT_NORMAL}$"

YifuCity_Restaurant_EventScript_OldMan_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_UUME_OLD_MAN EMOTE_NORMAL}{SPEAKER NAME_OLD_MAN} Stop telling your brother these\n"
	.string "silly stories!\p"
	.string "If he has nightmares and wets the\n"
	.string "bed, I'll make you clean up!$"

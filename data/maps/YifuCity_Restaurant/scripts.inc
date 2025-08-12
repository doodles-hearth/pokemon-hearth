YifuCity_Restaurant_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, YifuCity_Restaurant_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, YifuCity_Restaurant_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

YifuCity_Restaurant_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	compare VAR_HOTPOT_SCENE_STATE, 2
	goto_if_eq YifuCity_Restaurant_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	setflag FLAG_TEMP_1
	return

YifuCity_Restaurant_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	return

YifuCity_Restaurant_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_HOTPOT_SCENE_STATE, 2, HotpotWithFriends
	.2byte 0


YifuCity_Restaurant_EventScript_UninspiredChef::
	lock
	speakername YifuCity_Restaurant_EventScript_UninspiredChef_Text_0
	msgbox YifuCity_Restaurant_EventScript_UninspiredChef_Text_1
	closemessage
	delay 48
	faceplayer
	speakername YifuCity_Restaurant_EventScript_UninspiredChef_Text_0
	msgbox YifuCity_Restaurant_EventScript_UninspiredChef_Text_2
	closemessage
	release
	return


YifuCity_Restaurant_EventScript_RunningChef::
	lock
	faceplayer
	speakername YifuCity_Restaurant_EventScript_UninspiredChef_Text_0
	msgbox YifuCity_Restaurant_EventScript_RunningChef_Text_0
	closemessage
	release
	return


YifuCity_Restaurant_EventScript_LonelyGirl::
	lock
	faceplayer
	speakername YifuCity_Restaurant_EventScript_LonelyGirl_Text_0
	msgbox YifuCity_Restaurant_EventScript_LonelyGirl_Text_1
	closemessage
	release
	return


YifuCity_Restaurant_EventScript_OldWomen::
	lock
	applymovement LOCALID_HOTPOT_OLD_WOMAN_1, YifuCity_Restaurant_EventScript_OldWomen_Movement_0
	waitmovement 0
	speakername YifuCity_Restaurant_EventScript_OldWomen_Text_0
	msgbox YifuCity_Restaurant_EventScript_OldWomen_Text_1
	closemessage
	applymovement LOCALID_HOTPOT_OLD_WOMAN_2, YifuCity_Restaurant_EventScript_OldWomen_Movement_1
	waitmovement 0
	speakername YifuCity_Restaurant_EventScript_OldWomen_Text_0
	msgbox YifuCity_Restaurant_EventScript_OldWomen_Text_2
	closemessage
	release
	return


YifuCity_Restaurant_EventScript_FatGuy::
	lock
	faceplayer
	speakername YifuCity_Restaurant_EventScript_FatGuy_Text_0
	gettimeofday
	compare VAR_0x8000, TIME_LUNCHTIME
	goto_if_eq YifuCity_Restaurant_EventScript_FatGuy_2
	msgbox YifuCity_Restaurant_EventScript_FatGuy_Text_2
YifuCity_Restaurant_EventScript_FatGuy_1:
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement VAR_LAST_TALKED
	closemessage
	release
	return

YifuCity_Restaurant_EventScript_FatGuy_2:
	msgbox YifuCity_Restaurant_EventScript_FatGuy_Text_1
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
	return


YifuCity_Restaurant_EventScript_OldWomen_Movement_0:
	walk_in_place_fast_right
	step_end

YifuCity_Restaurant_EventScript_OldWomen_Movement_1:
	walk_in_place_fast_left
	step_end

YifuCity_Restaurant_EventScript_UninspiredChef_Text_0:
	.string "Cook$"

YifuCity_Restaurant_EventScript_UninspiredChef_Text_1:
	.string "Hmm… No, that's not it…$"

YifuCity_Restaurant_EventScript_UninspiredChef_Text_2:
	.string "You don't happen to be a culinary\n"
	.string "connoisseur, do you?\p"
	.string "What kids nowadays refer to as a\n"
	.string "“foodie”?\p"
	.string "You see, cooking used to be my\n"
	.string "passion. But lately I've been feeling…\l"
	.string "uninspired!\p"
	.string "It's a tragedy! I desperately seek\n"
	.string "fresh, bold new recipes!\p"
	.string "Say, if you come across interesting\n"
	.string "recipes during your travels… Would\l"
	.string "you mind coming back here and tell me\l"
	.string "about them?\p"
	.string "I'll make it worth your while!$"

YifuCity_Restaurant_EventScript_RunningChef_Text_0:
	.string "Huff… Huff…\n"
	.string "I wish my colleague would stop whining\l"
	.string "and get back to helping me…$"

YifuCity_Restaurant_EventScript_LonelyGirl_Text_0:
	.string "Girl$"

YifuCity_Restaurant_EventScript_LonelyGirl_Text_1:
	.string "I'm waiting for my date, but it seems\n"
	.string "he's late yet again…$"

YifuCity_Restaurant_EventScript_OldWomen_Text_0:
	.string "Old Woman$"

YifuCity_Restaurant_EventScript_OldWomen_Text_1:
	.string "Psst psst mumble gossip…$"

YifuCity_Restaurant_EventScript_OldWomen_Text_2:
	.string "Gossip gossip…\n"
	.string "Ho ho ho…$"

YifuCity_Restaurant_EventScript_FatGuy_Text_0:
	.string "Guy$"

YifuCity_Restaurant_EventScript_FatGuy_Text_1:
	.string "Chomp…\n"
	.string "Just gett'n a head start on lunch…\p"
	.string "{FONT_SMALL}Burp…{FONT_NORMAL} Ahem.\n"
	.string "If you'll excuse me.$"

YifuCity_Restaurant_EventScript_FatGuy_Text_2:
	.string "UHHHHG I ate too much…$"

YifuCity_Restaurant_EventScript_Munchlax_Text_0:
	.string "Chomp… Gulp!$"

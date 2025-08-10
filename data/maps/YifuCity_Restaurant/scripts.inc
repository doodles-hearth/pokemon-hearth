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
	getnatsukistartermongfx VAR_OBJ_GFX_ID_0
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
	speakername YifuCity_Restaurant_EventScript_UninspiredChef_Text_0
	faceplayer
	msgbox YifuCity_Restaurant_EventScript_RunningChef_Text_0
	return


HotpotWithFriends:
	lockall
	releaseall
	return


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

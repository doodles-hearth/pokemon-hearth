YifuCity_Onsen_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, YifuCity_Onsen_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

YifuCity_Onsen_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto_if_set FLAG_PAID_HOT_SPRINGS, YifuCity_Onsen_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return

YifuCity_Onsen_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	setobjectxyperm LOCALID_HOT_SPRINGS_OWNER, 2, 2
	return


YifuCity_Onsen_EventScript_Owner::
	lock
	faceplayer
	goto_if_set FLAG_PAID_HOT_SPRINGS, YifuCity_Onsen_EventScript_Owner_2
	setspeaker SP_NAME_OWNER
	msgbox YifuCity_Onsen_EventScript_Owner_Text_1
	showmoneybox 18, 0
	checkmoney 500
	compare VAR_RESULT, 0
	goto_if_ne YifuCity_Onsen_EventScript_Owner_5
	mcdialogue YifuCity_Onsen_EventScript_Owner_Text_5
	closemessage
	hidemoneybox
	setspeaker SP_NAME_OWNER
	msgbox YifuCity_Onsen_EventScript_Owner_Text_6
	closemessage
YifuCity_Onsen_EventScript_Owner_1:
	release
	return

YifuCity_Onsen_EventScript_Owner_2:
	setspeaker SP_NAME_OWNER
	msgbox YifuCity_Onsen_EventScript_Owner_Text_0
	closemessage
	goto YifuCity_Onsen_EventScript_Owner_1

YifuCity_Onsen_EventScript_Owner_5:
	mcdialogue YifuCity_Onsen_EventScript_Owner_Text_2, YifuCity_Onsen_EventScript_Owner_Text_3
	closemessage
	switch VAR_RESULT
	case 0, YifuCity_Onsen_EventScript_Owner_9
	case 1, YifuCity_Onsen_EventScript_Owner_10
	goto YifuCity_Onsen_EventScript_Owner_1

YifuCity_Onsen_EventScript_Owner_9:
	playse SE_SHOP
	removemoney 500
	updatemoneybox
	closemessage
	hidemoneybox
	setflag FLAG_PAID_HOT_SPRINGS
	compare VAR_FACING, DIR_WEST
	goto_if_eq YifuCity_Onsen_EventScript_Owner_12
	applymovement VAR_LAST_TALKED, YifuCity_Onsen_EventScript_Owner_Movement_1
YifuCity_Onsen_EventScript_Owner_11:
	waitmovement 0
	setspeaker SP_NAME_OWNER
	msgbox YifuCity_Onsen_EventScript_Owner_Text_0
	closemessage
	goto YifuCity_Onsen_EventScript_Owner_1

YifuCity_Onsen_EventScript_Owner_10:
	hidemoneybox
	setspeaker SP_NAME_OWNER
	msgbox YifuCity_Onsen_EventScript_Owner_Text_4
	closemessage
	goto YifuCity_Onsen_EventScript_Owner_1

YifuCity_Onsen_EventScript_Owner_12:
	applymovement VAR_LAST_TALKED, YifuCity_Onsen_EventScript_Owner_Movement_0
	goto YifuCity_Onsen_EventScript_Owner_11


YifuCity_Onsen_EventScript_Owner_Movement_0:
	walk_slow_left
	face_down
	step_end

YifuCity_Onsen_EventScript_Owner_Movement_1:
	walk_slow_right
	face_down
	step_end

YifuCity_Onsen_EventScript_Owner_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_HOT_OLD_WOMAN EMOTE_NORMAL}Enjoy the hot springs!$"

YifuCity_Onsen_EventScript_Owner_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_HOT_OLD_WOMAN EMOTE_NORMAL}You can access the hot springs for\n"
	.string "the day for ¥500.\p"
	.string "Be careful though, some bathers are\n"
	.string "there to relax, some to battle!$"

YifuCity_Onsen_EventScript_Owner_Text_2:
	.string "One entry!$"

YifuCity_Onsen_EventScript_Owner_Text_3:
	.string "No, thanks.$"

YifuCity_Onsen_EventScript_Owner_Text_4:
	.string "{CREATE_MUGSHOT MUGSHOT_HOT_OLD_WOMAN EMOTE_NORMAL}Sure, sure.$"

YifuCity_Onsen_EventScript_Owner_Text_5:
	.string "I don't have enough…$"

YifuCity_Onsen_EventScript_Owner_Text_6:
	.string "{CREATE_MUGSHOT MUGSHOT_HOT_OLD_WOMAN EMOTE_NORMAL}Sorry but I run a business, not a\n"
	.string "charity.$"

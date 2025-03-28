BelvedereRoute_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BelvedereRoute_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

BelvedereRoute_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
	map_script_2 VAR_TEMP_0, 0, BelvedereRoute_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0
	.2byte 0

BelvedereRoute_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0:
	goto_if_unset FLAG_HIDE_LOST_MAREEP_1, BelvedereRoute_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_2
BelvedereRoute_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_1:
	goto_if_unset FLAG_HIDE_LOST_MAREEP_2, BelvedereRoute_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_5
BelvedereRoute_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_4:
	goto_if_unset FLAG_HIDE_LOST_MAREEP_3, BelvedereRoute_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_8
BelvedereRoute_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_7:
	goto_if_unset FLAG_HIDE_LOST_MAREEP_4, BelvedereRoute_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_11
BelvedereRoute_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_10:
	goto_if_unset FLAG_HIDE_LOST_MAREEP_5, BelvedereRoute_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_13
	return

BelvedereRoute_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_2:
	removeobject 6
	goto BelvedereRoute_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_1

BelvedereRoute_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_5:
	removeobject 7
	goto BelvedereRoute_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_4

BelvedereRoute_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_8:
	removeobject 8
	goto BelvedereRoute_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_7

BelvedereRoute_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_11:
	removeobject 9
	goto BelvedereRoute_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_10

BelvedereRoute_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_13:
	removeobject 10
	return


BelvedereRoute_EventScript_FindMareep::
	lock
	faceplayer
	setseenmon SPECIES_MAREEP
	playmoncry SPECIES_MAREEP, CRY_MODE_NORMAL
	msgbox BelvedereRoute_EventScript_FindMareep_Text_0
	closemessage
	compare VAR_QUEST_MAREEP_STATE, 0
	goto_if_gt BelvedereRoute_EventScript_FindMareep_2
BelvedereRoute_EventScript_FindMareep_1:
	release
	return

BelvedereRoute_EventScript_FindMareep_2:
	removeobject VAR_LAST_TALKED
	switch VAR_LAST_TALKED
	case 1, BelvedereRoute_EventScript_FindMareep_6
	case 2, BelvedereRoute_EventScript_FindMareep_7
	case 3, BelvedereRoute_EventScript_FindMareep_8
	case 4, BelvedereRoute_EventScript_FindMareep_9
	case 5, BelvedereRoute_EventScript_FindMareep_10
BelvedereRoute_EventScript_FindMareep_4:
	addvar VAR_QUEST_MAREEP_STATE, 1
	goto BelvedereRoute_EventScript_FindMareep_1

BelvedereRoute_EventScript_FindMareep_6:
	setflag FLAG_HIDE_LOST_MAREEP_1
	addobject 6
	goto BelvedereRoute_EventScript_FindMareep_4

BelvedereRoute_EventScript_FindMareep_7:
	setflag FLAG_HIDE_LOST_MAREEP_2
	addobject 7
	goto BelvedereRoute_EventScript_FindMareep_4

BelvedereRoute_EventScript_FindMareep_8:
	setflag FLAG_HIDE_LOST_MAREEP_3
	addobject 8
	goto BelvedereRoute_EventScript_FindMareep_4

BelvedereRoute_EventScript_FindMareep_9:
	setflag FLAG_HIDE_LOST_MAREEP_4
	addobject 9
	goto BelvedereRoute_EventScript_FindMareep_4

BelvedereRoute_EventScript_FindMareep_10:
	setflag FLAG_HIDE_LOST_MAREEP_5
	addobject 10
	goto BelvedereRoute_EventScript_FindMareep_4


BelvedereRoute_EventScript_Rancher::
	lock
	faceplayer
	switch VAR_QUEST_MAREEP_STATE
	case 0, BelvedereRoute_EventScript_Rancher_3
	case 1, BelvedereRoute_EventScript_Rancher_4
	case 2, BelvedereRoute_EventScript_Rancher_5
	case 3, BelvedereRoute_EventScript_Rancher_6
	case 4, BelvedereRoute_EventScript_Rancher_7
	case 5, BelvedereRoute_EventScript_Rancher_8
	case 6, BelvedereRoute_EventScript_Rancher_9
	case 7, BelvedereRoute_EventScript_Rancher_10
BelvedereRoute_EventScript_Rancher_1:
	release
	return

BelvedereRoute_EventScript_Rancher_3:
	msgbox BelvedereRoute_EventScript_Rancher_Text_0, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, BelvedereRoute_EventScript_Rancher_12
	case NO, BelvedereRoute_EventScript_Rancher_13
	case MULTI_B_PRESSED, BelvedereRoute_EventScript_Rancher_14
	goto BelvedereRoute_EventScript_Rancher_1

BelvedereRoute_EventScript_Rancher_4:
	msgbox BelvedereRoute_EventScript_Rancher_Text_3
	goto BelvedereRoute_EventScript_Rancher_1

BelvedereRoute_EventScript_Rancher_5:
	msgbox BelvedereRoute_EventScript_Rancher_Text_4
	goto BelvedereRoute_EventScript_Rancher_1

BelvedereRoute_EventScript_Rancher_6:
	msgbox BelvedereRoute_EventScript_Rancher_Text_5
	goto BelvedereRoute_EventScript_Rancher_1

BelvedereRoute_EventScript_Rancher_7:
	msgbox BelvedereRoute_EventScript_Rancher_Text_6
	goto BelvedereRoute_EventScript_Rancher_1

BelvedereRoute_EventScript_Rancher_8:
	msgbox BelvedereRoute_EventScript_Rancher_Text_7
	goto BelvedereRoute_EventScript_Rancher_1

BelvedereRoute_EventScript_Rancher_9:
	msgbox BelvedereRoute_EventScript_Rancher_Text_8
	addvar VAR_QUEST_MAREEP_STATE, 1
	goto BelvedereRoute_EventScript_Rancher_1

BelvedereRoute_EventScript_Rancher_10:
	call BelvedereRoute_EventScript_Wool
	goto BelvedereRoute_EventScript_Rancher_1

BelvedereRoute_EventScript_Rancher_12:
	msgbox BelvedereRoute_EventScript_Rancher_Text_1
	closemessage
	addvar VAR_QUEST_MAREEP_STATE, 1
	goto BelvedereRoute_EventScript_Rancher_1

BelvedereRoute_EventScript_Rancher_13:
	msgbox BelvedereRoute_EventScript_Rancher_Text_2
	closemessage
	goto BelvedereRoute_EventScript_Rancher_1

BelvedereRoute_EventScript_Rancher_14:
	msgbox BelvedereRoute_EventScript_Rancher_Text_2
	closemessage
	goto BelvedereRoute_EventScript_Rancher_1


BelvedereRoute_EventScript_Wool::
	msgbox BelvedereRoute_EventScript_Wool_Text_0, MSGBOX_NPC
	return


BelvedereRoute_EventScript_FindMareep_Text_0:
	.string "Bêêêêêh!$"

BelvedereRoute_EventScript_Rancher_Text_0:
	.string "Hey, you didn't happen to see a\n"
	.string "Mareep on your way here, did\l"
	.string "you? I'm desperate… All my\l"
	.string "Mareep escaped my ranch!\p"
	.string "You look like you're at least a\n"
	.string "semi-capable person…\p"
	.string "Would you mind helping me get them\n"
	.string "back?$"

BelvedereRoute_EventScript_Rancher_Text_1:
	.string "Thank you so much!\p"
	.string "There are five Mareep in total.\p"
	.string "Hopefully they should all be not\n"
	.string "too far from the ranch…$"

BelvedereRoute_EventScript_Rancher_Text_2:
	.string "Now that's not very nice…$"

BelvedereRoute_EventScript_Rancher_Text_3:
	.string "I'm still missing five Mareep!$"

BelvedereRoute_EventScript_Rancher_Text_4:
	.string "I'm still missing four Mareep!$"

BelvedereRoute_EventScript_Rancher_Text_5:
	.string "I'm still missing three Mareep!$"

BelvedereRoute_EventScript_Rancher_Text_6:
	.string "I'm still missing two Mareep!$"

BelvedereRoute_EventScript_Rancher_Text_7:
	.string "I'm still missing one Mareep!$"

BelvedereRoute_EventScript_Rancher_Text_8:
	.string "Finally, my herd is back together\n"
	.string "again!\p"
	.string "I'm so glad. Thank you, sincerely.\p"
	.string "Here's a small token of my\n"
	.string "appreciation.$"

BelvedereRoute_EventScript_Wool_Text_0:
	.string "If you bring me enough wool, I'll\n"
	.string "knit you a nice warm cloak.$"

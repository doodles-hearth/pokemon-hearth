YifuCity_CrobatShop_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, YifuCity_CrobatShop_SetupNpcs
	.byte 0


YifuCity_CrobatShop_SetupNpcs::
	goto_if_set FLAG_CROBAT_PASSWORD_CORRECT, YifuCity_CrobatShop_SetupNpcs_1
	return

YifuCity_CrobatShop_SetupNpcs_1:
	setobjectmovementtype 4, MOVEMENT_TYPE_FACE_LEFT
	setobjectxyperm 4, 7, 4
	return


YifuCity_CrobatShop_Cashier::
	lock
	faceplayer
	speakername YifuCity_CrobatShop_Cashier_Text_0
	msgbox YifuCity_CrobatShop_Cashier_Text_1
	waitmessage
	pokemart Crobat_Mart
	speakername YifuCity_CrobatShop_Cashier_Text_0
	msgbox YifuCity_CrobatShop_Cashier_Text_2
	closemessage
	release
	return


	.align 2
Crobat_Mart:
	.2byte ITEM_OINTMENT
	.2byte ITEM_SUPER_OINTMENT
	.2byte ITEM_ULTRA_BALL_KNOCKOFF
	.2byte ITEM_ESCAPE_ROPE_KNOCKOFF
	.2byte ITEM_SLOWPOKE_TAIL
	.2byte ITEM_NONE

YifuCity_CrobatShop_Guard::
	lock
	faceplayer
	goto_if_set FLAG_CROBAT_PASSWORD_CORRECT, YifuCity_CrobatShop_Guard_2
	applymovement VAR_LAST_TALKED, YifuCity_CrobatShop_Guard_Movement_0
	speakername YifuCity_CrobatShop_Guard_Text_0
	msgbox YifuCity_CrobatShop_Guard_Text_2
	goto_if_unset FLAG_GOT_CROBAT_PASSWORD_FIRST_HALF, YifuCity_CrobatShop_Guard_5
	goto_if_unset FLAG_GOT_CROBAT_PASSWORD_SECOND_HALF, YifuCity_CrobatShop_Guard_5
	goto_if_set FLAG_GOT_CROBAT_PASSWORD_FIRST_HALF, YifuCity_CrobatShop_Guard_14
YifuCity_CrobatShop_Guard_4:
	release
	return

YifuCity_CrobatShop_Guard_2:
	speakername YifuCity_CrobatShop_Guard_Text_0
	msgbox YifuCity_CrobatShop_Guard_Text_1
	release
	end

YifuCity_CrobatShop_Guard_5:
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, YifuCity_CrobatShop_Guard_Text_3, YifuCity_CrobatShop_Guard_Text_4, YifuCity_CrobatShop_Guard_Text_5
	closemessage
	delay 24
	applymovement VAR_LAST_TALKED, YifuCity_CrobatShop_Guard_Movement_1
	speakername YifuCity_CrobatShop_Guard_Text_0
	msgbox YifuCity_CrobatShop_Guard_Text_6
	waitmovement 0
	closemessage
	compare VAR_FACING, DIR_NORTH
	goto_if_eq YifuCity_CrobatShop_Guard_11
	applymovement VAR_LAST_TALKED, YifuCity_CrobatShop_Guard_Movement_4
	applymovement OBJ_EVENT_ID_PLAYER, YifuCity_CrobatShop_Guard_Movement_5
YifuCity_CrobatShop_Guard_10:
	waitmovement VAR_LAST_TALKED
	waitmovement OBJ_EVENT_ID_PLAYER
	release
	goto YifuCity_CrobatShop_Guard_4

YifuCity_CrobatShop_Guard_11:
	applymovement VAR_LAST_TALKED, YifuCity_CrobatShop_Guard_Movement_2
	applymovement OBJ_EVENT_ID_PLAYER, YifuCity_CrobatShop_Guard_Movement_3
	goto YifuCity_CrobatShop_Guard_10

YifuCity_CrobatShop_Guard_14:
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, YifuCity_CrobatShop_Guard_Text_7, YifuCity_CrobatShop_Guard_Text_8, YifuCity_CrobatShop_Guard_Text_9
	closemessage
	compare VAR_RESULT, 1
	goto_if_eq YifuCity_CrobatShop_Guard_17
YifuCity_CrobatShop_Guard_16:
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, YifuCity_CrobatShop_Guard_Text_10, YifuCity_CrobatShop_Guard_Text_11, YifuCity_CrobatShop_Guard_Text_12
	compare VAR_RESULT, 0
	goto_if_eq YifuCity_CrobatShop_Guard_20
YifuCity_CrobatShop_Guard_19:
	delay 24
	goto_if_set FLAG_TEMP_1, YifuCity_CrobatShop_Guard_24
YifuCity_CrobatShop_Guard_23:
	delay 24
	applymovement VAR_LAST_TALKED, YifuCity_CrobatShop_Guard_Movement_1
	speakername YifuCity_CrobatShop_Guard_Text_0
	msgbox YifuCity_CrobatShop_Guard_Text_6
	waitmovement 0
	closemessage
	compare VAR_FACING, DIR_NORTH
	goto_if_eq YifuCity_CrobatShop_Guard_31
	applymovement VAR_LAST_TALKED, YifuCity_CrobatShop_Guard_Movement_4
	applymovement OBJ_EVENT_ID_PLAYER, YifuCity_CrobatShop_Guard_Movement_5
YifuCity_CrobatShop_Guard_30:
	waitmovement VAR_LAST_TALKED
	waitmovement OBJ_EVENT_ID_PLAYER
	clearflag FLAG_TEMP_1
	clearflag FLAG_TEMP_2
	goto YifuCity_CrobatShop_Guard_4

YifuCity_CrobatShop_Guard_17:
	setflag FLAG_TEMP_1
	goto YifuCity_CrobatShop_Guard_16

YifuCity_CrobatShop_Guard_20:
	setflag FLAG_TEMP_2
	goto YifuCity_CrobatShop_Guard_19

YifuCity_CrobatShop_Guard_22:
	speakername YifuCity_CrobatShop_Guard_Text_0
	msgbox YifuCity_CrobatShop_Guard_Text_13
	closemessage
	setflag FLAG_CROBAT_PASSWORD_CORRECT
	compare VAR_FACING, DIR_NORTH
	goto_if_eq YifuCity_CrobatShop_Guard_28
YifuCity_CrobatShop_Guard_27:
	applymovement VAR_LAST_TALKED, YifuCity_CrobatShop_Guard_Movement_7
	waitmovement 0
	goto YifuCity_CrobatShop_Guard_4

YifuCity_CrobatShop_Guard_24:
	goto_if_set FLAG_TEMP_2, YifuCity_CrobatShop_Guard_22
	goto YifuCity_CrobatShop_Guard_23

YifuCity_CrobatShop_Guard_28:
	applymovement OBJ_EVENT_ID_PLAYER, YifuCity_CrobatShop_Guard_Movement_6
	goto YifuCity_CrobatShop_Guard_27

YifuCity_CrobatShop_Guard_31:
	applymovement VAR_LAST_TALKED, YifuCity_CrobatShop_Guard_Movement_2
	applymovement OBJ_EVENT_ID_PLAYER, YifuCity_CrobatShop_Guard_Movement_3
	goto YifuCity_CrobatShop_Guard_30


YifuCity_CrobatShop_Customer1::
	lock
	faceplayer
	speakername YifuCity_CrobatShop_Customer1_Text_0
	msgbox YifuCity_CrobatShop_Customer1_Text_1
	closemessage
	release
	return


YifuCity_CrobatShop_Customer2::
	lock
	faceplayer
	speakername YifuCity_CrobatShop_Customer1_Text_0
	msgbox YifuCity_CrobatShop_Customer2_Text_0
	closemessage
	release
	return


YifuCity_CrobatShop_EventScript_Samurai::
	lock
	faceplayer
	speakername YifuCity_CrobatShop_EventScript_Samurai_Text_0
	msgbox YifuCity_CrobatShop_EventScript_Samurai_Text_1
	closemessage
	release
	return


YifuCity_CrobatShop_Guard_Movement_0:
	lock_facing_direction
	walk_in_place_faster_left
	unlock_facing_direction
	step_end

YifuCity_CrobatShop_Guard_Movement_1:
	lock_facing_direction
	walk_in_place_faster_left
	step_end

YifuCity_CrobatShop_Guard_Movement_2:
	walk_down
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

YifuCity_CrobatShop_Guard_Movement_3:
	lock_facing_direction
	lock_anim
	jump_2_down
	unlock_facing_direction
	unlock_anim
	step_end

YifuCity_CrobatShop_Guard_Movement_4:
	walk_left
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

YifuCity_CrobatShop_Guard_Movement_5:
	lock_facing_direction
	lock_anim
	jump_2_left
	unlock_facing_direction
	unlock_anim
	step_end

YifuCity_CrobatShop_Guard_Movement_6:
	walk_left
	face_right
	step_end

YifuCity_CrobatShop_Guard_Movement_7:
	walk_down
	face_left
	step_end

YifuCity_CrobatShop_Cashier_Text_0:
	.string "Salesman$"

YifuCity_CrobatShop_Cashier_Text_1:
	.string "G'day uh, welcome to the ye olde\n"
	.string "Crobat Shoppe!\p"
	.string "Have a lookee at our totally legal\n"
	.string "tchotchquees and memoralibia!$"

YifuCity_CrobatShop_Cashier_Text_2:
	.string "We thank thee fer yer business! Tell\n"
	.string "yer friends!\p"
	.string "{FONT_SMALL}Unless yer friends are the police!{FONT_NORMAL}\p"
	.string "Wut's that? I said nothin', ya must be\n"
	.string "hearin' things!$"

YifuCity_CrobatShop_Guard_Text_0:
	.string "Shady man$"

YifuCity_CrobatShop_Guard_Text_1:
	.string "Standin' guard is boring… Yawn…$"

YifuCity_CrobatShop_Guard_Text_2:
	.string "Password?$"

YifuCity_CrobatShop_Guard_Text_3:
	.string "Uh…$"

YifuCity_CrobatShop_Guard_Text_4:
	.string "Ehm…$"

YifuCity_CrobatShop_Guard_Text_5:
	.string "Well…$"

YifuCity_CrobatShop_Guard_Text_6:
	.string "That ain't the password! Scram!$"

YifuCity_CrobatShop_Guard_Text_7:
	.string "Noivern…$"

YifuCity_CrobatShop_Guard_Text_8:
	.string "Crobat…$"

YifuCity_CrobatShop_Guard_Text_9:
	.string "Swoobat…$"

YifuCity_CrobatShop_Guard_Text_10:
	.string "…is awesome!$"

YifuCity_CrobatShop_Guard_Text_11:
	.string "…is amazing!$"

YifuCity_CrobatShop_Guard_Text_12:
	.string "…is legendary!$"

YifuCity_CrobatShop_Guard_Text_13:
	.string "Hmmm… Ya don't look like the typical\n"
	.string "Zubat…\p"
	.string "… … … …\n"
	.string "… …Alright, ya can go through.\l"
	.string "Next time wear the damn uniform\l"
	.string "though, will ya?$"

YifuCity_CrobatShop_Customer1_Text_0:
	.string "Customer$"

YifuCity_CrobatShop_Customer1_Text_1:
	.string "This place is amazing!\n"
	.string "How is everything so cheap?!$"

YifuCity_CrobatShop_Customer2_Text_0:
	.string "These Ultra Balls look… different,\n"
	.string "somehow…$"

YifuCity_CrobatShop_EventScript_Samurai_Text_0:
	.string "Samurai$"

YifuCity_CrobatShop_EventScript_Samurai_Text_1:
	.string "Shhh, don't look at me!\n"
	.string "Someone tipped me off that the\l"
	.string "Crobat Shadows' band of misfits has a\l"
	.string "secret hideout right under the city!\p"
	.string "I'm trying to know more by standing\n"
	.string "around and listening!$"

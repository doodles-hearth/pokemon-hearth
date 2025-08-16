YifuCity_CrobatShop_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, YifuCity_CrobatShop_SetupNpcs
	.byte 0


YifuCity_CrobatShop_SetupNpcs::
	goto_if_set FLAG_CROBAT_PASSWORD_CORRECT, YifuCity_CrobatShop_SetupNpcs_2
YifuCity_CrobatShop_SetupNpcs_1:
	compare VAR_CROBAT_HIDEOUT_STATE, 4
	goto_if_lt YifuCity_CrobatShop_SetupNpcs_4
	return

YifuCity_CrobatShop_SetupNpcs_2:
	setobjectmovementtype 4, MOVEMENT_TYPE_FACE_LEFT
	setobjectxyperm 4, 7, 4
	goto YifuCity_CrobatShop_SetupNpcs_1

YifuCity_CrobatShop_SetupNpcs_4:
	setflag FLAG_TEMP_3
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


YifuCity_CrobatShop_CashierLegit::
	lock
	faceplayer
	speakername YifuCity_CrobatShop_Cashier_Text_0
	msgbox YifuCity_CrobatShop_CashierLegit_Text_0
	waitmessage
	pokemart Legit_Mart
	speakername YifuCity_CrobatShop_Cashier_Text_0
	msgbox YifuCity_CrobatShop_CashierLegit_Text_1
	closemessage
	release
	return


YifuCity_CrobatShop_CashierLegitTM::
	lock
	faceplayer
	speakername YifuCity_CrobatShop_Cashier_Text_0
	msgbox YifuCity_CrobatShop_CashierLegitTM_Text_0
	closemessage
	release
	return


	.align 2
Crobat_Mart:
	.2byte ITEM_OINTMENT
	.2byte ITEM_SUPER_OINTMENT
	.2byte ITEM_REVIVAL_POWDER
	.2byte ITEM_REVIVAL_BALM
	.2byte ITEM_ULTRA_BALL_KNOCKOFF
	.2byte ITEM_ESCAPE_ROPE_KNOCKOFF
	.2byte ITEM_SLOWPOKE_TAIL
	.2byte ITEM_NONE

	.align 2
Legit_Mart:
	.2byte ITEM_OINTMENT
	.2byte ITEM_SUPER_OINTMENT
	.2byte ITEM_REVIVAL_POWDER
	.2byte ITEM_REVIVAL_BALM
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_NONE

YifuCity_CrobatShop_Guard::
	lock
	faceplayer
	goto_if_set FLAG_CROBAT_PASSWORD_CORRECT, YifuCity_CrobatShop_Guard_2
	compare VAR_FACING, DIR_NORTH
	goto_if_eq YifuCity_CrobatShop_Guard_5
	applymovement VAR_LAST_TALKED, YifuCity_CrobatShop_Guard_Movement_1
YifuCity_CrobatShop_Guard_4:
	applymovement VAR_LAST_TALKED, YifuCity_CrobatShop_Guard_Movement_2
	speakername YifuCity_CrobatShop_Guard_Text_0
	msgbox YifuCity_CrobatShop_Guard_Text_2
	goto_if_unset FLAG_GOT_CROBAT_PASSWORD_FIRST_HALF, YifuCity_CrobatShop_Guard_9
	goto_if_unset FLAG_GOT_CROBAT_PASSWORD_SECOND_HALF, YifuCity_CrobatShop_Guard_9
	goto_if_set FLAG_GOT_CROBAT_PASSWORD_FIRST_HALF, YifuCity_CrobatShop_Guard_18
YifuCity_CrobatShop_Guard_8:
	release
	return

YifuCity_CrobatShop_Guard_2:
	speakername YifuCity_CrobatShop_Guard_Text_0
	msgbox YifuCity_CrobatShop_Guard_Text_1
	release
	end

YifuCity_CrobatShop_Guard_5:
	applymovement VAR_LAST_TALKED, YifuCity_CrobatShop_Guard_Movement_0
	goto YifuCity_CrobatShop_Guard_4

YifuCity_CrobatShop_Guard_9:
	mcdialogue YifuCity_CrobatShop_Guard_Text_3, YifuCity_CrobatShop_Guard_Text_4, YifuCity_CrobatShop_Guard_Text_5
	closemessage
	delay 24
	speakername YifuCity_CrobatShop_Guard_Text_0
	msgbox YifuCity_CrobatShop_Guard_Text_6
	waitmovement 0
	closemessage
	compare VAR_FACING, DIR_NORTH
	goto_if_eq YifuCity_CrobatShop_Guard_15
	applymovement VAR_LAST_TALKED, YifuCity_CrobatShop_Guard_Movement_5
	applymovement OBJ_EVENT_ID_PLAYER, YifuCity_CrobatShop_Guard_Movement_6
YifuCity_CrobatShop_Guard_14:
	waitmovement VAR_LAST_TALKED
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement VAR_LAST_TALKED, YifuCity_CrobatShop_Guard_Movement_1
	waitmovement 0
	release
	goto YifuCity_CrobatShop_Guard_8

YifuCity_CrobatShop_Guard_15:
	applymovement VAR_LAST_TALKED, YifuCity_CrobatShop_Guard_Movement_3
	applymovement OBJ_EVENT_ID_PLAYER, YifuCity_CrobatShop_Guard_Movement_4
	goto YifuCity_CrobatShop_Guard_14

YifuCity_CrobatShop_Guard_18:
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, YifuCity_CrobatShop_Guard_Text_7, YifuCity_CrobatShop_Guard_Text_8, YifuCity_CrobatShop_Guard_Text_9
	closemessage
	compare VAR_RESULT, 1
	goto_if_eq YifuCity_CrobatShop_Guard_21
YifuCity_CrobatShop_Guard_20:
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, YifuCity_CrobatShop_Guard_Text_10, YifuCity_CrobatShop_Guard_Text_11, YifuCity_CrobatShop_Guard_Text_12
	compare VAR_RESULT, 0
	goto_if_eq YifuCity_CrobatShop_Guard_24
YifuCity_CrobatShop_Guard_23:
	delay 24
	goto_if_set FLAG_TEMP_1, YifuCity_CrobatShop_Guard_28
YifuCity_CrobatShop_Guard_27:
	delay 24
	speakername YifuCity_CrobatShop_Guard_Text_0
	msgbox YifuCity_CrobatShop_Guard_Text_6
	waitmovement 0
	closemessage
	compare VAR_FACING, DIR_NORTH
	goto_if_eq YifuCity_CrobatShop_Guard_35
	applymovement VAR_LAST_TALKED, YifuCity_CrobatShop_Guard_Movement_5
	applymovement OBJ_EVENT_ID_PLAYER, YifuCity_CrobatShop_Guard_Movement_6
YifuCity_CrobatShop_Guard_34:
	waitmovement VAR_LAST_TALKED
	waitmovement OBJ_EVENT_ID_PLAYER
	clearflag FLAG_TEMP_1
	clearflag FLAG_TEMP_2
	goto YifuCity_CrobatShop_Guard_8

YifuCity_CrobatShop_Guard_21:
	setflag FLAG_TEMP_1
	goto YifuCity_CrobatShop_Guard_20

YifuCity_CrobatShop_Guard_24:
	setflag FLAG_TEMP_2
	goto YifuCity_CrobatShop_Guard_23

YifuCity_CrobatShop_Guard_26:
	speakername YifuCity_CrobatShop_Guard_Text_0
	msgbox YifuCity_CrobatShop_Guard_Text_13
	closemessage
	setflag FLAG_CROBAT_PASSWORD_CORRECT
	compare VAR_FACING, DIR_NORTH
	goto_if_eq YifuCity_CrobatShop_Guard_32
YifuCity_CrobatShop_Guard_31:
	applymovement VAR_LAST_TALKED, YifuCity_CrobatShop_Guard_Movement_8
	waitmovement 0
	goto YifuCity_CrobatShop_Guard_8

YifuCity_CrobatShop_Guard_28:
	goto_if_set FLAG_TEMP_2, YifuCity_CrobatShop_Guard_26
	goto YifuCity_CrobatShop_Guard_27

YifuCity_CrobatShop_Guard_32:
	applymovement OBJ_EVENT_ID_PLAYER, YifuCity_CrobatShop_Guard_Movement_7
	goto YifuCity_CrobatShop_Guard_31

YifuCity_CrobatShop_Guard_35:
	applymovement VAR_LAST_TALKED, YifuCity_CrobatShop_Guard_Movement_3
	applymovement OBJ_EVENT_ID_PLAYER, YifuCity_CrobatShop_Guard_Movement_4
	goto YifuCity_CrobatShop_Guard_34


YifuCity_CrobatShop_Customer1::
	lock
	faceplayer
	speakername YifuCity_CrobatShop_Customer1_Text_0
	goto_if_set FLAG_CLEARED_CROBAT_HIDEOUT, YifuCity_CrobatShop_Customer1_2
	msgbox YifuCity_CrobatShop_Customer1_Text_2
YifuCity_CrobatShop_Customer1_1:
	closemessage
	release
	return

YifuCity_CrobatShop_Customer1_2:
	msgbox YifuCity_CrobatShop_Customer1_Text_1
	goto YifuCity_CrobatShop_Customer1_1


YifuCity_CrobatShop_Customer2::
	lock
	faceplayer
	speakername YifuCity_CrobatShop_Customer1_Text_0
	goto_if_set FLAG_CLEARED_CROBAT_HIDEOUT, YifuCity_CrobatShop_Customer2_2
	msgbox YifuCity_CrobatShop_Customer2_Text_1
YifuCity_CrobatShop_Customer2_1:
	closemessage
	release
	return

YifuCity_CrobatShop_Customer2_2:
	msgbox YifuCity_CrobatShop_Customer2_Text_0
	goto YifuCity_CrobatShop_Customer2_1


YifuCity_CrobatShop_EventScript_Samurai::
	lock
	faceplayer
	speakername YifuCity_CrobatShop_EventScript_Samurai_Text_0
	msgbox YifuCity_CrobatShop_EventScript_Samurai_Text_1
	closemessage
	release
	return


YifuCity_CrobatShop_Guard_Movement_0:
	walk_in_place_faster_down
	step_end

YifuCity_CrobatShop_Guard_Movement_1:
	walk_in_place_faster_left
	step_end

YifuCity_CrobatShop_Guard_Movement_2:
	lock_facing_direction
	walk_in_place_faster_left
	unlock_facing_direction
	step_end

YifuCity_CrobatShop_Guard_Movement_3:
	walk_down
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

YifuCity_CrobatShop_Guard_Movement_4:
	lock_facing_direction
	lock_anim
	jump_2_down
	unlock_facing_direction
	unlock_anim
	step_end

YifuCity_CrobatShop_Guard_Movement_5:
	walk_left
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

YifuCity_CrobatShop_Guard_Movement_6:
	lock_facing_direction
	lock_anim
	jump_2_left
	unlock_facing_direction
	unlock_anim
	step_end

YifuCity_CrobatShop_Guard_Movement_7:
	walk_left
	face_right
	step_end

YifuCity_CrobatShop_Guard_Movement_8:
	walk_down
	face_left
	step_end

YifuCity_CrobatShop_Cashier_Text_0:
	.string "Shopkeeper$"

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

YifuCity_CrobatShop_CashierLegit_Text_0:
	.string "Hello there! Welcome to the Yifu City\n"
	.string "shop!$"

YifuCity_CrobatShop_CashierLegit_Text_1:
	.string "We hope you'll come again! Have a good\n"
	.string "day!$"

YifuCity_CrobatShop_CashierLegitTM_Text_0:
	.string "Hi! I'm prepping up here, but come\n"
	.string "back soon for some excusive new\l"
	.string "items!$"

YifuCity_CrobatShop_Guard_Text_0:
	.string "Shady man$"

YifuCity_CrobatShop_Guard_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_ZUBAT EMOTE_NORMAL}Standin' guard is boring… Yawn…$"

YifuCity_CrobatShop_Guard_Text_2:
	.string "{CREATE_MUGSHOT MUGSHOT_ZUBAT EMOTE_NORMAL}Password?$"

YifuCity_CrobatShop_Guard_Text_3:
	.string "Uh…$"

YifuCity_CrobatShop_Guard_Text_4:
	.string "Ehm…$"

YifuCity_CrobatShop_Guard_Text_5:
	.string "Well…$"

YifuCity_CrobatShop_Guard_Text_6:
	.string "{CREATE_MUGSHOT MUGSHOT_ZUBAT EMOTE_NORMAL}That ain't the password! Scram!$"

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
	.string "{CREATE_MUGSHOT MUGSHOT_ZUBAT EMOTE_NORMAL}Hmmm… Ya don't look like the typical\n"
	.string "Zubat…\p"
	.string "… … … …\n"
	.string "… …Alright, ya can go through.\l"
	.string "Next time wear the damn uniform\l"
	.string "though, will ya?$"

YifuCity_CrobatShop_Customer1_Text_0:
	.string "Customer$"

YifuCity_CrobatShop_Customer1_Text_1:
	.string "Woah! So I was buying illegal items?\n"
	.string "That's wild!$"

YifuCity_CrobatShop_Customer1_Text_2:
	.string "This place is amazing!\n"
	.string "How is everything so cheap?!$"

YifuCity_CrobatShop_Customer2_Text_0:
	.string "I knew it! I knew this shop was shady!$"

YifuCity_CrobatShop_Customer2_Text_1:
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

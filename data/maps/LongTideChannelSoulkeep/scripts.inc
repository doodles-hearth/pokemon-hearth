LongTideChannelSoulkeep_MapScripts::
	.byte 0


LongTideChannelSoulkeep_RouteSign::
	msgbox LongTideChannelSoulkeep_RouteSign_Text_0, MSGBOX_SIGN
	return


LongTideChannelSoulkeep_EventScripts_BoatGuy::
	lock
	faceplayer
	msgbox LongTideChannelSoulkeep_EventScripts_BoatGuy_Text_0
	mcdialogueB LongTideChannelSoulkeep_EventScripts_BoatGuy_Text_1, LongTideChannelSoulkeep_EventScripts_BoatGuy_Text_2
	closemessage
	compare VAR_RESULT, 0
	goto_if_eq LongTideChannelSoulkeep_EventScripts_BoatGuy_2
LongTideChannelSoulkeep_EventScripts_BoatGuy_1:
	release
	return

LongTideChannelSoulkeep_EventScripts_BoatGuy_2:
	playse SE_LEDGE
	applymovement VAR_LAST_TALKED, LongTideChannelSoulkeep_EventScripts_BoatGuy_Movement_0
	waitmovement VAR_LAST_TALKED
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	applymovement LOCALID_LONGTIDE_WINGULL, LongTideChannelSoulkeep_EventScripts_BoatGuy_Movement_1
	applymovement LOCALID_PLAYER, LongTideChannelSoulkeep_EventScripts_BoatGuy_Movement_2
	waitmovement LOCALID_PLAYER
	playse SE_MUGSHOT
	warpsilent MAP_SABERSIDE_TOWN
	goto LongTideChannelSoulkeep_EventScripts_BoatGuy_1


LongTideChannelSoulkeep_EventScripts_WhereChatot::
	lock
	faceplayer
	setnamedmon SPECIES_CHATOT
	goto_if_set FLAG_POST_CHATOT, LongTideChannelSoulkeep_EventScripts_WhereChatot_2
	msgbox LongTideChannelSoulkeep_EventScripts_WhereChatot_Text_1
	setdescribedmon SPECIES_CHATOT
LongTideChannelSoulkeep_EventScripts_WhereChatot_1:
	closemessage
	release
	return

LongTideChannelSoulkeep_EventScripts_WhereChatot_2:
	msgbox LongTideChannelSoulkeep_EventScripts_WhereChatot_Text_0
	goto LongTideChannelSoulkeep_EventScripts_WhereChatot_1


LongTideChannelSoulkeep_EventScripts_BoatGuy_Movement_0:
	jump_2_left
	delay_16
	delay_16
	step_end

LongTideChannelSoulkeep_EventScripts_BoatGuy_Movement_1:
	walk_up
	walk_left
	walk_left
	walk_in_place_left
	walk_in_place_left
	walk_in_place_left
	walk_in_place_left
	walk_in_place_left
	step_end

LongTideChannelSoulkeep_EventScripts_BoatGuy_Movement_2:
	walk_up
	jump_2_left
	delay_16
	face_down
	delay_16
	step_end

LongTideChannelSoulkeep_RouteSign_Text_0:
	.string "{LEFT_ARROW} Havenisle$"

LongTideChannelSoulkeep_EventScripts_BoatGuy_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_SEASIDE_OLD_MAN EMOTE_NORMAL}{SPEAKER NAME_OLD_MAN}I'm on my way to Saberside Town.\n"
	.string "Want to hop along?$"

LongTideChannelSoulkeep_EventScripts_BoatGuy_Text_1:
	.string "All aboard!$"

LongTideChannelSoulkeep_EventScripts_BoatGuy_Text_2:
	.string "No need.$"

LongTideChannelSoulkeep_EventScripts_WhereChatot_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_UUME_LITTLE_BOY EMOTE_NORMAL}{SPEAKER NAME_LITTLE_BOY}Where's Chatot? I wanna see Chatot!$"

LongTideChannelSoulkeep_EventScripts_WhereChatot_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_UUME_LITTLE_BOY EMOTE_NORMAL}{SPEAKER NAME_LITTLE_BOY}Oooh, Chatot's here!!\n"
	.string "I love Chatot!\p"
	.string "How would I talk to my friends in Yifu\n"
	.string "City without Chatot? We'd have to\l"
	.string "WRITE stuff to each other, YUCK!\p"
	.string "I love how it flicks its tail to keep a\n"
	.string "rhythm while it speaks!\l"
	.string "And it imitates any voice perfectly!$"

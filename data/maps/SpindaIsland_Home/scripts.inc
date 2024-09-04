SpindaIsland_Home_MapScripts::
# 6 "data/maps/SpindaIsland_Home/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SpindaIsland_Home_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 13 "data/maps/SpindaIsland_Home/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SpindaIsland_Home_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

SpindaIsland_Home_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 7 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_SLOWPOKE_EVOLVED, SpindaIsland_Home_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
# 10 "data/maps/SpindaIsland_Home/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( SLOWPOKE )
	return

SpindaIsland_Home_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 8 "data/maps/SpindaIsland_Home/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( SLOWBRO )
	return

SpindaIsland_Home_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 14 "data/maps/SpindaIsland_Home/scripts.pory"
	map_script_2 VAR_SPINDA_ISLAND_INTRO_STATE, 2, SpindaIsland_Home_EventScript_MainQuestRecap
	.2byte 0


SpindaIsland_Home_EventScript_MainQuestRecap::
# 18 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 19 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 20 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 21 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MainQuestRecap_Text_1
# 25 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 26 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 27 "data/maps/SpindaIsland_Home/scripts.pory"
	setvar VAR_SPINDA_ISLAND_INTRO_STATE, 3
# 28 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_MetapodOtherSide::
# 32 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 33 "data/maps/SpindaIsland_Home/scripts.pory"
	setvar VAR_METAPOD_OTHER_SIDE, 1
# 34 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_ArchiesHouseSign::
# 38 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_ArchiesHouseSign_Text_0, MSGBOX_SIGN
	return


SpindaIsland_Home_EventScript_BobsHouseSign::
# 42 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_BobsHouseSign_Text_0, MSGBOX_SIGN
	return


SpindaIsland_Home_EventScript_ICanNeverGoHome::
# 46 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 47 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 48 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_SAD
# 49 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_ICanNeverGoHome_Text_0
# 50 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_ICanNeverGoHome_Text_1, MSGBOX_NPC
# 54 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 55 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_Dad::
# 59 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 60 "data/maps/SpindaIsland_Home/scripts.pory"
	turnobject 2, DIR_SOUTH
# 61 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_OBTAINED_LEMONADE, SpindaIsland_Home_EventScript_Dad_2
# 69 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_SPOKE_TO_DAD, SpindaIsland_Home_EventScript_Dad_6
# 76 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_0
# 77 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_3
# 81 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
SpindaIsland_Home_EventScript_Dad_5:
# 84 "data/maps/SpindaIsland_Home/scripts.pory"
	giveitem ITEM_SALTY_LEMONADE
# 86 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 87 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 88 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 89 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_4
# 93 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 94 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 96 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 10
# 97 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_BALL
# 98 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 99 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_BALL
# 100 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 101 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_BALL
# 102 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 103 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 20
# 105 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_PIN
# 106 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
# 107 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 108 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 110 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_DISGUSTED
# 111 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 112 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_5
# 116 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 117 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 119 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_0
# 120 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_6
# 127 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 129 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_OBTAINED_LEMONADE
# 130 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_SPOKE_TO_DAD
SpindaIsland_Home_EventScript_Dad_1:
# 132 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_Dad_2:
# 62 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_0
# 63 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_1
# 67 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_Dad_1

SpindaIsland_Home_EventScript_Dad_6:
# 70 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_0
# 71 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_2
# 74 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_Dad_5


SpindaIsland_Home_EventScript_Dad_FromSide::
# 136 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 137 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 138 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_OBTAINED_LEMONADE, SpindaIsland_Home_EventScript_Dad_FromSide_2
# 146 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_SPOKE_TO_DAD, SpindaIsland_Home_EventScript_Dad_FromSide_6
# 153 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_0
# 154 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_FromSide_Text_1
# 159 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
SpindaIsland_Home_EventScript_Dad_FromSide_5:
# 161 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_SPOKE_TO_DAD
SpindaIsland_Home_EventScript_Dad_FromSide_1:
# 163 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_Dad_FromSide_2:
# 139 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_0
# 140 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_1
# 144 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_Dad_FromSide_1

SpindaIsland_Home_EventScript_Dad_FromSide_6:
# 147 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_0
# 148 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_FromSide_Text_0
# 151 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_Dad_FromSide_5


SpindaIsland_Home_EventScript_LemonadeStandSign::
# 167 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_LemonadeStandSign_Text_0, MSGBOX_SIGN
	return


SpindaIsland_Home_EventScript_MainStreetSign::
# 174 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MainStreetSign_Text_0, MSGBOX_SIGN
	return


SpindaIsland_Home_EventScript_MadelineSign::
# 180 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MadelineSign_Text_0, MSGBOX_SIGN
	return


SpindaIsland_Home_EventScript_PoemGirl::
# 186 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 188 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_POEM_GIRL, SpindaIsland_Home_EventScript_PoemGirl_2
# 202 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_GRASSWHISTLE
# 203 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 205 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 207 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 208 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 209 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_2
# 214 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 215 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 217 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_3, SpindaIsland_Home_EventScript_PoemGirl_Text_4, SpindaIsland_Home_EventScript_PoemGirl_Text_5
# 229 "data/maps/SpindaIsland_Home/scripts.pory"
	switch VAR_RESULT
# 230 "data/maps/SpindaIsland_Home/scripts.pory"
	case 0, SpindaIsland_Home_EventScript_PoemGirl_6
# 275 "data/maps/SpindaIsland_Home/scripts.pory"
	case 1, SpindaIsland_Home_EventScript_PoemGirl_7
# 370 "data/maps/SpindaIsland_Home/scripts.pory"
	case 2, SpindaIsland_Home_EventScript_PoemGirl_8
SpindaIsland_Home_EventScript_PoemGirl_1:
# 467 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 468 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 469 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_PoemGirl_2:
# 189 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 190 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 191 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 192 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_1
# 195 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 196 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 198 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 199 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 200 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_GRASSWHISTLE
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_6:
# 231 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_6, SpindaIsland_Home_EventScript_PoemGirl_Text_7
# 242 "data/maps/SpindaIsland_Home/scripts.pory"
	switch VAR_RESULT
# 243 "data/maps/SpindaIsland_Home/scripts.pory"
	case 0, SpindaIsland_Home_EventScript_PoemGirl_11
# 254 "data/maps/SpindaIsland_Home/scripts.pory"
	case 1, SpindaIsland_Home_EventScript_PoemGirl_12
SpindaIsland_Home_EventScript_PoemGirl_9:
# 267 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 268 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 269 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_12
# 273 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 274 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_7:
# 276 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_13, SpindaIsland_Home_EventScript_PoemGirl_Text_14
# 286 "data/maps/SpindaIsland_Home/scripts.pory"
	switch VAR_RESULT
# 288 "data/maps/SpindaIsland_Home/scripts.pory"
	case 0, SpindaIsland_Home_EventScript_PoemGirl_14
# 347 "data/maps/SpindaIsland_Home/scripts.pory"
	case 1, SpindaIsland_Home_EventScript_PoemGirl_15
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_8:
# 371 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_24, SpindaIsland_Home_EventScript_PoemGirl_Text_13
# 382 "data/maps/SpindaIsland_Home/scripts.pory"
	switch VAR_RESULT
# 384 "data/maps/SpindaIsland_Home/scripts.pory"
	case 0, SpindaIsland_Home_EventScript_PoemGirl_17
# 407 "data/maps/SpindaIsland_Home/scripts.pory"
	case 1, SpindaIsland_Home_EventScript_PoemGirl_18
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_11:
# 244 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_8, SpindaIsland_Home_EventScript_PoemGirl_Text_9
	goto SpindaIsland_Home_EventScript_PoemGirl_9

SpindaIsland_Home_EventScript_PoemGirl_12:
# 255 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_10, SpindaIsland_Home_EventScript_PoemGirl_Text_11
	goto SpindaIsland_Home_EventScript_PoemGirl_9

SpindaIsland_Home_EventScript_PoemGirl_14:
# 289 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_15, SpindaIsland_Home_EventScript_PoemGirl_Text_16
# 300 "data/maps/SpindaIsland_Home/scripts.pory"
	switch VAR_RESULT
# 302 "data/maps/SpindaIsland_Home/scripts.pory"
	case 0, SpindaIsland_Home_EventScript_PoemGirl_20
# 324 "data/maps/SpindaIsland_Home/scripts.pory"
	case 1, SpindaIsland_Home_EventScript_PoemGirl_21
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_15:
# 348 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_21, SpindaIsland_Home_EventScript_PoemGirl_Text_22
# 359 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 360 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 361 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_23
# 367 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 368 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_17:
# 385 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_25, SpindaIsland_Home_EventScript_PoemGirl_Text_26
# 396 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 397 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 398 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_27
# 403 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 404 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_18:
# 408 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_28, SpindaIsland_Home_EventScript_PoemGirl_Text_29
# 419 "data/maps/SpindaIsland_Home/scripts.pory"
	switch VAR_RESULT
# 420 "data/maps/SpindaIsland_Home/scripts.pory"
	case 0, SpindaIsland_Home_EventScript_PoemGirl_23
# 430 "data/maps/SpindaIsland_Home/scripts.pory"
	case 1, SpindaIsland_Home_EventScript_PoemGirl_24
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_20:
# 303 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_17, SpindaIsland_Home_EventScript_PoemGirl_Text_18
# 314 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 315 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 316 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_19
# 320 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 321 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_21:
# 325 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_17, SpindaIsland_Home_EventScript_PoemGirl_Text_18
# 336 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 337 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 338 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_20
# 342 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 343 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_23:
# 421 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 422 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 423 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_27
# 428 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 429 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_24:
# 431 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_30
# 440 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 441 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 442 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_31
# 449 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 450 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 452 "data/maps/SpindaIsland_Home/scripts.pory"
	giveitem ITEM_GRASS_BLADE
# 454 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 455 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 456 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_32
# 459 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 460 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 462 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_POEM_GIRL
	goto SpindaIsland_Home_EventScript_PoemGirl_1


SpindaIsland_Home_EventScript_Sunbather::
# 473 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 474 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Sunbather_Text_0
# 477 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_PIN
# 478 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
# 479 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 480 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 481 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 482 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 483 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Sunbather_Text_1
# 486 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 487 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 488 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 489 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_Slowpoke::
# 493 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 494 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_SLOWPOKE_EVOLVED, SpindaIsland_Home_Slowpoke_2
# 504 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 505 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_SLOWPOKE, CRY_MODE_NORMAL
# 506 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_Slowpoke_Text_2
# 507 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Slowpoke_Text_3
# 510 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmoncry
# 511 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	checkitem ITEM_WHITE_SEASHELL
# 0 "data/maps/SpindaIsland_Home/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq SpindaIsland_Home_Slowpoke_5
SpindaIsland_Home_Slowpoke_1:
# 591 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_Slowpoke_2:
# 495 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 496 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_SLOWBRO, CRY_MODE_NORMAL
# 497 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_Slowpoke_Text_0
# 498 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Slowpoke_Text_1
# 501 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_Slowpoke_1

SpindaIsland_Home_Slowpoke_5:
# 514 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_THINKING
# 515 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 516 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Slowpoke_Text_4
# 521 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_Slowpoke_Text_5, SpindaIsland_Home_Slowpoke_Text_6
# 531 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 532 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 534 "data/maps/SpindaIsland_Home/scripts.pory"
	switch VAR_RESULT
# 535 "data/maps/SpindaIsland_Home/scripts.pory"
	case 0, SpindaIsland_Home_Slowpoke_8
# 578 "data/maps/SpindaIsland_Home/scripts.pory"
	case 1, SpindaIsland_Home_Slowpoke_9
	goto SpindaIsland_Home_Slowpoke_1

SpindaIsland_Home_Slowpoke_8:
# 536 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 537 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 538 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Slowpoke_Text_7
# 542 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 544 "data/maps/SpindaIsland_Home/scripts.pory"
	removeitem ITEM_WHITE_SEASHELL
# 546 "data/maps/SpindaIsland_Home/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( SLOWBRO )
# 547 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject VAR_LAST_TALKED
# 548 "data/maps/SpindaIsland_Home/scripts.pory"
	addobject VAR_LAST_TALKED
# 549 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_BITE
# 550 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, SpindaIsland_Home_Movement_Slowpoke
# 551 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 552 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement VAR_LAST_TALKED
# 553 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 555 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_SLOWPOKE, CRY_MODE_NORMAL
# 556 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_Slowpoke_Text_0
# 557 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Slowpoke_Text_8
# 560 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmoncry
# 561 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 563 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_SHOCKED
# 564 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 565 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Slowpoke_Text_9
# 569 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 570 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 571 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Slowpoke_Text_10
# 574 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 575 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 577 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_SLOWPOKE_EVOLVED
	goto SpindaIsland_Home_Slowpoke_1

SpindaIsland_Home_Slowpoke_9:
# 579 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_SLOWPOKE, CRY_MODE_FAINT
# 580 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_Slowpoke_Text_2
# 581 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Slowpoke_Text_11
# 585 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmoncry
# 586 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_Slowpoke_1


SpindaIsland_Home_EventScript_Metapod::
# 595 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 596 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Metapod_Text_0
# 597 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_METAPOD, CRY_MODE_NORMAL
# 598 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Metapod_Text_1
# 601 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmoncry
# 602 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 603 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_MetapodBoysFuckOff::
# 607 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 608 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0
# 609 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_1
# 614 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 616 "data/maps/SpindaIsland_Home/scripts.pory"
	fadescreen FADE_TO_BLACK
# 617 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_HIDE_METAPOD_BATTLE
# 618 "data/maps/SpindaIsland_Home/scripts.pory"
	special DrawWholeMapView
# 619 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 60
# 620 "data/maps/SpindaIsland_Home/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 621 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 40
# 622 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_MetapodBoy1::
# 626 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 627 "data/maps/SpindaIsland_Home/scripts.pory"
	compare VAR_METAPOD_OTHER_SIDE, 1
	goto_if_eq SpindaIsland_Home_EventScript_MetapodBoy1_2
SpindaIsland_Home_EventScript_MetapodBoy1_1:
# 630 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0
# 631 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoy1_Text_0
# 634 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 636 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 638 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0
# 639 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoy1_Text_1
# 642 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 644 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 646 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0
# 647 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoy1_Text_2
# 650 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 652 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_HARDEN
# 653 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 654 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_HARDEN
# 655 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 656 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 657 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_MetapodBoy1_2:
# 628 "data/maps/SpindaIsland_Home/scripts.pory"
	goto SpindaIsland_Home_EventScript_MetapodBoysFuckOff
	goto SpindaIsland_Home_EventScript_MetapodBoy1_1


SpindaIsland_Home_EventScript_MetapodBoy2::
# 661 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 662 "data/maps/SpindaIsland_Home/scripts.pory"
	compare VAR_METAPOD_OTHER_SIDE, 1
	goto_if_eq SpindaIsland_Home_EventScript_MetapodBoy2_2
SpindaIsland_Home_EventScript_MetapodBoy2_1:
# 665 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 666 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0
# 667 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoy2_Text_0
# 670 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 671 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 672 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0
# 673 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoy1_Text_2
# 676 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 678 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_HARDEN
# 679 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 680 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_HARDEN
# 681 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 682 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 683 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_MetapodBoy2_2:
# 663 "data/maps/SpindaIsland_Home/scripts.pory"
	goto SpindaIsland_Home_EventScript_MetapodBoysFuckOff
	goto SpindaIsland_Home_EventScript_MetapodBoy2_1


SpindaIsland_Home_PhotoCameraWrongDir::
# 687 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 689 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_CAMERA_EXPLODED, SpindaIsland_Home_PhotoCameraWrongDir_2
# 698 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 699 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 700 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_PhotoCameraWrongDir_Text_1
# 703 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 704 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
SpindaIsland_Home_PhotoCameraWrongDir_1:
# 709 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_PhotoCameraWrongDir_2:
# 690 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 691 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 692 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_PhotoCameraWrongDir_Text_0
# 695 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 696 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
	goto SpindaIsland_Home_PhotoCameraWrongDir_1


# 712 "data/maps/SpindaIsland_Home/scripts.pory"
SpindaIsland_Home_Movement_Slowpoke:
# 713 "data/maps/SpindaIsland_Home/scripts.pory"
	lock_facing_direction
# 714 "data/maps/SpindaIsland_Home/scripts.pory"
	jump_in_place_down
# 715 "data/maps/SpindaIsland_Home/scripts.pory"
	unlock_facing_direction
# 716 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 716 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 716 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 717 "data/maps/SpindaIsland_Home/scripts.pory"
	face_up
# 718 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 719 "data/maps/SpindaIsland_Home/scripts.pory"
	face_down
# 720 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 721 "data/maps/SpindaIsland_Home/scripts.pory"
	face_left
# 722 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 723 "data/maps/SpindaIsland_Home/scripts.pory"
	face_up
# 724 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 725 "data/maps/SpindaIsland_Home/scripts.pory"
	face_player
# 726 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 726 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 726 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 727 "data/maps/SpindaIsland_Home/scripts.pory"
	lock_facing_direction
# 728 "data/maps/SpindaIsland_Home/scripts.pory"
	jump_in_place_down
# 729 "data/maps/SpindaIsland_Home/scripts.pory"
	jump_in_place_down
# 730 "data/maps/SpindaIsland_Home/scripts.pory"
	unlock_facing_direction
# 731 "data/maps/SpindaIsland_Home/scripts.pory"
	emote_heart
# 732 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 732 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 732 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
	step_end

SpindaIsland_Home_SlowpokeMistress::
# 736 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 737 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 738 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_RECEIVED_SLOWPOKE_REWARD, SpindaIsland_Home_SlowpokeMistress_2
# 747 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_SLOWPOKE_EVOLVED, SpindaIsland_Home_SlowpokeMistress_3
# 791 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LASS, EMOTE_SWEAT
# 792 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_SlowpokeMistress_Text_0
# 793 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_SlowpokeMistress_Text_7
# 796 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 797 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LASS, EMOTE_NORMAL
# 798 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_SlowpokeMistress_Text_8
# 802 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 803 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
SpindaIsland_Home_SlowpokeMistress_1:
# 805 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_SlowpokeMistress_2:
# 739 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LASS, EMOTE_HAPPY
# 740 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_SlowpokeMistress_Text_0
# 741 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_SlowpokeMistress_Text_1
# 745 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 746 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_SlowpokeMistress_1

SpindaIsland_Home_SlowpokeMistress_3:
# 748 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_PIN
# 749 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
# 750 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 751 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 752 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 754 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LASS, EMOTE_SURPRISED
# 755 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_SlowpokeMistress_Text_0
# 756 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_SlowpokeMistress_Text_2
# 760 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 761 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LASS, EMOTE_NORMAL
# 762 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_SlowpokeMistress_Text_3
# 765 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 766 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LASS, EMOTE_HAPPY
# 767 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_SlowpokeMistress_Text_4
# 770 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 771 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LASS, EMOTE_NORMAL
# 772 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_SlowpokeMistress_Text_5
# 775 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 776 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 778 "data/maps/SpindaIsland_Home/scripts.pory"
	giveitem ITEM_WATER_STONE_2
# 780 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_THINKING
# 781 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 782 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_SlowpokeMistress_Text_6
# 786 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 787 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 789 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_RECEIVED_SLOWPOKE_REWARD
	goto SpindaIsland_Home_SlowpokeMistress_1


SpindaIsland_Home_CarBoy::
	return


SpindaIsland_Home_CarGirl::
	return


SpindaIsland_Home_EventScript_MainQuestRecap_Text_0:
# 20 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Little Archie$"

SpindaIsland_Home_EventScript_MainQuestRecap_Text_1:
# 22 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Alright! The quicker mom gets her\n"
	.string "glass of {COLOR BLUE}WATER{COLOR DARK_GRAY}, the quicker Archie\l"
	.string "gets his super badass {COLOR RED}sail{COLOR DARK_GRAY}!\p"
	.string "Let's get moving!$"

SpindaIsland_Home_EventScript_ArchiesHouseSign_Text_0:
# 38 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "The Hoenns$"

SpindaIsland_Home_EventScript_BobsHouseSign_Text_0:
# 42 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Bob$"

SpindaIsland_Home_EventScript_ICanNeverGoHome_Text_0:
# 49 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Sad man$"

SpindaIsland_Home_EventScript_ICanNeverGoHome_Text_1:
# 51 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Curse the architect that built my\n"
	.string "house facing the wrong direction!!\p"
	.string "I can never go home!$"

SpindaIsland_Home_EventScript_Dad_Text_0:
# 62 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Dad$"

SpindaIsland_Home_EventScript_Dad_Text_1:
# 64 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Don't uh, pour that lemonade I gave\n"
	.string "you on the ground or anything.\p"
	.string "It'd probably kill all the grass and\n"
	.string "flowers.$"

SpindaIsland_Home_EventScript_Dad_Text_2:
# 72 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Here, have some lemonade!$"

SpindaIsland_Home_EventScript_Dad_Text_3:
# 78 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hiya, sonny! going adventuring today,\n"
	.string "are we?\p"
	.string "Want some lemonade?$"

SpindaIsland_Home_EventScript_Dad_Text_4:
# 90 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Now we're talkin'!! I can bring this to\n"
	.string "mom, that should do it!\p"
	.string "Let's take a sip first, I am PARCHED!$"

SpindaIsland_Home_EventScript_Dad_Text_5:
# 113 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "BLEARGH!\p"
	.string "Why is it… so salty?!$"

SpindaIsland_Home_EventScript_Dad_Text_6:
# 121 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Why, because it's seawater, obviously!\p"
	.string "I take it you're not a fan of my\n"
	.string "recipe?\p"
	.string "(You wouldn't be the only one…)\p"
	.string "In any case, it's nice of you to come\n"
	.string "visit me at the office, haha!\p"
	.string "See you around, little Archie! Don't\n"
	.string "get into trouble!$"

SpindaIsland_Home_EventScript_Dad_FromSide_Text_0:
# 149 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Come round to the front of the\n"
	.string "lemonade stand!$"

SpindaIsland_Home_EventScript_Dad_FromSide_Text_1:
# 155 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hiya, sonny! going adventuring today,\n"
	.string "are we?\p"
	.string "Want some lemonade?\p"
	.string "Come round to the front of the\n"
	.string "lemonade stand!$"

SpindaIsland_Home_EventScript_LemonadeStandSign_Text_0:
# 168 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "“ARCHIE'S LEMONADE\n"
	.string "A taste of the seaside!”$"

SpindaIsland_Home_EventScript_MainStreetSign_Text_0:
# 175 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "{UP_ARROW} Main street$"

SpindaIsland_Home_EventScript_MadelineSign_Text_0:
# 181 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Madeline$"

SpindaIsland_Home_EventScript_PoemGirl_Text_0:
# 191 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Maggie$"

SpindaIsland_Home_EventScript_PoemGirl_Text_1:
# 193 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "See you around, Archie…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_2:
# 210 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Archie…\p"
	.string "I want to hear a poem…\p"
	.string "I want you to reveal your heart to me.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_3:
# 224 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Ocean waves swimming…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_4:
# 225 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Roses are red…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_5:
# 226 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Roses are blue…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_6:
# 238 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "From the center of the sea…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_7:
# 239 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "They are calling to my heart…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_8:
# 251 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "With faith to reach land.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_9:
# 252 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Only to go back.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_10:
# 262 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "And my heart to theirs.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_11:
# 263 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Yearning for a touch.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_12:
# 270 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "That was very beautiful.\p"
	.string "I'm not really into haiku, though.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_13:
# 283 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Violets are blue…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_14:
# 284 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Just like our love…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_15:
# 296 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "The sky is pretty…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_16:
# 297 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "The Pincurchin are spiky…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_17:
# 310 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "And so are you.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_18:
# 311 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "And so are you!$"

SpindaIsland_Home_EventScript_PoemGirl_Text_19:
# 317 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Oh, that's nice.\p"
	.string "You're not truly revealing your poet's\n"
	.string "heart, though.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_20:
# 339 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "That's… a weird comparison.\p"
	.string "I thought you were a better poet\n"
	.string "than that.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_21:
# 355 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Which blooms like they do.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_22:
# 356 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Wait, I didn't mean to say that.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_23:
# 362 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Wow, Archie, uh…\p"
	.string "That's not really what I meant when I\n"
	.string "said you should reveal your heart.\p"
	.string "(Well, this is awkward.)\p"
	.string "(Let's pretend this never happened.)$"

SpindaIsland_Home_EventScript_PoemGirl_Text_24:
# 378 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Violets are red…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_25:
# 392 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "The sky isn't blue, it's purple instead.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_26:
# 393 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Doesn't make sense, but fun to be said.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_27:
# 399 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hmm…\p"
	.string "You're not revealing your heart right\n"
	.string "now.\p"
	.string "Plus, that didn't make any sense.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_28:
# 415 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Orchids are blue, too.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_29:
# 416 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Everything is blue…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_30:
# 438 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Because it's my favorite color.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_31:
# 443 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "… … … … …\p"
	.string "Wow, Archie, I…\p"
	.string "This was so touching…\p"
	.string "Thank you for revealing your heart to\n"
	.string "me like this.\p"
	.string "Here, take this.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_32:
# 457 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "It's a blade of grass large enough to\n"
	.string "whistle with.$"

SpindaIsland_Home_EventScript_Sunbather_Text_0:
# 475 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Ahh, it sure feels good to be sitting\n"
	.string "in the sun surrounded by all this\l"
	.string "{COLOR BLUE}WATER{COLOR DARK_GRAY}…$"

SpindaIsland_Home_EventScript_Sunbather_Text_1:
# 484 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Could you leave? You're blocking the\n"
	.string "sun.$"

SpindaIsland_Home_Slowpoke_Text_0:
# 497 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Slowbro$"

SpindaIsland_Home_Slowpoke_Text_1:
# 499 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Bruh…$"

SpindaIsland_Home_Slowpoke_Text_2:
# 506 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Slowpoke$"

SpindaIsland_Home_Slowpoke_Text_3:
# 508 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Slo…$"

SpindaIsland_Home_Slowpoke_Text_4:
# 517 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "… … …?\p"
	.string "He's looking at the white seashell I\n"
	.string "found…$"

SpindaIsland_Home_Slowpoke_Text_5:
# 528 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Give the seashell$"

SpindaIsland_Home_Slowpoke_Text_6:
# 529 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Don't give the seashell$"

SpindaIsland_Home_Slowpoke_Text_7:
# 539 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Sure, why the hell not!\p"
	.string "Here you go, buddy.$"

SpindaIsland_Home_Slowpoke_Text_8:
# 558 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Bruh!!$"

SpindaIsland_Home_Slowpoke_Text_9:
# 566 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "The heck?!\p"
	.string "My seashell bit him!$"

SpindaIsland_Home_Slowpoke_Text_10:
# 572 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Guess it was a Shellder all this time!$"

SpindaIsland_Home_Slowpoke_Text_11:
# 582 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "…Slo…\p"
	.string ":($"

SpindaIsland_Home_EventScript_Metapod_Text_0:
# 596 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Metapod$"

SpindaIsland_Home_EventScript_Metapod_Text_1:
# 599 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "…$"

SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0:
# 608 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Twin 1$"

SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_1:
# 610 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "What is it?!\p"
	.string "Oh, I guess we are blocking the stairs\n"
	.string "a little…\p"
	.string "Fine, we'll take our epic battle\n"
	.string "somewhere else.$"

SpindaIsland_Home_EventScript_MetapodBoy1_Text_0:
# 632 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I'm SO CLOSE to winning!$"

SpindaIsland_Home_EventScript_MetapodBoy1_Text_1:
# 640 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "What? You're distracting me!$"

SpindaIsland_Home_EventScript_MetapodBoy1_Text_2:
# 648 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Metapod, use harden!!$"

SpindaIsland_Home_EventScript_MetapodBoy2_Text_0:
# 668 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Can't you see we're in the midst of a\n"
	.string "fiery battle?$"

SpindaIsland_Home_PhotoCameraWrongDir_Text_0:
# 693 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Nothing left but a pile of ashes…$"

SpindaIsland_Home_PhotoCameraWrongDir_Text_1:
# 701 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Can't use that from this side.$"

SpindaIsland_Home_SlowpokeMistress_Text_0:
# 740 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Girl$"

SpindaIsland_Home_SlowpokeMistress_Text_1:
# 742 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Look at my super cool Slowbro!\p"
	.string "He just looks so happy!$"

SpindaIsland_Home_SlowpokeMistress_Text_2:
# 757 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "By Arceus!!\p"
	.string "How on earth did you convince him to\n"
	.string "evolve?$"

SpindaIsland_Home_SlowpokeMistress_Text_3:
# 763 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "…A cool-looking seashell? What are\n"
	.string "you talking about?$"

SpindaIsland_Home_SlowpokeMistress_Text_4:
# 768 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Well, thank you anyway! You can have\n"
	.string "this!$"

SpindaIsland_Home_SlowpokeMistress_Text_5:
# 773 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I no longer need it.$"

SpindaIsland_Home_SlowpokeMistress_Text_6:
# 783 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hmm… A {COLOR BLUE}WATER{COLOR DARK_GRAY} Stone…\p"
	.string "Maybe I could try giving this to mom?$"

SpindaIsland_Home_SlowpokeMistress_Text_7:
# 794 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I wish my Pokémon would evolve…$"

SpindaIsland_Home_SlowpokeMistress_Text_8:
# 799 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I keep trying to give him this Water\n"
	.string "Stone, but it just does nothing.\p"
	.string "Perhaps there's another way…$"

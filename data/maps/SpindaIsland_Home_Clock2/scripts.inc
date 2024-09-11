SpindaIsland_Home_Clock2_MapScripts::
# 4 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SpindaIsland_Home_Clock2_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 14 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, SpindaIsland_Home_Clock2_MapScripts_MAP_SCRIPT_ON_LOAD
# 11 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SpindaIsland_Home_Clock2_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

SpindaIsland_Home_Clock2_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 5 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	goto_if_set FLAG_SLOWPOKE_EVOLVED, SpindaIsland_Home_Clock2_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
# 8 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( SLOWPOKE )
	return

SpindaIsland_Home_Clock2_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 6 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( SLOWBRO )
	return

SpindaIsland_Home_Clock2_MapScripts_MAP_SCRIPT_ON_LOAD:
# 15 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	goto_if_set FLAG_CAMERA_EXPLODED, SpindaIsland_Home_Clock2_MapScripts_MAP_SCRIPT_ON_LOAD_2
SpindaIsland_Home_Clock2_MapScripts_MAP_SCRIPT_ON_LOAD_1:
# 19 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	goto_if_set FLAG_OPENED_CHEST, SpindaIsland_Home_Clock2_MapScripts_MAP_SCRIPT_ON_LOAD_4
	return

SpindaIsland_Home_Clock2_MapScripts_MAP_SCRIPT_ON_LOAD_2:
# 16 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	setmetatile 45, 30, METATILE_SpindaIslandSecondary_HouseBottomLeftCorner, TRUE
# 17 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	setmetatile 45, 31, METATILE_SpindaIsland_Grass, FALSE
	goto SpindaIsland_Home_Clock2_MapScripts_MAP_SCRIPT_ON_LOAD_1

SpindaIsland_Home_Clock2_MapScripts_MAP_SCRIPT_ON_LOAD_4:
# 20 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	setmetatile 6, 32, METATILE_SpindaIsland_EmptyChestBack, TRUE
	return

SpindaIsland_Home_Clock2_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 12 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	map_script_2 VAR_SPINDA_ISLAND_INTRO_STATE, 2, SpindaIsland_Home_EventScript_MainQuestRecap
	.2byte 0


SpindaIsland_Home_Clock2_EventScript_SadManHome_Front::
# 26 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	lock
# 27 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	goto_if_unset FLAG_HIDE_MAN_CANT_GO_HOME, SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_2
	checkitem ITEM_RUSTY_BOLT
# 0 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_5
# 45 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 46 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_0
# 47 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_3
# 50 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
# 51 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	closemessage
# 53 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_4
# 54 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_5
# 57 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_1:
# 60 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	release
	return

SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_2:
# 28 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 29 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_0
# 30 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_1
# 33 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
# 34 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	closemessage
	goto SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_1

SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_5:
# 37 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 38 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_0
# 39 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_2
# 42 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
# 43 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	closemessage
	goto SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_1


SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome::
# 64 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	lock
# 65 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	faceplayer
# 66 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_SAD
# 67 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_0
# 68 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_1
# 73 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
# 74 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	closemessage
# 76 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	playse SE_PIN
# 77 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	applymovement 7, Common_Movement_ExclamationMark
# 78 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	waitmovement 0
# 79 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay 48
# 81 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	applymovement 7, SpindaIsland_Home_Clock2_Movement_SadManSurprise
# 82 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	waitmovement 0
# 84 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_NORMAL
# 85 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_2
# 86 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_3
# 90 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
# 91 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	closemessage
# 93 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	faceplayer
# 94 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_NORMAL
# 95 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_2
# 96 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_4
# 100 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_5, SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_6
# 110 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	closemessage
# 112 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_2
# 113 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_7
# 119 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
# 120 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	closemessage
# 122 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 123 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_0
# 124 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_8
# 127 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
# 128 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	closemessage
# 130 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_NORMAL
# 131 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_2
# 132 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_9
# 135 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
# 136 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	closemessage
# 138 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 139 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_0
# 140 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_10
# 143 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
# 144 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	closemessage
# 146 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_NORMAL
# 147 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_2
# 148 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_11
# 152 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
# 153 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	closemessage
# 155 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 156 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_0
# 157 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_12
# 160 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
# 161 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	closemessage
# 163 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_NORMAL
# 164 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_4
# 165 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_13
# 169 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
# 170 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	closemessage
# 172 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	switch VAR_FACING
# 173 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	case DIR_NORTH, SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_3
# 175 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	case DIR_SOUTH, SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_4
# 177 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	case DIR_WEST, SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_5
# 179 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	case DIR_EAST, SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_6
SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_1:
# 182 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	waitmovement 0
# 183 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
# 184 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	waitmovement 0
# 186 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	playse SE_EXIT
# 187 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	waitse
# 188 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removeobject 7
# 189 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	setflag FLAG_HIDE_MAN_CANT_GO_HOME
# 191 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay 48
# 193 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 194 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_0
# 195 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_14
# 199 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
# 200 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	closemessage
# 202 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	release
	return

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_3:
# 174 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	applymovement 7, SpindaIsland_Home_Clock2_Movement_SadManEntersHome
	goto SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_1

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_4:
# 176 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	applymovement 7, SpindaIsland_Home_Clock2_Movement_SadManEntersHome
	goto SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_1

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_5:
# 178 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	applymovement 7, SpindaIsland_Home_Clock2_Movement_SadManEntersHome
	goto SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_1

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_6:
# 180 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	applymovement 7, SpindaIsland_Home_Clock2_Movement_SadManEntersHomeAroundPlayer
	goto SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_1


SpindaIsland_Home_Clock2_EventScript_SadManHomeWindow::
# 206 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	lock
# 207 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	goto_if_set FLAG_HIDE_MAN_CANT_GO_HOME, SpindaIsland_Home_Clock2_EventScript_SadManHomeWindow_3
SpindaIsland_Home_Clock2_EventScript_SadManHomeWindow_1:
# 216 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	release
	return

SpindaIsland_Home_Clock2_EventScript_SadManHomeWindow_2:
# 208 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_4
# 209 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_SadManHomeWindow_Text_0
# 213 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	closemessage
	goto SpindaIsland_Home_Clock2_EventScript_SadManHomeWindow_1

SpindaIsland_Home_Clock2_EventScript_SadManHomeWindow_3:
# 207 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	goto_if_unset FLAG_RECEIVED_RUSTY_BOLT, SpindaIsland_Home_Clock2_EventScript_SadManHomeWindow_2
	goto SpindaIsland_Home_Clock2_EventScript_SadManHomeWindow_1


SpindaIsland_Home_Clock2_SadMansHomeSign::
# 220 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_SadMansHomeSign_Text_0, MSGBOX_SIGN
	return


SpindaIsland_Home_Clock2_EventScript_FindSeashell::
# 224 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	lock
# 225 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 226 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_0
# 227 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_FindSeashell_Text_0
# 231 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
# 233 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	giveitem ITEM_WHITE_SEASHELL
# 234 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	setflag FLAG_FOUND_WHITE_SEASHELL
# 235 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removeobject VAR_LAST_TALKED
# 237 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	release
	return


SpindaIsland_Home_Clock2_EventScript_NoteBehindFaucetSign::
# 241 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_NoteBehindFaucetSign_Text_0, MSGBOX_SIGN
	return


SpindaIsland_Home_Clock2_EventScript_ExplanationSign::
# 247 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_ExplanationSign_Text_0, MSGBOX_SIGN
	return


SpindaIsland_Home_EventScript_StealWheel::
# 258 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	lock
# 259 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	goto_if_set FLAG_FAUCET_QUEST_STARTED, SpindaIsland_Home_EventScript_StealWheel_4
SpindaIsland_Home_EventScript_StealWheel_3:
# 300 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 301 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_0
# 302 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_StealWheel_Text_0
# 305 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
# 306 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	closemessage
SpindaIsland_Home_EventScript_StealWheel_1:
# 308 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_StealWheel_2:
# 260 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 261 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_0
# 262 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_StealWheel_Text_0
# 265 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
# 266 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 267 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_StealWheel_Text_1
# 271 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
	checkitem ITEM_BORROWED_PLIERS
# 0 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne SpindaIsland_Home_EventScript_StealWheel_7
# 292 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 293 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_StealWheel_Text_3
# 296 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
# 297 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_StealWheel_1

SpindaIsland_Home_EventScript_StealWheel_4:
# 259 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	goto_if_unset FLAG_FOUND_TOUGH_BOLT, SpindaIsland_Home_EventScript_StealWheel_2
	goto SpindaIsland_Home_EventScript_StealWheel_3

SpindaIsland_Home_EventScript_StealWheel_7:
# 274 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 275 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_StealWheel_Text_2
# 278 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
# 279 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	closemessage
# 281 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	playse SE_CLICK
# 282 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	waitse
# 283 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	playse SE_CLICK
# 284 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	waitse
# 286 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay 48
# 288 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	giveitem ITEM_TOUGH_BOLT
# 289 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	setflag FLAG_FOUND_TOUGH_BOLT
# 290 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	call SpindaIsland_Common_CheckGotAllItemsForNewFaucet
	goto SpindaIsland_Home_EventScript_StealWheel_1


# 311 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
SpindaIsland_Home_Clock2_Movement_SadManEntersHome:
# 312 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	walk_left
# 312 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	walk_left
# 312 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	walk_left
# 313 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	walk_up
# 314 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	face_up
	step_end

# 317 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
SpindaIsland_Home_Clock2_Movement_SadManEntersHomeAroundPlayer:
# 318 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	walk_up
# 319 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	walk_left
# 319 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	walk_left
# 319 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	walk_left
# 320 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	face_up
	step_end

# 323 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
SpindaIsland_Home_Clock2_Movement_SadManSurprise:
# 324 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 324 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 324 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 325 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	face_right
# 326 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 326 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 327 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	face_down
# 328 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 328 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 329 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	face_up
# 330 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 330 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 331 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	face_left
# 332 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 332 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 333 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	jump_in_place_left
# 334 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 334 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 334 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
	step_end

SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_0:
# 29 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "Little Archie$"

SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_1:
# 31 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "Door's locked.$"

SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_2:
# 40 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "I guess I should leave him alone now.$"

SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_3:
# 48 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "Mister? Can you hear me?$"

SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_4:
# 53 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "Stingy man$"

SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_5:
# 55 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "Go away!$"

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_0:
# 67 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "Sad man$"

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_1:
# 69 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "Curse the architect that built my\n"
	.string "house facing the wrong direction!!\p"
	.string "I can never go home!\p"
	.string "… …$"

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_2:
# 85 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "Fulfilled man$"

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_3:
# 87 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "My house! It's facing the right\n"
	.string "direction!\p"
	.string "But what… how…$"

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_4:
# 97 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "Did… did you do something?$"

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_5:
# 107 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "I didn't do anything special…$"

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_6:
# 108 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "I… turned around?$"

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_7:
# 114 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "Don't be modest, kid!\p"
	.string "I don't know how you did it, but you\n"
	.string "saved me from a life of endless\l"
	.string "waiting and suffering!\p"
	.string "I can finally go home.\p"
	.string "Well, goodbye.$"

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_8:
# 125 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "…$"

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_9:
# 133 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "… …$"

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_10:
# 141 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "… … …$"

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_11:
# 149 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "… … … …\p"
	.string "… … …{PAUSE 20}What?$"

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_12:
# 158 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "Well… Don't I get a reward or\n"
	.string "something?$"

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_13:
# 166 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "No. I don't owe you anything.\p"
	.string "Don't follow me.$"

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_14:
# 196 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "He's probably just in shock.\p"
	.string "I'm sure I can make him change his\n"
	.string "mind.$"

SpindaIsland_Home_Clock2_EventScript_SadManHomeWindow_Text_0:
# 210 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "What…\p"
	.string "Are you kidding? I said go away!$"

SpindaIsland_Home_Clock2_SadMansHomeSign_Text_0:
# 220 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "Marcus$"

SpindaIsland_Home_Clock2_EventScript_FindSeashell_Text_0:
# 228 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "Woah, what's this?\p"
	.string "This seashell's completely white! So\n"
	.string "cool!!$"

SpindaIsland_Home_Clock2_EventScript_NoteBehindFaucetSign_Text_0:
# 242 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "“look down”$"

SpindaIsland_Home_Clock2_EventScript_ExplanationSign_Text_0:
# 248 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "“This world is a little strange.\n"
	.string "When an object is turned to the side,\l"
	.string "you cannot interact with it.\l"
	.string "It has to face {COLOR RED}you{COLOR DARK_GRAY}.\l"
	.string "Not your body, but your very soul.\l"
	.string "What could be called the {COLOR RED}true you{COLOR DARK_GRAY}.”$"

SpindaIsland_Home_EventScript_StealWheel_Text_0:
# 263 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "Just a regular wheel.$"

SpindaIsland_Home_EventScript_StealWheel_Text_1:
# 268 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "Wait, it's stuck to the car with bolts!\p"
	.string "If I could just take one…$"

SpindaIsland_Home_EventScript_StealWheel_Text_2:
# 276 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "Here, let me just…$"

SpindaIsland_Home_EventScript_StealWheel_Text_3:
# 294 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "I'd need some pliers to get it out.$"

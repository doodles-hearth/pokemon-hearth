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
	goto_if_set FLAG_CAMERA_EXPLODED, SpindaIsland_Home_Clock2_MapScripts_MAP_SCRIPT_ON_LOAD_1
	return

SpindaIsland_Home_Clock2_MapScripts_MAP_SCRIPT_ON_LOAD_1:
# 16 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	setmetatile 45, 30, METATILE_SpindaIslandSecondary_HouseBottomLeftCorner, TRUE
# 17 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	setmetatile 45, 31, METATILE_SpindaIsland_Grass, FALSE
	return

SpindaIsland_Home_Clock2_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 12 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	map_script_2 VAR_SPINDA_ISLAND_INTRO_STATE, 2, SpindaIsland_Home_EventScript_MainQuestRecap
	.2byte 0


SpindaIsland_Home_Clock2_EventScript_SadManHome_Front::
# 23 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	lock
# 24 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	goto_if_unset FLAG_HIDE_MAN_CANT_GO_HOME, SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_2
	checkitem ITEM_RUSTY_BOLT
# 0 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_5
# 42 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 43 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_0
# 44 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_3
# 47 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
# 48 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	closemessage
# 50 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_4
# 51 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_5
# 54 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_1:
# 57 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	release
	return

SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_2:
# 25 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 26 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_0
# 27 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_1
# 30 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
# 31 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	closemessage
	goto SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_1

SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_5:
# 34 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 35 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_0
# 36 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_2
# 39 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
# 40 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	closemessage
	goto SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_1


SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome::
# 61 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	lock
# 62 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	faceplayer
# 63 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_SAD
# 64 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_0
# 65 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_1
# 70 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
# 71 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	closemessage
# 73 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	playse SE_PIN
# 74 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	applymovement 7, Common_Movement_ExclamationMark
# 75 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	waitmovement 0
# 76 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay 48
# 78 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	applymovement 7, SpindaIsland_Home_Clock2_Movement_SadManSurprise
# 79 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	waitmovement 0
# 81 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_NORMAL
# 82 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_2
# 83 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_3
# 87 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
# 88 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	closemessage
# 90 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	faceplayer
# 91 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_NORMAL
# 92 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_2
# 93 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_4
# 97 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_5, SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_6
# 107 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	closemessage
# 109 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_2
# 110 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_7
# 116 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
# 117 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	closemessage
# 119 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 120 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_0
# 121 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_8
# 124 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
# 125 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	closemessage
# 127 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_NORMAL
# 128 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_2
# 129 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_9
# 132 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
# 133 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	closemessage
# 135 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 136 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_0
# 137 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_10
# 140 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
# 141 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	closemessage
# 143 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_NORMAL
# 144 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_2
# 145 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_11
# 149 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
# 150 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	closemessage
# 152 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 153 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_0
# 154 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_12
# 157 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
# 158 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	closemessage
# 160 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_NORMAL
# 161 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_4
# 162 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_13
# 166 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
# 167 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	closemessage
# 169 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	switch VAR_FACING
# 170 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	case DIR_NORTH, SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_3
# 172 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	case DIR_SOUTH, SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_4
# 174 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	case DIR_WEST, SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_5
# 176 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	case DIR_EAST, SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_6
SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_1:
# 179 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	waitmovement 0
# 180 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
# 181 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	waitmovement 0
# 183 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	playse SE_EXIT
# 184 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	waitse
# 185 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removeobject 7
# 186 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	setflag FLAG_HIDE_MAN_CANT_GO_HOME
# 188 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay 48
# 190 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 191 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_0
# 192 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_14
# 196 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
# 197 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	closemessage
# 199 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	release
	return

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_3:
# 171 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	applymovement 7, SpindaIsland_Home_Clock2_Movement_SadManEntersHome
	goto SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_1

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_4:
# 173 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	applymovement 7, SpindaIsland_Home_Clock2_Movement_SadManEntersHome
	goto SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_1

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_5:
# 175 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	applymovement 7, SpindaIsland_Home_Clock2_Movement_SadManEntersHome
	goto SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_1

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_6:
# 177 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	applymovement 7, SpindaIsland_Home_Clock2_Movement_SadManEntersHomeAroundPlayer
	goto SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_1


SpindaIsland_Home_Clock2_EventScript_FindSeashell::
# 203 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	lock
# 204 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 205 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_0
# 206 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_FindSeashell_Text_0
# 210 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
# 212 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	giveitem ITEM_WHITE_SEASHELL
# 213 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	setflag FLAG_FOUND_WHITE_SEASHELL
# 214 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removeobject VAR_LAST_TALKED
# 216 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	release
	return


SpindaIsland_Home_Clock2_EventScript_NoteBehindFaucetSign::
# 220 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_NoteBehindFaucetSign_Text_0, MSGBOX_SIGN
	return


SpindaIsland_Home_Clock2_EventScript_ExplanationSign::
# 226 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_ExplanationSign_Text_0, MSGBOX_SIGN
	return


SpindaIsland_Home_EventScript_StealWheel::
# 237 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	lock
# 238 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	goto_if_set FLAG_FAUCET_QUEST_STARTED, SpindaIsland_Home_EventScript_StealWheel_4
SpindaIsland_Home_EventScript_StealWheel_3:
# 279 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 280 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_0
# 281 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_StealWheel_Text_0
# 284 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
# 285 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	closemessage
SpindaIsland_Home_EventScript_StealWheel_1:
# 287 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_StealWheel_2:
# 239 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 240 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_0
# 241 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_StealWheel_Text_0
# 244 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
# 245 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 246 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_StealWheel_Text_1
# 250 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
	checkitem ITEM_BORROWED_PLIERS
# 0 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne SpindaIsland_Home_EventScript_StealWheel_7
# 271 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 272 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_StealWheel_Text_3
# 275 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
# 276 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_StealWheel_1

SpindaIsland_Home_EventScript_StealWheel_4:
# 238 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	goto_if_unset FLAG_FOUND_TOUGH_BOLT, SpindaIsland_Home_EventScript_StealWheel_2
	goto SpindaIsland_Home_EventScript_StealWheel_3

SpindaIsland_Home_EventScript_StealWheel_7:
# 253 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 254 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_StealWheel_Text_2
# 257 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
# 258 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	closemessage
# 260 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	playse SE_CLICK
# 261 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	waitse
# 262 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	playse SE_CLICK
# 263 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	waitse
# 265 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay 48
# 267 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	giveitem ITEM_TOUGH_BOLT
# 268 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	setflag FLAG_FOUND_TOUGH_BOLT
# 269 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	call SpindaIsland_Common_CheckGotAllItemsForNewFaucet
	goto SpindaIsland_Home_EventScript_StealWheel_1


# 290 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
SpindaIsland_Home_Clock2_Movement_SadManEntersHome:
# 291 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	walk_left
# 291 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	walk_left
# 291 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	walk_left
# 292 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	walk_up
# 292 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	walk_up
	step_end

# 295 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
SpindaIsland_Home_Clock2_Movement_SadManEntersHomeAroundPlayer:
# 296 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	walk_up
# 297 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	walk_left
# 297 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	walk_left
# 297 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	walk_left
# 298 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	walk_up
	step_end

# 301 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
SpindaIsland_Home_Clock2_Movement_SadManSurprise:
# 302 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 302 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 302 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 303 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	face_right
# 304 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 304 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 305 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	face_down
# 306 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 306 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 307 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	face_up
# 308 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 308 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 309 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	face_left
# 310 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 310 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 311 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	jump_in_place_left
# 312 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 312 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 312 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
	step_end

SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_0:
# 26 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "Little Archie$"

SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_1:
# 28 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "Door's locked.$"

SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_2:
# 37 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "I guess I should leave him alone now.$"

SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_3:
# 45 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "Mister? Can you hear me?$"

SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_4:
# 50 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "Stingy man$"

SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_5:
# 52 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "Go away!$"

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_0:
# 64 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "Sad man$"

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_1:
# 66 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "Curse the architect that built my\n"
	.string "house facing the wrong direction!!\p"
	.string "I can never go home!\p"
	.string "… …$"

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_2:
# 82 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "Fulfilled man$"

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_3:
# 84 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "My house! It's facing the right\n"
	.string "direction!\p"
	.string "But what… how…$"

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_4:
# 94 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "Did… did you do something?$"

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_5:
# 104 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "I didn't do anything special…$"

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_6:
# 105 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "I… turned around?$"

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_7:
# 111 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "Don't be modest, kid!\p"
	.string "I don't know how you did it, but you\n"
	.string "saved me from a life of endless\l"
	.string "waiting and suffering!\p"
	.string "I can finally go home.\p"
	.string "Well, goodbye.$"

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_8:
# 122 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "…$"

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_9:
# 130 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "… …$"

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_10:
# 138 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "… … …$"

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_11:
# 146 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "… … … …\p"
	.string "… … …{PAUSE 20}What?$"

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_12:
# 155 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "Well… Don't I get a reward or\n"
	.string "something?$"

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_13:
# 163 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "No. I don't owe you anything.\p"
	.string "Don't follow me.$"

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_14:
# 193 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "He's probably just in shock.\p"
	.string "I'm sure I can make him change his\n"
	.string "mind.$"

SpindaIsland_Home_Clock2_EventScript_FindSeashell_Text_0:
# 207 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "Woah, what's this?\p"
	.string "This seashell's completely white! So\n"
	.string "cool!!$"

SpindaIsland_Home_Clock2_EventScript_NoteBehindFaucetSign_Text_0:
# 221 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "“look down”$"

SpindaIsland_Home_Clock2_EventScript_ExplanationSign_Text_0:
# 227 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "“This world is a little strange.\n"
	.string "When an object is turned to the side,\l"
	.string "you cannot interact with it.\l"
	.string "It has to face {COLOR RED}you{COLOR DARK_GRAY}.\l"
	.string "Not your body, but your very soul.\l"
	.string "What could be called the {COLOR RED}true you{COLOR DARK_GRAY}.”$"

SpindaIsland_Home_EventScript_StealWheel_Text_0:
# 242 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "Just a regular wheel.$"

SpindaIsland_Home_EventScript_StealWheel_Text_1:
# 247 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "Wait, it's stuck to the car with bolts!\p"
	.string "If I could just take one…$"

SpindaIsland_Home_EventScript_StealWheel_Text_2:
# 255 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "Here, let me just…$"

SpindaIsland_Home_EventScript_StealWheel_Text_3:
# 273 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "I'd need some pliers to get it out.$"

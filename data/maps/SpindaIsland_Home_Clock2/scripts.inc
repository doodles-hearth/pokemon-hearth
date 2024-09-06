SpindaIsland_Home_Clock2_MapScripts::
# 4 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SpindaIsland_Home_Clock2_MapScripts_MAP_SCRIPT_ON_TRANSITION
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

SpindaIsland_Home_Clock2_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 12 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	map_script_2 VAR_SPINDA_ISLAND_INTRO_STATE, 2, SpindaIsland_Home_EventScript_MainQuestRecap
	.2byte 0


SpindaIsland_Home_Clock2_EventScript_SadManHome_Front::
# 17 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	lock
# 18 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	goto_if_unset FLAG_HIDE_MAN_CANT_GO_HOME, SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_2
	checkitem ITEM_RUSTY_BOLT
# 0 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_5
# 36 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 37 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_0
# 38 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_3
# 41 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
# 42 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	closemessage
# 44 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_4
# 45 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_5
# 48 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_1:
# 51 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	release
	return

SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_2:
# 19 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 20 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_0
# 21 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_1
# 24 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
# 25 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	closemessage
	goto SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_1

SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_5:
# 28 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 29 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_0
# 30 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_2
# 33 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
# 34 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	closemessage
	goto SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_1


SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome::
# 55 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	lock
# 56 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	faceplayer
# 57 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_SAD
# 58 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_0
# 59 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_1
# 64 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
# 65 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	closemessage
# 67 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	playse SE_PIN
# 68 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	applymovement 3, Common_Movement_ExclamationMark
# 69 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	waitmovement 0
# 70 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay 48
# 72 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	applymovement 3, SpindaIsland_Home_Clock2_Movement_SadManSurprise
# 73 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	waitmovement 0
# 75 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_NORMAL
# 76 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_2
# 77 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_3
# 81 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
# 82 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	closemessage
# 84 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	faceplayer
# 85 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_NORMAL
# 86 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_2
# 87 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_4
# 91 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_5, SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_6
# 101 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	closemessage
# 103 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_2
# 104 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_7
# 110 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
# 111 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	closemessage
# 113 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 114 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_0
# 115 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_8
# 118 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
# 119 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	closemessage
# 121 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_NORMAL
# 122 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_2
# 123 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_9
# 126 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
# 127 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	closemessage
# 129 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 130 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_0
# 131 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_10
# 134 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
# 135 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	closemessage
# 137 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_NORMAL
# 138 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_2
# 139 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_11
# 143 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
# 144 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	closemessage
# 146 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 147 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_0
# 148 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_12
# 151 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
# 152 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	closemessage
# 154 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_NORMAL
# 155 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_4
# 156 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_13
# 160 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
# 161 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	closemessage
# 163 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	switch VAR_FACING
# 164 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	case DIR_NORTH, SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_3
# 166 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	case DIR_SOUTH, SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_4
# 168 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	case DIR_WEST, SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_5
# 170 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	case DIR_EAST, SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_6
SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_1:
# 173 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	waitmovement 0
# 174 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
# 175 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	waitmovement 0
# 177 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	playse SE_EXIT
# 178 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	waitse
# 179 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removeobject 3
# 180 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	setflag FLAG_HIDE_MAN_CANT_GO_HOME
# 182 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay 48
# 184 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 185 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_0
# 186 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_14
# 190 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
# 191 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	closemessage
# 193 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	release
	return

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_3:
# 165 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	applymovement 3, SpindaIsland_Home_Clock2_Movement_SadManEntersHome
	goto SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_1

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_4:
# 167 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	applymovement 3, SpindaIsland_Home_Clock2_Movement_SadManEntersHome
	goto SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_1

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_5:
# 169 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	applymovement 3, SpindaIsland_Home_Clock2_Movement_SadManEntersHome
	goto SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_1

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_6:
# 171 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	applymovement 3, SpindaIsland_Home_Clock2_Movement_SadManEntersHomeAroundPlayer
	goto SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_1


SpindaIsland_Home_Clock2_EventScript_FindSeashell::
# 197 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	lock
# 198 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 199 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_0
# 200 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_FindSeashell_Text_0
# 204 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
# 206 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	giveitem ITEM_WHITE_SEASHELL
# 207 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	setflag FLAG_FOUND_WHITE_SEASHELL
# 208 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removeobject VAR_LAST_TALKED
# 210 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	release
	return


SpindaIsland_Home_Clock2_EventScript_NoteBehindFaucetSign::
# 214 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_NoteBehindFaucetSign_Text_0, MSGBOX_SIGN
	return


SpindaIsland_Home_Clock2_EventScript_ExplanationSign::
# 220 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_Clock2_EventScript_ExplanationSign_Text_0, MSGBOX_SIGN
	return


SpindaIsland_Home_EventScript_StealWheel::
# 231 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	lock
# 232 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	goto_if_set FLAG_FAUCET_QUEST_STARTED, SpindaIsland_Home_EventScript_StealWheel_4
SpindaIsland_Home_EventScript_StealWheel_3:
# 273 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 274 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_0
# 275 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_StealWheel_Text_0
# 278 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
# 279 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	closemessage
SpindaIsland_Home_EventScript_StealWheel_1:
# 281 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_StealWheel_2:
# 233 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 234 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	speakername SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_0
# 235 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_StealWheel_Text_0
# 238 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
# 239 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 240 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_StealWheel_Text_1
# 244 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
	checkitem ITEM_BORROWED_PLIERS
# 0 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne SpindaIsland_Home_EventScript_StealWheel_7
# 265 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 266 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_StealWheel_Text_3
# 269 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
# 270 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_StealWheel_1

SpindaIsland_Home_EventScript_StealWheel_4:
# 232 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	goto_if_unset FLAG_FOUND_TOUGH_BOLT, SpindaIsland_Home_EventScript_StealWheel_2
	goto SpindaIsland_Home_EventScript_StealWheel_3

SpindaIsland_Home_EventScript_StealWheel_7:
# 247 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 248 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_StealWheel_Text_2
# 251 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	removefieldmugshot
# 252 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	closemessage
# 254 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	playse SE_CLICK
# 255 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	waitse
# 256 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	playse SE_CLICK
# 257 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	waitse
# 259 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay 48
# 261 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	giveitem ITEM_TOUGH_BOLT
# 262 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	setflag FLAG_STOLE_CAR_BOLT
# 263 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	call SpindaIsland_Common_CheckGotAllItemsForNewFaucet
	goto SpindaIsland_Home_EventScript_StealWheel_1


# 284 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
SpindaIsland_Home_Clock2_Movement_SadManEntersHome:
# 285 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	walk_left
# 285 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	walk_left
# 285 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	walk_left
# 286 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	walk_up
# 286 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	walk_up
	step_end

# 289 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
SpindaIsland_Home_Clock2_Movement_SadManEntersHomeAroundPlayer:
# 290 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	walk_up
# 291 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	walk_left
# 291 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	walk_left
# 291 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	walk_left
# 292 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	walk_up
	step_end

# 295 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
SpindaIsland_Home_Clock2_Movement_SadManSurprise:
# 296 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 296 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 296 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 297 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	face_right
# 298 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 298 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 299 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	face_down
# 300 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 300 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 301 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	face_up
# 302 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 302 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 303 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	face_left
# 304 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 304 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 305 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	jump_in_place_left
# 306 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 306 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
# 306 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	delay_16
	step_end

SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_0:
# 20 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "Little Archie$"

SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_1:
# 22 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "Door's locked.$"

SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_2:
# 31 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "I guess I should leave him alone now.$"

SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_3:
# 39 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "Mister? Can you hear me?$"

SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_4:
# 44 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "Stingy man$"

SpindaIsland_Home_Clock2_EventScript_SadManHome_Front_Text_5:
# 46 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "Go away!$"

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_0:
# 58 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "Sad man$"

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_1:
# 60 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "Curse the architect that built my\n"
	.string "house facing the wrong direction!!\p"
	.string "I can never go home!\p"
	.string "… …$"

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_2:
# 76 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "Fulfilled man$"

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_3:
# 78 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "My house! It's facing the right\n"
	.string "direction!\p"
	.string "But what… how…$"

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_4:
# 88 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "Did… did you do something?$"

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_5:
# 98 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "I didn't do anything special…$"

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_6:
# 99 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "I… turned around?$"

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_7:
# 105 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "Don't be modest, kid!\p"
	.string "I don't know how you did it, but you\n"
	.string "saved me from a life of endless\l"
	.string "waiting and suffering!\p"
	.string "I can finally go home.\p"
	.string "Well, goodbye.$"

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_8:
# 116 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "…$"

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_9:
# 124 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "… …$"

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_10:
# 132 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "… … …$"

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_11:
# 140 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "… … … …\p"
	.string "… … …{PAUSE 20}What?$"

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_12:
# 149 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "Well… Don't I get a reward or\n"
	.string "something?$"

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_13:
# 157 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "No. I don't owe you anything.\p"
	.string "Don't follow me.$"

SpindaIsland_Home_Clock2_EventScript_ICanNeverGoHome_GoHome_Text_14:
# 187 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "He's probably just in shock.\p"
	.string "I'm sure I can make him change his\n"
	.string "mind.$"

SpindaIsland_Home_Clock2_EventScript_FindSeashell_Text_0:
# 201 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "Woah, what's this?\p"
	.string "This seashell's completely white! So\n"
	.string "cool!!$"

SpindaIsland_Home_Clock2_EventScript_NoteBehindFaucetSign_Text_0:
# 215 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "“look down”$"

SpindaIsland_Home_Clock2_EventScript_ExplanationSign_Text_0:
# 221 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "“This world is a little strange.\n"
	.string "When an object is turned to the side,\l"
	.string "you cannot interact with it.\l"
	.string "It has to face {COLOR RED}you{COLOR DARK_GRAY}.\l"
	.string "Not your body, but your very soul.\l"
	.string "What could be called the {COLOR RED}true you{COLOR DARK_GRAY}.”$"

SpindaIsland_Home_EventScript_StealWheel_Text_0:
# 236 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "Just a regular wheel.$"

SpindaIsland_Home_EventScript_StealWheel_Text_1:
# 241 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "Wait, it's stuck to the car with bolts!\p"
	.string "If I could just take one…$"

SpindaIsland_Home_EventScript_StealWheel_Text_2:
# 249 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "Here, let me just…$"

SpindaIsland_Home_EventScript_StealWheel_Text_3:
# 267 "data/maps/SpindaIsland_Home_Clock2/scripts.pory"
	.string "I'd need some pliers to get it out.$"

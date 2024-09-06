SpindaIsland_Home_MapScripts::
# 5 "data/maps/SpindaIsland_Home/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SpindaIsland_Home_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 12 "data/maps/SpindaIsland_Home/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SpindaIsland_Home_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

SpindaIsland_Home_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 6 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_SLOWPOKE_EVOLVED, SpindaIsland_Home_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
# 9 "data/maps/SpindaIsland_Home/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( SLOWPOKE )
	return

SpindaIsland_Home_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 7 "data/maps/SpindaIsland_Home/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( SLOWBRO )
	return

SpindaIsland_Home_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 13 "data/maps/SpindaIsland_Home/scripts.pory"
	map_script_2 VAR_SPINDA_ISLAND_INTRO_STATE, 2, SpindaIsland_Home_EventScript_MainQuestRecap
	.2byte 0


SpindaIsland_Home_EventScript_MainQuestRecap::
# 17 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 18 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 19 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 20 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MainQuestRecap_Text_1
# 24 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 25 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 26 "data/maps/SpindaIsland_Home/scripts.pory"
	setvar VAR_SPINDA_ISLAND_INTRO_STATE, 3
# 27 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_MetapodOtherSide::
# 31 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 32 "data/maps/SpindaIsland_Home/scripts.pory"
	setvar VAR_METAPOD_OTHER_SIDE, 1
# 33 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_ArchiesHouseSign::
# 37 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_ArchiesHouseSign_Text_0, MSGBOX_SIGN
	return


SpindaIsland_Home_EventScript_BobsHouseSign::
# 41 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_BobsHouseSign_Text_0, MSGBOX_SIGN
	return


SpindaIsland_Home_EventScript_SadManHome_Back::
# 45 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 46 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_unset FLAG_HIDE_MAN_CANT_GO_HOME, SpindaIsland_Home_EventScript_SadManHome_Back_2
# 55 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_RECEIVED_RUSTY_BOLT, SpindaIsland_Home_EventScript_SadManHome_Back_5
# 64 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 65 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 66 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SadManHome_Back_Text_2
# 69 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 70 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 72 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_SadManHome_Back_Text_3
# 73 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SadManHome_Back_Text_4
# 77 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 79 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_EXIT
# 81 "data/maps/SpindaIsland_Home/scripts.pory"
	clearflag FLAG_HIDE_MAN_CANT_GO_HOME
# 82 "data/maps/SpindaIsland_Home/scripts.pory"
	setobjectxyperm 2, 42, 24
# 83 "data/maps/SpindaIsland_Home/scripts.pory"
	addobject 2
# 84 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement 2, SpindaIsland_Home_Movement_SadManExitsHouse
# 85 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SpindaIsland_Home_Movement_PlayerMakesWay
# 86 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 87 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 2
# 88 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 89 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 90 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_NORMAL
# 91 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_SadManHome_Back_Text_3
# 92 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SadManHome_Back_Text_5
# 95 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 96 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 97 "data/maps/SpindaIsland_Home/scripts.pory"
	giveitem ITEM_RUSTY_BOLT
# 98 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_RECEIVED_RUSTY_BOLT
# 99 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement 2, SpindaIsland_Home_Movement_SadManReEntersHouse
# 100 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 101 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_EXIT
# 102 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject 2
# 103 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_HIDE_MAN_CANT_GO_HOME
# 104 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 106 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 108 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_FAUCET_QUEST_STARTED, SpindaIsland_Home_EventScript_SadManHome_Back_8
# 139 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 140 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 141 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SadManHome_Back_Text_9
# 146 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 147 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
SpindaIsland_Home_EventScript_SadManHome_Back_1:
# 151 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_SadManHome_Back_2:
# 47 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 48 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 49 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SadManHome_Back_Text_0
# 52 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 53 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_SadManHome_Back_1

SpindaIsland_Home_EventScript_SadManHome_Back_5:
# 56 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 57 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 58 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SadManHome_Back_Text_1
# 61 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 62 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_SadManHome_Back_1

SpindaIsland_Home_EventScript_SadManHome_Back_8:
# 109 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 110 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 111 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SadManHome_Back_Text_6
# 114 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 115 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 117 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 119 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_PIN
# 120 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 121 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 122 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 123 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 125 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 126 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 127 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SadManHome_Back_Text_7
# 131 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 132 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 133 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SadManHome_Back_Text_8
# 136 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 137 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_SadManHome_Back_1


SpindaIsland_Home_EventScript_ICanNeverGoHome::
# 155 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 156 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 157 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_SAD
# 158 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_ICanNeverGoHome_Text_0
# 159 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_ICanNeverGoHome_Text_1, MSGBOX_NPC
# 163 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 164 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_Dad::
# 168 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 169 "data/maps/SpindaIsland_Home/scripts.pory"
	turnobject 3, DIR_SOUTH
# 170 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_OBTAINED_LEMONADE, SpindaIsland_Home_EventScript_Dad_2
# 178 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_SPOKE_TO_DAD, SpindaIsland_Home_EventScript_Dad_6
# 185 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_0
# 186 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_3
# 190 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
SpindaIsland_Home_EventScript_Dad_5:
# 193 "data/maps/SpindaIsland_Home/scripts.pory"
	giveitem ITEM_SALTY_LEMONADE
# 195 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 196 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 197 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 198 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_4
# 202 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 203 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 205 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 10
# 206 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_BALL
# 207 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 208 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_BALL
# 209 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 210 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_BALL
# 211 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 212 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 20
# 214 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_PIN
# 215 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
# 216 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 217 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 219 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_DISGUSTED
# 220 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 221 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_5
# 225 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 226 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 228 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_0
# 229 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_6
# 236 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 238 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_OBTAINED_LEMONADE
# 239 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_SPOKE_TO_DAD
SpindaIsland_Home_EventScript_Dad_1:
# 241 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_Dad_2:
# 171 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_0
# 172 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_1
# 176 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_Dad_1

SpindaIsland_Home_EventScript_Dad_6:
# 179 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_0
# 180 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_2
# 183 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_Dad_5


SpindaIsland_Home_EventScript_Dad_FromSide::
# 245 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 246 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 247 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_OBTAINED_LEMONADE, SpindaIsland_Home_EventScript_Dad_FromSide_2
# 255 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_SPOKE_TO_DAD, SpindaIsland_Home_EventScript_Dad_FromSide_6
# 262 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_0
# 263 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_FromSide_Text_1
# 268 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
SpindaIsland_Home_EventScript_Dad_FromSide_5:
# 270 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_SPOKE_TO_DAD
SpindaIsland_Home_EventScript_Dad_FromSide_1:
# 272 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_Dad_FromSide_2:
# 248 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_0
# 249 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_1
# 253 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_Dad_FromSide_1

SpindaIsland_Home_EventScript_Dad_FromSide_6:
# 256 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_0
# 257 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_FromSide_Text_0
# 260 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_Dad_FromSide_5


SpindaIsland_Home_EventScript_LemonadeStandSign::
# 276 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_LemonadeStandSign_Text_0, MSGBOX_SIGN
	return


SpindaIsland_Home_EventScript_MainStreetSign::
# 283 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MainStreetSign_Text_0, MSGBOX_SIGN
	return


SpindaIsland_Home_EventScript_MadelineSign::
# 289 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MadelineSign_Text_0, MSGBOX_SIGN
	return


SpindaIsland_Home_EventScript_PoemGirl::
# 295 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 297 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_POEM_GIRL, SpindaIsland_Home_EventScript_PoemGirl_2
# 311 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_GRASSWHISTLE
# 312 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 314 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 316 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 317 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 318 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_2
# 323 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 324 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 326 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_3, SpindaIsland_Home_EventScript_PoemGirl_Text_4, SpindaIsland_Home_EventScript_PoemGirl_Text_5
# 338 "data/maps/SpindaIsland_Home/scripts.pory"
	switch VAR_RESULT
# 339 "data/maps/SpindaIsland_Home/scripts.pory"
	case 0, SpindaIsland_Home_EventScript_PoemGirl_6
# 384 "data/maps/SpindaIsland_Home/scripts.pory"
	case 1, SpindaIsland_Home_EventScript_PoemGirl_7
# 479 "data/maps/SpindaIsland_Home/scripts.pory"
	case 2, SpindaIsland_Home_EventScript_PoemGirl_8
SpindaIsland_Home_EventScript_PoemGirl_1:
# 576 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 577 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 578 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_PoemGirl_2:
# 298 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 299 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 300 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 301 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_1
# 304 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 305 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 307 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 308 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 309 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_GRASSWHISTLE
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_6:
# 340 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_6, SpindaIsland_Home_EventScript_PoemGirl_Text_7
# 351 "data/maps/SpindaIsland_Home/scripts.pory"
	switch VAR_RESULT
# 352 "data/maps/SpindaIsland_Home/scripts.pory"
	case 0, SpindaIsland_Home_EventScript_PoemGirl_11
# 363 "data/maps/SpindaIsland_Home/scripts.pory"
	case 1, SpindaIsland_Home_EventScript_PoemGirl_12
SpindaIsland_Home_EventScript_PoemGirl_9:
# 376 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 377 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 378 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_12
# 382 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 383 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_7:
# 385 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_13, SpindaIsland_Home_EventScript_PoemGirl_Text_14
# 395 "data/maps/SpindaIsland_Home/scripts.pory"
	switch VAR_RESULT
# 397 "data/maps/SpindaIsland_Home/scripts.pory"
	case 0, SpindaIsland_Home_EventScript_PoemGirl_14
# 456 "data/maps/SpindaIsland_Home/scripts.pory"
	case 1, SpindaIsland_Home_EventScript_PoemGirl_15
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_8:
# 480 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_24, SpindaIsland_Home_EventScript_PoemGirl_Text_13
# 491 "data/maps/SpindaIsland_Home/scripts.pory"
	switch VAR_RESULT
# 493 "data/maps/SpindaIsland_Home/scripts.pory"
	case 0, SpindaIsland_Home_EventScript_PoemGirl_17
# 516 "data/maps/SpindaIsland_Home/scripts.pory"
	case 1, SpindaIsland_Home_EventScript_PoemGirl_18
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_11:
# 353 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_8, SpindaIsland_Home_EventScript_PoemGirl_Text_9
	goto SpindaIsland_Home_EventScript_PoemGirl_9

SpindaIsland_Home_EventScript_PoemGirl_12:
# 364 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_10, SpindaIsland_Home_EventScript_PoemGirl_Text_11
	goto SpindaIsland_Home_EventScript_PoemGirl_9

SpindaIsland_Home_EventScript_PoemGirl_14:
# 398 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_15, SpindaIsland_Home_EventScript_PoemGirl_Text_16
# 409 "data/maps/SpindaIsland_Home/scripts.pory"
	switch VAR_RESULT
# 411 "data/maps/SpindaIsland_Home/scripts.pory"
	case 0, SpindaIsland_Home_EventScript_PoemGirl_20
# 433 "data/maps/SpindaIsland_Home/scripts.pory"
	case 1, SpindaIsland_Home_EventScript_PoemGirl_21
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_15:
# 457 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_21, SpindaIsland_Home_EventScript_PoemGirl_Text_22
# 468 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 469 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 470 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_23
# 476 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 477 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_17:
# 494 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_25, SpindaIsland_Home_EventScript_PoemGirl_Text_26
# 505 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 506 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 507 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_27
# 512 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 513 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_18:
# 517 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_28, SpindaIsland_Home_EventScript_PoemGirl_Text_29
# 528 "data/maps/SpindaIsland_Home/scripts.pory"
	switch VAR_RESULT
# 529 "data/maps/SpindaIsland_Home/scripts.pory"
	case 0, SpindaIsland_Home_EventScript_PoemGirl_23
# 539 "data/maps/SpindaIsland_Home/scripts.pory"
	case 1, SpindaIsland_Home_EventScript_PoemGirl_24
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_20:
# 412 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_17, SpindaIsland_Home_EventScript_PoemGirl_Text_18
# 423 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 424 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 425 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_19
# 429 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 430 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_21:
# 434 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_17, SpindaIsland_Home_EventScript_PoemGirl_Text_18
# 445 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 446 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 447 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_20
# 451 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 452 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_23:
# 530 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 531 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 532 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_27
# 537 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 538 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_24:
# 540 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_30
# 549 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 550 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 551 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_31
# 558 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 559 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 561 "data/maps/SpindaIsland_Home/scripts.pory"
	giveitem ITEM_GRASS_BLADE
# 563 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 564 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 565 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_32
# 568 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 569 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 571 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_POEM_GIRL
	goto SpindaIsland_Home_EventScript_PoemGirl_1


SpindaIsland_Home_EventScript_Sunbather::
# 582 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 583 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_SUNBATHER, EMOTE_NORMAL
# 584 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Sunbather_Text_0
# 585 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Sunbather_Text_1
# 589 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 590 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 591 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 592 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 594 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_SUNBATHER, EMOTE_PENSIVE
# 595 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Sunbather_Text_0
# 596 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Sunbather_Text_2
# 599 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 600 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 601 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 602 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 603 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_Slowpoke::
# 607 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 608 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_SLOWPOKE_EVOLVED, SpindaIsland_Home_Slowpoke_2
# 618 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 619 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_SLOWPOKE, CRY_MODE_NORMAL
# 620 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_Slowpoke_Text_2
# 621 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Slowpoke_Text_3
# 624 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmoncry
# 625 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	checkitem ITEM_WHITE_SEASHELL
# 0 "data/maps/SpindaIsland_Home/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq SpindaIsland_Home_Slowpoke_5
SpindaIsland_Home_Slowpoke_1:
# 705 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_Slowpoke_2:
# 609 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 610 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_SLOWBRO, CRY_MODE_NORMAL
# 611 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_Slowpoke_Text_0
# 612 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Slowpoke_Text_1
# 615 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_Slowpoke_1

SpindaIsland_Home_Slowpoke_5:
# 628 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_THINKING
# 629 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 630 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Slowpoke_Text_4
# 635 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_Slowpoke_Text_5, SpindaIsland_Home_Slowpoke_Text_6
# 645 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 646 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 648 "data/maps/SpindaIsland_Home/scripts.pory"
	switch VAR_RESULT
# 649 "data/maps/SpindaIsland_Home/scripts.pory"
	case 0, SpindaIsland_Home_Slowpoke_8
# 692 "data/maps/SpindaIsland_Home/scripts.pory"
	case 1, SpindaIsland_Home_Slowpoke_9
	goto SpindaIsland_Home_Slowpoke_1

SpindaIsland_Home_Slowpoke_8:
# 650 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 651 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 652 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Slowpoke_Text_7
# 656 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 658 "data/maps/SpindaIsland_Home/scripts.pory"
	removeitem ITEM_WHITE_SEASHELL
# 660 "data/maps/SpindaIsland_Home/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( SLOWBRO )
# 661 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject VAR_LAST_TALKED
# 662 "data/maps/SpindaIsland_Home/scripts.pory"
	addobject VAR_LAST_TALKED
# 663 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_BITE
# 664 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, SpindaIsland_Home_Movement_Slowpoke
# 665 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 666 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement VAR_LAST_TALKED
# 667 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 669 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_SLOWPOKE, CRY_MODE_NORMAL
# 670 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_Slowpoke_Text_0
# 671 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Slowpoke_Text_8
# 674 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmoncry
# 675 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 677 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_SHOCKED
# 678 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 679 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Slowpoke_Text_9
# 683 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 684 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 685 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Slowpoke_Text_10
# 688 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 689 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 691 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_SLOWPOKE_EVOLVED
	goto SpindaIsland_Home_Slowpoke_1

SpindaIsland_Home_Slowpoke_9:
# 693 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_SLOWPOKE, CRY_MODE_FAINT
# 694 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_Slowpoke_Text_2
# 695 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Slowpoke_Text_11
# 699 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmoncry
# 700 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_Slowpoke_1


SpindaIsland_Home_EventScript_Metapod::
# 709 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 710 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Metapod_Text_0
# 711 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_METAPOD, CRY_MODE_NORMAL
# 712 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Metapod_Text_1
# 715 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmoncry
# 716 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 717 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_MetapodBoysFuckOff::
# 721 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 722 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0
# 723 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_1
# 728 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 730 "data/maps/SpindaIsland_Home/scripts.pory"
	fadescreen FADE_TO_BLACK
# 731 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_HIDE_METAPOD_BATTLE
# 732 "data/maps/SpindaIsland_Home/scripts.pory"
	special DrawWholeMapView
# 733 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 60
# 734 "data/maps/SpindaIsland_Home/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 735 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 40
# 736 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_MetapodBoy1::
# 740 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 741 "data/maps/SpindaIsland_Home/scripts.pory"
	compare VAR_METAPOD_OTHER_SIDE, 1
	goto_if_eq SpindaIsland_Home_EventScript_MetapodBoy1_2
SpindaIsland_Home_EventScript_MetapodBoy1_1:
# 744 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0
# 745 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoy1_Text_0
# 748 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 750 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 752 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0
# 753 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoy1_Text_1
# 756 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 758 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 760 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0
# 761 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoy1_Text_2
# 764 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 766 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_HARDEN
# 767 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 768 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_HARDEN
# 769 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 770 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 771 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_MetapodBoy1_2:
# 742 "data/maps/SpindaIsland_Home/scripts.pory"
	goto SpindaIsland_Home_EventScript_MetapodBoysFuckOff
	goto SpindaIsland_Home_EventScript_MetapodBoy1_1


SpindaIsland_Home_EventScript_MetapodBoy2::
# 775 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 776 "data/maps/SpindaIsland_Home/scripts.pory"
	compare VAR_METAPOD_OTHER_SIDE, 1
	goto_if_eq SpindaIsland_Home_EventScript_MetapodBoy2_2
SpindaIsland_Home_EventScript_MetapodBoy2_1:
# 779 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 780 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0
# 781 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoy2_Text_0
# 784 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 785 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 786 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0
# 787 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoy1_Text_2
# 790 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 792 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_HARDEN
# 793 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 794 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_HARDEN
# 795 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 796 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 797 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_MetapodBoy2_2:
# 777 "data/maps/SpindaIsland_Home/scripts.pory"
	goto SpindaIsland_Home_EventScript_MetapodBoysFuckOff
	goto SpindaIsland_Home_EventScript_MetapodBoy2_1


SpindaIsland_Home_PhotoCameraWrongDir::
# 801 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 803 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_CAMERA_EXPLODED, SpindaIsland_Home_PhotoCameraWrongDir_2
# 812 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 813 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 814 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_PhotoCameraWrongDir_Text_1
# 817 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 818 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
SpindaIsland_Home_PhotoCameraWrongDir_1:
# 823 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_PhotoCameraWrongDir_2:
# 804 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 805 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 806 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_PhotoCameraWrongDir_Text_0
# 809 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 810 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
	goto SpindaIsland_Home_PhotoCameraWrongDir_1


# 826 "data/maps/SpindaIsland_Home/scripts.pory"
SpindaIsland_Home_Movement_SadManExitsHouse:
# 827 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_down
	step_end

# 830 "data/maps/SpindaIsland_Home/scripts.pory"
SpindaIsland_Home_Movement_SadManReEntersHouse:
# 831 "data/maps/SpindaIsland_Home/scripts.pory"
	face_up
# 832 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 833 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
	step_end

# 836 "data/maps/SpindaIsland_Home/scripts.pory"
SpindaIsland_Home_Movement_PlayerMakesWay:
# 837 "data/maps/SpindaIsland_Home/scripts.pory"
	lock_facing_direction
# 838 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_down
# 839 "data/maps/SpindaIsland_Home/scripts.pory"
	unlock_facing_direction
	step_end

# 842 "data/maps/SpindaIsland_Home/scripts.pory"
SpindaIsland_Home_Movement_Slowpoke:
# 843 "data/maps/SpindaIsland_Home/scripts.pory"
	lock_facing_direction
# 844 "data/maps/SpindaIsland_Home/scripts.pory"
	jump_in_place_down
# 845 "data/maps/SpindaIsland_Home/scripts.pory"
	unlock_facing_direction
# 846 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 846 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 846 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 847 "data/maps/SpindaIsland_Home/scripts.pory"
	face_up
# 848 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 849 "data/maps/SpindaIsland_Home/scripts.pory"
	face_down
# 850 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 851 "data/maps/SpindaIsland_Home/scripts.pory"
	face_left
# 852 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 853 "data/maps/SpindaIsland_Home/scripts.pory"
	face_up
# 854 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 855 "data/maps/SpindaIsland_Home/scripts.pory"
	face_player
# 856 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 856 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 856 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 857 "data/maps/SpindaIsland_Home/scripts.pory"
	lock_facing_direction
# 858 "data/maps/SpindaIsland_Home/scripts.pory"
	jump_in_place_down
# 859 "data/maps/SpindaIsland_Home/scripts.pory"
	jump_in_place_down
# 860 "data/maps/SpindaIsland_Home/scripts.pory"
	unlock_facing_direction
# 861 "data/maps/SpindaIsland_Home/scripts.pory"
	emote_heart
# 862 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 862 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 862 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
	step_end

SpindaIsland_Home_SlowpokeMistress::
# 866 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 867 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 868 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_RECEIVED_SLOWPOKE_REWARD, SpindaIsland_Home_SlowpokeMistress_2
# 877 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_SLOWPOKE_EVOLVED, SpindaIsland_Home_SlowpokeMistress_3
# 921 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LASS, EMOTE_SWEAT
# 922 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_SlowpokeMistress_Text_0
# 923 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_SlowpokeMistress_Text_7
# 926 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 927 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LASS, EMOTE_NORMAL
# 928 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_SlowpokeMistress_Text_8
# 932 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 933 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
SpindaIsland_Home_SlowpokeMistress_1:
# 935 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_SlowpokeMistress_2:
# 869 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LASS, EMOTE_HAPPY
# 870 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_SlowpokeMistress_Text_0
# 871 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_SlowpokeMistress_Text_1
# 875 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 876 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_SlowpokeMistress_1

SpindaIsland_Home_SlowpokeMistress_3:
# 878 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_PIN
# 879 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
# 880 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 881 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 882 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 884 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LASS, EMOTE_SURPRISED
# 885 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_SlowpokeMistress_Text_0
# 886 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_SlowpokeMistress_Text_2
# 890 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 891 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LASS, EMOTE_NORMAL
# 892 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_SlowpokeMistress_Text_3
# 895 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 896 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LASS, EMOTE_HAPPY
# 897 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_SlowpokeMistress_Text_4
# 900 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 901 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LASS, EMOTE_NORMAL
# 902 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_SlowpokeMistress_Text_5
# 905 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 906 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 908 "data/maps/SpindaIsland_Home/scripts.pory"
	giveitem ITEM_WATER_STONE_2
# 910 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_THINKING
# 911 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 912 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_SlowpokeMistress_Text_6
# 916 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 917 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 919 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_RECEIVED_SLOWPOKE_REWARD
	goto SpindaIsland_Home_SlowpokeMistress_1


SpindaIsland_Home_CarBoy::
	return


SpindaIsland_Home_CarGirl::
	return


SpindaIsland_Home_EventScript_MainQuestRecap_Text_0:
# 19 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Little Archie$"

SpindaIsland_Home_EventScript_MainQuestRecap_Text_1:
# 21 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Alright! The quicker mom gets her\n"
	.string "glass of {COLOR BLUE}WATER{COLOR DARK_GRAY}, the quicker Archie\l"
	.string "gets his super badass pirate {COLOR RED}sail{COLOR DARK_GRAY}!\p"
	.string "Let's get moving!$"

SpindaIsland_Home_EventScript_ArchiesHouseSign_Text_0:
# 37 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "The Hoenns$"

SpindaIsland_Home_EventScript_BobsHouseSign_Text_0:
# 41 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Bob$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_0:
# 50 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Door's locked.$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_1:
# 59 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I guess I should leave him alone now.$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_2:
# 67 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hello? Are you there?$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_3:
# 72 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Stingy man$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_4:
# 74 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "…\p"
	.string "My GOD you're annoying.$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_5:
# 93 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Here's your reward. I hope you're\n"
	.string "happy.$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_6:
# 112 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "An old and rusty bolt? What am I\n"
	.string "supposed to do with this?$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_7:
# 128 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "A {COLOR RED}bolt{COLOR DARK_GRAY}! Of course! Lucky me!\p"
	.string "I'm one step closer to getting that\n"
	.string "sweet sweet faucet replacement!!$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_8:
# 134 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "(Did I really say that? Is this how\n"
	.string "being a grownup feels like?)$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_9:
# 142 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "A bolt?\p"
	.string "It's all rusty…\p"
	.string "Guess it'll join my useless trash\n"
	.string "collection!$"

SpindaIsland_Home_EventScript_ICanNeverGoHome_Text_0:
# 158 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Sad man$"

SpindaIsland_Home_EventScript_ICanNeverGoHome_Text_1:
# 160 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Curse the architect that built my\n"
	.string "house facing the wrong direction!!\p"
	.string "I can never go home!$"

SpindaIsland_Home_EventScript_Dad_Text_0:
# 171 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Dad$"

SpindaIsland_Home_EventScript_Dad_Text_1:
# 173 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Don't uh, pour that lemonade I gave\n"
	.string "you on the ground or anything.\p"
	.string "It'd probably kill all the grass and\n"
	.string "flowers.$"

SpindaIsland_Home_EventScript_Dad_Text_2:
# 181 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Here, have some lemonade!$"

SpindaIsland_Home_EventScript_Dad_Text_3:
# 187 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hiya, sonny! going adventuring today,\n"
	.string "are we?\p"
	.string "Want some lemonade?$"

SpindaIsland_Home_EventScript_Dad_Text_4:
# 199 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Now we're talkin'!! I can bring this to\n"
	.string "mom, that should do it!\p"
	.string "Let's take a sip first, I am PARCHED!$"

SpindaIsland_Home_EventScript_Dad_Text_5:
# 222 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "BLEARGH!\p"
	.string "Why is it… so salty?!$"

SpindaIsland_Home_EventScript_Dad_Text_6:
# 230 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Why, because it's seawater, obviously!\p"
	.string "I take it you're not a fan of my\n"
	.string "recipe?\p"
	.string "(You wouldn't be the only one…)\p"
	.string "In any case, it's nice of you to come\n"
	.string "visit me at the office, haha!\p"
	.string "See you around, little Archie! Don't\n"
	.string "get into trouble!$"

SpindaIsland_Home_EventScript_Dad_FromSide_Text_0:
# 258 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Come round to the front of the\n"
	.string "lemonade stand!$"

SpindaIsland_Home_EventScript_Dad_FromSide_Text_1:
# 264 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hiya, sonny! going adventuring today,\n"
	.string "are we?\p"
	.string "Want some lemonade?\p"
	.string "Come round to the front of the\n"
	.string "lemonade stand!$"

SpindaIsland_Home_EventScript_LemonadeStandSign_Text_0:
# 277 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "“ARCHIE'S LEMONADE\n"
	.string "A taste of the seaside!”$"

SpindaIsland_Home_EventScript_MainStreetSign_Text_0:
# 284 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "{UP_ARROW} Main street$"

SpindaIsland_Home_EventScript_MadelineSign_Text_0:
# 290 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Madeline$"

SpindaIsland_Home_EventScript_PoemGirl_Text_0:
# 300 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Maggie$"

SpindaIsland_Home_EventScript_PoemGirl_Text_1:
# 302 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "See you around, Archie…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_2:
# 319 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Archie…\p"
	.string "I want to hear a poem…\p"
	.string "I want you to reveal your heart to me.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_3:
# 333 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Ocean waves swimming…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_4:
# 334 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Roses are red…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_5:
# 335 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Roses are blue…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_6:
# 347 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "From the center of the sea…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_7:
# 348 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "They are calling to my heart…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_8:
# 360 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "With faith to reach land.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_9:
# 361 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Only to go back.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_10:
# 371 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "And my heart to theirs.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_11:
# 372 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Yearning for a touch.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_12:
# 379 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "That was very beautiful.\p"
	.string "I'm not really into haiku, though.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_13:
# 392 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Violets are blue…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_14:
# 393 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Just like our love…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_15:
# 405 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "The sky is pretty…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_16:
# 406 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "The Pincurchin are spiky…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_17:
# 419 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "And so are you.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_18:
# 420 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "And so are you!$"

SpindaIsland_Home_EventScript_PoemGirl_Text_19:
# 426 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Oh, that's nice.\p"
	.string "You're not truly revealing your poet's\n"
	.string "heart, though.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_20:
# 448 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "That's… a weird comparison.\p"
	.string "I thought you were a better poet\n"
	.string "than that.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_21:
# 464 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Which blooms like they do.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_22:
# 465 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Wait, I didn't mean to say that.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_23:
# 471 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Wow, Archie, uh…\p"
	.string "That's not really what I meant when I\n"
	.string "said you should reveal your heart.\p"
	.string "(Well, this is awkward.)\p"
	.string "(Let's pretend this never happened.)$"

SpindaIsland_Home_EventScript_PoemGirl_Text_24:
# 487 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Violets are red…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_25:
# 501 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "The sky isn't blue, it's purple instead.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_26:
# 502 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Doesn't make sense, but fun to be said.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_27:
# 508 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hmm…\p"
	.string "You're not revealing your heart right\n"
	.string "now.\p"
	.string "Plus, that didn't make any sense.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_28:
# 524 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Orchids are blue, too.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_29:
# 525 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Everything is blue…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_30:
# 547 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Because it's my favorite color.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_31:
# 552 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "… … … … …\p"
	.string "Wow, Archie, I…\p"
	.string "This was so touching…\p"
	.string "Thank you for revealing your heart to\n"
	.string "me like this.\p"
	.string "Here, take this.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_32:
# 566 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "It's a blade of grass large enough to\n"
	.string "whistle with.$"

SpindaIsland_Home_EventScript_Sunbather_Text_0:
# 584 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Sunbather$"

SpindaIsland_Home_EventScript_Sunbather_Text_1:
# 586 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Ahh, it sure feels good to be sitting\n"
	.string "in the sun surrounded by all this\l"
	.string "{COLOR BLUE}WATER{COLOR DARK_GRAY}…\p"
	.string "…$"

SpindaIsland_Home_EventScript_Sunbather_Text_2:
# 597 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Could you leave? You're blocking the\n"
	.string "sun.$"

SpindaIsland_Home_Slowpoke_Text_0:
# 611 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Slowbro$"

SpindaIsland_Home_Slowpoke_Text_1:
# 613 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Bruh…$"

SpindaIsland_Home_Slowpoke_Text_2:
# 620 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Slowpoke$"

SpindaIsland_Home_Slowpoke_Text_3:
# 622 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Slo…$"

SpindaIsland_Home_Slowpoke_Text_4:
# 631 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "… … …?\p"
	.string "He's looking at the white seashell I\n"
	.string "found…$"

SpindaIsland_Home_Slowpoke_Text_5:
# 642 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Give the seashell$"

SpindaIsland_Home_Slowpoke_Text_6:
# 643 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Don't give the seashell$"

SpindaIsland_Home_Slowpoke_Text_7:
# 653 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Sure, why the hell not!\p"
	.string "Here you go, buddy.$"

SpindaIsland_Home_Slowpoke_Text_8:
# 672 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Bruh!!$"

SpindaIsland_Home_Slowpoke_Text_9:
# 680 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "The heck?!\p"
	.string "My seashell bit him!$"

SpindaIsland_Home_Slowpoke_Text_10:
# 686 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Guess it was a Shellder all this time!$"

SpindaIsland_Home_Slowpoke_Text_11:
# 696 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "…Slo…\p"
	.string ":($"

SpindaIsland_Home_EventScript_Metapod_Text_0:
# 710 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Metapod$"

SpindaIsland_Home_EventScript_Metapod_Text_1:
# 713 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "…$"

SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0:
# 722 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Twin 1$"

SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_1:
# 724 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "What is it?!\p"
	.string "Oh, I guess we are blocking the stairs\n"
	.string "a little…\p"
	.string "Fine, we'll take our epic battle\n"
	.string "somewhere else.$"

SpindaIsland_Home_EventScript_MetapodBoy1_Text_0:
# 746 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I'm SO CLOSE to winning!$"

SpindaIsland_Home_EventScript_MetapodBoy1_Text_1:
# 754 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "What? You're distracting me!$"

SpindaIsland_Home_EventScript_MetapodBoy1_Text_2:
# 762 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Metapod, use harden!!$"

SpindaIsland_Home_EventScript_MetapodBoy2_Text_0:
# 782 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Can't you see we're in the midst of a\n"
	.string "fiery battle?$"

SpindaIsland_Home_PhotoCameraWrongDir_Text_0:
# 807 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Nothing left but a pile of ashes…$"

SpindaIsland_Home_PhotoCameraWrongDir_Text_1:
# 815 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Can't use that from this side.$"

SpindaIsland_Home_SlowpokeMistress_Text_0:
# 870 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Girl$"

SpindaIsland_Home_SlowpokeMistress_Text_1:
# 872 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Look at my super cool Slowbro!\p"
	.string "He just looks so happy!$"

SpindaIsland_Home_SlowpokeMistress_Text_2:
# 887 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "By Arceus!!\p"
	.string "How on earth did you convince him to\n"
	.string "evolve?$"

SpindaIsland_Home_SlowpokeMistress_Text_3:
# 893 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "…A cool-looking seashell? What are\n"
	.string "you talking about?$"

SpindaIsland_Home_SlowpokeMistress_Text_4:
# 898 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Well, thank you anyway! You can have\n"
	.string "this!$"

SpindaIsland_Home_SlowpokeMistress_Text_5:
# 903 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I no longer need it.$"

SpindaIsland_Home_SlowpokeMistress_Text_6:
# 913 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hmm… A {COLOR BLUE}WATER{COLOR DARK_GRAY} Stone…\p"
	.string "Maybe I could try giving this to mom?$"

SpindaIsland_Home_SlowpokeMistress_Text_7:
# 924 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I wish my Pokémon would evolve…$"

SpindaIsland_Home_SlowpokeMistress_Text_8:
# 929 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I keep trying to give him this Water\n"
	.string "Stone, but it just does nothing.\p"
	.string "Perhaps there's another way…$"

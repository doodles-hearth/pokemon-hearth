SpindaIsland_Home_MapScripts::
# 6 "data/maps/SpindaIsland_Home/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SpindaIsland_Home_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 13 "data/maps/SpindaIsland_Home/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, SpindaIsland_Home_MapScripts_MAP_SCRIPT_ON_LOAD
# 24 "data/maps/SpindaIsland_Home/scripts.pory"
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

SpindaIsland_Home_MapScripts_MAP_SCRIPT_ON_LOAD:
# 15 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_REPLACED_WHEEL, SpindaIsland_Home_MapScripts_MAP_SCRIPT_ON_LOAD_2
SpindaIsland_Home_MapScripts_MAP_SCRIPT_ON_LOAD_1:
# 19 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_CAMERA_EXPLODED, SpindaIsland_Home_MapScripts_MAP_SCRIPT_ON_LOAD_4
	return

SpindaIsland_Home_MapScripts_MAP_SCRIPT_ON_LOAD_2:
# 16 "data/maps/SpindaIsland_Home/scripts.pory"
	setmetatile 27, 50, METATILE_SpindaIslandSecondary_FaucetWheel, TRUE
	goto SpindaIsland_Home_MapScripts_MAP_SCRIPT_ON_LOAD_1

SpindaIsland_Home_MapScripts_MAP_SCRIPT_ON_LOAD_4:
# 20 "data/maps/SpindaIsland_Home/scripts.pory"
	setmetatile 14, 27, METATILE_SpindaIsland_Grass, FALSE
# 21 "data/maps/SpindaIsland_Home/scripts.pory"
	setmetatile 14, 28, METATILE_SpindaIslandSecondary_RoofProfileTopRightCorner, FALSE
	return

SpindaIsland_Home_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 25 "data/maps/SpindaIsland_Home/scripts.pory"
	map_script_2 VAR_SPINDA_ISLAND_INTRO_STATE, 2, SpindaIsland_Home_EventScript_MainQuestRecap
	.2byte 0


SpindaIsland_Home_EventScript_MainQuestRecap::
# 29 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 30 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 31 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 32 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MainQuestRecap_Text_1
# 36 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 37 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 38 "data/maps/SpindaIsland_Home/scripts.pory"
	setvar VAR_SPINDA_ISLAND_INTRO_STATE, 3
# 39 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_MetapodOtherSide::
# 43 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 44 "data/maps/SpindaIsland_Home/scripts.pory"
	setvar VAR_METAPOD_OTHER_SIDE, 1
# 45 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_ArchiesHouseSign::
# 49 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_ArchiesHouseSign_Text_0, MSGBOX_SIGN
	return


SpindaIsland_Home_EventScript_BobsHouseSign::
# 53 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_BobsHouseSign_Text_0, MSGBOX_SIGN
	return


SpindaIsland_Home_EventScript_SadManHome_Back::
# 57 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 58 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_unset FLAG_HIDE_MAN_CANT_GO_HOME, SpindaIsland_Home_EventScript_SadManHome_Back_2
# 67 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_RECEIVED_RUSTY_BOLT, SpindaIsland_Home_EventScript_SadManHome_Back_5
# 76 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 77 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 78 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SadManHome_Back_Text_2
# 81 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 82 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 84 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_SadManHome_Back_Text_3
# 85 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SadManHome_Back_Text_4
# 89 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 91 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_EXIT
# 93 "data/maps/SpindaIsland_Home/scripts.pory"
	clearflag FLAG_HIDE_MAN_CANT_GO_HOME
# 94 "data/maps/SpindaIsland_Home/scripts.pory"
	setobjectxyperm 6, 42, 24
# 95 "data/maps/SpindaIsland_Home/scripts.pory"
	addobject 6
# 96 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement 6, SpindaIsland_Home_Movement_SadManExitsHouse
# 97 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SpindaIsland_Home_Movement_PlayerMakesWay
# 98 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 99 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 6
# 100 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 101 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 102 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_NORMAL
# 103 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_SadManHome_Back_Text_3
# 104 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SadManHome_Back_Text_5
# 107 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 108 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 109 "data/maps/SpindaIsland_Home/scripts.pory"
	giveitem ITEM_RUSTY_BOLT
# 110 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_RECEIVED_RUSTY_BOLT
# 111 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement 6, SpindaIsland_Home_Movement_SadManReEntersHouse
# 112 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 113 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_EXIT
# 114 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject 6
# 115 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_HIDE_MAN_CANT_GO_HOME
# 116 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 118 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 120 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_FAUCET_QUEST_STARTED, SpindaIsland_Home_EventScript_SadManHome_Back_8
# 153 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 154 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 155 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SadManHome_Back_Text_9
# 160 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 161 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
SpindaIsland_Home_EventScript_SadManHome_Back_1:
# 165 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_SadManHome_Back_2:
# 59 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 60 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 61 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SadManHome_Back_Text_0
# 64 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 65 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_SadManHome_Back_1

SpindaIsland_Home_EventScript_SadManHome_Back_5:
# 68 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 69 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 70 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SadManHome_Back_Text_1
# 73 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 74 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_SadManHome_Back_1

SpindaIsland_Home_EventScript_SadManHome_Back_8:
# 121 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 122 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 123 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SadManHome_Back_Text_6
# 126 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 127 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 129 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 131 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_PIN
# 132 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 133 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 134 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 135 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 137 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 138 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 139 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SadManHome_Back_Text_7
# 143 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 144 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 145 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SadManHome_Back_Text_8
# 148 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 149 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 151 "data/maps/SpindaIsland_Home/scripts.pory"
	call SpindaIsland_Common_CheckGotAllItemsForNewFaucet
	goto SpindaIsland_Home_EventScript_SadManHome_Back_1


SpindaIsland_Home_EventScript_ICanNeverGoHome::
# 169 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 170 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 171 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_SAD
# 172 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_ICanNeverGoHome_Text_0
# 173 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_ICanNeverGoHome_Text_1, MSGBOX_NPC
# 177 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 178 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_Dad::
# 182 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 183 "data/maps/SpindaIsland_Home/scripts.pory"
	turnobject 7, DIR_SOUTH
# 184 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_OBTAINED_LEMONADE, SpindaIsland_Home_EventScript_Dad_2
# 194 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_SPOKE_TO_DAD, SpindaIsland_Home_EventScript_Dad_6
# 203 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_DAD, EMOTE_HAPPY
# 204 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_0
# 205 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_3
# 209 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 210 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
SpindaIsland_Home_EventScript_Dad_5:
# 213 "data/maps/SpindaIsland_Home/scripts.pory"
	giveitem ITEM_SALTY_LEMONADE
# 215 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 216 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 217 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 218 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_4
# 222 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 223 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 225 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 10
# 226 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_BALL
# 227 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 228 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_BALL
# 229 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 230 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_BALL
# 231 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 232 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 20
# 234 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_PIN
# 235 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 236 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 237 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 238 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 240 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_DISGUSTED
# 241 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 242 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_5
# 246 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 247 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 249 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_DAD, EMOTE_GRINNING
# 250 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_0
# 251 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_6
# 254 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 255 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_DAD, EMOTE_HAPPY
# 256 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_7
# 259 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 260 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_DAD, EMOTE_EMBARRASSED
# 261 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_8
# 264 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 265 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_DAD, EMOTE_HAPPY
# 266 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_9
# 270 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 271 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 273 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_OBTAINED_LEMONADE
# 274 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_SPOKE_TO_DAD
SpindaIsland_Home_EventScript_Dad_1:
# 276 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_Dad_2:
# 185 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_DAD, EMOTE_EMBARRASSED
# 186 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_0
# 187 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_1
# 191 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 192 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_Dad_1

SpindaIsland_Home_EventScript_Dad_6:
# 195 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_DAD, EMOTE_HAPPY
# 196 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_0
# 197 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_2
# 200 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 201 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_Dad_5


SpindaIsland_Home_EventScript_Dad_FromSide::
# 280 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 281 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 282 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_OBTAINED_LEMONADE, SpindaIsland_Home_EventScript_Dad_FromSide_2
# 292 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_SPOKE_TO_DAD, SpindaIsland_Home_EventScript_Dad_FromSide_6
# 301 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_DAD, EMOTE_HAPPY
# 302 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_0
# 303 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_FromSide_Text_1
# 308 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 309 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
SpindaIsland_Home_EventScript_Dad_FromSide_5:
# 311 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_SPOKE_TO_DAD
SpindaIsland_Home_EventScript_Dad_FromSide_1:
# 313 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_Dad_FromSide_2:
# 283 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_DAD, EMOTE_EMBARRASSED
# 284 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_0
# 285 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_1
# 289 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 290 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_Dad_FromSide_1

SpindaIsland_Home_EventScript_Dad_FromSide_6:
# 293 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_DAD, EMOTE_NORMAL
# 294 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_0
# 295 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_FromSide_Text_0
# 298 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 299 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_Dad_FromSide_5


SpindaIsland_Home_EventScript_LemonadeStandSign::
# 317 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_LemonadeStandSign_Text_0, MSGBOX_SIGN
	return


SpindaIsland_Home_EventScript_MainStreetSign::
# 324 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MainStreetSign_Text_0, MSGBOX_SIGN
	return


SpindaIsland_Home_EventScript_MadelineSign::
# 330 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MadelineSign_Text_0, MSGBOX_SIGN
	return


SpindaIsland_Home_EventScript_PoemGirl::
# 336 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 338 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_POEM_GIRL, SpindaIsland_Home_EventScript_PoemGirl_2
# 352 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_GRASSWHISTLE
# 353 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 355 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 357 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 358 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 359 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_2
# 364 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 365 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 367 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_3, SpindaIsland_Home_EventScript_PoemGirl_Text_4, SpindaIsland_Home_EventScript_PoemGirl_Text_5
# 379 "data/maps/SpindaIsland_Home/scripts.pory"
	switch VAR_RESULT
# 380 "data/maps/SpindaIsland_Home/scripts.pory"
	case 0, SpindaIsland_Home_EventScript_PoemGirl_6
# 425 "data/maps/SpindaIsland_Home/scripts.pory"
	case 1, SpindaIsland_Home_EventScript_PoemGirl_7
# 520 "data/maps/SpindaIsland_Home/scripts.pory"
	case 2, SpindaIsland_Home_EventScript_PoemGirl_8
SpindaIsland_Home_EventScript_PoemGirl_1:
# 618 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 619 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 620 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_PoemGirl_2:
# 339 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 340 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 341 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 342 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_1
# 345 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 346 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 348 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 349 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 350 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_GRASSWHISTLE
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_6:
# 381 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_6, SpindaIsland_Home_EventScript_PoemGirl_Text_7
# 392 "data/maps/SpindaIsland_Home/scripts.pory"
	switch VAR_RESULT
# 393 "data/maps/SpindaIsland_Home/scripts.pory"
	case 0, SpindaIsland_Home_EventScript_PoemGirl_11
# 404 "data/maps/SpindaIsland_Home/scripts.pory"
	case 1, SpindaIsland_Home_EventScript_PoemGirl_12
SpindaIsland_Home_EventScript_PoemGirl_9:
# 417 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 418 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 419 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_12
# 423 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 424 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_7:
# 426 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_13, SpindaIsland_Home_EventScript_PoemGirl_Text_14
# 436 "data/maps/SpindaIsland_Home/scripts.pory"
	switch VAR_RESULT
# 438 "data/maps/SpindaIsland_Home/scripts.pory"
	case 0, SpindaIsland_Home_EventScript_PoemGirl_14
# 497 "data/maps/SpindaIsland_Home/scripts.pory"
	case 1, SpindaIsland_Home_EventScript_PoemGirl_15
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_8:
# 521 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_24, SpindaIsland_Home_EventScript_PoemGirl_Text_13
# 532 "data/maps/SpindaIsland_Home/scripts.pory"
	switch VAR_RESULT
# 534 "data/maps/SpindaIsland_Home/scripts.pory"
	case 0, SpindaIsland_Home_EventScript_PoemGirl_17
# 557 "data/maps/SpindaIsland_Home/scripts.pory"
	case 1, SpindaIsland_Home_EventScript_PoemGirl_18
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_11:
# 394 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_8, SpindaIsland_Home_EventScript_PoemGirl_Text_9
	goto SpindaIsland_Home_EventScript_PoemGirl_9

SpindaIsland_Home_EventScript_PoemGirl_12:
# 405 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_10, SpindaIsland_Home_EventScript_PoemGirl_Text_11
	goto SpindaIsland_Home_EventScript_PoemGirl_9

SpindaIsland_Home_EventScript_PoemGirl_14:
# 439 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_15, SpindaIsland_Home_EventScript_PoemGirl_Text_16
# 450 "data/maps/SpindaIsland_Home/scripts.pory"
	switch VAR_RESULT
# 452 "data/maps/SpindaIsland_Home/scripts.pory"
	case 0, SpindaIsland_Home_EventScript_PoemGirl_20
# 474 "data/maps/SpindaIsland_Home/scripts.pory"
	case 1, SpindaIsland_Home_EventScript_PoemGirl_21
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_15:
# 498 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_21, SpindaIsland_Home_EventScript_PoemGirl_Text_22
# 509 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 510 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 511 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_23
# 517 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 518 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_17:
# 535 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_25, SpindaIsland_Home_EventScript_PoemGirl_Text_26
# 546 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 547 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 548 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_27
# 553 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 554 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_18:
# 558 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_28, SpindaIsland_Home_EventScript_PoemGirl_Text_29
# 569 "data/maps/SpindaIsland_Home/scripts.pory"
	switch VAR_RESULT
# 570 "data/maps/SpindaIsland_Home/scripts.pory"
	case 0, SpindaIsland_Home_EventScript_PoemGirl_23
# 580 "data/maps/SpindaIsland_Home/scripts.pory"
	case 1, SpindaIsland_Home_EventScript_PoemGirl_24
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_20:
# 453 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_17, SpindaIsland_Home_EventScript_PoemGirl_Text_18
# 464 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 465 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 466 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_19
# 470 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 471 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_21:
# 475 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_17, SpindaIsland_Home_EventScript_PoemGirl_Text_18
# 486 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 487 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 488 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_20
# 492 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 493 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_23:
# 571 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 572 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 573 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_27
# 578 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 579 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_24:
# 581 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_30
# 590 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 591 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 592 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_31
# 599 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 600 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 602 "data/maps/SpindaIsland_Home/scripts.pory"
	giveitem ITEM_GRASS_BLADE
# 604 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 605 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 606 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_32
# 610 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 611 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 613 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_POEM_GIRL
	goto SpindaIsland_Home_EventScript_PoemGirl_1


SpindaIsland_Home_EventScript_Sunbather::
# 624 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 625 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_SUNBATHER, EMOTE_NORMAL
# 626 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Sunbather_Text_0
# 627 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Sunbather_Text_1
# 631 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 632 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 633 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 634 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 636 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_SUNBATHER, EMOTE_PENSIVE
# 637 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Sunbather_Text_0
# 638 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Sunbather_Text_2
# 641 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 642 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 643 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 644 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 645 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_Slowpoke::
# 649 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 650 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_SLOWPOKE_EVOLVED, SpindaIsland_Home_Slowpoke_2
# 661 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 662 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_SLOWPOKE, CRY_MODE_NORMAL
# 663 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_Slowpoke_Text_2
# 664 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Slowpoke_Text_3
# 667 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmoncry
# 668 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	checkitem ITEM_WHITE_SEASHELL
# 0 "data/maps/SpindaIsland_Home/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq SpindaIsland_Home_Slowpoke_5
SpindaIsland_Home_Slowpoke_1:
# 751 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_Slowpoke_2:
# 651 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 652 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_SLOWBRO, CRY_MODE_NORMAL
# 653 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_Slowpoke_Text_0
# 654 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Slowpoke_Text_1
# 657 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmoncry
# 658 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_Slowpoke_1

SpindaIsland_Home_Slowpoke_5:
# 671 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_THINKING
# 672 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 673 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Slowpoke_Text_4
# 678 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_Slowpoke_Text_5, SpindaIsland_Home_Slowpoke_Text_6
# 688 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 689 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 691 "data/maps/SpindaIsland_Home/scripts.pory"
	switch VAR_RESULT
# 692 "data/maps/SpindaIsland_Home/scripts.pory"
	case 0, SpindaIsland_Home_Slowpoke_8
# 738 "data/maps/SpindaIsland_Home/scripts.pory"
	case 1, SpindaIsland_Home_Slowpoke_9
	goto SpindaIsland_Home_Slowpoke_1

SpindaIsland_Home_Slowpoke_8:
# 693 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 694 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 695 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Slowpoke_Text_7
# 699 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 700 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 702 "data/maps/SpindaIsland_Home/scripts.pory"
	removeitem ITEM_WHITE_SEASHELL
# 704 "data/maps/SpindaIsland_Home/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( SLOWBRO )
# 705 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_SHELLDER, CRY_MODE_NORMAL
# 706 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmoncry
# 707 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject VAR_LAST_TALKED
# 708 "data/maps/SpindaIsland_Home/scripts.pory"
	addobject VAR_LAST_TALKED
# 709 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_BITE
# 710 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, SpindaIsland_Home_Movement_Slowpoke
# 711 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 712 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement VAR_LAST_TALKED
# 713 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 715 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_SLOWPOKE, CRY_MODE_NORMAL
# 716 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_Slowpoke_Text_0
# 717 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Slowpoke_Text_8
# 720 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmoncry
# 721 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 723 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_SHOCKED
# 724 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 725 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Slowpoke_Text_9
# 729 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 730 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 731 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Slowpoke_Text_10
# 734 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 735 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 737 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_SLOWPOKE_EVOLVED
	goto SpindaIsland_Home_Slowpoke_1

SpindaIsland_Home_Slowpoke_9:
# 739 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_SLOWPOKE, CRY_MODE_FAINT
# 740 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_Slowpoke_Text_2
# 741 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Slowpoke_Text_11
# 745 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmoncry
# 746 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_Slowpoke_1


SpindaIsland_Home_EventScript_Metapod::
# 755 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 756 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Metapod_Text_0
# 757 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_METAPOD, CRY_MODE_NORMAL
# 758 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Metapod_Text_1
# 761 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmoncry
# 762 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 763 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_MetapodBoysFuckOff::
# 767 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 768 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_TWIN, EMOTE_ANGRY
# 769 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0
# 770 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_1
# 774 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_TWIN, EMOTE_NORMAL
# 775 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_2
# 779 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 781 "data/maps/SpindaIsland_Home/scripts.pory"
	fadescreen FADE_TO_BLACK
# 782 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_HIDE_METAPOD_BATTLE
# 783 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject 1
# 784 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject 2
# 785 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject 3
# 786 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject 4
# 787 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 60
# 788 "data/maps/SpindaIsland_Home/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 789 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 40
# 790 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Bussin::
# 794 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 795 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_TWIN, EMOTE_ANGRY
# 796 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0
# 797 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Bussin_Text_0
# 801 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_TWIN, EMOTE_NORMAL
# 802 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Bussin_Text_1
# 806 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 807 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 809 "data/maps/SpindaIsland_Home/scripts.pory"
	fadescreen FADE_TO_BLACK
# 810 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_HIDE_METAPOD_BATTLE
# 811 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject 1
# 812 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject 2
# 813 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject 3
# 814 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject 4
# 815 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 60
# 816 "data/maps/SpindaIsland_Home/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 817 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 40
# 818 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_MetapodBoy::
# 822 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 823 "data/maps/SpindaIsland_Home/scripts.pory"
	compare VAR_METAPOD_OTHER_SIDE, 1
	goto_if_eq SpindaIsland_Home_EventScript_MetapodBoy_2
SpindaIsland_Home_EventScript_MetapodBoy_1:
# 826 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_TWIN, EMOTE_ANGRY
# 827 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0
# 828 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoy_Text_0
# 831 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 832 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 834 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 836 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_TWIN, EMOTE_FINGER
# 837 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0
# 838 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoy_Text_1
# 841 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 842 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 844 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 846 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_TWIN, EMOTE_ANGRY
# 847 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0
# 848 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoy_Text_2
# 851 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 852 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 854 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_HARDEN
# 855 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 856 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_HARDEN
# 857 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 858 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 859 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_MetapodBoy_2:
# 824 "data/maps/SpindaIsland_Home/scripts.pory"
	goto SpindaIsland_Home_EventScript_MetapodBoysFuckOff
	goto SpindaIsland_Home_EventScript_MetapodBoy_1


SpindaIsland_Home_EventScript_MetapodBoy_Bussin::
# 863 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 864 "data/maps/SpindaIsland_Home/scripts.pory"
	compare VAR_METAPOD_OTHER_SIDE, 1
	goto_if_eq SpindaIsland_Home_EventScript_MetapodBoy_Bussin_2
SpindaIsland_Home_EventScript_MetapodBoy_Bussin_1:
# 867 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_TWIN, EMOTE_ANGRY
# 868 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0
# 869 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoy_Bussin_Text_0
# 872 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 873 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 875 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 877 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_TWIN, EMOTE_FINGER
# 878 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0
# 879 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoy_Bussin_Text_1
# 882 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 883 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 885 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 887 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_TWIN, EMOTE_ANGRY
# 888 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0
# 889 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoy_Bussin_Text_2
# 892 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 893 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 895 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_HARDEN
# 896 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 897 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_HARDEN
# 898 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 899 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 900 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_MetapodBoy_Bussin_2:
# 865 "data/maps/SpindaIsland_Home/scripts.pory"
	goto SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Bussin
	goto SpindaIsland_Home_EventScript_MetapodBoy_Bussin_1


SpindaIsland_Home_PhotoCameraWrongDir::
# 904 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 906 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_CAMERA_EXPLODED, SpindaIsland_Home_PhotoCameraWrongDir_2
# 915 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 916 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 917 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_PhotoCameraWrongDir_Text_1
# 920 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 921 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
SpindaIsland_Home_PhotoCameraWrongDir_1:
# 923 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_PhotoCameraWrongDir_2:
# 907 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 908 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 909 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_PhotoCameraWrongDir_Text_0
# 912 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 913 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
	goto SpindaIsland_Home_PhotoCameraWrongDir_1


SpindaIsland_Home_EventScript_FaucetShopSign::
# 927 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_FaucetShopSign_Text_0, MSGBOX_SIGN
	return


# 934 "data/maps/SpindaIsland_Home/scripts.pory"
SpindaIsland_Home_Movement_SadManExitsHouse:
# 935 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_down
	step_end

# 938 "data/maps/SpindaIsland_Home/scripts.pory"
SpindaIsland_Home_Movement_SadManReEntersHouse:
# 939 "data/maps/SpindaIsland_Home/scripts.pory"
	face_up
# 940 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 941 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
	step_end

# 944 "data/maps/SpindaIsland_Home/scripts.pory"
SpindaIsland_Home_Movement_PlayerMakesWay:
# 945 "data/maps/SpindaIsland_Home/scripts.pory"
	lock_facing_direction
# 946 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_down
# 947 "data/maps/SpindaIsland_Home/scripts.pory"
	unlock_facing_direction
	step_end

# 950 "data/maps/SpindaIsland_Home/scripts.pory"
SpindaIsland_Home_Movement_Slowpoke:
# 951 "data/maps/SpindaIsland_Home/scripts.pory"
	lock_facing_direction
# 952 "data/maps/SpindaIsland_Home/scripts.pory"
	jump_in_place_down
# 953 "data/maps/SpindaIsland_Home/scripts.pory"
	unlock_facing_direction
# 954 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 954 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 954 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 955 "data/maps/SpindaIsland_Home/scripts.pory"
	face_up
# 956 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 957 "data/maps/SpindaIsland_Home/scripts.pory"
	face_down
# 958 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 959 "data/maps/SpindaIsland_Home/scripts.pory"
	face_left
# 960 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 961 "data/maps/SpindaIsland_Home/scripts.pory"
	face_up
# 962 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 963 "data/maps/SpindaIsland_Home/scripts.pory"
	face_player
# 964 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 964 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 964 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 965 "data/maps/SpindaIsland_Home/scripts.pory"
	lock_facing_direction
# 966 "data/maps/SpindaIsland_Home/scripts.pory"
	jump_in_place_down
# 967 "data/maps/SpindaIsland_Home/scripts.pory"
	jump_in_place_down
# 968 "data/maps/SpindaIsland_Home/scripts.pory"
	unlock_facing_direction
# 969 "data/maps/SpindaIsland_Home/scripts.pory"
	emote_heart
# 970 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 970 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 970 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
	step_end

SpindaIsland_Home_SlowpokeMistress::
# 974 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 975 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 976 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_RECEIVED_SLOWPOKE_REWARD, SpindaIsland_Home_SlowpokeMistress_2
# 985 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_SLOWPOKE_EVOLVED, SpindaIsland_Home_SlowpokeMistress_3
# 1029 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LASS, EMOTE_SWEAT
# 1030 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_SlowpokeMistress_Text_0
# 1031 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_SlowpokeMistress_Text_7
# 1034 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1035 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LASS, EMOTE_NORMAL
# 1036 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_SlowpokeMistress_Text_8
# 1040 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1041 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
SpindaIsland_Home_SlowpokeMistress_1:
# 1043 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_SlowpokeMistress_2:
# 977 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LASS, EMOTE_HAPPY
# 978 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_SlowpokeMistress_Text_0
# 979 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_SlowpokeMistress_Text_1
# 983 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 984 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_SlowpokeMistress_1

SpindaIsland_Home_SlowpokeMistress_3:
# 986 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_PIN
# 987 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
# 988 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 989 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 990 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 992 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LASS, EMOTE_SURPRISED
# 993 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_SlowpokeMistress_Text_0
# 994 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_SlowpokeMistress_Text_2
# 998 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 999 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LASS, EMOTE_NORMAL
# 1000 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_SlowpokeMistress_Text_3
# 1003 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1004 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LASS, EMOTE_HAPPY
# 1005 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_SlowpokeMistress_Text_4
# 1008 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1009 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LASS, EMOTE_NORMAL
# 1010 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_SlowpokeMistress_Text_5
# 1013 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1014 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1016 "data/maps/SpindaIsland_Home/scripts.pory"
	giveitem ITEM_WATER_STONE_2
# 1018 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_THINKING
# 1019 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 1020 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_SlowpokeMistress_Text_6
# 1024 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1025 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1027 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_RECEIVED_SLOWPOKE_REWARD
	goto SpindaIsland_Home_SlowpokeMistress_1


SpindaIsland_Home_EventScript_Juan::
# 1047 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1048 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1049 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_NORMAL
# 1050 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Juan_Text_0
# 1051 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_TALKED_TO_JUAN_ABOUT_PUBES, SpindaIsland_Home_EventScript_Juan_2
# 1075 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Juan_Text_5
# 1086 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_SURPRISED
# 1087 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Juan_Text_6
# 1090 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1091 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1092 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_TALKED_TO_JUAN_ABOUT_PUBES
SpindaIsland_Home_EventScript_Juan_1:
# 1095 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_Juan_2:
# 1052 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Juan_Text_1
# 1056 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_Juan_Text_2, SpindaIsland_Home_EventScript_Juan_Text_3
# 1067 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_GRINNING
# 1068 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Juan_Text_4
# 1072 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1073 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_Juan_1


SpindaIsland_Home_EventScript_Machoke::
# 1099 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1100 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1101 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_MACHOKE, CRY_MODE_NORMAL
# 1102 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_TALKED_TO_JUAN_ABOUT_PUBES, SpindaIsland_Home_EventScript_Machoke_2
# 1105 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Machoke_Text_1
SpindaIsland_Home_EventScript_Machoke_1:
# 1107 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Machoke_Text_2
# 1110 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 1111 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1112 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_Machoke_2:
# 1103 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Machoke_Text_0
	goto SpindaIsland_Home_EventScript_Machoke_1


SpindaIsland_Home_EventScript_Lisa::
# 1116 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1117 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1118 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL_BLACK, EMOTE_NORMAL
# 1119 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Lisa_Text_0
# 1120 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Lisa_Text_1
# 1123 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1124 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1125 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_OldWoman::
# 1129 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1130 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1131 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_unset FLAG_SHUPPET_QUEST_STARTED, SpindaIsland_Home_EventScript_OldWoman_2
# 1142 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_unset FLAG_HIDE_SHUPPETS, SpindaIsland_Home_EventScript_OldWoman_3
SpindaIsland_Home_EventScript_OldWoman_1:
# 1153 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_HIDE_SHUPPETS, SpindaIsland_Home_EventScript_OldWoman_7
SpindaIsland_Home_EventScript_OldWoman_6:
# 1199 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_OldWoman_2:
# 1132 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1133 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_NORMAL
# 1134 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_OldWoman_Text_0
# 1135 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_OldWoman_Text_1
# 1139 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1140 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1141 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_SHUPPET_QUEST_STARTED
	goto SpindaIsland_Home_EventScript_OldWoman_1

SpindaIsland_Home_EventScript_OldWoman_3:
# 1143 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1144 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_NORMAL
# 1145 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_OldWoman_Text_0
# 1146 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_OldWoman_Text_2
# 1149 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1150 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_OldWoman_1

SpindaIsland_Home_EventScript_OldWoman_7:
# 1154 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_NORMAL
# 1155 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_OldWoman_Text_0
# 1156 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_OldWoman_Text_2
# 1159 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1160 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1162 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 1163 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 1164 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_OldWoman_Text_3
# 1167 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1168 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1170 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_NORMAL
# 1171 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_OldWoman_Text_0
# 1172 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_OldWoman_Text_4
# 1175 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_HAPPY
# 1176 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_OldWoman_Text_5
# 1180 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1181 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1185 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_HAPPY
# 1186 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_OldWoman_Text_6
# 1189 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1190 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1192 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, SpindaIsland_Home_Movement_GrandmaEntersHome
# 1193 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 1194 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject VAR_LAST_TALKED
# 1195 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_EXIT
# 1196 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 1197 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_HIDE_OLD_WOMAN
	goto SpindaIsland_Home_EventScript_OldWoman_6


# 1202 "data/maps/SpindaIsland_Home/scripts.pory"
SpindaIsland_Home_Movement_GrandmaEntersHome:
# 1203 "data/maps/SpindaIsland_Home/scripts.pory"
	face_up
	step_end

SpindaIsland_Home_EventScript_Boat::
	return


SpindaIsland_Home_EventScript_OldWomansDoor::
# 1211 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1213 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1214 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 1215 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_OldWomansDoor_Text_0
# 1218 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1219 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1221 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_CarBoy::
# 1225 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1226 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1227 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_BOY, EMOTE_NORMAL
# 1228 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_CarBoy_Text_0
# 1229 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_CarBoy_Text_1
# 1232 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1233 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1234 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 1235 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 1236 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_CarGirl::
# 1240 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1241 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_RECEIVED_NICKEL, SpindaIsland_Home_CarGirl_2
# 1251 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_REPLACED_WHEEL, SpindaIsland_Home_CarGirl_3
# 1268 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_LOOKING_FOR_WHEEL_REPLACEMENT, SpindaIsland_Home_CarGirl_4
# 1278 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1279 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_NORMAL
# 1280 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_CarGirl_Text_0
# 1281 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_CarGirl_Text_4
# 1288 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1289 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1291 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_LOOKING_FOR_WHEEL_REPLACEMENT
SpindaIsland_Home_CarGirl_1:
# 1294 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 1295 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 1297 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_CarGirl_2:
# 1242 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1243 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_NORMAL
# 1244 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_CarGirl_Text_0
# 1245 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_CarGirl_Text_1
# 1248 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1249 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_CarGirl_1

SpindaIsland_Home_CarGirl_3:
# 1252 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1253 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_NORMAL
# 1254 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_CarGirl_Text_0
# 1255 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_CarGirl_Text_2
# 1263 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1264 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1266 "data/maps/SpindaIsland_Home/scripts.pory"
	giveitem ITEM_RUSTY_NICKEL
# 1267 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_RECEIVED_NICKEL
	goto SpindaIsland_Home_CarGirl_1

SpindaIsland_Home_CarGirl_4:
# 1269 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1270 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 1271 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_CarGirl_Text_0
# 1272 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_CarGirl_Text_3
# 1275 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1276 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_CarGirl_1


SpindaIsland_Home_EventScript_MissingWheel::
# 1301 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1302 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_REPLACED_WHEEL, SpindaIsland_Home_EventScript_MissingWheel_2
# 1311 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1312 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 1313 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MissingWheel_Text_1
# 1317 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1318 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
SpindaIsland_Home_EventScript_MissingWheel_1:
# 1320 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_MissingWheel_2:
# 1303 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 1304 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 1305 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MissingWheel_Text_0
# 1308 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1309 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_MissingWheel_1


SpindaIsland_Home_EventScript_ReplaceWheelWithBrokenFaucet::
# 1324 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1326 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_FAUCET_QUEST_STARTED, SpindaIsland_Home_EventScript_ReplaceWheelWithBrokenFaucet_1
# 1357 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1358 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 1359 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_ReplaceWheelWithBrokenFaucet_Text_2
# 1362 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1363 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	return

SpindaIsland_Home_EventScript_ReplaceWheelWithBrokenFaucet_1:
# 1327 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1328 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 1329 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_ReplaceWheelWithBrokenFaucet_Text_0
# 1332 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1333 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1335 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 1337 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_CLICK
# 1338 "data/maps/SpindaIsland_Home/scripts.pory"
	setmetatile 27, 50, METATILE_SpindaIslandSecondary_FaucetWheel, TRUE
# 1339 "data/maps/SpindaIsland_Home/scripts.pory"
	special DrawWholeMapView
# 1340 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 1342 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 1344 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 1345 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 1346 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_ReplaceWheelWithBrokenFaucet_Text_1
# 1349 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1350 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1352 "data/maps/SpindaIsland_Home/scripts.pory"
	removeitem ITEM_BROKEN_FAUCET
# 1353 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_REPLACED_WHEEL
# 1355 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_SurveyedWheel::
# 1368 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1369 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_FAUCET_QUEST_STARTED, SpindaIsland_Home_EventScript_SurveyedWheel_4
SpindaIsland_Home_EventScript_SurveyedWheel_3:
# 1427 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1428 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 1429 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SurveyedWheel_Text_0
# 1432 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1433 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
SpindaIsland_Home_EventScript_SurveyedWheel_1:
# 1435 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_SurveyedWheel_2:
# 1370 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1371 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 1372 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SurveyedWheel_Text_0
# 1375 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1376 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 1377 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SurveyedWheel_Text_1
# 1381 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
	checkitem ITEM_BORROWED_PLIERS
# 0 "data/maps/SpindaIsland_Home/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne SpindaIsland_Home_EventScript_SurveyedWheel_7
# 1419 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1420 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SurveyedWheel_Text_6
# 1423 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1424 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_SurveyedWheel_1

SpindaIsland_Home_EventScript_SurveyedWheel_4:
# 1369 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_unset FLAG_FOUND_TOUGH_BOLT, SpindaIsland_Home_EventScript_SurveyedWheel_2
	goto SpindaIsland_Home_EventScript_SurveyedWheel_3

SpindaIsland_Home_EventScript_SurveyedWheel_7:
# 1384 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1385 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SurveyedWheel_Text_2
# 1388 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1389 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1391 "data/maps/SpindaIsland_Home/scripts.pory"
	turnobject 15, DIR_EAST
# 1392 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_NORMAL
# 1393 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_CarGirl_Text_0
# 1394 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SurveyedWheel_Text_3
# 1397 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1398 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1400 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 1401 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 1402 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SurveyedWheel_Text_4
# 1405 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1406 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1408 "data/maps/SpindaIsland_Home/scripts.pory"
	turnobject 15, DIR_NORTH
# 1409 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 1411 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1412 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 1413 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SurveyedWheel_Text_5
# 1416 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1417 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_SurveyedWheel_1


SpindaIsland_Home_EventScript_Raft::
# 1439 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
	checkitem ITEM_BADASS_SAIL
# 0 "data/maps/SpindaIsland_Home/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne SpindaIsland_Home_EventScript_Raft_2
# 1477 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1478 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 1479 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Raft_Text_4
# 1483 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1484 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
SpindaIsland_Home_EventScript_Raft_1:
# 1486 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_Raft_2:
# 1441 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 1442 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 1443 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Raft_Text_0
# 1446 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1447 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1449 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_FU_ZAKU
# 1450 "data/maps/SpindaIsland_Home/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_SOUTH
# 1451 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 1453 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 1455 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 1456 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 1457 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Raft_Text_1
# 1460 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1461 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Raft_Text_2
# 1465 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1466 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1468 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SpindaIsland_Home_Movement_PlayerEntersRaft
# 1469 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 1471 "data/maps/SpindaIsland_Home/scripts.pory"
	special SpawnCameraObject
# 1472 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, SpindaIsland_Home_Movement_RaftGoesToIsland
# 1473 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, SpindaIsland_Home_Movement_RaftGoesToIsland
# 1474 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 120
# 1475 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Raft_Text_3
	goto SpindaIsland_Home_EventScript_Raft_1


# 1489 "data/maps/SpindaIsland_Home/scripts.pory"
SpindaIsland_Home_Movement_RaftGoesToIsland:
# 1490 "data/maps/SpindaIsland_Home/scripts.pory"
	face_left
# 1491 "data/maps/SpindaIsland_Home/scripts.pory"
	lock_facing_direction
# 1492 "data/maps/SpindaIsland_Home/scripts.pory"
	lock_anim
# 1493 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_down
# 1493 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_down
# 1493 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_down
# 1493 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_down
# 1493 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_down
# 1493 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_down
# 1493 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_down
	step_end

# 1496 "data/maps/SpindaIsland_Home/scripts.pory"
SpindaIsland_Home_Movement_PlayerEntersRaft:
# 1497 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_down
# 1498 "data/maps/SpindaIsland_Home/scripts.pory"
	set_invisible
	step_end

SpindaIsland_Home_EventScript_MainQuestRecap_Text_0:
# 31 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Little Archie$"

SpindaIsland_Home_EventScript_MainQuestRecap_Text_1:
# 33 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Alright! The quicker mom gets her\n"
	.string "glass of {COLOR BLUE}WATER{COLOR DARK_GRAY}, the quicker Archie\l"
	.string "gets his super badass pirate {COLOR RED}sail{COLOR DARK_GRAY}!\p"
	.string "Let's get moving!$"

SpindaIsland_Home_EventScript_ArchiesHouseSign_Text_0:
# 49 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "The Hoenns$"

SpindaIsland_Home_EventScript_BobsHouseSign_Text_0:
# 53 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Bob$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_0:
# 62 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Door's locked.$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_1:
# 71 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I guess I should leave him alone now.$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_2:
# 79 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hello? Are you there?$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_3:
# 84 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Stingy man$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_4:
# 86 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "…\p"
	.string "My GOD you're annoying.$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_5:
# 105 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Here's your reward. I hope you're\n"
	.string "happy.$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_6:
# 124 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "An old and rusty bolt? What am I\n"
	.string "supposed to do with this?$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_7:
# 140 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "A {COLOR RED}bolt{COLOR DARK_GRAY}! Of course! Lucky me!\p"
	.string "I'm one step closer to getting that\n"
	.string "sweet sweet faucet replacement!!$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_8:
# 146 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "(Did I really say that? Is this how\n"
	.string "being a grownup feels like?)$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_9:
# 156 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "A bolt?\p"
	.string "It's all rusty…\p"
	.string "Guess it'll join my useless trash\n"
	.string "collection!$"

SpindaIsland_Home_EventScript_ICanNeverGoHome_Text_0:
# 172 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Sad man$"

SpindaIsland_Home_EventScript_ICanNeverGoHome_Text_1:
# 174 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Curse the architect that built my\n"
	.string "house facing the wrong direction!!\p"
	.string "I can never go home!$"

SpindaIsland_Home_EventScript_Dad_Text_0:
# 186 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Dad$"

SpindaIsland_Home_EventScript_Dad_Text_1:
# 188 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Don't uh, pour that lemonade I gave\n"
	.string "you on the ground or anything.\p"
	.string "It'd probably kill all the grass and\n"
	.string "flowers.$"

SpindaIsland_Home_EventScript_Dad_Text_2:
# 198 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Here, have some lemonade!$"

SpindaIsland_Home_EventScript_Dad_Text_3:
# 206 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hiya, sonny! going adventuring today,\n"
	.string "are we?\p"
	.string "Want some lemonade?$"

SpindaIsland_Home_EventScript_Dad_Text_4:
# 219 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Now we're talkin'!! I can bring this to\n"
	.string "mom, that should do it!\p"
	.string "Let's take a sip first, I am PARCHED!$"

SpindaIsland_Home_EventScript_Dad_Text_5:
# 243 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "BLEARGH!\p"
	.string "Why is it… so salty?!$"

SpindaIsland_Home_EventScript_Dad_Text_6:
# 252 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Why, because it's seawater, obviously!$"

SpindaIsland_Home_EventScript_Dad_Text_7:
# 257 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I take it you're not a fan of my\n"
	.string "recipe?$"

SpindaIsland_Home_EventScript_Dad_Text_8:
# 262 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "(You wouldn't be the only one…)$"

SpindaIsland_Home_EventScript_Dad_Text_9:
# 267 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "In any case, it's nice of you to come\n"
	.string "visit me at the office, haha!\p"
	.string "See you around, little Archie! Don't\n"
	.string "get into trouble!$"

SpindaIsland_Home_EventScript_Dad_FromSide_Text_0:
# 296 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Come round to the front of the\n"
	.string "lemonade stand!$"

SpindaIsland_Home_EventScript_Dad_FromSide_Text_1:
# 304 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hiya, sonny! going adventuring today,\n"
	.string "are we?\p"
	.string "Want some lemonade?\p"
	.string "Come round to the front of the\n"
	.string "lemonade stand!$"

SpindaIsland_Home_EventScript_LemonadeStandSign_Text_0:
# 318 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "“ARCHIE'S LEMONADE\n"
	.string "A taste of the seaside!”$"

SpindaIsland_Home_EventScript_MainStreetSign_Text_0:
# 325 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "{UP_ARROW} Main street$"

SpindaIsland_Home_EventScript_MadelineSign_Text_0:
# 331 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Madeline$"

SpindaIsland_Home_EventScript_PoemGirl_Text_0:
# 341 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Maggie$"

SpindaIsland_Home_EventScript_PoemGirl_Text_1:
# 343 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "See you around, Archie…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_2:
# 360 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Archie…\p"
	.string "I want to hear a poem…\p"
	.string "I want you to reveal your heart to me.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_3:
# 374 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Ocean waves swimming…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_4:
# 375 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Roses are red…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_5:
# 376 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Roses are blue…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_6:
# 388 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "From the center of the sea…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_7:
# 389 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "They are calling to my heart…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_8:
# 401 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "With faith to reach land.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_9:
# 402 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Only to go back.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_10:
# 412 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "And my heart to theirs.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_11:
# 413 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Yearning for a touch.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_12:
# 420 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "That was very beautiful.\p"
	.string "I'm not really into haiku, though.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_13:
# 433 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Violets are blue…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_14:
# 434 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Just like our love…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_15:
# 446 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "The sky is pretty…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_16:
# 447 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "The Pincurchin are spiky…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_17:
# 460 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "And so are you.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_18:
# 461 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "And so are you!$"

SpindaIsland_Home_EventScript_PoemGirl_Text_19:
# 467 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Oh, that's nice.\p"
	.string "You're not truly revealing your poet's\n"
	.string "heart, though.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_20:
# 489 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "That's… a weird comparison.\p"
	.string "I thought you were a better poet\n"
	.string "than that.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_21:
# 505 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Which blooms like they do.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_22:
# 506 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Wait, I didn't mean to say that.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_23:
# 512 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Wow, Archie, uh…\p"
	.string "That's not really what I meant when I\n"
	.string "said you should reveal your heart.\p"
	.string "(Well, this is awkward.)\p"
	.string "(Let's pretend this never happened.)$"

SpindaIsland_Home_EventScript_PoemGirl_Text_24:
# 528 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Violets are red…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_25:
# 542 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "The sky isn't blue, it's purple instead.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_26:
# 543 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Doesn't make sense, but fun to be said.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_27:
# 549 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hmm…\p"
	.string "You're not revealing your heart right\n"
	.string "now.\p"
	.string "Plus, that didn't make any sense.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_28:
# 565 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Orchids are blue, too.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_29:
# 566 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Everything is blue…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_30:
# 588 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Because it's my favorite color.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_31:
# 593 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "… … … … …\p"
	.string "Wow, Archie, I…\p"
	.string "This was so touching…\p"
	.string "Thank you for revealing your heart to\n"
	.string "me like this.\p"
	.string "Here, take this.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_32:
# 607 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "It's a blade of grass large enough to\n"
	.string "whistle with.\p"
	.string "Just don't listen to it too\n"
	.string "attentively, you might get sleepy.$"

SpindaIsland_Home_EventScript_Sunbather_Text_0:
# 626 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Sunbather$"

SpindaIsland_Home_EventScript_Sunbather_Text_1:
# 628 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Ahh, it sure feels good to be sitting\n"
	.string "in the sun surrounded by all this\l"
	.string "{COLOR BLUE}WATER{COLOR DARK_GRAY}…\p"
	.string "…$"

SpindaIsland_Home_EventScript_Sunbather_Text_2:
# 639 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Could you leave? You're blocking the\n"
	.string "sun.$"

SpindaIsland_Home_Slowpoke_Text_0:
# 653 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Slowbro$"

SpindaIsland_Home_Slowpoke_Text_1:
# 655 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Bruh…$"

SpindaIsland_Home_Slowpoke_Text_2:
# 663 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Slowpoke$"

SpindaIsland_Home_Slowpoke_Text_3:
# 665 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Slo…$"

SpindaIsland_Home_Slowpoke_Text_4:
# 674 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "… … …?\p"
	.string "He's looking at the white seashell I\n"
	.string "found…$"

SpindaIsland_Home_Slowpoke_Text_5:
# 685 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Give the seashell$"

SpindaIsland_Home_Slowpoke_Text_6:
# 686 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Don't give the seashell$"

SpindaIsland_Home_Slowpoke_Text_7:
# 696 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Sure, why the hell not!\p"
	.string "Here you go, buddy.$"

SpindaIsland_Home_Slowpoke_Text_8:
# 718 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Bruh!!$"

SpindaIsland_Home_Slowpoke_Text_9:
# 726 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "The heck?!\p"
	.string "My seashell bit him!$"

SpindaIsland_Home_Slowpoke_Text_10:
# 732 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Guess it was a Shellder all this time!$"

SpindaIsland_Home_Slowpoke_Text_11:
# 742 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "…Slo…\p"
	.string ":($"

SpindaIsland_Home_EventScript_Metapod_Text_0:
# 756 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Metapod$"

SpindaIsland_Home_EventScript_Metapod_Text_1:
# 759 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "…$"

SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0:
# 769 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Twin$"

SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_1:
# 771 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "What is it?!$"

SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_2:
# 776 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Oh, I guess we are blocking the stairs\n"
	.string "a little…\p"
	.string "Fine, we'll take our epic battle\n"
	.string "somewhere else.$"

SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Bussin_Text_0:
# 798 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "On god why you gotta bust my balls\n"
	.string "like that fr?!$"

SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Bussin_Text_1:
# 803 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Yikes, we lowkey do be blockin the\n"
	.string "stairs rn no cap…\p"
	.string "Aight word word, we gon vibe\n"
	.string "somewhere else.$"

SpindaIsland_Home_EventScript_MetapodBoy_Text_0:
# 829 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I'm SO CLOSE to tasting that sweet,\n"
	.string "sweet victory!$"

SpindaIsland_Home_EventScript_MetapodBoy_Text_1:
# 839 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Can't you see we're in the midst of a\n"
	.string "fiery battle?$"

SpindaIsland_Home_EventScript_MetapodBoy_Text_2:
# 849 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Metapod, use harden!!$"

SpindaIsland_Home_EventScript_MetapodBoy_Bussin_Text_0:
# 870 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I'm deadass SO CLOSE to catchin that\n"
	.string "bussin drip fr!$"

SpindaIsland_Home_EventScript_MetapodBoy_Bussin_Text_1:
# 880 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Can't you see we tryna catch some\n"
	.string "real heat rn bro? Sheesh!$"

SpindaIsland_Home_EventScript_MetapodBoy_Bussin_Text_2:
# 890 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Metapod, keep hittin that mid boi with\n"
	.string "harden, chief!!$"

SpindaIsland_Home_PhotoCameraWrongDir_Text_0:
# 910 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Nothing left but a pile of ashes…$"

SpindaIsland_Home_PhotoCameraWrongDir_Text_1:
# 918 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Can't use that from this side.$"

SpindaIsland_Home_EventScript_FaucetShopSign_Text_0:
# 928 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "“FAUCET WORKSHOP\n"
	.string "For all your faucet needs!\l"
	.string "WE ARE OPEN!!”$"

SpindaIsland_Home_SlowpokeMistress_Text_0:
# 978 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Girl$"

SpindaIsland_Home_SlowpokeMistress_Text_1:
# 980 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Look at my super cool Slowbro!\p"
	.string "He just looks so happy!$"

SpindaIsland_Home_SlowpokeMistress_Text_2:
# 995 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "By Arceus!!\p"
	.string "How on earth did you convince him to\n"
	.string "evolve?$"

SpindaIsland_Home_SlowpokeMistress_Text_3:
# 1001 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "…A cool-looking seashell? What are\n"
	.string "you talking about?$"

SpindaIsland_Home_SlowpokeMistress_Text_4:
# 1006 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Well, thank you anyway! You can have\n"
	.string "this!$"

SpindaIsland_Home_SlowpokeMistress_Text_5:
# 1011 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I no longer need it.$"

SpindaIsland_Home_SlowpokeMistress_Text_6:
# 1021 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hmm… A {COLOR BLUE}WATER{COLOR DARK_GRAY} Stone…\p"
	.string "Maybe I could try giving this to mom?$"

SpindaIsland_Home_SlowpokeMistress_Text_7:
# 1032 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I wish my Pokémon would evolve…$"

SpindaIsland_Home_SlowpokeMistress_Text_8:
# 1037 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I keep trying to give him this Water\n"
	.string "Stone, but it just does nothing.\p"
	.string "Perhaps there's another way…$"

SpindaIsland_Home_EventScript_Juan_Text_0:
# 1050 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Juan$"

SpindaIsland_Home_EventScript_Juan_Text_1:
# 1053 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hey, wanna hear more interesting\n"
	.string "facts about Pokémon?$"

SpindaIsland_Home_EventScript_Juan_Text_2:
# 1063 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Nope$"

SpindaIsland_Home_EventScript_Juan_Text_3:
# 1064 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "No thanks$"

SpindaIsland_Home_EventScript_Juan_Text_4:
# 1069 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Bummer! Come back whenever, I have\n"
	.string "plenty!$"

SpindaIsland_Home_EventScript_Juan_Text_5:
# 1076 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I'm just taking my friend Machoke for\n"
	.string "a stroll!\p"
	.string "You know, I've always wondered where\n"
	.string "the cute little thong and belt come\l"
	.string "from.\p"
	.string "My Machoke was already wearing it\n"
	.string "when I caught him!\p"
	.string "Do they have like a Machoke thong\n"
	.string "shop somewhere and all the Machoke\l"
	.string "go there to get their thong?\p"
	.string "Is there a Machoke censor who\n"
	.string "travels across all lands, putting\l"
	.string "thongs on wild Machoke?\p"
	.string "Do they actually just grow their own\n"
	.string "thong naturally?\p"
	.string "Is it… {PAUSE 20}Is it their…\p"
	.string "… … …\p"
	.string "… …It is, isn't it?$"

SpindaIsland_Home_EventScript_Juan_Text_6:
# 1088 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Oh boy, what a find! I need to write\n"
	.string "this discovery down in my PokéDex!!$"

SpindaIsland_Home_EventScript_Machoke_Text_0:
# 1103 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Sexy Machoke$"

SpindaIsland_Home_EventScript_Machoke_Text_1:
# 1105 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Machoke$"

SpindaIsland_Home_EventScript_Machoke_Text_2:
# 1108 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hmmm…$"

SpindaIsland_Home_EventScript_Lisa_Text_0:
# 1119 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Lisa$"

SpindaIsland_Home_EventScript_Lisa_Text_1:
# 1121 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hey Archie! Heard you were building a\n"
	.string "sick pirate ship!$"

SpindaIsland_Home_EventScript_OldWoman_Text_0:
# 1134 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Old woman$"

SpindaIsland_Home_EventScript_OldWoman_Text_1:
# 1136 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I think my house is haunted. There's\n"
	.string "something living in my attic.\p"
	.string "I don't know what to do…$"

SpindaIsland_Home_EventScript_OldWoman_Text_2:
# 1147 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Oh, I'm too scared to go back inside…$"

SpindaIsland_Home_EventScript_OldWoman_Text_3:
# 1165 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Don't worry granny! There were some\n"
	.string "Shuppet in your attic, but I chased\l"
	.string "them away!$"

SpindaIsland_Home_EventScript_OldWoman_Text_4:
# 1173 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Shuppet, you say?$"

SpindaIsland_Home_EventScript_OldWoman_Text_5:
# 1177 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "How adorable of you to help out a poor\n"
	.string "old lady…\p"
	.string "Please take this, for your trouble!$"

SpindaIsland_Home_EventScript_OldWoman_Text_6:
# 1187 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Have a good day, child.$"

SpindaIsland_Home_EventScript_OldWomansDoor_Text_0:
# 1216 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I'm glad I was able to help!$"

SpindaIsland_Home_CarBoy_Text_0:
# 1228 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Rudy$"

SpindaIsland_Home_CarBoy_Text_1:
# 1230 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Vrrrbbbbbmmmmmmm!!!!!$"

SpindaIsland_Home_CarGirl_Text_0:
# 1244 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Katie$"

SpindaIsland_Home_CarGirl_Text_1:
# 1246 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Thanks a bunch!$"

SpindaIsland_Home_CarGirl_Text_2:
# 1256 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Oh!\p"
	.string "You've got this super cool {COLOR RED}metal\n"
	.string "wheel{COLOR DARK_GRAY}…\p"
	.string "And you're just giving it to us?\p"
	.string "You're the best, Archie!!\p"
	.string "We don't have much, but please take\n"
	.string "this.\p"
	.string "It's my lucky coin! I hope it'll be\n"
	.string "lucky for you, too!$"

SpindaIsland_Home_CarGirl_Text_3:
# 1273 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Now what could we use as a wheel…$"

SpindaIsland_Home_CarGirl_Text_4:
# 1282 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hey Archie!\p"
	.string "As you can see we're almost done with\n"
	.string "our monster car.\p"
	.string "We're just missing one last wheel!\p"
	.string "We don't really need it to be an actual\n"
	.string "wheel, either.\p"
	.string "Anything round and spinny would do!$"

SpindaIsland_Home_EventScript_MissingWheel_Text_0:
# 1306 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "A shiny new wheel!$"

SpindaIsland_Home_EventScript_MissingWheel_Text_1:
# 1314 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "A wheel is missing.\p"
	.string "I'm sure I could find a replacement.$"

SpindaIsland_Home_EventScript_ReplaceWheelWithBrokenFaucet_Text_0:
# 1330 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "What if…$"

SpindaIsland_Home_EventScript_ReplaceWheelWithBrokenFaucet_Text_1:
# 1347 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Fits perfectly! There ya go!$"

SpindaIsland_Home_EventScript_ReplaceWheelWithBrokenFaucet_Text_2:
# 1360 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "This'd be perfect, but I need to\n"
	.string "repair it!$"

SpindaIsland_Home_EventScript_SurveyedWheel_Text_0:
# 1373 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Just a regular wheel.$"

SpindaIsland_Home_EventScript_SurveyedWheel_Text_1:
# 1378 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Wait, it's stuck to the car with bolts!\p"
	.string "If I could just take one…$"

SpindaIsland_Home_EventScript_SurveyedWheel_Text_2:
# 1386 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Here, let me just…$"

SpindaIsland_Home_EventScript_SurveyedWheel_Text_3:
# 1395 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Whatcha doing, Archie?$"

SpindaIsland_Home_EventScript_SurveyedWheel_Text_4:
# 1403 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Ah, uh, nothing!$"

SpindaIsland_Home_EventScript_SurveyedWheel_Text_5:
# 1414 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "(Darn, can't do this right under her\n"
	.string "nose.)$"

SpindaIsland_Home_EventScript_SurveyedWheel_Text_6:
# 1421 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I'd need some pliers to get it out.$"

SpindaIsland_Home_EventScript_Raft_Text_0:
# 1444 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "At last! I can finally set sail!!$"

SpindaIsland_Home_EventScript_Raft_Text_1:
# 1458 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "And voilà!$"

SpindaIsland_Home_EventScript_Raft_Text_2:
# 1462 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Goodbye, Spinda Island…\p"
	.string "Hello, adventure!$"

SpindaIsland_Home_EventScript_Raft_Text_3:
# 1475 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "butt$"

SpindaIsland_Home_EventScript_Raft_Text_4:
# 1480 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "My super-awesome pirate ship!\p"
	.string "Only thing missing is the sail.$"

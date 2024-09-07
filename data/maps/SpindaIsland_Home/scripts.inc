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


SpindaIsland_Home_EventScript_SadManHome_Back::
# 46 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 47 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_unset FLAG_HIDE_MAN_CANT_GO_HOME, SpindaIsland_Home_EventScript_SadManHome_Back_2
# 56 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_RECEIVED_RUSTY_BOLT, SpindaIsland_Home_EventScript_SadManHome_Back_5
# 65 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 66 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 67 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SadManHome_Back_Text_2
# 70 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 71 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 73 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_SadManHome_Back_Text_3
# 74 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SadManHome_Back_Text_4
# 78 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 80 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_EXIT
# 82 "data/maps/SpindaIsland_Home/scripts.pory"
	clearflag FLAG_HIDE_MAN_CANT_GO_HOME
# 83 "data/maps/SpindaIsland_Home/scripts.pory"
	setobjectxyperm 6, 42, 24
# 84 "data/maps/SpindaIsland_Home/scripts.pory"
	addobject 6
# 85 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement 6, SpindaIsland_Home_Movement_SadManExitsHouse
# 86 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SpindaIsland_Home_Movement_PlayerMakesWay
# 87 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 88 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 6
# 89 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 90 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 91 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_NORMAL
# 92 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_SadManHome_Back_Text_3
# 93 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SadManHome_Back_Text_5
# 96 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 97 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 98 "data/maps/SpindaIsland_Home/scripts.pory"
	giveitem ITEM_RUSTY_BOLT
# 99 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_RECEIVED_RUSTY_BOLT
# 100 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement 6, SpindaIsland_Home_Movement_SadManReEntersHouse
# 101 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 102 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_EXIT
# 103 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject 6
# 104 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_HIDE_MAN_CANT_GO_HOME
# 105 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 107 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 109 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_FAUCET_QUEST_STARTED, SpindaIsland_Home_EventScript_SadManHome_Back_8
# 142 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 143 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 144 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SadManHome_Back_Text_9
# 149 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 150 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
SpindaIsland_Home_EventScript_SadManHome_Back_1:
# 154 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_SadManHome_Back_2:
# 48 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 49 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 50 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SadManHome_Back_Text_0
# 53 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 54 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_SadManHome_Back_1

SpindaIsland_Home_EventScript_SadManHome_Back_5:
# 57 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 58 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 59 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SadManHome_Back_Text_1
# 62 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 63 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_SadManHome_Back_1

SpindaIsland_Home_EventScript_SadManHome_Back_8:
# 110 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 111 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 112 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SadManHome_Back_Text_6
# 115 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 116 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 118 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 120 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_PIN
# 121 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 122 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 123 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 124 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 126 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 127 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 128 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SadManHome_Back_Text_7
# 132 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 133 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 134 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SadManHome_Back_Text_8
# 137 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 138 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 140 "data/maps/SpindaIsland_Home/scripts.pory"
	call SpindaIsland_Common_CheckGotAllItemsForNewFaucet
	goto SpindaIsland_Home_EventScript_SadManHome_Back_1


SpindaIsland_Home_EventScript_ICanNeverGoHome::
# 158 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 159 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 160 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_SAD
# 161 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_ICanNeverGoHome_Text_0
# 162 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_ICanNeverGoHome_Text_1, MSGBOX_NPC
# 166 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 167 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_Dad::
# 171 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 172 "data/maps/SpindaIsland_Home/scripts.pory"
	turnobject 7, DIR_SOUTH
# 173 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_OBTAINED_LEMONADE, SpindaIsland_Home_EventScript_Dad_2
# 183 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_SPOKE_TO_DAD, SpindaIsland_Home_EventScript_Dad_6
# 192 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_DAD, EMOTE_HAPPY
# 193 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_0
# 194 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_3
# 198 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 199 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
SpindaIsland_Home_EventScript_Dad_5:
# 202 "data/maps/SpindaIsland_Home/scripts.pory"
	giveitem ITEM_SALTY_LEMONADE
# 204 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 205 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 206 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 207 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_4
# 211 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 212 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 214 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 10
# 215 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_BALL
# 216 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 217 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_BALL
# 218 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 219 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_BALL
# 220 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 221 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 20
# 223 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_PIN
# 224 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 225 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 226 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 227 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 229 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_DISGUSTED
# 230 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 231 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_5
# 235 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 236 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 238 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_DAD, EMOTE_GRINNING
# 239 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_0
# 240 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_6
# 243 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 244 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_DAD, EMOTE_HAPPY
# 245 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_7
# 248 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 249 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_DAD, EMOTE_EMBARRASSED
# 250 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_8
# 253 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 254 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_DAD, EMOTE_HAPPY
# 255 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_9
# 259 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 260 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 262 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_OBTAINED_LEMONADE
# 263 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_SPOKE_TO_DAD
SpindaIsland_Home_EventScript_Dad_1:
# 265 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_Dad_2:
# 174 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_DAD, EMOTE_EMBARRASSED
# 175 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_0
# 176 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_1
# 180 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 181 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_Dad_1

SpindaIsland_Home_EventScript_Dad_6:
# 184 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_DAD, EMOTE_HAPPY
# 185 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_0
# 186 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_2
# 189 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 190 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_Dad_5


SpindaIsland_Home_EventScript_Dad_FromSide::
# 269 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 270 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 271 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_OBTAINED_LEMONADE, SpindaIsland_Home_EventScript_Dad_FromSide_2
# 281 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_SPOKE_TO_DAD, SpindaIsland_Home_EventScript_Dad_FromSide_6
# 290 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_DAD, EMOTE_HAPPY
# 291 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_0
# 292 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_FromSide_Text_1
# 297 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 298 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
SpindaIsland_Home_EventScript_Dad_FromSide_5:
# 300 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_SPOKE_TO_DAD
SpindaIsland_Home_EventScript_Dad_FromSide_1:
# 302 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_Dad_FromSide_2:
# 272 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_DAD, EMOTE_EMBARRASSED
# 273 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_0
# 274 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_1
# 278 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 279 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_Dad_FromSide_1

SpindaIsland_Home_EventScript_Dad_FromSide_6:
# 282 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_DAD, EMOTE_NORMAL
# 283 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_0
# 284 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_FromSide_Text_0
# 287 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 288 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_Dad_FromSide_5


SpindaIsland_Home_EventScript_LemonadeStandSign::
# 306 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_LemonadeStandSign_Text_0, MSGBOX_SIGN
	return


SpindaIsland_Home_EventScript_MainStreetSign::
# 313 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MainStreetSign_Text_0, MSGBOX_SIGN
	return


SpindaIsland_Home_EventScript_MadelineSign::
# 319 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MadelineSign_Text_0, MSGBOX_SIGN
	return


SpindaIsland_Home_EventScript_PoemGirl::
# 325 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 327 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_POEM_GIRL, SpindaIsland_Home_EventScript_PoemGirl_2
# 341 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_GRASSWHISTLE
# 342 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 344 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 346 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 347 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 348 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_2
# 353 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 354 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 356 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_3, SpindaIsland_Home_EventScript_PoemGirl_Text_4, SpindaIsland_Home_EventScript_PoemGirl_Text_5
# 368 "data/maps/SpindaIsland_Home/scripts.pory"
	switch VAR_RESULT
# 369 "data/maps/SpindaIsland_Home/scripts.pory"
	case 0, SpindaIsland_Home_EventScript_PoemGirl_6
# 414 "data/maps/SpindaIsland_Home/scripts.pory"
	case 1, SpindaIsland_Home_EventScript_PoemGirl_7
# 509 "data/maps/SpindaIsland_Home/scripts.pory"
	case 2, SpindaIsland_Home_EventScript_PoemGirl_8
SpindaIsland_Home_EventScript_PoemGirl_1:
# 607 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 608 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 609 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_PoemGirl_2:
# 328 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 329 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 330 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 331 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_1
# 334 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 335 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 337 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 338 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 339 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_GRASSWHISTLE
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_6:
# 370 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_6, SpindaIsland_Home_EventScript_PoemGirl_Text_7
# 381 "data/maps/SpindaIsland_Home/scripts.pory"
	switch VAR_RESULT
# 382 "data/maps/SpindaIsland_Home/scripts.pory"
	case 0, SpindaIsland_Home_EventScript_PoemGirl_11
# 393 "data/maps/SpindaIsland_Home/scripts.pory"
	case 1, SpindaIsland_Home_EventScript_PoemGirl_12
SpindaIsland_Home_EventScript_PoemGirl_9:
# 406 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 407 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 408 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_12
# 412 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 413 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_7:
# 415 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_13, SpindaIsland_Home_EventScript_PoemGirl_Text_14
# 425 "data/maps/SpindaIsland_Home/scripts.pory"
	switch VAR_RESULT
# 427 "data/maps/SpindaIsland_Home/scripts.pory"
	case 0, SpindaIsland_Home_EventScript_PoemGirl_14
# 486 "data/maps/SpindaIsland_Home/scripts.pory"
	case 1, SpindaIsland_Home_EventScript_PoemGirl_15
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_8:
# 510 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_24, SpindaIsland_Home_EventScript_PoemGirl_Text_13
# 521 "data/maps/SpindaIsland_Home/scripts.pory"
	switch VAR_RESULT
# 523 "data/maps/SpindaIsland_Home/scripts.pory"
	case 0, SpindaIsland_Home_EventScript_PoemGirl_17
# 546 "data/maps/SpindaIsland_Home/scripts.pory"
	case 1, SpindaIsland_Home_EventScript_PoemGirl_18
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_11:
# 383 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_8, SpindaIsland_Home_EventScript_PoemGirl_Text_9
	goto SpindaIsland_Home_EventScript_PoemGirl_9

SpindaIsland_Home_EventScript_PoemGirl_12:
# 394 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_10, SpindaIsland_Home_EventScript_PoemGirl_Text_11
	goto SpindaIsland_Home_EventScript_PoemGirl_9

SpindaIsland_Home_EventScript_PoemGirl_14:
# 428 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_15, SpindaIsland_Home_EventScript_PoemGirl_Text_16
# 439 "data/maps/SpindaIsland_Home/scripts.pory"
	switch VAR_RESULT
# 441 "data/maps/SpindaIsland_Home/scripts.pory"
	case 0, SpindaIsland_Home_EventScript_PoemGirl_20
# 463 "data/maps/SpindaIsland_Home/scripts.pory"
	case 1, SpindaIsland_Home_EventScript_PoemGirl_21
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_15:
# 487 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_21, SpindaIsland_Home_EventScript_PoemGirl_Text_22
# 498 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 499 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 500 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_23
# 506 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 507 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_17:
# 524 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_25, SpindaIsland_Home_EventScript_PoemGirl_Text_26
# 535 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 536 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 537 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_27
# 542 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 543 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_18:
# 547 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_28, SpindaIsland_Home_EventScript_PoemGirl_Text_29
# 558 "data/maps/SpindaIsland_Home/scripts.pory"
	switch VAR_RESULT
# 559 "data/maps/SpindaIsland_Home/scripts.pory"
	case 0, SpindaIsland_Home_EventScript_PoemGirl_23
# 569 "data/maps/SpindaIsland_Home/scripts.pory"
	case 1, SpindaIsland_Home_EventScript_PoemGirl_24
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_20:
# 442 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_17, SpindaIsland_Home_EventScript_PoemGirl_Text_18
# 453 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 454 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 455 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_19
# 459 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 460 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_21:
# 464 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_17, SpindaIsland_Home_EventScript_PoemGirl_Text_18
# 475 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 476 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 477 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_20
# 481 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 482 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_23:
# 560 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 561 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 562 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_27
# 567 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 568 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_24:
# 570 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_30
# 579 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 580 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 581 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_31
# 588 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 589 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 591 "data/maps/SpindaIsland_Home/scripts.pory"
	giveitem ITEM_GRASS_BLADE
# 593 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 594 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 595 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_32
# 599 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 600 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 602 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_POEM_GIRL
	goto SpindaIsland_Home_EventScript_PoemGirl_1


SpindaIsland_Home_EventScript_Sunbather::
# 613 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 614 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_SUNBATHER, EMOTE_NORMAL
# 615 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Sunbather_Text_0
# 616 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Sunbather_Text_1
# 620 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 621 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 622 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 623 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 625 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_SUNBATHER, EMOTE_PENSIVE
# 626 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Sunbather_Text_0
# 627 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Sunbather_Text_2
# 630 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 631 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 632 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 633 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 634 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_Slowpoke::
# 638 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 639 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_SLOWPOKE_EVOLVED, SpindaIsland_Home_Slowpoke_2
# 650 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 651 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_SLOWPOKE, CRY_MODE_NORMAL
# 652 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_Slowpoke_Text_2
# 653 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Slowpoke_Text_3
# 656 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmoncry
# 657 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	checkitem ITEM_WHITE_SEASHELL
# 0 "data/maps/SpindaIsland_Home/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq SpindaIsland_Home_Slowpoke_5
SpindaIsland_Home_Slowpoke_1:
# 739 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_Slowpoke_2:
# 640 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 641 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_SLOWBRO, CRY_MODE_NORMAL
# 642 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_Slowpoke_Text_0
# 643 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Slowpoke_Text_1
# 646 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmoncry
# 647 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_Slowpoke_1

SpindaIsland_Home_Slowpoke_5:
# 660 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_THINKING
# 661 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 662 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Slowpoke_Text_4
# 667 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_Slowpoke_Text_5, SpindaIsland_Home_Slowpoke_Text_6
# 677 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 678 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 680 "data/maps/SpindaIsland_Home/scripts.pory"
	switch VAR_RESULT
# 681 "data/maps/SpindaIsland_Home/scripts.pory"
	case 0, SpindaIsland_Home_Slowpoke_8
# 726 "data/maps/SpindaIsland_Home/scripts.pory"
	case 1, SpindaIsland_Home_Slowpoke_9
	goto SpindaIsland_Home_Slowpoke_1

SpindaIsland_Home_Slowpoke_8:
# 682 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 683 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 684 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Slowpoke_Text_7
# 688 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 690 "data/maps/SpindaIsland_Home/scripts.pory"
	removeitem ITEM_WHITE_SEASHELL
# 692 "data/maps/SpindaIsland_Home/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( SLOWBRO )
# 693 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_SHELLDER, CRY_MODE_NORMAL
# 694 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmoncry
# 695 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject VAR_LAST_TALKED
# 696 "data/maps/SpindaIsland_Home/scripts.pory"
	addobject VAR_LAST_TALKED
# 697 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_BITE
# 698 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, SpindaIsland_Home_Movement_Slowpoke
# 699 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 700 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement VAR_LAST_TALKED
# 701 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 703 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_SLOWPOKE, CRY_MODE_NORMAL
# 704 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_Slowpoke_Text_0
# 705 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Slowpoke_Text_8
# 708 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmoncry
# 709 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 711 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_SHOCKED
# 712 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 713 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Slowpoke_Text_9
# 717 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 718 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 719 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Slowpoke_Text_10
# 722 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 723 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 725 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_SLOWPOKE_EVOLVED
	goto SpindaIsland_Home_Slowpoke_1

SpindaIsland_Home_Slowpoke_9:
# 727 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_SLOWPOKE, CRY_MODE_FAINT
# 728 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_Slowpoke_Text_2
# 729 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Slowpoke_Text_11
# 733 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmoncry
# 734 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_Slowpoke_1


SpindaIsland_Home_EventScript_Metapod::
# 743 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 744 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Metapod_Text_0
# 745 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_METAPOD, CRY_MODE_NORMAL
# 746 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Metapod_Text_1
# 749 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmoncry
# 750 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 751 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_MetapodBoysFuckOff::
# 755 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 756 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_TWIN, EMOTE_ANGRY
# 757 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0
# 758 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_1
# 762 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_TWIN, EMOTE_NORMAL
# 763 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_2
# 767 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 769 "data/maps/SpindaIsland_Home/scripts.pory"
	fadescreen FADE_TO_BLACK
# 770 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_HIDE_METAPOD_BATTLE
# 771 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject 1
# 772 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject 2
# 773 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject 3
# 774 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject 4
# 775 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 60
# 776 "data/maps/SpindaIsland_Home/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 777 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 40
# 778 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Bussin::
# 782 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 783 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_TWIN, EMOTE_ANGRY
# 784 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0
# 785 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Bussin_Text_0
# 789 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_TWIN, EMOTE_NORMAL
# 790 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Bussin_Text_1
# 794 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 796 "data/maps/SpindaIsland_Home/scripts.pory"
	fadescreen FADE_TO_BLACK
# 797 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_HIDE_METAPOD_BATTLE
# 798 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject 1
# 799 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject 2
# 800 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject 3
# 801 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject 4
# 802 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 60
# 803 "data/maps/SpindaIsland_Home/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 804 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 40
# 805 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_MetapodBoy::
# 809 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 810 "data/maps/SpindaIsland_Home/scripts.pory"
	compare VAR_METAPOD_OTHER_SIDE, 1
	goto_if_eq SpindaIsland_Home_EventScript_MetapodBoy_2
SpindaIsland_Home_EventScript_MetapodBoy_1:
# 813 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_TWIN, EMOTE_ANGRY
# 814 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0
# 815 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoy_Text_0
# 818 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 819 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 821 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 823 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_TWIN, EMOTE_FINGER
# 824 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0
# 825 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoy_Text_1
# 828 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 829 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 831 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 833 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_TWIN, EMOTE_ANGRY
# 834 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0
# 835 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoy_Text_2
# 838 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 839 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 841 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_HARDEN
# 842 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 843 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_HARDEN
# 844 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 845 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 846 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_MetapodBoy_2:
# 811 "data/maps/SpindaIsland_Home/scripts.pory"
	goto SpindaIsland_Home_EventScript_MetapodBoysFuckOff
	goto SpindaIsland_Home_EventScript_MetapodBoy_1


SpindaIsland_Home_EventScript_MetapodBoy_Bussin::
# 850 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 851 "data/maps/SpindaIsland_Home/scripts.pory"
	compare VAR_METAPOD_OTHER_SIDE, 1
	goto_if_eq SpindaIsland_Home_EventScript_MetapodBoy_Bussin_2
SpindaIsland_Home_EventScript_MetapodBoy_Bussin_1:
# 854 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_TWIN, EMOTE_ANGRY
# 855 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0
# 856 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoy_Bussin_Text_0
# 859 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 860 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 862 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 864 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_TWIN, EMOTE_FINGER
# 865 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0
# 866 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoy_Bussin_Text_1
# 869 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 870 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 872 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 874 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_TWIN, EMOTE_ANGRY
# 875 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0
# 876 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoy_Bussin_Text_2
# 879 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 880 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 882 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_HARDEN
# 883 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 884 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_HARDEN
# 885 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 886 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 887 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_MetapodBoy_Bussin_2:
# 852 "data/maps/SpindaIsland_Home/scripts.pory"
	goto SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Bussin
	goto SpindaIsland_Home_EventScript_MetapodBoy_Bussin_1


SpindaIsland_Home_PhotoCameraWrongDir::
# 891 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 893 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_CAMERA_EXPLODED, SpindaIsland_Home_PhotoCameraWrongDir_2
# 902 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 903 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 904 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_PhotoCameraWrongDir_Text_1
# 907 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 908 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
SpindaIsland_Home_PhotoCameraWrongDir_1:
# 910 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_PhotoCameraWrongDir_2:
# 894 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 895 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 896 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_PhotoCameraWrongDir_Text_0
# 899 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 900 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
	goto SpindaIsland_Home_PhotoCameraWrongDir_1


SpindaIsland_Home_EventScript_FaucetShopSign::
# 914 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_FaucetShopSign_Text_0, MSGBOX_SIGN
	return


# 921 "data/maps/SpindaIsland_Home/scripts.pory"
SpindaIsland_Home_Movement_SadManExitsHouse:
# 922 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_down
	step_end

# 925 "data/maps/SpindaIsland_Home/scripts.pory"
SpindaIsland_Home_Movement_SadManReEntersHouse:
# 926 "data/maps/SpindaIsland_Home/scripts.pory"
	face_up
# 927 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 928 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
	step_end

# 931 "data/maps/SpindaIsland_Home/scripts.pory"
SpindaIsland_Home_Movement_PlayerMakesWay:
# 932 "data/maps/SpindaIsland_Home/scripts.pory"
	lock_facing_direction
# 933 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_down
# 934 "data/maps/SpindaIsland_Home/scripts.pory"
	unlock_facing_direction
	step_end

# 937 "data/maps/SpindaIsland_Home/scripts.pory"
SpindaIsland_Home_Movement_Slowpoke:
# 938 "data/maps/SpindaIsland_Home/scripts.pory"
	lock_facing_direction
# 939 "data/maps/SpindaIsland_Home/scripts.pory"
	jump_in_place_down
# 940 "data/maps/SpindaIsland_Home/scripts.pory"
	unlock_facing_direction
# 941 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 941 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 941 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 942 "data/maps/SpindaIsland_Home/scripts.pory"
	face_up
# 943 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 944 "data/maps/SpindaIsland_Home/scripts.pory"
	face_down
# 945 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 946 "data/maps/SpindaIsland_Home/scripts.pory"
	face_left
# 947 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 948 "data/maps/SpindaIsland_Home/scripts.pory"
	face_up
# 949 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 950 "data/maps/SpindaIsland_Home/scripts.pory"
	face_player
# 951 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 951 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 951 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 952 "data/maps/SpindaIsland_Home/scripts.pory"
	lock_facing_direction
# 953 "data/maps/SpindaIsland_Home/scripts.pory"
	jump_in_place_down
# 954 "data/maps/SpindaIsland_Home/scripts.pory"
	jump_in_place_down
# 955 "data/maps/SpindaIsland_Home/scripts.pory"
	unlock_facing_direction
# 956 "data/maps/SpindaIsland_Home/scripts.pory"
	emote_heart
# 957 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 957 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 957 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
	step_end

SpindaIsland_Home_SlowpokeMistress::
# 961 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 962 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 963 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_RECEIVED_SLOWPOKE_REWARD, SpindaIsland_Home_SlowpokeMistress_2
# 972 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_SLOWPOKE_EVOLVED, SpindaIsland_Home_SlowpokeMistress_3
# 1016 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LASS, EMOTE_SWEAT
# 1017 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_SlowpokeMistress_Text_0
# 1018 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_SlowpokeMistress_Text_7
# 1021 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1022 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LASS, EMOTE_NORMAL
# 1023 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_SlowpokeMistress_Text_8
# 1027 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1028 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
SpindaIsland_Home_SlowpokeMistress_1:
# 1030 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_SlowpokeMistress_2:
# 964 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LASS, EMOTE_HAPPY
# 965 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_SlowpokeMistress_Text_0
# 966 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_SlowpokeMistress_Text_1
# 970 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 971 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_SlowpokeMistress_1

SpindaIsland_Home_SlowpokeMistress_3:
# 973 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_PIN
# 974 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
# 975 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 976 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 977 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 979 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LASS, EMOTE_SURPRISED
# 980 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_SlowpokeMistress_Text_0
# 981 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_SlowpokeMistress_Text_2
# 985 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 986 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LASS, EMOTE_NORMAL
# 987 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_SlowpokeMistress_Text_3
# 990 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 991 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LASS, EMOTE_HAPPY
# 992 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_SlowpokeMistress_Text_4
# 995 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 996 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LASS, EMOTE_NORMAL
# 997 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_SlowpokeMistress_Text_5
# 1000 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1001 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1003 "data/maps/SpindaIsland_Home/scripts.pory"
	giveitem ITEM_WATER_STONE_2
# 1005 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_THINKING
# 1006 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 1007 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_SlowpokeMistress_Text_6
# 1011 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1012 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1014 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_RECEIVED_SLOWPOKE_REWARD
	goto SpindaIsland_Home_SlowpokeMistress_1


SpindaIsland_Home_EventScript_Juan::
# 1034 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1035 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1036 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_NORMAL
# 1037 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Juan_Text_0
# 1038 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_TALKED_TO_JUAN_ABOUT_PUBES, SpindaIsland_Home_EventScript_Juan_2
# 1062 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Juan_Text_5
# 1073 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_SURPRISED
# 1074 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Juan_Text_6
# 1077 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1078 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1079 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_TALKED_TO_JUAN_ABOUT_PUBES
SpindaIsland_Home_EventScript_Juan_1:
# 1082 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_Juan_2:
# 1039 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Juan_Text_1
# 1043 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_Juan_Text_2, SpindaIsland_Home_EventScript_Juan_Text_3
# 1054 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_GRINNING
# 1055 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Juan_Text_4
# 1059 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1060 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_Juan_1


SpindaIsland_Home_EventScript_Machoke::
# 1086 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1087 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1088 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_MACHOKE, CRY_MODE_NORMAL
# 1089 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_TALKED_TO_JUAN_ABOUT_PUBES, SpindaIsland_Home_EventScript_Machoke_2
# 1092 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Machoke_Text_1
SpindaIsland_Home_EventScript_Machoke_1:
# 1094 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Machoke_Text_2
# 1097 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 1098 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1099 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_Machoke_2:
# 1090 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Machoke_Text_0
	goto SpindaIsland_Home_EventScript_Machoke_1


SpindaIsland_Home_CarBoy::
# 1103 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1104 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1105 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_BOY, EMOTE_NORMAL
# 1106 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_CarBoy_Text_0
# 1107 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_CarBoy_Text_1
# 1110 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1111 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1112 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 1113 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 1114 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_CarGirl::
# 1118 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1119 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_RECEIVED_NICKEL, SpindaIsland_Home_CarGirl_2
# 1129 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_REPLACED_WHEEL, SpindaIsland_Home_CarGirl_3
# 1146 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_LOOKING_FOR_WHEEL_REPLACEMENT, SpindaIsland_Home_CarGirl_4
# 1156 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1157 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_NORMAL
# 1158 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_CarGirl_Text_0
# 1159 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_CarGirl_Text_4
# 1166 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1167 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1169 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_LOOKING_FOR_WHEEL_REPLACEMENT
SpindaIsland_Home_CarGirl_1:
# 1172 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 1173 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 1175 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_CarGirl_2:
# 1120 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1121 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_NORMAL
# 1122 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_CarGirl_Text_0
# 1123 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_CarGirl_Text_1
# 1126 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1127 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_CarGirl_1

SpindaIsland_Home_CarGirl_3:
# 1130 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1131 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_NORMAL
# 1132 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_CarGirl_Text_0
# 1133 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_CarGirl_Text_2
# 1141 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1142 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1144 "data/maps/SpindaIsland_Home/scripts.pory"
	giveitem ITEM_RUSTY_NICKEL
# 1145 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_RECEIVED_NICKEL
	goto SpindaIsland_Home_CarGirl_1

SpindaIsland_Home_CarGirl_4:
# 1147 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1148 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 1149 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_CarGirl_Text_0
# 1150 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_CarGirl_Text_3
# 1153 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1154 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_CarGirl_1


SpindaIsland_Home_EventScript_MissingWheel::
# 1179 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1180 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_REPLACED_WHEEL, SpindaIsland_Home_EventScript_MissingWheel_2
# 1189 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1190 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 1191 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MissingWheel_Text_1
# 1195 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1196 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
SpindaIsland_Home_EventScript_MissingWheel_1:
# 1198 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_MissingWheel_2:
# 1181 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 1182 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 1183 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MissingWheel_Text_0
# 1186 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1187 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_MissingWheel_1


SpindaIsland_Home_EventScript_ReplaceWheelWithBrokenFaucet::
# 1202 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1204 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1205 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 1206 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_ReplaceWheelWithBrokenFaucet_Text_0
# 1209 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1210 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1212 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 1214 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_CLICK
# 1215 "data/maps/SpindaIsland_Home/scripts.pory"
	setmetatile 27, 50, METATILE_SpindaIslandSecondary_FaucetWheel, TRUE
# 1216 "data/maps/SpindaIsland_Home/scripts.pory"
	special DrawWholeMapView
# 1217 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 1219 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 1221 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 1222 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 1223 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_ReplaceWheelWithBrokenFaucet_Text_1
# 1226 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1227 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1229 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_REPLACED_WHEEL
# 1231 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_SurveyedWheel::
# 1235 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1236 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_FAUCET_QUEST_STARTED, SpindaIsland_Home_EventScript_SurveyedWheel_4
SpindaIsland_Home_EventScript_SurveyedWheel_3:
# 1294 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1295 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 1296 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SurveyedWheel_Text_0
# 1299 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1300 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
SpindaIsland_Home_EventScript_SurveyedWheel_1:
# 1302 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_SurveyedWheel_2:
# 1237 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1238 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 1239 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SurveyedWheel_Text_0
# 1242 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1243 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 1244 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SurveyedWheel_Text_1
# 1248 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
	checkitem ITEM_BORROWED_PLIERS
# 0 "data/maps/SpindaIsland_Home/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne SpindaIsland_Home_EventScript_SurveyedWheel_7
# 1286 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1287 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SurveyedWheel_Text_6
# 1290 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1291 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_SurveyedWheel_1

SpindaIsland_Home_EventScript_SurveyedWheel_4:
# 1236 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_unset FLAG_FOUND_TOUGH_BOLT, SpindaIsland_Home_EventScript_SurveyedWheel_2
	goto SpindaIsland_Home_EventScript_SurveyedWheel_3

SpindaIsland_Home_EventScript_SurveyedWheel_7:
# 1251 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1252 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SurveyedWheel_Text_2
# 1255 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1256 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1258 "data/maps/SpindaIsland_Home/scripts.pory"
	turnobject 15, DIR_EAST
# 1259 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_NORMAL
# 1260 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_CarGirl_Text_0
# 1261 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SurveyedWheel_Text_3
# 1264 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1265 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1267 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 1268 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 1269 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SurveyedWheel_Text_4
# 1272 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1273 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1275 "data/maps/SpindaIsland_Home/scripts.pory"
	turnobject 15, DIR_NORTH
# 1276 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 1278 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1279 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 1280 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SurveyedWheel_Text_5
# 1283 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1284 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_SurveyedWheel_1


SpindaIsland_Home_EventScript_MainQuestRecap_Text_0:
# 20 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Little Archie$"

SpindaIsland_Home_EventScript_MainQuestRecap_Text_1:
# 22 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Alright! The quicker mom gets her\n"
	.string "glass of {COLOR BLUE}WATER{COLOR DARK_GRAY}, the quicker Archie\l"
	.string "gets his super badass pirate {COLOR RED}sail{COLOR DARK_GRAY}!\p"
	.string "Let's get moving!$"

SpindaIsland_Home_EventScript_ArchiesHouseSign_Text_0:
# 38 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "The Hoenns$"

SpindaIsland_Home_EventScript_BobsHouseSign_Text_0:
# 42 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Bob$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_0:
# 51 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Door's locked.$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_1:
# 60 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I guess I should leave him alone now.$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_2:
# 68 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hello? Are you there?$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_3:
# 73 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Stingy man$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_4:
# 75 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "…\p"
	.string "My GOD you're annoying.$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_5:
# 94 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Here's your reward. I hope you're\n"
	.string "happy.$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_6:
# 113 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "An old and rusty bolt? What am I\n"
	.string "supposed to do with this?$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_7:
# 129 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "A {COLOR RED}bolt{COLOR DARK_GRAY}! Of course! Lucky me!\p"
	.string "I'm one step closer to getting that\n"
	.string "sweet sweet faucet replacement!!$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_8:
# 135 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "(Did I really say that? Is this how\n"
	.string "being a grownup feels like?)$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_9:
# 145 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "A bolt?\p"
	.string "It's all rusty…\p"
	.string "Guess it'll join my useless trash\n"
	.string "collection!$"

SpindaIsland_Home_EventScript_ICanNeverGoHome_Text_0:
# 161 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Sad man$"

SpindaIsland_Home_EventScript_ICanNeverGoHome_Text_1:
# 163 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Curse the architect that built my\n"
	.string "house facing the wrong direction!!\p"
	.string "I can never go home!$"

SpindaIsland_Home_EventScript_Dad_Text_0:
# 175 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Dad$"

SpindaIsland_Home_EventScript_Dad_Text_1:
# 177 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Don't uh, pour that lemonade I gave\n"
	.string "you on the ground or anything.\p"
	.string "It'd probably kill all the grass and\n"
	.string "flowers.$"

SpindaIsland_Home_EventScript_Dad_Text_2:
# 187 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Here, have some lemonade!$"

SpindaIsland_Home_EventScript_Dad_Text_3:
# 195 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hiya, sonny! going adventuring today,\n"
	.string "are we?\p"
	.string "Want some lemonade?$"

SpindaIsland_Home_EventScript_Dad_Text_4:
# 208 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Now we're talkin'!! I can bring this to\n"
	.string "mom, that should do it!\p"
	.string "Let's take a sip first, I am PARCHED!$"

SpindaIsland_Home_EventScript_Dad_Text_5:
# 232 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "BLEARGH!\p"
	.string "Why is it… so salty?!$"

SpindaIsland_Home_EventScript_Dad_Text_6:
# 241 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Why, because it's seawater, obviously!$"

SpindaIsland_Home_EventScript_Dad_Text_7:
# 246 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I take it you're not a fan of my\n"
	.string "recipe?$"

SpindaIsland_Home_EventScript_Dad_Text_8:
# 251 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "(You wouldn't be the only one…)$"

SpindaIsland_Home_EventScript_Dad_Text_9:
# 256 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "In any case, it's nice of you to come\n"
	.string "visit me at the office, haha!\p"
	.string "See you around, little Archie! Don't\n"
	.string "get into trouble!$"

SpindaIsland_Home_EventScript_Dad_FromSide_Text_0:
# 285 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Come round to the front of the\n"
	.string "lemonade stand!$"

SpindaIsland_Home_EventScript_Dad_FromSide_Text_1:
# 293 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hiya, sonny! going adventuring today,\n"
	.string "are we?\p"
	.string "Want some lemonade?\p"
	.string "Come round to the front of the\n"
	.string "lemonade stand!$"

SpindaIsland_Home_EventScript_LemonadeStandSign_Text_0:
# 307 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "“ARCHIE'S LEMONADE\n"
	.string "A taste of the seaside!”$"

SpindaIsland_Home_EventScript_MainStreetSign_Text_0:
# 314 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "{UP_ARROW} Main street$"

SpindaIsland_Home_EventScript_MadelineSign_Text_0:
# 320 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Madeline$"

SpindaIsland_Home_EventScript_PoemGirl_Text_0:
# 330 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Maggie$"

SpindaIsland_Home_EventScript_PoemGirl_Text_1:
# 332 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "See you around, Archie…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_2:
# 349 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Archie…\p"
	.string "I want to hear a poem…\p"
	.string "I want you to reveal your heart to me.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_3:
# 363 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Ocean waves swimming…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_4:
# 364 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Roses are red…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_5:
# 365 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Roses are blue…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_6:
# 377 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "From the center of the sea…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_7:
# 378 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "They are calling to my heart…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_8:
# 390 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "With faith to reach land.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_9:
# 391 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Only to go back.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_10:
# 401 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "And my heart to theirs.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_11:
# 402 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Yearning for a touch.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_12:
# 409 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "That was very beautiful.\p"
	.string "I'm not really into haiku, though.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_13:
# 422 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Violets are blue…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_14:
# 423 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Just like our love…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_15:
# 435 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "The sky is pretty…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_16:
# 436 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "The Pincurchin are spiky…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_17:
# 449 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "And so are you.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_18:
# 450 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "And so are you!$"

SpindaIsland_Home_EventScript_PoemGirl_Text_19:
# 456 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Oh, that's nice.\p"
	.string "You're not truly revealing your poet's\n"
	.string "heart, though.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_20:
# 478 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "That's… a weird comparison.\p"
	.string "I thought you were a better poet\n"
	.string "than that.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_21:
# 494 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Which blooms like they do.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_22:
# 495 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Wait, I didn't mean to say that.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_23:
# 501 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Wow, Archie, uh…\p"
	.string "That's not really what I meant when I\n"
	.string "said you should reveal your heart.\p"
	.string "(Well, this is awkward.)\p"
	.string "(Let's pretend this never happened.)$"

SpindaIsland_Home_EventScript_PoemGirl_Text_24:
# 517 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Violets are red…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_25:
# 531 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "The sky isn't blue, it's purple instead.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_26:
# 532 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Doesn't make sense, but fun to be said.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_27:
# 538 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hmm…\p"
	.string "You're not revealing your heart right\n"
	.string "now.\p"
	.string "Plus, that didn't make any sense.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_28:
# 554 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Orchids are blue, too.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_29:
# 555 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Everything is blue…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_30:
# 577 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Because it's my favorite color.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_31:
# 582 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "… … … … …\p"
	.string "Wow, Archie, I…\p"
	.string "This was so touching…\p"
	.string "Thank you for revealing your heart to\n"
	.string "me like this.\p"
	.string "Here, take this.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_32:
# 596 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "It's a blade of grass large enough to\n"
	.string "whistle with.\p"
	.string "Just don't listen to it too\n"
	.string "attentively, you might get sleepy.$"

SpindaIsland_Home_EventScript_Sunbather_Text_0:
# 615 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Sunbather$"

SpindaIsland_Home_EventScript_Sunbather_Text_1:
# 617 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Ahh, it sure feels good to be sitting\n"
	.string "in the sun surrounded by all this\l"
	.string "{COLOR BLUE}WATER{COLOR DARK_GRAY}…\p"
	.string "…$"

SpindaIsland_Home_EventScript_Sunbather_Text_2:
# 628 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Could you leave? You're blocking the\n"
	.string "sun.$"

SpindaIsland_Home_Slowpoke_Text_0:
# 642 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Slowbro$"

SpindaIsland_Home_Slowpoke_Text_1:
# 644 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Bruh…$"

SpindaIsland_Home_Slowpoke_Text_2:
# 652 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Slowpoke$"

SpindaIsland_Home_Slowpoke_Text_3:
# 654 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Slo…$"

SpindaIsland_Home_Slowpoke_Text_4:
# 663 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "… … …?\p"
	.string "He's looking at the white seashell I\n"
	.string "found…$"

SpindaIsland_Home_Slowpoke_Text_5:
# 674 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Give the seashell$"

SpindaIsland_Home_Slowpoke_Text_6:
# 675 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Don't give the seashell$"

SpindaIsland_Home_Slowpoke_Text_7:
# 685 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Sure, why the hell not!\p"
	.string "Here you go, buddy.$"

SpindaIsland_Home_Slowpoke_Text_8:
# 706 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Bruh!!$"

SpindaIsland_Home_Slowpoke_Text_9:
# 714 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "The heck?!\p"
	.string "My seashell bit him!$"

SpindaIsland_Home_Slowpoke_Text_10:
# 720 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Guess it was a Shellder all this time!$"

SpindaIsland_Home_Slowpoke_Text_11:
# 730 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "…Slo…\p"
	.string ":($"

SpindaIsland_Home_EventScript_Metapod_Text_0:
# 744 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Metapod$"

SpindaIsland_Home_EventScript_Metapod_Text_1:
# 747 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "…$"

SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0:
# 757 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Twin$"

SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_1:
# 759 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "What is it?!$"

SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_2:
# 764 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Oh, I guess we are blocking the stairs\n"
	.string "a little…\p"
	.string "Fine, we'll take our epic battle\n"
	.string "somewhere else.$"

SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Bussin_Text_0:
# 786 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "On god why you gotta bust my balls\n"
	.string "like that fr?!$"

SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Bussin_Text_1:
# 791 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Yikes, we lowkey do be blockin the\n"
	.string "stairs rn no cap…\p"
	.string "Aight word word, we gon vibe\n"
	.string "somewhere else.$"

SpindaIsland_Home_EventScript_MetapodBoy_Text_0:
# 816 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I'm SO CLOSE to tasting that sweet,\n"
	.string "sweet victory!$"

SpindaIsland_Home_EventScript_MetapodBoy_Text_1:
# 826 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Can't you see we're in the midst of a\n"
	.string "fiery battle?$"

SpindaIsland_Home_EventScript_MetapodBoy_Text_2:
# 836 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Metapod, use harden!!$"

SpindaIsland_Home_EventScript_MetapodBoy_Bussin_Text_0:
# 857 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I'm deadass SO CLOSE to catchin that\n"
	.string "bussin drip fr!$"

SpindaIsland_Home_EventScript_MetapodBoy_Bussin_Text_1:
# 867 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Can't you see we tryna catch some\n"
	.string "real heat rn bro? Sheesh!$"

SpindaIsland_Home_EventScript_MetapodBoy_Bussin_Text_2:
# 877 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Metapod, keep hittin that mid boi with\n"
	.string "harden, chief!!$"

SpindaIsland_Home_PhotoCameraWrongDir_Text_0:
# 897 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Nothing left but a pile of ashes…$"

SpindaIsland_Home_PhotoCameraWrongDir_Text_1:
# 905 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Can't use that from this side.$"

SpindaIsland_Home_EventScript_FaucetShopSign_Text_0:
# 915 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "“FAUCET WORKSHOP\n"
	.string "For all your faucet needs!\l"
	.string "WE ARE OPEN!!”$"

SpindaIsland_Home_SlowpokeMistress_Text_0:
# 965 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Girl$"

SpindaIsland_Home_SlowpokeMistress_Text_1:
# 967 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Look at my super cool Slowbro!\p"
	.string "He just looks so happy!$"

SpindaIsland_Home_SlowpokeMistress_Text_2:
# 982 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "By Arceus!!\p"
	.string "How on earth did you convince him to\n"
	.string "evolve?$"

SpindaIsland_Home_SlowpokeMistress_Text_3:
# 988 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "…A cool-looking seashell? What are\n"
	.string "you talking about?$"

SpindaIsland_Home_SlowpokeMistress_Text_4:
# 993 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Well, thank you anyway! You can have\n"
	.string "this!$"

SpindaIsland_Home_SlowpokeMistress_Text_5:
# 998 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I no longer need it.$"

SpindaIsland_Home_SlowpokeMistress_Text_6:
# 1008 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hmm… A {COLOR BLUE}WATER{COLOR DARK_GRAY} Stone…\p"
	.string "Maybe I could try giving this to mom?$"

SpindaIsland_Home_SlowpokeMistress_Text_7:
# 1019 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I wish my Pokémon would evolve…$"

SpindaIsland_Home_SlowpokeMistress_Text_8:
# 1024 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I keep trying to give him this Water\n"
	.string "Stone, but it just does nothing.\p"
	.string "Perhaps there's another way…$"

SpindaIsland_Home_EventScript_Juan_Text_0:
# 1037 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Juan$"

SpindaIsland_Home_EventScript_Juan_Text_1:
# 1040 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hey, wanna hear more interesting\n"
	.string "facts about Pokémon?$"

SpindaIsland_Home_EventScript_Juan_Text_2:
# 1050 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Nope$"

SpindaIsland_Home_EventScript_Juan_Text_3:
# 1051 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "No thanks$"

SpindaIsland_Home_EventScript_Juan_Text_4:
# 1056 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Bummer! Come back whenever, I have\n"
	.string "plenty!$"

SpindaIsland_Home_EventScript_Juan_Text_5:
# 1063 "data/maps/SpindaIsland_Home/scripts.pory"
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
# 1075 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Oh boy, what a finding! I need to write\n"
	.string "this discovery down in my PokéDex!!$"

SpindaIsland_Home_EventScript_Machoke_Text_0:
# 1090 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Sexy Machoke$"

SpindaIsland_Home_EventScript_Machoke_Text_1:
# 1092 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Machoke$"

SpindaIsland_Home_EventScript_Machoke_Text_2:
# 1095 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hmmm…$"

SpindaIsland_Home_CarBoy_Text_0:
# 1106 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Rudy$"

SpindaIsland_Home_CarBoy_Text_1:
# 1108 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Vrrrbbbbbmmmmmmm!!!!!$"

SpindaIsland_Home_CarGirl_Text_0:
# 1122 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Katie$"

SpindaIsland_Home_CarGirl_Text_1:
# 1124 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Thanks a bunch!$"

SpindaIsland_Home_CarGirl_Text_2:
# 1134 "data/maps/SpindaIsland_Home/scripts.pory"
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
# 1151 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Now what could we use as a wheel…$"

SpindaIsland_Home_CarGirl_Text_4:
# 1160 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hey Archie!\p"
	.string "As you can see we're almost done with\n"
	.string "our monster car.\p"
	.string "We're just missing one last wheel!\p"
	.string "We don't really need it to be an actual\n"
	.string "wheel, either.\p"
	.string "Anything round and spinny would do!$"

SpindaIsland_Home_EventScript_MissingWheel_Text_0:
# 1184 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "A shiny new wheel!$"

SpindaIsland_Home_EventScript_MissingWheel_Text_1:
# 1192 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "A wheel is missing.\p"
	.string "I'm sure I could find a replacement.$"

SpindaIsland_Home_EventScript_ReplaceWheelWithBrokenFaucet_Text_0:
# 1207 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "What if…$"

SpindaIsland_Home_EventScript_ReplaceWheelWithBrokenFaucet_Text_1:
# 1224 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Fits perfectly! There ya go!$"

SpindaIsland_Home_EventScript_SurveyedWheel_Text_0:
# 1240 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Just a regular wheel.$"

SpindaIsland_Home_EventScript_SurveyedWheel_Text_1:
# 1245 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Wait, it's stuck to the car with bolts!\p"
	.string "If I could just take one…$"

SpindaIsland_Home_EventScript_SurveyedWheel_Text_2:
# 1253 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Here, let me just…$"

SpindaIsland_Home_EventScript_SurveyedWheel_Text_3:
# 1262 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Whatcha doing, Archie?$"

SpindaIsland_Home_EventScript_SurveyedWheel_Text_4:
# 1270 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Ah, uh, nothing!$"

SpindaIsland_Home_EventScript_SurveyedWheel_Text_5:
# 1281 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "(Darn, can't do this right under her\n"
	.string "nose.)$"

SpindaIsland_Home_EventScript_SurveyedWheel_Text_6:
# 1288 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I'd need some pliers to get it out.$"

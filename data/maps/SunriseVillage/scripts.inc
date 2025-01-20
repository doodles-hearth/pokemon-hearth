SunriseVillage_MapScripts::
# 5 "data/maps/SunriseVillage/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, SunriseVillage_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

SunriseVillage_MapScripts_MAP_SCRIPT_ON_LOAD:
# 7 "data/maps/SunriseVillage/scripts.pory"
	setflag FLAG_TEMP_1
# 8 "data/maps/SunriseVillage/scripts.pory"
	setflag FLAG_TEMP_2
# 9 "data/maps/SunriseVillage/scripts.pory"
	setflag FLAG_TEMP_3
# 10 "data/maps/SunriseVillage/scripts.pory"
	setflag FLAG_TEMP_4
# 12 "data/maps/SunriseVillage/scripts.pory"
	gettime
# 13 "data/maps/SunriseVillage/scripts.pory"
	compare VAR_0x8000, 5
	goto_if_ge SunriseVillage_MapScripts_MAP_SCRIPT_ON_LOAD_2
	return

SunriseVillage_MapScripts_MAP_SCRIPT_ON_LOAD_1:
# 14 "data/maps/SunriseVillage/scripts.pory"
	random 4
# 15 "data/maps/SunriseVillage/scripts.pory"
	switch VAR_RESULT
# 16 "data/maps/SunriseVillage/scripts.pory"
	case 0, SunriseVillage_MapScripts_MAP_SCRIPT_ON_LOAD_6
# 18 "data/maps/SunriseVillage/scripts.pory"
	case 1, SunriseVillage_MapScripts_MAP_SCRIPT_ON_LOAD_7
# 20 "data/maps/SunriseVillage/scripts.pory"
	case 2, SunriseVillage_MapScripts_MAP_SCRIPT_ON_LOAD_8
# 22 "data/maps/SunriseVillage/scripts.pory"
	case 3, SunriseVillage_MapScripts_MAP_SCRIPT_ON_LOAD_9
	return

SunriseVillage_MapScripts_MAP_SCRIPT_ON_LOAD_2:
# 13 "data/maps/SunriseVillage/scripts.pory"
	compare VAR_0x8000, 17
	goto_if_le SunriseVillage_MapScripts_MAP_SCRIPT_ON_LOAD_1
	return

SunriseVillage_MapScripts_MAP_SCRIPT_ON_LOAD_6:
# 17 "data/maps/SunriseVillage/scripts.pory"
	clearflag FLAG_TEMP_1
	return

SunriseVillage_MapScripts_MAP_SCRIPT_ON_LOAD_7:
# 19 "data/maps/SunriseVillage/scripts.pory"
	clearflag FLAG_TEMP_2
	return

SunriseVillage_MapScripts_MAP_SCRIPT_ON_LOAD_8:
# 21 "data/maps/SunriseVillage/scripts.pory"
	clearflag FLAG_TEMP_4
	return

SunriseVillage_MapScripts_MAP_SCRIPT_ON_LOAD_9:
# 23 "data/maps/SunriseVillage/scripts.pory"
	clearflag FLAG_TEMP_1
# 24 "data/maps/SunriseVillage/scripts.pory"
	clearflag FLAG_TEMP_3
	return


SunriseVillage_Event_FatGuy::
# 32 "data/maps/SunriseVillage/scripts.pory"
	lock
# 33 "data/maps/SunriseVillage/scripts.pory"
	faceplayer
# 35 "data/maps/SunriseVillage/scripts.pory"
	speakername SunriseVillage_Event_FatGuy_Text_0
# 36 "data/maps/SunriseVillage/scripts.pory"
	compare VAR_SUNRISE_VILLAGE_INTRO_STATE, 4
	goto_if_ge SunriseVillage_Event_FatGuy_2
# 44 "data/maps/SunriseVillage/scripts.pory"
	msgbox SunriseVillage_Event_FatGuy_Text_2
# 49 "data/maps/SunriseVillage/scripts.pory"
	closemessage
SunriseVillage_Event_FatGuy_1:
# 51 "data/maps/SunriseVillage/scripts.pory"
	release
	end

SunriseVillage_Event_FatGuy_2:
# 37 "data/maps/SunriseVillage/scripts.pory"
	msgbox SunriseVillage_Event_FatGuy_Text_1
# 40 "data/maps/SunriseVillage/scripts.pory"
	closemessage
# 41 "data/maps/SunriseVillage/scripts.pory"
	applymovement 3, Common_Movement_FaceOriginalDirection
	goto SunriseVillage_Event_FatGuy_1


SunriseVillage_Event_GuardForest::
# 57 "data/maps/SunriseVillage/scripts.pory"
	lock
# 58 "data/maps/SunriseVillage/scripts.pory"
	applymovement 6, Common_Movement_WalkInPlaceFasterLeft
# 59 "data/maps/SunriseVillage/scripts.pory"
	goto_if_set FLAG_RECEIVED_STARTER, SunriseVillage_Event_GuardForest_2
# 89 "data/maps/SunriseVillage/scripts.pory"
	speakername SunriseVillage_Event_FatGuy_Text_0
# 90 "data/maps/SunriseVillage/scripts.pory"
	msgbox SunriseVillage_Event_GuardForest_Text_3
# 93 "data/maps/SunriseVillage/scripts.pory"
	closemessage
# 94 "data/maps/SunriseVillage/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
# 95 "data/maps/SunriseVillage/scripts.pory"
	speakername SunriseVillage_Event_FatGuy_Text_0
# 96 "data/maps/SunriseVillage/scripts.pory"
	msgbox SunriseVillage_Event_GuardForest_Text_4
# 102 "data/maps/SunriseVillage/scripts.pory"
	closemessage
# 103 "data/maps/SunriseVillage/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SunriseVillage_Event_GuardForest_Movement_0
# 104 "data/maps/SunriseVillage/scripts.pory"
	waitmovement 0
SunriseVillage_Event_GuardForest_1:
# 106 "data/maps/SunriseVillage/scripts.pory"
	release
	end

SunriseVillage_Event_GuardForest_2:
# 60 "data/maps/SunriseVillage/scripts.pory"
	speakername SunriseVillage_Event_FatGuy_Text_0
# 61 "data/maps/SunriseVillage/scripts.pory"
	compare VAR_SUNRISE_VILLAGE_INTRO_STATE, 8
	goto_if_ge SunriseVillage_Event_GuardForest_5
# 68 "data/maps/SunriseVillage/scripts.pory"
	compare VAR_SUNRISE_VILLAGE_INTRO_STATE, 7
	goto_if_eq SunriseVillage_Event_GuardForest_6
# 79 "data/maps/SunriseVillage/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
# 80 "data/maps/SunriseVillage/scripts.pory"
	msgbox SunriseVillage_Event_GuardForest_Text_2
# 83 "data/maps/SunriseVillage/scripts.pory"
	closemessage
# 84 "data/maps/SunriseVillage/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SunriseVillage_Event_GuardForest_Movement_0
# 85 "data/maps/SunriseVillage/scripts.pory"
	waitmovement 0
	goto SunriseVillage_Event_GuardForest_1

SunriseVillage_Event_GuardForest_5:
# 62 "data/maps/SunriseVillage/scripts.pory"
	msgbox SunriseVillage_Event_GuardForest_Text_0
# 67 "data/maps/SunriseVillage/scripts.pory"
	closemessage
	goto SunriseVillage_Event_GuardForest_1

SunriseVillage_Event_GuardForest_6:
# 69 "data/maps/SunriseVillage/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
# 70 "data/maps/SunriseVillage/scripts.pory"
	msgbox SunriseVillage_Event_GuardForest_Text_1
# 75 "data/maps/SunriseVillage/scripts.pory"
	closemessage
# 76 "data/maps/SunriseVillage/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SunriseVillage_Event_GuardForest_Movement_0
# 77 "data/maps/SunriseVillage/scripts.pory"
	waitmovement 0
	goto SunriseVillage_Event_GuardForest_1


SunriseVillage_Event_GuardForest_Interact::
# 111 "data/maps/SunriseVillage/scripts.pory"
	lock
# 112 "data/maps/SunriseVillage/scripts.pory"
	faceplayer
# 113 "data/maps/SunriseVillage/scripts.pory"
	speakername SunriseVillage_Event_FatGuy_Text_0
# 114 "data/maps/SunriseVillage/scripts.pory"
	goto_if_set FLAG_RECEIVED_STARTER, SunriseVillage_Event_GuardForest_Interact_2
# 137 "data/maps/SunriseVillage/scripts.pory"
	msgbox SunriseVillage_Event_GuardForest_Interact_Text_0
# 141 "data/maps/SunriseVillage/scripts.pory"
	closemessage
SunriseVillage_Event_GuardForest_Interact_1:
# 143 "data/maps/SunriseVillage/scripts.pory"
	release
	end

SunriseVillage_Event_GuardForest_Interact_2:
# 115 "data/maps/SunriseVillage/scripts.pory"
	compare VAR_SUNRISE_VILLAGE_INTRO_STATE, 8
	goto_if_ge SunriseVillage_Event_GuardForest_Interact_5
# 122 "data/maps/SunriseVillage/scripts.pory"
	compare VAR_SUNRISE_VILLAGE_INTRO_STATE, 7
	goto_if_eq SunriseVillage_Event_GuardForest_Interact_6
# 130 "data/maps/SunriseVillage/scripts.pory"
	msgbox SunriseVillage_Event_GuardForest_Text_2
# 133 "data/maps/SunriseVillage/scripts.pory"
	closemessage
	goto SunriseVillage_Event_GuardForest_Interact_1

SunriseVillage_Event_GuardForest_Interact_5:
# 116 "data/maps/SunriseVillage/scripts.pory"
	msgbox SunriseVillage_Event_GuardForest_Text_0
# 121 "data/maps/SunriseVillage/scripts.pory"
	closemessage
	goto SunriseVillage_Event_GuardForest_Interact_1

SunriseVillage_Event_GuardForest_Interact_6:
# 123 "data/maps/SunriseVillage/scripts.pory"
	msgbox SunriseVillage_Event_GuardForest_Text_1
# 128 "data/maps/SunriseVillage/scripts.pory"
	closemessage
	goto SunriseVillage_Event_GuardForest_Interact_1


SunriseVillage_Event_LittleGirl::
# 149 "data/maps/SunriseVillage/scripts.pory"
	speakername SunriseVillage_Event_LittleGirl_Text_0
# 150 "data/maps/SunriseVillage/scripts.pory"
	msgbox SunriseVillage_Event_LittleGirl_Text_1, MSGBOX_NPC
	return


SunriseVillage_Event_Boy::
# 158 "data/maps/SunriseVillage/scripts.pory"
	lockall
# 159 "data/maps/SunriseVillage/scripts.pory"
	faceplayer
# 160 "data/maps/SunriseVillage/scripts.pory"
	speakername SunriseVillage_Event_Boy_Text_0
# 161 "data/maps/SunriseVillage/scripts.pory"
	compare VAR_SUNRISE_VILLAGE_INTRO_STATE, 4
	goto_if_ge SunriseVillage_Event_Boy_2
# 168 "data/maps/SunriseVillage/scripts.pory"
	msgbox SunriseVillage_Event_Boy_Text_2
# 172 "data/maps/SunriseVillage/scripts.pory"
	closemessage
SunriseVillage_Event_Boy_1:
# 174 "data/maps/SunriseVillage/scripts.pory"
	releaseall
	end

SunriseVillage_Event_Boy_2:
# 162 "data/maps/SunriseVillage/scripts.pory"
	msgbox SunriseVillage_Event_Boy_Text_1
# 165 "data/maps/SunriseVillage/scripts.pory"
	closemessage
	goto SunriseVillage_Event_Boy_1


SunriseVillage_Event_Woman::
# 180 "data/maps/SunriseVillage/scripts.pory"
	lockall
# 181 "data/maps/SunriseVillage/scripts.pory"
	speakername SunriseVillage_Event_FatGuy_Text_0
# 182 "data/maps/SunriseVillage/scripts.pory"
	msgbox SunriseVillage_Event_Woman_Text_0
# 185 "data/maps/SunriseVillage/scripts.pory"
	releaseall
	end


SunriseVillage_Event_Farmer::
# 191 "data/maps/SunriseVillage/scripts.pory"
	lockall
# 192 "data/maps/SunriseVillage/scripts.pory"
	faceplayer
# 193 "data/maps/SunriseVillage/scripts.pory"
	speakername SunriseVillage_Event_FatGuy_Text_0
# 194 "data/maps/SunriseVillage/scripts.pory"
	msgbox SunriseVillage_Event_Farmer_Text_0
# 197 "data/maps/SunriseVillage/scripts.pory"
	releaseall
	end


SunriseVillage_Event_OldMan::
# 203 "data/maps/SunriseVillage/scripts.pory"
	lockall
# 204 "data/maps/SunriseVillage/scripts.pory"
	faceplayer
# 205 "data/maps/SunriseVillage/scripts.pory"
	speakername SunriseVillage_Event_FatGuy_Text_0
# 206 "data/maps/SunriseVillage/scripts.pory"
	msgbox SunriseVillage_Event_OldMan_Text_0
# 209 "data/maps/SunriseVillage/scripts.pory"
	releaseall
	end


SunriseVillage_Event_OldWoman::
# 215 "data/maps/SunriseVillage/scripts.pory"
	speakername SunriseVillage_Event_FatGuy_Text_0
# 216 "data/maps/SunriseVillage/scripts.pory"
	msgbox SunriseVillage_Event_OldWoman_Text_0, MSGBOX_NPC
	return


SunriseVillage_Event_Happiny::
# 223 "data/maps/SunriseVillage/scripts.pory"
	lock
# 224 "data/maps/SunriseVillage/scripts.pory"
	faceplayer
# 225 "data/maps/SunriseVillage/scripts.pory"
	ismonseen SPECIES_HAPPINY
# 226 "data/maps/SunriseVillage/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne SunriseVillage_Event_Happiny_2
# 229 "data/maps/SunriseVillage/scripts.pory"
	speakername SunriseVillage_Event_Happiny_Text_1
SunriseVillage_Event_Happiny_1:
# 231 "data/maps/SunriseVillage/scripts.pory"
	msgbox SunriseVillage_Event_Happiny_Text_2
# 234 "data/maps/SunriseVillage/scripts.pory"
	playmoncry SPECIES_HAPPINY, CRY_MODE_NORMAL
# 235 "data/maps/SunriseVillage/scripts.pory"
	waitmoncry
# 236 "data/maps/SunriseVillage/scripts.pory"
	release
	end

SunriseVillage_Event_Happiny_2:
# 227 "data/maps/SunriseVillage/scripts.pory"
	speakername SunriseVillage_Event_Happiny_Text_0
	goto SunriseVillage_Event_Happiny_1


SunriseVillage_Event_Munchlax::
# 242 "data/maps/SunriseVillage/scripts.pory"
	lock
# 243 "data/maps/SunriseVillage/scripts.pory"
	faceplayer
# 244 "data/maps/SunriseVillage/scripts.pory"
	waitse
# 245 "data/maps/SunriseVillage/scripts.pory"
	playmoncry SPECIES_MUNCHLAX, CRY_MODE_NORMAL
# 246 "data/maps/SunriseVillage/scripts.pory"
	ismonseen SPECIES_MUNCHLAX
# 247 "data/maps/SunriseVillage/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne SunriseVillage_Event_Munchlax_2
# 250 "data/maps/SunriseVillage/scripts.pory"
	speakername SunriseVillage_Event_Munchlax_Text_1
SunriseVillage_Event_Munchlax_1:
# 252 "data/maps/SunriseVillage/scripts.pory"
	msgbox SunriseVillage_Event_Munchlax_Text_2
# 255 "data/maps/SunriseVillage/scripts.pory"
	waitmoncry
# 256 "data/maps/SunriseVillage/scripts.pory"
	release
	end

SunriseVillage_Event_Munchlax_2:
# 248 "data/maps/SunriseVillage/scripts.pory"
	speakername SunriseVillage_Event_Munchlax_Text_0
	goto SunriseVillage_Event_Munchlax_1


SunriseVillage_Event_Kirlia::
# 262 "data/maps/SunriseVillage/scripts.pory"
	lock
# 263 "data/maps/SunriseVillage/scripts.pory"
	faceplayer
# 264 "data/maps/SunriseVillage/scripts.pory"
	ismonseen SPECIES_MUNCHLAX
# 265 "data/maps/SunriseVillage/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne SunriseVillage_Event_Kirlia_2
# 268 "data/maps/SunriseVillage/scripts.pory"
	speakername SunriseVillage_Event_Kirlia_Text_1
SunriseVillage_Event_Kirlia_1:
# 270 "data/maps/SunriseVillage/scripts.pory"
	msgbox SunriseVillage_Event_Kirlia_Text_2
# 273 "data/maps/SunriseVillage/scripts.pory"
	release
	end

SunriseVillage_Event_Kirlia_2:
# 266 "data/maps/SunriseVillage/scripts.pory"
	speakername SunriseVillage_Event_Kirlia_Text_0
	goto SunriseVillage_Event_Kirlia_1


SunriseVillage_Event_TestGyarados::
# 279 "data/maps/SunriseVillage/scripts.pory"
	lock
# 280 "data/maps/SunriseVillage/scripts.pory"
	givemon SPECIES_SNIVY, 100
# 281 "data/maps/SunriseVillage/scripts.pory"
	setwildbattle SPECIES_KOTORA, 5
# 282 "data/maps/SunriseVillage/scripts.pory"
	dowildbattle
# 283 "data/maps/SunriseVillage/scripts.pory"
	release
	end


SunriseVillage_Event_TownSign::
# 288 "data/maps/SunriseVillage/scripts.pory"
	msgbox SunriseVillage_Event_TownSign_Text_0, MSGBOX_SIGN
	return


SunriseVillage_Event_PlayersHouseSign::
# 292 "data/maps/SunriseVillage/scripts.pory"
	msgbox SunriseVillage_Event_PlayersHouseSign_Text_0, MSGBOX_SIGN
	return


SunriseVillage_Event_RivalsHouseSign::
# 296 "data/maps/SunriseVillage/scripts.pory"
	msgbox SunriseVillage_Event_RivalsHouseSign_Text_0, MSGBOX_SIGN
	return


SunriseVillage_Event_EldersHouseSign::
# 300 "data/maps/SunriseVillage/scripts.pory"
	msgbox SunriseVillage_Event_EldersHouseSign_Text_0, MSGBOX_SIGN
	return


# 76 "data/maps/SunriseVillage/scripts.pory"
SunriseVillage_Event_GuardForest_Movement_0:
# 76 "data/maps/SunriseVillage/scripts.pory"
	walk_down
	step_end

SunriseVillage_Event_FatGuy_Text_0:
# 35 "data/maps/SunriseVillage/scripts.pory"
	.string "Neighbour$"

SunriseVillage_Event_FatGuy_Text_1:
# 38 "data/maps/SunriseVillage/scripts.pory"
	.string "My new Pokémon is so cute, I don't\n"
	.string "feel like leaving it in its Pokéball!$"

SunriseVillage_Event_FatGuy_Text_2:
# 45 "data/maps/SunriseVillage/scripts.pory"
	.string "Someone managed to fit entire\n"
	.string "Pokémon inside these tiny balls.\p"
	.string "The power of science is staggering!$"

SunriseVillage_Event_GuardForest_Text_0:
# 63 "data/maps/SunriseVillage/scripts.pory"
	.string "Oh, I see you received a Pokémon!\p"
	.string "You'll probably be able to manage the\n"
	.string "woods on your own, then.\p"
	.string "Be careful!$"

SunriseVillage_Event_GuardForest_Text_1:
# 71 "data/maps/SunriseVillage/scripts.pory"
	.string "Hey, kid, heard you were going off on\n"
	.string "an adventure!\p"
	.string "Did you say bye to your sister?\p"
	.string "No? Thought so. Go see her before you\n"
	.string "run off, you ungrateful sibling!$"

SunriseVillage_Event_GuardForest_Text_2:
# 81 "data/maps/SunriseVillage/scripts.pory"
	.string "Hey, kid, a friend of yours was looking\n"
	.string "for you.$"

SunriseVillage_Event_GuardForest_Text_3:
# 91 "data/maps/SunriseVillage/scripts.pory"
	.string "Stop right there, kid!$"

SunriseVillage_Event_GuardForest_Text_4:
# 97 "data/maps/SunriseVillage/scripts.pory"
	.string "Wild POKéMON have been lashing out\n"
	.string "recently.\p"
	.string "I know you're used to walking around\n"
	.string "on your own, but the woods have\l"
	.string "become a dangerous place lately!\p"
	.string "I wouldn't go alone if I were you.\p"
	.string "Or, you know, if I were me.$"

SunriseVillage_Event_GuardForest_Interact_Text_0:
# 138 "data/maps/SunriseVillage/scripts.pory"
	.string "Wild POKéMON have been lashing out\n"
	.string "recently.\p"
	.string "Even the Ginko woods have become a\n"
	.string "dangerous place lately!$"

SunriseVillage_Event_LittleGirl_Text_0:
# 149 "data/maps/SunriseVillage/scripts.pory"
	.string "Little girl$"

SunriseVillage_Event_LittleGirl_Text_1:
# 151 "data/maps/SunriseVillage/scripts.pory"
	.string "I can't wait I can't wait I can't\n"
	.string "wait!!!\p"
	.string "AHHHHH I CAN'T WAIT!!!!$"

SunriseVillage_Event_Boy_Text_0:
# 160 "data/maps/SunriseVillage/scripts.pory"
	.string "Kid$"

SunriseVillage_Event_Boy_Text_1:
# 163 "data/maps/SunriseVillage/scripts.pory"
	.string "My Happiny is the strongest of all!\n"
	.string "See how fierce it looks?$"

SunriseVillage_Event_Boy_Text_2:
# 169 "data/maps/SunriseVillage/scripts.pory"
	.string "Hey {PLAYER}{KUN}!\p"
	.string "So, d'you think we'll get to choose the\n"
	.string "one we want?$"

SunriseVillage_Event_Woman_Text_0:
# 183 "data/maps/SunriseVillage/scripts.pory"
	.string "I can see the Poké Balls from here…\n"
	.string "I've never seen so many in my life!$"

SunriseVillage_Event_Farmer_Text_0:
# 195 "data/maps/SunriseVillage/scripts.pory"
	.string "I've been waiting for hours!$"

SunriseVillage_Event_OldMan_Text_0:
# 207 "data/maps/SunriseVillage/scripts.pory"
	.string "The distribution is about to start.$"

SunriseVillage_Event_OldWoman_Text_0:
# 217 "data/maps/SunriseVillage/scripts.pory"
	.string "I'm tired of waiting!$"

SunriseVillage_Event_Happiny_Text_0:
# 227 "data/maps/SunriseVillage/scripts.pory"
	.string "Happiny$"

SunriseVillage_Event_Happiny_Text_1:
# 229 "data/maps/SunriseVillage/scripts.pory"
	.string "Noisy egg$"

SunriseVillage_Event_Happiny_Text_2:
# 232 "data/maps/SunriseVillage/scripts.pory"
	.string "Happi!$"

SunriseVillage_Event_Munchlax_Text_0:
# 248 "data/maps/SunriseVillage/scripts.pory"
	.string "Munchlax$"

SunriseVillage_Event_Munchlax_Text_1:
# 250 "data/maps/SunriseVillage/scripts.pory"
	.string "Big nom$"

SunriseVillage_Event_Munchlax_Text_2:
# 253 "data/maps/SunriseVillage/scripts.pory"
	.string "Munch munch munch…$"

SunriseVillage_Event_Kirlia_Text_0:
# 266 "data/maps/SunriseVillage/scripts.pory"
	.string "Kirlia$"

SunriseVillage_Event_Kirlia_Text_1:
# 268 "data/maps/SunriseVillage/scripts.pory"
	.string "Posh dancer$"

SunriseVillage_Event_Kirlia_Text_2:
# 271 "data/maps/SunriseVillage/scripts.pory"
	.string "…$"

SunriseVillage_Event_TownSign_Text_0:
# 288 "data/maps/SunriseVillage/scripts.pory"
	.string "Sunrise Village\n"
	.string "“A village bathing in soft light.”$"

SunriseVillage_Event_PlayersHouseSign_Text_0:
# 292 "data/maps/SunriseVillage/scripts.pory"
	.string "{PLAYER}'s house$"

SunriseVillage_Event_RivalsHouseSign_Text_0:
# 296 "data/maps/SunriseVillage/scripts.pory"
	.string "Natsuki's house$"

SunriseVillage_Event_EldersHouseSign_Text_0:
# 300 "data/maps/SunriseVillage/scripts.pory"
	.string "Elder Kaba's house$"

SunriseVillage_MapScripts::
# 4 "data/maps/SunriseVillage/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, SunriseVillage_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

SunriseVillage_MapScripts_MAP_SCRIPT_ON_LOAD:
# 5 "data/maps/SunriseVillage/scripts.pory"
	compare VAR_SUNRISE_VILLAGE_INTRO_STATE, 6
	goto_if_lt SunriseVillage_MapScripts_MAP_SCRIPT_ON_LOAD_1
# 9 "data/maps/SunriseVillage/scripts.pory"
	clearflag FLAG_HIDE_SUNRISE_VILLAGE_STANDARD_NPC_POSITIONS
	return

SunriseVillage_MapScripts_MAP_SCRIPT_ON_LOAD_1:
# 6 "data/maps/SunriseVillage/scripts.pory"
	setflag FLAG_HIDE_SUNRISE_VILLAGE_STANDARD_NPC_POSITIONS
	return


SunriseVillage_Event_FatGuy::
# 16 "data/maps/SunriseVillage/scripts.pory"
	lock
# 17 "data/maps/SunriseVillage/scripts.pory"
	faceplayer
# 19 "data/maps/SunriseVillage/scripts.pory"
	goto_if_set FLAG_RECEIVED_STARTER, SunriseVillage_Event_FatGuy_2
# 26 "data/maps/SunriseVillage/scripts.pory"
	msgbox SunriseVillage_Event_FatGuy_Text_1
SunriseVillage_Event_FatGuy_1:
# 32 "data/maps/SunriseVillage/scripts.pory"
	release
	end

SunriseVillage_Event_FatGuy_2:
# 20 "data/maps/SunriseVillage/scripts.pory"
	msgbox SunriseVillage_Event_FatGuy_Text_0
# 23 "data/maps/SunriseVillage/scripts.pory"
	applymovement 3, Common_Movement_FaceOriginalDirection
	goto SunriseVillage_Event_FatGuy_1


SunriseVillage_Event_GuardForest::
# 38 "data/maps/SunriseVillage/scripts.pory"
	lock
# 39 "data/maps/SunriseVillage/scripts.pory"
	faceplayer
# 40 "data/maps/SunriseVillage/scripts.pory"
	goto_if_set FLAG_RECEIVED_STARTER, SunriseVillage_Event_GuardForest_2
# 48 "data/maps/SunriseVillage/scripts.pory"
	msgbox SunriseVillage_Event_GuardForest_Text_1
# 51 "data/maps/SunriseVillage/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 52 "data/maps/SunriseVillage/scripts.pory"
	waitmovement 0
# 53 "data/maps/SunriseVillage/scripts.pory"
	msgbox SunriseVillage_Event_GuardForest_Text_2
# 59 "data/maps/SunriseVillage/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
# 60 "data/maps/SunriseVillage/scripts.pory"
	waitmovement 0
SunriseVillage_Event_GuardForest_1:
# 62 "data/maps/SunriseVillage/scripts.pory"
	release
	end

SunriseVillage_Event_GuardForest_2:
# 41 "data/maps/SunriseVillage/scripts.pory"
	msgbox SunriseVillage_Event_GuardForest_Text_0
	goto SunriseVillage_Event_GuardForest_1


SunriseVillage_Event_LittleGirl::
# 68 "data/maps/SunriseVillage/scripts.pory"
	lockall
# 69 "data/maps/SunriseVillage/scripts.pory"
	faceplayer
# 70 "data/maps/SunriseVillage/scripts.pory"
	goto_if_set FLAG_RECEIVED_STARTER, SunriseVillage_Event_LittleGirl_2
# 77 "data/maps/SunriseVillage/scripts.pory"
	msgbox SunriseVillage_Event_LittleGirl_Text_1
SunriseVillage_Event_LittleGirl_1:
# 82 "data/maps/SunriseVillage/scripts.pory"
	releaseall
	end

SunriseVillage_Event_LittleGirl_2:
# 71 "data/maps/SunriseVillage/scripts.pory"
	msgbox SunriseVillage_Event_LittleGirl_Text_0
	goto SunriseVillage_Event_LittleGirl_1


SunriseVillage_Event_Boy::
# 88 "data/maps/SunriseVillage/scripts.pory"
	lockall
# 89 "data/maps/SunriseVillage/scripts.pory"
	faceplayer
# 90 "data/maps/SunriseVillage/scripts.pory"
	goto_if_set FLAG_RECEIVED_STARTER, SunriseVillage_Event_Boy_2
# 97 "data/maps/SunriseVillage/scripts.pory"
	msgbox SunriseVillage_Event_Boy_Text_1
SunriseVillage_Event_Boy_1:
# 102 "data/maps/SunriseVillage/scripts.pory"
	releaseall
	end

SunriseVillage_Event_Boy_2:
# 91 "data/maps/SunriseVillage/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_AZURILL
# 92 "data/maps/SunriseVillage/scripts.pory"
	msgbox SunriseVillage_Event_Boy_Text_0
	goto SunriseVillage_Event_Boy_1


SunriseVillage_Event_OldWoman::
# 108 "data/maps/SunriseVillage/scripts.pory"
	lockall
# 109 "data/maps/SunriseVillage/scripts.pory"
	faceplayer
# 110 "data/maps/SunriseVillage/scripts.pory"
	goto_if_set FLAG_RECEIVED_STARTER, SunriseVillage_Event_OldWoman_2
# 118 "data/maps/SunriseVillage/scripts.pory"
	msgbox SunriseVillage_Event_OldWoman_Text_1
SunriseVillage_Event_OldWoman_1:
# 122 "data/maps/SunriseVillage/scripts.pory"
	releaseall
	end

SunriseVillage_Event_OldWoman_2:
# 111 "data/maps/SunriseVillage/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_KIRLIA
# 112 "data/maps/SunriseVillage/scripts.pory"
	msgbox SunriseVillage_Event_OldWoman_Text_0
	goto SunriseVillage_Event_OldWoman_1


SunriseVillage_Event_Azurill::
# 128 "data/maps/SunriseVillage/scripts.pory"
	lock
# 129 "data/maps/SunriseVillage/scripts.pory"
	faceplayer
# 130 "data/maps/SunriseVillage/scripts.pory"
	waitse
# 131 "data/maps/SunriseVillage/scripts.pory"
	playmoncry SPECIES_AZURILL, CRY_MODE_NORMAL
# 132 "data/maps/SunriseVillage/scripts.pory"
	msgbox SunriseVillage_Event_Azurill_Text_0
# 135 "data/maps/SunriseVillage/scripts.pory"
	waitmoncry
# 136 "data/maps/SunriseVillage/scripts.pory"
	release
	end


SunriseVillage_Event_Kecleon::
# 142 "data/maps/SunriseVillage/scripts.pory"
	lock
# 143 "data/maps/SunriseVillage/scripts.pory"
	faceplayer
# 144 "data/maps/SunriseVillage/scripts.pory"
	waitse
# 145 "data/maps/SunriseVillage/scripts.pory"
	playmoncry SPECIES_KECLEON, CRY_MODE_NORMAL
# 146 "data/maps/SunriseVillage/scripts.pory"
	msgbox SunriseVillage_Event_Kecleon_Text_0
# 149 "data/maps/SunriseVillage/scripts.pory"
	waitmoncry
# 150 "data/maps/SunriseVillage/scripts.pory"
	release
	end


SunriseVillage_Event_Kirlia::
# 156 "data/maps/SunriseVillage/scripts.pory"
	lock
# 157 "data/maps/SunriseVillage/scripts.pory"
	faceplayer
# 158 "data/maps/SunriseVillage/scripts.pory"
	msgbox SunriseVillage_Event_Kirlia_Text_0
# 161 "data/maps/SunriseVillage/scripts.pory"
	release
	end


SunriseVillage_Event_TestGyarados::
# 167 "data/maps/SunriseVillage/scripts.pory"
	lock
# 168 "data/maps/SunriseVillage/scripts.pory"
	givemon SPECIES_SPHEAL, 100
# 169 "data/maps/SunriseVillage/scripts.pory"
	setwildbattle SPECIES_KOTORA, 5
# 170 "data/maps/SunriseVillage/scripts.pory"
	dowildbattle
# 171 "data/maps/SunriseVillage/scripts.pory"
	release
	end


SunriseVillage_Event_TownSign::
# 176 "data/maps/SunriseVillage/scripts.pory"
	msgbox SunriseVillage_Event_TownSign_Text_0, MSGBOX_SIGN
	return


SunriseVillage_Event_PlayersHouseSign::
# 180 "data/maps/SunriseVillage/scripts.pory"
	msgbox SunriseVillage_Event_PlayersHouseSign_Text_0, MSGBOX_SIGN
	return


SunriseVillage_Event_RivalsHouseSign::
# 184 "data/maps/SunriseVillage/scripts.pory"
	msgbox SunriseVillage_Event_RivalsHouseSign_Text_0, MSGBOX_SIGN
	return


SunriseVillage_Event_EldersHouseSign::
# 188 "data/maps/SunriseVillage/scripts.pory"
	msgbox SunriseVillage_Event_EldersHouseSign_Text_0, MSGBOX_SIGN
	return


SunriseVillage_Event_FatGuy_Text_0:
# 21 "data/maps/SunriseVillage/scripts.pory"
	.string "My new Pokémon is so cute, I don't feel\n"
	.string "like leaving it in its Pokéball!$"

SunriseVillage_Event_FatGuy_Text_1:
# 27 "data/maps/SunriseVillage/scripts.pory"
	.string "Someone managed to fit entire POKéMON\n"
	.string "inside these tiny balls.\p"
	.string "The power of science is staggering!$"

SunriseVillage_Event_GuardForest_Text_0:
# 42 "data/maps/SunriseVillage/scripts.pory"
	.string "Oh, I see you received a POKéMON!\p"
	.string "You'll probably be able to manage the\n"
	.string "woods on your own, then.\p"
	.string "Be careful!$"

SunriseVillage_Event_GuardForest_Text_1:
# 49 "data/maps/SunriseVillage/scripts.pory"
	.string "Stop right there!$"

SunriseVillage_Event_GuardForest_Text_2:
# 54 "data/maps/SunriseVillage/scripts.pory"
	.string "Wild POKéMON have been lashing out\n"
	.string "recently.\p"
	.string "I know you're used to walking around on\n"
	.string "your own, but the woods have become a\l"
	.string "dangerous place lately!\p"
	.string "I wouldn't go alone if I were you.\p"
	.string "Or, you know, if I were me.$"

SunriseVillage_Event_LittleGirl_Text_0:
# 72 "data/maps/SunriseVillage/scripts.pory"
	.string "I'm so happy I'm so happy I'm so happy!!!\p"
	.string "LOOK AT IT, IT'S ADORABLE!!!!$"

SunriseVillage_Event_LittleGirl_Text_1:
# 78 "data/maps/SunriseVillage/scripts.pory"
	.string "I can't wait I can't wait I can't wait!!!\p"
	.string "AHHHHH I CAN'T WAIT!!!!$"

SunriseVillage_Event_Boy_Text_0:
# 93 "data/maps/SunriseVillage/scripts.pory"
	.string "My {STR_VAR_1} is the strongest of\n"
	.string "all! See how fierce it looks?$"

SunriseVillage_Event_Boy_Text_1:
# 98 "data/maps/SunriseVillage/scripts.pory"
	.string "Hey {PLAYER}{KUN}!\p"
	.string "So, d'you think we'll get to choose the\n"
	.string "one we want?$"

SunriseVillage_Event_OldWoman_Text_0:
# 113 "data/maps/SunriseVillage/scripts.pory"
	.string "{STR_VAR_1} here is the silent type.\p"
	.string "I'm okay with that.$"

SunriseVillage_Event_OldWoman_Text_1:
# 119 "data/maps/SunriseVillage/scripts.pory"
	.string "I'm tired of waiting!\p"
	.string "$"

SunriseVillage_Event_Azurill_Text_0:
# 133 "data/maps/SunriseVillage/scripts.pory"
	.string "Azuazu!$"

SunriseVillage_Event_Kecleon_Text_0:
# 147 "data/maps/SunriseVillage/scripts.pory"
	.string "Kleeeeh!$"

SunriseVillage_Event_Kirlia_Text_0:
# 159 "data/maps/SunriseVillage/scripts.pory"
	.string "…$"

SunriseVillage_Event_TownSign_Text_0:
# 176 "data/maps/SunriseVillage/scripts.pory"
	.string "Sunrise Village\n"
	.string "“A village bathing in sunshine.”$"

SunriseVillage_Event_PlayersHouseSign_Text_0:
# 180 "data/maps/SunriseVillage/scripts.pory"
	.string "{PLAYER}'s house$"

SunriseVillage_Event_RivalsHouseSign_Text_0:
# 184 "data/maps/SunriseVillage/scripts.pory"
	.string "{RIVAL}'s house$"

SunriseVillage_Event_EldersHouseSign_Text_0:
# 188 "data/maps/SunriseVillage/scripts.pory"
	.string "Elder Kaba's house$"

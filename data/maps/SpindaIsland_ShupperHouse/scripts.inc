SpindaIsland_ShupperHouse_MapScripts::
	.byte 0


SpindaIsland_ShupperHouse_Shuppet::
# 6 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	lock
# 7 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	playmoncry SPECIES_SHUPPET, CRY_MODE_NORMAL
# 8 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	msgbox SpindaIsland_ShupperHouse_Shuppet_Text_0
# 9 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	waitmoncry
# 10 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	closemessage
# 11 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	release
	return


SpindaIsland_ShupperHouse_ChaseShuppets::
# 15 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	lock
# 17 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	playse SE_SWITCH
# 18 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	waitse
# 19 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	playse SE_M_LEER
# 20 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	fadescreenspeed FADE_TO_WHITE, 0
# 21 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	fadescreenspeed FADE_FROM_WHITE, 0
# 22 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	waitse
# 24 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	applymovement 1, Common_Movement_ExclamationMark
# 25 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	playmoncry SPECIES_SHUPPET, CRY_MODE_NORMAL
# 26 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	waitmoncry
# 27 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	applymovement 2, Common_Movement_ExclamationMark
# 28 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	playmoncry SPECIES_SHUPPET, CRY_MODE_NORMAL
# 29 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	waitmoncry
# 30 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	waitmovement 0
# 32 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	removeobject 1
# 33 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	delay 20
# 34 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	removeobject 2
# 35 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	delay 20
# 37 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	setflag FLAG_HIDE_SHUPPETS
# 39 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	release
	return


SpindaIsland_ShupperHouse_Shuppet_Text_0:
# 8 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	.string "Kekhekhehehe…$"

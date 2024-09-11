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
# 12 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	goto_if_set FLAG_SHUPPET_QUEST_STARTED, SpindaIsland_ShupperHouse_Shuppet_3
SpindaIsland_ShupperHouse_Shuppet_1:
# 26 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	release
	return

SpindaIsland_ShupperHouse_Shuppet_2:
# 13 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 14 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	speakername SpindaIsland_ShupperHouse_Shuppet_Text_1
# 15 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	msgbox SpindaIsland_ShupperHouse_Shuppet_Text_2
# 20 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	closemessage
# 21 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	removefieldmugshot
# 23 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	setflag FLAG_SAW_SHUPPETS
	goto SpindaIsland_ShupperHouse_Shuppet_1

SpindaIsland_ShupperHouse_Shuppet_3:
# 12 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	goto_if_unset FLAG_SAW_SHUPPETS, SpindaIsland_ShupperHouse_Shuppet_2
	goto SpindaIsland_ShupperHouse_Shuppet_1


SpindaIsland_ShupperHouse_ChaseShuppets::
# 30 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	lock
# 32 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	playse SE_SWITCH
# 33 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	waitse
# 34 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	playse SE_M_LEER
# 35 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	fadescreenspeed FADE_TO_WHITE, 0
# 36 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	fadescreenspeed FADE_FROM_WHITE, 0
# 37 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	waitse
# 39 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	applymovement 1, Common_Movement_ExclamationMark
# 40 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	playmoncry SPECIES_SHUPPET, CRY_MODE_NORMAL
# 41 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	waitmoncry
# 42 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	applymovement 2, Common_Movement_ExclamationMark
# 43 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	playmoncry SPECIES_SHUPPET, CRY_MODE_NORMAL
# 44 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	waitmoncry
# 45 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	waitmovement 0
# 47 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	removeobject 1
# 48 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	delay 20
# 49 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	removeobject 2
# 50 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	delay 60
# 52 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 53 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	speakername SpindaIsland_ShupperHouse_Shuppet_Text_1
# 54 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	msgbox SpindaIsland_ShupperHouse_ChaseShuppets_Text_0
# 57 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	closemessage
# 58 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	removefieldmugshot
# 60 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	setflag FLAG_HIDE_SHUPPETS
# 62 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	release
	return


SpindaIsland_ShupperHouse_FlashShuppetWrongDir::
# 66 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	lock
# 68 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	playse SE_SWITCH
# 69 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	waitse
# 70 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	playse SE_M_LEER
# 71 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	fadescreenspeed FADE_TO_WHITE, 0
# 72 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	fadescreenspeed FADE_FROM_WHITE, 0
# 73 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	waitse
# 75 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	delay 48
# 77 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 78 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	speakername SpindaIsland_ShupperHouse_Shuppet_Text_1
# 79 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	msgbox SpindaIsland_ShupperHouse_FlashShuppetWrongDir_Text_0
# 83 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	closemessage
# 84 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	removefieldmugshot
# 86 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	release
	return


SpindaIsland_ShupperHouse_Blinds::
# 90 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	lock
# 92 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 93 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	speakername SpindaIsland_ShupperHouse_Shuppet_Text_1
# 94 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	goto_if_set FLAG_HIDE_SHUPPETS, SpindaIsland_ShupperHouse_Blinds_2
# 100 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	msgbox SpindaIsland_ShupperHouse_Blinds_Text_1
SpindaIsland_ShupperHouse_Blinds_1:
# 104 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	closemessage
# 105 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	removefieldmugshot
# 107 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	release
	return

SpindaIsland_ShupperHouse_Blinds_2:
# 95 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	msgbox SpindaIsland_ShupperHouse_Blinds_Text_0
	goto SpindaIsland_ShupperHouse_Blinds_1


SpindaIsland_ShupperHouse_Shuppet_Text_0:
# 8 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	.string "Kekhekhehehe…$"

SpindaIsland_ShupperHouse_Shuppet_Text_1:
# 14 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	.string "Little Archie$"

SpindaIsland_ShupperHouse_Shuppet_Text_2:
# 16 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	.string "That's what the old lady must have\n"
	.string "been hearing!\p"
	.string "Maybe if I spook them, they'll go\n"
	.string "away?\p"
	.string "What are ghosts afraid of?$"

SpindaIsland_ShupperHouse_ChaseShuppets_Text_0:
# 55 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	.string "This takes care of that!$"

SpindaIsland_ShupperHouse_FlashShuppetWrongDir_Text_0:
# 80 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	.string "Nothing happened.\p"
	.string "That screen probably protects them.$"

SpindaIsland_ShupperHouse_Blinds_Text_0:
# 96 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	.string "No need to open them now.\p"
	.string "The Shuppet already left!$"

SpindaIsland_ShupperHouse_Blinds_Text_1:
# 101 "data/maps/SpindaIsland_ShupperHouse/scripts.pory"
	.string "The blinds are shut. They won't budge.$"

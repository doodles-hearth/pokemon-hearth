SpindaIsland_Home_MapScripts::
	.byte 0


SpindaIsland_Home_EventScript_HidingBoy::
# 6 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_HidingBoy_Text_0, MSGBOX_NPC
	return


testytesto::
# 12 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 13 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox testytesto_Text_0
# 14 "data/maps/SpindaIsland_Home/scripts.pory"
	call Spinda_SpinClockwise
# 15 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_HidingBoy_Text_0:
# 7 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Something is blocking the way.$"

testytesto_Text_0:
# 13 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "SPEEEEN$"

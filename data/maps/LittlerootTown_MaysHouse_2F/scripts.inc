LittlerootTown_MaysHouse_2F_MapScripts::
	.byte 0


LittlerootTown_MaysHouse_2F_BigSisCalling::
# 11 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	lock
# 12 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox LittlerootTown_MaysHouse_2F_BigSisCalling_Text_0
# 16 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_SUNRISE_VILLAGE_INTRO_STATE, 2
# 17 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	release
	end


# 21 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_PlayerGetOutOfBed:
# 22 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_8
# 23 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	face_left
# 24 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 25 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	jump_left
	step_end

LittlerootTown_MaysHouse_2F_BigSisCalling_Text_0:
# 13 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "{PLAYER}! {PLAYER}! Are you still\n"
	.string "sleeping?\p"
	.string "Get up and get ready!$"

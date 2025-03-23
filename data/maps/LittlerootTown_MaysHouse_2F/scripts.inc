LittlerootTown_MaysHouse_2F_MapScripts::
	.byte 0


LittlerootTown_MaysHouse_2F_BigSisCalling::
	lock
	msgbox LittlerootTown_MaysHouse_2F_BigSisCalling_Text_0
	closemessage
	setvar VAR_SUNRISE_VILLAGE_INTRO_STATE, 2
	release
	end


LittlerootTown_MaysHouse_2F_Movement_PlayerGetOutOfBed:
	delay_8
	face_left
	delay_16
	jump_left
	step_end

LittlerootTown_MaysHouse_2F_BigSisCalling_Text_0:
	.string "{PLAYER}! {PLAYER}! Are you\n"
	.string "still sleeping?\p"
	.string "Get up and get ready!$"

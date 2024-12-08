ChiiTown_NPCSchedules::
# 23 "data/scripts/schedule/chii_town.pory"
	setflag FLAG_TEMP_5
# 24 "data/scripts/schedule/chii_town.pory"
	setflag FLAG_TEMP_6
# 25 "data/scripts/schedule/chii_town.pory"
	gettimeofday
# 26 "data/scripts/schedule/chii_town.pory"
	switch VAR_0x8000
# 27 "data/scripts/schedule/chii_town.pory"
	case 0, ChiiTown_NPCSchedules_2
# 29 "data/scripts/schedule/chii_town.pory"
	case 1, ChiiTown_NPCSchedules_3
# 31 "data/scripts/schedule/chii_town.pory"
	case 2, ChiiTown_NPCSchedules_4
# 33 "data/scripts/schedule/chii_town.pory"
	case 3, ChiiTown_NPCSchedules_5
# 35 "data/scripts/schedule/chii_town.pory"
	case 4, ChiiTown_NPCSchedules_6
# 37 "data/scripts/schedule/chii_town.pory"
	case 5, ChiiTown_NPCSchedules_7
# 39 "data/scripts/schedule/chii_town.pory"
	case 6, ChiiTown_NPCSchedules_8
	return

ChiiTown_NPCSchedules_2:
# 28 "data/scripts/schedule/chii_town.pory"
	call ChiiTown_DeadNightSchedules
	return

ChiiTown_NPCSchedules_3:
# 30 "data/scripts/schedule/chii_town.pory"
	call ChiiTown_EarlySchedules
	return

ChiiTown_NPCSchedules_4:
# 32 "data/scripts/schedule/chii_town.pory"
	call ChiiTown_MorningSchedules
	return

ChiiTown_NPCSchedules_5:
# 34 "data/scripts/schedule/chii_town.pory"
	call ChiiTown_LunchtimeSchedules
	return

ChiiTown_NPCSchedules_6:
# 36 "data/scripts/schedule/chii_town.pory"
	call ChiiTown_AfternoonSchedules
	return

ChiiTown_NPCSchedules_7:
# 38 "data/scripts/schedule/chii_town.pory"
	call ChiiTown_EveningSchedules
	return

ChiiTown_NPCSchedules_8:
# 40 "data/scripts/schedule/chii_town.pory"
	call ChiiTown_NightSchedules
	return


ChiiTown_DeadNightSchedules:
	return


ChiiTown_EarlySchedules:
	return


ChiiTown_MorningSchedules:
	return


ChiiTown_LunchtimeSchedules:
# 56 "data/scripts/schedule/chii_town.pory"
	clearflag FLAG_TEMP_5
	return


ChiiTown_AfternoonSchedules:
	return


ChiiTown_EveningSchedules:
	return


ChiiTown_NightSchedules:
	return


ChiiTownSchool_NPCSchedules::
# 75 "data/scripts/schedule/chii_town.pory"
	setflag FLAG_TEMP_1
# 76 "data/scripts/schedule/chii_town.pory"
	setflag FLAG_TEMP_2
# 77 "data/scripts/schedule/chii_town.pory"
	gettimeofday
# 78 "data/scripts/schedule/chii_town.pory"
	switch VAR_0x8000
# 79 "data/scripts/schedule/chii_town.pory"
	case 0, ChiiTownSchool_NPCSchedules_2
# 81 "data/scripts/schedule/chii_town.pory"
	case 1, ChiiTownSchool_NPCSchedules_3
# 83 "data/scripts/schedule/chii_town.pory"
	case 2, ChiiTownSchool_NPCSchedules_4
# 85 "data/scripts/schedule/chii_town.pory"
	case 3, ChiiTownSchool_NPCSchedules_5
# 87 "data/scripts/schedule/chii_town.pory"
	case 4, ChiiTownSchool_NPCSchedules_6
# 89 "data/scripts/schedule/chii_town.pory"
	case 5, ChiiTownSchool_NPCSchedules_7
# 91 "data/scripts/schedule/chii_town.pory"
	case 6, ChiiTownSchool_NPCSchedules_8
	return

ChiiTownSchool_NPCSchedules_2:
# 80 "data/scripts/schedule/chii_town.pory"
	call ChiiTownSchool_DeadNightSchedules
	return

ChiiTownSchool_NPCSchedules_3:
# 82 "data/scripts/schedule/chii_town.pory"
	call ChiiTownSchool_EarlySchedules
	return

ChiiTownSchool_NPCSchedules_4:
# 84 "data/scripts/schedule/chii_town.pory"
	call ChiiTownSchool_MorningSchedules
	return

ChiiTownSchool_NPCSchedules_5:
# 86 "data/scripts/schedule/chii_town.pory"
	call ChiiTownSchool_LunchtimeSchedules
	return

ChiiTownSchool_NPCSchedules_6:
# 88 "data/scripts/schedule/chii_town.pory"
	call ChiiTownSchool_AfternoonSchedules
	return

ChiiTownSchool_NPCSchedules_7:
# 90 "data/scripts/schedule/chii_town.pory"
	call ChiiTownSchool_EveningSchedules
	return

ChiiTownSchool_NPCSchedules_8:
# 92 "data/scripts/schedule/chii_town.pory"
	call ChiiTownSchool_NightSchedules
	return


ChiiTownSchool_DeadNightSchedules:
	return


ChiiTownSchool_EarlySchedules:
# 101 "data/scripts/schedule/chii_town.pory"
	clearflag FLAG_TEMP_1
# 102 "data/scripts/schedule/chii_town.pory"
	clearflag FLAG_TEMP_2
	return


ChiiTownSchool_MorningSchedules:
# 106 "data/scripts/schedule/chii_town.pory"
	clearflag FLAG_TEMP_1
# 107 "data/scripts/schedule/chii_town.pory"
	clearflag FLAG_TEMP_2
	return


ChiiTownSchool_LunchtimeSchedules:
	return


ChiiTownSchool_AfternoonSchedules:
# 113 "data/scripts/schedule/chii_town.pory"
	clearflag FLAG_TEMP_1
# 114 "data/scripts/schedule/chii_town.pory"
	clearflag FLAG_TEMP_2
	return


ChiiTownSchool_EveningSchedules:
	return


ChiiTownSchool_NightSchedules:
	return


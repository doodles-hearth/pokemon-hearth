ChiiTown_NPCSchedules::
	setflag FLAG_TEMP_5
	setflag FLAG_TEMP_6
	setflag FLAG_TEMP_7
	setflag FLAG_TEMP_8
	gettimeofday
	switch VAR_0x8000
	case TIME_DEAD_NIGHT, ChiiTown_NPCSchedules_2
	case TIME_EARLY_MORNING, ChiiTown_NPCSchedules_3
	case TIME_MORNING, ChiiTown_NPCSchedules_4
	case TIME_LUNCHTIME, ChiiTown_NPCSchedules_5
	case TIME_NOONTIME, ChiiTown_NPCSchedules_6
	case TIME_EVENING, ChiiTown_NPCSchedules_7
	case TIME_NIGHT, ChiiTown_NPCSchedules_8
	return

ChiiTown_NPCSchedules_2:
	call ChiiTown_DeadNightSchedules
	return

ChiiTown_NPCSchedules_3:
	call ChiiTown_EarlySchedules
	return

ChiiTown_NPCSchedules_4:
	call ChiiTown_MorningSchedules
	return

ChiiTown_NPCSchedules_5:
	call ChiiTown_LunchtimeSchedules
	return

ChiiTown_NPCSchedules_6:
	call ChiiTown_AfternoonSchedules
	return

ChiiTown_NPCSchedules_7:
	call ChiiTown_EveningSchedules
	return

ChiiTown_NPCSchedules_8:
	call ChiiTown_NightSchedules
	return


ChiiTown_DrawMetatiles::
	switch VAR_0x8000
	case TIME_DEAD_NIGHT, ChiiTown_DrawMetatiles_2
	case TIME_EARLY_MORNING, ChiiTown_DrawMetatiles_3
	case TIME_MORNING, ChiiTown_DrawMetatiles_3
	case TIME_LUNCHTIME, ChiiTown_DrawMetatiles_3
	case TIME_NOONTIME, ChiiTown_DrawMetatiles_3
	case TIME_EVENING, ChiiTown_DrawMetatiles_3
	case TIME_NIGHT, ChiiTown_DrawMetatiles_3

ChiiTown_DrawMetatiles_3:
	end

ChiiTown_DrawMetatiles_2:
	setmetatile 14, 6, METATILE_PorytilesPrimaryTutorial_DoorPlaceholder, TRUE
	setmetatile 24, 20, METATILE_PorytilesPrimaryTutorial_DoorPlaceholder, TRUE
	return


ChiiTown_DeadNightSchedules:
	return


ChiiTown_EarlySchedules:
	clearflag FLAG_TEMP_8
	return


ChiiTown_MorningSchedules:
	clearflag FLAG_TEMP_6
	clearflag FLAG_TEMP_8
	return


ChiiTown_LunchtimeSchedules:
	clearflag FLAG_TEMP_5
	clearflag FLAG_TEMP_8
	return


ChiiTown_AfternoonSchedules:
	clearflag FLAG_TEMP_6
	clearflag FLAG_TEMP_7
	clearflag FLAG_TEMP_8
	return


ChiiTown_EveningSchedules:
	clearflag FLAG_TEMP_8
	return


ChiiTown_NightSchedules:
	clearflag FLAG_TEMP_8
	return


ChiiTownSchool_NPCSchedules::
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_2
	setflag FLAG_TEMP_3
	gettimeofday
	switch VAR_0x8000
	case TIME_DEAD_NIGHT, ChiiTownSchool_NPCSchedules_2
	case TIME_EARLY_MORNING, ChiiTownSchool_NPCSchedules_3
	case TIME_MORNING, ChiiTownSchool_NPCSchedules_4
	case TIME_LUNCHTIME, ChiiTownSchool_NPCSchedules_5
	case TIME_NOONTIME, ChiiTownSchool_NPCSchedules_6
	case TIME_EVENING, ChiiTownSchool_NPCSchedules_7
	case TIME_NIGHT, ChiiTownSchool_NPCSchedules_8
	return

ChiiTownSchool_NPCSchedules_2:
	call ChiiTownSchool_DeadNightSchedules
	return

ChiiTownSchool_NPCSchedules_3:
	call ChiiTownSchool_EarlySchedules
	return

ChiiTownSchool_NPCSchedules_4:
	call ChiiTownSchool_MorningSchedules
	return

ChiiTownSchool_NPCSchedules_5:
	call ChiiTownSchool_LunchtimeSchedules
	return

ChiiTownSchool_NPCSchedules_6:
	call ChiiTownSchool_AfternoonSchedules
	return

ChiiTownSchool_NPCSchedules_7:
	call ChiiTownSchool_EveningSchedules
	return

ChiiTownSchool_NPCSchedules_8:
	call ChiiTownSchool_NightSchedules
	return


ChiiTownSchool_DeadNightSchedules:
	return


ChiiTownSchool_EarlySchedules:
	clearflag FLAG_TEMP_3
	return


ChiiTownSchool_MorningSchedules:
	clearflag FLAG_TEMP_1
	clearflag FLAG_TEMP_2
	clearflag FLAG_TEMP_3
	return


ChiiTownSchool_LunchtimeSchedules:
	clearflag FLAG_TEMP_2
	return


ChiiTownSchool_AfternoonSchedules:
	clearflag FLAG_TEMP_1
	clearflag FLAG_TEMP_2
	clearflag FLAG_TEMP_3
	return


ChiiTownSchool_EveningSchedules:
	clearflag FLAG_TEMP_3
	return


ChiiTownSchool_NightSchedules:
	return


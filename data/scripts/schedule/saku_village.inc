SakuVillage_NPCSchedules::
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_2
	gettimeofday
	switch VAR_0x8000
	case TIME_DEAD_NIGHT, SakuVillage_NPCSchedules_2
	case TIME_EARLY_MORNING, SakuVillage_NPCSchedules_3
	case TIME_MORNING, SakuVillage_NPCSchedules_4
	case TIME_LUNCHTIME, SakuVillage_NPCSchedules_5
	case TIME_NOONTIME, SakuVillage_NPCSchedules_6
	case TIME_EVENING, SakuVillage_NPCSchedules_7
	case TIME_NIGHT, SakuVillage_NPCSchedules_8
	return

SakuVillage_NPCSchedules_2:
	call SakuVillage_DeadNightSchedules
	return

SakuVillage_NPCSchedules_3:
	call SakuVillage_EarlySchedules
	return

SakuVillage_NPCSchedules_4:
	call SakuVillage_MorningSchedules
	return

SakuVillage_NPCSchedules_5:
	call SakuVillage_LunchtimeSchedules
	return

SakuVillage_NPCSchedules_6:
	call SakuVillage_AfternoonSchedules
	return

SakuVillage_NPCSchedules_7:
	call SakuVillage_EveningSchedules
	return

SakuVillage_NPCSchedules_8:
	call SakuVillage_NightSchedules
	return


SakuVillage_DrawMetatiles::
	gettimeofday
	switch VAR_0x8000
	case TIME_DEAD_NIGHT, SakuVillage_DrawMetatiles_2
	case TIME_EARLY_MORNING, SakuVillage_DrawMetatiles_3
	case TIME_MORNING, SakuVillage_DrawMetatiles_3
	case TIME_LUNCHTIME, SakuVillage_DrawMetatiles_3
	case TIME_NOONTIME, SakuVillage_DrawMetatiles_3
	case TIME_EVENING, SakuVillage_DrawMetatiles_3
	case TIME_NIGHT, SakuVillage_DrawMetatiles_3
SakuVillage_DrawMetatiles_3:
	end

SakuVillage_DrawMetatiles_2:
	setmetatile 16, 20, METATILE_SakuKura_Door, TRUE
	setmetatile 22, 18, METATILE_SakuKura_Door, TRUE
	setmetatile 18, 33, METATILE_SakuKura_Door, TRUE
	setmetatile 35, 31, METATILE_SakuKura_Door, TRUE
	return


SakuVillage_DeadNightSchedules:
	return


SakuVillage_EarlySchedules:
	clearflag FLAG_TEMP_1
	return


SakuVillage_MorningSchedules:
	clearflag FLAG_TEMP_1
	return


SakuVillage_LunchtimeSchedules:
	clearflag FLAG_TEMP_2
	return


SakuVillage_AfternoonSchedules:
	clearflag FLAG_TEMP_1
	return


SakuVillage_EveningSchedules:
	return


SakuVillage_NightSchedules:
	return


KuraVillage_NPCSchedules::
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_2
	gettimeofday
	switch VAR_0x8000
	case TIME_DEAD_NIGHT, KuraVillage_NPCSchedules_2
	case TIME_EARLY_MORNING, KuraVillage_NPCSchedules_3
	case TIME_MORNING, KuraVillage_NPCSchedules_4
	case TIME_LUNCHTIME, KuraVillage_NPCSchedules_5
	case TIME_NOONTIME, KuraVillage_NPCSchedules_6
	case TIME_EVENING, KuraVillage_NPCSchedules_7
	case TIME_NIGHT, KuraVillage_NPCSchedules_8
	return

KuraVillage_NPCSchedules_2:
	call KuraVillage_DeadNightSchedules
	return

KuraVillage_NPCSchedules_3:
	call KuraVillage_EarlySchedules
	return

KuraVillage_NPCSchedules_4:
	call KuraVillage_MorningSchedules
	return

KuraVillage_NPCSchedules_5:
	call KuraVillage_LunchtimeSchedules
	return

KuraVillage_NPCSchedules_6:
	call KuraVillage_AfternoonSchedules
	return

KuraVillage_NPCSchedules_7:
	call KuraVillage_EveningSchedules
	return

KuraVillage_NPCSchedules_8:
	call KuraVillage_NightSchedules
	return


KuraVillage_DrawMetatiles::
	gettimeofday
	switch VAR_0x8000
	case TIME_DEAD_NIGHT, KuraVillage_DrawMetatiles_2
	case TIME_EARLY_MORNING, KuraVillage_DrawMetatiles_3
	case TIME_MORNING, KuraVillage_DrawMetatiles_3
	case TIME_LUNCHTIME, KuraVillage_DrawMetatiles_3
	case TIME_NOONTIME, KuraVillage_DrawMetatiles_3
	case TIME_EVENING, KuraVillage_DrawMetatiles_3
	case TIME_NIGHT, KuraVillage_DrawMetatiles_3
KuraVillage_DrawMetatiles_3:
	end

KuraVillage_DrawMetatiles_2:
	setmetatile 40, 16, METATILE_SakuKura_Door, TRUE
	setmetatile 43, 23, METATILE_SakuKura_Door, TRUE
	setmetatile 34, 25, METATILE_SakuKura_Door, TRUE
	setmetatile 18, 7, METATILE_SakuKura_Door, TRUE
	return


KuraVillage_DeadNightSchedules:
	return


KuraVillage_EarlySchedules:
	clearflag FLAG_TEMP_1
	return


KuraVillage_MorningSchedules:
	clearflag FLAG_TEMP_1
	return


KuraVillage_LunchtimeSchedules:
	clearflag FLAG_TEMP_2
	return


KuraVillage_AfternoonSchedules:
	clearflag FLAG_TEMP_1
	return


KuraVillage_EveningSchedules:
	return


KuraVillage_NightSchedules:
	return


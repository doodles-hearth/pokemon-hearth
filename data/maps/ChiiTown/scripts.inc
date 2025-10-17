ChiiTown_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, ChiiTown_MapScripts_MAP_SCRIPT_ON_LOAD
	map_script MAP_SCRIPT_ON_TRANSITION, ChiiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ChiiTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

ChiiTown_MapScripts_MAP_SCRIPT_ON_LOAD:
	call ChiiTown_DrawMetatiles
	return

ChiiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setflag FLAG_VISITED_CHII_TOWN
	return

ChiiTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_CHII_TOWN_OLD_MAN_TRESPASS_STATE, 2, ChiiTown_EventScript_SetTrespassVar
	.2byte 0


ChiiTown_DrawMetatiles::
	goto_if_set FLAG_BADGE01_GET, ChiiTown_DrawMetatiles_2
ChiiTown_DrawMetatiles_1:
	goto_if_set FLAG_BADGE03_GET, ChiiTown_DrawMetatiles_5
ChiiTown_DrawMetatiles_4:
	goto_if_set FLAG_BADGE04_GET, ChiiTown_DrawMetatiles_8
ChiiTown_DrawMetatiles_7:
	goto_if_set FLAG_BADGE05_GET, ChiiTown_DrawMetatiles_11
ChiiTown_DrawMetatiles_10:
	goto_if_set FLAG_BADGE06_GET, ChiiTown_DrawMetatiles_14
ChiiTown_DrawMetatiles_13:
	goto_if_set FLAG_BADGE08_GET, ChiiTown_DrawMetatiles_17
ChiiTown_DrawMetatiles_16:
	gettimeofday
	switch VAR_0x8000
	case TIME_DEAD_NIGHT, ChiiTown_DrawMetatiles_20
	case TIME_EARLY_MORNING, ChiiTown_DrawMetatiles_21
	case TIME_MORNING, ChiiTown_DrawMetatiles_21
	case TIME_LUNCHTIME, ChiiTown_DrawMetatiles_21
	case TIME_AFTERNOON, ChiiTown_DrawMetatiles_21
	case TIME_EVENING, ChiiTown_DrawMetatiles_21
	case TIME_NIGHT, ChiiTown_DrawMetatiles_21
ChiiTown_DrawMetatiles_21:
	end

ChiiTown_DrawMetatiles_2:
	setmetatile 17, 18, METATILE_SunriseVillage_RedFlowers, FALSE
	setmetatile 17, 19, METATILE_SunriseVillage_RedFlowers, FALSE
	goto ChiiTown_DrawMetatiles_1

ChiiTown_DrawMetatiles_5:
	setmetatile 16, 16, METATILE_SunriseVillage_RedFlowers, FALSE
	goto ChiiTown_DrawMetatiles_4

ChiiTown_DrawMetatiles_8:
	setmetatile 11, 20, METATILE_SunriseVillage_RedFlowers, FALSE
	setmetatile 15, 22, METATILE_SunriseVillage_RedFlowers, FALSE
	goto ChiiTown_DrawMetatiles_7

ChiiTown_DrawMetatiles_11:
	setmetatile 16, 22, METATILE_SunriseVillage_RedFlowers, FALSE
	goto ChiiTown_DrawMetatiles_10

ChiiTown_DrawMetatiles_14:
	setmetatile 18, 23, METATILE_SunriseVillage_RedFlowers, FALSE
	setmetatile 17, 16, METATILE_SunriseVillage_RedFlowers, FALSE
	goto ChiiTown_DrawMetatiles_13

ChiiTown_DrawMetatiles_17:
	setmetatile 10, 21, METATILE_SunriseVillage_RedFlowers, FALSE
	setmetatile 16, 19, METATILE_SunriseVillage_RedFlowers, FALSE
	setmetatile 21, 23, METATILE_SunriseVillage_RedFlowers, FALSE
	goto ChiiTown_DrawMetatiles_16

ChiiTown_DrawMetatiles_20:
	setmetatile 14, 5, METATILE_PorytilesPrimaryTutorial_ClosedDoorTop, TRUE
	setmetatile 14, 6, METATILE_PorytilesPrimaryTutorial_ClosedDoorBottom, TRUE
	return


ChiiTown_EventScript_WatchfulMom::
	gettimeofday
	setspeaker SP_NAME_WOMAN
	switch VAR_0x8000
	case TIME_MORNING, ChiiTown_EventScript_WatchfulMom_3
	case TIME_AFTERNOON, ChiiTown_EventScript_WatchfulMom_4
	msgbox ChiiTown_EventScript_WatchfulMom_Text_2, MSGBOX_NPC
ChiiTown_EventScript_WatchfulMom_1:
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	return

ChiiTown_EventScript_WatchfulMom_3:
	msgbox ChiiTown_EventScript_WatchfulMom_Text_0, MSGBOX_NPC
	goto ChiiTown_EventScript_WatchfulMom_1

ChiiTown_EventScript_WatchfulMom_4:
	msgbox ChiiTown_EventScript_WatchfulMom_Text_1, MSGBOX_NPC
	goto ChiiTown_EventScript_WatchfulMom_1


ChiiTown_EventScript_Shopper::
	setspeaker SP_NAME_WOMAN
	msgbox ChiiTown_EventScript_Shopper_Text_0, MSGBOX_NPC
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	return


ChiiTown_EventScript_Kecleon::
	lock
	faceplayer
	setseenmon SPECIES_KECLEON
	playmoncry SPECIES_KECLEON, CRY_MODE_NORMAL
	setspeakertomonname SPECIES_KECLEON
	applymovement VAR_LAST_TALKED, ChiiTown_EventScript_Kecleon_Movement_0
	msgbox ChiiTown_EventScript_Kecleon_Text_0
	waitmoncry
	closemessage
	release
	return


ChiiTown_EventScript_PlantingFlowers::
	lock
	faceplayer
	applymovement VAR_LAST_TALKED, ChiiTown_EventScript_PlantingFlowers_Movement_0
	setspeaker SP_NAME_LITTLE_GIRL
	msgbox ChiiTown_EventScript_PlantingFlowers_Text_0
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	return


ChiiTown_EventScript_AlsoPlantingFlowers::
	setspeaker SP_NAME_LITTLE_BOY
	msgbox ChiiTown_EventScript_AlsoPlantingFlowers_Text_0, MSGBOX_NPC
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	return


ChiiTown_EventScript_WatchingTheChildren::
	setspeaker SP_NAME_TEACHER
	msgbox ChiiTown_EventScript_WatchingTheChildren_Text_0, MSGBOX_NPC
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	return


ChiiTown_EventScript_EatingBerries::
	lock
	faceplayer
	setspeaker SP_NAME_LITTLE_GIRL
	msgbox ChiiTown_EventScript_EatingBerries_Text_0, MSGBOX_DEFAULT
	closemessage
	checkitem ITEM_ORAN_BERRY, 1
	compare VAR_RESULT, 0
	goto_if_ne ChiiTown_EventScript_EatingBerries_2
ChiiTown_EventScript_EatingBerries_1:
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	return

ChiiTown_EventScript_EatingBerries_2:
	msgbox ChiiTown_EventScript_EatingBerries_Text_1
	mcdialogue ChiiTown_EventScript_EatingBerries_Text_2, ChiiTown_EventScript_EatingBerries_Text_3
	compare VAR_RESULT, 0
	goto_if_eq ChiiTown_EventScript_EatingBerries_4
	goto ChiiTown_EventScript_EatingBerries_1

ChiiTown_EventScript_EatingBerries_4:
	removeitem ITEM_ORAN_BERRY
	applymovement VAR_LAST_TALKED, ChiiTown_EventScript_EatingBerries_Movement_0
	setspeaker SP_NAME_LITTLE_GIRL
	msgbox ChiiTown_EventScript_EatingBerries_Text_4, MSGBOX_DEFAULT
	closemessage
	addvar VAR_PLAYER_REPUTATION, 1
	goto ChiiTown_EventScript_EatingBerries_1


ChiiTown_EventScript_BerryEnthusiast::
	lock
	faceplayer
	setspeaker SP_NAME_LITTLE_BOY
	msgbox ChiiTown_EventScript_BerryEnthusiast_Text_0
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	return


ChiiTown_EventScript_BattlingGirl::
	lock
	faceplayer
	goto_if_set FLAG_BEAT_CHII_TOWN_KIDS, ChiiTown_EventScript_BattlingGirl_2
	compare VAR_FACING, DIR_NORTH
	goto_if_eq ChiiTown_EventScript_BattlingGirl_6
	applymovement 16, ChiiTown_EventScript_BattlingGirl_Movement_1
ChiiTown_EventScript_BattlingGirl_5:
	waitmovement 0
	special GetPlayerMrMrsString
	setspeaker SP_NAME_LITTLE_GIRL
	msgbox ChiiTown_EventScript_BattlingGirl_Text_1
	mcdialogue ChiiTown_EventScript_BattlingGirl_Text_2, ChiiTown_EventScript_BattlingGirl_Text_3
	closemessage
	compare VAR_RESULT, 0
	goto_if_eq ChiiTown_EventScript_BattlingGirl_10
	applymovement VAR_LAST_TALKED, ChiiTown_EventScript_BattlingGirl_Movement_2
	setspeaker SP_NAME_LITTLE_GIRL
	msgbox ChiiTown_EventScript_BattlingGirl_Text_6
	closemessage
ChiiTown_EventScript_BattlingGirl_9:
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	applymovement 16, ChiiTown_EventScript_BattlingGirl_Movement_1
	waitmovement 0
ChiiTown_EventScript_BattlingGirl_1:
	release
	return

ChiiTown_EventScript_BattlingGirl_2:
	special GetPlayerMrMrsString
	setspeaker SP_NAME_LITTLE_GIRL
	msgbox ChiiTown_EventScript_BattlingGirl_Text_0
	closemessage
	goto ChiiTown_EventScript_BattlingGirl_1

ChiiTown_EventScript_BattlingGirl_6:
	applymovement 16, ChiiTown_EventScript_BattlingGirl_Movement_0
	goto ChiiTown_EventScript_BattlingGirl_5

ChiiTown_EventScript_BattlingGirl_10:
	trainerbattle_two_trainers TRAINER_MINORI, ChiiTown_EventScript_BattlingGirl_Text_4, TRAINER_KAITO, ChiiTown_EventScript_BattlingGirl_Text_5
	setflag FLAG_BEAT_CHII_TOWN_KIDS
	special GetPlayerMrMrsString
	applymovement VAR_LAST_TALKED, ChiiTown_EventScript_EatingBerries_Movement_0
	setspeaker SP_NAME_LITTLE_GIRL
	msgbox ChiiTown_EventScript_BattlingGirl_Text_0
	closemessage
	goto ChiiTown_EventScript_BattlingGirl_9


ChiiTown_EventScript_BattlingBoy::
	lock
	faceplayer
	goto_if_set FLAG_BEAT_CHII_TOWN_KIDS, ChiiTown_EventScript_BattlingBoy_2
	applymovement 15, ChiiTown_EventScript_BattlingGirl_Movement_0
	waitmovement 0
	special GetPlayerMrMrsString
	setspeaker SP_NAME_LITTLE_BOY
	msgbox ChiiTown_EventScript_BattlingBoy_Text_1
	mcdialogue ChiiTown_EventScript_BattlingGirl_Text_2, ChiiTown_EventScript_BattlingGirl_Text_3
	closemessage
	compare VAR_RESULT, 0
	goto_if_eq ChiiTown_EventScript_BattlingBoy_6
	applymovement VAR_LAST_TALKED, ChiiTown_EventScript_BattlingGirl_Movement_2
	setspeaker SP_NAME_LITTLE_BOY
	msgbox ChiiTown_EventScript_BattlingBoy_Text_3
	closemessage
ChiiTown_EventScript_BattlingBoy_5:
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	applymovement 15, ChiiTown_EventScript_BattlingBoy_Movement_0
	waitmovement 0
ChiiTown_EventScript_BattlingBoy_1:
	release
	return

ChiiTown_EventScript_BattlingBoy_2:
	special GetPlayerMrMrsString
	setspeaker SP_NAME_LITTLE_BOY
	msgbox ChiiTown_EventScript_BattlingBoy_Text_0
	closemessage
	goto ChiiTown_EventScript_BattlingBoy_1

ChiiTown_EventScript_BattlingBoy_6:
	trainerbattle_two_trainers TRAINER_MINORI, ChiiTown_EventScript_BattlingGirl_Text_4, TRAINER_KAITO, ChiiTown_EventScript_BattlingGirl_Text_5
	setflag FLAG_BEAT_CHII_TOWN_KIDS
	special GetPlayerMrMrsString
	applymovement VAR_LAST_TALKED, ChiiTown_EventScript_EatingBerries_Movement_0
	setspeaker SP_NAME_LITTLE_BOY
	msgbox ChiiTown_EventScript_BattlingBoy_Text_2
	closemessage
	goto ChiiTown_EventScript_BattlingBoy_5


ChiiTown_EventScript_Mart::
	lock
	faceplayer
	setspeaker SP_NAME_SHOPKEEPER
	message ChiiTown_EventScript_Mart_Text_0
	waitmessage
	pokemart ChiiTown_Mart
	setspeaker SP_NAME_SHOPKEEPER
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	return


ChiiTown_EventScript_MartDecor::
	lock
	faceplayer
	setspeaker SP_NAME_SHOPKEEPER
	message ChiiTown_EventScript_MartDecor_Text_0
	waitmessage
	pokemartdecoration ChiiTown_MartDecors
	setspeaker SP_NAME_SHOPKEEPER
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	return


	.align 2
ChiiTown_MartDecors:
	.2byte DECOR_SURF_MAT
	.2byte ITEM_NONE

	.align 2
ChiiTown_Mart:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_OINTMENT
	.2byte ITEM_REVIVAL_POWDER
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_NONE

ChiiTown_EventScript_Samurai::
	setspeaker SP_NAME_SAMURAI
	msgbox ChiiTown_EventScript_Samurai_Text_0, MSGBOX_NPC
	return


ChiiTown_EventScript_TownSign::
	msgbox ChiiTown_EventScript_TownSign_Text_0, MSGBOX_SIGN
	return


ChiiTown_EventScript_SchoolSign::
	msgbox ChiiTown_EventScript_SchoolSign_Text_0, MSGBOX_SIGN
	return


ChiiTown_EventScript_SetTrespassVar::
	setvar VAR_CHII_TOWN_OLD_MAN_TRESPASS_STATE, 1
	return


ChiiTown_EventScript_Kecleon_Movement_0:
	emote_music
	step_end

ChiiTown_EventScript_PlantingFlowers_Movement_0:
	emote_happy
	step_end

ChiiTown_EventScript_EatingBerries_Movement_0:
	emote_heart
	step_end

ChiiTown_EventScript_BattlingGirl_Movement_0:
	face_down
	step_end

ChiiTown_EventScript_BattlingGirl_Movement_1:
	face_left
	step_end

ChiiTown_EventScript_BattlingGirl_Movement_2:
	emote_angry
	step_end

ChiiTown_EventScript_BattlingBoy_Movement_0:
	face_right
	step_end

ChiiTown_EventScript_WatchfulMom_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_SUNRISE_WOMAN_1 EMOTE_NORMAL}I'm dropping off my children to\n"
	.string "school.\p"
	.string "With all the recent Pokémon attacks,\n"
	.string "I will not let them leave my sight!$"

ChiiTown_EventScript_WatchfulMom_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_SUNRISE_WOMAN_1 EMOTE_NORMAL}I'm waiting to pick up my children\n"
	.string "after school.\p"
	.string "With all the recent Pokémon attacks,\n"
	.string "I will not let them leave my sight!$"

ChiiTown_EventScript_WatchfulMom_Text_2:
	.string "{CREATE_MUGSHOT MUGSHOT_SUNRISE_WOMAN_1 EMOTE_NORMAL}Phew… Being a full-time mom is\n"
	.string "exhausting…$"

ChiiTown_EventScript_Shopper_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_SUNRISE_WOMAN_2 EMOTE_NORMAL}The town market lady sells Pokémon\n"
	.string "medicine and Poké Balls now!\p"
	.string "Careful, though: her ointments can't\n"
	.string "be used in the middle of a battle.\p"
	.string "They're super cheap though, so don't\n"
	.string "be afraid to use them to avoid\l"
	.string "needing to run to the nearest Refuge!$"

ChiiTown_EventScript_Kecleon_Text_0:
	.string "Kleeeeh!$"

ChiiTown_EventScript_PlantingFlowers_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_SUNRISE_LITTLE_GIRL EMOTE_NORMAL}I'm planting flowers so that the wild\n"
	.string "Pokémon become happy again!$"

ChiiTown_EventScript_AlsoPlantingFlowers_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_SUNRISE_LITTLE_BOY EMOTE_NORMAL}She's making me plant flowers so that\n"
	.string "the wild Pokémon become happy again.\p"
	.string "I'm not though…$"

ChiiTown_EventScript_WatchingTheChildren_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_MASQUERAIN_GIRL EMOTE_NORMAL}Recess is great to channel the\n"
	.string "children's pent up energy.$"

ChiiTown_EventScript_EatingBerries_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_SCHOOL_KID_F EMOTE_NORMAL}Sensei said that we should eat\n"
	.string "berries to grow big and strong!\p"
	.string "But how are we supposed to get them\n"
	.string "if we aren't big and strong yet?$"

ChiiTown_EventScript_EatingBerries_Text_1:
	.string "Give the girl an Oran Berry?$"

ChiiTown_EventScript_EatingBerries_Text_2:
	.string "Give$"

ChiiTown_EventScript_EatingBerries_Text_3:
	.string "Don't give$"

ChiiTown_EventScript_EatingBerries_Text_4:
	.string "{CREATE_MUGSHOT MUGSHOT_SCHOOL_KID_F EMOTE_NORMAL}Oh my gosh, thank you!$"

ChiiTown_EventScript_BerryEnthusiast_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_SCHOOL_KID_M EMOTE_NORMAL}I've been eating berries just like\n"
	.string "Sensei said, but I haven't grown yet.\p"
	.string "I don't care though. They're\n"
	.string "delicious!$"

ChiiTown_EventScript_BattlingGirl_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_SCHOOL_KID_F EMOTE_NORMAL}Wow, {STR_VAR_1}! You're super\n"
	.string "strong!!\p"
	.string "I'll have to train Snuggles a whole lot\n"
	.string "more!$"

ChiiTown_EventScript_BattlingGirl_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_SCHOOL_KID_F EMOTE_NORMAL}Hey {STR_VAR_1}! We've been\n"
	.string "studying Pokémon battles in class.\l"
	.string "Wanna fight with us?$"

ChiiTown_EventScript_BattlingGirl_Text_2:
	.string "Sure!$"

ChiiTown_EventScript_BattlingGirl_Text_3:
	.string "I don't want to.$"

ChiiTown_EventScript_BattlingGirl_Text_4:
	.string "Whaaaat?!$"

ChiiTown_EventScript_BattlingGirl_Text_5:
	.string "Well I never learned about THAT!$"

ChiiTown_EventScript_BattlingGirl_Text_6:
	.string "{CREATE_MUGSHOT MUGSHOT_SCHOOL_KID_F EMOTE_NORMAL}Ughhhh, older kids are so boooring!$"

ChiiTown_EventScript_BattlingBoy_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_SCHOOL_KID_M EMOTE_NORMAL}Wow, {STR_VAR_1}! Can you be our\n"
	.string "Sensei?\p"
	.string "That way, Destroyer will be invincible!$"

ChiiTown_EventScript_BattlingBoy_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_SCHOOL_KID_M EMOTE_NORMAL}Hello {STR_VAR_1}! We're top of our\n"
	.string "class! That means we're strong!\l"
	.string "Wanna battle us?$"

ChiiTown_EventScript_BattlingBoy_Text_2:
	.string "{CREATE_MUGSHOT MUGSHOT_SCHOOL_KID_M EMOTE_NORMAL}Wow, {STR_VAR_1}! Can you be our\n"
	.string "sensei?\p"
	.string "That way, Destroyer will be invincible!$"

ChiiTown_EventScript_BattlingBoy_Text_3:
	.string "{CREATE_MUGSHOT MUGSHOT_SCHOOL_KID_M EMOTE_NORMAL}Fine! Go do grownup stuff!$"

ChiiTown_EventScript_Mart_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_CLERK EMOTE_NORMAL}Welcome to Chii Town's market!\p"
	.string "How may I help you?$"

ChiiTown_EventScript_MartDecor_Text_0:
	.string "Decors!$"

ChiiTown_EventScript_Samurai_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_SAMURAI EMOTE_NORMAL}There's been reports of shady men\n"
	.string "dressed in blue loitering around here.\p"
	.string "Be careful when traveling!$"

ChiiTown_EventScript_TownSign_Text_0:
	.string "Chii Town\n"
	.string "“The smallest town, with the biggest\l"
	.string "heart.”$"

ChiiTown_EventScript_SchoolSign_Text_0:
	.string "Little Deerling elementary school$"

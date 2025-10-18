YifuCity_Refuge_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, YifuCity_Refuge_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

YifuCity_Refuge_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setrespawn HEAL_LOCATION_YIFU_CITY
	goto_if_unset FLAG_CLEARED_CROBAT_HIDEOUT, YifuCity_Refuge_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
YifuCity_Refuge_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	getroutechallengestate ROUTE_CHALLENGE_WHITESLATE_YIFU
	compare VAR_RESULT, ROUTE_CHALLENGE_STATE_SUCCESS_CONFIRMED
	goto_if_eq YifuCity_Refuge_MapScripts_MAP_SCRIPT_ON_TRANSITION_5
	compare VAR_RESULT, ROUTE_CHALLENGE_STATE_FAILURE_CONFIRMED
	goto_if_eq YifuCity_Refuge_MapScripts_MAP_SCRIPT_ON_TRANSITION_5
YifuCity_Refuge_MapScripts_MAP_SCRIPT_ON_TRANSITION_4:
	goto_if_set FLAG_DAILY_YIFU_HOTEL_ROOM, YifuCity_Refuge_MapScripts_MAP_SCRIPT_ON_TRANSITION_9
	return

YifuCity_Refuge_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
	setflag FLAG_TEMP_1
	goto YifuCity_Refuge_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

YifuCity_Refuge_MapScripts_MAP_SCRIPT_ON_TRANSITION_5:
	setflag FLAG_TEMP_2
	goto YifuCity_Refuge_MapScripts_MAP_SCRIPT_ON_TRANSITION_4

YifuCity_Refuge_MapScripts_MAP_SCRIPT_ON_TRANSITION_9:
	setobjectxyperm LOCALID_YIFU_REFUGE_VALET, 3, 2
	return


YifuCity_Refuge_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE_YIFU
	setvar VAR_0x800A, LOCALID_CHANSEY_YIFU
	setvar VAR_0x8009, MUGSHOT_UUME_NURSE
	call Common_EventScript_PkmnCenterNurse_CutTheBullshit
	waitmessage
	waitbuttonpress
	release
	end


YifuCity_Refuge_EventScript_Pasture::
	setvar VAR_0x8009, MUGSHOT_UUME_MAN_2
	call Common_EventScript_PcGuy
	release
	end


YifuCity_Refuge_EventScript_FakeNurse::
	setvar VAR_0x800B, 1
	setvar VAR_0x800A, LOCALID_WOOBAT_YIFU
	lock
	faceplayer
	setvar VAR_0x8004, 0
	setspeaker SP_NAME_NURSE
	msgbox YifuCity_Refuge_EventScript_FakeNurse_Text_0
	closemessage
	incrementgamestat GAME_STAT_USED_POKECENTER
	call EventScript_PkmnCenterNurse_TakeAndHealPkmn
	goto_if_set FLAG_GOT_SCAMMED_YIFU_REFUGE, YifuCity_Refuge_EventScript_FakeNurse_2
	setflag FLAG_GOT_SCAMMED_YIFU_REFUGE
	setspeaker SP_NAME_NURSE
	msgbox YifuCity_Refuge_EventScript_FakeNurse_Text_4
	showmoneybox 18, 0
	mcdialogue YifuCity_Refuge_EventScript_FakeNurse_Text_5, YifuCity_Refuge_EventScript_FakeNurse_Text_6, YifuCity_Refuge_EventScript_FakeNurse_Text_7
	closemessage
	switch VAR_RESULT
	case 0, YifuCity_Refuge_EventScript_FakeNurse_9
	case 1, YifuCity_Refuge_EventScript_FakeNurse_9
	case 2, YifuCity_Refuge_EventScript_FakeNurse_10
YifuCity_Refuge_EventScript_FakeNurse_1:
	hidemoneybox
	closemessage
	return

YifuCity_Refuge_EventScript_FakeNurse_2:
	showmoneybox 18, 0
	checkmoney 500
	compare VAR_RESULT, 0
	goto_if_ne YifuCity_Refuge_EventScript_FakeNurse_5
	setspeaker SP_NAME_NURSE
	msgbox YifuCity_Refuge_EventScript_FakeNurse_Text_3
	goto YifuCity_Refuge_EventScript_FakeNurse_1

YifuCity_Refuge_EventScript_FakeNurse_5:
	setspeaker SP_NAME_NURSE
	msgbox YifuCity_Refuge_EventScript_FakeNurse_Text_1
	playse SE_SHOP
	removemoney 500
	updatemoneybox
	setspeaker SP_NAME_NURSE
	msgbox YifuCity_Refuge_EventScript_FakeNurse_Text_2
	goto YifuCity_Refuge_EventScript_FakeNurse_1

YifuCity_Refuge_EventScript_FakeNurse_9:
	checkmoney 500
	compare VAR_RESULT, 0
	goto_if_ne YifuCity_Refuge_EventScript_FakeNurse_11
	setspeaker SP_NAME_NURSE
	msgbox YifuCity_Refuge_EventScript_FakeNurse_Text_9
	goto YifuCity_Refuge_EventScript_FakeNurse_1

YifuCity_Refuge_EventScript_FakeNurse_10:
	checkmoney 500
	compare VAR_RESULT, 0
	goto_if_ne YifuCity_Refuge_EventScript_FakeNurse_14
	setspeaker SP_NAME_NURSE
	msgbox YifuCity_Refuge_EventScript_FakeNurse_Text_11
	applymovement VAR_LAST_TALKED, YifuCity_Refuge_EventScript_FakeNurse_Movement_0
	msgbox YifuCity_Refuge_EventScript_FakeNurse_Text_12
	goto YifuCity_Refuge_EventScript_FakeNurse_1

YifuCity_Refuge_EventScript_FakeNurse_11:
	setspeaker SP_NAME_NURSE
	msgbox YifuCity_Refuge_EventScript_FakeNurse_Text_8
	playse SE_SHOP
	removemoney 500
	updatemoneybox
	setspeaker SP_NAME_NURSE
	msgbox YifuCity_Refuge_EventScript_FakeNurse_Text_2
	goto YifuCity_Refuge_EventScript_FakeNurse_1

YifuCity_Refuge_EventScript_FakeNurse_14:
	setspeaker SP_NAME_NURSE
	msgbox YifuCity_Refuge_EventScript_FakeNurse_Text_10
	playse SE_SHOP
	removemoney 500
	updatemoneybox
	setspeaker SP_NAME_NURSE
	msgbox YifuCity_Refuge_EventScript_FakeNurse_Text_2
	goto YifuCity_Refuge_EventScript_FakeNurse_1


YifuCity_Refuge_EventScript_Woobat::
	lock
	setseenmon SPECIES_WOOBAT
	playmoncry SPECIES_WOOBAT, CRY_MODE_NORMAL
	setspeaker YifuCity_Refuge_EventScript_Woobat_Text_0
	msgbox YifuCity_Refuge_EventScript_Woobat_Text_1
	waitse
	closemessage
	release
	return


YifuCity_Refuge_EventScript_Shamisen::
	lock
	faceplayer
	setspeaker SP_NAME_SHAMISEN_PLAYER
	msgbox YifuCity_Refuge_EventScript_Shamisen_Text_0
	closemessage
	release
	end


YifuCity_Refuge_EventScript_ShamisensPokemon::
	lock
	faceplayer
	setseenmon SPECIES_TOXEL_TOKUAN
	setspeakertomonname SPECIES_TOXEL_TOKUAN
	playmoncry SPECIES_TOXEL_TOKUAN, CRY_MODE_NORMAL
	msgbox YifuCity_Refuge_EventScript_ShamisensPokemon_Text_0
	closemessage
	release
	end


YifuCity_Refuge_EventScript_HotelValet::
	lock
	faceplayer
	special GetPlayerSirMissString
	goto_if_set FLAG_DAILY_YIFU_HOTEL_ROOM, YifuCity_Refuge_EventScript_HotelValet_2
	setspeaker SP_NAME_VALET
	msgbox YifuCity_Refuge_EventScript_HotelValet_Text_1
	showmoneybox 18, 0
	checkmoney 500
	compare VAR_RESULT, 0
	goto_if_ne YifuCity_Refuge_EventScript_HotelValet_5
	mcdialogue YifuCity_Refuge_EventScript_HotelValet_Text_7
	closemessage
	hidemoneybox
	setspeaker SP_NAME_VALET
	msgbox YifuCity_Refuge_EventScript_HotelValet_Text_8
	closemessage
YifuCity_Refuge_EventScript_HotelValet_1:
	release
	return

YifuCity_Refuge_EventScript_HotelValet_2:
	setspeaker SP_NAME_VALET
	msgbox YifuCity_Refuge_EventScript_HotelValet_Text_0
	closemessage
	goto YifuCity_Refuge_EventScript_HotelValet_1

YifuCity_Refuge_EventScript_HotelValet_5:
	mcdialogue YifuCity_Refuge_EventScript_HotelValet_Text_2, YifuCity_Refuge_EventScript_HotelValet_Text_3
	closemessage
	switch VAR_RESULT
	case 0, YifuCity_Refuge_EventScript_HotelValet_9
	case 1, YifuCity_Refuge_EventScript_HotelValet_10
	goto YifuCity_Refuge_EventScript_HotelValet_1

YifuCity_Refuge_EventScript_HotelValet_9:
	setspeaker SP_NAME_VALET
	msgbox YifuCity_Refuge_EventScript_HotelValet_Text_4
	playse SE_SHOP
	removemoney 500
	updatemoneybox
	hidemoneybox
	setspeaker SP_NAME_VALET
	msgbox YifuCity_Refuge_EventScript_HotelValet_Text_5
	closemessage
	compare VAR_FACING, DIR_WEST
	goto_if_eq YifuCity_Refuge_EventScript_HotelValet_12
	applymovement VAR_LAST_TALKED, YifuCity_Refuge_EventScript_HotelValet_Movement_1
YifuCity_Refuge_EventScript_HotelValet_11:
	waitmovement 0
	setflag FLAG_DAILY_YIFU_HOTEL_ROOM
	goto YifuCity_Refuge_EventScript_HotelValet_1

YifuCity_Refuge_EventScript_HotelValet_10:
	hidemoneybox
	setspeaker SP_NAME_VALET
	msgbox YifuCity_Refuge_EventScript_HotelValet_Text_6
	closemessage
	goto YifuCity_Refuge_EventScript_HotelValet_1

YifuCity_Refuge_EventScript_HotelValet_12:
	applymovement VAR_LAST_TALKED, YifuCity_Refuge_EventScript_HotelValet_Movement_0
	goto YifuCity_Refuge_EventScript_HotelValet_11


YifuCity_Refuge_EventScript_FakeValet::
	lock
	faceplayer
	setspeaker SP_NAME_ZUBAT_GRUNT
	msgbox YifuCity_Refuge_EventScript_FakeValet_Text_0
	closemessage
	setnamedmon SPECIES_PAWNIARD
	setdescribedmon SPECIES_PAWNIARD
	release
	end


YifuCity_Refuge_EventScript_ListenToShamisen::
	lock
	faceplayer
	setspeaker SP_NAME_BOY
	applymovement VAR_LAST_TALKED, YifuCity_Refuge_EventScript_ListenToShamisen_Movement_0
	msgbox YifuCity_Refuge_EventScript_ListenToShamisen_Text_0
	closemessage
	release
	end


YifuCity_Refuge_EventScript_OldMan::
	lock
	faceplayer
	setspeaker SP_NAME_OLD_MAN
	msgbox YifuCity_Refuge_EventScript_OldMan_Text_0
	closemessage
	release
	end


YifuCity_Refuge_EventScript_Traveler::
	lock
	faceplayer
	setspeaker SP_NAME_TRAVELER
	msgbox YifuCity_Refuge_EventScript_Traveler_Text_0
	closemessage
	setnamedmon SPECIES_PAWNIARD
	setdescribedmon SPECIES_PAWNIARD
	release
	end


YifuCity_Refuge_EventScript_Bisharp::
	lock
	faceplayer
	setseenmon SPECIES_PAWNIARD
	playmoncry SPECIES_PAWNIARD, CRY_MODE_NORMAL
	setspeakertomonname SPECIES_PAWNIARD
	msgbox YifuCity_Refuge_EventScript_Bisharp_Text_0
	waitmoncry
	closemessage
	release
	return


YifuCity_Refuge_EventScript_Samurai::
	lock
	faceplayer
	applymovement VAR_LAST_TALKED, YifuCity_Refuge_EventScript_Samurai_Movement_0
	setspeaker SP_NAME_SAMURAI
	msgbox YifuCity_Refuge_EventScript_Samurai_Text_0
	closemessage
	release
	end


YifuCity_Refuge_EventScript_GotTrashedByDojo::
	lock
	faceplayer
	applymovement VAR_LAST_TALKED, YifuCity_Refuge_EventScript_ListenToShamisen_Movement_0
	setspeaker SP_NAME_MAN
	msgbox YifuCity_Refuge_EventScript_GotTrashedByDojo_Text_0
	closemessage
	release
	end


YifuCity_Refuge_EventScript_RouteShamisensPokemon::
	lock
	setseenmon SPECIES_GROWLITHE
	playmoncry SPECIES_GROWLITHE, CRY_MODE_NORMAL
	setspeakertomonname SPECIES_GROWLITHE
	msgbox YifuCity_Refuge_EventScript_RouteShamisensPokemon_Text_0
	waitse
	closemessage
	release
	return


YifuCity_Refuge_EventScript_RouteShamisen::
	lock
	faceplayer
	getroutechallengestate ROUTE_CHALLENGE_WHITESLATE_YIFU
	switch VAR_RESULT
	case ROUTE_CHALLENGE_STATE_STARTED, YifuCity_Refuge_EventScript_RouteShamisen_3
	case ROUTE_CHALLENGE_STATE_SUCCESS, YifuCity_Refuge_EventScript_RouteShamisen_3
	case ROUTE_CHALLENGE_STATE_FAILURE, YifuCity_Refuge_EventScript_RouteShamisen_4
YifuCity_Refuge_EventScript_RouteShamisen_1:
	closemessage
	release
	end

YifuCity_Refuge_EventScript_RouteShamisen_3:
	goto_if_set FLAG_TEMP_3, YifuCity_Refuge_EventScript_RouteShamisen_6
	setflag FLAG_TEMP_3
	setspeaker SP_NAME_SHAMISEN_PLAYER
	msgbox YifuCity_Refuge_EventScript_RouteShamisen_Text_1
YifuCity_Refuge_EventScript_RouteShamisen_5:
	mcdialogue YifuCity_Refuge_EventScript_RouteShamisen_Text_2, YifuCity_Refuge_EventScript_RouteShamisen_Text_3, YifuCity_Refuge_EventScript_RouteShamisen_Text_4
	closemessage
	specialvar VAR_0x8000, GetPlayerTrainerIdOnesDigit
	switch VAR_RESULT
	case 0, YifuCity_Refuge_EventScript_RouteShamisen_15
	case 1, YifuCity_Refuge_EventScript_RouteShamisen_16
	case 2, YifuCity_Refuge_EventScript_RouteShamisen_17
YifuCity_Refuge_EventScript_RouteShamisen_13:
	getpartysize
	compare VAR_RESULT, PARTY_SIZE
	goto_if_lt YifuCity_Refuge_EventScript_RouteShamisen_18
	setspeaker SP_NAME_SHAMISEN_PLAYER
	msgbox YifuCity_Refuge_EventScript_RouteShamisen_Text_7
	closemessage
	goto YifuCity_Refuge_EventScript_RouteShamisen_1

YifuCity_Refuge_EventScript_RouteShamisen_4:
	applymovement VAR_LAST_TALKED, YifuCity_Refuge_EventScript_Samurai_Movement_0
	setspeaker SP_NAME_SHAMISEN_PLAYER
	msgbox YifuCity_Refuge_EventScript_RouteShamisen_Text_8
	mcdialogue YifuCity_Refuge_EventScript_RouteShamisen_Text_9, YifuCity_Refuge_EventScript_RouteShamisen_Text_10
	switch VAR_RESULT
	case 0, YifuCity_Refuge_EventScript_RouteShamisen_11
	case 1, YifuCity_Refuge_EventScript_RouteShamisen_12
YifuCity_Refuge_EventScript_RouteShamisen_9:
	call YifuCity_Refuge_EventScript_RouteShamisenLeaves
	setroutechallengestate ROUTE_CHALLENGE_WHITESLATE_YIFU, ROUTE_CHALLENGE_STATE_FAILURE_CONFIRMED
	goto YifuCity_Refuge_EventScript_RouteShamisen_1

YifuCity_Refuge_EventScript_RouteShamisen_6:
	setspeaker SP_NAME_SHAMISEN_PLAYER
	msgbox YifuCity_Refuge_EventScript_RouteShamisen_Text_0
	goto YifuCity_Refuge_EventScript_RouteShamisen_5

YifuCity_Refuge_EventScript_RouteShamisen_11:
	applymovement VAR_LAST_TALKED, YifuCity_Refuge_EventScript_Samurai_Movement_0
	setspeaker SP_NAME_SHAMISEN_PLAYER
	msgbox YifuCity_Refuge_EventScript_RouteShamisen_Text_11
	closemessage
	setflag FLAG_LIED_TO_SHAMISEN_PLAYER
	goto YifuCity_Refuge_EventScript_RouteShamisen_9

YifuCity_Refuge_EventScript_RouteShamisen_12:
	applymovement VAR_LAST_TALKED, YifuCity_Refuge_EventScript_RouteShamisen_Movement_0
	setspeaker SP_NAME_SHAMISEN_PLAYER
	msgbox YifuCity_Refuge_EventScript_RouteShamisen_Text_12
	giveitem ITEM_SUPERGIRI, 3
	setspeaker SP_NAME_SHAMISEN_PLAYER
	msgbox YifuCity_Refuge_EventScript_RouteShamisen_Text_13
	closemessage
	goto YifuCity_Refuge_EventScript_RouteShamisen_9

YifuCity_Refuge_EventScript_RouteShamisen_15:
	compare VAR_0x8000, 4
	goto_if_le YifuCity_Refuge_EventScript_RouteShamisen_21
	setvar VAR_TEMP_0, SPECIES_TORCHIC
	goto YifuCity_Refuge_EventScript_RouteShamisen_13

YifuCity_Refuge_EventScript_RouteShamisen_16:
	compare VAR_0x8000, 4
	goto_if_le YifuCity_Refuge_EventScript_RouteShamisen_24
	setvar VAR_TEMP_0, SPECIES_OSHAWOTT
	goto YifuCity_Refuge_EventScript_RouteShamisen_13

YifuCity_Refuge_EventScript_RouteShamisen_17:
	compare VAR_0x8000, 4
	goto_if_le YifuCity_Refuge_EventScript_RouteShamisen_27
	setvar VAR_TEMP_0, SPECIES_BULBASAUR
	goto YifuCity_Refuge_EventScript_RouteShamisen_13

YifuCity_Refuge_EventScript_RouteShamisen_18:
	playfanfare MUS_OBTAIN_ITEM
	message YifuCity_Refuge_EventScript_RouteShamisen_Text_5
	waitfanfare
	giveegg VAR_TEMP_0
	setspeaker SP_NAME_SHAMISEN_PLAYER
	msgbox YifuCity_Refuge_EventScript_RouteShamisen_Text_6
	closemessage
	call YifuCity_Refuge_EventScript_RouteShamisenLeaves
	setroutechallengestate ROUTE_CHALLENGE_WHITESLATE_YIFU, ROUTE_CHALLENGE_STATE_SUCCESS_CONFIRMED
	goto YifuCity_Refuge_EventScript_RouteShamisen_1

YifuCity_Refuge_EventScript_RouteShamisen_21:
	setvar VAR_TEMP_0, SPECIES_CHIMCHAR
	goto YifuCity_Refuge_EventScript_RouteShamisen_13

YifuCity_Refuge_EventScript_RouteShamisen_24:
	setvar VAR_TEMP_0, SPECIES_TOTODILE
	goto YifuCity_Refuge_EventScript_RouteShamisen_13

YifuCity_Refuge_EventScript_RouteShamisen_27:
	setvar VAR_TEMP_0, SPECIES_CHIKORITA
	goto YifuCity_Refuge_EventScript_RouteShamisen_13


YifuCity_Refuge_EventScript_RouteShamisenLeaves::
	switch VAR_FACING
	case DIR_EAST, YifuCity_Refuge_EventScript_RouteShamisenLeaves_3
	applymovement VAR_LAST_TALKED, YifuCity_Refuge_EventScript_RouteShamisenLeaves_Movement_2
	applymovement 17, YifuCity_Refuge_EventScript_RouteShamisenLeaves_Movement_0
YifuCity_Refuge_EventScript_RouteShamisenLeaves_1:
	delay 24
	applymovement OBJ_EVENT_ID_PLAYER, YifuCity_Refuge_EventScript_RouteShamisenLeaves_Movement_3
	waitmovement VAR_LAST_TALKED
	playse SE_EXIT
	removeobject VAR_LAST_TALKED
	waitse
	switch VAR_FACING
	case DIR_EAST, YifuCity_Refuge_EventScript_RouteShamisenLeaves_7
	applymovement 17, YifuCity_Refuge_EventScript_RouteShamisenLeaves_Movement_5
YifuCity_Refuge_EventScript_RouteShamisenLeaves_5:
	waitmovement 17
	playse SE_EXIT
	removeobject 17
	waitse
	setflag FLAG_TEMP_2
	return

YifuCity_Refuge_EventScript_RouteShamisenLeaves_3:
	applymovement VAR_LAST_TALKED, YifuCity_Refuge_EventScript_RouteShamisenLeaves_Movement_0
	applymovement 17, YifuCity_Refuge_EventScript_RouteShamisenLeaves_Movement_1
	goto YifuCity_Refuge_EventScript_RouteShamisenLeaves_1

YifuCity_Refuge_EventScript_RouteShamisenLeaves_7:
	applymovement 17, YifuCity_Refuge_EventScript_RouteShamisenLeaves_Movement_4
	goto YifuCity_Refuge_EventScript_RouteShamisenLeaves_5


YifuCity_Refuge_EventScript_FakeNurse_Movement_0:
	emote_angry
	step_end

YifuCity_Refuge_EventScript_HotelValet_Movement_0:
	walk_down
	face_right
	step_end

YifuCity_Refuge_EventScript_HotelValet_Movement_1:
	walk_right
	face_down
	step_end

YifuCity_Refuge_EventScript_ListenToShamisen_Movement_0:
	emote_sweat
	step_end

YifuCity_Refuge_EventScript_Samurai_Movement_0:
	emote_pensive
	step_end

YifuCity_Refuge_EventScript_RouteShamisen_Movement_0:
	emote_happy
	step_end

YifuCity_Refuge_EventScript_RouteShamisenLeaves_Movement_0:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	face_down
	step_end

YifuCity_Refuge_EventScript_RouteShamisenLeaves_Movement_1:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

YifuCity_Refuge_EventScript_RouteShamisenLeaves_Movement_2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

YifuCity_Refuge_EventScript_RouteShamisenLeaves_Movement_3:
	walk_in_place_fast_left
	step_end

YifuCity_Refuge_EventScript_RouteShamisenLeaves_Movement_4:
	walk_left
	face_down
	step_end

YifuCity_Refuge_EventScript_RouteShamisenLeaves_Movement_5:
	walk_down
	step_end

YifuCity_Refuge_EventScript_FakeNurse_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_ZUBAT EMOTE_NORMAL}Gimme yer Pokémon, I'mma heal 'em\n"
	.string "good.$"

YifuCity_Refuge_EventScript_FakeNurse_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_ZUBAT EMOTE_NORMAL}Yep, uh, good as new, probably!\p"
	.string "Ya know the drill, ¥500 please!$"

YifuCity_Refuge_EventScript_FakeNurse_Text_2:
	.string "{CREATE_MUGSHOT MUGSHOT_ZUBAT EMOTE_NORMAL}C'magain, or whatever.$"

YifuCity_Refuge_EventScript_FakeNurse_Text_3:
	.string "{CREATE_MUGSHOT MUGSHOT_ZUBAT EMOTE_NORMAL}Yep, uh, good as new, probably!\p"
	.string "Ya know the drill, ¥500 please!\p"
	.string "… … …\n"
	.string "… … …What? Yer THAT poor?\p"
	.string "I feel almost bad for ya, buddy…\p"
	.string "I guess, uh… I guess we're good then,\n"
	.string "don' worry 'bout it.\p"
	.string "Now make like a Treecko 'n leave!$"

YifuCity_Refuge_EventScript_FakeNurse_Text_4:
	.string "{CREATE_MUGSHOT MUGSHOT_ZUBAT EMOTE_NORMAL}Yep, uh, good as new, probably!\p"
	.string "By the way, that'll be ¥500, wow, so\n"
	.string "cheap!$"

YifuCity_Refuge_EventScript_FakeNurse_Text_5:
	.string "What?!$"

YifuCity_Refuge_EventScript_FakeNurse_Text_6:
	.string "No way!$"

YifuCity_Refuge_EventScript_FakeNurse_Text_7:
	.string "Okay, I guess…$"

YifuCity_Refuge_EventScript_FakeNurse_Text_8:
	.string "{CREATE_MUGSHOT MUGSHOT_ZUBAT EMOTE_NORMAL}No whinin'! Fork over the cash before\n"
	.string "I call security!$"

YifuCity_Refuge_EventScript_FakeNurse_Text_9:
	.string "{CREATE_MUGSHOT MUGSHOT_ZUBAT EMOTE_NORMAL}No whinin'! Fork over the cash before\n"
	.string "I call security!\p"
	.string "… … …\n"
	.string "… … …What? Yer THAT poor?\p"
	.string "I feel almost bad for ya, buddy…\p"
	.string "I guess, uh… I guess we're good then,\n"
	.string "don' worry 'bout it.\p"
	.string "Now make like a Treecko 'n leave!$"

YifuCity_Refuge_EventScript_FakeNurse_Text_10:
	.string "{CREATE_MUGSHOT MUGSHOT_ZUBAT EMOTE_NORMAL}…Really? Jus' like that?\p"
	.string "(Wow, this one's really dumb, huh?)\p"
	.string "I mean, yeah, you better!$"

YifuCity_Refuge_EventScript_FakeNurse_Text_11:
	.string "{CREATE_MUGSHOT MUGSHOT_ZUBAT EMOTE_NORMAL}…Really? Jus' like that?\p"
	.string "(Wow, this one's really dumb, huh?)\p"
	.string "… … …\n"
	.string "… … …What? Ya don't have 'nuff cash?!\p"
	.string "I can't believe it! I've been had!$"

YifuCity_Refuge_EventScript_FakeNurse_Text_12:
	.string "Get outta here, ya scammer!$"

YifuCity_Refuge_EventScript_Woobat_Text_0:
	.string "Chansey?$"

YifuCity_Refuge_EventScript_Woobat_Text_1:
	.string "Rrrrr!$"

YifuCity_Refuge_EventScript_Shamisen_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_SHAMISEN_BLUE EMOTE_NORMAL}Good evening, traveler.\p"
	.string "I hope my song will soothe your spirit,\n"
	.string "should it be troubled.$"

YifuCity_Refuge_EventScript_ShamisensPokemon_Text_0:
	.string "Mrrrp…$"

YifuCity_Refuge_EventScript_HotelValet_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_UUME_VALET} Enjoy your stay, {STR_VAR_1}!\n"
	.string "Room one is yours for the day!$"

YifuCity_Refuge_EventScript_HotelValet_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_UUME_VALET} Good day, {STR_VAR_1}!\n"
	.string "A room is available for ¥500, if you\l"
	.string "need a place to spend the night!$"

YifuCity_Refuge_EventScript_HotelValet_Text_2:
	.string "One room, please.$"

YifuCity_Refuge_EventScript_HotelValet_Text_3:
	.string "No, thanks.$"

YifuCity_Refuge_EventScript_HotelValet_Text_4:
	.string "{CREATE_MUGSHOT MUGSHOT_UUME_VALET} For sure. That'll be ¥500!$"

YifuCity_Refuge_EventScript_HotelValet_Text_5:
	.string "{CREATE_MUGSHOT MUGSHOT_UUME_VALET} Your room is the first one down the\n"
	.string "corridor!\l"
	.string "We hope you have a pleasant stay!$"

YifuCity_Refuge_EventScript_HotelValet_Text_6:
	.string "{CREATE_MUGSHOT MUGSHOT_UUME_VALET} Have a nice day!$"

YifuCity_Refuge_EventScript_HotelValet_Text_7:
	.string "I'm poor…$"

YifuCity_Refuge_EventScript_HotelValet_Text_8:
	.string "{CREATE_MUGSHOT MUGSHOT_UUME_VALET} Goodness, it appears you don't have\n"
	.string "enough money…\l"
	.string "I'm sorry!$"

YifuCity_Refuge_EventScript_FakeValet_Text_0:
	.string "Would you be so kind as to piss right\n"
	.string "off, please?$"

YifuCity_Refuge_EventScript_ListenToShamisen_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_BOY_2 EMOTE_NORMAL}Whew… I've walked all day…\n"
	.string "I am spent!$"

YifuCity_Refuge_EventScript_OldMan_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_UUME_OLD_MAN EMOTE_NORMAL}I'm just resting my old bones by the\n"
	.string "fire.\p"
	.string "How the years go by swiftly…\n"
	.string "Do treasure each passing day…$"

YifuCity_Refuge_EventScript_Traveler_Text_0:
	.string "I come from a place high up in the\n"
	.string "mountains, where the Pokémon are as\l"
	.string "tough as the rocky landscape.\p"
	.string "My Pawniard hones its claws on the\n"
	.string "hardest stones to keep them sharp.$"

YifuCity_Refuge_EventScript_Bisharp_Text_0:
	.string "Kshhh.$"

YifuCity_Refuge_EventScript_Samurai_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_SAMURAI EMOTE_NORMAL}The Crobat Shadows must be operating\n"
	.string "from somewhere… But where?$"

YifuCity_Refuge_EventScript_GotTrashedByDojo_Text_0:
	.string "Arrgh… this city's Dojo is all girls, so\n"
	.string "I thought it was going to be super\l"
	.string "easy…\p"
	.string "I got obliterated…$"

YifuCity_Refuge_EventScript_RouteShamisensPokemon_Text_0:
	.string "Rr-ruff!$"

YifuCity_Refuge_EventScript_RouteShamisen_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_SHAMISEN_RED EMOTE_NORMAL}Ah, so have you made space in your\n"
	.string "party for the Egg I wanted to give\l"
	.string "you?\p"
	.string "Which of these Eggs do you favor?$"

YifuCity_Refuge_EventScript_RouteShamisen_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_SHAMISEN_RED EMOTE_NORMAL}Hello, traveler.\n"
	.string "… … …\l"
	.string "… … …!\p"
	.string "Oh, I recognize you! You're that\n"
	.string "promising young Wielder I met on\l"
	.string "Whiteslate Route!\p"
	.string "… …Yes, I feel it…\p"
	.string "You managed to traverse the whole\n"
	.string "Route, triumphing of both Wielders\l"
	.string "and wild Pokémon, relying on your\l"
	.string "Wielding skills and medicine…\p"
	.string "Congratulations, um… {FONT_SMALL}What did you say\n"
	.string "your name was?{FONT_NORMAL}\p"
	.string "Congratulations, {PLAYER}!\n"
	.string "As I expected, you have proved\l"
	.string "worthy of our songs!\p"
	.string "I carry some Pokémon Eggs right this\n"
	.string "moment. I want you to have one, I know\l"
	.string "it would be in good hands.\p"
	.string "Which of these Eggs do you favor?$"

YifuCity_Refuge_EventScript_RouteShamisen_Text_2:
	.string "The warm Egg!$"

YifuCity_Refuge_EventScript_RouteShamisen_Text_3:
	.string "The wet Egg!$"

YifuCity_Refuge_EventScript_RouteShamisen_Text_4:
	.string "The mossy Egg!$"

YifuCity_Refuge_EventScript_RouteShamisen_Text_5:
	.string "{PLAYER} received the mysterious\n"
	.string "Egg.$"

YifuCity_Refuge_EventScript_RouteShamisen_Text_6:
	.string "{CREATE_MUGSHOT MUGSHOT_SHAMISEN_RED EMOTE_NORMAL}Please take good care of this Egg.\p"
	.string "May destiny cross our paths again!$"

YifuCity_Refuge_EventScript_RouteShamisen_Text_7:
	.string "{CREATE_MUGSHOT MUGSHOT_SHAMISEN_RED EMOTE_NORMAL}Oh, but wait, you don't have enough\n"
	.string "room for the Egg!\p"
	.string "I'll wait for you to make some.$"

YifuCity_Refuge_EventScript_RouteShamisen_Text_8:
	.string "{CREATE_MUGSHOT MUGSHOT_SHAMISEN_RED EMOTE_NORMAL}Hello, traveler.\n"
	.string "… … …\l"
	.string "… … …!\p"
	.string "Oh, I recognize you! You're that\n"
	.string "promising young Wielder I met on\l"
	.string "Whiteslate Route!\p"
	.string "{PLAYER}? It's nice to meet you\n"
	.string "again.\p"
	.string "Tell me honestly, {PLAYER}… Did you\n"
	.string "manage to traverse Whiteslate Route\l"
	.string "without resorting to the services of\l"
	.string "a Pokémon Refuge?$"

YifuCity_Refuge_EventScript_RouteShamisen_Text_9:
	.string "I did!$"

YifuCity_Refuge_EventScript_RouteShamisen_Text_10:
	.string "I didn't…$"

YifuCity_Refuge_EventScript_RouteShamisen_Text_11:
	.string "{CREATE_MUGSHOT MUGSHOT_SHAMISEN_RED EMOTE_NORMAL}Hmmmm… … …\n"
	.string "… … …\p"
	.string "You aren't telling the truth, are you?\n"
	.string "You're deceiving yourself, do you not\l"
	.string "feel it in your heart?\p"
	.string "Don't be too sad about not\n"
	.string "succeeding. Honesty beats pride, and\l"
	.string "you will get other opportunities to\l"
	.string "prove yourself in the future!\p"
	.string "Rest here a while, and prepare well for\n"
	.string "your next journey!$"

YifuCity_Refuge_EventScript_RouteShamisen_Text_12:
	.string "{CREATE_MUGSHOT MUGSHOT_SHAMISEN_RED EMOTE_NORMAL}Oh, that's alright! Don't beat\n"
	.string "yourself up. I see in your heart that\l"
	.string "you have a bright future ahead of\l"
	.string "you.\p"
	.string "Honesty beats pride, and you will get\n"
	.string "other opportunities to prove\l"
	.string "yourself in the future!\p"
	.string "Rest here a while, and use these to\n"
	.string "prepare for your next journey!$"

YifuCity_Refuge_EventScript_RouteShamisen_Text_13:
	.string "{CREATE_MUGSHOT MUGSHOT_SHAMISEN_RED EMOTE_NORMAL}May destiny cross our paths again!$"

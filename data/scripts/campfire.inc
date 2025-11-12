EventScript_Campfire::
	lock
	goto_if_set FLAG_HIDE_CAMPFIRE_PARTY_MON_1, EventScript_Campfire_2
	msgbox EventScript_Campfire_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EventScript_Campfire_7
EventScript_Campfire_1:
	release
	return

EventScript_Campfire_2:
	msgbox EventScript_Campfire_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EventScript_Campfire_5
	goto EventScript_Campfire_1

EventScript_Campfire_5:
	campfire
	goto EventScript_Campfire_1

EventScript_Campfire_7:
	call EventScript_LeaveCampfire
	goto EventScript_Campfire_1


EventScript_WalkAwayFromCampfire::
	lock
	msgbox EventScript_Campfire_Text_1, MSGBOX_YESNO
	closemessage
	compare VAR_RESULT, YES
	goto_if_eq EventScript_WalkAwayFromCampfire_2
	specialvar VAR_RESULT, GetPlayerFacingDirection
	buffernumberstring STR_VAR_1, VAR_RESULT
	switch VAR_RESULT
	case DIR_NORTH, EventScript_WalkAwayFromCampfire_7
	case DIR_SOUTH, EventScript_WalkAwayFromCampfire_8
	case DIR_EAST, EventScript_WalkAwayFromCampfire_9
	case DIR_WEST, EventScript_WalkAwayFromCampfire_10
EventScript_WalkAwayFromCampfire_5:
	waitmovement 0
EventScript_WalkAwayFromCampfire_1:
	release
	return

EventScript_WalkAwayFromCampfire_2:
	call EventScript_LeaveCampfire
	goto EventScript_WalkAwayFromCampfire_1

EventScript_WalkAwayFromCampfire_7:
	applymovement OBJ_EVENT_ID_PLAYER, Movement_ComeBackToCampfire_Down
	goto EventScript_WalkAwayFromCampfire_5

EventScript_WalkAwayFromCampfire_8:
	applymovement OBJ_EVENT_ID_PLAYER, Movement_ComeBackToCampfire_Up
	goto EventScript_WalkAwayFromCampfire_5

EventScript_WalkAwayFromCampfire_9:
	applymovement OBJ_EVENT_ID_PLAYER, Movement_ComeBackToCampfire_Left
	goto EventScript_WalkAwayFromCampfire_5

EventScript_WalkAwayFromCampfire_10:
	applymovement OBJ_EVENT_ID_PLAYER, Movement_ComeBackToCampfire_Right
	goto EventScript_WalkAwayFromCampfire_5


Movement_ComeBackToCampfire_Down:
	walk_down
	step_end

Movement_ComeBackToCampfire_Up:
	walk_up
	step_end

Movement_ComeBackToCampfire_Left:
	walk_left
	step_end

Movement_ComeBackToCampfire_Right:
	walk_right
	step_end

EventScript_LeaveCampfire::
	msgbox EventScript_LeaveCampfire_Text_0
	closemessage
	fadescreen FADE_TO_BLACK
	leaveCampfire
	fadescreen FADE_FROM_BLACK
	return


EventScript_PokemonGaveYouAnItem::
	msgbox EventScript_PokemonGaveYouAnItem_Text_0, MSGBOX_DEFAULT
	giveitem 0x1
	release
	end


EventScript_OldForagingBloke::
	msgbox EventScript_OldForagingBloke_Text_0, MSGBOX_DEFAULT
	giveitem ITEM_PECHA_BERRY
	clearCampfireEventHere
	delay 20
	campfire
	return


EventScript_PokemonHandsYouAnOran::
	msgbox EventScript_PokemonHandsYouAnOran_Text_0, MSGBOX_DEFAULT
	giveitem ITEM_ORAN_BERRY
	clearCampfireEventHere
	delay 20
	campfire
	return


EventScript_CamperWantsToBattle::
	msgbox EventScript_CamperWantsToBattle_Text_0, MSGBOX_YESNO
	clearCampfireEventHere
	delay 20
	campfire
	return


EventScript_PokemonWantsToBattle::
	msgbox EventScript_PokemonWantsToBattle_Text_0, MSGBOX_YESNO
	clearCampfireEventHere
	delay 20
	campfire
	return



EventScript_CampfirePokemon1::
    getcampfireaction 0
    end

EventScript_CampfirePokemon2::
    getcampfireaction 1
    end

EventScript_CampfirePokemon3::
    getcampfireaction 2
    end

EventScript_CampfirePokemon4::
    getcampfireaction 3
    end

EventScript_CampfirePokemon5::
    getcampfireaction 4
    end

EventScript_CampfirePokemon6::
    getcampfireaction 5
    end

EventScript_CampfireGeneric::
	faceplayer
EventScript_CampfireGenericSkipFace:
	waitfieldeffect FLDEFF_EMOTE
	message 0x0
	waitmessage
	waitbuttonpress
    closemessage
	return 

EventScript_CampfireFaceUp::
	applymovement OBJ_EVENT_ID_FOLLOWER Common_Movement_FaceUp
	waitmovement OBJ_EVENT_ID_FOLLOWER
	goto EventScript_FollowerGenericSkipFace

EventScript_CampfireIsShivering::
	faceplayer
	compare VAR_FACING, DIR_NORTH
	call_if_eq ShiverVertical
	compare VAR_FACING, DIR_SOUTH
	call_if_eq ShiverVertical
	compare VAR_FACING, DIR_WEST
	call_if_eq ShiverHorizontal
	compare VAR_FACING, DIR_EAST
	call_if_eq ShiverHorizontal
	goto EventScript_CampfireGeneric

EventScript_CampfireNostalgia::
	applymovement VAR_LAST_TALKED, FollowerNostalgiaMovement
	waitmovement VAR_LAST_TALKED
	goto EventScript_CampfireGeneric

EventScript_CampfireHopping::
	faceplayer
	applymovement VAR_LAST_TALKED, FollowerSkippingMovement
	waitmovement VAR_LAST_TALKED
	goto EventScript_CampfireGeneric

EventScript_CampfireCuddling:: @ similar to Std_MsgboxDefault
	faceplayer
	compare VAR_FACING, DIR_NORTH
	call_if_eq CuddleS
	compare VAR_FACING, DIR_SOUTH
	call_if_eq CuddleN
	compare VAR_FACING, DIR_WEST
	call_if_eq CuddleE
	compare VAR_FACING, DIR_EAST
	call_if_eq CuddleW
	goto EventScript_CampfireGeneric

EventScript_CampfireGetCloser::
	faceplayer
	compare VAR_FACING, DIR_NORTH
	call_if_eq CreepCloserS
	compare VAR_FACING, DIR_SOUTH
	call_if_eq CreepCloserN
	compare VAR_FACING, DIR_WEST
	call_if_eq CreepCloserE
	compare VAR_FACING, DIR_EAST
	call_if_eq CreepCloserW
	goto EventScript_CampfireGeneric

EventScript_CampfirePokingPlayer::
	faceplayer
	compare VAR_FACING, DIR_NORTH
	call_if_eq PokePlayerS
	compare VAR_FACING, DIR_SOUTH
	call_if_eq PokePlayerN
	compare VAR_FACING, DIR_WEST
	call_if_eq PokePlayerE
	compare VAR_FACING, DIR_EAST
	call_if_eq PokePlayerW
	goto EventScript_CampfireGeneric

EventScript_CampfireLookAround::
	applymovement VAR_LAST_TALKED FollowerLookAround
	waitmovement VAR_LAST_TALKED
	goto EventScript_CampfireGeneric

EventScript_CampfireLookAway::
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerLookAway
	waitmovement OBJ_EVENT_ID_FOLLOWER
	goto EventScript_FollowerGenericSkipFace

EventScript_CampfireLookAwayBark::
	applymovement VAR_LAST_TALKED FollowerLookAwayBark
	waitmovement VAR_LAST_TALKED
	goto EventScript_CampfireGenericSkipFace

EventScript_CampfirePokeGround::
	faceplayer
	applymovement VAR_LAST_TALKED FollowerPokeGround
	waitmovement VAR_LAST_TALKED
	goto EventScript_CampfireGeneric

EventScript_CampfireFastHopping::
	applymovement VAR_LAST_TALKED FollowerHopFast
	waitmovement VAR_LAST_TALKED
	goto EventScript_CampfireGenericSkipFace

EventScript_CampfireDizzy::
	applymovement VAR_LAST_TALKED FollowerDizzy
	waitmovement 0
	goto EventScript_CampfireGenericSkipFace

EventScript_CampfireDance::
	faceplayer
	applymovement VAR_LAST_TALKED FollowerDance
	waitmovement 0
	goto EventScript_CampfireGenericSkipFace

EventScript_CampfireFaceResult:: @ Face towards direction in VAR_RESULT
	switch VAR_RESULT
	case DIR_SOUTH, EventScript_FollowerFaceDown
	case DIR_NORTH, EventScript_FollowerFaceUp
	case DIR_WEST, EventScript_FollowerFaceLeft
	case DIR_EAST, EventScript_FollowerFaceRight
	goto EventScript_CampfireGeneric

EventScript_Campfire_Text_0:
	.string "Rest at the campfire?$"

EventScript_Campfire_Text_1:
	.string "Leave the campfire?$"

EventScript_LeaveCampfire_Text_0:
	.string "Your Pokémon are well-rested.\n"
	.string "Time to go!$"

EventScript_PokemonGaveYouAnItem_Text_0:
	.string "{STR_VAR_1} handed you an item!$"

EventScript_OldForagingBloke_Text_0:
	.string "I was foraging in the area when I\n"
	.string "noticed you setting up! Please take\l"
	.string "this.$"

EventScript_PokemonHandsYouAnOran_Text_0:
	.string "{STR_VAR_1} scurried up to you\n"
	.string "and handed you an item!$"

EventScript_CamperWantsToBattle_Text_0:
	.string "Hey this is my campfire. Battle me for\n"
	.string "it?$"

EventScript_PokemonWantsToBattle_Text_0:
	.string "{STR_VAR_1} wants to battle!$"

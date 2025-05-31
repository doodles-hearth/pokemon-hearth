YifuCity_House2_MapScripts::
	.byte 0


YifuCity_House2_Seamstress::
	lock
	faceplayer
	speakername YifuCity_House2_Seamstress_Text_0
	msgbox YifuCity_House2_Seamstress_Text_1
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceDown
	waitmovement 0
	speakername YifuCity_House2_Seamstress_Text_0
	msgbox YifuCity_House2_Seamstress_Text_2
	closemessage
	applymovement 3, YifuCity_House2_Seamstress_Movement_0
	waitmovement 0
	release
	return


YifuCity_House2_Model::
	lock
	faceplayer
	goto_if_set FLAG_OBTAINED_CHOICE_SCARF, YifuCity_House2_Model_2
	speakername YifuCity_House2_Model_Text_1
	msgbox YifuCity_House2_Model_Text_2
	closemessage
	giveitem ITEM_CHOICE_SCARF
	setflag FLAG_OBTAINED_CHOICE_SCARF
YifuCity_House2_Model_1:
	release
	return

YifuCity_House2_Model_2:
	msgbox YifuCity_House2_Model_Text_0
	closemessage
	goto YifuCity_House2_Model_1


YifuCity_House2_Tarountula::
	lock
	faceplayer
	setseenmon SPECIES_TAROUNTULA
	playmoncry SPECIES_TAROUNTULA, CRY_MODE_NORMAL
	setspeakertomonname SPECIES_TAROUNTULA
	msgbox YifuCity_House2_Tarountula_Text_0
	waitmoncry
	closemessage
	goto_if_unset FLAG_OBTAINED_DESTINY_KNOT, YifuCity_House2_Tarountula_2
YifuCity_House2_Tarountula_1:
	release
	return

YifuCity_House2_Tarountula_2:
	applymovement 3, YifuCity_House2_Tarountula_Movement_0
	waitmovement 0
	giveitem ITEM_DESTINY_KNOT
	setflag FLAG_OBTAINED_DESTINY_KNOT
	goto YifuCity_House2_Tarountula_1


YifuCity_House2_Seamstress_Movement_0:
	jump_in_place_right
	walk_right
	walk_right
	walk_up
	walk_right
	walk_right
	face_up
	delay_16
	jump_in_place_up
	delay_16
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	step_end

YifuCity_House2_Tarountula_Movement_0:
	lock_facing_direction
	jump_in_place_down
	unlock_facing_direction
	step_end

YifuCity_House2_Seamstress_Text_0:
	.string "Seamstress$"

YifuCity_House2_Seamstress_Text_1:
	.string "I've been working day and night on a\n"
	.string "dress for the Samurai Chief's\l"
	.string "daugther.\p"
	.string "This will be my greatest work!$"

YifuCity_House2_Seamstress_Text_2:
	.string "Tarountula, could you bring me some\n"
	.string "more of that red thread?$"

YifuCity_House2_Model_Text_0:
	.string "That Tarountula creeps me out…\n"
	.string "It has so many legs…$"

YifuCity_House2_Model_Text_1:
	.string "Model$"

YifuCity_House2_Model_Text_2:
	.string "Yawn… Being a model is so tiring! My\n"
	.string "feet hurt from standing here for\l"
	.string "hours…\p"
	.string "I do get some sweet free stuff\n"
	.string "though! Here, you can have this, I\l"
	.string "already have this color!$"

YifuCity_House2_Tarountula_Text_0:
	.string "Thshh!$"

SilverTunnel_2F_MapScripts::
	.byte 0


SilverTunnel_2F_EventScript_Trainer1::
	trainerbattle_double TRAINER_TAMA, SilverTunnel_2F_EventScript_Trainer1_Text_0, SilverTunnel_2F_EventScript_Trainer1_Text_1, SilverTunnel_2F_EventScript_Trainer1_Text_2
	speakername SilverTunnel_2F_EventScript_Trainer1_Text_3
	msgbox SilverTunnel_2F_EventScript_Trainer1_Text_4, MSGBOX_AUTOCLOSE
	end


SilverTunnel_2F_EventScript_Kansaku::
	trainerbattle_single TRAINER_IKUTO, SilverTunnel_2F_EventScript_Kansaku_Text_0, SilverTunnel_2F_EventScript_Kansaku_Text_1
	speakername SilverTunnel_2F_EventScript_Kansaku_Text_2
	msgbox SilverTunnel_2F_EventScript_Kansaku_Text_3, MSGBOX_AUTOCLOSE
	end


SilverTunnel_2F_EventScript_Sandslash::
	lock
	faceplayer
	playmoncry SPECIES_SANDSLASH, CRY_MODE_NORMAL
	speakername SilverTunnel_2F_EventScript_Sandslash_Text_0
	msgbox SilverTunnel_2F_EventScript_Sandslash_Text_1
	waitmoncry
	closemessage
	release
	return


SilverTunnel_2F_EventScript_Miner::
	lock
	faceplayer
	speakername SilverTunnel_2F_EventScript_Miner_Text_0
	msgbox SilverTunnel_2F_EventScript_Miner_Text_1
	closemessage
	turnobject VAR_LAST_TALKED, DIR_EAST
	playmoncry SPECIES_SANDSLASH, CRY_MODE_NORMAL
	applymovement 5, SilverTunnel_2F_EventScript_Miner_Movement_0
	waitmoncry
	waitmovement 0
	release
	return


SilverTunnel_2F_EventScript_Miner_Movement_0:
	jump_in_place_right
	step_end

SilverTunnel_2F_EventScript_Trainer1_Text_0:
	.string "The lack of precious gemstones here\n"
	.string "is disappointing!$"

SilverTunnel_2F_EventScript_Trainer1_Text_1:
	.string "You shine like a diamond!$"

SilverTunnel_2F_EventScript_Trainer1_Text_2:
	.string "My two Pokémon like to fight side by\n"
	.string "side. Come back with at least two\l"
	.string "Pokémon.$"

SilverTunnel_2F_EventScript_Trainer1_Text_3:
	.string "Tama$"

SilverTunnel_2F_EventScript_Trainer1_Text_4:
	.string "I came here all the way from Saberside\n"
	.string "Town looking for precious gemstones.\p"
	.string "But there's only sad, grey rocks here…$"

SilverTunnel_2F_EventScript_Kansaku_Text_0:
	.string "You scared me! I'll break your head!$"

SilverTunnel_2F_EventScript_Kansaku_Text_1:
	.string "What a headache!$"

SilverTunnel_2F_EventScript_Kansaku_Text_2:
	.string "Ikuto$"

SilverTunnel_2F_EventScript_Kansaku_Text_3:
	.string "Onix is the best! Sure, she causes\n"
	.string "cave-ins sometimes, but that's not\l"
	.string "important!$"

SilverTunnel_2F_EventScript_Sandslash_Text_0:
	.string "Sandslash$"

SilverTunnel_2F_EventScript_Sandslash_Text_1:
	.string "Sahaaah!$"

SilverTunnel_2F_EventScript_Miner_Text_0:
	.string "Miner$"

SilverTunnel_2F_EventScript_Miner_Text_1:
	.string "We're here mining all day, everyday!\n"
	.string "Ain't that right, Sandy?$"

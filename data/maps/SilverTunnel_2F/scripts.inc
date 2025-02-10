SilverTunnel_2F_MapScripts::
	.byte 0


SilverTunnel_2F_EventScript_Trainer1::
	trainerbattle_single TRAINER_DUMMY, SilverTunnel_2F_EventScript_Trainer1_Text_0, SilverTunnel_2F_EventScript_Trainer1_Text_1, BeachboundRoute_EventScript_Karu_PostBattle
	speakername SilverTunnel_2F_EventScript_Trainer1_Text_2
	msgbox SilverTunnel_2F_EventScript_Trainer1_Text_3, MSGBOX_AUTOCLOSE
	end


SilverTunnel_2F_EventScript_Trainer2::
	trainerbattle_single TRAINER_DUMMY, SilverTunnel_2F_EventScript_Trainer1_Text_0, SilverTunnel_2F_EventScript_Trainer1_Text_1, BeachboundRoute_EventScript_Karu_PostBattle
	speakername SilverTunnel_2F_EventScript_Trainer1_Text_2
	msgbox SilverTunnel_2F_EventScript_Trainer1_Text_3, MSGBOX_AUTOCLOSE
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
	.string "Let's fight$"

SilverTunnel_2F_EventScript_Trainer1_Text_1:
	.string "Oh no I lost$"

SilverTunnel_2F_EventScript_Trainer1_Text_2:
	.string "TODO$"

SilverTunnel_2F_EventScript_Trainer1_Text_3:
	.string "Now I'm sad$"

SilverTunnel_2F_EventScript_Sandslash_Text_0:
	.string "Sandslash$"

SilverTunnel_2F_EventScript_Sandslash_Text_1:
	.string "Sahaaah!$"

SilverTunnel_2F_EventScript_Miner_Text_0:
	.string "Miner$"

SilverTunnel_2F_EventScript_Miner_Text_1:
	.string "We're here mining all day, everyday!\n"
	.string "Ain't that right, Sandy?$"

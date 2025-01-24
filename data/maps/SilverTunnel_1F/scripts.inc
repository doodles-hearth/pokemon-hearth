SilverTunnel_1F_MapScripts::
	.byte 0


SilverTunnel_1F_EventScript_Trainer1::
	trainerbattle_single TRAINER_DUMMY, SilverTunnel_1F_EventScript_Trainer1_Text_0, SilverTunnel_1F_EventScript_Trainer1_Text_1, BeachboundRoute_EventScript_Karu_PostBattle
	speakername SilverTunnel_1F_EventScript_Trainer1_Text_2
	msgbox SilverTunnel_1F_EventScript_Trainer1_Text_3, MSGBOX_AUTOCLOSE
	end


SilverTunnel_1F_EventScript_Trainer2::
	trainerbattle_single TRAINER_DUMMY, SilverTunnel_1F_EventScript_Trainer1_Text_0, SilverTunnel_1F_EventScript_Trainer1_Text_1, BeachboundRoute_EventScript_Karu_PostBattle
	speakername SilverTunnel_1F_EventScript_Trainer1_Text_2
	msgbox SilverTunnel_1F_EventScript_Trainer1_Text_3, MSGBOX_AUTOCLOSE
	end


SilverTunnel_1F_TrainerTips::
	msgbox SilverTunnel_1F_TrainerTips_Text_0, MSGBOX_SIGN
	return


SilverTunnel_1F_EventScript_Trainer1_Text_0:
	.string "Let's fight$"

SilverTunnel_1F_EventScript_Trainer1_Text_1:
	.string "Oh no I lost$"

SilverTunnel_1F_EventScript_Trainer1_Text_2:
	.string "TODO$"

SilverTunnel_1F_EventScript_Trainer1_Text_3:
	.string "Now I'm sad$"

SilverTunnel_1F_TrainerTips_Text_0:
	.string "Warning!\p"
	.string "Wild Pokémon burrow in the sand!\p"
	.string "Cross at your own risk!$"

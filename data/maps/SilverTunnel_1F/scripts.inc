SilverTunnel_1F_MapScripts::
	.byte 0


SilverTunnel_1F_EventScript_Kento::
	trainerbattle_single TRAINER_KENTO, SilverTunnel_1F_EventScript_Kento_Text_0, SilverTunnel_1F_EventScript_Kento_Text_1
	speakername SilverTunnel_1F_EventScript_Kento_Text_2
	msgbox SilverTunnel_1F_EventScript_Kento_Text_3, MSGBOX_AUTOCLOSE
	end


SilverTunnel_1F_EventScript_Trainer2::
	trainerbattle_single TRAINER_SHUYA, SilverTunnel_1F_EventScript_Trainer2_Text_0, SilverTunnel_1F_EventScript_Trainer2_Text_1, BeachboundRoute_EventScript_Karu_PostBattle
	speakername SilverTunnel_1F_EventScript_Trainer2_Text_2
	msgbox SilverTunnel_1F_EventScript_Trainer2_Text_3, MSGBOX_AUTOCLOSE
	end


SilverTunnel_1F_TrainerTips::
	msgbox SilverTunnel_1F_TrainerTips_Text_0, MSGBOX_SIGN
	return


SilverTunnel_1F_EventScript_Kento_Text_0:
	.string "You ain't no miner, are ya?$"

SilverTunnel_1F_EventScript_Kento_Text_1:
	.string "How am I gonna get any work done now?$"

SilverTunnel_1F_EventScript_Kento_Text_2:
	.string "Kento$"

SilverTunnel_1F_EventScript_Kento_Text_3:
	.string "My Makuhita breaks rocks for me!$"

SilverTunnel_1F_EventScript_Trainer2_Text_0:
	.string "D'ya know how tough we miners are?$"

SilverTunnel_1F_EventScript_Trainer2_Text_1:
	.string "I gotta say, yer not bad either!$"

SilverTunnel_1F_EventScript_Trainer2_Text_2:
	.string "Shuya$"

SilverTunnel_1F_EventScript_Trainer2_Text_3:
	.string "Sometimes we armwrestle with our\n"
	.string "Makuhita just for kicks!$"

SilverTunnel_1F_TrainerTips_Text_0:
	.string "Warning!\p"
	.string "Wild Pokémon burrow in the sand!\p"
	.string "Cross at your own risk!$"

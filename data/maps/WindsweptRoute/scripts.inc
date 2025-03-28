WindsweptRoute_MapScripts::
	.byte 0


WindsweptRoute_EventScript_OvergrownTrees::
	lock
	faceplayer
	goto_if_set FLAG_CUT_TREE_SILVER_TUNNEL, WindsweptRoute_EventScript_OvergrownTrees_2
	msgbox WindsweptRoute_EventScript_OvergrownTrees_Text_1
WindsweptRoute_EventScript_OvergrownTrees_1:
	release
	return

WindsweptRoute_EventScript_OvergrownTrees_2:
	msgbox WindsweptRoute_EventScript_OvergrownTrees_Text_0
	goto WindsweptRoute_EventScript_OvergrownTrees_1


WindsweptRoute_EventScript_Trainer1::
	trainerbattle_single TRAINER_MUSASHI_1, WindsweptRoute_EventScript_Trainer1_Text_0, WindsweptRoute_EventScript_Trainer1_Text_1
	speakername WindsweptRoute_EventScript_Trainer1_Text_2
	msgbox WindsweptRoute_EventScript_Trainer1_Text_3, MSGBOX_AUTOCLOSE
	end


WindsweptRoute_EventScript_Trainer2::
	trainerbattle_single TRAINER_ITAMAE, WindsweptRoute_EventScript_Trainer2_Text_0, WindsweptRoute_EventScript_Trainer2_Text_1
	speakername WindsweptRoute_EventScript_Trainer2_Text_2
	msgbox WindsweptRoute_EventScript_Trainer2_Text_3, MSGBOX_AUTOCLOSE
	end


WindsweptRoute_EventScript_Trainer3::
	trainerbattle_single TRAINER_MAKOTO_1, WindsweptRoute_EventScript_Trainer3_Text_0, WindsweptRoute_EventScript_Trainer3_Text_1
	speakername WindsweptRoute_EventScript_Trainer3_Text_2
	msgbox WindsweptRoute_EventScript_Trainer3_Text_3, MSGBOX_AUTOCLOSE
	end


WindsweptRoute_EventScript_Fisherman_ShortRod::
	lock
	faceplayer
	speakername WindsweptRoute_EventScript_Fisherman_ShortRod_Text_0
	msgbox WindsweptRoute_EventScript_Fisherman_ShortRod_Text_1
	closemessage
	release
	return


WindsweptRoute_EventScript_Roku::
	trainerbattle_single TRAINER_ROKU, WindsweptRoute_EventScript_Roku_Text_0, WindsweptRoute_EventScript_Roku_Text_1
	speakername WindsweptRoute_EventScript_Roku_Text_2
	msgbox WindsweptRoute_EventScript_Roku_Text_3, MSGBOX_AUTOCLOSE
	end


WindsweptRoute_EventScript_Trainer4::
	trainerbattle_single TRAINER_MUSASHI_1, WindsweptRoute_EventScript_Trainer1_Text_0, WindsweptRoute_EventScript_Trainer1_Text_1
	speakername WindsweptRoute_EventScript_Trainer1_Text_2
	msgbox WindsweptRoute_EventScript_Trainer1_Text_3, MSGBOX_AUTOCLOSE
	end


WindsweptRoute_EventScript_Trainer5::
	trainerbattle_single TRAINER_MUSASHI_1, WindsweptRoute_EventScript_Trainer1_Text_0, WindsweptRoute_EventScript_Trainer1_Text_1
	speakername WindsweptRoute_EventScript_Trainer1_Text_2
	msgbox WindsweptRoute_EventScript_Trainer1_Text_3, MSGBOX_AUTOCLOSE
	end


WindsweptRoute_EventScript_Trainer6::
	trainerbattle_single TRAINER_MUSASHI_1, WindsweptRoute_EventScript_Trainer1_Text_0, WindsweptRoute_EventScript_Trainer1_Text_1
	speakername WindsweptRoute_EventScript_Trainer1_Text_2
	msgbox WindsweptRoute_EventScript_Trainer1_Text_3, MSGBOX_AUTOCLOSE
	end


WindsweptRoute_EventScript_OvergrownTrees_Text_0:
	.string "Thank you for cutting down that\n"
	.string "annoying tree! We can go to\l"
	.string "Silveridge again now!$"

WindsweptRoute_EventScript_OvergrownTrees_Text_1:
	.string "The weeds got out of control here,\n"
	.string "and some trees now block the way\l"
	.string "to Silver Tunnel…\p"
	.string "Someone'll eventually have to ask\n"
	.string "for help from the old Cut master\l"
	.string "on Tranquil route…$"

WindsweptRoute_EventScript_Trainer1_Text_0:
	.string "These winds blow as strong as my\n"
	.string "will to win!$"

WindsweptRoute_EventScript_Trainer1_Text_1:
	.string "You blew us away!$"

WindsweptRoute_EventScript_Trainer1_Text_2:
	.string "Musashi$"

WindsweptRoute_EventScript_Trainer1_Text_3:
	.string "I come here to train my Pokémon.\n"
	.string "The harsh weather helps us give\l"
	.string "the best of ourselves.$"

WindsweptRoute_EventScript_Trainer2_Text_0:
	.string "I'm scouring this salty grass for\n"
	.string "the tastiest ingredients!$"

WindsweptRoute_EventScript_Trainer2_Text_1:
	.string "Bitter is the taste of defeat…$"

WindsweptRoute_EventScript_Trainer2_Text_2:
	.string "Itamae$"

WindsweptRoute_EventScript_Trainer2_Text_3:
	.string "This place is an inspiration for my\n"
	.string "innovative cuisine.\p"
	.string "The rocks are salty, the plants are\n"
	.string "salty… To an extent, even the air\l"
	.string "is salty.$"

WindsweptRoute_EventScript_Trainer3_Text_0:
	.string "These cliffs are so damn tall! Good\n"
	.string "thing I have a damn long fishing\l"
	.string "rod.$"

WindsweptRoute_EventScript_Trainer3_Text_1:
	.string "My rod didn't keep me from losing…$"

WindsweptRoute_EventScript_Trainer3_Text_2:
	.string "Makoto$"

WindsweptRoute_EventScript_Trainer3_Text_3:
	.string "Look at that poor sod over there!\n"
	.string "His fishing rod's so short, I can't\l"
	.string "help but laugh!$"

WindsweptRoute_EventScript_Fisherman_ShortRod_Text_0:
	.string "Fisherman$"

WindsweptRoute_EventScript_Fisherman_ShortRod_Text_1:
	.string "That guy over there keeps bragging\n"
	.string "about having a long fishing rod.\p"
	.string "Little does he realize that I, with\n"
	.string "my much shorter rod, catch only\l"
	.string "the highest-jumping fish!$"

WindsweptRoute_EventScript_Roku_Text_0:
	.string "Uh, I was just taking a short\n"
	.string "break, okay?$"

WindsweptRoute_EventScript_Roku_Text_1:
	.string "I mistook you for the boss…$"

WindsweptRoute_EventScript_Roku_Text_2:
	.string "Roku$"

WindsweptRoute_EventScript_Roku_Text_3:
	.string "Please don't tell my colleagues\n"
	.string "I've been slacking off…$"

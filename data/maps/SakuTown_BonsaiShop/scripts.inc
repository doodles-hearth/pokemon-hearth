SakuTown_BonsaiShop_MapScripts::
	.byte 0


SakuTown_BonsaiShop_Assistant::
# 6 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	lock
# 7 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	faceplayer
# 10 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	goto_if_set FLAG_TALKED_TO_BONSAI_SHOP_ASSISTANT, SakuTown_BonsaiShop_Assistant_2
# 21 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	goto_if_set FLAG_RECEIVED_WAILMER_PAIL, SakuTown_BonsaiShop_Assistant_5
# 40 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	msgbox SakuTown_BonsaiShop_Assistant_Text_3
# 49 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	closemessage
# 50 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	giveitem ITEM_ORAN_BERRY, 3
# 51 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 53 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	msgbox SakuTown_BonsaiShop_Assistant_Text_4
# 58 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	closemessage
# 59 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	giveitem ITEM_WAILMER_PAIL
# 60 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 62 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	msgbox SakuTown_BonsaiShop_Assistant_Text_5
# 68 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	setflag FLAG_TALKED_TO_BONSAI_SHOP_ASSISTANT
SakuTown_BonsaiShop_Assistant_1:
# 72 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	release
	return

SakuTown_BonsaiShop_Assistant_2:
# 11 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	msgbox SakuTown_BonsaiShop_Assistant_Text_0
	goto SakuTown_BonsaiShop_Assistant_1

SakuTown_BonsaiShop_Assistant_5:
# 22 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	msgbox SakuTown_BonsaiShop_Assistant_Text_1
# 25 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	playse SE_PIN
# 26 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	applymovement 1, Common_Movement_ExclamationMark
# 27 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	waitmovement 0
# 28 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	applymovement 1, Common_Movement_Delay48
# 29 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	waitmovement 0
# 30 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	msgbox SakuTown_BonsaiShop_Assistant_Text_2
# 36 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	release
	goto SakuTown_BonsaiShop_Assistant_1


SakuTown_BonsaiShop_Assistant_Text_0:
# 12 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	.string "Hi there!\p"
	.string "The shop owner is currently away. She's\n"
	.string "very busy.\p"
	.string "Busy with what, you ask?\p"
	.string "Um, I'm actually not sure.$"

SakuTown_BonsaiShop_Assistant_Text_1:
# 23 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	.string "Hello, welcome to our bonsai shop…$"

SakuTown_BonsaiShop_Assistant_Text_2:
# 31 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	.string "Oh, but I know you! We met on Tranquil\n"
	.string "route, remember?\p"
	.string "Have you used the watering can I gave\n"
	.string "you yet?\p"
	.string "Oh, yes, I work here. We sell bonsai and\n"
	.string "other potted flowers!\p"
	.string "I'm the owner's assistant, I manage the\n"
	.string "shop while she's away!$"

SakuTown_BonsaiShop_Assistant_Text_3:
# 41 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	.string "Hello, welcome to our bonsai shop!I'm\n"
	.string "the owner's assistant, I manage the\l"
	.string "shop while she's away.\p"
	.string "We sell bonsai and other potted\n"
	.string "flowers! Are you interested in plants?\p"
	.string "Have you ever seen strange patches of\n"
	.string "soil while on your journey?\p"
	.string "Those soil patches are incredibly\n"
	.string "fertile, which means any berry you plant\l"
	.string "in that soil will thrive and grow into a\l"
	.string "tree, ready to be harvested!\p"
	.string "I see you're a trainer. Well, different\n"
	.string "berries have different effects when\l"
	.string "they're fed to Pokémon.\p"
	.string "I love berries, hopefully you'll soon\n"
	.string "learn to love them too!\p"
	.string "Here, try planting a few!$"

SakuTown_BonsaiShop_Assistant_Text_4:
# 54 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	.string "Oh, right, I was almost forgetting!\p"
	.string "You must remember to water them\n"
	.string "regularly, or they won't grow!\p"
	.string "I like you. Take this!$"

SakuTown_BonsaiShop_Assistant_Text_5:
# 63 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	.string "Isn't it cute? It's friend-shaped!\p"
	.string "Don't worry about it, I have a spare one.\p"
	.string "Have fun gardening!$"

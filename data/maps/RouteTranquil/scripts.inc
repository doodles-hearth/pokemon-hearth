RouteTranquil_MapScripts::
	.byte 0


RouteTranquil_EventScript_Chikao::
# 10 "data/maps/RouteTranquil/scripts.pory"
	trainerbattle_single TRAINER_CHIKAO, RouteTranquil_EventScript_Chikao_Text_0, RouteTranquil_EventScript_Chikao_Text_1
# 15 "data/maps/RouteTranquil/scripts.pory"
	msgbox RouteTranquil_EventScript_Chikao_Text_2, MSGBOX_AUTOCLOSE
	end


RouteTranquil_EventScript_Takeshi::
# 20 "data/maps/RouteTranquil/scripts.pory"
	trainerbattle_single TRAINER_TAKESHI, RouteTranquil_EventScript_Takeshi_Text_0, RouteTranquil_EventScript_Takeshi_Text_1
# 25 "data/maps/RouteTranquil/scripts.pory"
	msgbox RouteTranquil_EventScript_Takeshi_Text_2, MSGBOX_AUTOCLOSE
	end


RouteTranquil_EventScript_Hana::
# 30 "data/maps/RouteTranquil/scripts.pory"
	trainerbattle_single TRAINER_HANA, RouteTranquil_EventScript_Hana_Text_0, RouteTranquil_EventScript_Hana_Text_1
# 35 "data/maps/RouteTranquil/scripts.pory"
	msgbox RouteTranquil_EventScript_Hana_Text_2, MSGBOX_AUTOCLOSE
	end


RouteTranquil_EventScript_Kenji::
# 40 "data/maps/RouteTranquil/scripts.pory"
	trainerbattle_single TRAINER_KENJI, RouteTranquil_EventScript_Kenji_Text_0, RouteTranquil_EventScript_Kenji_Text_1
# 45 "data/maps/RouteTranquil/scripts.pory"
	msgbox RouteTranquil_EventScript_Kenji_Text_2, MSGBOX_AUTOCLOSE
	end


RouteTranquil_EventScript_MysteriousSamurai::
# 54 "data/maps/RouteTranquil/scripts.pory"
	lock
# 55 "data/maps/RouteTranquil/scripts.pory"
	msgbox RouteTranquil_EventScript_MysteriousSamurai_Text_0
# 62 "data/maps/RouteTranquil/scripts.pory"
	closemessage
# 64 "data/maps/RouteTranquil/scripts.pory"
	applymovement 9, RouteTranquil_Movement_MysteriousSamuraiWalksAway
# 65 "data/maps/RouteTranquil/scripts.pory"
	removeobject 9
# 67 "data/maps/RouteTranquil/scripts.pory"
	setflag FLAG_MYSTERIOUS_SAMURAI_TRANQUIL_ROUTE
# 68 "data/maps/RouteTranquil/scripts.pory"
	release
	end


# 72 "data/maps/RouteTranquil/scripts.pory"
RouteTranquil_Movement_MysteriousSamuraiWalksAway:
# 73 "data/maps/RouteTranquil/scripts.pory"
	walk_right
# 74 "data/maps/RouteTranquil/scripts.pory"
	walk_right
# 75 "data/maps/RouteTranquil/scripts.pory"
	walk_right
# 76 "data/maps/RouteTranquil/scripts.pory"
	walk_right
# 77 "data/maps/RouteTranquil/scripts.pory"
	walk_right
# 78 "data/maps/RouteTranquil/scripts.pory"
	walk_right
	step_end

RouteTranquil_EventScript_Girl::
# 82 "data/maps/RouteTranquil/scripts.pory"
	lock
# 83 "data/maps/RouteTranquil/scripts.pory"
	msgbox RouteTranquil_EventScript_Girl_Text_0, MSGBOX_AUTOCLOSE
# 84 "data/maps/RouteTranquil/scripts.pory"
	release
	end


RouteTranquil_EventScript_BerryWoman::
# 89 "data/maps/RouteTranquil/scripts.pory"
	lock
# 91 "data/maps/RouteTranquil/scripts.pory"
	msgbox RouteTranquil_EventScript_BerryWoman_Text_0
# 92 "data/maps/RouteTranquil/scripts.pory"
	closemessage
# 93 "data/maps/RouteTranquil/scripts.pory"
	applymovement 5, Common_Movement_FaceRight
# 94 "data/maps/RouteTranquil/scripts.pory"
	waitmovement 0
# 95 "data/maps/RouteTranquil/scripts.pory"
	delay 48
# 96 "data/maps/RouteTranquil/scripts.pory"
	applymovement 5, Common_Movement_FacePlayer
# 97 "data/maps/RouteTranquil/scripts.pory"
	waitmovement 0
# 98 "data/maps/RouteTranquil/scripts.pory"
	msgbox RouteTranquil_EventScript_BerryWoman_Text_1
# 105 "data/maps/RouteTranquil/scripts.pory"
	closemessage
# 106 "data/maps/RouteTranquil/scripts.pory"
	giveitem ITEM_ORAN_BERRY, 3
# 107 "data/maps/RouteTranquil/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 109 "data/maps/RouteTranquil/scripts.pory"
	msgbox RouteTranquil_EventScript_BerryWoman_Text_2
# 114 "data/maps/RouteTranquil/scripts.pory"
	closemessage
# 115 "data/maps/RouteTranquil/scripts.pory"
	giveitem ITEM_WAILMER_PAIL
# 116 "data/maps/RouteTranquil/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 118 "data/maps/RouteTranquil/scripts.pory"
	msgbox RouteTranquil_EventScript_BerryWoman_Text_3
# 123 "data/maps/RouteTranquil/scripts.pory"
	setflag FLAG_RECEIVED_WAILMER_PAIL
# 124 "data/maps/RouteTranquil/scripts.pory"
	release
	end


RouteTranquil_TrainerTips1::
# 129 "data/maps/RouteTranquil/scripts.pory"
	msgbox RouteTranquil_TrainerTips1_Text_0, MSGBOX_SIGN
	return


RouteTranquil_TrainerTips2::
# 137 "data/maps/RouteTranquil/scripts.pory"
	msgbox RouteTranquil_TrainerTips2_Text_0, MSGBOX_SIGN
	return


RouteTranquil_EventScript_Chikao_Text_0:
# 12 "data/maps/RouteTranquil/scripts.pory"
	.string "I've been studying Pokémon at school! I\n"
	.string "can't lose!$"

RouteTranquil_EventScript_Chikao_Text_1:
# 13 "data/maps/RouteTranquil/scripts.pory"
	.string "I should have listened in class...$"

RouteTranquil_EventScript_Chikao_Text_2:
# 15 "data/maps/RouteTranquil/scripts.pory"
	.string "Some Pokémon have more attack, and some have more special attack!\p What's the difference? Uhh... It's too complicated to explain.$"

RouteTranquil_EventScript_Takeshi_Text_0:
# 22 "data/maps/RouteTranquil/scripts.pory"
	.string "Stay right there! I'll defeat you with\n"
	.string "my ninja skills!$"

RouteTranquil_EventScript_Takeshi_Text_1:
# 23 "data/maps/RouteTranquil/scripts.pory"
	.string "I had the sun in my eyes!$"

RouteTranquil_EventScript_Takeshi_Text_2:
# 25 "data/maps/RouteTranquil/scripts.pory"
	.string "I must hone my ninja skills!$"

RouteTranquil_EventScript_Hana_Text_0:
# 32 "data/maps/RouteTranquil/scripts.pory"
	.string "Ugh, how can Kenji paint a portrait of\n"
	.string "me if people keep walking between us?$"

RouteTranquil_EventScript_Hana_Text_1:
# 33 "data/maps/RouteTranquil/scripts.pory"
	.string "Great, now my hair is all messed up.$"

RouteTranquil_EventScript_Hana_Text_2:
# 35 "data/maps/RouteTranquil/scripts.pory"
	.string "Kenji really is an amazing artist. I feel\n"
	.string "very lucky.$"

RouteTranquil_EventScript_Kenji_Text_0:
# 42 "data/maps/RouteTranquil/scripts.pory"
	.string "You're interrupting my creative flow!!$"

RouteTranquil_EventScript_Kenji_Text_1:
# 43 "data/maps/RouteTranquil/scripts.pory"
	.string "Such beauty! What an artistic fight\n"
	.string "this was!$"

RouteTranquil_EventScript_Kenji_Text_2:
# 46 "data/maps/RouteTranquil/scripts.pory"
	.string "Hana is the best subject I could dream\n"
	.string "of.\p"
	.string "Hey, please don't tell her I said that.$"

RouteTranquil_EventScript_MysteriousSamurai_Text_0:
# 56 "data/maps/RouteTranquil/scripts.pory"
	.string "So you are one of those new Pokémon\n"
	.string "trainers, right?\p"
	.string "You say Pokémon have been restless,\n"
	.string "lately?\p"
	.string "Interesting.\p"
	.string "I have the feeling we're going to meet\n"
	.string "again soon.\p"
	.string "Until then, farewell.$"

RouteTranquil_EventScript_Girl_Text_0:
# 83 "data/maps/RouteTranquil/scripts.pory"
	.string "What? Oh, I don't fight.\p"
	.string "My Pokémon and I are just strolling.$"

RouteTranquil_EventScript_BerryWoman_Text_0:
# 91 "data/maps/RouteTranquil/scripts.pory"
	.string "Hi, young one! See this?$"

RouteTranquil_EventScript_BerryWoman_Text_1:
# 99 "data/maps/RouteTranquil/scripts.pory"
	.string "You can plant berries in the ground in\n"
	.string "fertile spots like this.\p"
	.string "The seeds will eventually grow into a\n"
	.string "healthy berry tree, ready to be\l"
	.string "harvested!\p"
	.string "I see you're a trainer. Well, different\n"
	.string "berries have different effects when\l"
	.string "they're fed to Pokémon.\p"
	.string "I love berries, hopefully you'll soon\n"
	.string "learn to love them too!\p"
	.string "Here, try planting a few!$"

RouteTranquil_EventScript_BerryWoman_Text_2:
# 110 "data/maps/RouteTranquil/scripts.pory"
	.string "Oh, right, I was almost forgetting!\p"
	.string "You must remember to water them\n"
	.string "regularly, or they won't grow!\p"
	.string "I like you. Take this!$"

RouteTranquil_EventScript_BerryWoman_Text_3:
# 119 "data/maps/RouteTranquil/scripts.pory"
	.string "Don't worry about it, I have a spare one.\p"
	.string "Have fun gardening!$"

RouteTranquil_TrainerTips1_Text_0:
# 130 "data/maps/RouteTranquil/scripts.pory"
	.string "Some Pokémon only come out come\n"
	.string "nighttime.\p"
	.string "Visit the same spot at different times\n"
	.string "of day to have a chance of seeing rare\l"
	.string "Pokémon!$"

RouteTranquil_TrainerTips2_Text_0:
# 138 "data/maps/RouteTranquil/scripts.pory"
	.string "Several items can be assigned to the\n"
	.string "SELECT button from your bag.$"

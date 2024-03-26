GinkoWoods_MapScripts::
	.byte 0


GinkoWoods_EventScript_Toshio::
# 7 "data/maps/GinkoWoods/scripts.pory"
	trainerbattle_single TRAINER_TOSHIO_1, GinkoWoods_EventScript_Toshio_Text_0, GinkoWoods_EventScript_Toshio_Text_1
# 17 "data/maps/GinkoWoods/scripts.pory"
	msgbox GinkoWoods_EventScript_Toshio_Text_2
# 18 "data/maps/GinkoWoods/scripts.pory"
	release
	end


GinkoWoods_EventScript_Eiji::
# 23 "data/maps/GinkoWoods/scripts.pory"
	trainerbattle_single TRAINER_EIJI, GinkoWoods_EventScript_Eiji_Text_0, GinkoWoods_EventScript_Eiji_Text_1
# 28 "data/maps/GinkoWoods/scripts.pory"
	msgbox GinkoWoods_EventScript_Eiji_Text_2
# 29 "data/maps/GinkoWoods/scripts.pory"
	release
	end


GinkoWoods_EventScript_OldMan::
# 34 "data/maps/GinkoWoods/scripts.pory"
	lock
# 35 "data/maps/GinkoWoods/scripts.pory"
	faceplayer
# 36 "data/maps/GinkoWoods/scripts.pory"
	msgbox GinkoWoods_EventScript_OldMan_Text_0
# 37 "data/maps/GinkoWoods/scripts.pory"
	release
	end


GinkoWoods_EventScript_TrainerTips1::
# 42 "data/maps/GinkoWoods/scripts.pory"
	msgbox GinkoWoods_EventScript_TrainerTips1_Text_0, MSGBOX_SIGN
	return


GinkoWoods_EventScript_TrainerTips2::
# 46 "data/maps/GinkoWoods/scripts.pory"
	msgbox GinkoWoods_EventScript_TrainerTips2_Text_0, MSGBOX_SIGN
	return


GinkoWoods_EventScript_Toshio_Text_0:
# 9 "data/maps/GinkoWoods/scripts.pory"
	.string "Our eyes met! Therefore we must battle!$"

GinkoWoods_EventScript_Toshio_Text_1:
# 10 "data/maps/GinkoWoods/scripts.pory"
	.string "Should have kept my mouth shut…$"

GinkoWoods_EventScript_Toshio_Text_2:
# 17 "data/maps/GinkoWoods/scripts.pory"
	.string "Real trainers fight when they spot each\n"
	.string "other!\p"
	.string "At least that's what my dad told me…$"

GinkoWoods_EventScript_Eiji_Text_0:
# 25 "data/maps/GinkoWoods/scripts.pory"
	.string "With the help of my brand-new Pokémon,\n"
	.string "I'm catching all sort of bugs!$"

GinkoWoods_EventScript_Eiji_Text_1:
# 26 "data/maps/GinkoWoods/scripts.pory"
	.string "My bugs!$"

GinkoWoods_EventScript_Eiji_Text_2:
# 28 "data/maps/GinkoWoods/scripts.pory"
	.string "I asked Elder Kaba for a bird Pokémon,\n"
	.string "because they're strong against bugs!$"

GinkoWoods_EventScript_OldMan_Text_0:
# 36 "data/maps/GinkoWoods/scripts.pory"
	.string "These woods are fascinating.\p"
	.string "There seem to be a lot of yellow\n"
	.string "Pokémon here.\p"
	.string "Perhaps they can hide from predators\n"
	.string "thanks to the color of these trees.$"

GinkoWoods_EventScript_TrainerTips1_Text_0:
# 42 "data/maps/GinkoWoods/scripts.pory"
	.string "Some items can be hidden under the\n"
	.string "forest's thick canopy. Look around!$"

GinkoWoods_EventScript_TrainerTips2_Text_0:
# 46 "data/maps/GinkoWoods/scripts.pory"
	.string "You can sort the contents of your bag\n"
	.string "by pressing START.$"

MaguroHarbor_Refuge_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MaguroHarbor_Refuge_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

MaguroHarbor_Refuge_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setrespawn HEAL_LOCATION_MAGURO_HARBOR
	return


MaguroHarbor_Refuge_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse_CutTheBullshit
	waitmessage
	waitbuttonpress
	release
	end


MaguroHarbor_Refuge_EventScript_Hariko::
	lock
	faceplayer
	goto_if_set FLAG_BEAT_HARIKO_IN_MAGURO_REFUGE, MaguroHarbor_Refuge_EventScript_Hariko_1
	goto_if_set FLAG_TALKED_TO_HARIKO_IN_MAGURO_REFUGE, MaguroHarbor_Refuge_EventScript_Hariko_2
	speakername MaguroHarbor_Refuge_EventScript_Hariko_Text_0
	msgbox MaguroHarbor_Refuge_EventScript_Hariko_Text_3
	closemessage
	setseenmon SPECIES_SLOWPOKE
	setnamedmon SPECIES_SLOWPOKE
	setflag FLAG_TALKED_TO_HARIKO_IN_MAGURO_REFUGE
	applymovement 4, MaguroHarbor_Refuge_EventScript_Hariko_Movement_0
	waitmovement 4
	delay 60
	playse SE_LEDGE
	applymovement 5, MaguroHarbor_Refuge_EventScript_Hariko_Movement_1
	waitmovement 5
	playmoncry SPECIES_SLOWPOKE, CRY_MODE_NORMAL
	speakername MaguroHarbor_Refuge_EventScript_Hariko_Text_4
	msgbox MaguroHarbor_Refuge_EventScript_Hariko_Text_5
	closemessage
	applymovement 4, MaguroHarbor_Refuge_EventScript_Hariko_Movement_2
	waitmovement 4
	speakername MaguroHarbor_Refuge_EventScript_Hariko_Text_0
	msgbox MaguroHarbor_Refuge_EventScript_Hariko_Text_6
	goto MaguroHarbor_Refuge_BattleHariko
	return

MaguroHarbor_Refuge_EventScript_Hariko_1:
	speakername MaguroHarbor_Refuge_EventScript_Hariko_Text_0
	msgbox MaguroHarbor_Refuge_EventScript_Hariko_Text_1
	closemessage
	return

MaguroHarbor_Refuge_EventScript_Hariko_2:
	speakername MaguroHarbor_Refuge_EventScript_Hariko_Text_0
	msgbox MaguroHarbor_Refuge_EventScript_Hariko_Text_2
	closemessage
	goto MaguroHarbor_Refuge_BattleHariko
	return


MaguroHarbor_Refuge_BattleHariko::
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, MaguroHarbor_Refuge_BattleHariko_Text_0, MaguroHarbor_Refuge_BattleHariko_Text_1
	closemessage
	switch VAR_RESULT
	case 0, MaguroHarbor_Refuge_BattleHariko_3
	case 1, MaguroHarbor_Refuge_BattleHariko_4
MaguroHarbor_Refuge_BattleHariko_1:
	release
	return

MaguroHarbor_Refuge_BattleHariko_3:
	trainerbattle_no_intro TRAINER_HARIKO_MAGURO, MaguroHarbor_Refuge_BattleHariko_Text_2
	setflag FLAG_BEAT_HARIKO_IN_MAGURO_REFUGE
	speakername MaguroHarbor_Refuge_EventScript_Hariko_Text_0
	msgbox MaguroHarbor_Refuge_BattleHariko_Text_3
	closemessage
	giveitem ITEM_UUMEGIRI, 4
	speakername MaguroHarbor_Refuge_EventScript_Hariko_Text_0
	msgbox MaguroHarbor_Refuge_BattleHariko_Text_4
	closemessage
	goto MaguroHarbor_Refuge_BattleHariko_1

MaguroHarbor_Refuge_BattleHariko_4:
	speakername MaguroHarbor_Refuge_EventScript_Hariko_Text_0
	msgbox MaguroHarbor_Refuge_BattleHariko_Text_5
	closemessage
	goto MaguroHarbor_Refuge_BattleHariko_1


MaguroHarbor_Refuge_EventScript_Slowpoke::
	lock
	faceplayer
	setseenmon SPECIES_SLOWPOKE
	playmoncry SPECIES_SLOWPOKE, CRY_MODE_NORMAL
	goto_if_set FLAG_TALKED_TO_HARIKO_IN_MAGURO_REFUGE, MaguroHarbor_Refuge_EventScript_Slowpoke_2
	setspeakertomonname SPECIES_SLOWPOKE
MaguroHarbor_Refuge_EventScript_Slowpoke_1:
	msgbox MaguroHarbor_Refuge_EventScript_Slowpoke_Text_0
	waitmoncry
	closemessage
	release
	return

MaguroHarbor_Refuge_EventScript_Slowpoke_2:
	speakername MaguroHarbor_Refuge_EventScript_Hariko_Text_4
	goto MaguroHarbor_Refuge_EventScript_Slowpoke_1


MaguroHarbor_Refuge_EventScript_DescribedMons::
	lock
	faceplayer
	setnamedmon SPECIES_KRABBY
	setdescribedmon SPECIES_KRABBY
	speakername MaguroHarbor_Refuge_EventScript_DescribedMons_Text_0
	msgbox MaguroHarbor_Refuge_EventScript_DescribedMons_Text_1
	closemessage
	release
	return


MaguroHarbor_Refuge_EventScript_Krabby::
	lock
	faceplayer
	setseenmon SPECIES_KRABBY
	playmoncry SPECIES_KRABBY, CRY_MODE_NORMAL
	setspeakertomonname SPECIES_KRABBY
	msgbox MaguroHarbor_Refuge_EventScript_Krabby_Text_0
	waitmoncry
	closemessage
	release
	return


MaguroHarbor_Refuge_EventScript_Hariko_Movement_0:
	walk_in_place_fast_left
	step_end

MaguroHarbor_Refuge_EventScript_Hariko_Movement_1:
	jump_in_place_down
	step_end

MaguroHarbor_Refuge_EventScript_Hariko_Movement_2:
	walk_in_place_fast_down
	step_end

MaguroHarbor_Refuge_EventScript_Hariko_Text_0:
	.string "Hariko$"

MaguroHarbor_Refuge_EventScript_Hariko_Text_1:
	.string "Where are you headed after getting\n"
	.string "the Maguro Dojo's Token?\p"
	.string "Silveridge? I heard there are\n"
	.string "enormous rock snakes burrowing\l"
	.string "through Silver Tunnel…\p"
	.string "If you see one, tell me about it the\n"
	.string "next time we meet.$"

MaguroHarbor_Refuge_EventScript_Hariko_Text_2:
	.string "Hello again, {PLAYER}. So, do you\n"
	.string "want to battle?$"

MaguroHarbor_Refuge_EventScript_Hariko_Text_3:
	.string "Oh, hello there, {PLAYER}.\n"
	.string "Fancy meeting you here, as they say.\p"
	.string "I assume you are here to challenge\n"
	.string "the Maguro Harbor Dojo?\p"
	.string "Me? I am not particularly interested\n"
	.string "in becoming a great Wielder.\p"
	.string "I travel to learn as much as I can\n"
	.string "about Pokémon!\p"
	.string "You've not met my companion yet, have\n"
	.string "you? Meet my Slowpoke, Bean!$"

MaguroHarbor_Refuge_EventScript_Hariko_Text_4:
	.string "Bean$"

MaguroHarbor_Refuge_EventScript_Hariko_Text_5:
	.string "Hurr…$"

MaguroHarbor_Refuge_EventScript_Hariko_Text_6:
	.string "Bean is a little slow, but he is happy\n"
	.string "to meet you!\p"
	.string "He may not look like a fighter, but he\n"
	.string "enjoys a good battle, too. Would you\l"
	.string "like to have a friendly bout, Bean\l"
	.string "against your Pokémon?$"

MaguroHarbor_Refuge_BattleHariko_Text_0:
	.string "Yes!$"

MaguroHarbor_Refuge_BattleHariko_Text_1:
	.string "Maybe later.$"

MaguroHarbor_Refuge_BattleHariko_Text_2:
	.string "Very interesting.$"

MaguroHarbor_Refuge_BattleHariko_Text_3:
	.string "We lost, but Bean tells me he had fun!\n"
	.string "I am glad.\p"
	.string "Everyday we learn something new\n"
	.string "about Pokémon, be it through battling\l"
	.string "or observation.\p"
	.string "I brought snacks for my journey.\n"
	.string "If I give you some, you will probably\l"
	.string "feel rewarded for this fight!$"

MaguroHarbor_Refuge_BattleHariko_Text_4:
	.string "These can be fed to your Pokémon\n"
	.string "during battle to save you from a\l"
	.string "pickle.\p"
	.string "Farewell, {PLAYER}.$"

MaguroHarbor_Refuge_BattleHariko_Text_5:
	.string "No problem. I will be here a while\n"
	.string "before I continue my journey.$"

MaguroHarbor_Refuge_EventScript_Slowpoke_Text_0:
	.string "Duh…$"

MaguroHarbor_Refuge_EventScript_DescribedMons_Text_0:
	.string "Man$"

MaguroHarbor_Refuge_EventScript_DescribedMons_Text_1:
	.string "Oh! You're writing a Pokémon\n"
	.string "encyclopedia? That's amazing!\p"
	.string "I bet you're wondering how you can\n"
	.string "fill up the description of every\l"
	.string "Pokémon.\l"
	.string "Well, asking around definitely helps!\p"
	.string "For instance, Krabby sleeps burrowed\n"
	.string "inside holes in the sand, and did you\l"
	.string "know it can grow its pincers back if\l"
	.string "they fall during battle?\p"
	.string "Go ahead, you can write that down\n"
	.string "about it!$"

MaguroHarbor_Refuge_EventScript_Krabby_Text_0:
	.string "Krblblblbl…$"

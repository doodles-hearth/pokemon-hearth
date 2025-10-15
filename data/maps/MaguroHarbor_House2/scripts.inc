MaguroHarbor_House2_MapScripts::
	.byte 0


MaguroHarbor_House2_OldMan::
	lock
	faceplayer
	msgbox MaguroHarbor_House2_OldMan_Text_0
	closemessage
	release
	return


MaguroHarbor_House2_MyBrother::
	lock
	faceplayer
	gettimeofday
	compare VAR_0x8000, TIME_EVENING
	goto_if_eq MaguroHarbor_House2_MyBrother_2
	compare VAR_0x8000, TIME_NIGHT
	goto_if_eq MaguroHarbor_House2_MyBrother_2
	compare VAR_0x8000, TIME_DEAD_NIGHT
	goto_if_eq MaguroHarbor_House2_MyBrother_2
	msgbox MaguroHarbor_House2_MyBrother_Text_1
MaguroHarbor_House2_MyBrother_1:
	closemessage
	release
	return

MaguroHarbor_House2_MyBrother_2:
	msgbox MaguroHarbor_House2_MyBrother_Text_0
	goto MaguroHarbor_House2_MyBrother_1


MaguroHarbor_House2_Fisherman::
	lock
	msgbox MaguroHarbor_House2_Fisherman_Text_0
	closemessage
	release
	return


MaguroHarbor_House2_Cramorant::
	lock
	faceplayer
	setseenmon SPECIES_CRAMORANT
	setspeakertomonname SPECIES_CRAMORANT
	playmoncry SPECIES_CRAMORANT, CRY_MODE_NORMAL
	applymovement VAR_LAST_TALKED, MaguroHarbor_House2_Cramorant_Movement_0
	msgbox MaguroHarbor_House2_Cramorant_Text_0
	waitmoncry
	release
	return


MaguroHarbor_House2_Cramorant_Movement_0:
	emote_exclamation_mark
	step_end

MaguroHarbor_House2_OldMan_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_SEASIDE_OLD_MAN EMOTE_NORMAL}{SPEAKER NAME_OLD_MAN}When I was a youngun like you, I used\n"
	.string "to fish in the Icy Isles.\p"
	.string "The water was so cold, it'd freeze\n"
	.string "your beard right up!$"

MaguroHarbor_House2_MyBrother_Text_0:
	.string "{SPEAKER NAME_FISHERMAN}Another day, another safe return\n"
	.string "from the merciless ocean waves.$"

MaguroHarbor_House2_MyBrother_Text_1:
	.string "{SPEAKER NAME_FISHERMAN}My brother has gone to the Angler's\n"
	.string "Shrine.\p"
	.string "He makes offerings and asks for our\n"
	.string "safekeeping when we're at sea.$"

MaguroHarbor_House2_Fisherman_Text_0:
	.string "{SPEAKER NAME_FISHERMAN}A divinity watches over the people of\n"
	.string "each trade.\p"
	.string "The great Bronzong near Kura Village\n"
	.string "grants farmers good harvests…\p"
	.string "The old Gyarados temple out at sea\n"
	.string "guards fishermen against shipwreck…\p"
	.string "Uhh, the rest I can't remember!$"

MaguroHarbor_House2_Cramorant_Text_0:
	.string "Sqwawk!$"

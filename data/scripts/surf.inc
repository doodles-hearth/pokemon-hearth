EventScript_UseSurf::
# 2 "data/scripts/surf.pory"
	checkpartymove MOVE_SURF
# 3 "data/scripts/surf.pory"
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantSurf
# 4 "data/scripts/surf.pory"
	bufferpartymonnick STR_VAR_1, VAR_RESULT
# 5 "data/scripts/surf.pory"
	setfieldeffectargument 0, VAR_RESULT
# 6 "data/scripts/surf.pory"
	lockall
# 7 "data/scripts/surf.pory"
	msgbox gText_WantToUseSurf, MSGBOX_YESNO
# 8 "data/scripts/surf.pory"
	compare VAR_RESULT, NO
	goto_if_ne EventScript_UseSurf_2
EventScript_UseSurf_1:
# 12 "data/scripts/surf.pory"
	releaseall
	end

EventScript_UseSurf_2:
# 9 "data/scripts/surf.pory"
	msgbox gText_PlayerUsedSurf, MSGBOX_DEFAULT
# 10 "data/scripts/surf.pory"
	dofieldeffect FLDEFF_USE_SURF
	goto EventScript_UseSurf_1


EventScript_CantSurf::
# 17 "data/scripts/surf.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 18 "data/scripts/surf.pory"
	speakername EventScript_CantSurf_Text_0
# 19 "data/scripts/surf.pory"
	msgbox EventScript_CantSurf_Text_1, MSGBOX_DEFAULT
# 20 "data/scripts/surf.pory"
	closemessage
# 21 "data/scripts/surf.pory"
	removefieldmugshot
	end


EventScript_CantSurf_Text_0:
# 18 "data/scripts/surf.pory"
	.string "Little Archie$"

EventScript_CantSurf_Text_1:
# 19 "data/scripts/surf.pory"
	.string "Can't swim here…\n"
	.string "Too many Pincurchin!$"

EventScript_UseSurf::
# 2 "data/scripts/surf.pory"
	lockall
# 3 "data/scripts/surf.pory"
	goto EventScript_CantSurf
# 15 "data/scripts/surf.pory"
	releaseall
	end


EventScript_CantSurf::
# 20 "data/scripts/surf.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 21 "data/scripts/surf.pory"
	speakername EventScript_CantSurf_Text_0
# 22 "data/scripts/surf.pory"
	msgbox EventScript_CantSurf_Text_1, MSGBOX_DEFAULT
# 23 "data/scripts/surf.pory"
	closemessage
# 24 "data/scripts/surf.pory"
	removefieldmugshot
	end


EventScript_CantSurf_Text_0:
# 21 "data/scripts/surf.pory"
	.string "Little Archie$"

EventScript_CantSurf_Text_1:
# 22 "data/scripts/surf.pory"
	.string "Can't swim here…\n"
	.string "Too many Pincurchin!$"

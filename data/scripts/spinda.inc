Spinda_SpinClockwise::
# 3 "data/scripts/spinda.pory"
	rotateplayerxyclockwise
# 4 "data/scripts/spinda.pory"
	buffernumberstring STR_VAR_1, VAR_0x8000
# 5 "data/scripts/spinda.pory"
	buffernumberstring STR_VAR_2, VAR_0x8001
# 6 "data/scripts/spinda.pory"
	msgbox Spinda_SpinClockwise_Text_0, MSGBOX_AUTOCLOSE
# 7 "data/scripts/spinda.pory"
	warpsilent MAP_SPINDA_ISLAND_HOME_CLOCK1, VAR_0x8000, VAR_0x8001
	return


Spinda_SpinCounterclockwise::
# 11 "data/scripts/spinda.pory"
	rotateplayerxycounterclockwise
# 12 "data/scripts/spinda.pory"
	warpsilent MAP_SPINDA_ISLAND_HOME_CLOCK1, VAR_0x8000, VAR_0x8001
	return


Spinda_SpinClockwise_Text_0:
# 6 "data/scripts/spinda.pory"
	.string "{STR_VAR_1}, {STR_VAR_2}$"

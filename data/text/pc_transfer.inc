gText_PkmnTransferredSomeonesPC::
	.string "{STR_VAR_2} was transferred to\n"
	.string "the Pasture.\p"
	.string "It was placed in \n"
	.string "Pen “{STR_VAR_1}.”$"

gText_PkmnTransferredLanettesPC::
	.string "{STR_VAR_2} was transferred to\n"
#if IS_FRLG
    .string "BILL'S PC.\p"
#else
	.string "the Pasture.\p"
#endif
	.string "It was placed in \n"
	.string "Pen “{STR_VAR_1}.”$"

gText_PkmnTransferredSomeonesPCBoxFull::
	.string "Pen “{STR_VAR_3}”\n"
	.string "was full.\p"
	.string "{STR_VAR_2} was transferred to\n"
	.string "Pen “{STR_VAR_1}.”$"

gText_PkmnTransferredLanettesPCBoxFull::
#if IS_FRLG
	  .string "BOX “{STR_VAR_3}” on\n"
    .string "BILL'S PC was full.\p"
#else
	.string "Pen “{STR_VAR_3}”\n"
	.string "was full.\p"
#endif
	.string "{STR_VAR_2} was transferred to\n"
	.string "Pen “{STR_VAR_1}.”$"

gText_PkmnSentToPCAfterCatch::
	.string "{STR_VAR_2} was sent to\n"
	.string "the Pasture.\p"
	.string "It was placed in \n"
	.string "Pen “{STR_VAR_1}”.$"

gText_PlayerObtainedTheMon::
    .string "{PLAYER} obtained\n"
    .string "the {STR_VAR_1}!$"

gText_NoMoreRoomForPokemon::
	.string "There's no more room for POKéMON!\p"
	.string "The Pasture is full and\n"
	.string "can't accept any more!$"

gText_NicknameThisPokemon::
	.string "Do you want to give a nickname to\n"
	.string "this {STR_VAR_1}?$"

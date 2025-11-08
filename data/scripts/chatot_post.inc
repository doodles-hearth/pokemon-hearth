ChatotPost_EventScript_Chatot::
# 2 "data/scripts/chatot_post.pory"
	lockall
# 4 "data/scripts/chatot_post.pory"
	setseenmon SPECIES_CHATOT
# 5 "data/scripts/chatot_post.pory"
	setchatotlastspeaker
# 7 "data/scripts/chatot_post.pory"
	waitse
# 8 "data/scripts/chatot_post.pory"
	playse SE_LEDGE
# 9 "data/scripts/chatot_post.pory"
	applymovement VAR_LAST_TALKED, ChatotPost_EventScript_Chatot_Movement_0
# 10 "data/scripts/chatot_post.pory"
	waitmovement VAR_LAST_TALKED
# 11 "data/scripts/chatot_post.pory"
	waitse
# 13 "data/scripts/chatot_post.pory"
	playmoncry SPECIES_CHATOT, CRY_MODE_NORMAL
# 14 "data/scripts/chatot_post.pory"
	applymovement VAR_LAST_TALKED, ChatotPost_EventScript_Chatot_Movement_1
# 16 "data/scripts/chatot_post.pory"
	delay 16
	checkchatotpost
# 0 "data/scripts/chatot_post.pory"
	compare VAR_RESULT, 0
	goto_if_ne ChatotPost_EventScript_Chatot_2
# 52 "data/scripts/chatot_post.pory"
	setspeakertomonname SPECIES_CHATOT
# 53 "data/scripts/chatot_post.pory"
	msgbox ChatotPost_EventScript_Chatot_Text_2
# 54 "data/scripts/chatot_post.pory"
	closemessage
# 55 "data/scripts/chatot_post.pory"
	releaseall
	end

ChatotPost_EventScript_Chatot_1:
# 59 "data/scripts/chatot_post.pory"
	playse SE_LEDGE
# 60 "data/scripts/chatot_post.pory"
	applymovement VAR_LAST_TALKED, ChatotPost_EventScript_Chatot_Movement_0
# 61 "data/scripts/chatot_post.pory"
	waitse
# 63 "data/scripts/chatot_post.pory"
	playmoncry SPECIES_CHATOT, CRY_MODE_NORMAL
# 65 "data/scripts/chatot_post.pory"
	setspeakertomonname SPECIES_CHATOT
# 66 "data/scripts/chatot_post.pory"
	msgbox ChatotPost_EventScript_Chatot_Text_3, MSGBOX_DEFAULT
# 67 "data/scripts/chatot_post.pory"
	releaseall
	end

ChatotPost_EventScript_Chatot_2:
# 19 "data/scripts/chatot_post.pory"
	setspeakertomonname SPECIES_CHATOT
# 21 "data/scripts/chatot_post.pory"
	checkchatotpostnumber
# 22 "data/scripts/chatot_post.pory"
	compare VAR_RESULT, 1
	goto_if_eq ChatotPost_EventScript_Chatot_6
# 28 "data/scripts/chatot_post.pory"
	buffernumberstring STR_VAR_2, VAR_RESULT
# 29 "data/scripts/chatot_post.pory"
	msgbox ChatotPost_EventScript_Chatot_Text_1
ChatotPost_EventScript_Chatot_5:
# 35 "data/scripts/chatot_post.pory"
	closemessage
# 36 "data/scripts/chatot_post.pory"
	delay 24
# 38 "data/scripts/chatot_post.pory"
	readchatotpost
	checkchatotpost
# 0 "data/scripts/chatot_post.pory"
	compare VAR_RESULT, 0
	goto_if_ne ChatotPost_EventScript_Chatot_10
ChatotPost_EventScript_Chatot_9:
	checkchatotpost
# 0 "data/scripts/chatot_post.pory"
	compare VAR_RESULT, 0
	goto_if_ne ChatotPost_EventScript_Chatot_12
	goto ChatotPost_EventScript_Chatot_1

ChatotPost_EventScript_Chatot_6:
# 23 "data/scripts/chatot_post.pory"
	msgbox ChatotPost_EventScript_Chatot_Text_0
	goto ChatotPost_EventScript_Chatot_5

ChatotPost_EventScript_Chatot_10:
# 42 "data/scripts/chatot_post.pory"
	call ChatotPost_EventScript_NextMessage
	goto ChatotPost_EventScript_Chatot_9

ChatotPost_EventScript_Chatot_12:
# 47 "data/scripts/chatot_post.pory"
	call ChatotPost_EventScript_NextMessage
	goto ChatotPost_EventScript_Chatot_1


ChatotPost_EventScript_NextMessage:
# 72 "data/scripts/chatot_post.pory"
	playmoncry SPECIES_CHATOT, CRY_MODE_NORMAL
# 73 "data/scripts/chatot_post.pory"
	applymovement VAR_LAST_TALKED, ChatotPost_EventScript_Chatot_Movement_1
# 75 "data/scripts/chatot_post.pory"
	setspeakertomonname SPECIES_CHATOT
# 77 "data/scripts/chatot_post.pory"
	random 4
# 78 "data/scripts/chatot_post.pory"
	switch VAR_RESULT
# 79 "data/scripts/chatot_post.pory"
	case 0, ChatotPost_EventScript_NextMessage_3
# 81 "data/scripts/chatot_post.pory"
	case 1, ChatotPost_EventScript_NextMessage_4
# 83 "data/scripts/chatot_post.pory"
	case 2, ChatotPost_EventScript_NextMessage_5
# 85 "data/scripts/chatot_post.pory"
	case 3, ChatotPost_EventScript_NextMessage_6
ChatotPost_EventScript_NextMessage_1:
# 89 "data/scripts/chatot_post.pory"
	readchatotpost
	return

ChatotPost_EventScript_NextMessage_3:
# 80 "data/scripts/chatot_post.pory"
	msgbox Text_Chatot_Next1
	goto ChatotPost_EventScript_NextMessage_1

ChatotPost_EventScript_NextMessage_4:
# 82 "data/scripts/chatot_post.pory"
	msgbox Text_Chatot_Next2
	goto ChatotPost_EventScript_NextMessage_1

ChatotPost_EventScript_NextMessage_5:
# 84 "data/scripts/chatot_post.pory"
	msgbox Text_Chatot_Next3
	goto ChatotPost_EventScript_NextMessage_1

ChatotPost_EventScript_NextMessage_6:
# 86 "data/scripts/chatot_post.pory"
	msgbox Text_Chatot_Next4
	goto ChatotPost_EventScript_NextMessage_1


ChatotPost_EventScript_EmptyPost::
# 93 "data/scripts/chatot_post.pory"
	lock
# 94 "data/scripts/chatot_post.pory"
	setnamedmon SPECIES_CHATOT
# 95 "data/scripts/chatot_post.pory"
	msgbox ChatotPost_EventScript_EmptyPost_Text_0
# 96 "data/scripts/chatot_post.pory"
	closemessage
# 97 "data/scripts/chatot_post.pory"
	release
	return


ChatotPost_EventScript_None::
	return


ChatotPost_EventScript_FromHariko::
# 125 "data/scripts/chatot_post.pory"
	setspeakertomonname SPECIES_CHATOT
# 126 "data/scripts/chatot_post.pory"
	msgbox ChatotPost_EventScript_FromHariko_Text_0
# 131 "data/scripts/chatot_post.pory"
	fadescreen FADE_TO_BLACK
# 132 "data/scripts/chatot_post.pory"
	delay 48
# 133 "data/scripts/chatot_post.pory"
	closemessage
# 134 "data/scripts/chatot_post.pory"
	fadescreen FADE_FROM_BLACK
# 135 "data/scripts/chatot_post.pory"
	setspeakertomonname SPECIES_CHATOT
# 136 "data/scripts/chatot_post.pory"
	msgbox ChatotPost_EventScript_FromHariko_Text_1
# 137 "data/scripts/chatot_post.pory"
	closemessage
# 139 "data/scripts/chatot_post.pory"
	setnamedmon SPECIES_CHATOT
# 140 "data/scripts/chatot_post.pory"
	setnamedmon SPECIES_WAILORD
	return


ChatotPost_EventScript_FromBigSis::
# 145 "data/scripts/chatot_post.pory"
	special GetPlayerBrotherSisterString
# 146 "data/scripts/chatot_post.pory"
	setspeakertomonname SPECIES_CHATOT
# 147 "data/scripts/chatot_post.pory"
	msgbox ChatotPost_EventScript_FromBigSis_Text_0
# 154 "data/scripts/chatot_post.pory"
	closemessage
# 156 "data/scripts/chatot_post.pory"
	giveitem ITEM_ENTEI_STATUETTE
# 158 "data/scripts/chatot_post.pory"
	setnamedmon SPECIES_CHATOT
	return


ChatotPost_EventScript_Post_NatsukiRareCandy::
# 163 "data/scripts/chatot_post.pory"
	closemessage
# 164 "data/scripts/chatot_post.pory"
	setspeakertomonname SPECIES_CHATOT
# 165 "data/scripts/chatot_post.pory"
	goto_if_set FLAG_BADGE02_GET, ChatotPost_EventScript_Post_NatsukiRareCandy_2
# 174 "data/scripts/chatot_post.pory"
	msgbox ChatotPost_EventScript_Post_NatsukiRareCandy_Text_1
ChatotPost_EventScript_Post_NatsukiRareCandy_1:
# 181 "data/scripts/chatot_post.pory"
	closemessage
# 183 "data/scripts/chatot_post.pory"
	giveitem ITEM_RARE_CANDY
# 185 "data/scripts/chatot_post.pory"
	setnamedmon SPECIES_CHATOT
	return

ChatotPost_EventScript_Post_NatsukiRareCandy_2:
# 166 "data/scripts/chatot_post.pory"
	msgbox ChatotPost_EventScript_Post_NatsukiRareCandy_Text_0
	goto ChatotPost_EventScript_Post_NatsukiRareCandy_1


ChatotPost_EventScript_MichaelIrvin::
# 190 "data/scripts/chatot_post.pory"
	setspeakertomonname SPECIES_CHATOT
# 191 "data/scripts/chatot_post.pory"
	msgbox ChatotPost_EventScript_MichaelIrvin_Text_0
# 201 "data/scripts/chatot_post.pory"
	closemessage
	return


ChatotPost_EventScript_PechaOvergrown::
# 206 "data/scripts/chatot_post.pory"
	setspeakertomonname SPECIES_CHATOT
# 207 "data/scripts/chatot_post.pory"
	msgbox ChatotPost_EventScript_PechaOvergrown_Text_0
# 211 "data/scripts/chatot_post.pory"
	closemessage
# 213 "data/scripts/chatot_post.pory"
	giveitem ITEM_RARE_CANDY
	return


ChatotPost_EventScript_DessertCatastrophe::
# 220 "data/scripts/chatot_post.pory"
	setspeakertomonname SPECIES_CHATOT
# 221 "data/scripts/chatot_post.pory"
	msgbox ChatotPost_EventScript_DessertCatastrophe_Text_0
# 230 "data/scripts/chatot_post.pory"
	closemessage
# 232 "data/scripts/chatot_post.pory"
	giveitem ITEM_LEFTOVERS
	return


ChatotPost_EventScript_BigSisLeftovers::
# 239 "data/scripts/chatot_post.pory"
	setspeakertomonname SPECIES_CHATOT
# 240 "data/scripts/chatot_post.pory"
	msgbox ChatotPost_EventScript_BigSisLeftovers_Text_0
# 246 "data/scripts/chatot_post.pory"
	closemessage
# 248 "data/scripts/chatot_post.pory"
	giveitem ITEM_LEFTOVERS
	return


ChatotPost_EventScript_TrainerMessage::
# 258 "data/scripts/chatot_post.pory"
	setspeakertomonname SPECIES_CHATOT
# 259 "data/scripts/chatot_post.pory"
	msgbox gStringVar4
# 260 "data/scripts/chatot_post.pory"
	closemessage
	return


# 9 "data/scripts/chatot_post.pory"
ChatotPost_EventScript_Chatot_Movement_0:
# 9 "data/scripts/chatot_post.pory"
	jump_in_place_down
	step_end

# 14 "data/scripts/chatot_post.pory"
ChatotPost_EventScript_Chatot_Movement_1:
# 14 "data/scripts/chatot_post.pory"
	emote_music
	step_end

ChatotPost_EventScript_Chatot_Text_0:
# 24 "data/scripts/chatot_post.pory"
	.string "SQWAK!{PAUSE 8} POST FOR YOU!{PAUSE 8} SQWAK!{PAUSE 8}\n"
	.string "THIS IS FROM “{STR_VAR_1}”…$"

ChatotPost_EventScript_Chatot_Text_1:
# 30 "data/scripts/chatot_post.pory"
	.string "SQWAK!{PAUSE 8} POST FOR YOU!{PAUSE 8} SQWAK!{PAUSE 8}\n"
	.string "{STR_VAR_2} NEW MESSAGES!{PAUSE 8} SQWAK!\p"
	.string "FIRST MESSAGE FROM “{STR_VAR_1}”…$"

ChatotPost_EventScript_Chatot_Text_2:
# 53 "data/scripts/chatot_post.pory"
	.string "SQWAK!{PAUSE 8} NO MORE POST!$"

ChatotPost_EventScript_Chatot_Text_3:
# 66 "data/scripts/chatot_post.pory"
	.string "SQWAK!$"

ChatotPost_EventScript_EmptyPost_Text_0:
# 95 "data/scripts/chatot_post.pory"
	.string "It reads: “Chatot Post”.\n"
	.string "… …No Chatot in sight!$"

ChatotPost_EventScript_FromHariko_Text_0:
# 127 "data/scripts/chatot_post.pory"
	.string "“Hello {PLAYER}!\n"
	.string "Do you want to hear a fun fact?\p"
	.string "Did you know that Wailord aren't\n"
	.string "actually the biggest living things?\p"
	.string "The biggest living things are actually\n"
	.string "mushrooms, because…$"

ChatotPost_EventScript_FromHariko_Text_1:
# 136 "data/scripts/chatot_post.pory"
	.string "…also did you know…\p"
	.string "Wait… Chatot!\p"
	.string "Come back, Chatot!”$"

ChatotPost_EventScript_FromBigSis_Text_0:
# 148 "data/scripts/chatot_post.pory"
	.string "“Chatot, are you listening to me?\n"
	.string "Hey, look this way-{PAUSE 8} pspsps!\p"
	.string "Ahem, hey little {STR_VAR_1}!\n"
	.string "Hope you're missing me already!\p"
	.string "You forgot your lucky Entei Statuette\n"
	.string "when you left.\p"
	.string "I like the tradition, so indulge me,\n"
	.string "okay? Please? Everyone carries one!\p"
	.string "See you soon {PLAYER}, love you.”$"

ChatotPost_EventScript_Post_NatsukiRareCandy_Text_0:
# 167 "data/scripts/chatot_post.pory"
	.string "“What's up, {PLAYER}?\n"
	.string "It's your bestie Natsuki.\p"
	.string "I heard you did well in your battle\n"
	.string "against Hana.\l"
	.string "Two tokens already, huh?\p"
	.string "You might be a stronger rival than I\n"
	.string "anticipated! I gotta work harder!\p"
	.string "Here's a little gift from me to you, I\n"
	.string "think your Pokémon will like it.\p"
	.string "See you around, {PLAYER}.”$"

ChatotPost_EventScript_Post_NatsukiRareCandy_Text_1:
# 175 "data/scripts/chatot_post.pory"
	.string "“What's up, {PLAYER}?\nIt's your bestie Natsuki.\p"
	.string "Have you beaten that Hana lady\nalready?\lI bet you got your butt handed to ya!\p"
	.string "Here's a little something to help you\nout! I think your Pokémon will like it!\p"
	.string "See you around, {PLAYER}.”$"

ChatotPost_EventScript_MichaelIrvin_Text_0:
# 192 "data/scripts/chatot_post.pory"
	.string "Listen to everybody - nobody,\l"
	.string "NOBODY believes in you!\p"
	.string "WHAT! ARE YOU PREPARED!\lTO DO ABOUT IT?!!\p"
	.string "DON'T LET THEM COME INTO -\n"
	.string "YOUR HOUSE!\n"
	.string "TAKE -\n"
	.string "YOUR MEAL!\n"
	.string "DO WHAT YOU NEED TO DO, TO-DAY!!!$"

ChatotPost_EventScript_PechaOvergrown_Text_0:
# 207 "data/scripts/chatot_post.pory"
	.string "I don't know who you are. I don't know\n"
	.string "what you want. But I grew too many\l"
	.string "Pecha berries, so...I hope you have a\l"
	.string "sweet tooth!$"

ChatotPost_EventScript_DessertCatastrophe_Text_0:
# 222 "data/scripts/chatot_post.pory"
	.string "Listen to me very carefully.\p"
	.string "I have made a fresh batch of cherry\n"
	.string "cookies to be delivered at random to a\l"
	.string "trainer of pure heart.\p"
	.string "If you have grown tired on your\n"
	.string "journey, one bite of these sweets will\l"
	.string "fill you with renewed resolve!\p"
	.string "I hope you enjoy eating these as much\n"
	.string "as I did making them! And please, keep\l"
	.string "them away from your Pokemon. Wait a\l"
	.string "minute...$"

ChatotPost_EventScript_BigSisLeftovers_Text_0:
# 240 "data/scripts/chatot_post.pory"
	.string "Hey little {STR_VAR_1}!\l"
	.string "You must be homesick on your big\l"
	.string "journey, huh?\p"
	.string "Well I went ahead and made a batch of\n"
	.string "your favorite dish! I bet you were\l"
	.string "salivating soon as you saw Chatot on\l"
	.string "the perch, huh?\p"
	.string "I really hope you enjoy it. If anybody\n"
	.string "else gets their hands on this dish... I'll\l"
	.string "cry!$"

Text_Chatot_Next1:
# 105 "data/scripts/chatot_post.pory"
	.string "HERE'S ANOTHER FROM “{STR_VAR_1}”!{PAUSE 8}\n"
	.string "SQWAK!$"

Text_Chatot_Next2:
# 109 "data/scripts/chatot_post.pory"
	.string "SQWAK!{PAUSE 8}\n"
	.string "NEXT MESSAGE, FROM “{STR_VAR_1}”!$"

Text_Chatot_Next3:
# 113 "data/scripts/chatot_post.pory"
	.string "SQWAK!{PAUSE 8} ANOTHER MESSAGE!{PAUSE 8}\n"
	.string "FROM “{STR_VAR_1}”!{PAUSE 8} SQWAK!$"

Text_Chatot_Next4:
# 117 "data/scripts/chatot_post.pory"
	.string "SQWAK SQWAK!{PAUSE 8} ONE MORE!\n"
	.string "FROM “{STR_VAR_1}”!$"

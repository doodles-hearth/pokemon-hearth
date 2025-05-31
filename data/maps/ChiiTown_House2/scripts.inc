ChiiTown_House2_MapScripts::
	.byte 0


ChiiTown_House2_Child::
	speakername ChiiTown_House2_Child_Text_0
	msgbox ChiiTown_House2_Child_Text_1, MSGBOX_NPC
	return


ChiiTown_House2_Parent::
	speakername ChiiTown_House2_Parent_Text_0
	msgbox ChiiTown_House2_Parent_Text_1, MSGBOX_NPC
	return


ChiiTown_House2_Child_Text_0:
	.string "Little girl$"

ChiiTown_House2_Child_Text_1:
	.string "Mama said there's a BIIIG library in a\n"
	.string "town far away from here!\p"
	.string "One day, I'll read ALLLL the books in\n"
	.string "that library!$"

ChiiTown_House2_Parent_Text_0:
	.string "Woman$"

ChiiTown_House2_Parent_Text_1:
	.string "My daughter loves reading. I don't\n"
	.string "read her bedtime stories, she reads\l"
	.string "them to me!$"

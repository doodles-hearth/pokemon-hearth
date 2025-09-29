ChiiTown_House2_MapScripts::
	.byte 0


ChiiTown_House2_Child::
	setspeaker SP_NAME_LITTLE_GIRL
	msgbox ChiiTown_House2_Child_Text_0, MSGBOX_NPC
	return


ChiiTown_House2_Parent::
	setspeaker SP_NAME_WOMAN
	msgbox ChiiTown_House2_Parent_Text_0, MSGBOX_NPC
	return


ChiiTown_House2_Child_Text_0:
	.string "Mama said there's a BIIIG library in a\n"
	.string "town far away from here!\p"
	.string "One day, I'll read ALLLL the books in\n"
	.string "that library!$"

ChiiTown_House2_Parent_Text_0:
	.string "My daughter loves reading. I don't\n"
	.string "read her bedtime stories, she reads\l"
	.string "them to me!$"

EventScript_ClayFurnace::
	msgbox EventScript_ClayFurnace_Text_0
	closemessage
	playmoncry SPECIES_SLUGMA, CRY_MODE_NORMAL
	getnamedmon SPECIES_SLUGMA
	compare VAR_RESULT, 0
	goto_if_ne EventScript_ClayFurnace_2
	msgbox EventScript_ClayFurnace_Text_2
EventScript_ClayFurnace_1:
	setseenmon SPECIES_SLUGMA
	waitmoncry
	closemessage
	return

EventScript_ClayFurnace_2:
	msgbox EventScript_ClayFurnace_Text_1
	goto EventScript_ClayFurnace_1



EventScript_PictureBookShelf::
	msgbox Text_PictureBookShelf, MSGBOX_SIGN
	end

EventScript_BookShelf::
	msgbox Text_BookShelf, MSGBOX_SIGN
	end

EventScript_PokemonCenterBookShelf::
	msgbox Text_PokemonCenterBookShelf, MSGBOX_SIGN
	end

EventScript_Vase::
	msgbox Text_Vase, MSGBOX_SIGN
	end

EventScript_EmptyTrashCan::
	msgbox Text_EmptyTrashCan, MSGBOX_SIGN
	end

EventScript_ShopShelf::
	msgbox Text_ShopShelf, MSGBOX_SIGN
	end

EventScript_Blueprint::
	msgbox Text_Blueprint, MSGBOX_SIGN
	end

EventScript_ClayFurnace_Text_0:
	.string "The fire dances in the furnace.$"

EventScript_ClayFurnace_Text_1:
	.string "…Hey, there's a Slugma in here!$"

EventScript_ClayFurnace_Text_2:
	.string "…Hey, there's a Pokémon in here!$"

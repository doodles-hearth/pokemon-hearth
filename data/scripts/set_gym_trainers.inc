Common_EventScript_SetGymTrainers::
	switch VAR_0x8008
	case 1, Common_EventScript_SetGymTrainers_2
	case 2, Common_EventScript_SetGymTrainers_3
	case 3, Common_EventScript_SetGymTrainers_4
	case 4, Common_EventScript_SetGymTrainers_5
	case 5, Common_EventScript_SetGymTrainers_6
	case 6, Common_EventScript_SetGymTrainers_7
	case 7, Common_EventScript_SetGymTrainers_8
	case 8, Common_EventScript_SetGymTrainers_9
	return

Common_EventScript_SetGymTrainers_2:
	call KoiPond_Dojo_SetGymTrainers
	return

Common_EventScript_SetGymTrainers_3:
	call Bonsai_Dojo_SetGymTrainers
	return

Common_EventScript_SetGymTrainers_4:
	call YifuCity_Dojo_SetGymTrainers
	return

Common_EventScript_SetGymTrainers_5:
	call LavaridgeTown_Gym_SetGymTrainers
	return

Common_EventScript_SetGymTrainers_6:
	call PetalburgCity_Gym_SetGymTrainers
	return

Common_EventScript_SetGymTrainers_7:
	call FortreeCity_Gym_SetGymTrainers
	return

Common_EventScript_SetGymTrainers_8:
	call MossdeepCity_Gym_SetGymTrainers
	return

Common_EventScript_SetGymTrainers_9:
	call SootopolisCity_Gym_SetGymTrainers
	return


KoiPond_Dojo_SetGymTrainers::
	settrainerflag TRAINER_IZUMI
	settrainerflag TRAINER_REN
	settrainerflag TRAINER_MIZU
	return


Bonsai_Dojo_SetGymTrainers::
	settrainerflag TRAINER_TAKAO
	settrainerflag TRAINER_JOCELYN
	settrainerflag TRAINER_LAURA
	settrainerflag TRAINER_BRENDEN
	settrainerflag TRAINER_CRISTIAN
	settrainerflag TRAINER_LILITH
	return


YifuCity_Dojo_SetGymTrainers::
	settrainerflag TRAINER_AKARI
	settrainerflag TRAINER_YUKA
	settrainerflag TRAINER_KANAE
	settrainerflag TRAINER_NANAMI
	settrainerflag TRAINER_MIIKA
	return


LavaridgeTown_Gym_SetGymTrainers::
	settrainerflag TRAINER_COLE
	settrainerflag TRAINER_AXLE
	settrainerflag TRAINER_KEEGAN
	settrainerflag TRAINER_GERALD
	settrainerflag TRAINER_DANIELLE
	settrainerflag TRAINER_JACE
	settrainerflag TRAINER_JEFF
	settrainerflag TRAINER_ELI
	return


PetalburgCity_Gym_SetGymTrainers::
	settrainerflag TRAINER_RANDALL
	settrainerflag TRAINER_PARKER
	settrainerflag TRAINER_GEORGE
	settrainerflag TRAINER_BERKE
	settrainerflag TRAINER_MARY
	settrainerflag TRAINER_ALEXIA
	settrainerflag TRAINER_JODY
	return


FortreeCity_Gym_SetGymTrainers::
	settrainerflag TRAINER_JARED
	settrainerflag TRAINER_FLINT
	settrainerflag TRAINER_ASHLEY
	settrainerflag TRAINER_EDWARDO
	settrainerflag TRAINER_HUMBERTO
	settrainerflag TRAINER_DARIUS
	return


MossdeepCity_Gym_SetGymTrainers::
	settrainerflag TRAINER_PRESTON
	settrainerflag TRAINER_VIRGIL
	settrainerflag TRAINER_BLAKE
	settrainerflag TRAINER_HANNAH
	settrainerflag TRAINER_SAMANTHA
	settrainerflag TRAINER_MAURA
	settrainerflag TRAINER_SYLVIA
	settrainerflag TRAINER_NATE
	settrainerflag TRAINER_KATHLEEN
	settrainerflag TRAINER_CLIFFORD
	settrainerflag TRAINER_MACEY
	settrainerflag TRAINER_NICHOLAS
	return


SootopolisCity_Gym_SetGymTrainers::
	settrainerflag TRAINER_ANDREA
	settrainerflag TRAINER_CRISSY
	settrainerflag TRAINER_BRIANNA
	settrainerflag TRAINER_CONNIE
	settrainerflag TRAINER_BRIDGET
	settrainerflag TRAINER_OLIVIA
	settrainerflag TRAINER_TIFFANY
	settrainerflag TRAINER_BETHANY
	settrainerflag TRAINER_ANNIKA
	settrainerflag TRAINER_DAPHNE
	return


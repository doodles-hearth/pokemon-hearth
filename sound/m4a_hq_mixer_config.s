/* HQ-Mixer rev 4.0 created by ipatix (c) 2021
 * licensed under GPLv3, see LICENSE.txt for details */

	/**********************
	 * CONFIGURATION AREA *
	 **********************/

	.equ ENABLE_REVERB, 1                        @ <-- if you want faster code or don't like reverb, set this to '0', set to '1' otherwise
	.equ ENABLE_DMA, 1                           @ <-- Using DMA produces smaller code and has better performance. Disable it if your case does not allow to use DMA.

	/*****************
	 * END OF CONFIG *
	 *****************/

	/* NO USER SERVICABLE CODE BELOW HERE! YOU HAVE BEEN WARNED */

	.equ FRAME_LENGTH_5734, 0x60
	.equ FRAME_LENGTH_7884, 0x84             @ THIS MODE IS NOT SUPPORTED BY THIS ENGINE BECAUSE IT DOESN'T USE AN 8 ALIGNED BUFFER LENGTH
	.equ FRAME_LENGTH_10512, 0xB0
	.equ FRAME_LENGTH_13379, 0xE0            @ DEFAULT
	.equ FRAME_LENGTH_15768, 0x108
	.equ FRAME_LENGTH_18157, 0x130
	.equ FRAME_LENGTH_21024, 0x160
	.equ FRAME_LENGTH_26758, 0x1C0
	.equ FRAME_LENGTH_31536, 0x210
	.equ FRAME_LENGTH_36314, 0x260
	.equ FRAME_LENGTH_40137, 0x2A0
	.equ FRAME_LENGTH_42048, 0x2C0

	/* stack variables */
	.equ ARG_FRAME_LENGTH, 0x0               @ Number of samples per frame/buffer
	.equ ARG_REMAIN_CHN, 0x4                 @ temporary to count down the channels to process
	.equ ARG_BUFFER_POS, 0x8                 @ stores the current output buffer pointer
	.equ ARG_LOOP_START_POS, 0xC             @ stores wave loop start position in channel loop
	.equ ARG_LOOP_LENGTH, 0x10               @   ''    ''   ''  end position
	.equ ARG_BUFFER_POS_INDEX_HINT, 0x14     @ if this value is == 2, then this is the last buffer before wraparound
	.equ ARG_PCM_STRUCT, 0x18                @ pointer to engine the main work area

	/* pulse wave synth configuration offset */
	.equ SYNTH_TYPE, 0x1                     @ [byte]
	.equ SYNTH_BASE_WAVE_DUTY, 0x2           @ [byte]
	.equ SYNTH_WIDTH_CHANGE_1, 0x3           @ [byte]
	.equ SYNTH_MOD_AMOUNT, 0x4               @ [byte]
	.equ SYNTH_WIDTH_CHANGE_2, 0x5           @ [byte]

	.equ MODE_FLGSH_SIGN_REVERSE, 27         @ shift by n bits to get the reverse flag into SIGN

	/* variables of the engine work area */
	.equ VAR_REVERB, 0x5                     @ [byte] 0-127 = reverb level
	.equ VAR_MAX_CHN, 0x6                    @ [byte] maximum channels to process
	.equ VAR_MASTER_VOL, 0x7                 @ [byte] PCM master volume
	.equ VAR_EXT_NOISE_SHAPE_LEFT, 0xE       @ [byte] normally unused, used here for noise shaping
	.equ VAR_EXT_NOISE_SHAPE_RIGHT, 0xF      @ [byte] normally unused, used here for noise shaping
	.equ VAR_DEF_PITCH_FAC, 0x18             @ [word] this value gets multiplied with the samplerate for the inter sample distance
	.equ VAR_FIRST_CHN, 0x50                 @ [CHN struct] relative offset to channel array
	.equ VAR_PCM_BUFFER, 0x350

	/* just some more defines */
	.equ ARM_OP_LEN, 0x4

	/* extensions */
	.equ BDPCM_BLK_STRIDE, 0x21
	.equ BDPCM_BLK_SIZE, 0x40
	.equ BDPCM_BLK_SIZE_MASK, 0x3F
	.equ BDPCM_BLK_SIZE_SHIFT, 0x6

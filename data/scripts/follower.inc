EventScript_Follower::
# 2 "data/scripts/follower.pory"
	random 3
# 4 "data/scripts/follower.pory"
	switch VAR_RESULT
# 5 "data/scripts/follower.pory"
	case 0, EventScript_Follower_3
# 15 "data/scripts/follower.pory"
	case 1, EventScript_Follower_4
# 25 "data/scripts/follower.pory"
	case 2, EventScript_Follower_5
EventScript_Follower_1:
# 58 "data/scripts/follower.pory"
	release
	return

EventScript_Follower_3:
# 6 "data/scripts/follower.pory"
	lock
# 7 "data/scripts/follower.pory"
	faceplayer
# 8 "data/scripts/follower.pory"
	playfirstmoncry
# 9 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, Spinda_emote_love
# 10 "data/scripts/follower.pory"
	waitmovement 0
# 11 "data/scripts/follower.pory"
	waitmoncry
# 12 "data/scripts/follower.pory"
	msgbox EventScript_Follower_Text_0
# 13 "data/scripts/follower.pory"
	closemessage
# 14 "data/scripts/follower.pory"
	release
	goto EventScript_Follower_1

EventScript_Follower_4:
# 16 "data/scripts/follower.pory"
	lock
# 17 "data/scripts/follower.pory"
	faceplayer
# 18 "data/scripts/follower.pory"
	playfirstmoncry
# 19 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, Spinda_dizzy
# 20 "data/scripts/follower.pory"
	waitmovement 0
# 21 "data/scripts/follower.pory"
	waitmoncry
# 22 "data/scripts/follower.pory"
	msgbox EventScript_Follower_Text_1
# 23 "data/scripts/follower.pory"
	closemessage
# 24 "data/scripts/follower.pory"
	release
	goto EventScript_Follower_1

EventScript_Follower_5:
# 26 "data/scripts/follower.pory"
	lock
# 27 "data/scripts/follower.pory"
	faceplayer
# 28 "data/scripts/follower.pory"
	playfirstmoncry
# 29 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, Spinda_jump
# 30 "data/scripts/follower.pory"
	waitmoncry
# 31 "data/scripts/follower.pory"
	waitmovement 0
# 32 "data/scripts/follower.pory"
	release
	goto EventScript_Follower_1


# 61 "data/scripts/follower.pory"
Spinda_emote_love:
# 62 "data/scripts/follower.pory"
	lock_facing_direction
# 63 "data/scripts/follower.pory"
	jump_in_place_down
# 64 "data/scripts/follower.pory"
	unlock_facing_direction
# 65 "data/scripts/follower.pory"
	emote_heart
	step_end

# 68 "data/scripts/follower.pory"
Spinda_dizzy:
# 69 "data/scripts/follower.pory"
	face_down
# 70 "data/scripts/follower.pory"
	delay_16
# 71 "data/scripts/follower.pory"
	face_up
# 72 "data/scripts/follower.pory"
	delay_16
# 73 "data/scripts/follower.pory"
	face_left
# 74 "data/scripts/follower.pory"
	delay_16
# 75 "data/scripts/follower.pory"
	face_down
# 76 "data/scripts/follower.pory"
	delay_16
# 77 "data/scripts/follower.pory"
	face_player
# 78 "data/scripts/follower.pory"
	delay_16
	step_end

# 81 "data/scripts/follower.pory"
Spinda_jump:
# 82 "data/scripts/follower.pory"
	lock_facing_direction
# 83 "data/scripts/follower.pory"
	jump_in_place_down
# 84 "data/scripts/follower.pory"
	unlock_facing_direction
	step_end

# 87 "data/scripts/follower.pory"

# 88 "data/scripts/follower.pory"
gText_FollowerLovesYou::
# 89 "data/scripts/follower.pory"
	.string "{STR_VAR_1} is regarding you with\nadoration!$"
# 90 "data/scripts/follower.pory"

# 91 "data/scripts/follower.pory"
gText_FollowerLostInThought::
# 92 "data/scripts/follower.pory"
	.string "{STR_VAR_1} seems lost in thought.$"
# 93 "data/scripts/follower.pory"

# 94 "data/scripts/follower.pory"
gText_FollowerDefault::
# 95 "data/scripts/follower.pory"
	.string "ERROR 404: Script not found.$"
# 96 "data/scripts/follower.pory"

# 97 "data/scripts/follower.pory"
gText_WantsToFly::
# 98 "data/scripts/follower.pory"
	.string "{STR_VAR_1} looks up at the\nsky restlessly.\pWould you like to use FLY?$"
# 99 "data/scripts/follower.pory"
@ TODO EVA ICI follower override?
# 100 "data/scripts/follower.pory"
@EventScript_Follower::
# 101 "data/scripts/follower.pory"
@	lock
# 102 "data/scripts/follower.pory"
@	bufferlivemonnickname 0
# 103 "data/scripts/follower.pory"
@	playfirstmoncry
# 104 "data/scripts/follower.pory"
@	getfolloweraction
# 105 "data/scripts/follower.pory"
EventScript_FollowerEnd::
# 106 "data/scripts/follower.pory"
	waitfieldeffect FLDEFF_EMOTE
# 107 "data/scripts/follower.pory"
	release
# 108 "data/scripts/follower.pory"
	end
# 109 "data/scripts/follower.pory"

# 110 "data/scripts/follower.pory"
EventScript_FollowerLovesYou::
# 111 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, ContestHall_Movement_Heart
# 112 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 113 "data/scripts/follower.pory"
	waitmoncry
# 114 "data/scripts/follower.pory"
	msgbox gText_FollowerLovesYou, MSGBOX_DEFAULT
# 115 "data/scripts/follower.pory"
	return
# 116 "data/scripts/follower.pory"

# 117 "data/scripts/follower.pory"
@ Message address must be loaded into bank 0
# 118 "data/scripts/follower.pory"
EventScript_FollowerGeneric:: @ similar to Std_MsgboxDefault
# 119 "data/scripts/follower.pory"
	faceplayer
# 120 "data/scripts/follower.pory"
EventScript_FollowerGenericSkipFace:
# 121 "data/scripts/follower.pory"
	waitfieldeffect FLDEFF_EMOTE
# 122 "data/scripts/follower.pory"
	message 0x0
# 123 "data/scripts/follower.pory"
	waitmessage
# 124 "data/scripts/follower.pory"
	waitbuttonpress
# 125 "data/scripts/follower.pory"
	return
# 126 "data/scripts/follower.pory"

# 127 "data/scripts/follower.pory"
EventScript_FollowerJump::
# 128 "data/scripts/follower.pory"
	faceplayer
# 129 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerSplashMovement
# 130 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 131 "data/scripts/follower.pory"
	waitfieldeffect FLDEFF_EMOTE
# 132 "data/scripts/follower.pory"
	message 0x0
# 133 "data/scripts/follower.pory"
	waitmessage
# 134 "data/scripts/follower.pory"
	waitbuttonpress
# 135 "data/scripts/follower.pory"
	return
# 136 "data/scripts/follower.pory"

# 137 "data/scripts/follower.pory"
EnterPokeballMovement::
# 138 "data/scripts/follower.pory"
	enter_pokeball
# 139 "data/scripts/follower.pory"
	step_end
# 140 "data/scripts/follower.pory"

# 141 "data/scripts/follower.pory"
@ Movement scripts below, movements are defined in movement.inc
# 142 "data/scripts/follower.pory"

# 143 "data/scripts/follower.pory"
FollowerSplashMovement::
# 144 "data/scripts/follower.pory"
	jump_in_place_down
# 145 "data/scripts/follower.pory"
	delay_4
# 146 "data/scripts/follower.pory"
	jump_in_place_down
# 147 "data/scripts/follower.pory"
	face_player
# 148 "data/scripts/follower.pory"
	step_end
# 149 "data/scripts/follower.pory"

# 150 "data/scripts/follower.pory"
FollowerShiverVerticalMovement:
# 151 "data/scripts/follower.pory"
	lock_facing_direction
# 152 "data/scripts/follower.pory"
	slide_left
# 153 "data/scripts/follower.pory"
	slide_right
# 154 "data/scripts/follower.pory"
	slide_right
# 155 "data/scripts/follower.pory"
	slide_left
# 156 "data/scripts/follower.pory"
	unlock_facing_direction
# 157 "data/scripts/follower.pory"
	step_end
# 158 "data/scripts/follower.pory"

# 159 "data/scripts/follower.pory"
FollowerShiverHorizontalMovement:
# 160 "data/scripts/follower.pory"
	lock_facing_direction
# 161 "data/scripts/follower.pory"
	slide_up
# 162 "data/scripts/follower.pory"
	slide_down
# 163 "data/scripts/follower.pory"
	slide_down
# 164 "data/scripts/follower.pory"
	slide_up
# 165 "data/scripts/follower.pory"
	unlock_facing_direction
# 166 "data/scripts/follower.pory"
	step_end
# 167 "data/scripts/follower.pory"

# 168 "data/scripts/follower.pory"
FollowerNostalgiaMovement:
# 169 "data/scripts/follower.pory"
	face_away_player
# 170 "data/scripts/follower.pory"
	lock_facing_direction
# 171 "data/scripts/follower.pory"
	jump_in_place_down
# 172 "data/scripts/follower.pory"
	jump_in_place_down
# 173 "data/scripts/follower.pory"
	jump_in_place_down
# 174 "data/scripts/follower.pory"
	unlock_facing_direction
# 175 "data/scripts/follower.pory"
	face_player
# 176 "data/scripts/follower.pory"
	lock_facing_direction
# 177 "data/scripts/follower.pory"
	jump_in_place_down
# 178 "data/scripts/follower.pory"
	unlock_facing_direction
# 179 "data/scripts/follower.pory"
	step_end
# 180 "data/scripts/follower.pory"

# 181 "data/scripts/follower.pory"
FollowerSkippingMovement:
# 182 "data/scripts/follower.pory"
	lock_facing_direction
# 183 "data/scripts/follower.pory"
	jump_in_place_down
# 184 "data/scripts/follower.pory"
	delay_4
# 185 "data/scripts/follower.pory"
	jump_in_place_down
# 186 "data/scripts/follower.pory"
	unlock_facing_direction
# 187 "data/scripts/follower.pory"
	step_end
# 188 "data/scripts/follower.pory"

# 189 "data/scripts/follower.pory"
FollowerJumpOnPlayerNorth:
# 190 "data/scripts/follower.pory"
	jump_up
# 191 "data/scripts/follower.pory"
	delay_4
# 192 "data/scripts/follower.pory"
	lock_facing_direction
# 193 "data/scripts/follower.pory"
	walk_fast_down
# 194 "data/scripts/follower.pory"
	unlock_facing_direction
# 195 "data/scripts/follower.pory"
	step_end
# 196 "data/scripts/follower.pory"

# 197 "data/scripts/follower.pory"
FollowerJumpOnPlayerSouth:
# 198 "data/scripts/follower.pory"
	jump_down
# 199 "data/scripts/follower.pory"
	delay_4
# 200 "data/scripts/follower.pory"
	lock_facing_direction
# 201 "data/scripts/follower.pory"
	walk_fast_up
# 202 "data/scripts/follower.pory"
	unlock_facing_direction
# 203 "data/scripts/follower.pory"
	step_end
# 204 "data/scripts/follower.pory"

# 205 "data/scripts/follower.pory"
FollowerJumpOnPlayerEast:
# 206 "data/scripts/follower.pory"
	jump_right
# 207 "data/scripts/follower.pory"
	delay_4
# 208 "data/scripts/follower.pory"
	lock_facing_direction
# 209 "data/scripts/follower.pory"
	walk_fast_left
# 210 "data/scripts/follower.pory"
	unlock_facing_direction
# 211 "data/scripts/follower.pory"
	step_end
# 212 "data/scripts/follower.pory"

# 213 "data/scripts/follower.pory"
FollowerJumpOnPlayerWest:
# 214 "data/scripts/follower.pory"
	jump_left
# 215 "data/scripts/follower.pory"
	delay_4
# 216 "data/scripts/follower.pory"
	lock_facing_direction
# 217 "data/scripts/follower.pory"
	walk_fast_right
# 218 "data/scripts/follower.pory"
	unlock_facing_direction
# 219 "data/scripts/follower.pory"
	step_end
# 220 "data/scripts/follower.pory"

# 221 "data/scripts/follower.pory"
FollowerCuddlingNorth:
# 222 "data/scripts/follower.pory"
	face_left
# 223 "data/scripts/follower.pory"
	lock_facing_direction
# 224 "data/scripts/follower.pory"
	walk_up
# 225 "data/scripts/follower.pory"
	walk_in_place_left
# 226 "data/scripts/follower.pory"
	walk_in_place_left
# 227 "data/scripts/follower.pory"
	unlock_facing_direction
# 228 "data/scripts/follower.pory"
	walk_down
# 229 "data/scripts/follower.pory"
	face_player
# 230 "data/scripts/follower.pory"
	step_end
# 231 "data/scripts/follower.pory"

# 232 "data/scripts/follower.pory"
FollowerCuddlingSouth:
# 233 "data/scripts/follower.pory"
	face_right
# 234 "data/scripts/follower.pory"
	lock_facing_direction
# 235 "data/scripts/follower.pory"
	walk_down
# 236 "data/scripts/follower.pory"
	walk_in_place_right
# 237 "data/scripts/follower.pory"
	walk_in_place_right
# 238 "data/scripts/follower.pory"
	unlock_facing_direction
# 239 "data/scripts/follower.pory"
	walk_up
# 240 "data/scripts/follower.pory"
	face_player
# 241 "data/scripts/follower.pory"
	step_end
# 242 "data/scripts/follower.pory"

# 243 "data/scripts/follower.pory"
FollowerCuddlingEast:
# 244 "data/scripts/follower.pory"
	face_down
# 245 "data/scripts/follower.pory"
	lock_facing_direction
# 246 "data/scripts/follower.pory"
	walk_right
# 247 "data/scripts/follower.pory"
	walk_in_place_down
# 248 "data/scripts/follower.pory"
	walk_in_place_down
# 249 "data/scripts/follower.pory"
	unlock_facing_direction
# 250 "data/scripts/follower.pory"
	walk_left
# 251 "data/scripts/follower.pory"
	face_player
# 252 "data/scripts/follower.pory"
	step_end
# 253 "data/scripts/follower.pory"

# 254 "data/scripts/follower.pory"
FollowerCuddlingWest:
# 255 "data/scripts/follower.pory"
	face_down
# 256 "data/scripts/follower.pory"
	lock_facing_direction
# 257 "data/scripts/follower.pory"
	walk_left
# 258 "data/scripts/follower.pory"
	walk_in_place_down
# 259 "data/scripts/follower.pory"
	walk_in_place_down
# 260 "data/scripts/follower.pory"
	unlock_facing_direction
# 261 "data/scripts/follower.pory"
	walk_right
# 262 "data/scripts/follower.pory"
	face_player
# 263 "data/scripts/follower.pory"
	step_end
# 264 "data/scripts/follower.pory"

# 265 "data/scripts/follower.pory"
FollowerGetCloserNorth:
# 266 "data/scripts/follower.pory"
	walk_up
# 267 "data/scripts/follower.pory"
	delay_16
# 268 "data/scripts/follower.pory"
	lock_facing_direction
# 269 "data/scripts/follower.pory"
	walk_down
# 270 "data/scripts/follower.pory"
	unlock_facing_direction
# 271 "data/scripts/follower.pory"
	step_end
# 272 "data/scripts/follower.pory"

# 273 "data/scripts/follower.pory"
FollowerGetCloserSouth:
# 274 "data/scripts/follower.pory"
	walk_down
# 275 "data/scripts/follower.pory"
	delay_16
# 276 "data/scripts/follower.pory"
	lock_facing_direction
# 277 "data/scripts/follower.pory"
	walk_up
# 278 "data/scripts/follower.pory"
	unlock_facing_direction
# 279 "data/scripts/follower.pory"
	step_end
# 280 "data/scripts/follower.pory"

# 281 "data/scripts/follower.pory"
FollowerGetCloserEast:
# 282 "data/scripts/follower.pory"
	walk_right
# 283 "data/scripts/follower.pory"
	delay_16
# 284 "data/scripts/follower.pory"
	lock_facing_direction
# 285 "data/scripts/follower.pory"
	walk_left
# 286 "data/scripts/follower.pory"
	unlock_facing_direction
# 287 "data/scripts/follower.pory"
	step_end
# 288 "data/scripts/follower.pory"

# 289 "data/scripts/follower.pory"
FollowerGetCloserWest:
# 290 "data/scripts/follower.pory"
	walk_left
# 291 "data/scripts/follower.pory"
	delay_16
# 292 "data/scripts/follower.pory"
	lock_facing_direction
# 293 "data/scripts/follower.pory"
	walk_right
# 294 "data/scripts/follower.pory"
	unlock_facing_direction
# 295 "data/scripts/follower.pory"
	step_end
# 296 "data/scripts/follower.pory"

# 297 "data/scripts/follower.pory"
FollowerPokeNorth:
# 298 "data/scripts/follower.pory"
	walk_faster_up
# 299 "data/scripts/follower.pory"
	delay_8
# 300 "data/scripts/follower.pory"
	lock_facing_direction
# 301 "data/scripts/follower.pory"
	walk_faster_down
# 302 "data/scripts/follower.pory"
	delay_4
# 303 "data/scripts/follower.pory"
	walk_faster_up
# 304 "data/scripts/follower.pory"
	delay_4
# 305 "data/scripts/follower.pory"
	walk_faster_down
# 306 "data/scripts/follower.pory"
	unlock_facing_direction
# 307 "data/scripts/follower.pory"
	step_end
# 308 "data/scripts/follower.pory"

# 309 "data/scripts/follower.pory"
FollowerPokeSouth:
# 310 "data/scripts/follower.pory"
	walk_faster_down
# 311 "data/scripts/follower.pory"
	delay_8
# 312 "data/scripts/follower.pory"
	lock_facing_direction
# 313 "data/scripts/follower.pory"
	walk_faster_up
# 314 "data/scripts/follower.pory"
	delay_4
# 315 "data/scripts/follower.pory"
	walk_faster_down
# 316 "data/scripts/follower.pory"
	delay_4
# 317 "data/scripts/follower.pory"
	walk_faster_up
# 318 "data/scripts/follower.pory"
	unlock_facing_direction
# 319 "data/scripts/follower.pory"
	step_end
# 320 "data/scripts/follower.pory"

# 321 "data/scripts/follower.pory"
FollowerPokeEast:
# 322 "data/scripts/follower.pory"
	walk_faster_right
# 323 "data/scripts/follower.pory"
	delay_8
# 324 "data/scripts/follower.pory"
	lock_facing_direction
# 325 "data/scripts/follower.pory"
	walk_faster_left
# 326 "data/scripts/follower.pory"
	delay_4
# 327 "data/scripts/follower.pory"
	walk_faster_right
# 328 "data/scripts/follower.pory"
	delay_4
# 329 "data/scripts/follower.pory"
	walk_faster_left
# 330 "data/scripts/follower.pory"
	unlock_facing_direction
# 331 "data/scripts/follower.pory"
	step_end
# 332 "data/scripts/follower.pory"

# 333 "data/scripts/follower.pory"
FollowerPokeWest:
# 334 "data/scripts/follower.pory"
	walk_faster_left
# 335 "data/scripts/follower.pory"
	delay_8
# 336 "data/scripts/follower.pory"
	lock_facing_direction
# 337 "data/scripts/follower.pory"
	walk_faster_right
# 338 "data/scripts/follower.pory"
	delay_4
# 339 "data/scripts/follower.pory"
	walk_faster_left
# 340 "data/scripts/follower.pory"
	delay_4
# 341 "data/scripts/follower.pory"
	walk_faster_right
# 342 "data/scripts/follower.pory"
	unlock_facing_direction
# 343 "data/scripts/follower.pory"
	step_end
# 344 "data/scripts/follower.pory"

# 345 "data/scripts/follower.pory"
FollowerLookAround:
# 346 "data/scripts/follower.pory"
	face_away_player
# 347 "data/scripts/follower.pory"
	delay_16
# 348 "data/scripts/follower.pory"
	delay_16
# 349 "data/scripts/follower.pory"
	face_left
# 350 "data/scripts/follower.pory"
	delay_16
# 351 "data/scripts/follower.pory"
	delay_16
# 352 "data/scripts/follower.pory"
	face_up
# 353 "data/scripts/follower.pory"
	delay_16
# 354 "data/scripts/follower.pory"
	delay_16
# 355 "data/scripts/follower.pory"
	face_down
# 356 "data/scripts/follower.pory"
	delay_16
# 357 "data/scripts/follower.pory"
	delay_16
# 358 "data/scripts/follower.pory"
	step_end
# 359 "data/scripts/follower.pory"

# 360 "data/scripts/follower.pory"
FollowerLookAway:
# 361 "data/scripts/follower.pory"
	face_away_player
# 362 "data/scripts/follower.pory"
	delay_16
# 363 "data/scripts/follower.pory"
	delay_16
# 364 "data/scripts/follower.pory"
	step_end
# 365 "data/scripts/follower.pory"

# 366 "data/scripts/follower.pory"
FollowerLookAwayBark:
# 367 "data/scripts/follower.pory"
	face_away_player
# 368 "data/scripts/follower.pory"
	lock_facing_direction
# 369 "data/scripts/follower.pory"
	jump_in_place_down
# 370 "data/scripts/follower.pory"
	jump_in_place_down
# 371 "data/scripts/follower.pory"
	unlock_facing_direction
# 372 "data/scripts/follower.pory"
	step_end
# 373 "data/scripts/follower.pory"

# 374 "data/scripts/follower.pory"
FollowerLookAwayPokeG:
# 375 "data/scripts/follower.pory"
	face_away_player
# 376 "data/scripts/follower.pory"
	lock_facing_direction
# 377 "data/scripts/follower.pory"
	walk_in_place_down
# 378 "data/scripts/follower.pory"
	walk_in_place_down
# 379 "data/scripts/follower.pory"
	walk_in_place_down
# 380 "data/scripts/follower.pory"
	unlock_facing_direction
# 381 "data/scripts/follower.pory"
	step_end
# 382 "data/scripts/follower.pory"

# 383 "data/scripts/follower.pory"
FollowerPokeGround:
# 384 "data/scripts/follower.pory"
	lock_facing_direction
# 385 "data/scripts/follower.pory"
	walk_in_place_down
# 386 "data/scripts/follower.pory"
	walk_in_place_down
# 387 "data/scripts/follower.pory"
	walk_in_place_down
# 388 "data/scripts/follower.pory"
	unlock_facing_direction
# 389 "data/scripts/follower.pory"
	step_end
# 390 "data/scripts/follower.pory"

# 391 "data/scripts/follower.pory"
FollowerStartled:
# 392 "data/scripts/follower.pory"
	face_away_player
# 393 "data/scripts/follower.pory"
	lock_facing_direction
# 394 "data/scripts/follower.pory"
	jump_in_place_down
# 395 "data/scripts/follower.pory"
	unlock_facing_direction
# 396 "data/scripts/follower.pory"
	face_player
# 397 "data/scripts/follower.pory"
	step_end
# 398 "data/scripts/follower.pory"

# 399 "data/scripts/follower.pory"
FollowerHopFast:
# 400 "data/scripts/follower.pory"
	jump_in_place_up
# 401 "data/scripts/follower.pory"
	jump_in_place_down
# 402 "data/scripts/follower.pory"
	jump_in_place_left
# 403 "data/scripts/follower.pory"
	jump_in_place_right
# 404 "data/scripts/follower.pory"
	face_player
# 405 "data/scripts/follower.pory"
	step_end
# 406 "data/scripts/follower.pory"

# 407 "data/scripts/follower.pory"
FollowerDizzy:
# 408 "data/scripts/follower.pory"
	walk_in_place_left
# 409 "data/scripts/follower.pory"
	walk_in_place_fast_right
# 410 "data/scripts/follower.pory"
	walk_in_place_slow_up
# 411 "data/scripts/follower.pory"
	walk_in_place_fast_down
# 412 "data/scripts/follower.pory"
	delay_4
# 413 "data/scripts/follower.pory"
	face_away_player
# 414 "data/scripts/follower.pory"
	step_end
# 415 "data/scripts/follower.pory"

# 416 "data/scripts/follower.pory"
FollowerLookAroundScared:
# 417 "data/scripts/follower.pory"
	face_up
# 418 "data/scripts/follower.pory"
	delay_16
# 419 "data/scripts/follower.pory"
	face_down
# 420 "data/scripts/follower.pory"
	delay_16
# 421 "data/scripts/follower.pory"
	face_left
# 422 "data/scripts/follower.pory"
	delay_16
# 423 "data/scripts/follower.pory"
	face_right
# 424 "data/scripts/follower.pory"
	delay_16
# 425 "data/scripts/follower.pory"
	face_up
# 426 "data/scripts/follower.pory"
	delay_16
# 427 "data/scripts/follower.pory"
	face_down
# 428 "data/scripts/follower.pory"
	delay_16
# 429 "data/scripts/follower.pory"
	face_left
# 430 "data/scripts/follower.pory"
	delay_16
# 431 "data/scripts/follower.pory"
	face_right
# 432 "data/scripts/follower.pory"
	delay_16
# 433 "data/scripts/follower.pory"
	face_player
# 434 "data/scripts/follower.pory"
	step_end
# 435 "data/scripts/follower.pory"

# 436 "data/scripts/follower.pory"
FollowerDance:
# 437 "data/scripts/follower.pory"
	lock_facing_direction
# 438 "data/scripts/follower.pory"
	jump_in_place_up
# 439 "data/scripts/follower.pory"
	unlock_facing_direction
# 440 "data/scripts/follower.pory"
	walk_in_place_fast_up
# 441 "data/scripts/follower.pory"
	walk_in_place_fast_left
# 442 "data/scripts/follower.pory"
	walk_in_place_fast_down
# 443 "data/scripts/follower.pory"
	walk_in_place_fast_right
# 444 "data/scripts/follower.pory"
	walk_in_place_fast_up
# 445 "data/scripts/follower.pory"
	walk_in_place_fast_left
# 446 "data/scripts/follower.pory"
	walk_in_place_fast_down
# 447 "data/scripts/follower.pory"
	walk_in_place_fast_right
# 448 "data/scripts/follower.pory"
	jump_in_place_up
# 449 "data/scripts/follower.pory"
	jump_in_place_down
# 450 "data/scripts/follower.pory"
	jump_in_place_up
# 451 "data/scripts/follower.pory"
	face_player
# 452 "data/scripts/follower.pory"
	step_end
# 453 "data/scripts/follower.pory"

# 454 "data/scripts/follower.pory"
@ Movement scripts
# 455 "data/scripts/follower.pory"

# 456 "data/scripts/follower.pory"
EventScript_FollowerIsShivering::
# 457 "data/scripts/follower.pory"
	faceplayer
# 458 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_NORTH
# 459 "data/scripts/follower.pory"
	call_if_eq ShiverVertical
# 460 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_SOUTH
# 461 "data/scripts/follower.pory"
	call_if_eq ShiverVertical
# 462 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_WEST
# 463 "data/scripts/follower.pory"
	call_if_eq ShiverHorizontal
# 464 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_EAST
# 465 "data/scripts/follower.pory"
	call_if_eq ShiverHorizontal
# 466 "data/scripts/follower.pory"
	goto EventScript_FollowerGeneric
# 467 "data/scripts/follower.pory"

# 468 "data/scripts/follower.pory"
ShiverVertical:
# 469 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerShiverVerticalMovement
# 470 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 471 "data/scripts/follower.pory"
	return
# 472 "data/scripts/follower.pory"

# 473 "data/scripts/follower.pory"
ShiverHorizontal:
# 474 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerShiverHorizontalMovement
# 475 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 476 "data/scripts/follower.pory"
	return
# 477 "data/scripts/follower.pory"

# 478 "data/scripts/follower.pory"
EventScript_FollowerNostalgia::
# 479 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerNostalgiaMovement
# 480 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 481 "data/scripts/follower.pory"
	goto EventScript_FollowerGeneric
# 482 "data/scripts/follower.pory"

# 483 "data/scripts/follower.pory"
EventScript_FollowerHopping::
# 484 "data/scripts/follower.pory"
	faceplayer
# 485 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerSkippingMovement
# 486 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 487 "data/scripts/follower.pory"
	goto EventScript_FollowerGeneric
# 488 "data/scripts/follower.pory"

# 489 "data/scripts/follower.pory"
JumpOnN:
# 490 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerJumpOnPlayerNorth
# 491 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 492 "data/scripts/follower.pory"
	return
# 493 "data/scripts/follower.pory"

# 494 "data/scripts/follower.pory"
JumpOnS:
# 495 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerJumpOnPlayerSouth
# 496 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 497 "data/scripts/follower.pory"
	return
# 498 "data/scripts/follower.pory"

# 499 "data/scripts/follower.pory"
JumpOnE:
# 500 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerJumpOnPlayerEast
# 501 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 502 "data/scripts/follower.pory"
	return
# 503 "data/scripts/follower.pory"

# 504 "data/scripts/follower.pory"
JumpOnW:
# 505 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerJumpOnPlayerWest
# 506 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 507 "data/scripts/follower.pory"
	return
# 508 "data/scripts/follower.pory"

# 509 "data/scripts/follower.pory"
EventScript_FollowerJumpOnPlayer::
# 510 "data/scripts/follower.pory"
	faceplayer
# 511 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_NORTH
# 512 "data/scripts/follower.pory"
	call_if_eq JumpOnS
# 513 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_SOUTH
# 514 "data/scripts/follower.pory"
	call_if_eq JumpOnN
# 515 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_WEST
# 516 "data/scripts/follower.pory"
	call_if_eq JumpOnE
# 517 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_EAST
# 518 "data/scripts/follower.pory"
	call_if_eq JumpOnW
# 519 "data/scripts/follower.pory"
	goto EventScript_FollowerGeneric
# 520 "data/scripts/follower.pory"

# 521 "data/scripts/follower.pory"
CuddleN:
# 522 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerCuddlingNorth
# 523 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 524 "data/scripts/follower.pory"
	return
# 525 "data/scripts/follower.pory"

# 526 "data/scripts/follower.pory"
CuddleS:
# 527 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerCuddlingSouth
# 528 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 529 "data/scripts/follower.pory"
	return
# 530 "data/scripts/follower.pory"

# 531 "data/scripts/follower.pory"
CuddleE:
# 532 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerCuddlingEast
# 533 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 534 "data/scripts/follower.pory"
	return
# 535 "data/scripts/follower.pory"

# 536 "data/scripts/follower.pory"
CuddleW:
# 537 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerCuddlingWest
# 538 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 539 "data/scripts/follower.pory"
	return
# 540 "data/scripts/follower.pory"

# 541 "data/scripts/follower.pory"
EventScript_FollowerCuddling:: @ similar to Std_MsgboxDefault
# 542 "data/scripts/follower.pory"
	faceplayer
# 543 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_NORTH
# 544 "data/scripts/follower.pory"
	call_if_eq CuddleS
# 545 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_SOUTH
# 546 "data/scripts/follower.pory"
	call_if_eq CuddleN
# 547 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_WEST
# 548 "data/scripts/follower.pory"
	call_if_eq CuddleE
# 549 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_EAST
# 550 "data/scripts/follower.pory"
	call_if_eq CuddleW
# 551 "data/scripts/follower.pory"
	goto EventScript_FollowerGeneric
# 552 "data/scripts/follower.pory"

# 553 "data/scripts/follower.pory"
ShCuddleN:
# 554 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerShiverVerticalMovement
# 555 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 556 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerCuddlingNorth
# 557 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 558 "data/scripts/follower.pory"
	return
# 559 "data/scripts/follower.pory"

# 560 "data/scripts/follower.pory"
ShCuddleS:
# 561 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerShiverVerticalMovement
# 562 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 563 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerCuddlingSouth
# 564 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 565 "data/scripts/follower.pory"
	return
# 566 "data/scripts/follower.pory"

# 567 "data/scripts/follower.pory"
ShCuddleE:
# 568 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerShiverHorizontalMovement
# 569 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 570 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerCuddlingEast
# 571 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 572 "data/scripts/follower.pory"
	return
# 573 "data/scripts/follower.pory"

# 574 "data/scripts/follower.pory"
ShCuddleW:
# 575 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerShiverHorizontalMovement
# 576 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 577 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerCuddlingWest
# 578 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 579 "data/scripts/follower.pory"
	return
# 580 "data/scripts/follower.pory"

# 581 "data/scripts/follower.pory"
EventScript_FollowerShiverCuddling::
# 582 "data/scripts/follower.pory"
	faceplayer
# 583 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_NORTH
# 584 "data/scripts/follower.pory"
	call_if_eq ShCuddleS
# 585 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_SOUTH
# 586 "data/scripts/follower.pory"
	call_if_eq ShCuddleN
# 587 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_WEST
# 588 "data/scripts/follower.pory"
	call_if_eq ShCuddleE
# 589 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_EAST
# 590 "data/scripts/follower.pory"
	call_if_eq ShCuddleW
# 591 "data/scripts/follower.pory"
	goto EventScript_FollowerGeneric
# 592 "data/scripts/follower.pory"

# 593 "data/scripts/follower.pory"
CreepCloserN:
# 594 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerGetCloserNorth
# 595 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 596 "data/scripts/follower.pory"
	return
# 597 "data/scripts/follower.pory"

# 598 "data/scripts/follower.pory"
CreepCloserS:
# 599 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerGetCloserSouth
# 600 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 601 "data/scripts/follower.pory"
	return
# 602 "data/scripts/follower.pory"

# 603 "data/scripts/follower.pory"
CreepCloserE:
# 604 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerGetCloserEast
# 605 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 606 "data/scripts/follower.pory"
	return
# 607 "data/scripts/follower.pory"

# 608 "data/scripts/follower.pory"
CreepCloserW:
# 609 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerGetCloserWest
# 610 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 611 "data/scripts/follower.pory"
	return
# 612 "data/scripts/follower.pory"

# 613 "data/scripts/follower.pory"
EventScript_FollowerGetCloser::
# 614 "data/scripts/follower.pory"
	faceplayer
# 615 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_NORTH
# 616 "data/scripts/follower.pory"
	call_if_eq CreepCloserS
# 617 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_SOUTH
# 618 "data/scripts/follower.pory"
	call_if_eq CreepCloserN
# 619 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_WEST
# 620 "data/scripts/follower.pory"
	call_if_eq CreepCloserE
# 621 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_EAST
# 622 "data/scripts/follower.pory"
	call_if_eq CreepCloserW
# 623 "data/scripts/follower.pory"
	goto EventScript_FollowerGeneric
# 624 "data/scripts/follower.pory"

# 625 "data/scripts/follower.pory"
PokePlayerN:
# 626 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerGetCloserNorth
# 627 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 628 "data/scripts/follower.pory"
	return
# 629 "data/scripts/follower.pory"

# 630 "data/scripts/follower.pory"
PokePlayerS:
# 631 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerGetCloserSouth
# 632 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 633 "data/scripts/follower.pory"
	return
# 634 "data/scripts/follower.pory"

# 635 "data/scripts/follower.pory"
PokePlayerE:
# 636 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerGetCloserEast
# 637 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 638 "data/scripts/follower.pory"
	return
# 639 "data/scripts/follower.pory"

# 640 "data/scripts/follower.pory"
PokePlayerW:
# 641 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerGetCloserWest
# 642 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 643 "data/scripts/follower.pory"
	return
# 644 "data/scripts/follower.pory"

# 645 "data/scripts/follower.pory"
EventScript_FollowerPokingPlayer::
# 646 "data/scripts/follower.pory"
	faceplayer
# 647 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_NORTH
# 648 "data/scripts/follower.pory"
	call_if_eq PokePlayerS
# 649 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_SOUTH
# 650 "data/scripts/follower.pory"
	call_if_eq PokePlayerN
# 651 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_WEST
# 652 "data/scripts/follower.pory"
	call_if_eq PokePlayerE
# 653 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_EAST
# 654 "data/scripts/follower.pory"
	call_if_eq PokePlayerW
# 655 "data/scripts/follower.pory"
	goto EventScript_FollowerGeneric
# 656 "data/scripts/follower.pory"

# 657 "data/scripts/follower.pory"
EventScript_FollowerLookAround::
# 658 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerLookAround
# 659 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 660 "data/scripts/follower.pory"
	goto EventScript_FollowerGeneric
# 661 "data/scripts/follower.pory"

# 662 "data/scripts/follower.pory"
EventScript_FollowerLookAway::
# 663 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerLookAway
# 664 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 665 "data/scripts/follower.pory"
	goto EventScript_FollowerGenericSkipFace
# 666 "data/scripts/follower.pory"

# 667 "data/scripts/follower.pory"
EventScript_FollowerLookAwayBark::
# 668 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerLookAwayBark
# 669 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 670 "data/scripts/follower.pory"
	goto EventScript_FollowerGenericSkipFace
# 671 "data/scripts/follower.pory"

# 672 "data/scripts/follower.pory"
EventScript_FollowerLookAwayPoke::
# 673 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerLookAwayPokeG
# 674 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 675 "data/scripts/follower.pory"
	goto EventScript_FollowerGenericSkipFace
# 676 "data/scripts/follower.pory"

# 677 "data/scripts/follower.pory"
EventScript_FollowerPokeGround::
# 678 "data/scripts/follower.pory"
	faceplayer
# 679 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerPokeGround
# 680 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 681 "data/scripts/follower.pory"
	goto EventScript_FollowerGeneric
# 682 "data/scripts/follower.pory"

# 683 "data/scripts/follower.pory"
EventScript_FollowerStartled::
# 684 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerStartled
# 685 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 686 "data/scripts/follower.pory"
	goto EventScript_FollowerGenericSkipFace
# 687 "data/scripts/follower.pory"

# 688 "data/scripts/follower.pory"
EventScript_FollowerFastHopping::
# 689 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerHopFast
# 690 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 691 "data/scripts/follower.pory"
	goto EventScript_FollowerGenericSkipFace
# 692 "data/scripts/follower.pory"

# 693 "data/scripts/follower.pory"
EventScript_FollowerDizzy::
# 694 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerDizzy
# 695 "data/scripts/follower.pory"
	waitmovement 0
# 696 "data/scripts/follower.pory"
	goto EventScript_FollowerGenericSkipFace
# 697 "data/scripts/follower.pory"

# 698 "data/scripts/follower.pory"
EventScript_FollowerLookAroundScared::
# 699 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerLookAroundScared
# 700 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 701 "data/scripts/follower.pory"
	goto EventScript_FollowerGeneric
# 702 "data/scripts/follower.pory"

# 703 "data/scripts/follower.pory"
EventScript_FollowerDance::
# 704 "data/scripts/follower.pory"
	faceplayer
# 705 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerDance
# 706 "data/scripts/follower.pory"
	waitmovement 0
# 707 "data/scripts/follower.pory"
	goto EventScript_FollowerGenericSkipFace
# 708 "data/scripts/follower.pory"

# 709 "data/scripts/follower.pory"
EventScript_FollowerFaceUp::
# 710 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER Common_Movement_FaceUp
# 711 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 712 "data/scripts/follower.pory"
	goto EventScript_FollowerGenericSkipFace
# 713 "data/scripts/follower.pory"

# 714 "data/scripts/follower.pory"
EventScript_FollowerFaceResult:: @ Face towards direction in VAR_RESULT
# 715 "data/scripts/follower.pory"
	switch VAR_RESULT
# 716 "data/scripts/follower.pory"
	case DIR_SOUTH, EventScript_FollowerFaceDown
# 717 "data/scripts/follower.pory"
	case DIR_NORTH, EventScript_FollowerFaceUp
# 718 "data/scripts/follower.pory"
	case DIR_WEST, EventScript_FollowerFaceLeft
# 719 "data/scripts/follower.pory"
	case DIR_EAST, EventScript_FollowerFaceRight
# 720 "data/scripts/follower.pory"
	goto EventScript_FollowerGeneric
# 721 "data/scripts/follower.pory"

# 722 "data/scripts/follower.pory"
EventScript_FollowerFaceDown:
# 723 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER Common_Movement_FaceDown
# 724 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 725 "data/scripts/follower.pory"
	goto EventScript_FollowerGenericSkipFace
# 726 "data/scripts/follower.pory"

# 727 "data/scripts/follower.pory"
EventScript_FollowerFaceLeft:
# 728 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER Common_Movement_FaceLeft
# 729 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 730 "data/scripts/follower.pory"
	goto EventScript_FollowerGenericSkipFace
# 731 "data/scripts/follower.pory"

# 732 "data/scripts/follower.pory"
EventScript_FollowerFaceRight:
# 733 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER Common_Movement_FaceRight
# 734 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 735 "data/scripts/follower.pory"
	goto EventScript_FollowerGenericSkipFace

EventScript_Follower_Text_0:
# 12 "data/scripts/follower.pory"
	.string "Spinda seems happy to have your\n"
	.string "attention!$"

EventScript_Follower_Text_1:
# 22 "data/scripts/follower.pory"
	.string "Spinda looks dizzy!$"

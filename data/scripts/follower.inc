EventScript_Follower::
# 2 "data/scripts/follower.pory"
	lock
# 3 "data/scripts/follower.pory"
	bufferlivemonnickname 0
# 4 "data/scripts/follower.pory"
	msgbox EventScript_Follower_Text_0
# 8 "data/scripts/follower.pory"
	dynmultichoice 16, 8, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, EventScript_Follower_Text_1, EventScript_Follower_Text_2
# 19 "data/scripts/follower.pory"
	closemessage
# 21 "data/scripts/follower.pory"
	compare VAR_RESULT, 0
	goto_if_eq EventScript_Follower_2
# 23 "data/scripts/follower.pory"
	compare VAR_RESULT, 1
	goto_if_eq EventScript_Follower_3
EventScript_Follower_1:
# 27 "data/scripts/follower.pory"
	release
	return

EventScript_Follower_2:
# 22 "data/scripts/follower.pory"
	call Spinda_SpinClockwise
	goto EventScript_Follower_1

EventScript_Follower_3:
# 24 "data/scripts/follower.pory"
	call Spinda_SpinCounterclockwise
	goto EventScript_Follower_1


# 30 "data/scripts/follower.pory"

# 31 "data/scripts/follower.pory"
gText_FollowerLovesYou::
# 32 "data/scripts/follower.pory"
	.string "{STR_VAR_1} is regarding you with\nadoration!$"
# 33 "data/scripts/follower.pory"

# 34 "data/scripts/follower.pory"
gText_FollowerLostInThought::
# 35 "data/scripts/follower.pory"
	.string "{STR_VAR_1} seems lost in thought.$"
# 36 "data/scripts/follower.pory"

# 37 "data/scripts/follower.pory"
gText_FollowerDefault::
# 38 "data/scripts/follower.pory"
	.string "ERROR 404: Script not found.$"
# 39 "data/scripts/follower.pory"

# 40 "data/scripts/follower.pory"
gText_WantsToFly::
# 41 "data/scripts/follower.pory"
	.string "{STR_VAR_1} looks up at the\nsky restlessly.\pWould you like to use FLY?$"
# 42 "data/scripts/follower.pory"
@ TODO EVA ICI follower override?
# 43 "data/scripts/follower.pory"
@EventScript_Follower::
# 44 "data/scripts/follower.pory"
@	lock
# 45 "data/scripts/follower.pory"
@	bufferlivemonnickname 0
# 46 "data/scripts/follower.pory"
@	playfirstmoncry
# 47 "data/scripts/follower.pory"
@	getfolloweraction
# 48 "data/scripts/follower.pory"
EventScript_FollowerEnd::
# 49 "data/scripts/follower.pory"
	waitfieldeffect FLDEFF_EMOTE
# 50 "data/scripts/follower.pory"
	release
# 51 "data/scripts/follower.pory"
	end
# 52 "data/scripts/follower.pory"

# 53 "data/scripts/follower.pory"
EventScript_FollowerLovesYou::
# 54 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, ContestHall_Movement_Heart
# 55 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 56 "data/scripts/follower.pory"
	waitmoncry
# 57 "data/scripts/follower.pory"
	msgbox gText_FollowerLovesYou, MSGBOX_DEFAULT
# 58 "data/scripts/follower.pory"
	return
# 59 "data/scripts/follower.pory"

# 60 "data/scripts/follower.pory"
@ Message address must be loaded into bank 0
# 61 "data/scripts/follower.pory"
EventScript_FollowerGeneric:: @ similar to Std_MsgboxDefault
# 62 "data/scripts/follower.pory"
	faceplayer
# 63 "data/scripts/follower.pory"
EventScript_FollowerGenericSkipFace:
# 64 "data/scripts/follower.pory"
	waitfieldeffect FLDEFF_EMOTE
# 65 "data/scripts/follower.pory"
	message 0x0
# 66 "data/scripts/follower.pory"
	waitmessage
# 67 "data/scripts/follower.pory"
	waitbuttonpress
# 68 "data/scripts/follower.pory"
	return
# 69 "data/scripts/follower.pory"

# 70 "data/scripts/follower.pory"
EventScript_FollowerJump::
# 71 "data/scripts/follower.pory"
	faceplayer
# 72 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerSplashMovement
# 73 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 74 "data/scripts/follower.pory"
	waitfieldeffect FLDEFF_EMOTE
# 75 "data/scripts/follower.pory"
	message 0x0
# 76 "data/scripts/follower.pory"
	waitmessage
# 77 "data/scripts/follower.pory"
	waitbuttonpress
# 78 "data/scripts/follower.pory"
	return
# 79 "data/scripts/follower.pory"

# 80 "data/scripts/follower.pory"
EnterPokeballMovement::
# 81 "data/scripts/follower.pory"
	enter_pokeball
# 82 "data/scripts/follower.pory"
	step_end
# 83 "data/scripts/follower.pory"

# 84 "data/scripts/follower.pory"
@ Movement scripts below, movements are defined in movement.inc
# 85 "data/scripts/follower.pory"

# 86 "data/scripts/follower.pory"
FollowerSplashMovement::
# 87 "data/scripts/follower.pory"
	jump_in_place_down
# 88 "data/scripts/follower.pory"
	delay_4
# 89 "data/scripts/follower.pory"
	jump_in_place_down
# 90 "data/scripts/follower.pory"
	face_player
# 91 "data/scripts/follower.pory"
	step_end
# 92 "data/scripts/follower.pory"

# 93 "data/scripts/follower.pory"
FollowerShiverVerticalMovement:
# 94 "data/scripts/follower.pory"
	lock_facing_direction
# 95 "data/scripts/follower.pory"
	slide_left
# 96 "data/scripts/follower.pory"
	slide_right
# 97 "data/scripts/follower.pory"
	slide_right
# 98 "data/scripts/follower.pory"
	slide_left
# 99 "data/scripts/follower.pory"
	unlock_facing_direction
# 100 "data/scripts/follower.pory"
	step_end
# 101 "data/scripts/follower.pory"

# 102 "data/scripts/follower.pory"
FollowerShiverHorizontalMovement:
# 103 "data/scripts/follower.pory"
	lock_facing_direction
# 104 "data/scripts/follower.pory"
	slide_up
# 105 "data/scripts/follower.pory"
	slide_down
# 106 "data/scripts/follower.pory"
	slide_down
# 107 "data/scripts/follower.pory"
	slide_up
# 108 "data/scripts/follower.pory"
	unlock_facing_direction
# 109 "data/scripts/follower.pory"
	step_end
# 110 "data/scripts/follower.pory"

# 111 "data/scripts/follower.pory"
FollowerNostalgiaMovement:
# 112 "data/scripts/follower.pory"
	face_away_player
# 113 "data/scripts/follower.pory"
	lock_facing_direction
# 114 "data/scripts/follower.pory"
	jump_in_place_down
# 115 "data/scripts/follower.pory"
	jump_in_place_down
# 116 "data/scripts/follower.pory"
	jump_in_place_down
# 117 "data/scripts/follower.pory"
	unlock_facing_direction
# 118 "data/scripts/follower.pory"
	face_player
# 119 "data/scripts/follower.pory"
	lock_facing_direction
# 120 "data/scripts/follower.pory"
	jump_in_place_down
# 121 "data/scripts/follower.pory"
	unlock_facing_direction
# 122 "data/scripts/follower.pory"
	step_end
# 123 "data/scripts/follower.pory"

# 124 "data/scripts/follower.pory"
FollowerSkippingMovement:
# 125 "data/scripts/follower.pory"
	lock_facing_direction
# 126 "data/scripts/follower.pory"
	jump_in_place_down
# 127 "data/scripts/follower.pory"
	delay_4
# 128 "data/scripts/follower.pory"
	jump_in_place_down
# 129 "data/scripts/follower.pory"
	unlock_facing_direction
# 130 "data/scripts/follower.pory"
	step_end
# 131 "data/scripts/follower.pory"

# 132 "data/scripts/follower.pory"
FollowerJumpOnPlayerNorth:
# 133 "data/scripts/follower.pory"
	jump_up
# 134 "data/scripts/follower.pory"
	delay_4
# 135 "data/scripts/follower.pory"
	lock_facing_direction
# 136 "data/scripts/follower.pory"
	walk_fast_down
# 137 "data/scripts/follower.pory"
	unlock_facing_direction
# 138 "data/scripts/follower.pory"
	step_end
# 139 "data/scripts/follower.pory"

# 140 "data/scripts/follower.pory"
FollowerJumpOnPlayerSouth:
# 141 "data/scripts/follower.pory"
	jump_down
# 142 "data/scripts/follower.pory"
	delay_4
# 143 "data/scripts/follower.pory"
	lock_facing_direction
# 144 "data/scripts/follower.pory"
	walk_fast_up
# 145 "data/scripts/follower.pory"
	unlock_facing_direction
# 146 "data/scripts/follower.pory"
	step_end
# 147 "data/scripts/follower.pory"

# 148 "data/scripts/follower.pory"
FollowerJumpOnPlayerEast:
# 149 "data/scripts/follower.pory"
	jump_right
# 150 "data/scripts/follower.pory"
	delay_4
# 151 "data/scripts/follower.pory"
	lock_facing_direction
# 152 "data/scripts/follower.pory"
	walk_fast_left
# 153 "data/scripts/follower.pory"
	unlock_facing_direction
# 154 "data/scripts/follower.pory"
	step_end
# 155 "data/scripts/follower.pory"

# 156 "data/scripts/follower.pory"
FollowerJumpOnPlayerWest:
# 157 "data/scripts/follower.pory"
	jump_left
# 158 "data/scripts/follower.pory"
	delay_4
# 159 "data/scripts/follower.pory"
	lock_facing_direction
# 160 "data/scripts/follower.pory"
	walk_fast_right
# 161 "data/scripts/follower.pory"
	unlock_facing_direction
# 162 "data/scripts/follower.pory"
	step_end
# 163 "data/scripts/follower.pory"

# 164 "data/scripts/follower.pory"
FollowerCuddlingNorth:
# 165 "data/scripts/follower.pory"
	face_left
# 166 "data/scripts/follower.pory"
	lock_facing_direction
# 167 "data/scripts/follower.pory"
	walk_up
# 168 "data/scripts/follower.pory"
	walk_in_place_left
# 169 "data/scripts/follower.pory"
	walk_in_place_left
# 170 "data/scripts/follower.pory"
	unlock_facing_direction
# 171 "data/scripts/follower.pory"
	walk_down
# 172 "data/scripts/follower.pory"
	face_player
# 173 "data/scripts/follower.pory"
	step_end
# 174 "data/scripts/follower.pory"

# 175 "data/scripts/follower.pory"
FollowerCuddlingSouth:
# 176 "data/scripts/follower.pory"
	face_right
# 177 "data/scripts/follower.pory"
	lock_facing_direction
# 178 "data/scripts/follower.pory"
	walk_down
# 179 "data/scripts/follower.pory"
	walk_in_place_right
# 180 "data/scripts/follower.pory"
	walk_in_place_right
# 181 "data/scripts/follower.pory"
	unlock_facing_direction
# 182 "data/scripts/follower.pory"
	walk_up
# 183 "data/scripts/follower.pory"
	face_player
# 184 "data/scripts/follower.pory"
	step_end
# 185 "data/scripts/follower.pory"

# 186 "data/scripts/follower.pory"
FollowerCuddlingEast:
# 187 "data/scripts/follower.pory"
	face_down
# 188 "data/scripts/follower.pory"
	lock_facing_direction
# 189 "data/scripts/follower.pory"
	walk_right
# 190 "data/scripts/follower.pory"
	walk_in_place_down
# 191 "data/scripts/follower.pory"
	walk_in_place_down
# 192 "data/scripts/follower.pory"
	unlock_facing_direction
# 193 "data/scripts/follower.pory"
	walk_left
# 194 "data/scripts/follower.pory"
	face_player
# 195 "data/scripts/follower.pory"
	step_end
# 196 "data/scripts/follower.pory"

# 197 "data/scripts/follower.pory"
FollowerCuddlingWest:
# 198 "data/scripts/follower.pory"
	face_down
# 199 "data/scripts/follower.pory"
	lock_facing_direction
# 200 "data/scripts/follower.pory"
	walk_left
# 201 "data/scripts/follower.pory"
	walk_in_place_down
# 202 "data/scripts/follower.pory"
	walk_in_place_down
# 203 "data/scripts/follower.pory"
	unlock_facing_direction
# 204 "data/scripts/follower.pory"
	walk_right
# 205 "data/scripts/follower.pory"
	face_player
# 206 "data/scripts/follower.pory"
	step_end
# 207 "data/scripts/follower.pory"

# 208 "data/scripts/follower.pory"
FollowerGetCloserNorth:
# 209 "data/scripts/follower.pory"
	walk_up
# 210 "data/scripts/follower.pory"
	delay_16
# 211 "data/scripts/follower.pory"
	lock_facing_direction
# 212 "data/scripts/follower.pory"
	walk_down
# 213 "data/scripts/follower.pory"
	unlock_facing_direction
# 214 "data/scripts/follower.pory"
	step_end
# 215 "data/scripts/follower.pory"

# 216 "data/scripts/follower.pory"
FollowerGetCloserSouth:
# 217 "data/scripts/follower.pory"
	walk_down
# 218 "data/scripts/follower.pory"
	delay_16
# 219 "data/scripts/follower.pory"
	lock_facing_direction
# 220 "data/scripts/follower.pory"
	walk_up
# 221 "data/scripts/follower.pory"
	unlock_facing_direction
# 222 "data/scripts/follower.pory"
	step_end
# 223 "data/scripts/follower.pory"

# 224 "data/scripts/follower.pory"
FollowerGetCloserEast:
# 225 "data/scripts/follower.pory"
	walk_right
# 226 "data/scripts/follower.pory"
	delay_16
# 227 "data/scripts/follower.pory"
	lock_facing_direction
# 228 "data/scripts/follower.pory"
	walk_left
# 229 "data/scripts/follower.pory"
	unlock_facing_direction
# 230 "data/scripts/follower.pory"
	step_end
# 231 "data/scripts/follower.pory"

# 232 "data/scripts/follower.pory"
FollowerGetCloserWest:
# 233 "data/scripts/follower.pory"
	walk_left
# 234 "data/scripts/follower.pory"
	delay_16
# 235 "data/scripts/follower.pory"
	lock_facing_direction
# 236 "data/scripts/follower.pory"
	walk_right
# 237 "data/scripts/follower.pory"
	unlock_facing_direction
# 238 "data/scripts/follower.pory"
	step_end
# 239 "data/scripts/follower.pory"

# 240 "data/scripts/follower.pory"
FollowerPokeNorth:
# 241 "data/scripts/follower.pory"
	walk_faster_up
# 242 "data/scripts/follower.pory"
	delay_8
# 243 "data/scripts/follower.pory"
	lock_facing_direction
# 244 "data/scripts/follower.pory"
	walk_faster_down
# 245 "data/scripts/follower.pory"
	delay_4
# 246 "data/scripts/follower.pory"
	walk_faster_up
# 247 "data/scripts/follower.pory"
	delay_4
# 248 "data/scripts/follower.pory"
	walk_faster_down
# 249 "data/scripts/follower.pory"
	unlock_facing_direction
# 250 "data/scripts/follower.pory"
	step_end
# 251 "data/scripts/follower.pory"

# 252 "data/scripts/follower.pory"
FollowerPokeSouth:
# 253 "data/scripts/follower.pory"
	walk_faster_down
# 254 "data/scripts/follower.pory"
	delay_8
# 255 "data/scripts/follower.pory"
	lock_facing_direction
# 256 "data/scripts/follower.pory"
	walk_faster_up
# 257 "data/scripts/follower.pory"
	delay_4
# 258 "data/scripts/follower.pory"
	walk_faster_down
# 259 "data/scripts/follower.pory"
	delay_4
# 260 "data/scripts/follower.pory"
	walk_faster_up
# 261 "data/scripts/follower.pory"
	unlock_facing_direction
# 262 "data/scripts/follower.pory"
	step_end
# 263 "data/scripts/follower.pory"

# 264 "data/scripts/follower.pory"
FollowerPokeEast:
# 265 "data/scripts/follower.pory"
	walk_faster_right
# 266 "data/scripts/follower.pory"
	delay_8
# 267 "data/scripts/follower.pory"
	lock_facing_direction
# 268 "data/scripts/follower.pory"
	walk_faster_left
# 269 "data/scripts/follower.pory"
	delay_4
# 270 "data/scripts/follower.pory"
	walk_faster_right
# 271 "data/scripts/follower.pory"
	delay_4
# 272 "data/scripts/follower.pory"
	walk_faster_left
# 273 "data/scripts/follower.pory"
	unlock_facing_direction
# 274 "data/scripts/follower.pory"
	step_end
# 275 "data/scripts/follower.pory"

# 276 "data/scripts/follower.pory"
FollowerPokeWest:
# 277 "data/scripts/follower.pory"
	walk_faster_left
# 278 "data/scripts/follower.pory"
	delay_8
# 279 "data/scripts/follower.pory"
	lock_facing_direction
# 280 "data/scripts/follower.pory"
	walk_faster_right
# 281 "data/scripts/follower.pory"
	delay_4
# 282 "data/scripts/follower.pory"
	walk_faster_left
# 283 "data/scripts/follower.pory"
	delay_4
# 284 "data/scripts/follower.pory"
	walk_faster_right
# 285 "data/scripts/follower.pory"
	unlock_facing_direction
# 286 "data/scripts/follower.pory"
	step_end
# 287 "data/scripts/follower.pory"

# 288 "data/scripts/follower.pory"
FollowerLookAround:
# 289 "data/scripts/follower.pory"
	face_away_player
# 290 "data/scripts/follower.pory"
	delay_16
# 291 "data/scripts/follower.pory"
	delay_16
# 292 "data/scripts/follower.pory"
	face_left
# 293 "data/scripts/follower.pory"
	delay_16
# 294 "data/scripts/follower.pory"
	delay_16
# 295 "data/scripts/follower.pory"
	face_up
# 296 "data/scripts/follower.pory"
	delay_16
# 297 "data/scripts/follower.pory"
	delay_16
# 298 "data/scripts/follower.pory"
	face_down
# 299 "data/scripts/follower.pory"
	delay_16
# 300 "data/scripts/follower.pory"
	delay_16
# 301 "data/scripts/follower.pory"
	step_end
# 302 "data/scripts/follower.pory"

# 303 "data/scripts/follower.pory"
FollowerLookAway:
# 304 "data/scripts/follower.pory"
	face_away_player
# 305 "data/scripts/follower.pory"
	delay_16
# 306 "data/scripts/follower.pory"
	delay_16
# 307 "data/scripts/follower.pory"
	step_end
# 308 "data/scripts/follower.pory"

# 309 "data/scripts/follower.pory"
FollowerLookAwayBark:
# 310 "data/scripts/follower.pory"
	face_away_player
# 311 "data/scripts/follower.pory"
	lock_facing_direction
# 312 "data/scripts/follower.pory"
	jump_in_place_down
# 313 "data/scripts/follower.pory"
	jump_in_place_down
# 314 "data/scripts/follower.pory"
	unlock_facing_direction
# 315 "data/scripts/follower.pory"
	step_end
# 316 "data/scripts/follower.pory"

# 317 "data/scripts/follower.pory"
FollowerLookAwayPokeG:
# 318 "data/scripts/follower.pory"
	face_away_player
# 319 "data/scripts/follower.pory"
	lock_facing_direction
# 320 "data/scripts/follower.pory"
	walk_in_place_down
# 321 "data/scripts/follower.pory"
	walk_in_place_down
# 322 "data/scripts/follower.pory"
	walk_in_place_down
# 323 "data/scripts/follower.pory"
	unlock_facing_direction
# 324 "data/scripts/follower.pory"
	step_end
# 325 "data/scripts/follower.pory"

# 326 "data/scripts/follower.pory"
FollowerPokeGround:
# 327 "data/scripts/follower.pory"
	lock_facing_direction
# 328 "data/scripts/follower.pory"
	walk_in_place_down
# 329 "data/scripts/follower.pory"
	walk_in_place_down
# 330 "data/scripts/follower.pory"
	walk_in_place_down
# 331 "data/scripts/follower.pory"
	unlock_facing_direction
# 332 "data/scripts/follower.pory"
	step_end
# 333 "data/scripts/follower.pory"

# 334 "data/scripts/follower.pory"
FollowerStartled:
# 335 "data/scripts/follower.pory"
	face_away_player
# 336 "data/scripts/follower.pory"
	lock_facing_direction
# 337 "data/scripts/follower.pory"
	jump_in_place_down
# 338 "data/scripts/follower.pory"
	unlock_facing_direction
# 339 "data/scripts/follower.pory"
	face_player
# 340 "data/scripts/follower.pory"
	step_end
# 341 "data/scripts/follower.pory"

# 342 "data/scripts/follower.pory"
FollowerHopFast:
# 343 "data/scripts/follower.pory"
	jump_in_place_up
# 344 "data/scripts/follower.pory"
	jump_in_place_down
# 345 "data/scripts/follower.pory"
	jump_in_place_left
# 346 "data/scripts/follower.pory"
	jump_in_place_right
# 347 "data/scripts/follower.pory"
	face_player
# 348 "data/scripts/follower.pory"
	step_end
# 349 "data/scripts/follower.pory"

# 350 "data/scripts/follower.pory"
FollowerDizzy:
# 351 "data/scripts/follower.pory"
	walk_in_place_left
# 352 "data/scripts/follower.pory"
	walk_in_place_fast_right
# 353 "data/scripts/follower.pory"
	walk_in_place_slow_up
# 354 "data/scripts/follower.pory"
	walk_in_place_fast_down
# 355 "data/scripts/follower.pory"
	delay_4
# 356 "data/scripts/follower.pory"
	face_away_player
# 357 "data/scripts/follower.pory"
	step_end
# 358 "data/scripts/follower.pory"

# 359 "data/scripts/follower.pory"
FollowerLookAroundScared:
# 360 "data/scripts/follower.pory"
	face_up
# 361 "data/scripts/follower.pory"
	delay_16
# 362 "data/scripts/follower.pory"
	face_down
# 363 "data/scripts/follower.pory"
	delay_16
# 364 "data/scripts/follower.pory"
	face_left
# 365 "data/scripts/follower.pory"
	delay_16
# 366 "data/scripts/follower.pory"
	face_right
# 367 "data/scripts/follower.pory"
	delay_16
# 368 "data/scripts/follower.pory"
	face_up
# 369 "data/scripts/follower.pory"
	delay_16
# 370 "data/scripts/follower.pory"
	face_down
# 371 "data/scripts/follower.pory"
	delay_16
# 372 "data/scripts/follower.pory"
	face_left
# 373 "data/scripts/follower.pory"
	delay_16
# 374 "data/scripts/follower.pory"
	face_right
# 375 "data/scripts/follower.pory"
	delay_16
# 376 "data/scripts/follower.pory"
	face_player
# 377 "data/scripts/follower.pory"
	step_end
# 378 "data/scripts/follower.pory"

# 379 "data/scripts/follower.pory"
FollowerDance:
# 380 "data/scripts/follower.pory"
	lock_facing_direction
# 381 "data/scripts/follower.pory"
	jump_in_place_up
# 382 "data/scripts/follower.pory"
	unlock_facing_direction
# 383 "data/scripts/follower.pory"
	walk_in_place_fast_up
# 384 "data/scripts/follower.pory"
	walk_in_place_fast_left
# 385 "data/scripts/follower.pory"
	walk_in_place_fast_down
# 386 "data/scripts/follower.pory"
	walk_in_place_fast_right
# 387 "data/scripts/follower.pory"
	walk_in_place_fast_up
# 388 "data/scripts/follower.pory"
	walk_in_place_fast_left
# 389 "data/scripts/follower.pory"
	walk_in_place_fast_down
# 390 "data/scripts/follower.pory"
	walk_in_place_fast_right
# 391 "data/scripts/follower.pory"
	jump_in_place_up
# 392 "data/scripts/follower.pory"
	jump_in_place_down
# 393 "data/scripts/follower.pory"
	jump_in_place_up
# 394 "data/scripts/follower.pory"
	face_player
# 395 "data/scripts/follower.pory"
	step_end
# 396 "data/scripts/follower.pory"

# 397 "data/scripts/follower.pory"
@ Movement scripts
# 398 "data/scripts/follower.pory"

# 399 "data/scripts/follower.pory"
EventScript_FollowerIsShivering::
# 400 "data/scripts/follower.pory"
	faceplayer
# 401 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_NORTH
# 402 "data/scripts/follower.pory"
	call_if_eq ShiverVertical
# 403 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_SOUTH
# 404 "data/scripts/follower.pory"
	call_if_eq ShiverVertical
# 405 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_WEST
# 406 "data/scripts/follower.pory"
	call_if_eq ShiverHorizontal
# 407 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_EAST
# 408 "data/scripts/follower.pory"
	call_if_eq ShiverHorizontal
# 409 "data/scripts/follower.pory"
	goto EventScript_FollowerGeneric
# 410 "data/scripts/follower.pory"

# 411 "data/scripts/follower.pory"
ShiverVertical:
# 412 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerShiverVerticalMovement
# 413 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 414 "data/scripts/follower.pory"
	return
# 415 "data/scripts/follower.pory"

# 416 "data/scripts/follower.pory"
ShiverHorizontal:
# 417 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerShiverHorizontalMovement
# 418 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 419 "data/scripts/follower.pory"
	return
# 420 "data/scripts/follower.pory"

# 421 "data/scripts/follower.pory"
EventScript_FollowerNostalgia::
# 422 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerNostalgiaMovement
# 423 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 424 "data/scripts/follower.pory"
	goto EventScript_FollowerGeneric
# 425 "data/scripts/follower.pory"

# 426 "data/scripts/follower.pory"
EventScript_FollowerHopping::
# 427 "data/scripts/follower.pory"
	faceplayer
# 428 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerSkippingMovement
# 429 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 430 "data/scripts/follower.pory"
	goto EventScript_FollowerGeneric
# 431 "data/scripts/follower.pory"

# 432 "data/scripts/follower.pory"
JumpOnN:
# 433 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerJumpOnPlayerNorth
# 434 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 435 "data/scripts/follower.pory"
	return
# 436 "data/scripts/follower.pory"

# 437 "data/scripts/follower.pory"
JumpOnS:
# 438 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerJumpOnPlayerSouth
# 439 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 440 "data/scripts/follower.pory"
	return
# 441 "data/scripts/follower.pory"

# 442 "data/scripts/follower.pory"
JumpOnE:
# 443 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerJumpOnPlayerEast
# 444 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 445 "data/scripts/follower.pory"
	return
# 446 "data/scripts/follower.pory"

# 447 "data/scripts/follower.pory"
JumpOnW:
# 448 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerJumpOnPlayerWest
# 449 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 450 "data/scripts/follower.pory"
	return
# 451 "data/scripts/follower.pory"

# 452 "data/scripts/follower.pory"
EventScript_FollowerJumpOnPlayer::
# 453 "data/scripts/follower.pory"
	faceplayer
# 454 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_NORTH
# 455 "data/scripts/follower.pory"
	call_if_eq JumpOnS
# 456 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_SOUTH
# 457 "data/scripts/follower.pory"
	call_if_eq JumpOnN
# 458 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_WEST
# 459 "data/scripts/follower.pory"
	call_if_eq JumpOnE
# 460 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_EAST
# 461 "data/scripts/follower.pory"
	call_if_eq JumpOnW
# 462 "data/scripts/follower.pory"
	goto EventScript_FollowerGeneric
# 463 "data/scripts/follower.pory"

# 464 "data/scripts/follower.pory"
CuddleN:
# 465 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerCuddlingNorth
# 466 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 467 "data/scripts/follower.pory"
	return
# 468 "data/scripts/follower.pory"

# 469 "data/scripts/follower.pory"
CuddleS:
# 470 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerCuddlingSouth
# 471 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 472 "data/scripts/follower.pory"
	return
# 473 "data/scripts/follower.pory"

# 474 "data/scripts/follower.pory"
CuddleE:
# 475 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerCuddlingEast
# 476 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 477 "data/scripts/follower.pory"
	return
# 478 "data/scripts/follower.pory"

# 479 "data/scripts/follower.pory"
CuddleW:
# 480 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerCuddlingWest
# 481 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 482 "data/scripts/follower.pory"
	return
# 483 "data/scripts/follower.pory"

# 484 "data/scripts/follower.pory"
EventScript_FollowerCuddling:: @ similar to Std_MsgboxDefault
# 485 "data/scripts/follower.pory"
	faceplayer
# 486 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_NORTH
# 487 "data/scripts/follower.pory"
	call_if_eq CuddleS
# 488 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_SOUTH
# 489 "data/scripts/follower.pory"
	call_if_eq CuddleN
# 490 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_WEST
# 491 "data/scripts/follower.pory"
	call_if_eq CuddleE
# 492 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_EAST
# 493 "data/scripts/follower.pory"
	call_if_eq CuddleW
# 494 "data/scripts/follower.pory"
	goto EventScript_FollowerGeneric
# 495 "data/scripts/follower.pory"

# 496 "data/scripts/follower.pory"
ShCuddleN:
# 497 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerShiverVerticalMovement
# 498 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 499 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerCuddlingNorth
# 500 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 501 "data/scripts/follower.pory"
	return
# 502 "data/scripts/follower.pory"

# 503 "data/scripts/follower.pory"
ShCuddleS:
# 504 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerShiverVerticalMovement
# 505 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 506 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerCuddlingSouth
# 507 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 508 "data/scripts/follower.pory"
	return
# 509 "data/scripts/follower.pory"

# 510 "data/scripts/follower.pory"
ShCuddleE:
# 511 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerShiverHorizontalMovement
# 512 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 513 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerCuddlingEast
# 514 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 515 "data/scripts/follower.pory"
	return
# 516 "data/scripts/follower.pory"

# 517 "data/scripts/follower.pory"
ShCuddleW:
# 518 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerShiverHorizontalMovement
# 519 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 520 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerCuddlingWest
# 521 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 522 "data/scripts/follower.pory"
	return
# 523 "data/scripts/follower.pory"

# 524 "data/scripts/follower.pory"
EventScript_FollowerShiverCuddling::
# 525 "data/scripts/follower.pory"
	faceplayer
# 526 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_NORTH
# 527 "data/scripts/follower.pory"
	call_if_eq ShCuddleS
# 528 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_SOUTH
# 529 "data/scripts/follower.pory"
	call_if_eq ShCuddleN
# 530 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_WEST
# 531 "data/scripts/follower.pory"
	call_if_eq ShCuddleE
# 532 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_EAST
# 533 "data/scripts/follower.pory"
	call_if_eq ShCuddleW
# 534 "data/scripts/follower.pory"
	goto EventScript_FollowerGeneric
# 535 "data/scripts/follower.pory"

# 536 "data/scripts/follower.pory"
CreepCloserN:
# 537 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerGetCloserNorth
# 538 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 539 "data/scripts/follower.pory"
	return
# 540 "data/scripts/follower.pory"

# 541 "data/scripts/follower.pory"
CreepCloserS:
# 542 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerGetCloserSouth
# 543 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 544 "data/scripts/follower.pory"
	return
# 545 "data/scripts/follower.pory"

# 546 "data/scripts/follower.pory"
CreepCloserE:
# 547 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerGetCloserEast
# 548 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 549 "data/scripts/follower.pory"
	return
# 550 "data/scripts/follower.pory"

# 551 "data/scripts/follower.pory"
CreepCloserW:
# 552 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerGetCloserWest
# 553 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 554 "data/scripts/follower.pory"
	return
# 555 "data/scripts/follower.pory"

# 556 "data/scripts/follower.pory"
EventScript_FollowerGetCloser::
# 557 "data/scripts/follower.pory"
	faceplayer
# 558 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_NORTH
# 559 "data/scripts/follower.pory"
	call_if_eq CreepCloserS
# 560 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_SOUTH
# 561 "data/scripts/follower.pory"
	call_if_eq CreepCloserN
# 562 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_WEST
# 563 "data/scripts/follower.pory"
	call_if_eq CreepCloserE
# 564 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_EAST
# 565 "data/scripts/follower.pory"
	call_if_eq CreepCloserW
# 566 "data/scripts/follower.pory"
	goto EventScript_FollowerGeneric
# 567 "data/scripts/follower.pory"

# 568 "data/scripts/follower.pory"
PokePlayerN:
# 569 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerGetCloserNorth
# 570 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 571 "data/scripts/follower.pory"
	return
# 572 "data/scripts/follower.pory"

# 573 "data/scripts/follower.pory"
PokePlayerS:
# 574 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerGetCloserSouth
# 575 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 576 "data/scripts/follower.pory"
	return
# 577 "data/scripts/follower.pory"

# 578 "data/scripts/follower.pory"
PokePlayerE:
# 579 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerGetCloserEast
# 580 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 581 "data/scripts/follower.pory"
	return
# 582 "data/scripts/follower.pory"

# 583 "data/scripts/follower.pory"
PokePlayerW:
# 584 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerGetCloserWest
# 585 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 586 "data/scripts/follower.pory"
	return
# 587 "data/scripts/follower.pory"

# 588 "data/scripts/follower.pory"
EventScript_FollowerPokingPlayer::
# 589 "data/scripts/follower.pory"
	faceplayer
# 590 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_NORTH
# 591 "data/scripts/follower.pory"
	call_if_eq PokePlayerS
# 592 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_SOUTH
# 593 "data/scripts/follower.pory"
	call_if_eq PokePlayerN
# 594 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_WEST
# 595 "data/scripts/follower.pory"
	call_if_eq PokePlayerE
# 596 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_EAST
# 597 "data/scripts/follower.pory"
	call_if_eq PokePlayerW
# 598 "data/scripts/follower.pory"
	goto EventScript_FollowerGeneric
# 599 "data/scripts/follower.pory"

# 600 "data/scripts/follower.pory"
EventScript_FollowerLookAround::
# 601 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerLookAround
# 602 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 603 "data/scripts/follower.pory"
	goto EventScript_FollowerGeneric
# 604 "data/scripts/follower.pory"

# 605 "data/scripts/follower.pory"
EventScript_FollowerLookAway::
# 606 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerLookAway
# 607 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 608 "data/scripts/follower.pory"
	goto EventScript_FollowerGenericSkipFace
# 609 "data/scripts/follower.pory"

# 610 "data/scripts/follower.pory"
EventScript_FollowerLookAwayBark::
# 611 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerLookAwayBark
# 612 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 613 "data/scripts/follower.pory"
	goto EventScript_FollowerGenericSkipFace
# 614 "data/scripts/follower.pory"

# 615 "data/scripts/follower.pory"
EventScript_FollowerLookAwayPoke::
# 616 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerLookAwayPokeG
# 617 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 618 "data/scripts/follower.pory"
	goto EventScript_FollowerGenericSkipFace
# 619 "data/scripts/follower.pory"

# 620 "data/scripts/follower.pory"
EventScript_FollowerPokeGround::
# 621 "data/scripts/follower.pory"
	faceplayer
# 622 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerPokeGround
# 623 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 624 "data/scripts/follower.pory"
	goto EventScript_FollowerGeneric
# 625 "data/scripts/follower.pory"

# 626 "data/scripts/follower.pory"
EventScript_FollowerStartled::
# 627 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerStartled
# 628 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 629 "data/scripts/follower.pory"
	goto EventScript_FollowerGenericSkipFace
# 630 "data/scripts/follower.pory"

# 631 "data/scripts/follower.pory"
EventScript_FollowerFastHopping::
# 632 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerHopFast
# 633 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 634 "data/scripts/follower.pory"
	goto EventScript_FollowerGenericSkipFace
# 635 "data/scripts/follower.pory"

# 636 "data/scripts/follower.pory"
EventScript_FollowerDizzy::
# 637 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerDizzy
# 638 "data/scripts/follower.pory"
	waitmovement 0
# 639 "data/scripts/follower.pory"
	goto EventScript_FollowerGenericSkipFace
# 640 "data/scripts/follower.pory"

# 641 "data/scripts/follower.pory"
EventScript_FollowerLookAroundScared::
# 642 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerLookAroundScared
# 643 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 644 "data/scripts/follower.pory"
	goto EventScript_FollowerGeneric
# 645 "data/scripts/follower.pory"

# 646 "data/scripts/follower.pory"
EventScript_FollowerDance::
# 647 "data/scripts/follower.pory"
	faceplayer
# 648 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerDance
# 649 "data/scripts/follower.pory"
	waitmovement 0
# 650 "data/scripts/follower.pory"
	goto EventScript_FollowerGenericSkipFace
# 651 "data/scripts/follower.pory"

# 652 "data/scripts/follower.pory"
EventScript_FollowerFaceUp::
# 653 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER Common_Movement_FaceUp
# 654 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 655 "data/scripts/follower.pory"
	goto EventScript_FollowerGenericSkipFace
# 656 "data/scripts/follower.pory"

# 657 "data/scripts/follower.pory"
EventScript_FollowerFaceResult:: @ Face towards direction in VAR_RESULT
# 658 "data/scripts/follower.pory"
	switch VAR_RESULT
# 659 "data/scripts/follower.pory"
	case DIR_SOUTH, EventScript_FollowerFaceDown
# 660 "data/scripts/follower.pory"
	case DIR_NORTH, EventScript_FollowerFaceUp
# 661 "data/scripts/follower.pory"
	case DIR_WEST, EventScript_FollowerFaceLeft
# 662 "data/scripts/follower.pory"
	case DIR_EAST, EventScript_FollowerFaceRight
# 663 "data/scripts/follower.pory"
	goto EventScript_FollowerGeneric
# 664 "data/scripts/follower.pory"

# 665 "data/scripts/follower.pory"
EventScript_FollowerFaceDown:
# 666 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER Common_Movement_FaceDown
# 667 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 668 "data/scripts/follower.pory"
	goto EventScript_FollowerGenericSkipFace
# 669 "data/scripts/follower.pory"

# 670 "data/scripts/follower.pory"
EventScript_FollowerFaceLeft:
# 671 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER Common_Movement_FaceLeft
# 672 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 673 "data/scripts/follower.pory"
	goto EventScript_FollowerGenericSkipFace
# 674 "data/scripts/follower.pory"

# 675 "data/scripts/follower.pory"
EventScript_FollowerFaceRight:
# 676 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER Common_Movement_FaceRight
# 677 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 678 "data/scripts/follower.pory"
	goto EventScript_FollowerGenericSkipFace

EventScript_Follower_Text_0:
# 5 "data/scripts/follower.pory"
	.string "Take Spinda for a spin?$"

EventScript_Follower_Text_1:
# 15 "data/scripts/follower.pory"
	.string "Spin clockwise$"

EventScript_Follower_Text_2:
# 16 "data/scripts/follower.pory"
	.string "Spin counterclockwise$"

EventScript_Follower::
# 2 "data/scripts/follower.pory"
	lock
# 3 "data/scripts/follower.pory"
	playfirstmoncry
# 4 "data/scripts/follower.pory"
	faceplayer
# 5 "data/scripts/follower.pory"
	msgbox EventScript_Follower_Text_0
# 9 "data/scripts/follower.pory"
	dynmultichoice 16, 8, FALSE, 10, 0, DYN_MULTICHOICE_CB_NONE, EventScript_Follower_Text_1, EventScript_Follower_Text_2
# 20 "data/scripts/follower.pory"
	closemessage
# 22 "data/scripts/follower.pory"
	compare VAR_RESULT, 0
	goto_if_eq EventScript_Follower_2
# 24 "data/scripts/follower.pory"
	compare VAR_RESULT, 1
	goto_if_eq EventScript_Follower_3
EventScript_Follower_1:
# 28 "data/scripts/follower.pory"
	release
	return

EventScript_Follower_2:
# 23 "data/scripts/follower.pory"
	call Spinda_SpinClockwise
	goto EventScript_Follower_1

EventScript_Follower_3:
# 25 "data/scripts/follower.pory"
	call Spinda_SpinCounterclockwise
	goto EventScript_Follower_1


# 31 "data/scripts/follower.pory"

# 32 "data/scripts/follower.pory"
gText_FollowerLovesYou::
# 33 "data/scripts/follower.pory"
	.string "{STR_VAR_1} is regarding you with\nadoration!$"
# 34 "data/scripts/follower.pory"

# 35 "data/scripts/follower.pory"
gText_FollowerLostInThought::
# 36 "data/scripts/follower.pory"
	.string "{STR_VAR_1} seems lost in thought.$"
# 37 "data/scripts/follower.pory"

# 38 "data/scripts/follower.pory"
gText_FollowerDefault::
# 39 "data/scripts/follower.pory"
	.string "ERROR 404: Script not found.$"
# 40 "data/scripts/follower.pory"

# 41 "data/scripts/follower.pory"
gText_WantsToFly::
# 42 "data/scripts/follower.pory"
	.string "{STR_VAR_1} looks up at the\nsky restlessly.\pWould you like to use FLY?$"
# 43 "data/scripts/follower.pory"
@ TODO EVA ICI follower override?
# 44 "data/scripts/follower.pory"
@EventScript_Follower::
# 45 "data/scripts/follower.pory"
@	lock
# 46 "data/scripts/follower.pory"
@	bufferlivemonnickname 0
# 47 "data/scripts/follower.pory"
@	playfirstmoncry
# 48 "data/scripts/follower.pory"
@	getfolloweraction
# 49 "data/scripts/follower.pory"
EventScript_FollowerEnd::
# 50 "data/scripts/follower.pory"
	waitfieldeffect FLDEFF_EMOTE
# 51 "data/scripts/follower.pory"
	release
# 52 "data/scripts/follower.pory"
	end
# 53 "data/scripts/follower.pory"

# 54 "data/scripts/follower.pory"
EventScript_FollowerLovesYou::
# 55 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, ContestHall_Movement_Heart
# 56 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 57 "data/scripts/follower.pory"
	waitmoncry
# 58 "data/scripts/follower.pory"
	msgbox gText_FollowerLovesYou, MSGBOX_DEFAULT
# 59 "data/scripts/follower.pory"
	return
# 60 "data/scripts/follower.pory"

# 61 "data/scripts/follower.pory"
@ Message address must be loaded into bank 0
# 62 "data/scripts/follower.pory"
EventScript_FollowerGeneric:: @ similar to Std_MsgboxDefault
# 63 "data/scripts/follower.pory"
	faceplayer
# 64 "data/scripts/follower.pory"
EventScript_FollowerGenericSkipFace:
# 65 "data/scripts/follower.pory"
	waitfieldeffect FLDEFF_EMOTE
# 66 "data/scripts/follower.pory"
	message 0x0
# 67 "data/scripts/follower.pory"
	waitmessage
# 68 "data/scripts/follower.pory"
	waitbuttonpress
# 69 "data/scripts/follower.pory"
	return
# 70 "data/scripts/follower.pory"

# 71 "data/scripts/follower.pory"
EventScript_FollowerJump::
# 72 "data/scripts/follower.pory"
	faceplayer
# 73 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerSplashMovement
# 74 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 75 "data/scripts/follower.pory"
	waitfieldeffect FLDEFF_EMOTE
# 76 "data/scripts/follower.pory"
	message 0x0
# 77 "data/scripts/follower.pory"
	waitmessage
# 78 "data/scripts/follower.pory"
	waitbuttonpress
# 79 "data/scripts/follower.pory"
	return
# 80 "data/scripts/follower.pory"

# 81 "data/scripts/follower.pory"
EnterPokeballMovement::
# 82 "data/scripts/follower.pory"
	enter_pokeball
# 83 "data/scripts/follower.pory"
	step_end
# 84 "data/scripts/follower.pory"

# 85 "data/scripts/follower.pory"
@ Movement scripts below, movements are defined in movement.inc
# 86 "data/scripts/follower.pory"

# 87 "data/scripts/follower.pory"
FollowerSplashMovement::
# 88 "data/scripts/follower.pory"
	jump_in_place_down
# 89 "data/scripts/follower.pory"
	delay_4
# 90 "data/scripts/follower.pory"
	jump_in_place_down
# 91 "data/scripts/follower.pory"
	face_player
# 92 "data/scripts/follower.pory"
	step_end
# 93 "data/scripts/follower.pory"

# 94 "data/scripts/follower.pory"
FollowerShiverVerticalMovement:
# 95 "data/scripts/follower.pory"
	lock_facing_direction
# 96 "data/scripts/follower.pory"
	slide_left
# 97 "data/scripts/follower.pory"
	slide_right
# 98 "data/scripts/follower.pory"
	slide_right
# 99 "data/scripts/follower.pory"
	slide_left
# 100 "data/scripts/follower.pory"
	unlock_facing_direction
# 101 "data/scripts/follower.pory"
	step_end
# 102 "data/scripts/follower.pory"

# 103 "data/scripts/follower.pory"
FollowerShiverHorizontalMovement:
# 104 "data/scripts/follower.pory"
	lock_facing_direction
# 105 "data/scripts/follower.pory"
	slide_up
# 106 "data/scripts/follower.pory"
	slide_down
# 107 "data/scripts/follower.pory"
	slide_down
# 108 "data/scripts/follower.pory"
	slide_up
# 109 "data/scripts/follower.pory"
	unlock_facing_direction
# 110 "data/scripts/follower.pory"
	step_end
# 111 "data/scripts/follower.pory"

# 112 "data/scripts/follower.pory"
FollowerNostalgiaMovement:
# 113 "data/scripts/follower.pory"
	face_away_player
# 114 "data/scripts/follower.pory"
	lock_facing_direction
# 115 "data/scripts/follower.pory"
	jump_in_place_down
# 116 "data/scripts/follower.pory"
	jump_in_place_down
# 117 "data/scripts/follower.pory"
	jump_in_place_down
# 118 "data/scripts/follower.pory"
	unlock_facing_direction
# 119 "data/scripts/follower.pory"
	face_player
# 120 "data/scripts/follower.pory"
	lock_facing_direction
# 121 "data/scripts/follower.pory"
	jump_in_place_down
# 122 "data/scripts/follower.pory"
	unlock_facing_direction
# 123 "data/scripts/follower.pory"
	step_end
# 124 "data/scripts/follower.pory"

# 125 "data/scripts/follower.pory"
FollowerSkippingMovement:
# 126 "data/scripts/follower.pory"
	lock_facing_direction
# 127 "data/scripts/follower.pory"
	jump_in_place_down
# 128 "data/scripts/follower.pory"
	delay_4
# 129 "data/scripts/follower.pory"
	jump_in_place_down
# 130 "data/scripts/follower.pory"
	unlock_facing_direction
# 131 "data/scripts/follower.pory"
	step_end
# 132 "data/scripts/follower.pory"

# 133 "data/scripts/follower.pory"
FollowerJumpOnPlayerNorth:
# 134 "data/scripts/follower.pory"
	jump_up
# 135 "data/scripts/follower.pory"
	delay_4
# 136 "data/scripts/follower.pory"
	lock_facing_direction
# 137 "data/scripts/follower.pory"
	walk_fast_down
# 138 "data/scripts/follower.pory"
	unlock_facing_direction
# 139 "data/scripts/follower.pory"
	step_end
# 140 "data/scripts/follower.pory"

# 141 "data/scripts/follower.pory"
FollowerJumpOnPlayerSouth:
# 142 "data/scripts/follower.pory"
	jump_down
# 143 "data/scripts/follower.pory"
	delay_4
# 144 "data/scripts/follower.pory"
	lock_facing_direction
# 145 "data/scripts/follower.pory"
	walk_fast_up
# 146 "data/scripts/follower.pory"
	unlock_facing_direction
# 147 "data/scripts/follower.pory"
	step_end
# 148 "data/scripts/follower.pory"

# 149 "data/scripts/follower.pory"
FollowerJumpOnPlayerEast:
# 150 "data/scripts/follower.pory"
	jump_right
# 151 "data/scripts/follower.pory"
	delay_4
# 152 "data/scripts/follower.pory"
	lock_facing_direction
# 153 "data/scripts/follower.pory"
	walk_fast_left
# 154 "data/scripts/follower.pory"
	unlock_facing_direction
# 155 "data/scripts/follower.pory"
	step_end
# 156 "data/scripts/follower.pory"

# 157 "data/scripts/follower.pory"
FollowerJumpOnPlayerWest:
# 158 "data/scripts/follower.pory"
	jump_left
# 159 "data/scripts/follower.pory"
	delay_4
# 160 "data/scripts/follower.pory"
	lock_facing_direction
# 161 "data/scripts/follower.pory"
	walk_fast_right
# 162 "data/scripts/follower.pory"
	unlock_facing_direction
# 163 "data/scripts/follower.pory"
	step_end
# 164 "data/scripts/follower.pory"

# 165 "data/scripts/follower.pory"
FollowerCuddlingNorth:
# 166 "data/scripts/follower.pory"
	face_left
# 167 "data/scripts/follower.pory"
	lock_facing_direction
# 168 "data/scripts/follower.pory"
	walk_up
# 169 "data/scripts/follower.pory"
	walk_in_place_left
# 170 "data/scripts/follower.pory"
	walk_in_place_left
# 171 "data/scripts/follower.pory"
	unlock_facing_direction
# 172 "data/scripts/follower.pory"
	walk_down
# 173 "data/scripts/follower.pory"
	face_player
# 174 "data/scripts/follower.pory"
	step_end
# 175 "data/scripts/follower.pory"

# 176 "data/scripts/follower.pory"
FollowerCuddlingSouth:
# 177 "data/scripts/follower.pory"
	face_right
# 178 "data/scripts/follower.pory"
	lock_facing_direction
# 179 "data/scripts/follower.pory"
	walk_down
# 180 "data/scripts/follower.pory"
	walk_in_place_right
# 181 "data/scripts/follower.pory"
	walk_in_place_right
# 182 "data/scripts/follower.pory"
	unlock_facing_direction
# 183 "data/scripts/follower.pory"
	walk_up
# 184 "data/scripts/follower.pory"
	face_player
# 185 "data/scripts/follower.pory"
	step_end
# 186 "data/scripts/follower.pory"

# 187 "data/scripts/follower.pory"
FollowerCuddlingEast:
# 188 "data/scripts/follower.pory"
	face_down
# 189 "data/scripts/follower.pory"
	lock_facing_direction
# 190 "data/scripts/follower.pory"
	walk_right
# 191 "data/scripts/follower.pory"
	walk_in_place_down
# 192 "data/scripts/follower.pory"
	walk_in_place_down
# 193 "data/scripts/follower.pory"
	unlock_facing_direction
# 194 "data/scripts/follower.pory"
	walk_left
# 195 "data/scripts/follower.pory"
	face_player
# 196 "data/scripts/follower.pory"
	step_end
# 197 "data/scripts/follower.pory"

# 198 "data/scripts/follower.pory"
FollowerCuddlingWest:
# 199 "data/scripts/follower.pory"
	face_down
# 200 "data/scripts/follower.pory"
	lock_facing_direction
# 201 "data/scripts/follower.pory"
	walk_left
# 202 "data/scripts/follower.pory"
	walk_in_place_down
# 203 "data/scripts/follower.pory"
	walk_in_place_down
# 204 "data/scripts/follower.pory"
	unlock_facing_direction
# 205 "data/scripts/follower.pory"
	walk_right
# 206 "data/scripts/follower.pory"
	face_player
# 207 "data/scripts/follower.pory"
	step_end
# 208 "data/scripts/follower.pory"

# 209 "data/scripts/follower.pory"
FollowerGetCloserNorth:
# 210 "data/scripts/follower.pory"
	walk_up
# 211 "data/scripts/follower.pory"
	delay_16
# 212 "data/scripts/follower.pory"
	lock_facing_direction
# 213 "data/scripts/follower.pory"
	walk_down
# 214 "data/scripts/follower.pory"
	unlock_facing_direction
# 215 "data/scripts/follower.pory"
	step_end
# 216 "data/scripts/follower.pory"

# 217 "data/scripts/follower.pory"
FollowerGetCloserSouth:
# 218 "data/scripts/follower.pory"
	walk_down
# 219 "data/scripts/follower.pory"
	delay_16
# 220 "data/scripts/follower.pory"
	lock_facing_direction
# 221 "data/scripts/follower.pory"
	walk_up
# 222 "data/scripts/follower.pory"
	unlock_facing_direction
# 223 "data/scripts/follower.pory"
	step_end
# 224 "data/scripts/follower.pory"

# 225 "data/scripts/follower.pory"
FollowerGetCloserEast:
# 226 "data/scripts/follower.pory"
	walk_right
# 227 "data/scripts/follower.pory"
	delay_16
# 228 "data/scripts/follower.pory"
	lock_facing_direction
# 229 "data/scripts/follower.pory"
	walk_left
# 230 "data/scripts/follower.pory"
	unlock_facing_direction
# 231 "data/scripts/follower.pory"
	step_end
# 232 "data/scripts/follower.pory"

# 233 "data/scripts/follower.pory"
FollowerGetCloserWest:
# 234 "data/scripts/follower.pory"
	walk_left
# 235 "data/scripts/follower.pory"
	delay_16
# 236 "data/scripts/follower.pory"
	lock_facing_direction
# 237 "data/scripts/follower.pory"
	walk_right
# 238 "data/scripts/follower.pory"
	unlock_facing_direction
# 239 "data/scripts/follower.pory"
	step_end
# 240 "data/scripts/follower.pory"

# 241 "data/scripts/follower.pory"
FollowerPokeNorth:
# 242 "data/scripts/follower.pory"
	walk_faster_up
# 243 "data/scripts/follower.pory"
	delay_8
# 244 "data/scripts/follower.pory"
	lock_facing_direction
# 245 "data/scripts/follower.pory"
	walk_faster_down
# 246 "data/scripts/follower.pory"
	delay_4
# 247 "data/scripts/follower.pory"
	walk_faster_up
# 248 "data/scripts/follower.pory"
	delay_4
# 249 "data/scripts/follower.pory"
	walk_faster_down
# 250 "data/scripts/follower.pory"
	unlock_facing_direction
# 251 "data/scripts/follower.pory"
	step_end
# 252 "data/scripts/follower.pory"

# 253 "data/scripts/follower.pory"
FollowerPokeSouth:
# 254 "data/scripts/follower.pory"
	walk_faster_down
# 255 "data/scripts/follower.pory"
	delay_8
# 256 "data/scripts/follower.pory"
	lock_facing_direction
# 257 "data/scripts/follower.pory"
	walk_faster_up
# 258 "data/scripts/follower.pory"
	delay_4
# 259 "data/scripts/follower.pory"
	walk_faster_down
# 260 "data/scripts/follower.pory"
	delay_4
# 261 "data/scripts/follower.pory"
	walk_faster_up
# 262 "data/scripts/follower.pory"
	unlock_facing_direction
# 263 "data/scripts/follower.pory"
	step_end
# 264 "data/scripts/follower.pory"

# 265 "data/scripts/follower.pory"
FollowerPokeEast:
# 266 "data/scripts/follower.pory"
	walk_faster_right
# 267 "data/scripts/follower.pory"
	delay_8
# 268 "data/scripts/follower.pory"
	lock_facing_direction
# 269 "data/scripts/follower.pory"
	walk_faster_left
# 270 "data/scripts/follower.pory"
	delay_4
# 271 "data/scripts/follower.pory"
	walk_faster_right
# 272 "data/scripts/follower.pory"
	delay_4
# 273 "data/scripts/follower.pory"
	walk_faster_left
# 274 "data/scripts/follower.pory"
	unlock_facing_direction
# 275 "data/scripts/follower.pory"
	step_end
# 276 "data/scripts/follower.pory"

# 277 "data/scripts/follower.pory"
FollowerPokeWest:
# 278 "data/scripts/follower.pory"
	walk_faster_left
# 279 "data/scripts/follower.pory"
	delay_8
# 280 "data/scripts/follower.pory"
	lock_facing_direction
# 281 "data/scripts/follower.pory"
	walk_faster_right
# 282 "data/scripts/follower.pory"
	delay_4
# 283 "data/scripts/follower.pory"
	walk_faster_left
# 284 "data/scripts/follower.pory"
	delay_4
# 285 "data/scripts/follower.pory"
	walk_faster_right
# 286 "data/scripts/follower.pory"
	unlock_facing_direction
# 287 "data/scripts/follower.pory"
	step_end
# 288 "data/scripts/follower.pory"

# 289 "data/scripts/follower.pory"
FollowerLookAround:
# 290 "data/scripts/follower.pory"
	face_away_player
# 291 "data/scripts/follower.pory"
	delay_16
# 292 "data/scripts/follower.pory"
	delay_16
# 293 "data/scripts/follower.pory"
	face_left
# 294 "data/scripts/follower.pory"
	delay_16
# 295 "data/scripts/follower.pory"
	delay_16
# 296 "data/scripts/follower.pory"
	face_up
# 297 "data/scripts/follower.pory"
	delay_16
# 298 "data/scripts/follower.pory"
	delay_16
# 299 "data/scripts/follower.pory"
	face_down
# 300 "data/scripts/follower.pory"
	delay_16
# 301 "data/scripts/follower.pory"
	delay_16
# 302 "data/scripts/follower.pory"
	step_end
# 303 "data/scripts/follower.pory"

# 304 "data/scripts/follower.pory"
FollowerLookAway:
# 305 "data/scripts/follower.pory"
	face_away_player
# 306 "data/scripts/follower.pory"
	delay_16
# 307 "data/scripts/follower.pory"
	delay_16
# 308 "data/scripts/follower.pory"
	step_end
# 309 "data/scripts/follower.pory"

# 310 "data/scripts/follower.pory"
FollowerLookAwayBark:
# 311 "data/scripts/follower.pory"
	face_away_player
# 312 "data/scripts/follower.pory"
	lock_facing_direction
# 313 "data/scripts/follower.pory"
	jump_in_place_down
# 314 "data/scripts/follower.pory"
	jump_in_place_down
# 315 "data/scripts/follower.pory"
	unlock_facing_direction
# 316 "data/scripts/follower.pory"
	step_end
# 317 "data/scripts/follower.pory"

# 318 "data/scripts/follower.pory"
FollowerLookAwayPokeG:
# 319 "data/scripts/follower.pory"
	face_away_player
# 320 "data/scripts/follower.pory"
	lock_facing_direction
# 321 "data/scripts/follower.pory"
	walk_in_place_down
# 322 "data/scripts/follower.pory"
	walk_in_place_down
# 323 "data/scripts/follower.pory"
	walk_in_place_down
# 324 "data/scripts/follower.pory"
	unlock_facing_direction
# 325 "data/scripts/follower.pory"
	step_end
# 326 "data/scripts/follower.pory"

# 327 "data/scripts/follower.pory"
FollowerPokeGround:
# 328 "data/scripts/follower.pory"
	lock_facing_direction
# 329 "data/scripts/follower.pory"
	walk_in_place_down
# 330 "data/scripts/follower.pory"
	walk_in_place_down
# 331 "data/scripts/follower.pory"
	walk_in_place_down
# 332 "data/scripts/follower.pory"
	unlock_facing_direction
# 333 "data/scripts/follower.pory"
	step_end
# 334 "data/scripts/follower.pory"

# 335 "data/scripts/follower.pory"
FollowerStartled:
# 336 "data/scripts/follower.pory"
	face_away_player
# 337 "data/scripts/follower.pory"
	lock_facing_direction
# 338 "data/scripts/follower.pory"
	jump_in_place_down
# 339 "data/scripts/follower.pory"
	unlock_facing_direction
# 340 "data/scripts/follower.pory"
	face_player
# 341 "data/scripts/follower.pory"
	step_end
# 342 "data/scripts/follower.pory"

# 343 "data/scripts/follower.pory"
FollowerHopFast:
# 344 "data/scripts/follower.pory"
	jump_in_place_up
# 345 "data/scripts/follower.pory"
	jump_in_place_down
# 346 "data/scripts/follower.pory"
	jump_in_place_left
# 347 "data/scripts/follower.pory"
	jump_in_place_right
# 348 "data/scripts/follower.pory"
	face_player
# 349 "data/scripts/follower.pory"
	step_end
# 350 "data/scripts/follower.pory"

# 351 "data/scripts/follower.pory"
FollowerDizzy:
# 352 "data/scripts/follower.pory"
	walk_in_place_left
# 353 "data/scripts/follower.pory"
	walk_in_place_fast_right
# 354 "data/scripts/follower.pory"
	walk_in_place_slow_up
# 355 "data/scripts/follower.pory"
	walk_in_place_fast_down
# 356 "data/scripts/follower.pory"
	delay_4
# 357 "data/scripts/follower.pory"
	face_away_player
# 358 "data/scripts/follower.pory"
	step_end
# 359 "data/scripts/follower.pory"

# 360 "data/scripts/follower.pory"
FollowerLookAroundScared:
# 361 "data/scripts/follower.pory"
	face_up
# 362 "data/scripts/follower.pory"
	delay_16
# 363 "data/scripts/follower.pory"
	face_down
# 364 "data/scripts/follower.pory"
	delay_16
# 365 "data/scripts/follower.pory"
	face_left
# 366 "data/scripts/follower.pory"
	delay_16
# 367 "data/scripts/follower.pory"
	face_right
# 368 "data/scripts/follower.pory"
	delay_16
# 369 "data/scripts/follower.pory"
	face_up
# 370 "data/scripts/follower.pory"
	delay_16
# 371 "data/scripts/follower.pory"
	face_down
# 372 "data/scripts/follower.pory"
	delay_16
# 373 "data/scripts/follower.pory"
	face_left
# 374 "data/scripts/follower.pory"
	delay_16
# 375 "data/scripts/follower.pory"
	face_right
# 376 "data/scripts/follower.pory"
	delay_16
# 377 "data/scripts/follower.pory"
	face_player
# 378 "data/scripts/follower.pory"
	step_end
# 379 "data/scripts/follower.pory"

# 380 "data/scripts/follower.pory"
FollowerDance:
# 381 "data/scripts/follower.pory"
	lock_facing_direction
# 382 "data/scripts/follower.pory"
	jump_in_place_up
# 383 "data/scripts/follower.pory"
	unlock_facing_direction
# 384 "data/scripts/follower.pory"
	walk_in_place_fast_up
# 385 "data/scripts/follower.pory"
	walk_in_place_fast_left
# 386 "data/scripts/follower.pory"
	walk_in_place_fast_down
# 387 "data/scripts/follower.pory"
	walk_in_place_fast_right
# 388 "data/scripts/follower.pory"
	walk_in_place_fast_up
# 389 "data/scripts/follower.pory"
	walk_in_place_fast_left
# 390 "data/scripts/follower.pory"
	walk_in_place_fast_down
# 391 "data/scripts/follower.pory"
	walk_in_place_fast_right
# 392 "data/scripts/follower.pory"
	jump_in_place_up
# 393 "data/scripts/follower.pory"
	jump_in_place_down
# 394 "data/scripts/follower.pory"
	jump_in_place_up
# 395 "data/scripts/follower.pory"
	face_player
# 396 "data/scripts/follower.pory"
	step_end
# 397 "data/scripts/follower.pory"

# 398 "data/scripts/follower.pory"
@ Movement scripts
# 399 "data/scripts/follower.pory"

# 400 "data/scripts/follower.pory"
EventScript_FollowerIsShivering::
# 401 "data/scripts/follower.pory"
	faceplayer
# 402 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_NORTH
# 403 "data/scripts/follower.pory"
	call_if_eq ShiverVertical
# 404 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_SOUTH
# 405 "data/scripts/follower.pory"
	call_if_eq ShiverVertical
# 406 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_WEST
# 407 "data/scripts/follower.pory"
	call_if_eq ShiverHorizontal
# 408 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_EAST
# 409 "data/scripts/follower.pory"
	call_if_eq ShiverHorizontal
# 410 "data/scripts/follower.pory"
	goto EventScript_FollowerGeneric
# 411 "data/scripts/follower.pory"

# 412 "data/scripts/follower.pory"
ShiverVertical:
# 413 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerShiverVerticalMovement
# 414 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 415 "data/scripts/follower.pory"
	return
# 416 "data/scripts/follower.pory"

# 417 "data/scripts/follower.pory"
ShiverHorizontal:
# 418 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerShiverHorizontalMovement
# 419 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 420 "data/scripts/follower.pory"
	return
# 421 "data/scripts/follower.pory"

# 422 "data/scripts/follower.pory"
EventScript_FollowerNostalgia::
# 423 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerNostalgiaMovement
# 424 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 425 "data/scripts/follower.pory"
	goto EventScript_FollowerGeneric
# 426 "data/scripts/follower.pory"

# 427 "data/scripts/follower.pory"
EventScript_FollowerHopping::
# 428 "data/scripts/follower.pory"
	faceplayer
# 429 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerSkippingMovement
# 430 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 431 "data/scripts/follower.pory"
	goto EventScript_FollowerGeneric
# 432 "data/scripts/follower.pory"

# 433 "data/scripts/follower.pory"
JumpOnN:
# 434 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerJumpOnPlayerNorth
# 435 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 436 "data/scripts/follower.pory"
	return
# 437 "data/scripts/follower.pory"

# 438 "data/scripts/follower.pory"
JumpOnS:
# 439 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerJumpOnPlayerSouth
# 440 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 441 "data/scripts/follower.pory"
	return
# 442 "data/scripts/follower.pory"

# 443 "data/scripts/follower.pory"
JumpOnE:
# 444 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerJumpOnPlayerEast
# 445 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 446 "data/scripts/follower.pory"
	return
# 447 "data/scripts/follower.pory"

# 448 "data/scripts/follower.pory"
JumpOnW:
# 449 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerJumpOnPlayerWest
# 450 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 451 "data/scripts/follower.pory"
	return
# 452 "data/scripts/follower.pory"

# 453 "data/scripts/follower.pory"
EventScript_FollowerJumpOnPlayer::
# 454 "data/scripts/follower.pory"
	faceplayer
# 455 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_NORTH
# 456 "data/scripts/follower.pory"
	call_if_eq JumpOnS
# 457 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_SOUTH
# 458 "data/scripts/follower.pory"
	call_if_eq JumpOnN
# 459 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_WEST
# 460 "data/scripts/follower.pory"
	call_if_eq JumpOnE
# 461 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_EAST
# 462 "data/scripts/follower.pory"
	call_if_eq JumpOnW
# 463 "data/scripts/follower.pory"
	goto EventScript_FollowerGeneric
# 464 "data/scripts/follower.pory"

# 465 "data/scripts/follower.pory"
CuddleN:
# 466 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerCuddlingNorth
# 467 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 468 "data/scripts/follower.pory"
	return
# 469 "data/scripts/follower.pory"

# 470 "data/scripts/follower.pory"
CuddleS:
# 471 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerCuddlingSouth
# 472 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 473 "data/scripts/follower.pory"
	return
# 474 "data/scripts/follower.pory"

# 475 "data/scripts/follower.pory"
CuddleE:
# 476 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerCuddlingEast
# 477 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 478 "data/scripts/follower.pory"
	return
# 479 "data/scripts/follower.pory"

# 480 "data/scripts/follower.pory"
CuddleW:
# 481 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerCuddlingWest
# 482 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 483 "data/scripts/follower.pory"
	return
# 484 "data/scripts/follower.pory"

# 485 "data/scripts/follower.pory"
EventScript_FollowerCuddling:: @ similar to Std_MsgboxDefault
# 486 "data/scripts/follower.pory"
	faceplayer
# 487 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_NORTH
# 488 "data/scripts/follower.pory"
	call_if_eq CuddleS
# 489 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_SOUTH
# 490 "data/scripts/follower.pory"
	call_if_eq CuddleN
# 491 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_WEST
# 492 "data/scripts/follower.pory"
	call_if_eq CuddleE
# 493 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_EAST
# 494 "data/scripts/follower.pory"
	call_if_eq CuddleW
# 495 "data/scripts/follower.pory"
	goto EventScript_FollowerGeneric
# 496 "data/scripts/follower.pory"

# 497 "data/scripts/follower.pory"
ShCuddleN:
# 498 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerShiverVerticalMovement
# 499 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 500 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerCuddlingNorth
# 501 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 502 "data/scripts/follower.pory"
	return
# 503 "data/scripts/follower.pory"

# 504 "data/scripts/follower.pory"
ShCuddleS:
# 505 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerShiverVerticalMovement
# 506 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 507 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerCuddlingSouth
# 508 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 509 "data/scripts/follower.pory"
	return
# 510 "data/scripts/follower.pory"

# 511 "data/scripts/follower.pory"
ShCuddleE:
# 512 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerShiverHorizontalMovement
# 513 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 514 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerCuddlingEast
# 515 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 516 "data/scripts/follower.pory"
	return
# 517 "data/scripts/follower.pory"

# 518 "data/scripts/follower.pory"
ShCuddleW:
# 519 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerShiverHorizontalMovement
# 520 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 521 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerCuddlingWest
# 522 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 523 "data/scripts/follower.pory"
	return
# 524 "data/scripts/follower.pory"

# 525 "data/scripts/follower.pory"
EventScript_FollowerShiverCuddling::
# 526 "data/scripts/follower.pory"
	faceplayer
# 527 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_NORTH
# 528 "data/scripts/follower.pory"
	call_if_eq ShCuddleS
# 529 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_SOUTH
# 530 "data/scripts/follower.pory"
	call_if_eq ShCuddleN
# 531 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_WEST
# 532 "data/scripts/follower.pory"
	call_if_eq ShCuddleE
# 533 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_EAST
# 534 "data/scripts/follower.pory"
	call_if_eq ShCuddleW
# 535 "data/scripts/follower.pory"
	goto EventScript_FollowerGeneric
# 536 "data/scripts/follower.pory"

# 537 "data/scripts/follower.pory"
CreepCloserN:
# 538 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerGetCloserNorth
# 539 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 540 "data/scripts/follower.pory"
	return
# 541 "data/scripts/follower.pory"

# 542 "data/scripts/follower.pory"
CreepCloserS:
# 543 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerGetCloserSouth
# 544 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 545 "data/scripts/follower.pory"
	return
# 546 "data/scripts/follower.pory"

# 547 "data/scripts/follower.pory"
CreepCloserE:
# 548 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerGetCloserEast
# 549 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 550 "data/scripts/follower.pory"
	return
# 551 "data/scripts/follower.pory"

# 552 "data/scripts/follower.pory"
CreepCloserW:
# 553 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerGetCloserWest
# 554 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 555 "data/scripts/follower.pory"
	return
# 556 "data/scripts/follower.pory"

# 557 "data/scripts/follower.pory"
EventScript_FollowerGetCloser::
# 558 "data/scripts/follower.pory"
	faceplayer
# 559 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_NORTH
# 560 "data/scripts/follower.pory"
	call_if_eq CreepCloserS
# 561 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_SOUTH
# 562 "data/scripts/follower.pory"
	call_if_eq CreepCloserN
# 563 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_WEST
# 564 "data/scripts/follower.pory"
	call_if_eq CreepCloserE
# 565 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_EAST
# 566 "data/scripts/follower.pory"
	call_if_eq CreepCloserW
# 567 "data/scripts/follower.pory"
	goto EventScript_FollowerGeneric
# 568 "data/scripts/follower.pory"

# 569 "data/scripts/follower.pory"
PokePlayerN:
# 570 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerGetCloserNorth
# 571 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 572 "data/scripts/follower.pory"
	return
# 573 "data/scripts/follower.pory"

# 574 "data/scripts/follower.pory"
PokePlayerS:
# 575 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerGetCloserSouth
# 576 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 577 "data/scripts/follower.pory"
	return
# 578 "data/scripts/follower.pory"

# 579 "data/scripts/follower.pory"
PokePlayerE:
# 580 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerGetCloserEast
# 581 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 582 "data/scripts/follower.pory"
	return
# 583 "data/scripts/follower.pory"

# 584 "data/scripts/follower.pory"
PokePlayerW:
# 585 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerGetCloserWest
# 586 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 587 "data/scripts/follower.pory"
	return
# 588 "data/scripts/follower.pory"

# 589 "data/scripts/follower.pory"
EventScript_FollowerPokingPlayer::
# 590 "data/scripts/follower.pory"
	faceplayer
# 591 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_NORTH
# 592 "data/scripts/follower.pory"
	call_if_eq PokePlayerS
# 593 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_SOUTH
# 594 "data/scripts/follower.pory"
	call_if_eq PokePlayerN
# 595 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_WEST
# 596 "data/scripts/follower.pory"
	call_if_eq PokePlayerE
# 597 "data/scripts/follower.pory"
	compare VAR_FACING, DIR_EAST
# 598 "data/scripts/follower.pory"
	call_if_eq PokePlayerW
# 599 "data/scripts/follower.pory"
	goto EventScript_FollowerGeneric
# 600 "data/scripts/follower.pory"

# 601 "data/scripts/follower.pory"
EventScript_FollowerLookAround::
# 602 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerLookAround
# 603 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 604 "data/scripts/follower.pory"
	goto EventScript_FollowerGeneric
# 605 "data/scripts/follower.pory"

# 606 "data/scripts/follower.pory"
EventScript_FollowerLookAway::
# 607 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerLookAway
# 608 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 609 "data/scripts/follower.pory"
	goto EventScript_FollowerGenericSkipFace
# 610 "data/scripts/follower.pory"

# 611 "data/scripts/follower.pory"
EventScript_FollowerLookAwayBark::
# 612 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerLookAwayBark
# 613 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 614 "data/scripts/follower.pory"
	goto EventScript_FollowerGenericSkipFace
# 615 "data/scripts/follower.pory"

# 616 "data/scripts/follower.pory"
EventScript_FollowerLookAwayPoke::
# 617 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerLookAwayPokeG
# 618 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 619 "data/scripts/follower.pory"
	goto EventScript_FollowerGenericSkipFace
# 620 "data/scripts/follower.pory"

# 621 "data/scripts/follower.pory"
EventScript_FollowerPokeGround::
# 622 "data/scripts/follower.pory"
	faceplayer
# 623 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerPokeGround
# 624 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 625 "data/scripts/follower.pory"
	goto EventScript_FollowerGeneric
# 626 "data/scripts/follower.pory"

# 627 "data/scripts/follower.pory"
EventScript_FollowerStartled::
# 628 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerStartled
# 629 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 630 "data/scripts/follower.pory"
	goto EventScript_FollowerGenericSkipFace
# 631 "data/scripts/follower.pory"

# 632 "data/scripts/follower.pory"
EventScript_FollowerFastHopping::
# 633 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerHopFast
# 634 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 635 "data/scripts/follower.pory"
	goto EventScript_FollowerGenericSkipFace
# 636 "data/scripts/follower.pory"

# 637 "data/scripts/follower.pory"
EventScript_FollowerDizzy::
# 638 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerDizzy
# 639 "data/scripts/follower.pory"
	waitmovement 0
# 640 "data/scripts/follower.pory"
	goto EventScript_FollowerGenericSkipFace
# 641 "data/scripts/follower.pory"

# 642 "data/scripts/follower.pory"
EventScript_FollowerLookAroundScared::
# 643 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerLookAroundScared
# 644 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 645 "data/scripts/follower.pory"
	goto EventScript_FollowerGeneric
# 646 "data/scripts/follower.pory"

# 647 "data/scripts/follower.pory"
EventScript_FollowerDance::
# 648 "data/scripts/follower.pory"
	faceplayer
# 649 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerDance
# 650 "data/scripts/follower.pory"
	waitmovement 0
# 651 "data/scripts/follower.pory"
	goto EventScript_FollowerGenericSkipFace
# 652 "data/scripts/follower.pory"

# 653 "data/scripts/follower.pory"
EventScript_FollowerFaceUp::
# 654 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER Common_Movement_FaceUp
# 655 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 656 "data/scripts/follower.pory"
	goto EventScript_FollowerGenericSkipFace
# 657 "data/scripts/follower.pory"

# 658 "data/scripts/follower.pory"
EventScript_FollowerFaceResult:: @ Face towards direction in VAR_RESULT
# 659 "data/scripts/follower.pory"
	switch VAR_RESULT
# 660 "data/scripts/follower.pory"
	case DIR_SOUTH, EventScript_FollowerFaceDown
# 661 "data/scripts/follower.pory"
	case DIR_NORTH, EventScript_FollowerFaceUp
# 662 "data/scripts/follower.pory"
	case DIR_WEST, EventScript_FollowerFaceLeft
# 663 "data/scripts/follower.pory"
	case DIR_EAST, EventScript_FollowerFaceRight
# 664 "data/scripts/follower.pory"
	goto EventScript_FollowerGeneric
# 665 "data/scripts/follower.pory"

# 666 "data/scripts/follower.pory"
EventScript_FollowerFaceDown:
# 667 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER Common_Movement_FaceDown
# 668 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 669 "data/scripts/follower.pory"
	goto EventScript_FollowerGenericSkipFace
# 670 "data/scripts/follower.pory"

# 671 "data/scripts/follower.pory"
EventScript_FollowerFaceLeft:
# 672 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER Common_Movement_FaceLeft
# 673 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 674 "data/scripts/follower.pory"
	goto EventScript_FollowerGenericSkipFace
# 675 "data/scripts/follower.pory"

# 676 "data/scripts/follower.pory"
EventScript_FollowerFaceRight:
# 677 "data/scripts/follower.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER Common_Movement_FaceRight
# 678 "data/scripts/follower.pory"
	waitmovement OBJ_EVENT_ID_FOLLOWER
# 679 "data/scripts/follower.pory"
	goto EventScript_FollowerGenericSkipFace

EventScript_Follower_Text_0:
# 6 "data/scripts/follower.pory"
	.string "Take Spinda for a spin?$"

EventScript_Follower_Text_1:
# 16 "data/scripts/follower.pory"
	.string "Spin clockwise$"

EventScript_Follower_Text_2:
# 17 "data/scripts/follower.pory"
	.string "Spin counterclockwise$"

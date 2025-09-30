This is the README for Jamie's Movement Pack feature branch, please refer to another branch for the pokeemerald-expansion README

# Videos

## `Shake Movement Actions`

https://github.com/user-attachments/assets/12f6b975-5f1d-468d-b385-c874f7344770
***
The video show the npc following this movement rountine:
```
	face_left
	shake_horizontal
	shake_vertical
	face_up
	shake_horizontal
	shake_vertical
	face_down
	shake_horizontal
	shake_vertical
	face_right
	shake_horizontal
	shake_vertical
	step_end
```
## `Quarter Step`
https://github.com/user-attachments/assets/64f90d2b-61de-42bf-a751-5c24c771c79c
***
The video show the npc following this movement rountine:
```
	quarter_step_left
	delay_16
	delay_16
	lock_facing_direction
	quarter_step_right
	delay_16
	unlock_facing_direction
	face_right
	delay_16
	quarter_step_right
	delay_16
	delay_16
	lock_facing_direction
	quarter_step_left
	delay_16
	unlock_facing_direction
	face_up
	delay_16
	quarter_step_up
	delay_16
	delay_16
	lock_facing_direction
	quarter_step_down
	delay_16
	unlock_facing_direction
	face_down
	delay_16
	quarter_step_down
	delay_16
	delay_16
	lock_facing_direction
	quarter_step_up
	delay_16
	step_end
```
# Usage

## `Shake Movement Actions`

You can use `shake_horizontal` and `shake_vertical` in the movement script of an object event and they will start shaking.<br>
As seen in the videos, the shake will last 32 frames and the sprite of the object event will change position every 4 frames always staying one pixel away from the original position until the shaking is over

## `Quarter Step`

You can use `quarter_step_left`, `quarter_step_right`, `quarter_step_up` and `quarter_step_down` in the movement script of an object event and they move around a quarter step in the desired direction.<br>
The action should take 16 frames. During this movement, the object event is not moving, only its sprite so collision will occurs as if the object event was staying in the position before it started quarter stepping.

# Questions and Bug Reports

If you have difficulties or encounter a bug, you can post in the #romhacking-help channel of the Team Aqua Hideout (TAH) discord server and ping @Jamie

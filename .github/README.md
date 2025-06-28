This is the README for the Shake Movement Actions feature branch, please refer to anotehr branch for the pokeemerald-expansion README

# About `Shake Movement Actions`

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
# Usage

You can use `shake_horizontal` and `shake_vertical` in the movement script of an object event and they will start shaking.<br>
As seen in the videos, the shake will last 32 frames and the sprite of the object event will change position every 4 frames always staying one pixel away from the original position until the shaking is over

# Questions and Bug Reports

If you have difficulties or encounter a bug, you can post in the #romhacking-help channel of the Team Aqua Hideout (TAH) discord server and ping @Jamie

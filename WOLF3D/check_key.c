/*
** check_key.c for wolf3dbonus in /home/Rev/wolf3dbonus
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Mon Jan	9 15:40:03 2017 Roméo Nahon
** Last update	Mon Jan	9 15:40:03 2017 Roméo Nahon
*/

#include "include/my.h"

void	check_key(BUFF)
{
	movement(framebuffer);
	shot_key(framebuffer);
	switch_weapon(framebuffer);
	if (framebuffer->music_play1 == 0 && framebuffer->music_play2 == 0)
		sfSound_stop(framebuffer->walk_sound);
}

void	shot_key(BUFF)
{
	if (sfKeyboard_isKeyPressed(sfKeyQ) == sfTrue)
	{
		framebuffer->stab = 1;
		raycast(framebuffer);
		if (framebuffer->touch == 0 && framebuffer->weapon == 1)
			sfSound_play(framebuffer->stab_in_air);
		framebuffer->touch = 0;
		if (framebuffer->weapon == 0)
			shoot_animation(framebuffer);
		else if (framebuffer->weapon == 1)
			stab_animation(framebuffer);
	}
	else
	{
		framebuffer->shot = 0;
		framebuffer->stab = 0;
	}
}

void	switch_weapon(BUFF)
{
	if (sfKeyboard_isKeyPressed(sfKeyNum1) == sfTrue)
		framebuffer->weapon = 0;
	else if (sfKeyboard_isKeyPressed(sfKeyNum2) == sfTrue)
		framebuffer->weapon = 1;
}

void	movement(BUFF)
{
	if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue)
		move_up(framebuffer);
	else
	{
		sfSound_stop(framebuffer->run_sound);
		framebuffer->music_play1 = 0;
	}
	if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue)
		move_down(framebuffer);
	else	
		framebuffer->music_play2 = 0;
	if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue)
		move_right(framebuffer);
	if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue)
		move_left(framebuffer);
}
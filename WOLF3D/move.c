/*
** move.c for wolf3d in /home/Rev/wolf3d
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Wed Jan	4 11:36:47 2017 Roméo Nahon
** Last update	Wed Jan	4 11:36:47 2017 Roméo Nahon
*/

#include "include/my.h"

void	move_up(BUFF)
{
	if (MAP_R[(int)(R_POS_Y + R_DIR_Y * SPEED)][(int)R_POS_X] == 0)
		R_POS_Y += R_DIR_Y * SPEED;
	if (MAP_R[(int)R_POS_Y][(int)(R_POS_X + R_DIR_X * SPEED)] == 0)
		R_POS_X += R_DIR_X * SPEED;
	display_all(framebuffer);
	if (framebuffer->music_play1 == 1
		&& sfSound_getStatus(framebuffer->walk_sound) != sfPlaying)
		sfSound_play(framebuffer->walk_sound);
	if (sfKeyboard_isKeyPressed(sfKeyLShift) == sfTrue)
	{
		framebuffer->music_play1 = 0;
		SPEED = 0.25;
		if (framebuffer->music_play1 == 0
			&& sfSound_getStatus(framebuffer->run_sound) != sfPlaying)
			sfSound_play(framebuffer->run_sound);
	}
	else
	{
		sfSound_stop(framebuffer->run_sound);
		framebuffer->music_play1 = 1;
		SPEED = 0.15;
	}
}

void	move_down(BUFF)
{
	if (MAP_R[(int)(R_POS_Y - R_DIR_Y * SPEED)][(int)R_POS_X] == 0)
		R_POS_Y -= R_DIR_Y * SPEED;
	if (MAP_R[(int)R_POS_Y][(int)(R_POS_X - R_DIR_X * SPEED)] == 0)
		R_POS_X -= R_DIR_X * SPEED;
	display_all(framebuffer);
	framebuffer->music_play2 = 1;
	if (framebuffer->music_play2 == 1
		&& sfSound_getStatus(framebuffer->walk_sound) != sfPlaying)
		sfSound_play(framebuffer->walk_sound);
}

void	move_right(BUFF)
{
	OLD_D_X = R_DIR_X;
	R_DIR_X = R_DIR_X * cos((-1 * ROTSPEED)) - R_DIR_Y * sin(-1 * ROTSPEED);
	R_DIR_Y = OLD_D_X * sin((-1 * ROTSPEED)) + R_DIR_Y * cos(-1 * ROTSPEED);
	OLD_P_X = R_PLAN_X;
	R_PLAN_X = R_PLAN_X * cos((-1 * ROTSPEED)) - R_PLAN_Y * sin(-1 * ROTSPEED);
	R_PLAN_Y = OLD_P_X * sin((-1 * ROTSPEED)) + R_PLAN_Y * cos(-1 * ROTSPEED);
	display_all(framebuffer);
}

void	move_left(BUFF)
{
	OLD_D_X = R_DIR_X;
	R_DIR_X = R_DIR_X * cos(ROTSPEED) - R_DIR_Y * sin(ROTSPEED);
	R_DIR_Y = OLD_D_X * sin(ROTSPEED) + R_DIR_Y * cos(ROTSPEED);
	OLD_P_X = R_PLAN_X;
	R_PLAN_X = R_PLAN_X * cos(ROTSPEED) - R_PLAN_Y * sin(ROTSPEED);
	R_PLAN_Y = OLD_P_X * sin(ROTSPEED) + R_PLAN_Y * cos(ROTSPEED);
	display_all(framebuffer);
}
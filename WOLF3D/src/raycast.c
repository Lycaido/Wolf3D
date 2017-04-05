/*
** raycast.c for wolf3d in /home/Rev/wolf3d/src
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Fri Dec	23 17:54:30 2016 Roméo Nahon
** Last update	Fri Dec	23 17:54:30 2016 Roméo Nahon
*/

#include "include/my.h"
void	init_raycast_value(BUFF)
{
	R_CAM_X = (2 * R_X / (double)S_WIDTH) - 1;
	R_RAYD_X = R_DIR_X + R_PLAN_X * R_CAM_X;
	R_RAYD_Y = R_DIR_Y + R_PLAN_Y * R_CAM_X;
	R_CAMMAP_X = (int)R_POS_X;
	R_CAMMAP_Y = (int)R_POS_Y;
	R_INTERDIST_X = sqrt(1 + (R_RAYD_Y * R_RAYD_Y) / (R_RAYD_X * R_RAYD_X));
	R_INTERDIST_Y = sqrt(1 + (R_RAYD_X * R_RAYD_X) / (R_RAYD_Y * R_RAYD_Y));
	R_TOUCHW = 0;
}

void	raycast(BUFF)
{
	R_X = 0;
	R_Y = 0;
	while (R_X <= S_WIDTH)
	{
		init_raycast_value(framebuffer);
		check_raycast_dist(framebuffer);
		find_raycast_intersection(framebuffer);
		correct_visual(framebuffer);
		shoot_enemy(framebuffer);
		limit_draw(framebuffer);
		draw_wall(framebuffer);
		R_X++;
	}
}

void	shoot_enemy(BUFF)
{
	if (R_TOUCHW == 2 && R_X == S_WIDTH / 2
		&& framebuffer->shot == 1 && framebuffer->weapon == 0)
	{
		sfSound_play(framebuffer->explosion);
		framebuffer->map_ray[R_CAMMAP_Y][R_CAMMAP_X] = 0;
		framebuffer->shot = 0;
		framebuffer->enemy -= 1;
	}
	if (R_TOUCHW == 2 && R_X == S_WIDTH / 2 && framebuffer->weapon == 1)
	{
		if (R_GOODW < 0.5 && framebuffer->stab == 1)
		{
			framebuffer->touch = 1;
			framebuffer->enemy -= 1;
			sfSound_play(framebuffer->stab_inside);
			sfSound_play(framebuffer->explosion);
			framebuffer->map_ray[R_CAMMAP_Y][R_CAMMAP_X] = 0;
		}
	}
}
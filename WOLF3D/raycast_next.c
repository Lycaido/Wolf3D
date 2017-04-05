/*
** raycast_next.c for wolf3d in /home/Rev/wolf3d
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Tue Jan	3 18:16:30 2017 Roméo Nahon
** Last update	Tue Jan	3 18:16:30 2017 Roméo Nahon
*/

#include "include/my.h"

void	check_raycast_dist(BUFF)
{
	if (R_RAYD_X < 0)
	{
		R_STEPD_X = -1;
		R_DISTSIDE_X = (R_POS_X - R_CAMMAP_X) * R_INTERDIST_X;
	}
	else
	{
		R_STEPD_X = 1;
		R_DISTSIDE_X = (R_CAMMAP_X + 1.0 - R_POS_X) * R_INTERDIST_X;
	}		
	if (R_RAYD_Y < 0)
	{
		R_STEPD_Y = -1;
		R_DISTSIDE_Y = (R_POS_Y - R_CAMMAP_Y) * R_INTERDIST_Y;
	}
	else
	{
		R_STEPD_Y = 1;
		R_DISTSIDE_Y = (R_CAMMAP_Y + 1.0 - R_POS_Y) * R_INTERDIST_Y;
	}
}

void	find_raycast_intersection(BUFF)
{
	while (R_TOUCHW == 0)
	{
		if (R_DISTSIDE_X < R_DISTSIDE_Y)
		{
			R_DISTSIDE_X += R_INTERDIST_X;
			R_CAMMAP_X += R_STEPD_X;
			R_SIDE = 0;
		}
		else
		{
			R_DISTSIDE_Y += R_INTERDIST_Y;
			R_CAMMAP_Y += R_STEPD_Y;
			R_SIDE = 1;
		}
		if (framebuffer->map_ray[R_CAMMAP_Y][R_CAMMAP_X] == 1)
			R_TOUCHW = 1;
		if (framebuffer->map_ray[R_CAMMAP_Y][R_CAMMAP_X] == 2)
			R_TOUCHW = 2;
	}
}

void	correct_visual(BUFF)
{
	if (R_SIDE == 0)
		R_GOODW = (R_CAMMAP_X - R_POS_X + (1 - R_STEPD_X) / 2) / R_RAYD_X;
	else
		R_GOODW = (R_CAMMAP_Y - R_POS_Y + (1 - R_STEPD_Y) / 2) / R_RAYD_Y;
}

void	limit_draw(BUFF)
{
	R_HEIGHTW = (int)(S_HEIGHT / R_GOODW);
	R_SDRAW = (int)((-R_HEIGHTW) / 2 + S_HEIGHT / 2);
	R_EDRAW = (int)(R_HEIGHTW / 2 + S_HEIGHT / 2);
	if (R_SDRAW < 0)
		R_SDRAW = 0;
	if (R_EDRAW >= S_HEIGHT)
		R_EDRAW = S_HEIGHT - 1;
}

void	draw_wall(BUFF)
{
	R_Y = R_SDRAW;
	shadow(framebuffer);
	color_wall(framebuffer);
	color_floor_cell(framebuffer);
}
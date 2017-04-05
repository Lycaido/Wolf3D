/*
** color_next.c for wolf3d in /home/Rev/wolf3dbonus
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Thu Jan	5 15:19:01 2017 Roméo Nahon
** Last update	Thu Jan	5 15:19:01 2017 Roméo Nahon
*/

#include "include/my.h"

sfColor	red_color(BUFF)
{
	sfColor color;

	color.r = 230;
	color.g = 0;
	color.b = 0;
	color.a = framebuffer->opaque;
	return (color);
}

void	shadow(BUFF)
{
	if (R_GOODW >= 3)
	{
		framebuffer->opaque = 130 - (R_GOODW * 5);
		if (framebuffer->opaque <= 10)
			framebuffer->opaque = 10;
		framebuffer->grey = 100 - (R_GOODW * 5);
		if (framebuffer->grey <= 10)
			framebuffer->grey = 10;
		framebuffer->greyplus = 30;
	}
	else
	{
		framebuffer->opaque = 130 + (R_GOODW);
		framebuffer->grey = 100 + (R_GOODW);
		framebuffer->greyplus = 30;
	}
}

void	color_wall(BUFF)
{
	if (R_TOUCHW == 1)
	{
		while (R_Y < R_EDRAW)
		{
			if (R_SIDE == 1)
				my_put_pixel(framebuffer, R_X, R_Y, grey_color(framebuffer));
			else
				my_put_pixel(framebuffer, R_X, R_Y, white_color(framebuffer));
			R_Y++;
		}
	}
	if (R_TOUCHW == 2)
	{
		while (R_Y < R_EDRAW)
		{
			if (R_SIDE == 1)
				my_put_pixel(framebuffer, R_X, R_Y, red_color(framebuffer));
			else
				my_put_pixel(framebuffer, R_X, R_Y, red_color(framebuffer));
			R_Y++;
		}
	}
}

void	color_floor_cell(BUFF)
{
	if (R_EDRAW < 0)
		R_EDRAW = S_HEIGHT;
	R_Y = R_EDRAW;
	while (R_Y < S_HEIGHT)
	{
		my_put_pixel(framebuffer, R_X, SKY_Y, greyplus_color(framebuffer));
		my_put_pixel(framebuffer, R_X, R_Y, brown_color(framebuffer));
		R_Y++;
	}	
}
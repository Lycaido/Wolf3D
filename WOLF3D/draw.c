/*
** draw.c for wolf3d in /home/Rev/wolf3d
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Mon Jan	2 13:35:29 2017 Roméo Nahon
** Last update	Mon Jan	2 13:35:29 2017 Roméo Nahon
*/

#include "include/my.h"

int	draw_square(BUFF, sfColor color, int x, int y)
{
	int x_;
	int	y_;
	int y_tmp;

	x_ = x + 7;
	y_ = y + 7;
	y_tmp = y;
	while (x < x_)
	{
		y = y_tmp;
		while (y < y_)
		{
			framebuffer->pixels[(S_WIDTH * y + x) * 4] = color.r;
			framebuffer->pixels[(S_WIDTH * y + x) * 4 + 1] = color.g;
			framebuffer->pixels[(S_WIDTH * y + x) * 4 + 2] = color.b;
			framebuffer->pixels[(S_WIDTH * y + x) * 4 + 3] = color.a;
			y = y + 1;
		}
		x = x + 1;
	}
}

void	draw_crossfire(BUFF)
{
	sfVector2i	from1;
	sfVector2i	from2;
	sfVector2i	to1;
	sfVector2i	to2;
	int x;
	int y;

	from1.x = (S_WIDTH / 2) - 10;
	from1.y = S_HEIGHT / 2;
	from2.x = S_WIDTH / 2;
	from2.y = (S_HEIGHT / 2) - 10;
	to1.x = (S_WIDTH / 2) + 10;
	to1.y = (S_HEIGHT / 2);
	to2.x = (S_WIDTH / 2);
	to2.y = (S_HEIGHT / 2) + 10;
	my_draw_line(framebuffer, from1, to1, sfRed);
	my_draw_line(framebuffer, from2, to2, sfRed);
}
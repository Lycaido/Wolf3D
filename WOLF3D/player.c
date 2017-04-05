/*
** player.c for wolf3d in /home/Rev/wolf3d
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Sat Dec	24 12:52:26 2016 Roméo Nahon
** Last update	Sat Dec	24 12:52:26 2016 Roméo Nahon
*/

#include "include/my.h"

int	draw_player(BUFF, sfColor color, int x, int y)
{
	int x_;
	int	y_;
	int y_tmp;

	x_ = x + 7;
	y_ = y + 7;
	y_tmp = y + 3;
	while (x + 3 < x_ + 3)
	{
		y = y_tmp;
		while (y < y_ + 3)
		{
			framebuffer->pixels[(S_WIDTH * y + x) * 4] = color.r;
			framebuffer->pixels[(S_WIDTH * y + x) * 4 + 1] = color.g;
			framebuffer->pixels[(S_WIDTH * y + x) * 4 + 2] = color.b;
			framebuffer->pixels[(S_WIDTH * y + x) * 4 + 3] = color.a;
			y = y + 1;
		}
		x += 1;
	}
}
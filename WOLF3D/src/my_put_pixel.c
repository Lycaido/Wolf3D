/*
** my_put_pixel.c for raytracer1 in /home/Rev/raytracer1
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Thu Feb	9 19:27:34 2017 Roméo Nahon
** Last update	Thu Feb	9 19:27:34 2017 Roméo Nahon
*/

#include "../include/my.h"

void	my_put_pixel(BUFF, int x, int y, sfColor color)
{
	if (y < S_HEIGHT && x < S_WIDTH)
	{
		framebuffer->pixels[(S_WIDTH * y + x) * 4] = color.r;
		framebuffer->pixels[(S_WIDTH * y + x) * 4 + 1] = color.g;
		framebuffer->pixels[(S_WIDTH * y + x) * 4 + 2] = color.b;
		framebuffer->pixels[(S_WIDTH * y + x) * 4 + 3] = color.a;
	}
}
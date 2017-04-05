/*
** color.c for wolf3d in /home/Rev/wolf3d
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Tue Jan	3 18:27:20 2017 Roméo Nahon
** Last update	Tue Jan	3 18:27:20 2017 Roméo Nahon
*/

#include "include/my.h"

sfColor	grey_color(BUFF)
{
	sfColor color;

	color.r = 255;
	color.g = 255;
	color.b = 255;
	color.a = framebuffer->grey;
	return (color);
}

sfColor	greyplus_color(BUFF)
{
	sfColor color;

	color.r = 255;
	color.g = 255;
	color.b = 255;
	color.a = framebuffer->greyplus;
	return (color);
}

sfColor	white_color(BUFF)
{
	sfColor color;

	color.r = 255;
	color.g = 255;
	color.b = 255;
	color.a = framebuffer->opaque;
	return (color);
}

sfColor	brown_color(BUFF)
{
	sfColor color;

	color.r = 80;
	color.g = 29;
	color.b = 29;
	color.a = framebuffer->opaque;
	return (color);
}

sfColor	orange_color()
{
	sfColor color;

	color.r = 255;
	color.g = 141;
	color.b = 0;
	color.a = 255;
	return (color);
}
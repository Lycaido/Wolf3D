/*
** init_next.c for wolf3dbonus in /home/Rev/wolf3dbonus
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Fri Jan	13 15:24:48 2017 Roméo Nahon
** Last update	Fri Jan	13 15:24:48 2017 Roméo Nahon
*/

#include "include/my.h"

void	init_menu_next(BUFF)
{
	sfText_setFont(framebuffer->menu_play, framebuffer->menu_font);
	sfText_setFont(framebuffer->menu_quit, framebuffer->menu_font);
	sfText_setFont(framebuffer->menu_help, framebuffer->menu_font);
	sfText_setString(framebuffer->menu_play, "Play");
	sfText_setString(framebuffer->menu_help, "Help");
	sfText_setString(framebuffer->menu_quit, "Quit");
	sfText_setCharacterSize(framebuffer->menu_play, 50);
	sfText_setCharacterSize(framebuffer->menu_quit, 50);
	sfText_setCharacterSize(framebuffer->menu_help, 50);
}

void	init_time(BUFF)
{
	sfVector2f pos;

	framebuffer->time_text = sfText_create();
	sfText_setFont(framebuffer->time_text, framebuffer->menu_font);
	sfText_setCharacterSize(framebuffer->time_text, 50);
	pos.x = S_WIDTH / 2;
	pos.y = 0;
	sfText_setPosition(framebuffer->time_text, pos);
}
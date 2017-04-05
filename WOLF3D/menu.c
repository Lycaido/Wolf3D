/*
** menu.c for wolf3dbonus in /home/Rev/wolf3dbonus
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Sat Jan	7 14:51:56 2017 Roméo Nahon
** Last update	Sat Jan	7 14:51:56 2017 Roméo Nahon
*/

#include "include/my.h"

void	create_menu(BUFF)
{
	sfRenderWindow_drawSprite(FMV, framebuffer->main_menu, NULL);
	display_option(framebuffer);
	if (framebuffer->select_option == 0)
	{
		sfText_setColor(framebuffer->menu_quit, sfWhite);
		sfText_setColor(framebuffer->menu_help, sfWhite);
		sfText_setColor(framebuffer->menu_play, sfRed);
	}
	if (framebuffer->select_option == 1)
	{
		sfText_setColor(framebuffer->menu_play, sfWhite);
		sfText_setColor(framebuffer->menu_quit, sfWhite);
		sfText_setColor(framebuffer->menu_help, sfRed);
	}
	if (framebuffer->select_option == 2)
	{
		sfText_setColor(framebuffer->menu_play, sfWhite);
		sfText_setColor(framebuffer->menu_quit, sfRed);
		sfText_setColor(framebuffer->menu_help, sfWhite);
	}
}

void	create_help_menu(BUFF)
{
	sfRenderWindow_drawSprite(FMV, framebuffer->help_menu, NULL);
	sfRenderWindow_drawText(FMV, framebuffer->play2_text, NULL);
	sfText_setColor(framebuffer->play2_text, sfRed);
	sfRenderWindow_display(framebuffer->window);
}

void	display_option(BUFF)
{
	sfRenderWindow_drawText(FMV, framebuffer->menu_play, NULL);
	sfRenderWindow_drawText(FMV, framebuffer->menu_help, NULL);
	sfRenderWindow_drawText(FMV, framebuffer->menu_quit, NULL);
}
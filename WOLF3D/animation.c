/*
** animation.c for wolf3dbonus in /home/Rev/wolf3dbonus
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Sat Jan	7 11:35:45 2017 Roméo Nahon
** Last update	Sat Jan	7 11:35:46 2017 Roméo Nahon
*/

#include "include/my.h"

void	shoot_animation(BUFF)
{
	sfRenderWindow_clear(framebuffer->window, sfBlack);
	sfRenderWindow_drawSprite(FMV, framebuffer->sprite, NULL);
	sfRenderWindow_drawSprite(FMV, framebuffer->gun_fire, NULL);
	sfRenderWindow_drawText(FMV, framebuffer->time_text, NULL);
	sfRenderWindow_display(framebuffer->window);
	framebuffer->shot = 1;
	usleep(80000);
	sfRenderWindow_clear(framebuffer->window, sfBlack);
	sfRenderWindow_drawSprite(FMV, framebuffer->sprite, NULL);
	sfRenderWindow_drawSprite(FMV, framebuffer->gun_after_fire, NULL);
	sfRenderWindow_drawText(FMV, framebuffer->time_text, NULL);
	sfRenderWindow_display(framebuffer->window);
	usleep(80000);
	sfRenderWindow_clear(framebuffer->window, sfBlack);
	sfRenderWindow_drawSprite(FMV, framebuffer->sprite, NULL);
	sfRenderWindow_drawSprite(FMV, framebuffer->gun, NULL);
	sfRenderWindow_drawText(FMV, framebuffer->time_text, NULL);
	sfRenderWindow_display(framebuffer->window);
	sfSound_play(framebuffer->shot_gun_sound);
}

void	stab_animation(BUFF)
{
	sfRenderWindow_clear(framebuffer->window, sfBlack);
	sfRenderWindow_drawSprite(FMV, framebuffer->sprite, NULL);
	sfRenderWindow_drawSprite(FMV, framebuffer->stab_knife, NULL);
	sfRenderWindow_drawText(FMV, framebuffer->time_text, NULL);
	sfRenderWindow_display(framebuffer->window);
	usleep(120000);
	sfRenderWindow_clear(framebuffer->window, sfBlack);
	sfRenderWindow_drawSprite(FMV, framebuffer->sprite, NULL);
	sfRenderWindow_drawSprite(FMV, framebuffer->knife, NULL);
	sfRenderWindow_drawText(FMV, framebuffer->time_text, NULL);
	sfRenderWindow_display(framebuffer->window);
}

void	snake_animation(BUFF)
{
	sfRenderWindow_clear(framebuffer->window, sfBlack);
	sfRenderWindow_drawSprite(FMV, framebuffer->history, NULL);
	sfRenderWindow_drawSprite(FMV, framebuffer->snake2, NULL);
	sfRenderWindow_drawText(FMV, framebuffer->play_speetch, NULL);
	sfRenderWindow_display(framebuffer->window);
	usleep(200000);
	sfRenderWindow_clear(framebuffer->window, sfBlack);
	sfRenderWindow_drawSprite(FMV, framebuffer->history, NULL);
	sfRenderWindow_drawSprite(FMV, framebuffer->snake1, NULL);
	sfRenderWindow_drawText(FMV, framebuffer->play_speetch, NULL);
	sfRenderWindow_display(framebuffer->window);
	usleep(200000);
}
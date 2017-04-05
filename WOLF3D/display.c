/*
** display.c for wolf3d in /home/Rev/wolf3dbonus
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Mon Jan	9 15:37:29 2017 Roméo Nahon
** Last update	Mon Jan	9 15:37:29 2017 Roméo Nahon
*/

#include "include/my.h"

void	display(BUFF)
{
	sfRenderWindow_clear(framebuffer->window, sfBlack);
	sfRenderWindow_drawSprite(FMV, framebuffer->sprite, NULL);
	if (framebuffer->weapon == 0)
		sfRenderWindow_drawSprite(FMV, framebuffer->gun, NULL);
	else if (framebuffer->weapon == 1)
		sfRenderWindow_drawSprite(FMV, framebuffer->knife, NULL);
	if (framebuffer->timer >= (TIME - 1))
		disp_loose(framebuffer);
	else if (framebuffer->enemy == 0)
		disp_win(framebuffer);
	sfRenderWindow_drawText(FMV, framebuffer->time_text, NULL);
	sfRenderWindow_display(framebuffer->window);
}

void	disp_win(BUFF)
{
	framebuffer->select_menu = 0;
	sfRenderWindow_drawText(FMV, framebuffer->win, NULL);
	sfRenderWindow_display(framebuffer->window);
	sfMusic_stop(framebuffer->main_music);
	sfSound_stop(framebuffer->walk_sound);
	sfSound_stop(framebuffer->run_sound);
	sfSound_stop(framebuffer->explosion);
	sfMusic_play(framebuffer->win_music);
	sleep(7);
	free_all(framebuffer);
	exit(1);
}

void	disp_loose(BUFF)
{
	framebuffer->select_menu = 0;
	sfRenderWindow_drawText(FMV, framebuffer->game_over, NULL);
	sfRenderWindow_display(framebuffer->window);
	sfMusic_stop(framebuffer->main_music);
	sfSound_stop(framebuffer->walk_sound);
	sfSound_stop(framebuffer->run_sound);
	sfSound_stop(framebuffer->explosion);
	sfMusic_play(framebuffer->game_over_music);
	sleep(6);
	free_all(framebuffer);
	exit(2);
}

void	display_all(BUFF)
{
	raycast(framebuffer);
	minimap(framebuffer);
	display_fov(framebuffer);
	draw_player(framebuffer, COLOR_P, R_POS_X * SQUARE, R_POS_Y * SQUARE);
	draw_crossfire(framebuffer);
}

void	display_fov(BUFF)
{
	float x;
	float y;

	x = R_POS_X + 0.3;
	y = R_POS_Y + 0.6;
	framebuffer->from.x = x * SQUARE;
	framebuffer->from.y = y * SQUARE;
	framebuffer->to.x = x * SQUARE + R_DIR_X * SQUARE + R_PLAN_X * SQUARE;
	framebuffer->to.y = y * SQUARE + R_DIR_Y * SQUARE + R_PLAN_Y * SQUARE;
	my_draw_line(framebuffer, framebuffer->to, framebuffer->from, COLOR_P);
	framebuffer->to.x = x * SQUARE + R_DIR_X * SQUARE - R_PLAN_X * SQUARE;
	framebuffer->to.y = y * SQUARE + R_DIR_Y * SQUARE - R_PLAN_Y * SQUARE;
	my_draw_line(framebuffer, framebuffer->to, framebuffer->from, COLOR_P);
}
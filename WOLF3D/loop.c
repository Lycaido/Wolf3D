/*
** loop.c for wolf3D in /home/Rev/wolf3d
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Fri Dec	23 14:35:56 2016 Roméo Nahon
** Last update	Fri Dec	23 14:35:56 2016 Roméo Nahon
*/

#include "include/my.h"


void	event(BUFF, int start)
{
	while (sfRenderWindow_pollEvent(framebuffer->window, &framebuffer->event))
		event_in_event(framebuffer);
	if (framebuffer->start == 0)
	{
		create_menu(framebuffer);
		sfRenderWindow_display(framebuffer->window);
	}
	if (framebuffer->select_menu == 1 && framebuffer->start_game == 1)
		check_key(framebuffer);
	if (framebuffer->select_menu == 3)
	{
		create_help_menu(framebuffer);
		if (sfKeyboard_isKeyPressed(sfKeyReturn) == sfTrue
			&& framebuffer->start == 2)
		{
			framebuffer->start = 0;
			framebuffer->select_menu = 0;
			framebuffer->select_option = 0;
		}
		framebuffer->start = 2;
	}
}

void	event_in_event(BUFF)
{
	if (FEKC == sfKeyEscape || framebuffer->event.type == sfEvtClosed
		|| (sfKeyboard_isKeyPressed(sfKeyReturn) == sfTrue  && S_O == 2))
		sfRenderWindow_close(framebuffer->window);
	if (framebuffer->start == 0)
	{
		if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue && S_O > 0)
			framebuffer->select_option -= 1;
		else if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue && S_O < 2)
			framebuffer->select_option += 1;
	}
	if (sfKeyboard_isKeyPressed(sfKeyReturn) == sfTrue && S_O == 0)
		framebuffer->select_menu = 1;
	if (sfKeyboard_isKeyPressed(sfKeyReturn) == sfTrue && S_O == 2)
		framebuffer->select_menu = 2;
	if (sfKeyboard_isKeyPressed(sfKeyReturn) == sfTrue && S_O == 1)
		framebuffer->select_menu = 3;
}

void	loop(BUFF)
{
	char 	res[1];
	int 	start;
	int 	voice;
	int  	anim;

	start = 0;
	voice = 0;
	anim = 0;
	while (sfRenderWindow_isOpen(framebuffer->window))
	{
		event(framebuffer, start);
		if (framebuffer->select_menu == 1)
		{
			voice = speetch_start(framebuffer, start, voice);
			start = game_start(framebuffer, start);
		}
		sfTexture_updateFromPixels(FT, FP, S_WIDTH, S_HEIGHT, 0, 0);
		usleep(30000);
	}
	free_all(framebuffer);
}

int		speetch_start(BUFF, int start, int voice)
{
	framebuffer->start = 1;
	if (start == 0)
	{
		if (voice == 0)
		{
			sfMusic_setVolume(framebuffer->menu_music, 50.0);
			sfMusic_play(framebuffer->snake_voice);
		}
		voice = 1;
		if (sfMusic_getStatus(framebuffer->snake_voice) == sfPlaying)
			snake_animation(framebuffer);
	}
	if (sfKeyboard_isKeyPressed(sfKeyReturn) == sfTrue && start == 0 && S_M == 1)
		framebuffer->start_game = 1;
	return (voice);
}

int		game_start(BUFF, int start)
{
	if (framebuffer->start_game == 1)
	{
		framebuffer->timer += ((float)1 / 17);
		sfText_setString(T_T, intoarg(C_T - framebuffer->timer, 2));
		if (start == 0)
		{
			sfMusic_stop(framebuffer->snake_voice);
			sfMusic_stop(framebuffer->menu_music);
			sfMusic_play(framebuffer->main_music);
		}
		start = 1;
		display_all(framebuffer);
		display(framebuffer);
	}
	return (start);
}
/*
** init.c for wolf3D in /home/Rev/wolf3d
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Fri Dec	23 14:35:50 2016 Roméo Nahon
** Last update	Fri Dec	23 14:35:50 2016 Roméo Nahon
*/

#include "include/my.h"

int		init(t_my_framebuffer *framebuffer)
{
	framebuffer->mode.width = S_WIDTH;
	framebuffer->mode.height = S_HEIGHT;
	framebuffer->mode.bitsPerPixel = 32;
	FMV = sfRenderWindow_create(FM, "Metal Gear Wolf3D", sfResize | sfClose, NULL);
	if (framebuffer->window == NULL)
		return (-1);
	sfRenderWindow_setVerticalSyncEnabled(FMV, sfTrue);
	sfRenderWindow_setFramerateLimit(FMV, 120);
	framebuffer->sprite = sfSprite_create();
	framebuffer->texture = sfTexture_create(S_WIDTH, S_HEIGHT);
	create_pixel_buffer(framebuffer);
	sfSprite_setTexture(framebuffer->sprite, framebuffer->texture, sfTrue);
	init_gun(framebuffer);
	init_knife(framebuffer);
	init_snake(framebuffer);
	init_music(framebuffer);
	init_menu(framebuffer);
	init_help(framebuffer);
	init_time(framebuffer);
	init_gm_win(framebuffer);
	sfMusic_play(framebuffer->menu_music);
	sfTexture_updateFromPixels(FT, FP, S_WIDTH, S_HEIGHT, 0, 0);
	return (0);
}

void	init_menu(BUFF)
{
	sfVector2f pos_text;

	framebuffer->main_menu = sfSprite_create();
	M_M = sfMusic_createFromFile("ressources/menu_theme.ogg");
	sfMusic_setLoop(framebuffer->menu_music, sfTrue);
	sfMusic_setVolume(framebuffer->main_music, 40.0);
	M_M_T = sfTexture_createFromFile("ressources/main_menu.png", NULL);
	sfSprite_setTexture(framebuffer->main_menu, M_M_T, sfTrue);
	M_F = sfFont_createFromFile("ressources/DampfPlatzsh.ttf");
	framebuffer->menu_play = sfText_create();
	framebuffer->menu_quit = sfText_create();
	framebuffer->menu_help = sfText_create();
	init_menu_next(framebuffer);
	pos_text.x = 640;
	pos_text.y = 400;
	sfText_setPosition(framebuffer->menu_play, pos_text);
	pos_text.x = 640;
	pos_text.y = 600;
	sfText_setPosition(framebuffer->menu_quit, pos_text);
	pos_text.x = 640;
	pos_text.y = 500;
	sfText_setPosition(framebuffer->menu_help, pos_text);
}

void	init_help(BUFF)
{
	sfVector2f pos_text;

	framebuffer->help_menu = sfSprite_create();
	H_M_T = sfTexture_createFromFile("ressources/help_menu.png", NULL);
	sfSprite_setTexture(framebuffer->help_menu, H_M_T, sfTrue);
	framebuffer->play2_text = sfText_create();
	framebuffer->play_speetch = sfText_create();
	sfText_setFont(framebuffer->play2_text, framebuffer->menu_font);
	sfText_setFont(framebuffer->play_speetch, framebuffer->menu_font);
	sfText_setString(framebuffer->play2_text, "Play");
	sfText_setString(framebuffer->play_speetch, "Press Enter");
	sfText_setCharacterSize(framebuffer->play2_text, 50);
	sfText_setCharacterSize(framebuffer->play_speetch, 50);
	pos_text.x = S_WIDTH / 2 - 50;
	pos_text.y = 700;
	sfText_setPosition(framebuffer->play2_text, pos_text);
	pos_text.x = S_WIDTH / 2 - 100;
	pos_text.y = 700;
	sfText_setPosition(framebuffer->play_speetch, pos_text);
	sfText_setColor(framebuffer->play_speetch, sfRed);
}

void	init_music(BUFF)
{
	MAIN_M = sfMusic_createFromFile("ressources/main_theme3.ogg");
	W_S_B = sfSoundBuffer_createFromFile("ressources/walk_sound2.ogg");
	framebuffer->walk_sound = sfSound_create();
	S_G_S_B = sfSoundBuffer_createFromFile("ressources/shootgun.ogg");
	framebuffer->shot_gun_sound = sfSound_create();
	R_S_B = sfSoundBuffer_createFromFile("ressources/run_sound.ogg");
	framebuffer->run_sound = sfSound_create();
	framebuffer->stab_in_air = sfSound_create();
	S_I_A_B = sfSoundBuffer_createFromFile("ressources/stab_in_air.ogg");
	framebuffer->stab_inside = sfSound_create();
	S_I_B = sfSoundBuffer_createFromFile("ressources/stab_inside.ogg");
	sfSound_setBuffer(framebuffer->walk_sound, framebuffer->walk_sound_b);
	sfSound_setBuffer(framebuffer->run_sound, framebuffer->run_sound_b);
	sfSound_setBuffer(framebuffer->shot_gun_sound, S_G_S_B);
	sfSound_setBuffer(framebuffer->stab_in_air, framebuffer->stab_in_air_b);
	sfSound_setBuffer(framebuffer->stab_inside, framebuffer->stab_inside_b);
	sfMusic_setLoop(framebuffer->main_music, sfTrue);
	sfMusic_setVolume(framebuffer->main_music, 18.0);
	framebuffer->explosion = sfSound_create();
	E_B = sfSoundBuffer_createFromFile("ressources/explosion.ogg");
	sfSound_setBuffer(framebuffer->explosion, framebuffer->explosion_b);
}

void	init_gm_win(BUFF)
{
	sfVector2f pos;

	G_O_M = sfMusic_createFromFile("ressources/game_over.ogg");
	framebuffer->win_music = sfMusic_createFromFile("ressources/win.ogg");
	framebuffer->game_over = sfText_create();
	framebuffer->win = sfText_create();
	sfText_setFont(framebuffer->game_over, framebuffer->menu_font);
	sfText_setFont(framebuffer->win, framebuffer->menu_font);
	sfText_setString(framebuffer->game_over, "Game Over");
	sfText_setCharacterSize(framebuffer->game_over, 100);
	sfText_setString(framebuffer->win, "You win");
	sfText_setCharacterSize(framebuffer->win, 100);
	pos.x = S_WIDTH / 2 - 250;
	pos.y = S_HEIGHT / 2 - 100;
	sfText_setPosition(framebuffer->game_over, pos);
		pos.x = S_WIDTH / 2 - 180;
	pos.y = S_HEIGHT / 2 - 100;
	sfText_setPosition(framebuffer->win, pos);
}
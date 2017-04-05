/*
** main.c for wolf3d in /home/Rev/wolf3d
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Fri Dec	23 14:30:08 2016 Roméo Nahon
** Last update	Fri Dec	23 14:30:08 2016 Roméo Nahon
*/

#include "include/my.h"

int	create_pixel_buffer(t_my_framebuffer *framebuffer)
{
	int	i;

	framebuffer->width = S_WIDTH;
	framebuffer->height = S_HEIGHT;
	PIXELS = malloc(FW * FH * 4 * sizeof(PIXELS));
	i = 0;
	if (PIXELS == NULL)
		return (84);
	while (i < framebuffer->width * framebuffer->height * 4)
	{
		PIXELS[i] = 0;
		i += 1;
	}
}
int	init_start(BUFF, t_player *player, char *buffer)
{
	R_DIR_X = -1;
	R_DIR_Y = 0;
	R_PLAN_X = 0;
	R_PLAN_Y = 0.66;
	find_dimension(buffer, framebuffer);
	find_position(buffer, player);
	framebuffer->count = 0;
	framebuffer->enemy = 0;
	framebuffer->raycast->pos_y = (float)player->x + 0.8;
	framebuffer->raycast->pos_x = (float)player->y - 0.5;
	framebuffer->map_ray = minimap_ray(framebuffer);
	framebuffer->count = 1;
	framebuffer->shot = 0;
	framebuffer->weapon = 0;
	framebuffer->touch = 0;
	framebuffer->select_menu = 0;
	framebuffer->start = 0;
	framebuffer->select_option = 0;
	framebuffer->start_music = 0;
	framebuffer->start_game = 0;
	framebuffer->count_time = TIME;
	framebuffer->timer = 0.0;
	SPEED = 0.15;
	ROTSPEED = 0.1;
}

void	free_all(BUFF)
{
	free_all_next(framebuffer);
	sfTexture_destroy(framebuffer->gun_fire_t);
	sfTexture_destroy(framebuffer->gun_after_fire_t);
	sfTexture_destroy(framebuffer->gun_t);
	sfTexture_destroy(framebuffer->main_menu_t);
	sfTexture_destroy(framebuffer->help_menu_t);
	sfText_destroy(framebuffer->menu_play);
	sfText_destroy(framebuffer->menu_quit);
	sfText_destroy(framebuffer->menu_help);
	sfText_destroy(framebuffer->play2_text);
	sfText_destroy(framebuffer->game_over);
	sfText_destroy(framebuffer->win);
	sfText_destroy(framebuffer->play_speetch);
	sfFont_destroy(framebuffer->menu_font);
	sfRenderWindow_destroy(framebuffer->window);
	free(framebuffer);
	free(framebuffer->raycast);
	free(framebuffer->coord);
}

void	free_all_next(BUFF)
{
	sfMusic_destroy(framebuffer->main_music);
	sfMusic_destroy(framebuffer->menu_music);
	sfMusic_destroy(framebuffer->game_over_music);
	sfMusic_destroy(framebuffer->win_music);
	sfMusic_destroy(framebuffer->snake_voice);
	sfSound_destroy(framebuffer->walk_sound);
	sfSound_destroy(framebuffer->run_sound);
	sfSound_destroy(framebuffer->shot_gun_sound);
	sfSound_destroy(framebuffer->stab_inside);
	sfSound_destroy(framebuffer->stab_in_air);
	sfSound_destroy(framebuffer->explosion);
	sfSoundBuffer_destroy(framebuffer->shot_gun_sound_b);
	sfSoundBuffer_destroy(framebuffer->walk_sound_b);
	sfSoundBuffer_destroy(framebuffer->run_sound_b);
	sfSoundBuffer_destroy(framebuffer->stab_inside_b);
	sfSoundBuffer_destroy(framebuffer->stab_in_air_b);
	sfSoundBuffer_destroy(framebuffer->explosion_b);
	sfSprite_destroy(framebuffer->gun_fire);
	sfSprite_destroy(framebuffer->gun);
	sfSprite_destroy(framebuffer->gun_after_fire);
	sfSprite_destroy(framebuffer->stab_knife);
	sfSprite_destroy(framebuffer->main_menu);
	sfSprite_destroy(framebuffer->help_menu);
}
int			main(int ac, char **av)
{
	int			fd;
	char			*buffer;
	t_my_framebuffer	*framebuffer;
	t_player		*player;

	if (ac > 1)
	{
		my_printf("trop d'argument\n");
		return (84);
	}
	if ((framebuffer = malloc(sizeof(t_my_framebuffer))) == NULL)
		return (84);
	if ((player = malloc(sizeof(t_player))) == NULL)
		return (84);
	if ((framebuffer->raycast = malloc(sizeof(t_raycast))) == NULL)
		return (84);
	if ((framebuffer->coord = malloc(sizeof(t_coord))) == NULL)
		return (84);
	if ((buffer = malloc(sizeof(char) * 1000)) == NULL)
		return (84);
	if ((fd = open("map2", O_RDONLY)) == -1)
	{
		my_printf("problème dans le chargement de la map\n");
		return (84);		
	}
	read(fd, buffer, 1000);
	MAP = buffer;
	init_start(framebuffer, player, buffer);
	init(framebuffer);
	loop(framebuffer);
	close(fd);
}

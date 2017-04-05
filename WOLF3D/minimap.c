/*
** minimap.c for wolf3d in /home/Rev/wolf3d
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Fri Dec	23 14:29:38 2016 Roméo Nahon
** Last update	Fri Dec	23 14:29:38 2016 Roméo Nahon
*/

#include "include/my.h"

int		minimap(BUFF)
{
	t_minimap map;

	map.i = -1;
	map.x = SQUARE;
	map.y = SQUARE;
	map.begin = SQUARE;
	map.j = 0;
	map.r = -1;
	while (framebuffer->map_ray[++map.i])
	{
		while (++map.r < framebuffer->coord->x)
		{
			if (framebuffer->map_ray[map.j][map.r] == 1)
				draw_square(framebuffer, sfRed, map.x, map.y);
			else if (framebuffer->map_ray[map.j][map.r] == 0)
				draw_square(framebuffer, orange_color(), map.x, map.y);
			else if (framebuffer->map_ray[map.j][map.r] == 2)
				draw_square(framebuffer, sfBlue, map.x, map.y);
			map.x += SQUARE;
		}
		map.x = map.begin;
		map.y += SQUARE;
		map.j += 1;
		map.r = -1;
	}
}

int	find_position(char *buffer, t_player *player)
{
	int	i;

	i = -1;
	player->x = 0;
	player->y = 0;
	while (buffer[++i] != '0')
	{
		if (buffer[i] == '1' || buffer[i] == '2')
			player->x += 1;
		else if (buffer[i] == '\n')
		{
			player->y += 1;
			player->x = 0;
		}
	}
	player->x += 1;
	player->y += 1;
}

int	find_dimension(char *buffer, BUFF)
{
	int	i;

	i = -1;
	framebuffer->coord->x = 0;
	framebuffer->coord->y = 0;
	while (buffer[++i] != '\0')
	{
		if (buffer[i] == '1' || buffer[i] == '0' || buffer[i] == '2')
			framebuffer->coord->x += 1;
		else if (buffer[i] == '\n')
			framebuffer->coord->y += 1;
	}
	framebuffer->coord->x = framebuffer->coord->x / (framebuffer->coord->y + 1);
}

int		**minimap_ray(BUFF)
{
	t_ray *mini;

	if ((mini = malloc(sizeof(t_ray))) == NULL)
		return (NULL);
	if ((mini->map_r = malloc(sizeof(int*) *
		(framebuffer->coord->y + 300))) == NULL)
		return (NULL);
	mini->i = -1;
	mini->x = 0;
	mini->y = 0;
	while (MAP[++mini->i] != '\0')
	{
		mini->map_r[mini->y] = malloc(sizeof(int) * (framebuffer->coord->x + 300));
		while (MAP[mini->i] == '1' || MAP[mini->i] == '0' || MAP[mini->i] == '2')
		{
			minimap_ray_next(framebuffer, mini);
			mini->x += 1;
			mini->i += 1;
		}
		mini->y += 1;
		mini->x = 0;
	}
	return (mini->map_r);
}

void	minimap_ray_next(BUFF, t_ray *mini)
{
	if (MAP[mini->i] == '1')
		mini->map_r[mini->y][mini->x] = 1;
	else if (MAP[mini->i] == '0')
		mini->map_r[mini->y][mini->x] = 0;
	else if (MAP[mini->i] == '2')
	{
		if (framebuffer->count == 0)
			framebuffer->enemy += 1;
		mini->map_r[mini->y][mini->x] = 2;
	}
}
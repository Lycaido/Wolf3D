/*
** init_object.c for wolf3dbonus in /home/Rev/wolf3dbonus
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Sat Jan	7 13:46:37 2017 Roméo Nahon
** Last update	Sat Jan	7 13:46:37 2017 Roméo Nahon
*/

#include "include/my.h"

void	init_gun(BUFF)
{
	sfVector2f	scale_gun;
	sfVector2f	gun_pos;

	scale_gun.x = 6.2;
	scale_gun.y = 6.2;
	framebuffer->gun = sfSprite_create();
	G_T = sfTexture_createFromFile("ressources/wolfgun.png", NULL);
	sfSprite_setTexture(framebuffer->gun, framebuffer->gun_t, sfTrue);
	sfSprite_setScale(framebuffer->gun, scale_gun);
	framebuffer->gun_fire = sfSprite_create();
	 G_F_T = sfTexture_createFromFile("ressources/gunfire.png", NULL);
	sfSprite_setTexture(framebuffer->gun_fire, G_F_T, sfTrue);
	sfSprite_setScale(framebuffer->gun_fire, scale_gun);
	framebuffer->gun_after_fire = sfSprite_create();
	G_A_F_T = sfTexture_createFromFile("ressources/gunafterfire.png", NULL);
	sfSprite_setTexture(framebuffer->gun_after_fire, G_A_F_T, sfTrue);
	sfSprite_setScale(framebuffer->gun_after_fire, scale_gun);
	gun_pos.x = -400;
	gun_pos.y = 0;
	sfSprite_setPosition(framebuffer->gun_fire, gun_pos);
	gun_pos.x = -800;
	gun_pos.y = 0;
	sfSprite_setPosition(framebuffer->gun_after_fire, gun_pos);
}

void	init_knife(BUFF)
{
	sfVector2f	scale_knife;
	sfVector2f	knife_pos;

	scale_knife.x = 7.2;
	scale_knife.y = 7.2;
	framebuffer->knife = sfSprite_create();
	framebuffer->knife_t = sfTexture_createFromFile("ressources/knife.png", NULL);
	framebuffer->stab_knife = sfSprite_create();
	S_K_T = sfTexture_createFromFile("ressources/knife_stab.png", NULL);
	sfSprite_setTexture(framebuffer->stab_knife, S_K_T, sfTrue);
	sfSprite_setTexture(framebuffer->knife, framebuffer->knife_t, sfTrue);
	sfSprite_setScale(framebuffer->knife, scale_knife);
	knife_pos.x = -550;
	knife_pos.y = 345;
	sfSprite_setPosition(framebuffer->knife, knife_pos);
	scale_knife.x = 7.2;
	scale_knife.y = 7.2;
	sfSprite_setScale(framebuffer->stab_knife, scale_knife);
	knife_pos.x = -1050;
	knife_pos.y = 345;
	sfSprite_setPosition(framebuffer->stab_knife, knife_pos);
}

void	init_snake(BUFF)
{
	sfVector2f pos;

	S_V = sfMusic_createFromFile("ressources/snake_voice.ogg");
	framebuffer->snake1 = sfSprite_create();
	framebuffer->snake2 = sfSprite_create();
	framebuffer->history = sfSprite_create();
	H_T = sfTexture_createFromFile("ressources/history.png", NULL);
	S1_T = sfTexture_createFromFile("ressources/snake1.png", NULL);
	S2_T = sfTexture_createFromFile("ressources/snake2.png", NULL);
	sfSprite_setTexture(framebuffer->snake1, framebuffer->snake1_t, sfTrue);
	sfSprite_setTexture(framebuffer->snake2, framebuffer->snake2_t, sfTrue);
	sfSprite_setTexture(framebuffer->history, framebuffer->history_t, sfTrue);
	pos.x = S_WIDTH / 2 - 90;
	pos.y = 0;
	sfSprite_setPosition(framebuffer->snake1, pos);
	pos.x = S_WIDTH / 2 - 90;
	pos.y = -3;
	sfSprite_setPosition(framebuffer->snake2, pos);

}
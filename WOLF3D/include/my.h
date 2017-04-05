/*
** my.h for wolf3d in /home/Rev/wolf3d/include
**
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
**
** Started on	Sat Dec	24 16:07:16 2016 Roméo Nahon
** Last update	Sat Dec	24 16:07:16 2016 Roméo Nahon
*/

#ifndef MY_H
# define MY_H

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#define BUFF 		t_my_framebuffer *framebuffer
#define S_WIDTH 	1200
#define S_HEIGHT 	800
#define SIZE 		15
#define SQUARE 		10
#define FM 			framebuffer->mode
#define FMV 		framebuffer->window
#define FT			framebuffer->texture
#define FP 			framebuffer->pixels
#define FW 			framebuffer->width
#define FH 			framebuffer->height
#define FEKC		framebuffer->event.key.code
#define PIXELS 		framebuffer->pixels
#define MAP         framebuffer->map

#define R_POS_X	framebuffer->raycast->pos_y
#define R_POS_Y framebuffer->raycast->pos_x
#define R_DIR_X framebuffer->raycast->vect_dir_y
#define R_DIR_Y framebuffer->raycast->vect_dir_x
#define R_PLAN_X framebuffer->raycast->vect_plan_y
#define R_PLAN_Y framebuffer->raycast->vect_plan_x
#define R_CAM_X framebuffer->raycast->cam_x
#define R_RAY_X framebuffer->raycast->pos_ray_y
#define R_RAY_Y framebuffer->raycast->pos_ray_x
#define R_RAYD_X framebuffer->raycast->ray_dir_y
#define R_RAYD_Y framebuffer->raycast->ray_dir_x
#define R_CAMMAP_X framebuffer->raycast->cam_map_y
#define R_CAMMAP_Y framebuffer->raycast->cam_map_x
#define R_DISTSIDE_X framebuffer->raycast->dist_side_y
#define R_DISTSIDE_Y framebuffer->raycast->dist_side_x
#define R_INTERDIST_X framebuffer->raycast->inter_dist_y
#define R_INTERDIST_Y framebuffer->raycast->inter_dist_x
#define R_STEPD_X framebuffer->raycast->step_dir_y
#define R_STEPD_Y framebuffer->raycast->step_dir_x
#define R_SIDE framebuffer->raycast->side
#define R_GOODW framebuffer->raycast->good_wall_dist
#define R_SDRAW framebuffer->raycast->start_draw
#define R_EDRAW framebuffer->raycast->end_draw
#define R_X framebuffer->raycast->x
#define R_Y framebuffer->raycast->y
#define R_TOUCHW framebuffer->raycast->touch_wall
#define R_HEIGHTW framebuffer->raycast->height_wall
#define OLD_P_X framebuffer->raycast->old_plan_x
#define OLD_D_X framebuffer->raycast->old_dir_x
#define SPEED framebuffer->raycast->speed
#define ROTSPEED framebuffer->raycast->rotspeed
#define COLOR_P sfCyan

#define G_O_M framebuffer->game_over_music
#define MAP_R framebuffer->map_ray
#define G_A_F_T framebuffer->gun_after_fire_t 
#define G_F_T framebuffer->gun_fire_t
#define G_T framebuffer->gun_t
#define S_K_T framebuffer->stab_knife_t
#define S_V framebuffer->snake_voice
#define H_T framebuffer->history_t
#define S1_T framebuffer->snake1_t
#define S2_T framebuffer->snake2_t
#define M_M_T framebuffer->main_menu_t
#define M_F framebuffer->menu_font
#define M_M framebuffer->menu_music
#define H_M_T framebuffer->help_menu_t
#define MAIN_M framebuffer->main_music
#define W_S_B framebuffer->walk_sound_b
#define S_G_S_B framebuffer->shot_gun_sound_b
#define R_S_B framebuffer->run_sound_b
#define S_I_A_B framebuffer->stab_in_air_b
#define S_I_B framebuffer->stab_inside_b
#define SKY_Y S_HEIGHT - R_Y - 1
#define TIME 40
#define	S_O framebuffer->select_option
#define S_M framebuffer->select_menu
#define T_T framebuffer->time_text
#define C_T framebuffer->count_time
#define E_B framebuffer->explosion_b

void 	my_printf(char *str, ...);
int 	my_getnbr(char *str);
int 	count_column(int **nb);
int 	count_line(int **nb);
int 	my_strlen(char *str);
char    *intoarg(int, int);
char    *my_itoa(int, char*);

typedef struct 		s_line
{
	int 			dx;
	int 			dy;
	int 			xinc;
	int 			yinc;
	int 			i;
	int 			cumul;
	int 			x;
	int 			y;
} 					t_line;

typedef struct s_ray
{
	int	i;
	int	x;
	int y;
	int **map_r;
}				t_ray;
typedef struct s_player
{
	int	x;
	int	y;
}				t_player;

typedef struct s_raycast
{
	double pos_x;
	double pos_y;
	double cam_x;
	double vect_dir_x;
	double vect_dir_y;
	double vect_plan_x;
	double vect_plan_y;
	double pos_ray_x;
	double pos_ray_y;
	double ray_dir_x;
	double ray_dir_y;
	int cam_map_x;
	int cam_map_y;
	double dist_side_y;
	double dist_side_x;
	double inter_dist_x;
	double inter_dist_y;
	int step_dir_x;
	int step_dir_y;
	int side;
	double good_wall_dist;
	int start_draw;
	int end_draw;
	int	x;
	int y;
	int touch_wall;
	int height_wall;
	double old_plan_x;
	double old_dir_x;
	float speed;
	float rotspeed;
}			t_raycast;

typedef struct s_coord
{
	int x;
	int y;
}			t_coord;

typedef struct s_minimap
{
	int	i;
	int	j;
	int	r;
	int	x;
	int y;
	int begin;
}				t_minimap;

typedef struct 		s_my_framebuffer
{
	sfRenderWindow* window;
	sfWindow 		*wind;		
	sfVideoMode     mode;
	sfTexture* 		texture;
	sfTexture*		gun_t;
	sfTexture*		gun_fire_t;
	sfTexture*		gun_after_fire_t;
	sfTexture*		knife_t;
	sfTexture*		stab_knife_t;
	sfTexture*		main_menu_t;
	sfTexture*		help_menu_t;
	sfTexture*		history_t;
	sfTexture*		arrow_key_t;
	sfTexture*		q_key_t;
	sfTexture*		shift_key_t;
	sfTexture*		snake1_t;
	sfTexture*		snake2_t;
	sfSprite* 		sprite;
	sfSprite*		gun;
	sfSprite*		gun_fire;
	sfSprite*		gun_after_fire;
	sfSprite*		knife;
	sfSprite*		stab_knife;
	sfSprite*		main_menu;
	sfSprite*		help_menu;
	sfSprite*		history;
	sfSprite*		snake1;
	sfSprite*		snake2;
	sfFont*			menu_font;
	sfText*			game_over;
	sfText*			play_speetch;
	sfText*			win;
	sfText*			menu_play;
	sfText*			menu_quit;
	sfText*			menu_help;
	sfText*			play2_text;
	sfText*			time_text;
	sfMusic*		shoot_gun;
	sfMusic*		snake_voice;
	sfMusic*		main_music;
	sfMusic*		game_over_music;
	sfMusic*		win_music;
	sfMusic*		menu_music;
	sfSound			*walk_sound;
	sfSoundBuffer 	*walk_sound_b;
	sfSound			*shot_gun_sound;
	sfSoundBuffer 	*shot_gun_sound_b;
	sfSound			*run_sound;
	sfSoundBuffer	*run_sound_b;
	sfSound			*stab_in_air;
	sfSoundBuffer   *stab_in_air_b;
	sfSound			*stab_inside;
	sfSoundBuffer	*stab_inside_b;
	sfSound         *explosion;
	sfSoundBuffer	*explosion_b;
	sfUint8* 		pixels;
	sfEvent  		event;
	t_player		*player;
	t_raycast		*raycast;
	t_coord			*coord;
	sfVector2i		from;
	sfVector2i		to;
	int 			opaque;
	int 			grey;
	int 			greyplus;
	int 			music_play1;
	int 			music_play2;
	char			*map;
	int				**map_ray;
	int 			width;
	int 			height;
	int				shot;
	int 			weapon;
	int 			stab;
	int				touch;
	int 			select_menu;
	int 			start;
	int 			select_option;
	float			timer;
	int 			enemy;
	int 			count;
	int 			start_music;
	int 			start_game;
	int 			count_time;
} 					t_my_framebuffer;

void	init_menu_next(BUFF);

void	check_key(BUFF);
void	shot_key(BUFF);
void	switch_weapon(BUFF);
void	movement(BUFF);

void	display(t_my_framebuffer *);
void	display_all(BUFF);
void	display_fov(BUFF);
void	disp_loose(BUFF);
void	disp_win(BUFF);

void	event(BUFF, int start);
void	loop(t_my_framebuffer *);
void	event_in_event(BUFF);
int		speetch_start(BUFF, int start, int voice);
int		game_start(BUFF, int start);

sfColor	orange_color();
sfColor	grey_color(BUFF);
sfColor	white_color(BUFF);
sfColor	brown_color(BUFF);
sfColor	greyplus_color(BUFF);

sfColor	red_color(BUFF);
void	shadow(BUFF);
void	color_wall(BUFF);
void	color_floor_cell(BUFF);

int		draw_square(BUFF, sfColor color, int , int);
void	draw_crossfire(BUFF);

void	init_gun(BUFF);
void	init_knife(BUFF);
void	init_snake(BUFF);

int		init(t_my_framebuffer *);
void	init_menu(BUFF);
void	init_time(BUFF);
void	init_gm_win(BUFF);
void	init_help(BUFF);
void	init_music(BUFF);

int		create_pixel_buffer(t_my_framebuffer *);
int		init_start(BUFF, t_player *player, char *buffer);
void 	free_all(BUFF);
void	free_all_next(BUFF);

void	create_menu(BUFF);
void	create_help_menu(BUFF);
void	display_option(BUFF);

int		minimap(BUFF);
int		find_position(char *buffer, t_player *player);
int		find_dimension(char *buffer, BUFF);
int 	**minimap_ray(BUFF);
void	minimap_ray_next(BUFF, t_ray *mini);

void	move_left(BUFF);
void	move_right(BUFF);
void	move_down(BUFF);
void	move_up(BUFF);

int		draw_player(BUFF, sfColor color, int x, int y);

void	check_raycast_dist(BUFF);
void	find_raycast_intersection(BUFF);
void	correct_visual(BUFF);
void	limit_draw(BUFF);
void	draw_wall(BUFF);

void	init_raycast_value(BUFF);
void	shoot_enemy(BUFF);
void	raycast(BUFF);

void	shoot_animation(BUFF);
void	stab_animation(BUFF);
void	snake_animation(BUFF);

void	line_dx_inf(t_line line, BUFF, sfColor color);
void	line_dx_sup(t_line line, BUFF, sfColor color);
void	my_draw_line(BUFF, sfVector2i from, sfVector2i to, sfColor color);

void	my_put_pixel(BUFF, int x, int y, sfColor color);
#endif /* MY_H */
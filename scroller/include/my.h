/*
** my.h for scroller in /home/Rev/scroller/include
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Fri Mar	31 21:17:05 2017 Roméo Nahon
** Last update	Fri Mar	31 21:17:05 2017 Roméo Nahon
*/


#ifndef MY_H
# define MY_H

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#define S_WIDTH 	1920
#define S_HEIGHT 	1080

#define OBJECT scroller->object
#define OBJECT_C scroller->object->comete
#define OBJECT_A scroller->object->asteroide
#define OBJECT_P scroller->object->player

#define INIT scroller->init
#define SPHERE scroller->sphere

#define VECT(x) dir_vector.x
#define STARS_SPW 1920
#define STARS_RAN 1070
#define STARS_END -200
#define PATH_1 "Ressources/sprite/asteroid1.png"
#define PATH_2 "Ressources/sprite/Lagaf.png"
#define PATH_3 "Ressources/sprite/proust.png"

/*lib*/
int	my_printf(char *str, ...);
char	*get_next_line(int);
char	*intoarg(int, int);
int	my_intlen(int);

typedef	struct s_shoot
{
  sfSprite*	shoot;
  sfTexture	*shoot_t;
  sfVector2f	shoot_pos;
  sfIntRect	*hitbox;
  int		id;
}		t_shoot;

typedef struct s_player
{
  sfVector2f	p_pos;
  sfVector2f	p_pos_shoot;

  sfSprite	*player;

  t_shoot      **shoot;

  sfImage	*player_image;
  sfImage	*shoot_image;

  sfTexture	*player_t;

  sfIntRect	*rect_player;
  sfIntRect	*rect_shoot;
  sfIntRect	*hitbox;

  int		texture;
  int		lock;
  int		lock_2;
  float		angle;
}		t_player;

typedef struct s_ast_mob
{
  sfSprite*	ast;
  sfVector2f	pos_ast;
  sfIntRect	*hitbox;
  int		speed;
}		t_ast_mob;

typedef	struct  s_asteroide
{
  int		random;
  int		i;

  t_ast_mob	**ast_mob;
  sfImage	*ast_image;
  sfTexture	*ast_t;
  sfIntRect	*rect;
}		t_asteroide;

typedef	struct s_comete
{
  int			i;
  float			angle_com;
  sfVector2f		pos_com;
  sfVector2f		pos_com_2;

  sfSprite*		com_1;
  sfSprite*		com_2;
  sfTexture*		com_t_1;
  sfTexture*		com_t_2;
  sfTexture*		com_t_3;
  sfTexture*		com_t_4;
  sfTexture*		com_t_5;
  sfTexture*		com_t_6;
  sfTexture*		com_t_7;

}				t_comete;

typedef struct s_object
{

  t_comete 		*comete;
  t_asteroide		*asteroide;
  t_player		*player;
  sfSprite*		background;
  sfTexture*		background_t;
  sfVector2f		pos_bg;
  sfSprite*		background_2;
  sfTexture*		background_t_2;
  sfVector2f		pos_bg_2;
  sfSprite*		background_3;
  sfTexture*		background_t_3;
  sfVector2f		pos_bg_3;

  sfSprite*		planete_1;
  sfTexture*		planete_t_1;
  sfVector2f		pos_plan_1;

  sfSprite*		planete_2;
  sfTexture*		planete_t_2;
  sfVector2f		pos_plan_2;
  sfVector2f		scale_plan_2;
  int				i;

  sfSprite*		galaxy;
  sfTexture*		galaxy_t;
  sfVector2f		pos_gala;
  float 		angle;
  sfVector2f		scale_gala;
  sfVector2f		ori_gala;

  sfSprite*		stars_1;
  sfTexture*		stars_t_1;
  sfVector2f		stars_pos_1;
  int				s1;

  sfSprite*		stars_2;
  sfTexture*		stars_t_2;
  sfVector2f		stars_pos_2;
  int				s2;

  sfSprite*		stars_3;
  sfTexture*		stars_t_3;
  sfVector2f		stars_pos_3;
  int				s3;

  sfSprite*		stars_4;
  sfTexture*		stars_t_4;
  sfVector2f		stars_pos_4;
  int				s4;

  sfSprite*		stars_5;
  sfTexture*		stars_t_5;
  sfVector2f		stars_pos_5;
  int				s5;

  sfSprite*		stars_6;
  sfTexture*		stars_t_6;
  sfVector2f		stars_pos_6;
  int				s6;

  sfSprite*		stars_7;
  sfTexture*		stars_t_7;
  sfVector2f		stars_pos_7;
  int				s7;

  sfSprite*		stars_8;
  sfTexture*		stars_t_8;
  sfVector2f		stars_pos_8;
  int				s8;

  sfSprite*		stars_9;
  sfTexture*		stars_t_9;
  sfVector2f		stars_pos_9;
  int				s9;

  sfSprite*		stars_10;
  sfTexture*		stars_t_10;
  sfVector2f		stars_pos_10;
  int				s10;

  sfText* 		end_text;
  sfFont	        *font;
  sfVector2f		end_text_pos;
  sfVector2f		end_text_origin;
  float			end_text_angle;
  int				j;

  sfText* 		tracker_text;
  sfVector2f		tracker_text_pos;

  sfSprite*		ast_1;
  sfTexture*		ast_t_1;
  sfVector2f		pos_ast_1;

  sfSprite*		ast_2;
  sfTexture*		ast_t_2;
  sfVector2f		pos_ast_2;

  sfSprite*		ast_3;
  sfTexture*		ast_t_3;
  sfVector2f		pos_ast_3;
  
  sfText* 		score_text;
}				t_object;

typedef struct s_list_tracker
{
  char	*name;
  sfMusic	*music;
  struct s_list_tracker *next;
}			   t_list_tracker;

typedef struct s_control_tracker
{
  t_list_tracker *first;
}			   t_control_tracker;

typedef struct s_init
{
  sfRenderWindow* window;
  sfVideoMode     mode;
  sfEvent	event;
}				t_init;

typedef struct s_sphere
{
  sfUint8	*pixels;
  int		width;
  int		height;
  
  sfSprite*	sphere;
  sfTexture*	sphere_t;
  
  sfVector3f	eye_pos;
  sfVector2i	s_size;
  sfVector2i	pos;
  float		res;
  
  float		light;
}		t_sphere;

typedef struct s_scroller
{
  t_init		*init;
  t_object		*object;
  t_control_tracker 	*list;
  t_sphere		*sphere;
  int			i;
  int			score;
  int			old_score;

  sfSprite *lagaf;
  sfSprite *proust;
  sfTexture *lagaf_t;
  sfTexture *proust_t;
  sfColor   *color_proust;
  sfColor   *color_lagaf;
   int      j;
   int      y;
}		t_scroller;

/*init.c*/
int	init(t_scroller *scroller);
int	init_struct(t_scroller *scroller);

/*loop.c*/
int	loop(t_scroller *scroller);

/*init_next.c*/
int	init_background(t_scroller *scroller);
int	init_planete1(t_scroller *scroller);
int	init_planete2(t_scroller *scroller);
int	init_galaxy(t_scroller *scroller);
int	init_vaisseau1(t_scroller *scroller);

/*init_next_2.c*/
int	init_vaisseau2(t_scroller *scroller);
int	init_vaisseau3(t_scroller *scroller);
int	init_vaisseau4(t_scroller *scroller);
int	init_2d_plan(t_scroller *scroller);
int	init_stars(t_scroller *scroller);

/*draw_object.c*/
void	draw_planete1(t_scroller *scroller);
void	draw_galaxy(t_scroller *scroller);
void	draw_planete2(t_scroller *scroller);
void	draw_stars(t_scroller *scroller);
void	draw_end_text(t_scroller *scroller);

/*stars.c*/
void	draw_stars_1(t_scroller *scroller);
void	draw_stars_2(t_scroller *scroller);
void	draw_stars_3(t_scroller *scroller);
void	draw_stars_4(t_scroller *scroller);
void	draw_stars_5(t_scroller *scroller);

/*stars_next.c*/
void	draw_stars_6(t_scroller *scroller);
void	draw_stars_7(t_scroller *scroller);
void	draw_stars_8(t_scroller *scroller);
void	draw_stars_9(t_scroller *scroller);
void	draw_stars_10(t_scroller *scroller);

/*init_next_3.c*/
void	init_text(t_scroller *scroller);
int	init_sphere(t_scroller *);
sfColor	red_color(t_scroller *scroller);

/*tracker.c*/
int	tracker(t_scroller *, t_list_tracker *, t_list_tracker*);
int	get_list_music(t_scroller *scroller);

/*draw_scene.c*/
void	draw_scene(t_scroller *scroller);
void	draw_sphere(t_scroller *scroller);
void	draw_end(t_scroller *scroller);
void	control_time(t_scroller *, int, clock_t);

/*init_stars.c*/
int	init_stars_1_4(t_scroller *scroller);
int	init_stars_5_8(t_scroller *scroller);

/*sphere.c*/
int	create_pixel_buffer(t_scroller *scroller);
float	intersect_sphere(sfVector3f, sfVector3f, float);

/*calc_dir_vector.c*/
void		my_put_pixel(t_scroller *, int x, int y, sfColor);
sfVector3f	calc_dir_vector(float, sfVector2i, sfVector2i);

/*light.c*/
float	get_light_coef(sfVector3f, sfVector3f);

/*init_comete.c*/
void	init_com(t_scroller *scroller);

/*draw_scene_next.c*/
void	draw_comete(t_scroller *scroller);

/*init_asteroide.c*/
void	anim_asteroide(t_scroller *scroller);
void	init_asteroide(t_scroller *scroller);
void	draw_asteroide(t_scroller *scroller);

/*player.c*/
void	init_player(t_scroller *scroller);
void	draw_player(t_scroller *scroller);
void	draw_shoot(t_scroller *scroller);

/*keyboard.c*/
void	key_down(t_scroller *scroller);
void	key_up(t_scroller *scroller);
void	key_space(t_scroller *scroller);

/*collision.c*/
int	collision_shoot_ast(t_scroller *scroller, int);
int	collision_ast_shoot(t_scroller *scroller, int);
void	move_hitbox_shoot(t_scroller *scroller);
int	collision_player(t_scroller *scroller);

/*init_score.c*/
void	init_score(t_scroller *scroller);
void	draw_score(t_scroller *scroller);

/*opacity.c*/
void   init_opacity(t_scroller *scroller);
void  draw_opacity(t_scroller *scroller);

#endif /* MY_H */

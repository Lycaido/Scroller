/*
** draw_scene.c for scroller in /home/Rev/scroller
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Sun Apr	2 02:49:58 2017 Roméo Nahon
** Last update	Sun Apr	2 02:49:58 2017 Roméo Nahon
*/

#include "include/my.h"

void	draw_scene(t_scroller *scroller)
{
  sfRenderWindow_drawSprite(INIT->window, OBJECT->background_3, NULL);
  OBJECT->pos_bg_3.x -= 1;
  OBJECT->pos_bg.x -= 1;
  if (OBJECT->pos_bg_3.x <= -1900)
    OBJECT->pos_bg_3.x = 1900;
  if (OBJECT->pos_bg.x <= -1900)
    OBJECT->pos_bg.x = 1900;
  sfSprite_setPosition(OBJECT->background, OBJECT->pos_bg);
  sfSprite_setPosition(OBJECT->background_3, OBJECT->pos_bg_3);
  draw_stars(scroller);
  draw_galaxy(scroller);
  draw_planete1(scroller);
  draw_planete2(scroller);
  draw_comete(scroller);
}

void	draw_end(t_scroller *scroller)
{
  OBJECT->pos_bg_2.x -= 10;
  OBJECT->pos_bg.x -= 10;
  if (OBJECT->pos_bg_2.x <= -1900)
    OBJECT->pos_bg_2.x = 1900;
  if (OBJECT->pos_bg.x <= -1900)
    OBJECT->pos_bg.x = 1900;
  sfSprite_setPosition(OBJECT->background, OBJECT->pos_bg);
  sfSprite_setPosition(OBJECT->background_2, OBJECT->pos_bg_2);
  sfRenderWindow_drawSprite(INIT->window, OBJECT->background_2, NULL);
  draw_end_text(scroller);
  draw_opacity(scroller);
}

void	control_time(t_scroller *scroller, int timer, clock_t time_)
{
  int my_time;

  time_ = clock();
  timer = time_ / 100000;
  my_time = 120 - timer;
  if (my_time > 0)
    {
      draw_scene(scroller);
      scroller->i = 1;
    }
  else
    {
      if (scroller->i == 1)
	{
	  OBJECT->pos_bg.x = 0;
	  scroller->i = 0;
	}
      draw_end(scroller);
    }
}

void	draw_sphere(t_scroller *scroller)
{
  sfVector3f light_vector;
  sfVector3f normal_vector;

  light_vector.x = -100;
  light_vector.y = 0;
  SPHERE->pos.y = -1;
  while (++(SPHERE->pos.y) < S_HEIGHT)
    {
      SPHERE->pos.x = -1;
      while (++(SPHERE->pos.x) < S_WIDTH)
	{
	  SPHERE->res =
	    intersect_sphere(SPHERE->eye_pos,
			     calc_dir_vector(-200, SPHERE->s_size, SPHERE->pos), 50.0f);
	  if (SPHERE->res > 0)
	    {
	      normal_vector.x = SPHERE->pos.x - 600;
	      normal_vector.y = SPHERE->pos.y - 100;
	      normal_vector.z = -10;
	      SPHERE->light = get_light_coef(light_vector, normal_vector);
	      my_put_pixel(scroller,
			   SPHERE->pos.x, SPHERE->pos.y, red_color(scroller));
	    }
	}
    }
}

/*
** draw_object.c for scroller in /home/Rev/scroller
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Sat Apr	1 03:42:04 2017 Roméo Nahon
** Last update	Sat Apr	1 03:42:04 2017 Roméo Nahon
*/

#include "include/my.h"

void	draw_galaxy(t_scroller *scroller)
{
  sfSprite_setPosition(OBJECT->galaxy, OBJECT->pos_gala);
  sfRenderWindow_drawSprite(INIT->window, OBJECT->galaxy, NULL);
  OBJECT->pos_gala.x += 0.4;
  if (OBJECT->pos_gala.x  >= 2200)
    {
      OBJECT->pos_gala.x = -950;
      OBJECT->scale_gala.y = 1;
      OBJECT->scale_gala.x = 1;
    }
  OBJECT->angle += 0.02;
  sfSprite_setRotation(OBJECT->galaxy, OBJECT->angle);
}

void	draw_planete1(t_scroller *scroller)
{
  sfSprite_setPosition(OBJECT->planete_1, OBJECT->pos_plan_1);
  sfRenderWindow_drawSprite(INIT->window, OBJECT->planete_1, NULL);
  OBJECT->pos_plan_1.x += 0.2;
  if (OBJECT->pos_plan_1.x >= 1600)
    OBJECT->pos_plan_1.x = -1250;
}

void	draw_planete2(t_scroller *scroller)
{
  sfSprite_setPosition(OBJECT->planete_2, OBJECT->pos_plan_2);
  sfRenderWindow_drawSprite(INIT->window, OBJECT->planete_2, NULL);
  if (OBJECT->scale_plan_2.x <= 0.00)
    OBJECT->i = 1;
  else if (OBJECT->scale_plan_2.x >= 1.2) OBJECT->i = 0;
  if (OBJECT->i == 0)
    {
      OBJECT->pos_plan_2.x += 2;
      OBJECT->scale_plan_2.y -= 0.00018;
      OBJECT->scale_plan_2.x -= 0.00018;
    }
  else if (OBJECT->i == 1)
    {
      OBJECT->pos_plan_2.x += 0.5;
      OBJECT->scale_plan_2.y += 0.001;
      OBJECT->scale_plan_2.x += 0.001;
    }
  if (OBJECT->pos_plan_2.x >= 1850)
    {
      OBJECT->scale_plan_2.x = 1;
      OBJECT->scale_plan_2.y = 1;
      OBJECT->pos_plan_2.x = -900;
      OBJECT->pos_plan_2.y = 500;
    }
  sfSprite_setScale(OBJECT->planete_2, OBJECT->scale_plan_2);
}

void	draw_stars(t_scroller *scroller)
{
  draw_stars_1(scroller);
  draw_stars_2(scroller);
  draw_stars_3(scroller);
  draw_stars_4(scroller);
  draw_stars_5(scroller);
  draw_stars_7(scroller);
  draw_stars_8(scroller);
  draw_stars_9(scroller);
  draw_stars_10(scroller);
}

void	draw_end_text(t_scroller *scroller)
{
  sfRenderWindow_drawText(INIT->window, OBJECT->end_text, NULL);
  if (OBJECT->end_text_pos.y <= 200)
    OBJECT->j = 1;
  else if (OBJECT->end_text_pos.y >= 800)
    OBJECT->j = 0;
  if (OBJECT->j == 1)
    {
      OBJECT->end_text_pos.x += 3;
      OBJECT->end_text_pos.y += 2;
    }
  else if (OBJECT->j == 0)
    {
      OBJECT->end_text_pos.x += 3;
      OBJECT->end_text_pos.y -= 2;
    }
  if (OBJECT->end_text_pos.x >= 2200)
    {
      OBJECT->end_text_pos.x = -700;
      OBJECT->end_text_pos.y = 500;
    }
  sfText_setPosition (OBJECT->end_text, OBJECT->end_text_pos);
  OBJECT->end_text_angle = OBJECT->end_text_angle + 1;
  sfText_setRotation(OBJECT->end_text, OBJECT->end_text_angle);
}

/*
** stars.c for scroller in /home/Rev/scroller
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Sat Apr	1 05:58:38 2017 Roméo Nahon
** Last update	Sat Apr	1 05:58:38 2017 Roméo Nahon
*/

#include "include/my.h"

void	draw_stars_1(t_scroller *scroller)
{
  sfRenderWindow_drawSprite(INIT->window, OBJECT->stars_1, NULL);
  if (OBJECT->s1 == 0)
    {
      OBJECT->stars_pos_1.y = rand() % STARS_RAN;
      OBJECT->stars_pos_1.x = STARS_SPW;
      OBJECT->s1 = 1;
    }
  if (OBJECT->stars_pos_1.x <= STARS_END)
    {
      OBJECT->stars_pos_1.y = rand() % STARS_RAN;
      OBJECT->s1 = 0;
    }
  OBJECT->stars_pos_1.x -= 30;
  sfSprite_setPosition(OBJECT->stars_1, OBJECT->stars_pos_1);
}

void	draw_stars_2(t_scroller *scroller)
{
  sfRenderWindow_drawSprite(INIT->window, OBJECT->stars_2, NULL);
  if (OBJECT->s2 == 0)
    {
      OBJECT->stars_pos_2.y = rand() % STARS_RAN;
      OBJECT->stars_pos_2.x = STARS_SPW;
      OBJECT->s2 = 1;
    }
  if (OBJECT->stars_pos_2.x <= STARS_END)
    {
      OBJECT->stars_pos_2.y = rand() % STARS_RAN;
      OBJECT->s2 = 0;
    }
  OBJECT->stars_pos_2.x -= 50;
  sfSprite_setPosition(OBJECT->stars_2, OBJECT->stars_pos_2);
}

void	draw_stars_3(t_scroller *scroller)
{
  sfRenderWindow_drawSprite(INIT->window, OBJECT->stars_3, NULL);
  if (OBJECT->s3 == 0)
    {
      OBJECT->stars_pos_3.y = rand() % STARS_RAN;
      OBJECT->stars_pos_3.x = STARS_SPW;
      OBJECT->s3 = 1;
    }
  if (OBJECT->stars_pos_3.x <= STARS_END)
    {
      OBJECT->stars_pos_3.y = rand() % STARS_RAN;
      OBJECT->s3 = 0;
    }
  OBJECT->stars_pos_3.x -= 15;
  sfSprite_setPosition(OBJECT->stars_3, OBJECT->stars_pos_3);
}

void	draw_stars_4(t_scroller *scroller)
{
  sfRenderWindow_drawSprite(INIT->window, OBJECT->stars_4, NULL);
  if (OBJECT->s4 == 0)
    {
      OBJECT->stars_pos_4.y = rand() % STARS_RAN;
      OBJECT->stars_pos_4.x = STARS_SPW;
      OBJECT->s4 = 1;
    }
  if (OBJECT->stars_pos_4.x <= STARS_END)
    {
      OBJECT->stars_pos_4.y = rand() % STARS_RAN;
      OBJECT->s4 = 0;
    }
  OBJECT->stars_pos_4.x -= 18;
  sfSprite_setPosition(OBJECT->stars_4, OBJECT->stars_pos_4);
}

void	draw_stars_5(t_scroller *scroller)
{
  sfRenderWindow_drawSprite(INIT->window, OBJECT->stars_5, NULL);
  if (OBJECT->s5 == 0)
    {
      OBJECT->stars_pos_5.y = rand() % STARS_RAN;
      OBJECT->stars_pos_5.x = STARS_SPW;
      OBJECT->s5 = 1;
    }
  if (OBJECT->stars_pos_5.x <= STARS_END)
    {
      OBJECT->stars_pos_5.y = rand() % STARS_RAN;
      OBJECT->s5 = 0;
    }
  OBJECT->stars_pos_5.x -= 27;
  sfSprite_setPosition(OBJECT->stars_5, OBJECT->stars_pos_5);
}

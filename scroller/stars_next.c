/*
** stars_next.c for scroller in /home/Rev/scroller
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Sat Apr	1 06:01:43 2017 Roméo Nahon
** Last update	Sat Apr	1 06:01:43 2017 Roméo Nahon
*/

#include "include/my.h"

void	draw_stars_6(t_scroller *scroller)
{
  sfRenderWindow_drawSprite(INIT->window, OBJECT->stars_6, NULL);
  if (OBJECT->s6 == 0)
    {
      OBJECT->stars_pos_6.y = rand() % STARS_RAN;
      OBJECT->stars_pos_6.x = STARS_SPW;
      OBJECT->s6 = 1;
    }
  if (OBJECT->stars_pos_6.x <= STARS_END)
    {
      OBJECT->stars_pos_6.y = rand() % STARS_RAN;
      OBJECT->s6 = 0;
    }
  OBJECT->stars_pos_6.x -= 35;
  sfSprite_setPosition(OBJECT->stars_6, OBJECT->stars_pos_6);
}

void	draw_stars_7(t_scroller *scroller)
{
  sfRenderWindow_drawSprite(INIT->window, OBJECT->stars_7, NULL);
  if (OBJECT->s7 == 0)
    {
      OBJECT->stars_pos_7.y = rand() % STARS_RAN;
      OBJECT->stars_pos_7.x = STARS_SPW;
      OBJECT->s7 = 1;
    }
  if (OBJECT->stars_pos_7.x <= STARS_END)
    {
      OBJECT->stars_pos_7.y = rand() % STARS_RAN;
      OBJECT->s7 = 0;
    }
  OBJECT->stars_pos_7.x -= 22;
  sfSprite_setPosition(OBJECT->stars_7, OBJECT->stars_pos_7);
}

void	draw_stars_8(t_scroller *scroller)
{
  sfRenderWindow_drawSprite(INIT->window, OBJECT->stars_8, NULL);
  if (OBJECT->s8 == 0)
    {
      OBJECT->stars_pos_8.y = rand() % STARS_RAN;
      OBJECT->stars_pos_8.x = STARS_SPW;
      OBJECT->s8 = 1;
    }
  if (OBJECT->stars_pos_8.x <= STARS_END)
    {
      OBJECT->stars_pos_8.y = rand() % STARS_RAN;
      OBJECT->s8 = 0;
    }
  OBJECT->stars_pos_8.x -= 25;
  sfSprite_setPosition(OBJECT->stars_8, OBJECT->stars_pos_8);
}

void	draw_stars_9(t_scroller *scroller)
{
  sfRenderWindow_drawSprite(INIT->window, OBJECT->stars_9, NULL);
  if (OBJECT->s9 == 0)
    {
      OBJECT->stars_pos_9.y = rand() % STARS_RAN;
      OBJECT->stars_pos_9.x = STARS_SPW;
      OBJECT->s9 = 1;
    }
  if (OBJECT->stars_pos_9.x <= STARS_END)
    {
      OBJECT->stars_pos_9.y = rand() % STARS_RAN;
      OBJECT->s9 = 0;
    }
  OBJECT->stars_pos_9.x -= 12;
  sfSprite_setPosition(OBJECT->stars_9, OBJECT->stars_pos_9);
}

void	draw_stars_10(t_scroller *scroller)
{
  sfRenderWindow_drawSprite(INIT->window, OBJECT->stars_10, NULL);
  if (OBJECT->s10 == 0)
    {
      OBJECT->stars_pos_10.y = rand() % STARS_RAN;
      OBJECT->stars_pos_10.x = STARS_SPW;
      OBJECT->s10 = 1;
    }
  if (OBJECT->stars_pos_10.x <= STARS_END)
    {
      OBJECT->stars_pos_10.y = rand() % STARS_RAN;
      OBJECT->s10 = 0;
    }
  OBJECT->stars_pos_10.x -= 89;
  sfSprite_setPosition(OBJECT->stars_10, OBJECT->stars_pos_10);
}

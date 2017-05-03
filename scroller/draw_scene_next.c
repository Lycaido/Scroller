/*
** draw_scene_next.c for scroller in /home/Rev/scroller
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Sun Apr	2 07:37:14 2017 Roméo Nahon
** Last update	Sun Apr	2 07:37:14 2017 Roméo Nahon
*/

#include "include/my.h"

void	draw_comete_1_next(t_scroller *scroller)
{
  if (OBJECT_C->pos_com.y == OBJECT_C->i - 20)
    {
      sfSprite_setTexture(OBJECT_C->com_1, OBJECT_C->com_t_4, sfTrue);
      sfSprite_setTexture(OBJECT_C->com_2, OBJECT_C->com_t_4, sfTrue);
    }
  else if (OBJECT_C->pos_com.y == OBJECT_C->i - 25)
    {
      sfSprite_setTexture(OBJECT_C->com_1, OBJECT_C->com_t_5, sfTrue);
      sfSprite_setTexture(OBJECT_C->com_2, OBJECT_C->com_t_5, sfTrue);
    }
  else if (OBJECT_C->pos_com.y == OBJECT_C->i - 30)
    {
      sfSprite_setTexture(OBJECT_C->com_1, OBJECT_C->com_t_6, sfTrue);
      sfSprite_setTexture(OBJECT_C->com_2, OBJECT_C->com_t_6, sfTrue);
    }
  else if (OBJECT_C->pos_com.y == OBJECT_C->i - 35)
    {
      sfSprite_setTexture(OBJECT_C->com_1, OBJECT_C->com_t_7, sfTrue);
      sfSprite_setTexture(OBJECT_C->com_2, OBJECT_C->com_t_7, sfTrue);
      OBJECT_C->i = OBJECT_C->pos_com.y;
    }
}
void	draw_comete_1(t_scroller *scroller)
{
  if (OBJECT_C->pos_com.y == OBJECT_C->i + 5)
    {
      sfSprite_setTexture(OBJECT_C->com_1, OBJECT_C->com_t_1, sfTrue);
      sfSprite_setTexture(OBJECT_C->com_2, OBJECT_C->com_t_1, sfTrue);
    }
  else if (OBJECT_C->pos_com.y == OBJECT_C->i - 10)
    {
      sfSprite_setTexture(OBJECT_C->com_1, OBJECT_C->com_t_2, sfTrue);
      sfSprite_setTexture(OBJECT_C->com_2, OBJECT_C->com_t_2, sfTrue);
    }
  else if (OBJECT_C->pos_com.y == OBJECT_C->i - 15)
    {
      sfSprite_setTexture(OBJECT_C->com_1, OBJECT_C->com_t_3, sfTrue);
      sfSprite_setTexture(OBJECT_C->com_2, OBJECT_C->com_t_3, sfTrue);
    }
  draw_comete_1_next(scroller);
  sfRenderWindow_drawSprite(INIT->window, OBJECT_C->com_1, NULL);
}
void	draw_comete(t_scroller *scroller)
{
  if (OBJECT_C->pos_com.y <= -100)
    {
      OBJECT_C->pos_com.y = 1100;
      OBJECT_C->pos_com.x = rand() % 1900;
      OBJECT_C->i = OBJECT_C->pos_com.y;
    }
  if (OBJECT_C->pos_com_2.y <= -100)
    {
      OBJECT_C->pos_com_2.y = 1400;
      OBJECT_C->pos_com_2.x = rand() % 1900;
      OBJECT_C->i = OBJECT_C->pos_com.y;
    }
  draw_comete_1(scroller);
  sfRenderWindow_drawSprite(INIT->window, OBJECT_C->com_1, NULL);
  sfRenderWindow_drawSprite(INIT->window, OBJECT_C->com_2, NULL);
  OBJECT_C->pos_com.x += 1;
  OBJECT_C->pos_com.y -= 1;
  OBJECT_C->pos_com_2.x -= 1;
  OBJECT_C->pos_com_2.y -= 1;
  sfSprite_setPosition(OBJECT_C->com_1, OBJECT_C->pos_com);
  sfSprite_setPosition(OBJECT_C->com_2, OBJECT_C->pos_com_2);
}

/*
** init_next_2.c for scroller in /home/Rev/scroller
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Sat Apr	1 03:34:21 2017 Roméo Nahon
** Last update	Sat Apr	1 03:34:21 2017 Roméo Nahon
*/

#include "include/my.h"

int		init_stars(t_scroller *scroller)
{
  init_stars_1_4(scroller);
  init_stars_5_8(scroller);
  OBJECT->stars_9 = sfSprite_create();
  OBJECT->stars_t_9 =
    sfTexture_createFromFile("Ressources/Background/stars.png", NULL);
  if (OBJECT->stars_t_9 == NULL) return (84);
  sfSprite_setTexture(OBJECT->stars_9, OBJECT->stars_t_9, sfTrue);
  OBJECT->s9 = 0;
  OBJECT->stars_10 = sfSprite_create();
  OBJECT->stars_t_10 =
    sfTexture_createFromFile("Ressources/Background/stars.png", NULL);
  if (OBJECT->stars_t_10 == NULL) return (84);
  sfSprite_setTexture(OBJECT->stars_10, OBJECT->stars_t_10, sfTrue);
  OBJECT->s10 = 0;
}

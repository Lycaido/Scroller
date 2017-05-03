/*
** init_stars.c for scroller in /home/Rev/scroller
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Sun Apr	2 02:56:49 2017 Roméo Nahon
** Last update	Sun Apr	2 02:56:49 2017 Roméo Nahon
*/

#include "include/my.h"

int 	init_stars_1_4(t_scroller *scroller)
{
  OBJECT->stars_1 = sfSprite_create();
  OBJECT->stars_t_1 =
    sfTexture_createFromFile("Ressources/Background/stars.png", NULL);
  if (OBJECT->stars_t_1 == NULL) return (84);
  sfSprite_setTexture(OBJECT->stars_1, OBJECT->stars_t_1, sfTrue);
  OBJECT->stars_2 = sfSprite_create();
  OBJECT->stars_t_2 =
    sfTexture_createFromFile("Ressources/Background/stars.png", NULL);
  if (OBJECT->stars_t_2 == NULL) return (84);
  sfSprite_setTexture(OBJECT->stars_2, OBJECT->stars_t_2, sfTrue);
  OBJECT->s2 = 0;
  OBJECT->stars_3 = sfSprite_create();
  OBJECT->stars_t_3 =
    sfTexture_createFromFile("Ressources/Background/stars.png", NULL);
  if (OBJECT->stars_t_3 == NULL) return (84);
  sfSprite_setTexture(OBJECT->stars_3, OBJECT->stars_t_3, sfTrue);
  OBJECT->s3 = 0;
  OBJECT->stars_4 = sfSprite_create();
  OBJECT->stars_t_4 =
    sfTexture_createFromFile("Ressources/Background/stars.png", NULL);
  if (OBJECT->stars_t_4 == NULL) return (84);
  sfSprite_setTexture(OBJECT->stars_4, OBJECT->stars_t_4, sfTrue);
  OBJECT->s4 = 0;
}

int	init_stars_5_8(t_scroller *scroller)
{
  OBJECT->stars_5 = sfSprite_create();
  OBJECT->stars_t_5 =
    sfTexture_createFromFile("Ressources/Background/stars.png", NULL);
  if (OBJECT->stars_t_5 == NULL) return (84);
  sfSprite_setTexture(OBJECT->stars_5, OBJECT->stars_t_5, sfTrue);
  OBJECT->s5 = 0;
  OBJECT->stars_6 = sfSprite_create();
  OBJECT->stars_t_6 =
    sfTexture_createFromFile("Ressources/Background/stars.png", NULL);
  if (OBJECT->stars_t_6 == NULL) return (84);
  sfSprite_setTexture(OBJECT->stars_6, OBJECT->stars_t_6, sfTrue);
  OBJECT->s6 = 0;
  OBJECT->stars_7 = sfSprite_create();
  OBJECT->stars_t_7 =
    sfTexture_createFromFile("Ressources/Background/stars.png", NULL);
  if (OBJECT->stars_t_7 == NULL) return (84);
  sfSprite_setTexture(OBJECT->stars_7, OBJECT->stars_t_7, sfTrue);
  OBJECT->s7 = 0;
  OBJECT->stars_8 = sfSprite_create();
  OBJECT->stars_t_8 =
    sfTexture_createFromFile("Ressources/Background/stars.png", NULL);
  if (OBJECT->stars_t_8 == NULL) return (84);
  sfSprite_setTexture(OBJECT->stars_8, OBJECT->stars_t_8, sfTrue);
  OBJECT->s8 = 0;
}

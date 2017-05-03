/*
** init_comete.c for scroller in /home/Rev/scroller
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Sun Apr	2 07:19:15 2017 Roméo Nahon
** Last update	Sun Apr	2 07:19:15 2017 Roméo Nahon
*/

#include "include/my.h"

int 	init_com_texture(t_scroller *scroller)
{
  OBJECT_C->com_t_1 =
    sfTexture_createFromFile("Ressources/sprite/com_1.png", NULL);
  OBJECT_C->com_t_2 =
    sfTexture_createFromFile("Ressources/sprite/com_2.png", NULL);
  OBJECT_C->com_t_3 =
    sfTexture_createFromFile("Ressources/sprite/com_3.png", NULL);
  OBJECT_C->com_t_4 =
    sfTexture_createFromFile("Ressources/sprite/com_4.png", NULL);
  OBJECT_C->com_t_5 =
    sfTexture_createFromFile("Ressources/sprite/com_5.png", NULL);
  OBJECT_C->com_t_6 =
    sfTexture_createFromFile("Ressources/sprite/com_6.png", NULL);
  OBJECT_C->com_t_7 =
    sfTexture_createFromFile("Ressources/sprite/com_7.png", NULL);
  if (OBJECT_C->com_t_1 == NULL || OBJECT_C->com_t_2 == NULL ||
      OBJECT_C->com_t_3 == NULL || OBJECT_C->com_t_4 == NULL ||
      OBJECT_C->com_t_5 == NULL || OBJECT_C->com_t_6 == NULL ||
      OBJECT_C->com_t_6 == NULL)
    return (84);
}

void	init_com(t_scroller *scroller)
{
  OBJECT_C->pos_com.x = 300;
  OBJECT_C->pos_com.y = 1080;
  OBJECT_C->pos_com_2.x = 1800;
  OBJECT_C->pos_com_2.y = 1280;
  OBJECT_C->i = OBJECT_C->pos_com.y;
  OBJECT_C->com_1 = sfSprite_create();
  OBJECT_C->com_2 = sfSprite_copy(OBJECT_C->com_1);
  init_com_texture(scroller);
  OBJECT_C->angle_com = 40;
  sfSprite_setRotation(OBJECT_C->com_1, OBJECT_C->angle_com);
  OBJECT_C->angle_com = -40;
  sfSprite_setRotation(OBJECT_C->com_2, OBJECT_C->angle_com);
  sfSprite_setPosition(OBJECT_C->com_1, OBJECT_C->pos_com);
  sfSprite_setPosition(OBJECT_C->com_2, OBJECT_C->pos_com_2);
}

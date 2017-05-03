/*
** init_next.c for scroller in /home/Rev/scroller
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Sat Apr	1 03:28:01 2017 Roméo Nahon
** Last update	Sat Apr	1 03:28:01 2017 Roméo Nahon
*/

#include "include/my.h"

int	init_background(t_scroller *scroller)
{
  OBJECT->background = sfSprite_create();
  OBJECT->background_t =
    sfTexture_createFromFile("Ressources/Background/background.png", NULL);
  if (OBJECT->background_t == NULL)
    return (84);
  sfSprite_setTexture(OBJECT->background, OBJECT->background_t, sfTrue);
  OBJECT->background_2 = sfSprite_create();
  OBJECT->background_t_2 =
    sfTexture_createFromFile("Ressources/Background/space2bg.jpg", NULL);
  if (OBJECT->background_t_2 == NULL)
    return (84);
  sfSprite_setTexture(OBJECT->background_2,
		      OBJECT->background_t_2, sfTrue);
  OBJECT->pos_bg_2.x = 1900;
  sfSprite_setPosition(OBJECT->background_2, OBJECT->pos_bg_2);
  OBJECT->background_3 = sfSprite_create();
  OBJECT->background_t_3 =
    sfTexture_createFromFile("Ressources/Background/background.png", NULL);
  OBJECT->pos_bg_3.x = 1900;
  if (OBJECT->background_t_3 == NULL)
    return (84);
  sfSprite_setTexture(OBJECT->background_3,
		      OBJECT->background_t_3, sfTrue);
  return (0);
}

int	init_planete1(t_scroller *scroller)
{
  OBJECT->pos_plan_1.x = 0;
  OBJECT->pos_plan_1.y = 10;
  OBJECT->planete_1 = sfSprite_create();
  OBJECT->planete_t_1 =
    sfTexture_createFromFile("Ressources/Background/planete.png", NULL);
  if (OBJECT->planete_t_1 == NULL)
    return (84);
  sfSprite_setTexture(OBJECT->planete_1, OBJECT->planete_t_1, sfTrue);
  return (0);
}

int	init_planete2(t_scroller *scroller)
{
  OBJECT->pos_plan_2.x = -800;
  OBJECT->pos_plan_2.y = 500;
  OBJECT->scale_plan_2.y = 1;
  OBJECT->scale_plan_2.x = 1;
  OBJECT->i = 0;
  OBJECT->planete_2 = sfSprite_create();
  OBJECT->planete_t_2 =
    sfTexture_createFromFile("Ressources/Background/planete_2.png", NULL);
  if (OBJECT->planete_t_2 == NULL)
    return (84);
  sfSprite_setTexture(OBJECT->planete_2, OBJECT->planete_t_2, sfTrue);
  return (0);
}

int	init_galaxy(t_scroller *scroller)
{
  OBJECT->pos_gala.x = 20;
  OBJECT->pos_gala.y = 0;
  OBJECT->scale_gala.y = 1;
  OBJECT->scale_gala.x = 1;
  OBJECT->ori_gala.x = 300;
  OBJECT->ori_gala.y = 40;
  OBJECT->angle = 0;
  OBJECT->galaxy = sfSprite_create();
  OBJECT->galaxy_t =
    sfTexture_createFromFile("Ressources/Background/galaxy1.png", NULL);
  if (OBJECT->galaxy_t == NULL)
    return (84);
  sfSprite_setTexture(OBJECT->galaxy, OBJECT->galaxy_t, sfTrue);
  sfSprite_setOrigin(OBJECT->galaxy, OBJECT->ori_gala);
  sfSprite_setPosition(OBJECT->galaxy, OBJECT->pos_gala);
  return (0);
}

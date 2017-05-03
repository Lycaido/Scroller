/*
** init.c for scroller in /home/Rev/scroller
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Fri Mar	31 20:42:28 2017 Roméo Nahon
** Last update	Fri Mar	31 20:42:28 2017 Roméo Nahon
*/

#include "include/my.h"

int	init_struct_next(t_scroller *scroller)
{
  if ((OBJECT_P->hitbox = malloc(sizeof(sfIntRect))) == NULL)
    return (84);
}

int	init_struct(t_scroller *scroller)
{
  if ((INIT = malloc(sizeof(t_init))) == NULL)
    return (84);
  if ((scroller->object = malloc(sizeof(t_object))) == NULL)
    return (84);
  if ((scroller->sphere = malloc(sizeof(t_sphere))) == NULL)
    return (84);
  if ((scroller->object->comete = malloc(sizeof(t_comete))) == NULL)
    return (84);
  if ((scroller->object->asteroide = malloc(sizeof(t_asteroide))) == NULL)
    return (84);
  if ((scroller->object->asteroide->rect =
       malloc(sizeof(sfIntRect))) == NULL)
    return (84);
  if ((scroller->object->asteroide->ast_mob =
       malloc(sizeof(t_ast_mob*) * 20)) == NULL)
    return (84);
  if ((OBJECT->player = malloc(sizeof(t_player))) == NULL)
    return (84);
  if ((OBJECT->player->shoot = malloc(sizeof(t_shoot*) * 150)) == NULL)
    return (84);
  init_struct_next(scroller);
  return (0);
}

int	init_object(t_scroller *scroller)
{
  init_background(scroller);
  init_planete1(scroller);
  init_planete2(scroller);
  init_galaxy(scroller);
  init_stars(scroller);
  init_text(scroller);
  init_sphere(scroller);
  init_com(scroller);
  init_asteroide(scroller);
  init_player(scroller);
  init_score(scroller);
  init_opacity(scroller);
  return (0);
}

int	init(t_scroller *scroller)
{
  INIT->mode.width = S_WIDTH;
  INIT->mode.height = S_HEIGHT;
  INIT->mode.bitsPerPixel = 32;
  INIT->window =
    sfRenderWindow_create(INIT->mode
			  , "Space Scroller", sfFullscreen, NULL);
  if (INIT->window == NULL)
    return (-1);
  sfRenderWindow_setFramerateLimit(INIT->window, 60);
  init_object(scroller);
  return (0);
}

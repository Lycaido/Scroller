/*
** opacity.c for scroller in /home/Rev/scroller
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Sun Apr	2 22:10:40 2017 Roméo Nahon
** Last update	Sun Apr	2 22:10:40 2017 Roméo Nahon
*/

#include "include/my.h"

void	draw_opacity(t_scroller *scroller)
{
  if (scroller->color_lagaf->a <= 0)
    scroller->j = 1;
  else if (scroller->color_lagaf->a >= 255)
    scroller->j = 0;
  if (scroller->j == 1 && OBJECT_A->i % 2 == 1)
    scroller->color_lagaf->a += 1;
  else if (scroller->j == 0 && OBJECT_A->i % 2 == 1)
    scroller->color_lagaf->a -= 1;
  if (scroller->color_proust->a <= 0)
    scroller->y = 1;
  else if (scroller->color_proust->a >= 255)
    scroller->y = 0;
  if (scroller->y == 1 && OBJECT_A->i % 2 == 1)
    scroller->color_proust->a += 1;
  else if (scroller->y == 0 && OBJECT_A->i % 2 == 1)
    scroller->color_proust->a -= 1;
  sfSprite_setColor(scroller->proust, *(scroller->color_proust));
  sfSprite_setColor(scroller->lagaf, *(scroller->color_lagaf));
  sfRenderWindow_drawSprite(INIT->window, scroller->lagaf, NULL);
  sfRenderWindow_drawSprite(INIT->window, scroller->proust, NULL);
}
void		init_opacity(t_scroller *scroller)
{
  sfVector2f	pos_proust;
  sfVector2f	pos_lagaf;

  pos_proust.x = 1000;
  pos_proust.y = 250;
  pos_lagaf.x = 1000;
  pos_lagaf.y = 300;
  if ((scroller->color_proust =
       malloc(sizeof(*(scroller->color_proust)))) == NULL)
    return ;
  if ((scroller->color_lagaf =
       malloc(sizeof(*(scroller->color_lagaf)))) == NULL)
    return ;
  scroller->lagaf = sfSprite_create();
  scroller->proust = sfSprite_create();
  scroller->color_proust->a = 0;
  scroller->color_lagaf->a = 255;
  if ((scroller->lagaf_t =
    sfTexture_createFromFile(PATH_2, NULL)) == NULL) return ;
  if ((scroller->proust_t =
    sfTexture_createFromFile(PATH_3, NULL)) == NULL) return ;
  sfSprite_setTexture(scroller->lagaf, scroller->lagaf_t, sfTrue);
  sfSprite_setTexture(scroller->proust, scroller->proust_t, sfTrue);
  sfSprite_setPosition(scroller->lagaf, pos_lagaf);
  sfSprite_setPosition(scroller->proust, pos_proust);
}

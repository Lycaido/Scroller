/*
** player.c for scroller in /home/Rev/scroller
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Sun Apr	2 15:04:34 2017 Roméo Nahon
** Last update	Sun Apr	2 15:04:34 2017 Roméo Nahon
*/

#include "include/my.h"

void	draw_shoot(t_scroller *scroller)
{
  int	i;

  i = -1;
  while (++i < 150)
    {
      if (OBJECT_P->shoot[i]->id == 1)
	{
	  sfSprite_setPosition(OBJECT_P->shoot[i]->shoot,
			       OBJECT_P->shoot[i]->shoot_pos);
	  sfRenderWindow_drawSprite(INIT->window,
				    OBJECT_P->shoot[i]->shoot, NULL);
	  OBJECT_P->shoot[i]->hitbox->left = OBJECT_P->shoot[i]->shoot_pos.x;
	  OBJECT_P->shoot[i]->hitbox->top = OBJECT_P->shoot[i]->shoot_pos.y;
	  OBJECT_P->shoot[i]->hitbox->height = 20;
	  OBJECT_P->shoot[i]->hitbox->width= 20;
	  OBJECT_P->shoot[i]->shoot_pos.x += 20;
	  if (OBJECT_P->p_pos_shoot.x > 1900 ||
	      collision_ast_shoot(scroller, i) == 1)
	    OBJECT_P->shoot[i]->id = 2;
	}
    }
}
void	draw_player(t_scroller *scroller)
{
  OBJECT_P->hitbox->left = OBJECT_P->p_pos.x;
  OBJECT_P->hitbox->top = OBJECT_P->p_pos.y;
  OBJECT_P->hitbox->height = 20;
  OBJECT_P->hitbox->width = 20;
  OBJECT_P->player_t = sfTexture_createFromImage(OBJECT_P
						 ->player_image, OBJECT_P->rect_player);
  sfSprite_setPosition(OBJECT_P->player, OBJECT_P->p_pos);
  sfSprite_setTexture(OBJECT_P->player, OBJECT_P->player_t, sfTrue);
  sfRenderWindow_drawSprite(INIT->window, OBJECT_P->player, NULL);
}
void	init_player_next(t_scroller *scroller)
{
  if ((OBJECT_P->rect_player =
       malloc(sizeof(sfIntRect))) == NULL)
    return ;
  if ((OBJECT_P->rect_shoot =
       malloc(sizeof(sfIntRect))) == NULL)
    return ;
  OBJECT_P->player = sfSprite_create();
  OBJECT_P->p_pos.x = 50;
  OBJECT_P->p_pos.y = 540;
  OBJECT_P->rect_player->left = 125;
  OBJECT_P->rect_player->top = 50;
  OBJECT_P->rect_player->height = 40;
  OBJECT_P->rect_player->width = 40;
  OBJECT_P->rect_shoot->left = 0;
  OBJECT_P->rect_shoot->top = 0;
  OBJECT_P->rect_shoot->height = 150;
  OBJECT_P->rect_shoot->width = 50;
  OBJECT_P->angle = 90;
  OBJECT_P->player_image =
    sfImage_createFromFile("Ressources/sprite/playert.png");
  OBJECT_P->shoot_image =
    sfImage_createFromFile("Ressources/sprite/shoot.png");
}
void	init_player(t_scroller *scroller)
{
  int	i;

  i = -1;
  init_player_next(scroller);
  OBJECT_P->player_t = sfTexture_createFromImage(OBJECT_P
						 ->player_image, OBJECT_P->rect_player);
  sfSprite_setPosition(OBJECT_P->player, OBJECT_P->p_pos);
  sfSprite_setRotation(OBJECT_P->player, OBJECT_P->angle);
  while (++i < 150)
    {
      if ((OBJECT_P->shoot[i] =
	   malloc(sizeof(*(OBJECT_P->shoot[i])))) == NULL)
	return ;
      if ((OBJECT_P->shoot[i]->hitbox = malloc(sizeof(sfIntRect))) == NULL)
	return ;
      OBJECT_P->shoot[i]->shoot = sfSprite_create();
      OBJECT_P->shoot[i]->id = 0;
      OBJECT_P->shoot[i]->hitbox->left = OBJECT_P->shoot[i]->shoot_pos.x;
      OBJECT_P->shoot[i]->hitbox->top = OBJECT_P->shoot[i]->shoot_pos.y;
      OBJECT_P->shoot[i]->hitbox->height = 150;
      OBJECT_P->shoot[i]->hitbox->width= 50;
    }
}

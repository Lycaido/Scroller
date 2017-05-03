/*
** keyboard.c for scroller in /home/Rev/scroller
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Sun Apr	2 16:26:07 2017 Roméo Nahon
** Last update	Sun Apr	2 16:26:07 2017 Roméo Nahon
*/

#include "include/my.h"

void	key_up(t_scroller *scroller)
{
  if (sfKeyboard_isKeyPressed(sfKeyUp)
      == sfTrue && OBJECT->player->p_pos.y > 0)
    {
      OBJECT->player->p_pos.y -= 5;
      OBJECT_P->player_t =
	sfTexture_createFromImage(OBJECT_P
				  ->player_image, OBJECT_P->rect_player);
      if (OBJECT_P->lock == 0)
	{
	  OBJECT_P->rect_player->left -= 88;
	  OBJECT_P->lock = 1;
	}
    }
  else
    {
      if (OBJECT_P->lock == 1)
	{
	  OBJECT_P->rect_player->left += 88;
	  OBJECT_P->player_t =
	    sfTexture_createFromImage(OBJECT_P
				      ->player_image, OBJECT_P->rect_player);
	  OBJECT_P->lock = 0;
	}
    }
}

void	key_down(t_scroller *scroller)
{
  if (sfKeyboard_isKeyPressed(sfKeyDown)
      == sfTrue && OBJECT->player->p_pos.y <= 1080)
    {
      OBJECT->player->p_pos.y += 5;
      OBJECT_P->player_t =
	sfTexture_createFromImage(OBJECT_P
				  ->player_image, OBJECT_P->rect_player);
      if (OBJECT_P->lock_2 == 0)
	{
	  OBJECT_P->rect_player->left += 88;
	  OBJECT_P->lock_2 = 1;
	}
    }
  else
    {
      if (OBJECT_P->lock_2 == 1)
	{
	  OBJECT_P->rect_player->left -= 88;
	  OBJECT_P->player_t =
	    sfTexture_createFromImage(OBJECT_P
				      ->player_image, OBJECT_P->rect_player);
	  OBJECT_P->lock_2 = 0;
	}
    }
}

void	key_space(t_scroller *scroller)
{
  int i;

  i = -1;
  if (sfKeyboard_isKeyPressed(sfKeySpace)
      == sfTrue && OBJECT_A->i % 10 == 1)
    {
      while (++i < 150 && OBJECT_P->shoot[i]->id != 0);			
      OBJECT_P->shoot[i]->id = 1;
      OBJECT_P->p_pos_shoot = sfSprite_getPosition(OBJECT_P->player);
      OBJECT_P->shoot[i]->shoot_pos = OBJECT_P->p_pos_shoot;
      OBJECT_P->shoot[i]->shoot_pos.y -= 5;
      OBJECT_P->shoot[i]->shoot_pos.x += 10;
      OBJECT_P->shoot[i]->shoot_t =
	sfTexture_createFromImage(OBJECT_P
				  ->shoot_image, OBJECT_P->rect_shoot);
      sfSprite_setRotation(OBJECT_P->shoot[i]->shoot, OBJECT_P->angle);
      sfSprite_setPosition(OBJECT_P->shoot[i]->shoot,
			   OBJECT_P->shoot[i]->shoot_pos);
      sfSprite_setTexture(OBJECT_P->shoot[i]->shoot,
			  OBJECT_P->shoot[i]->shoot_t, sfTrue);
    }
}

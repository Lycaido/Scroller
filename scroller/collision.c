/*
** collision.c for scroller in /home/Rev/scroller
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Sun Apr	2 17:31:39 2017 Roméo Nahon
** Last update	Sun Apr	2 17:31:39 2017 Roméo Nahon
*/

#include "include/my.h"

int	collision_shoot_ast(t_scroller *scroller, int j)
{
  int	i;

  i = -1;
  while (++i < 150)
    {
      if (OBJECT_P->shoot[i] != NULL && OBJECT_A->ast_mob[j] != NULL)
	{
	  if (sfIntRect_intersects(OBJECT_P->
				   shoot[i]->hitbox, OBJECT_A->ast_mob[j]->
				   hitbox, NULL) == sfTrue)
	    {
	      scroller->score += 100;
	      return (1);
	    }
	}
    }
  return (0);
}

int	collision_ast_shoot(t_scroller *scroller, int j)
{
  int	i;

  i = -1;
  while (++i < 20)
    {
      if (OBJECT_P->shoot[j] != NULL && OBJECT_A->ast_mob[i] != NULL)
	{
	  if (sfIntRect_intersects(OBJECT_P->
				   shoot[j]->hitbox, OBJECT_A->ast_mob[i]->
				   hitbox, NULL) == sfTrue)
	    {
	      return (1);
	    }
	}
    }
  return (0);
}

int	collision_player(t_scroller *scroller)
{
  int	i;

  i = -1;
  while (++i < 20)
    {
      if (OBJECT_P->hitbox != NULL && OBJECT_A->ast_mob[i] != NULL)
	{
	  if (sfIntRect_intersects(OBJECT_P->hitbox, OBJECT_A->ast_mob[i]->
				   hitbox, NULL) == sfTrue)
	    {
	      return (84);
	    }
	}
    }
  return (0);
}

void	move_hitbox_shoot(t_scroller *scroller)
{
  int	i;

  i = -1;
  while (++i < 150)
    {
      if (OBJECT_P->shoot[i]->id == 2)
	{
	  OBJECT_P->shoot[i]->hitbox->left = -1000;
	  OBJECT_P->shoot[i]->hitbox->top = -1000;
	  OBJECT_P->shoot[i]->hitbox->height = 0;
	  OBJECT_P->shoot[i]->hitbox->width= 0;
	  OBJECT_P->shoot[i]->id = 0;
	}
    }
}

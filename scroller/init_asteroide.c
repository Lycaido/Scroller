/*
** init_asteroide.c for scroller in /home/Rev/scroller
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Sun Apr	2 07:19:29 2017 Roméo Nahon
** Last update	Sun Apr	2 07:19:29 2017 Roméo Nahon
*/

#include "include/my.h"

void	draw_asteroide_next(t_scroller *scroller, int i)
{
  if (collision_shoot_ast(scroller, i) == 1)
    {
      move_hitbox_shoot(scroller);
      OBJECT_A->random = rand() % (400 - 2000) + 400;
      OBJECT_A->ast_mob[i]->pos_ast.x = 1900 + OBJECT_A->random;
      OBJECT_A->ast_mob[i]->pos_ast.y = rand() % (50 - 1000) + 50;
    }
  OBJECT_A->ast_mob[i]->hitbox->left =
    OBJECT_A->ast_mob[i]->pos_ast.x + 15;
  OBJECT_A->ast_mob[i]->hitbox->top = OBJECT_A->ast_mob[i]->pos_ast.y;
  OBJECT_A->ast_mob[i]->hitbox->height = 150;
  OBJECT_A->ast_mob[i]->hitbox->width = 130;
  OBJECT_A->ast_mob[i]->pos_ast.x -= OBJECT_A->ast_mob[i]->speed;
  sfSprite_setPosition(OBJECT_A->ast_mob[i]->ast,
		       OBJECT_A->ast_mob[i]->pos_ast);
  sfSprite_setTexture(OBJECT_A->ast_mob[i]->ast,
		      OBJECT_A->ast_t, sfTrue);
  sfRenderWindow_drawSprite(INIT->window,
			    OBJECT_A->ast_mob[i]->ast, NULL);
}
void	draw_asteroide(t_scroller *scroller)
{
  int i;

  i = -1;
  anim_asteroide(scroller);
  while (++i < 20)
    {
      if (OBJECT_A->ast_mob[i]->pos_ast.x <= -100 - OBJECT_A->random)
	{
	  OBJECT_A->random = rand() % (400 - 2000) + 400;
	  OBJECT_A->ast_mob[i]->pos_ast.x = 1900 + OBJECT_A->random;
	  OBJECT_A->ast_mob[i]->pos_ast.y = rand() % (50 - 1000) + 50;
	}
      draw_asteroide_next(scroller, i);
    }
}

void	anim_asteroide(t_scroller *scroller)
{
  if (OBJECT_A->i % 5 == 1)
    {
      OBJECT_A->ast_t =
	sfTexture_createFromImage(OBJECT_A->ast_image, OBJECT_A->rect);
      OBJECT_A->rect->left += 250;
      if (OBJECT_A->rect->left == 2000)
	OBJECT_A->rect->left = 0;
    }
  OBJECT_A->i += 1;
}

void	init_asteroide(t_scroller *scroller)
{
  int i;

  i = -1;
  OBJECT_A->rect->left = 0;
  OBJECT_A->rect->top = 0;
  OBJECT_A->rect->width = 250;
  OBJECT_A->rect->height = 250;
  OBJECT_A->i = 0;
  OBJECT_A->ast_image = sfImage_createFromFile(PATH_1);
  if (OBJECT_A->ast_image == NULL) return ;
  OBJECT_A->ast_t =
    sfTexture_createFromImage(OBJECT_A->ast_image, OBJECT_A->rect);
  while (++i < 20)
    {
      if ((OBJECT_A->ast_mob[i] =
	   malloc(sizeof(*(OBJECT_A->ast_mob[i])))) == NULL)
	return ;
      if ((OBJECT_A->ast_mob[i]->hitbox = malloc(sizeof(sfIntRect))) == NULL)
	return ;
      OBJECT_A->ast_mob[i]->speed = rand() % (1 - 8) + 1;
      OBJECT_A->ast_mob[i]->ast = sfSprite_create();
      OBJECT_A->random = rand() % (400 - 2000) + 400;
      OBJECT_A->ast_mob[i]->pos_ast.x = 1900 + OBJECT_A->random;
      OBJECT_A->ast_mob[i]->pos_ast.y = rand() % (50 - 1000) + 50;
    }
}

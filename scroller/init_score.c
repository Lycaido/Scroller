/*
** init_score.c for scroller in /home/Rev/scroller
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Sun Apr	2 18:50:37 2017 Roméo Nahon
** Last update	Sun Apr	2 18:50:37 2017 Roméo Nahon
*/

#include "include/my.h"

void	draw_score(t_scroller *scroller)
{
  char 	*score;

  score = intoarg(scroller->score, my_intlen(scroller->score));
  sfText_setString(OBJECT->score_text, score);
  sfRenderWindow_drawText(INIT->window, OBJECT->score_text, NULL);
}
void	init_score(t_scroller *scroller)
{
  sfVector2f	pos;

  scroller->score = 0;
  pos.x = 900;
  pos.y = 1000;
  scroller->old_score = scroller->score;
  OBJECT->score_text = sfText_create();
  sfText_setString(OBJECT->score_text, "0");
  sfText_setPosition(OBJECT->score_text, pos);
  sfText_setFont(OBJECT->score_text, OBJECT->font);
  sfText_setCharacterSize(OBJECT->score_text, 50);
  sfRenderWindow_drawText(INIT->window, OBJECT->score_text, NULL);
}

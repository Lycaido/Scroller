/*
** loop.c for scroller in /home/Rev/scroller
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Fri Mar	31 20:43:28 2017 Roméo Nahon
** Last update	Fri Mar	31 20:43:28 2017 Roméo Nahon
*/

#include "include/my.h"

void	score(t_scroller *scroller)
{
  if (scroller->score == scroller->old_score + 1000
      && OBJECT_P->rect_player->top <= 275)
    {
      if (OBJECT_P->rect_player->top >= 135 &&
	  OBJECT_P->rect_player->top < 180)
	{
	  OBJECT_P->rect_shoot->left += 55;
	  OBJECT_P->rect_player->top += 55;
	  OBJECT_P->rect_player->height = 48;
	  OBJECT_P->rect_player->width = 45;
	}
      else if (OBJECT_P->rect_player->top >= 180)
	{
	  OBJECT_P->rect_shoot->left += 55;
	  OBJECT_P->rect_player->top += 55;
	  OBJECT_P->rect_player->height = 48;
	  OBJECT_P->rect_player->width = 46;
	}
      else
	{
	  OBJECT_P->rect_shoot->left += 55;
	  OBJECT_P->rect_player->top += 45;
	}
      scroller->old_score = scroller->score;
    }
}
int	scene(t_scroller *scroller,
	      int timer, clock_t time_,
	      t_list_tracker *elem)
{
  sfRenderWindow_drawSprite(INIT->window, OBJECT->background, NULL);
  control_time(scroller, timer, time_);
  if (elem != NULL)
    sfText_setString(OBJECT->tracker_text, elem->name);
  sfText_setPosition (OBJECT->tracker_text, OBJECT->tracker_text_pos);
  OBJECT->tracker_text_pos.x += 2;
  if (OBJECT->tracker_text_pos.x >= 1900)
    OBJECT->tracker_text_pos.x = -700;
  sfRenderWindow_drawText(INIT->window, OBJECT->tracker_text, NULL);
  sfRenderWindow_drawSprite(INIT->window, SPHERE->sphere, NULL);
  sfTexture_updateFromPixels(SPHERE->sphere_t,
			     SPHERE->pixels, S_WIDTH, S_HEIGHT, 0, 0);
  draw_shoot(scroller);
  draw_player(scroller);
  draw_asteroide(scroller);
  draw_score(scroller);
  score(scroller);
  move_hitbox_shoot(scroller);
  if (collision_player(scroller) == 84) return (84);
  sfRenderWindow_display(scroller->init->window);
  return (0);
}

void	get_keyevent(t_scroller *scroller)
{
  if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue
      && OBJECT->player->p_pos.x > 10)
    OBJECT->player->p_pos.x -= 5;
  if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue
      && OBJECT->player->p_pos.x < 1920)
    OBJECT->player->p_pos.x += 5;
  key_up(scroller);
  key_down(scroller);
  key_space(scroller);
}
int	event(t_scroller *scroller,
	      t_list_tracker *elem,
	      t_list_tracker *old_elem)
{
  int		timer;
  clock_t	time_;

  while (sfRenderWindow_isOpen(scroller->init->window))
    {
      sfRenderWindow_clear(scroller->init->window, sfBlack);
      while (sfRenderWindow_pollEvent(INIT->window, &INIT->event))
	{
	  if (scroller->init->event.key.code == sfKeyEscape)
	    sfRenderWindow_close(scroller->init->window);
	  if (sfKeyboard_isKeyPressed(sfKeyE) == sfTrue)
	    {
	      if (elem == NULL) elem = scroller->list->first;
	      else
		{
		  old_elem = elem;
		  elem = elem->next;
		}
	      tracker(scroller, elem, old_elem);
	    }
	}
      if (scene(scroller, timer, time_, elem) == 84) return (84);
      get_keyevent(scroller);
    }
  return (0);
}

int		loop(t_scroller *scroller)
{
  t_list_tracker *old_elem;
  t_list_tracker *elem;

  if (scroller->list->first == NULL)
    {
      my_printf("Error: no music\n");
      return (84);
    }
  elem = scroller->list->first;
  if (event(scroller, elem, old_elem) == 84)
    return (84);
  sfRenderWindow_destroy(scroller->init->window);
  return (0);
}

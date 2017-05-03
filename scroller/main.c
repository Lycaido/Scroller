/*
** main.c for scroller in /home/Rev/scroller
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Fri Mar	31 20:43:22 2017 Roméo Nahon
** Last update	Fri Mar	31 20:43:22 2017 Roméo Nahon
*/

#include "include/my.h"

int		main(int ac, char **av)
{
  time_t	t;
  t_scroller	*scroller;

  srand(time(&t));
  if ((scroller = malloc(sizeof(t_scroller))) == NULL)
    return (84);
  if ((scroller->list = malloc(sizeof(t_control_tracker))) == NULL)
    return (84);
  init_struct(scroller);
  if (get_list_music(scroller) == 84)
    return (84);
  init(scroller);
  if (loop(scroller) == 84)
    return (84);
  return (0);
}

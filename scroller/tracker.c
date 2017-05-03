/*
** tracker.c for scroller in /home/Rev/scroller
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Sat Apr	1 10:15:48 2017 Roméo Nahon
** Last update	Sat Apr	1 10:15:48 2017 Roméo Nahon
*/

#include "include/my.h"

void		push_music(t_scroller *scroller, char *music_name)
{
  t_list_tracker	*elem;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    return ;
  elem->name = music_name;
  elem->next = scroller->list->first;
  scroller->list->first = elem;
}

int	get_list_music(t_scroller *scroller)
{
	char	*name;
	int		fd;

	fd = open("music.conf", O_RDONLY);
	if (fd < 0) return (84);
	while ((name = get_next_line(fd)) != NULL)
		push_music(scroller, name);
}

int	tracker(t_scroller *scroller,
			t_list_tracker *elem, t_list_tracker* old_elem)
{	
  if (elem != NULL)
    {
      elem->music = sfMusic_createFromFile(elem->name);
      if (old_elem->music != NULL)
	{
	  sfMusic_stop(old_elem->music);
	  sfMusic_destroy(old_elem->music);
	}
      sfMusic_play(elem->music);
    }
}

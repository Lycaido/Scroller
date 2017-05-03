/*
** raytrace.c for raytracer1 in /home/Rev/raytracer1/autograder
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Fri Feb	10 13:09:52 2017 Roméo Nahon
** Last update	Fri Feb	10 13:09:52 2017 Roméo Nahon
*/

#include "include/my.h"

void	my_put_pixel(t_scroller *scroller,
		     int x, int y, sfColor color)
{
  if (y < S_HEIGHT && x < S_WIDTH)
    {
      SPHERE->pixels[(S_WIDTH * y + x) * 4] = color.r;
      SPHERE->pixels[(S_WIDTH * y + x) * 4 + 1] = color.g;
      SPHERE->pixels[(S_WIDTH * y + x) * 4 + 2] = color.b;
      SPHERE->pixels[(S_WIDTH * y + x) * 4 + 3] = color.a;
    }
}

sfVector3f	calc_dir_vector(float dist_to_plane,
				sfVector2i screen_size,
				sfVector2i screen_pos)
{
  sfVector3f	dir;

  dir.x = dist_to_plane;
  dir.y = (screen_size.x / 2) - screen_pos.x;
  dir.z = (screen_size.y / 2) - screen_pos.y;
  return (dir);
}

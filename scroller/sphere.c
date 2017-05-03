/*
** sphere.c for scroller in /home/Rev/scroller
** 
** Made by Roméo Nahon
** Login   <Rev@epitech.net>
** 
** Started on Sun Apr 2 04:37:28 2017 Roméo Nahon
** Last update Sun Apr  2 20:38:48 2017 Roméo Nahon
*/

#include "include/my.h"

int	create_pixel_buffer(t_scroller *scroller)
{
  int	i;

  SPHERE->width = S_WIDTH;
  SPHERE->height = S_HEIGHT;
  if ((SPHERE->pixels = malloc(SPHERE->width
    * SPHERE->height * 4 * sizeof(SPHERE->pixels))) == NULL)
    return (84);
  i = 0;
  while (i < SPHERE->width * SPHERE->height * 4)
  {
    SPHERE->pixels[i] = 0;
    i += 1;
  }
  return (0);
}

float	x1_x2_sphere(float x1, float x2)
{
  if (x1 <= 0 && x2 <= 0)
    return (-1.0);
  else if (x1 < x2 && x1 > 0 && x2 > 0)
    return (x1);
  else if (x1 > x2 && x1 > 0 && x2 > 0)
    return (x2);
  else if (x2 < 0 && x1 > 0)
    return (x1);
  else if (x2 < 0 && x1 > 0)
    return (x2);
  return (-1.0);
}

float	intersect_sphere_next(float b, float c, float a)
{
  float	delta;
  float	x1;
  float	x2;

  delta = (b * b) - (4 * a * c);
  if (delta > 0)
    {
      if (a == 0)
	return (-1.0);
      x1 = (-b + sqrt((b * b) - (4 * a * c))) / (2 * a);
      x2 = (-b - sqrt((b * b) - (4 * a * c))) / (2 * a);
      return (x1_x2_sphere(x1, x2));
    }
  else if (delta == 0)
    {
      if (a == 0)
	return (1.0);
      if ((-b / (2 * a)) < 0)
	return (-1.0);
      return (-b / (2 * a));
    }
  else
    return (-1.0);
}

float	intersect_sphere(sfVector3f eye_pos,
			 sfVector3f dir_vector,
			 float radius)
{
  float	a;
  float	b;
  float	c;

  a = (VECT(x) * VECT(x)) + (VECT(y) * VECT(y)) + (VECT(z) * VECT(z));
  b = 2 * (((eye_pos.x) * VECT(x)) + (eye_pos.y
				      * VECT(y)) + (eye_pos.z * VECT(z)));
  c = (eye_pos.x * eye_pos.x) +
    (eye_pos.y * eye_pos.y) +
    (eye_pos.z * eye_pos.z) - (radius * radius);
  return (intersect_sphere_next(b, c, a));
}

sfVector3f	get_normal_sphere(sfVector3f intersection_point)
{
  return (intersection_point);
}

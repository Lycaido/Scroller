/*
** light.c for raytracer in /home/Rev/raytracer1/autograder
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Fri Feb	24 15:38:19 2017 Roméo Nahon
** Last update	Fri Feb	24 15:38:19 2017 Roméo Nahon
*/

#include "include/my.h"

sfVector3f	normal_this(sfVector3f to_normal)
{
  float		lenght;

  if ((lenght = to_normal.x * to_normal.x + to_normal.y
       * to_normal.y + to_normal.z * to_normal.z) < 0)
    lenght = -lenght;
  lenght = sqrt(lenght);
  if (lenght == 0)
    {
      to_normal.x = 0;
      to_normal.y = 0;
      to_normal.z = 0;
      return (to_normal);
    }
  else if (lenght < 0)
    lenght = -lenght;
  to_normal.x = to_normal.x / lenght;
  to_normal.y = to_normal.y / lenght;
  to_normal.z = to_normal.z / lenght;
  return (to_normal);
}

float	get_light_coef(sfVector3f light_vector, sfVector3f normal_vector)
{
  float	light_coef;

  normal_vector = normal_this(normal_vector);
  light_vector = normal_this(light_vector);
  light_coef = light_vector.x * normal_vector.x +
    light_vector.y * normal_vector.y +
    light_vector.z * normal_vector.z;
  if (light_coef <= 0)
    light_coef = 0;
  else if (light_coef >= 1)
    light_coef = 1;
  return (light_coef);
}

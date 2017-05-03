/*
** init_next_3.c for scroller in /home/Rev/scroller
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Sat Apr	1 08:49:43 2017 Roméo Nahon
** Last update	Sat Apr	1 08:49:43 2017 Roméo Nahon
*/

#include "include/my.h"

void	init_text(t_scroller *scroller)
{
  OBJECT->end_text_pos.x = 10;
  OBJECT->end_text_pos.y = 500;
  OBJECT->end_text_origin.x = 300;
  OBJECT->end_text_origin.y = 2;
  OBJECT->end_text_angle = 0;
  OBJECT->j = 0;
  OBJECT->font = sfFont_createFromFile("Ressources/font/space_age.ttf");
  OBJECT->end_text = sfText_create();
  OBJECT->tracker_text = sfText_create();
  sfText_setString(OBJECT->end_text, "Space Scroller");
  sfText_setFont(OBJECT->end_text, OBJECT->font);
  sfText_setFont(OBJECT->tracker_text, OBJECT->font);
  sfText_setOrigin(OBJECT->end_text, OBJECT->end_text_origin);
  sfText_setCharacterSize(OBJECT->end_text, 50);
}

sfColor		red_color(t_scroller *scroller)
{
  sfColor color;

  color.r = 255 * SPHERE->light;
  color.g = 255 * SPHERE->light;
  color.b = 51 * SPHERE->light;
  color.a = 255;
  return (color);
}

int	init_sphere(t_scroller *scroller)
{
  SPHERE->eye_pos.x = 100;
  SPHERE->eye_pos.y = 0;
  SPHERE->eye_pos.z = 0;
  SPHERE->s_size.x = S_HEIGHT;
  SPHERE->s_size.y = S_WIDTH;
  create_pixel_buffer(scroller);
  if ((SPHERE->sphere = sfSprite_create()) == NULL)
    return (84);
  if ((SPHERE->sphere_t = sfTexture_create(S_WIDTH, S_HEIGHT)) == NULL)
    return (84);
  sfSprite_setTexture(SPHERE->sphere, SPHERE->sphere_t, sfTrue);
  draw_sphere(scroller);
}

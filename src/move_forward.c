/*
** move_forward.c for wolf3d in /home/arthur/delivery/wolf3d
**
** Made by Arthur Philippe
** Login   <arthur@epitech.net>
**
** Started on  Tue Dec 20 13:13:33 2016 Arthur Philippe
** Last update Sat Jan 14 08:47:33 2017 Arthur Philippe
*/

#include "wolf.h"
#include <math.h>

sfVector2f	move_forward(sfVector2f pos, float direction, float distance)
{
  sfVector2f	w;
  float		angle;

  angle = degres_to_rads(direction);
  w.x = pos.x + (distance * cos(angle));
  w.y = pos.y + (distance * sin(angle));
  return (w);
}

float		degres_to_rads(float degres)
{
  float		rads;

  rads = degres * (M_PI / 180);
  return (rads);
}

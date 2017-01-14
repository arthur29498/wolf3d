/*
** wf_darkness.c for wolf3d in /home/arthur/delivery/wolf3d/src/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Sat Jan 14 09:03:19 2017 Arthur Philippe
** Last update Sat Jan 14 15:20:46 2017 Arthur Philippe
*/

#include "wolf.h"

void	wf_darken(t_raycast *rayc)
{
  if (rayc->dist > 510)
    rayc->color.a = 255;
  else if (rayc->dist > 255)
    rayc->color.a = (rayc->dist - 255);
  else
    rayc->color.a = 0;
  if (rayc->color.a > 175)
    rayc->color.a -= 175;
  else
    rayc->color.a = 0;
}

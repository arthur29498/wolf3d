/*
** my_draw_line.c for wolf3d in /home/arthur/delivery/wolf3d
**
** Made by Arthur Philippe
** Login   <arthur@epitech.net>
**
** Started on  Mon Dec 19 13:32:03 2016 Arthur Philippe
** Last update Sun Dec 25 15:24:23 2016 Arthur Philippe
*/

#include "wolf.h"

void	my_draw_line(t_my_framebuffer *framebuffer,
		     sfVector2i from,
		     sfVector2i to,
		     sfColor color)
{
  int	v1;
  int	v2;
  int	x;
  int	x2;
  int	y;

  if (to.x == from.x)
    my_draw_ordinate(framebuffer, from, to, color);
  else
    {
      v1 = to.x - from.x;
      v2 = to.y - from.y;
      x = (to.x < from.x) ? to.x : from.x;
      x2 = (to.x < from.x) ? from.x : to.x;
      while (x < x2)
	{
	  y = from.y + v2 * (x - from.x) / v1;
	  if (y >= 0 && x >= 0)
	    if (!(y >= (*framebuffer).height && x >= (*framebuffer).width))
	      my_put_pixel(framebuffer, x, y, color);
	  x += 1;
	}
    }
}

void	my_draw_ordinate(t_my_framebuffer *framebuffer,
			 sfVector2i from,
			 sfVector2i to,
			 sfColor color)
{
  int	low;
  int	high;

  low = (from.y <= to.y) ? from.y : to.y;
  high = (from.y > to.y) ? from.y : to.y;
  while (low <= high)
    {
      if (high >= 0 && low >= 0 && high <= (*framebuffer).height && to.x >= 0)
	if (to.x <= (*framebuffer).width)
	  my_put_pixel(framebuffer, to.x, low, color);
      low += 1;
    }
}

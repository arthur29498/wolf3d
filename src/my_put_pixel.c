/*
** my_put_pixel.c for wold3d in /home/arthur/delivery/wolf3d
**
** Made by Arthur Philippe
** Login   <arthur@epitech.net>
**
** Started on  Mon Dec 19 13:32:39 2016 Arthur Philippe
** Last update Sat Jun  3 14:15:51 2017 Arthur Philippe
*/

#include "wolf.h"

void	my_put_pixel(t_my_framebuffer *framebuffer, int x,
		     int y, sfColor color)
{
  if (x < 0 || y < 0)
    return ;
  if (x > (*framebuffer).width || y > (*framebuffer).height)
    return ;
  (*framebuffer).pixels[((*framebuffer).width * y + x) * 4] = color.r;
  (*framebuffer).pixels[((*framebuffer).width * y + x) * 4 + 1] = color.g;
  (*framebuffer).pixels[((*framebuffer).width * y + x) * 4 + 2] = color.b;
  (*framebuffer).pixels[((*framebuffer).width * y + x) * 4 + 3] = color.a;
}

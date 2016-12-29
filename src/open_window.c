/*
** open_window.c for wolf3d in /home/arthur/delivery/wolf3d
**
** Made by Arthur Philippe
** Login   <arthur@epitech.net>
**
** Started on  Mon Dec 19 13:35:43 2016 Arthur Philippe
** Last update Thu Dec 29 10:51:21 2016 Arthur Philippe
*/

#include "wolf.h"

int			wf_start_window(t_my_window *w, t_env *env)
{
  my_putstr(1, HINT_OPENING_WINDOW);
  if (!w)
    return (1);
  w->window = create_window(WINDOW_NAME, SC_W, SC_H);
  w->sprite = sfSprite_create();
  w->tex = sfTexture_create(SC_W, SC_H);
  w->buffer = my_framebuffer_create(SC_W, SC_H);
  if (!w->buffer || !w->window)
    return (1);
  sfSprite_setTexture(w->sprite, w->tex, sfTrue);
  wf_rendering_parser(w, env);
  sfTexture_updateFromPixels(w->tex, w->buffer->pixels, SC_W, SC_H, 0, 0);
  my_putstr(1, HINT_DONE);
  return (0);
}

sfRenderWindow		*create_window(char *name, int width, int height)
{
  sfRenderWindow	*window;
  sfVideoMode		mode;

  mode.width = width;
  mode.height = height;
  mode.bitsPerPixel = 32;
  window = sfRenderWindow_create(mode, name, sfResize | sfClose, NULL);
  return (window);
}

t_my_framebuffer	*my_framebuffer_create(int width, int height)
{
  int			i;
  t_my_framebuffer	*buffer;

  buffer = malloc(sizeof(t_my_framebuffer));
  if (!buffer)
    return ((t_my_framebuffer *) 0);
  (*buffer).pixels = malloc(width * height * 5 * sizeof(sfUint8));
  (*buffer).width = width;
  (*buffer).height = height;
  if (!((*buffer).pixels))
    return ((t_my_framebuffer *) 0);
  i = 0;
  while (i < width * height * 4)
    (*buffer).pixels[i++] = 0;
  return (buffer);
}

void	wf_reset_pixels(t_my_framebuffer *buffer)
{
  int	i;

  i = 0;
  while (i < (*buffer).width * (*buffer).height * 4)
    (*buffer).pixels[i++] = 0;
}

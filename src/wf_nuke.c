/*
** wf_nuke.c for wolf3d in /home/arthur/delivery/wolf3d
**
** Made by Arthur Philippe
** Login   <arthur@epitech.net>
**
** Started on  Wed Dec 28 14:27:39 2016 Arthur Philippe
** Last update Thu Dec 29 16:45:31 2016 Arthur Philippe
*/

#include "wolf.h"

void	my_memset(char *str, int len)
{
  int	i;

  i = -1;
  while (++i < len)
    str[i] = 0;
}

void	my_env_destroy(t_env *env)
{
  int	i;

  i = 0;
  my_putstr(1, "Destroying environement");
  while (i < env->map_size - 1 && env->map[i])
    {
      my_putstr(1, ".");
      free(env->map[i]);
      i += 1;
    }
  my_putstr(1, " freed map lines, ");
  free(env->map);
  my_putstr(1, "freed map itself, ");
  free(env);
  my_putstr(1, "freed env [SUCCESS]\n");
}

void	wf_window_destroy(t_my_window *w)
{
  my_putstr(1, "Destroying window... ");
  free(w->buffer->pixels);
  my_putstr(1, "freed pixels, ");
  free(w->buffer);
  my_putstr(1, "freed framebuffer, ");
  sfTexture_destroy(w->tex);
  sfSprite_destroy(w->sprite);
  my_putstr(1, "freed texture and sprite, ");
  sfRenderWindow_destroy(w->window);
  my_putstr(1, "destroyed window [SUCCESS]\n");
}

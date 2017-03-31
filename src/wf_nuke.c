/*
** wf_nuke.c for wolf3d in /home/arthur/delivery/wolf3d
**
** Made by Arthur Philippe
** Login   <arthur@epitech.net>
**
** Started on  Wed Dec 28 14:27:39 2016 Arthur Philippe
** Last update Sun Jan 15 12:37:40 2017 Arthur Philippe
*/

#include "wolf.h"
#include "wolf_messages.h"
#include <stdlib.h>
#include <unistd.h>

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
  if (!env)
    return ;
  my_putstr(STDOUT_FILENO, HINT_NUKE_ENV);
  while (i < env->map_size && env->map[i])
    {
      my_putstr(STDOUT_FILENO, ".");
      free(env->map[i]);
      i += 1;
    }
  free(env->map[i]);
  my_putstr(STDOUT_FILENO, HINT_NUKE_CONTENT);
  free(env->map);
  my_putstr(STDOUT_FILENO, HINT_NUKE_PTR);
  free(env);
  my_putstr(STDOUT_FILENO, HINT_NUKE_ENV_ENDED);
}

void	wf_window_destroy(t_my_window *w)
{
  if (!w)
    return ;
  my_putstr(STDOUT_FILENO, HINT_NUKE_WDW);
  free(w->buffer->pixels);
  my_putstr(STDOUT_FILENO, HINT_NUKE_PIXELS);
  free(w->buffer);
  my_putstr(STDOUT_FILENO, HINT_NUKE_FRAMEBUFFER);
  sfTexture_destroy(w->tex);
  sfSprite_destroy(w->sprite);
  my_putstr(STDOUT_FILENO, HINT_NUKE_TEX);
  sfRenderWindow_destroy(w->window);
  my_putstr(STDOUT_FILENO, HINT_NUKE_WDW_ENDED);
}

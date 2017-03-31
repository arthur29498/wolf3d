/*
** wf_game_parser.c for wolf3d in /home/arthur/delivery/wolf3d
**
** Made by Arthur Philippe
** Login   <arthur@epitech.net>
**
** Started on  Wed Dec 28 10:48:22 2016 Arthur Philippe
** Last update Sun Jan 15 19:51:54 2017 Arthur Philippe
*/

#include "wolf.h"
#include "wolf_files.h"
#include "wolf_messages.h"
#include <stdlib.h>
#include <unistd.h>

int		wolf_single_map(char *map_name)
{
  t_my_window	*w;
  t_env		*env;

  w = malloc(sizeof(t_my_window));
  env = malloc(sizeof(t_env));
  if (w && env && !wf_set_env(map_name, env) && !wf_start_window(w, env))
    {
      my_putstr(STDOUT_FILENO, HINT_LAUNCHED_GAME);
      while (sfRenderWindow_isOpen(w->window))
	{
	  wf_loop(w, env);
	  if (is_posf_a_wall(env->player.pos, env->map) == 4)
	    return (wolf_terminate_game(env, w, 1));
	  if (is_posf_a_wall(env->player.pos, env->map) == 3)
	    sfRenderWindow_close(w->window);
	}
    }
  else
    return (1);
  wf_window_destroy(w);
  my_env_destroy(env);
  return (0);
}

int		wolf_campaign_mode()
{
  t_my_window	*w;
  t_env		*env;
  char		*file;
  int		out;

  w = malloc(sizeof(t_my_window));
  env = malloc(sizeof(t_env));
  file = wf_get_next_file_name();
  if (file && w && env && !wf_set_env(file, env) && !wf_start_window(w, env))
    {
      free(file);
      while (sfRenderWindow_isOpen(w->window) && env)
	{
	  if (wf_loop(w, env))
	    out = 2;
	  if (is_posf_a_wall(env->player.pos, env->map) == 4)
	    return (wolf_terminate_game(env, w, 1));
	  if (is_posf_a_wall(env->player.pos, env->map) == 3)
	    env = wf_load_next_map(env);
	}
    }
  else
    return (1);
  return (wolf_terminate_game(env, w, out));
}

int		wolf_terminate_game(t_env *env, t_my_window *w, int status)
{
  wf_window_destroy(w);
  my_env_destroy(env);
  if (status == 1)
    display_file(G_OVER_FILE);
  return (status);
}

t_env		*wf_load_next_map(t_env *env)
{
  char		*file;

  my_env_destroy(env);
  file = wf_get_next_file_name();
  if (file)
    {
      display_file(N_STAGE_FILE);
      my_putstr(STDOUT_FILENO, HINT_NEXT_LEVEL);
      my_putstr(STDOUT_FILENO, file);
      my_putstr(STDOUT_FILENO, "\n");
      env = malloc(sizeof(t_env));
      if (env && !wf_set_env(file, env))
	{
	  free(file);
	  return (env);
	}
    }
  return (0);
}

char		*wf_get_next_file_name()
{
  static int	i = -1;
  int		i2;
  char		*buffer;
  char		*file_name;

  i2 = 0;
  buffer = file_to_buffer(CAMPAIGN_CONF);
  if (!buffer)
    return ((char *) 0);
  file_name = malloc(sizeof(char) * 80);
  if (!file_name)
    return (file_name);
  while (buffer[++i] && buffer[i] != '\n' && i2 < 64)
    {
      file_name[i2] = buffer[i];
      i2 += 1;
    }
  free (buffer);
  file_name[i2] = 0;
  return (file_name);
}

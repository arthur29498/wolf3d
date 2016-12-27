/*
** main.c for wolf3d in /home/arthur/delivery/wolf3d
**
** Made by Arthur Philippe
** Login   <arthur@epitech.net>
**
** Started on  Mon Dec 19 14:25:15 2016 Arthur Philippe
** Last update Sat Dec 24 14:13:25 2016 Arthur Philippe
*/

#include "wolf.h"
/*
int	main(int ac, char **av)
{
  char	*buffer;

  if (ac != 2)
    return (EXIT_ARG_COUNT);
  buffer = file_to_buffer(av[1]);
  if (buffer)
    {
      free(buffer);
      return ((wf_start_window()) ? EXIT_FAILURE : EXIT_SUCCES);
    }
  return (EXIT_FAIL);
}
*/

int	main(void)
{
  t_env	*env;

  env = malloc(sizeof(t_env));
  if (env)
    {
      if (wf_set_env(MAP_NAME, env) == -1)
	return (84);
      disp_map(env);
      wf_start_window(env);
      my_env_destroy(env);
    }
  else
    return (84);
  return (0);
}

void	my_env_destroy(t_env *env)
{
  int	i;

  i = 0;
  while (env->map[i])
    {
      free(env->map[i]);
      i += 1;
    }
  free(env->map[i]);
  free(env->map);
  free(env);
}

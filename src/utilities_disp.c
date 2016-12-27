/*
** utilities_disp.c for wold3d in /home/arthur/delivery/wolf3d
**
** Made by Arthur Philippe
** Login   <arthur@epitech.net>
**
** Started on  Fri Dec 23 13:16:56 2016 Arthur Philippe
** Last update Fri Dec 23 14:59:21 2016 Arthur Philippe
*/

#include "wolf.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] && str[i] != -1)
    i += 1;
  return (i);
}

int	my_putstr(int fd, char *str)
{
  return (write(fd, str, my_strlen(str)));
}

void	disp_map(t_env *env)
{
  int	y;

  y = 0;
  while (env->map[y])
    {
      my_putstr(1, env->map[y]);
      my_putstr(1, "\n");
      y += 1;
    }
}

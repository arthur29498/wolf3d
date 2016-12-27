/*
** wf_errors.c for wolf3d in /home/arthur/delivery/wolf3d
**
** Made by Arthur Philippe
** Login   <arthur@epitech.net>
**
** Started on  Mon Dec 19 13:48:42 2016 Arthur Philippe
** Last update Wed Dec 21 21:29:53 2016 Arthur Philippe
*/

#include "wolf.h"

void	*wf_fd_errors(int e, char *f_name)
{
  my_putstr(2, "wolf3d: ");
  my_putstr(2, f_name);
  my_putstr(2, ": ");
  if (e == 2)
    my_putstr(2, "No such file or directory\n");
  else if (e == 13)
    my_putstr(2, "Permission denied\n");
  else if (e == 21)
    my_putstr(2, "Is a directory\n");
  else
    my_putstr(2, "Unexpected file related error\n");
  return (0);
}

void	*wf_usage_error(int e)
{
  my_putstr(2, "wolf3d: usage error: ");
  if (e == 1)
    my_putstr(2, MSG_INVALID_MAP);
  return (0);
}

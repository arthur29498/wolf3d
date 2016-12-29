/*
** wf_errors.c for wolf3d in /home/arthur/delivery/wolf3d
**
** Made by Arthur Philippe
** Login   <arthur@epitech.net>
**
** Started on  Mon Dec 19 13:48:42 2016 Arthur Philippe
** Last update Wed Dec 28 14:11:48 2016 Arthur Philippe
*/

#include "wolf.h"

void	*wf_fd_errors(int e, char *f_name)
{
  my_putstr(2, MSG_FD_ERROR);
  my_putstr(2, f_name);
  my_putstr(2, ": ");
  if (e == 2)
    my_putstr(2, MSG_MISSING_FILE);
  else if (e == 13)
    my_putstr(2, MSG_PERMISSION);
  else if (e == 21)
    my_putstr(2, MSG_IS_DIR);
  else
    my_putstr(2, MSG_UNKNOWN);
  return (0);
}

void	*wf_usage_error(int e)
{
  my_putstr(2, MSG_FC_ERROR);
  if (e == 1)
    my_putstr(2, MSG_INVALID_MAP);
  return (0);
}

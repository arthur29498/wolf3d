/*
** wf_errors.c for wolf3d in /home/arthur/delivery/wolf3d
**
** Made by Arthur Philippe
** Login   <arthur@epitech.net>
**
** Started on  Mon Dec 19 13:48:42 2016 Arthur Philippe
** Last update Wed Jan 11 11:02:10 2017 Arthur Philippe
*/

#include "wolf.h"
#include "wolf_messages.h"
#include <unistd.h>

void	*wf_fd_errors(int e, char *f_name)
{
  my_putstr(STDERR_FILENO, MSG_FD_ERROR);
  my_putstr(STDERR_FILENO, f_name);
  my_putstr(STDERR_FILENO, ": ");
  if (e == 2)
    my_putstr(STDERR_FILENO, MSG_MISSING_FILE);
  else if (e == 13)
    my_putstr(STDERR_FILENO, MSG_PERMISSION);
  else if (e == 21)
    my_putstr(STDERR_FILENO, MSG_IS_DIR);
  else
    my_putstr(STDERR_FILENO, MSG_UNKNOWN);
  return (0);
}

void	*wf_usage_error(int e)
{
  my_putstr(STDERR_FILENO, MSG_FC_ERROR);
  if (e == 1)
    my_putstr(STDERR_FILENO, MSG_INVALID_MAP);
  return (0);
}

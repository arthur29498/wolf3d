/*
** main.c for wolf3d in /home/arthur/delivery/wolf3d
**
** Made by Arthur Philippe
** Login   <arthur@epitech.net>
**
** Started on  Mon Dec 19 14:25:15 2016 Arthur Philippe
** Last update Sun Jan 15 19:47:50 2017 Arthur Philippe
*/

#include "wolf.h"
#include "wolf_files.h"
#include "wolf_messages.h"
#include <unistd.h>

int	main(int ac, char **av)
{
  if (ac > 1)
    {
      if (av[1][0] == '-' && av[1][1] == 'h')
	display_file(HELPER_FILE);
      else
	{
	  if (!wolf_single_map(av[1]))
	    my_putstr(STDOUT_FILENO, HINT_EXITED);
	}
      return (EXIT_SUCCESS);
    }
  if (!wolf_campaign_mode())
    {
      display_file(WINNING_FILE);
      my_putstr(STDOUT_FILENO, HINT_WIN);
    }
  else
    my_putstr(STDOUT_FILENO, HINT_EXITED);
  return (EXIT_SUCCESS);
}

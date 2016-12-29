/*
** main.c for wolf3d in /home/arthur/delivery/wolf3d
**
** Made by Arthur Philippe
** Login   <arthur@epitech.net>
**
** Started on  Mon Dec 19 14:25:15 2016 Arthur Philippe
** Last update Thu Dec 29 16:44:24 2016 Arthur Philippe
*/

#include "wolf.h"

int	main(int ac, char **av)
{
  if (ac > 1)
    {
      if (av[1][0] == '-' && av[1][1] == 'h')
	display_file(HELPER_FILE);
      else
	{
	  if (!wolf_single_map(av[1]))
	    {
	      display_file(WINNING_FILE);
	      my_putstr(1, HINT_WIN);
	    }
	  else
	    my_putstr(1, HINT_EXITED);
	}
      return (EXIT_SUCCESS);
    }
  if (!wolf_campaign_mode())
    {
      display_file(WINNING_FILE);
      my_putstr(1, HINT_WIN);
    }
  else
    my_putstr(1, HINT_EXITED);
  return (EXIT_SUCCESS);
}

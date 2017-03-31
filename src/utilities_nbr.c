/*
** utilities_nbr.c for wolf3d in /home/arthur/delivery/wolf3d/src/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Fri Jan 13 13:34:11 2017 Arthur Philippe
** Last update Fri Jan 13 13:53:39 2017 Arthur Philippe
*/

#include "wolf.h"

int	my_getnbr(char *str)
{
  int	nb;
  int	sign;

  nb = 0;
  sign = 1;
  if (*str == '-')
    {
      sign = -1;
      str += 1;
    }
  while (*str && *str != '\n' && *str != -1)
    {
      if (*str >= '0' && *str <= '9')
	nb = (nb * 10) + ((*str) - 48);
      str += 1;
    }
  return (sign * nb);
}

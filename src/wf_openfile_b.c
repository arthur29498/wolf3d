/*
** wf_openfile_b.c for wolf3d in /home/arthur/delivery/wolf3d/src/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Fri Jan 13 10:26:06 2017 Arthur Philippe
** Last update Fri Jan 13 16:23:38 2017 Arthur Philippe
*/

#include "wolf.h"
#include "wolf_files.h"
#include <stdlib.h>

sfVector2f	wf_place_player(char **map)
{
  int		x;
  int		y;
  sfVector2f	player;

  x = 0;
  y = 0;
  player.x = 0;
  player.y = 0;
  while (map[y] && map[y][x] && !player.x)
    {
      if (map[y][x] == 'p')
	{
	  player.x = (float) x + 0.5;
	  player.y = (float) y + 0.5;
	  map[y][x] = '0';
	}
      x += 1;
      if (!map[y][x])
	{
	  y += 1;
	  x = 0;
	}
    }
  my_putstr(1, "player placed ");
  return ((!player.x) ? DEFAULT_SPAWN : player);
}

void	wf_conf_file(t_env *envir)
{
  char	*buffer;
  int	i;

  buffer = file_to_buffer(CONFIG_FILE);
  i = 0;
  if (buffer)
    {
      envir->fov = my_getnbr(buffer);
      while (buffer[i++] != '\n');
      envir->night = my_getnbr(&buffer[i]);
      free(buffer);
    }
  else
    {
      envir->fov = FOV;
      envir->night = 0;
    }
}

/*
** wf_openfile.c for wolf3d in /home/arthur/delivery/wolf3d
**
** Made by Arthur Philippe
** Login   <arthur@epitech.net>
**
** Started on  Mon Dec 19 14:01:10 2016 Arthur Philippe
** Last update Fri Jan 13 15:01:19 2017 Arthur Philippe
*/

#include "wolf.h"
#include "wolf_messages.h"
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char	*file_to_buffer(char *file_name)
{
  int	file_descriptor;
  int	size;
  char	*buffer;

  buffer = malloc(sizeof(char) * BUFFER_SIZE);
  if (!buffer)
    return ((char *) 0);
  my_memset(buffer, BUFFER_SIZE);
  errno = 0;
  file_descriptor = open(file_name, O_RDONLY);
  if (file_descriptor == -1)
    return ((char *) wf_fd_errors(errno, file_name));
  size = read(file_descriptor, buffer, BUFFER_SIZE - 1);
  if (size < 0)
    return ((char *) wf_fd_errors(errno, file_name));
  buffer[BUFFER_SIZE - 1] = 0;
  close(file_descriptor);
  return (buffer);
}

void	display_file(char *file)
{
  char	*buffer;

  buffer = file_to_buffer(file);
  my_putstr(STDOUT_FILENO, buffer);
  free(buffer);
}

int	wf_map_size(char *buffer)
{
  int	i;
  int	lines;
  int	cols;

  i = -1;
  lines = 0;
  cols = 0;
  while (buffer[++i] && buffer[i] != -1)
    {
      if (buffer[i] == '\n')
	{
	  lines += 1;
	  my_putstr(STDOUT_FILENO, ".");
	  cols = (!cols) ? i : cols;
	}
      else if (buffer[i] != '0' && buffer[i] != '1'
	       && buffer[i] != 'w' && buffer[i] != 't' && buffer[i] != 'p')
	{
	  wf_usage_error(1);
	  return (0);
	}
    }
  my_putstr(STDOUT_FILENO, " ");
  return ((lines + 1 != cols && lines != cols) ? 0 : cols);
}

char	**wf_set_map(char *buffer, int size)
{
  char	**map;
  int	ix;
  int	iy;
  int	ib;

  ix = 0;
  iy = 0;
  ib = -1;
  if (!(map = malloc(sizeof(char *) * (size + 5))))
    return (0);
  while (buffer[++ib] && buffer[ib] != -1)
    {
      if (!(map[iy] = malloc(sizeof(char) * (size + 5))))
	return (0);
      while (buffer[ib] == '1' || buffer[ib] == '0'
	     || buffer[ib] == 'w' || buffer[ib] == 't' || buffer[ib] == 'p')
	map[iy][ix++] = buffer[ib++];
      map[iy][ix] = 0;
      iy += (buffer[ib] == '\n') ? 1 : 0;
      ix = (buffer[ib] == '\n') ? 0 : ix + 1;
    }
  if (!(map[iy + 1] = malloc(sizeof(char) * (size + 1))))
    return (0);
  map[iy] = 0;
  return (map);
}

int	wf_set_env(char *file, t_env *envir)
{
  char	*buffer;

  my_putstr(STDOUT_FILENO, HINT_LOADING_MAP);
  buffer = file_to_buffer(file);
  if (buffer && envir
      && (envir->map_size = wf_map_size(buffer))
      && (envir->map = wf_set_map(buffer, envir->map_size)))
    {
      my_putstr(1, "finnishing up, ");
      envir->player.pos = wf_place_player(envir->map);
      envir->player.heading = (float) 0;
      free(buffer);
      wf_conf_file(envir);
    }
  else
    {
      my_putstr(STDOUT_FILENO, HINT_FAIL);
      return (-1);
    }
  my_putstr(STDOUT_FILENO, HINT_DONE);
  return (0);
}

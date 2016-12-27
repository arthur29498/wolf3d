/*
** raycast.c for wolf3d in /home/arthur/delivery/wolf3d
**
** Made by Arthur Philippe
** Login   <arthur@epitech.net>
**
** Started on  Tue Dec 20 13:12:08 2016 Arthur Philippe
** Last update Tue Dec 27 15:28:54 2016 Arthur Philippe
*/

#include "wolf.h"

/*
** at the beginning there was nothing
*/
/*
float		raycast(sfVector2f pos,
			float direction,
			int **map,
			sfVector2i mapSize)
{
  sfVector2f	tmp;

  tmp = pos;
}
*/

t_raycast	raycast_ultimate(sfVector2f pos,
		      float direction,
		      char **map)
{
  sfVector2f	tmp;
  sfVector2f	prev;
  t_raycast	out;
  float		delta_dist;

  tmp = pos;
  out.dist = 0;
  delta_dist = 0;
  while (!is_posf_a_wall(tmp, map))
    {
      tmp = move_forward(pos, direction, out.dist);
      out.dist += 0.01;
    }
  while (is_posf_a_wall(prev, map) && delta_dist < 0.1)
    {
      prev = move_forward(pos, direction, out.dist - delta_dist);
      delta_dist += 0.0002;
    }
  out.dist = (out.dist - delta_dist) + 0.0002;
  if (is_posf_a_wall(tmp, map) == 1)
    out.color = wf_wall_color(tmp, prev);
  else
    out.color = sfGreen;
  return (out);
}

int		is_posf_a_wall(sfVector2f posf, char **map)
{
  int		x;
  int		y;

  x = (int) posf.x;
  y = (int) posf.y;
  if (x < 0 || y < 0 || !map[y] || !map[y][x])
    return (2);
  else if (map[y][x] == '1')
    return (1);
  else if (map[y][x] == 'w')
    return (3);
  return (0);
}

sfColor		wf_wall_color(sfVector2f wall, sfVector2f prev)
{
  sfVector2i	wall_t;
  sfVector2i	prev_t;
  sfVector2i	delta;

  wall_t.x = (int) wall.x;
  wall_t.y = (int) wall.y;
  prev_t.x = (int) prev.x;
  prev_t.y = (int) prev.y;
  delta.x = prev_t.x - wall_t.x;
  delta.y = prev_t.y - wall_t.y;
  if (delta.y == -1)
    return (WALL_COLOR_N);
  else if (delta.x == 1)
    return (WALL_COLOR_S);
  else if (delta.x == -1)
    return (WALL_COLOR_W);
  else if (delta.y == 1)
    return (WALL_COLOR_E);
  return (sfRed);
}

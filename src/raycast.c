/*
** raycast.c for wolf3d in /home/arthur/delivery/wolf3d
**
** Made by Arthur Philippe
** Login   <arthur@epitech.net>
**
** Started on  Tue Dec 20 13:12:08 2016 Arthur Philippe
** Last update Mon Jan  9 20:57:27 2017 Arthur Philippe
*/

#include "wolf.h"

/*
** at the beginning there was nothing
*/

float		raycast(sfVector2f pos,
			float direction,
			int **map,
			sfVector2i mapSize)
{
  sfVector2f	tmp;
  float		dist;

  tmp = pos;
  dist = 0;
  while (tmp.x < mapSize.x && tmp.y < mapSize.y
	 && map[(int) tmp.y][(int) tmp.x])
    {
      tmp = move_forward(pos, direction, dist);
      dist += 0.02;
    }
  return (dist);
}

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
  while (!is_posf_a_wall(tmp, map) || is_posf_a_wall(tmp, map) == 4
	 || is_posf_a_wall(tmp, map) == 3)
    {
      tmp = move_forward(pos, direction, out.dist);
      out.dist += 0.02;
    }
  while (is_posf_a_wall(prev, map) == 1 && delta_dist < 0.1)
    {
      prev = move_forward(pos, direction, out.dist - delta_dist);
      delta_dist += 0.001;
    }
  out.dist = (out.dist - delta_dist) + 0.001;
  if (is_posf_a_wall(tmp, map) == 1)
    out.color = wf_wall_color(tmp, prev, map);
  else
    out.color = sfRed;
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
  else if (map[y][x] == 't')
    return (4);
  return (0);
}

sfColor		wf_wall_color(sfVector2f wall, sfVector2f prev, char **map)
{
  sfVector2i	wall_t;
  sfVector2i	prev_t;
  sfVector2i	delta;

  if (is_posf_a_wall(prev, map) == 3)
    return (sfGreen);
  wall_t.x = (int) wall.x;
  wall_t.y = (int) wall.y;
  prev_t.x = (int) prev.x;
  prev_t.y = (int) prev.y;
  delta.x = prev_t.x - wall_t.x;
  delta.y = prev_t.y - wall_t.y;
  if (delta.y == -1 && !delta.x)
    return (WALL_COLOR_N);
  else if (delta.x == 1 && !delta.y)
    return (WALL_COLOR_S);
  else if (delta.x == -1 && !delta.y)
    return (WALL_COLOR_W);
  else if (delta.y == 1 && !delta.x)
    return (WALL_COLOR_E);
  return (WALL_COLOR_C);
}

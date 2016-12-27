/*
** wf_interact.c for wolf3d in /home/arthur/delivery/wolf3d
**
** Made by Arthur Philippe
** Login   <arthur@epitech.net>
**
** Started on  Mon Dec 19 13:59:37 2016 Arthur Philippe
** Last update Tue Dec 27 14:50:56 2016 Arthur Philippe
*/

#include "wolf.h"

int		wf_interact(t_env *env, sfEvent event)
{
  sfVector2f	np;

  np = env->player.pos;
  if (event.key.code == sfKeyE)
    env->player.heading += 5;
  else if (event.key.code == sfKeyA)
    env->player.heading -= 5;
  else if (event.key.code == sfKeyZ)
    np = move_forward(np, env->player.heading, 0.1);
  else if (event.key.code == sfKeyS)
    np = move_forward(np, env->player.heading, -0.1);
  else if (event.key.code == sfKeyQ)
    np = move_forward(np, env->player.heading - 90, 0.1);
  else if (event.key.code == sfKeyD)
    np = move_forward(np, env->player.heading + 90, 0.1);
  else
    return (0);
  printf("new heading is %f @ (%f %f)\n", env->player.heading, np.x, np.y);
  if (!is_posf_a_wall(np, env->map))
    {
      env->player.pos = np;
      return (1);
    }
  return (0);
}

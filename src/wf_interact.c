/*
** wf_interact.c for wolf3d in /home/arthur/delivery/wolf3d
**
** Made by Arthur Philippe
** Login   <arthur@epitech.net>
**
** Started on  Mon Dec 19 13:59:37 2016 Arthur Philippe
** Last update Sun Jan 15 09:33:07 2017 Arthur Philippe
*/

#include "wolf.h"

int		wf_interact(t_env *env)
{
  sfVector2f	np;

  np = env->player.pos;
  if (KEY_PRSD(sfKeyZ) == sfTrue)
    np = move_forward(np, env->player.heading, 0.05);
  if (KEY_PRSD(sfKeyS) == sfTrue)
    np = move_forward(np, env->player.heading, -0.05);
  if (KEY_PRSD(sfKeyQ) == sfTrue)
    np = move_forward(np, env->player.heading - 90, 0.05);
  if (KEY_PRSD(sfKeyD) == sfTrue)
    np = move_forward(np, env->player.heading + 90, 0.05);
  if ((env->player.pos.x != np.x || env->player.pos.y != np.y)
      && (!is_posf_a_wall(np, env->map)
	  || is_posf_a_wall(np, env->map) == 3
	  || is_posf_a_wall(np, env->map) == 4))
    {
      env->player.pos = np;
      wf_turn(env);
      return (1);
    }
  return (0);
}

int	wf_turn(t_env *env)
{
  if (KEY_PRSD(sfKeyE) == sfTrue)
    env->player.heading += 2.5;
  else if (KEY_PRSD(sfKeyA) == sfTrue)
    env->player.heading -= 2.5;
  else if (KEY_PRSD(sfKeyW) == sfTrue)
    env->fov += (env->fov + 2 <= 1080) ? 2 : 0;
  else if (KEY_PRSD(sfKeyX) == sfTrue)
    env->fov -= (env->fov - 2 >= 40) ? 2 : 0;
  else
    return (0);
  return (1);
}

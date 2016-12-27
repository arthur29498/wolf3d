/*
** wf_core.c for wold3d in /home/arthur/delivery/wolf3d
**
** Made by Arthur Philippe
** Login   <arthur@epitech.net>
**
** Started on  Tue Dec 20 10:35:18 2016 Arthur Philippe
** Last update Tue Dec 27 13:55:08 2016 Arthur Philippe
*/

#include "wolf.h"

void		wf_loop(t_my_window *w, t_env *env)
{
  sfEvent	event;
  int		status;

  status = 0;
  while (sfRenderWindow_pollEvent(w->window, &event))
    {
      if (event.type == sfEvtClosed)
	sfRenderWindow_close(w->window);
      if (event.type == sfEvtKeyPressed)
	status = wf_interact(env, event);
    }
  sfRenderWindow_clear(w->window, sfCyan);
  if (status)
    {
      wf_reset_pixels(w->buffer);
      wf_rendering_parser(w, env);
      status = 0;
    }
  sfRenderWindow_drawSprite(w->window, w->sprite, NULL);
  sfTexture_updateFromPixels(w->tex, w->buffer->pixels, SC_W, SC_H, 0, 0);
  sfRenderWindow_display(w->window);
}

void		wf_rendering_parser(t_my_window *w, t_env *env)
{
  float		ray;
  float		step;
  t_raycast	ray_c;
  int		col;

  ray = env->player.heading - FOV / 2;
  ray_c.dist = 0;
  step = (float) FOV / w->buffer->width;
  col = 0;
  while (ray < env->player.heading + FOV / 2)
    {
      ray_c = raycast_ultimate(env->player.pos, ray, env->map);
      ray_c.dist = wf_convert_in_height(ray_c.dist, w, env->player.heading, ray);
      wf_draw_col(col, w, ray_c.dist, ray_c.color);
      ray += step;
      col += 1;
    }
}

void		wf_draw_col(int col,
			    t_my_window *w,
			    float height,
			    sfColor wall_color)
{
  sfVector2i	max;
  sfVector2i	min;
  sfVector2i	top;

  max.x = col;
  min.x = col;
  top.x = col;
  max.y = (w->buffer->height / 2) + (height / 2);
  min.y = (w->buffer->height / 2) - (height / 2);
  top.y = w->buffer->height;
  my_draw_ordinate(w->buffer, min, max, wall_color);
  my_draw_ordinate(w->buffer, max, top , GROUND_COLOR);
}

float		wf_convert_in_height(float dist,
				     t_my_window *w,
				     float heading,
				     float ray)
{
  float		height;

  dist *= cosf(wf_degres_to_rads(heading) - wf_degres_to_rads(ray));
  height = w->buffer->height / dist;
  height = (height > w->buffer->height) ? w->buffer->height : height;
  return (height);
}

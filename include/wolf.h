/*
** wolf.h for wolf3d in /home/arthur/delivery/wolf3d
**
** Made by Arthur Philippe
** Login   <arthur@epitech.net>
**
** Started on  Mon Dec 19 14:17:18 2016 Arthur Philippe
** Last update Tue Dec 27 13:54:25 2016 Arthur Philippe
*/

#ifndef WOLF3D_H_
# define WOLF3D_H_

# define EXIT_SUCCES	0
# define EXIT_FAIL	84
# define EXIT_ARG_COUNT	84

# define BUFFER_SIZE	10000
# define SC_W		1280
# define SC_H		720
# define WINDOW_NAME	"WOLF 3D: Find your way out! :D"
# define MAP_NAME	"map.w3"

# include <SFML/Graphics/RenderWindow.h>
# include <SFML/Graphics/Sprite.h>
# include <SFML/Graphics/Texture.h>

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>
# include <stdio.h>

# define MSG_INVALID_MAP	"Map is invalid\n"

# define FOV		60
# define DEFAULT_SPAWN	((sfVector2f) {1.5, 1.5})
# define WALL_COLOR_N	((sfColor) {192, 192, 192, 255})
# define WALL_COLOR_S	((sfColor) {169, 169, 169, 255})
# define WALL_COLOR_E	((sfColor) {128, 128, 128, 255})
# define WALL_COLOR_W	((sfColor) {105, 105, 105, 255})
# define GROUND_COLOR	((sfColor) {47, 79, 79, 255})

/*
** custom structures
*/
typedef struct		s_my_framebuffer
{
  sfUint8		*pixels;
  int			width;
  int			height;
}			t_my_framebuffer;

typedef struct		s_my_window
{
  sfRenderWindow	*window;
  sfSprite		*sprite;
  sfTexture		*tex;
  t_my_framebuffer	*buffer;
}			t_my_window;

typedef struct		s_player
{
  sfVector2f		pos;
  float			heading;
}			t_player;

typedef struct		s_env
{
  char			**map;
  int			map_size;
  t_player		player;
}			t_env;

typedef struct		s_raycast
{
  float			dist;
  sfColor		color;
}			t_raycast;

/*
** mandatory implemtation : put_pixel, draw_line, move_forward and raycast.
*/
void		my_put_pixel(t_my_framebuffer *,
			     int,
			     int,
			     sfColor);

void		my_draw_line(t_my_framebuffer *,
			     sfVector2i,
			     sfVector2i,
			     sfColor);
void		my_draw_ordinate(t_my_framebuffer *,
			         sfVector2i,
			         sfVector2i,
			         sfColor);
sfVector2f	move_forward(sfVector2f pos, float direction, float distance);
sfVector2f	move_forward_rev(sfVector2f, float, float);
float		wf_degres_to_rads(float degres);
t_raycast	raycast_ultimate(sfVector2f, float, char **);
sfColor		wf_wall_color(sfVector2f, sfVector2f);

/*
** window related implements.
*/
int				wf_start_window(t_env *);
void				wf_loop(t_my_window *, t_env *);
sfRenderWindow			*create_window(char *, int, int);
t_my_framebuffer		*my_framebuffer_create(int, int);
void				my_framebuffer_destroy(t_my_framebuffer *);

/*
** data management
*/
char				*file_to_buffer(char *);
int				wf_map_size(char *buffer);
char				**wf_set_map(char *buffer, int size);
int				wf_set_env(char *file, t_env *envir);
void				my_env_destroy(t_env *);

/*
** Error management
*/
void				*wf_fd_errors(int, char *);
void				*wf_usage_error(int e);

/*
** Utilities
*/
int				my_putstr(int, char *);
void				disp_map(t_env *);

/*
** Rendering
*/
void	wf_rendering_parser(t_my_window *, t_env *);
int	is_posf_a_wall(sfVector2f, char **);
void	wf_draw_col(int, t_my_window *, float, sfColor);
float	wf_convert_in_height(float, t_my_window *, float, float);
void	wf_reset_pixels(t_my_framebuffer *);

/*
** Interaction
*/
int	wf_interact(t_env *, sfEvent);

#endif /* !WOLF3D_H_ */

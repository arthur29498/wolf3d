/*
** wolf.h for wolf3d in /home/arthur/delivery/wolf3d
**
** Made by Arthur Philippe
** Login   <arthur@epitech.net>
**
** Started on  Mon Dec 19 14:17:18 2016 Arthur Philippe
** Last update Sun Jan 15 20:30:12 2017 Arthur Philippe
*/

#ifndef WOLF3D_H_
# define WOLF3D_H_

# define EXIT_SUCCESS	0
# define EXIT_FAIL	84
# define EXIT_ARG_COUNT	84
# define BUFFER_SIZE	10000
# define SC_W		1024
# define SC_H		768
# define WINDOW_NAME	"WOLF3D, Get out of the maze!"
# define MAP_NAME	"map.w3"
# include <SFML/Graphics/RenderWindow.h>
# include <SFML/Graphics/Sprite.h>
# include <SFML/Graphics/Texture.h>
# define FOV		60
# define DEFAULT_SPAWN	((sfVector2f) {1.5, 1.5})
# define NIGHT_COLOR	((sfColor) {0, 10, 23, 255})
# define NIGHT_GROUND	((sfColor) {0, 11, 24, 150})
# define KEY_PRSD(X)	sfKeyboard_isKeyPressed(X)
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
  int			night;
  int			fov;
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
float		degres_to_rads(float degres);
t_raycast	raycast_ultimate(sfVector2f, float, char **);
sfColor		wf_wall_color(sfVector2f, sfVector2f, char **);
/*
** window related implements.
*/
int				wf_start_window(t_my_window *, t_env *);
int				wf_loop(t_my_window *, t_env *);
sfRenderWindow			*create_window(char *, int, int);
t_my_framebuffer		*my_framebuffer_create(int, int);
void				wf_window_destroy(t_my_window *);
void				wf_refresh_window(t_my_window *,
						  t_env *,
						  int *);
/*
** data management
*/
char				*file_to_buffer(char *);
int				wf_map_size(char *buffer);
char				**wf_set_map(char *buffer, int size);
int				wf_set_env(char *file, t_env *envir);
void				wf_conf_file(t_env *);
void				my_env_destroy(t_env *);
void				display_file(char *);
void				my_memset(char *, int);
sfVector2f			wf_place_player(char **map);
int				my_getnbr(char *);
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
void	wf_draw_col(int, t_my_window *, t_raycast *, int);
float	wf_convert_in_height(float, t_my_window *, t_env *, float);
void	wf_reset_pixels(t_my_framebuffer *);
void	wf_darken(t_raycast *);
/*
** Interaction
*/
int	wf_interact(t_env *);
int	wf_turn(t_env *);
int	wolf_single_map(char *);
/*
** Campaign
*/
int	wolf_campaign_mode(void);
t_env	*wf_load_next_map(t_env *);
char	*wf_get_next_file_name(void);
int	wolf_terminate_game(t_env *, t_my_window *, int status);

#endif /* !WOLF3D_H_ */

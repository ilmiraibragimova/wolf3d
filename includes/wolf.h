

#ifndef WOLF_H
# define WOLF_H
# include <unistd.h>
# include "libft.h"
# include <SDL2/SDL.h>
#include "../frameworks/SDL2.framework/Headers/SDL_surface.h"
#include "../frameworks/SDL2.framework/Headers/SDL_video.h"
#include "../frameworks/SDL2.framework/Headers/SDL_render.h"
# include <math.h>
#include <fcntl.h>
#include <stdio.h>
# define HEIGHT 600
# define WIDTH 896


typedef struct s_vec2
{
	double x;
	double y;
}				t_vec2;

typedef struct s_ray
{
	t_vec2 point0;
	t_vec2 dir;
	t_vec2 delta;
	t_vec2 point1;
	int width;
	t_vec2 step;
	int insect;
	int mx;
	int my;
	int side;
	double dist;
	int h;
	double light;
	int tex_h;
	int tex_x;
	int block;
}				t_ray;


typedef struct s_cam
{
	t_vec2 dir;
	t_vec2 pln;
	double cam;

}				t_cam;

typedef struct s_map
{
	int sizex;
	int sizey;
	int **z;
	int y0;

}	t_map;

typedef struct	s_w
{
	t_map		map;
	int			name;
	double		x;
	double		y;
	t_ray 		ray;
	double 		player_x;
	double 		player_y;
	t_cam		cam;
	SDL_Window		*win;
	SDL_Renderer	*ren;
	SDL_Surface		*screen;
	SDL_Texture		*texture;
	SDL_Surface		*s;
	SDL_Surface		*s1;
	SDL_Surface		*s2;
	SDL_Surface		*s3;
	SDL_Surface		*s4;
	SDL_Surface 	*floor;
	SDL_Surface 	*sky;
	double floor_x;
	double floor_y;
	double wall_x;

}				t_w;

void			ft_usage(int a);
int	ft_read_wolf(char *argv, t_w *w);
void ft_ray_cast(t_w *w);
void	loop_for_image(t_w *w);
void	for_keys(t_w *w, const uint8_t *keys, SDL_Event event);
void init_cam(t_w *w);
void load_textures(t_w *w);
void		draw_wall(t_w *w, int x, int start, int end);
void		draw_floor(t_w *w, int x, int start, int end);
void draw_sky(t_w *w);
void		put_pixel(SDL_Surface *surf, const int x, const int y,
							   const int color);
Uint32		read_pixel(SDL_Surface *surface, const int x, const int y);
void	ft_put_error(char *s);
#endif

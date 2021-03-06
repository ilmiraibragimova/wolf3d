/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 21:00:53 by lseema            #+#    #+#             */
/*   Updated: 2021/05/16 18:16:24 by ilmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# include "libft.h"
# include <unistd.h>
# include <SDL2/SDL.h>
# include "../frameworks/SDL2.framework/Headers/SDL_surface.h"
# include "../frameworks/SDL2.framework/Headers/SDL_video.h"
# include "../frameworks/SDL2.framework/Headers/SDL_render.h"
# include "../frameworks/SDL2_mixer.framework/Headers/SDL_mixer.h"
# include <math.h>
# include <fcntl.h>
# define HEIGHT 504
# define WIDTH 896

typedef struct s_vec2
{
	double	x;
	double	y;
}			t_vec2;

typedef struct s_ray
{
	t_vec2	point0;
	t_vec2	dir;
	t_vec2	delta;
	t_vec2	point1;
	int		width;
	int		insect;
	int		mx;
	int		my;
	int		side;
	double	dist;
	int		h;
	double	light;
	int		tex_h;
	int		tex_x;
	int		block;
	int		sky_x;
}			t_ray;

typedef struct s_cam
{
	t_vec2	dir;
	t_vec2	pln;
	double	cam;
}			t_cam;

typedef struct s_map
{
	int		sizex;
	int		sizey;
	int		**z;
	int		y0;
}			t_map;

typedef struct s_sounds
{
	Mix_Chunk	*move;
	Mix_Chunk	*wood_door;
	Mix_Chunk	*metal_door;
	Mix_Music	*birds_chill;
	Mix_Music	*dark_loops;
	Mix_Music	*asian_loop;
}				t_sounds;

typedef struct s_w
{
	t_map			map;
	t_sounds		sounds;
	int				name;
	double			x;
	double			y;
	t_ray			ray;
	double			player_x;
	double			player_y;
	t_cam			cam;
	SDL_Window		*win;
	SDL_Renderer	*ren;
	SDL_Surface		*screen;
	SDL_Texture		*texture;
	SDL_Surface		**s;
	SDL_Surface		*s1;
	SDL_Surface		*s2;
	SDL_Surface		*s3;
	SDL_Surface		*s4;
	SDL_Surface		*s5;
	SDL_Surface		*s6;
	SDL_Surface		*floor;
	SDL_Surface		*floor1;
	SDL_Surface		*floor2;
	SDL_Surface		*sky;
	double			floor_x;
	double			floor_y;
	double			wall_x;

}					t_w;

void	ft_usage(int a);
int		ft_read_wolf(char *argv, t_w *w);
int		ft_check(int fd, char **line, t_w *w);
void	ft_ray_cast(t_w *w);
void	manage_ray_insect(t_w *w);
int		find_side_num(t_w *w);
void	loop_for_image(t_w *w);
void	for_keys(t_w *w, const uint8_t *keys);
void	init_cam(t_w *w);
void	load_textures(t_w *w);
void	draw_wall(t_w *w, int x, int start, int end);
void	draw_floor(t_w *w, int x, int end);
void	draw_sky(t_w *w);
void	put_pixel(SDL_Surface *surf, const int x, const int y,
			const int color);
Uint32	read_pixel(SDL_Surface *surface, const int x, const int y);
void	ft_put_error(char *s);
int		init_audio(t_w *w);
void	audio_handle(t_w *w, const uint8_t *keys);
void	free_audio(t_w *w);
#endif

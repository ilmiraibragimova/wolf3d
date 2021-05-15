/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 22:14:37 by lseema            #+#    #+#             */
/*   Updated: 2021/05/15 22:14:39 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	draw_wall(t_w *w, int x, int start, int end)
{
	int		y;
	int		d;
	double	tex_y;

	y = start;
	while (y < end)
	{
		d = y * w->s1->h - HEIGHT * w->s1->h / 2 + w->ray.h * w->s1->h / 2;
		tex_y = ((d * (double)w->s1->h / 4) / w->ray.h) / w->s1->h;
		((int *)(w->screen->pixels))[y * WIDTH + x] = ((int *)(w->s1->pixels)) \
			[(int)tex_y * w->s1->pitch +\
			(int)w->ray.tex_x * w->s1->format->BytesPerPixel];
		y++;
	}
}

static void	find_wall(t_w *w)
{
	if ((w->ray.side == 0 ) && w->ray.dir.x > 0)
	{
		w->floor_x = w->ray.mx;
		w->floor_y = w->ray.my + w->wall_x;
	}
	 else if (w->ray.side == 0 && w->ray.dir.x < 0)
	{
		w->floor_x = w->ray.mx + 1;
		w->floor_y = w->ray.my + w->wall_x;
	}
	else if (w->ray.side == 1 && w->ray.dir.y > 0)
	{
		w->floor_x = w->ray.mx + w->wall_x;
		w->floor_y = w->ray.my;
	}
	else
	{
		w->floor_x = w->ray.mx + w->wall_x;
		w->floor_y = w->ray.my + 1.0;
	}
}

void	draw_floor(t_w *w, int x, int end)
{
	int		y;
	int		tex_y;
	double	floorx;
	double	floory;
	double	floor_part;

	find_wall(w);
	y = end;
	while (y < HEIGHT)
	{
		floor_part = (HEIGHT / (2.0 * y - HEIGHT)) / w->ray.dist;
		if (floor_part > 1)
			floor_part = 1;
		floorx = floor_part * w->floor_x +\
			(1.0 - floor_part) * w->player_x;
		floory = floor_part * w->floor_y +\
			(1.0 - floor_part) * w->player_y;
		w->ray.tex_x = (int)(floorx * (double)w->floor->w) % w->floor->w;
		tex_y = (int)(floory * (double)w->floor->h) % w->floor->h;
		put_pixel(w->screen, x, y, (read_pixel(w->floor, (int)w->ray.tex_x, \
			(int)tex_y)));
		y++;
	}
}

void	draw_sky(t_w *w)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT / 2)
		{
			put_pixel(w->screen, x, y,
				read_pixel(w->sky, (int)(x + w->ray.sky_x) % w->sky->w, \
					(int)(y) % w->sky->h));
			y++;
		}
		x++;
	}
}

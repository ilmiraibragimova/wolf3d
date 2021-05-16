/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 20:04:12 by lseema            #+#    #+#             */
/*   Updated: 2021/05/16 03:30:36 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int	ft_insect(t_w *w)
{
	int	in;

	in = 0;
	w->ray.mx = (int)w->player_x;
	w->ray.my = (int)w->player_y;
	while (!in)
	{
		if (w->ray.point1.x < w->ray.point1.y)
		{
			w->ray.point1.x += w->ray.delta.x;
			w->ray.mx += w->ray.point0.x;
			w->ray.side = 0;
		}
		else
		{
			w->ray.point1.y += w->ray.delta.y;
			w->ray.my += w->ray.point0.y;
			w->ray.side = 1;
		}
		if (w->ray.mx < 0 || w->ray.my < 0 || w->ray.mx >= w->map.sizex \
			|| w->ray.mx >= w->map.sizey)
			break ;
		in = w->map.z[w->ray.mx][w->ray.my];
	}
	return (in);
}

int	find_side_num(t_w *w)
{
	if (w->ray.side == 1)
	{
		if ((w->ray.point0.x == -1 && w->ray.point0.y == -1) || \
			(w->ray.point0.x == 1 && w->ray.point0.y == -1))
			return (1);
		if ((w->ray.point0.x == -1 && w->ray.point0.y == 1) || \
			(w->ray.point0.x == 1 && w->ray.point0.y == 1))
			return (2);
	}
	if ((w->ray.point0.x == -1 && w->ray.point0.y == -1) || \
		(w->ray.point0.x == -1 && w->ray.point0.y == 1))
		return (3);
	return (4);
}

void	ray_dir_set(t_w *w)
{
	w->ray.dir.x = w->cam.dir.x + w->cam.pln.x * w->cam.cam;
	w->ray.dir.y = w->cam.dir.y + w->cam.pln.y * w->cam.cam;
	w->ray.delta = (t_vec2){.x = sqrt((w->ray.dir.y * w->ray.dir.y) \
		/ (w->ray.dir.x * w->ray.dir.x) + 1), .y = sqrt((w->ray.dir.x \
		* w->ray.dir.x) / (w->ray.dir.y * w->ray.dir.y) + 1)};
	if (w->ray.dir.x < 0)
	{
		w->ray.point0.x = -1;
		w->ray.point1.x = (w->player_x - (int)w->player_x) * w->ray.delta.x;
	}
	else
	{
		w->ray.point0.x = 1;
		w->ray.point1.x = ((int)w->player_x - w->player_x + 1) * w->ray.delta.x;
	}
	if (w->ray.dir.y < 0)
	{
		w->ray.point0.y = -1;
		w->ray.point1.y = (w->player_y - (int)w->player_y) * w->ray.delta.y;
	}
	else
	{
		w->ray.point0.y = 1;
		w->ray.point1.y = ((int)w->player_y - w->player_y + 1) * w->ray.delta.y;
	}
}

void	ft_ray_cast_1(t_w *w)
{
	ray_dir_set(w);
	w->ray.insect = ft_insect(w);
	if (w->ray.insect)
	{
		if (w->ray.side)
			w->ray.dist = (w->ray.my - w->player_y + (1 - w->ray.point0.y) / 2) \
				/ w->ray.dir.y;
		else
			w->ray.dist = (w->ray.mx - w->player_x + (1 - w->ray.point0.x) / 2) \
				/ w->ray.dir.x;
		if (w->ray.dist < 0.5)
			w->ray.dist = 1;
		w->ray.h = (int)(HEIGHT / w->ray.dist);
		manage_ray_insect(w);
		if (w->ray.side == 1)
			w->wall_x = w->player_x + w->ray.dist * w->ray.dir.x;
		else
			w->wall_x = w->player_y + w->ray.dist * w->ray.dir.y;
		w->wall_x -= floor(w->wall_x);
		w->ray.tex_x = (int)(w->wall_x * (double)w->s1->w / 4);
		if (w->ray.side == 0 && w->ray.dir.x > 0)
			w->ray.tex_x = (double)w->s1->w / 4 - w->ray.tex_x - 1;
		if (w->ray.side == 1 && w->ray.dir.y < 0)
			w->ray.tex_x = (double)w->s1->w / 4 - w->ray.tex_x - 1;
	}
}

void	ft_ray_cast(t_w *w)
{
	int	x;
	int	start;
	int	end;

	x = 0;
	draw_sky(w);
	while (x < WIDTH)
	{
		w->cam.cam = 2.0f * x / WIDTH - 1.0f;
		ft_ray_cast_1(w);
		start = (int)(HEIGHT * 0.5 - w->ray.h * 0.5);
		if (w->ray.insect == 5)
			start = (int)(HEIGHT * 0.5 - w->ray.h * 0.5);
		end = start + w->ray.h;
		if (start < 0)
			start = 0;
		if (end > HEIGHT - 1)
			end = HEIGHT - 1;
		draw_wall(w, x, start, end);
		draw_floor(w, x, end);
		x++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 20:04:12 by lseema            #+#    #+#             */
/*   Updated: 2021/05/15 22:18:52 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	init_cam(t_w *w)
{
	w->cam.dir = (t_vec2){-1, 0};
	w->cam.pln = (t_vec2){0, 0.9};
	w->ray.side = 0;
}

int	ft_insect(t_w *w)
{
	int		in;
	int		dist;

	in = 0;
	dist = 0;
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
		dist++;
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

void	ft_ray_cast_1(t_w *w, int x)
{
	w->cam.cam = 2.0f * x / WIDTH - 1.0f;
	w->ray.dir.x = w->cam.dir.x + w->cam.pln.x * w->cam.cam;
	w->ray.dir.y = w->cam.dir.y + w->cam.pln.y * w->cam.cam;
	w->ray.delta.x = sqrt((w->ray.dir.y * w->ray.dir.y) / (w->ray.dir.x * w->ray.dir.x) + 1);
	w->ray.delta.y = sqrt((w->ray.dir.x * w->ray.dir.x) / (w->ray.dir.y * w->ray.dir.y) + 1);
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
	w->ray.insect = 0;
	w->ray.insect = ft_insect(w);
	if (w->ray.insect)
	{
		if (w->ray.side)
			w->ray.dist = (w->ray.my - w->player_y + (1 - w->ray.point0.y) / 2) / w->ray.dir.y;
		else
			w->ray.dist = (w->ray.mx - w->player_x + (1 - w->ray.point0.x) / 2) / w->ray.dir.x;
		if (w->ray.dist < 0.5)
			w->ray.dist = 1;
		w->ray.h = (int)(HEIGHT / w->ray.dist);
		w->floor = w->floor2;
		if (w->ray.insect == 1 && find_side_num(w) == 1)
			w->s1 = w->s[1];
		else if (w->ray.insect == 1 && find_side_num(w) == 2)
			w->s1 = w->s[2];
		else if (w->ray.insect == 1 && find_side_num(w) == 3)
			w->s1 = w->s[3];
		else if (w->ray.insect == 1 && find_side_num(w) == 4)
			w->s1 = w->s[4];
		else if (w->ray.insect == 2 && find_side_num(w) == 1)
			w->s1 = w->s[5];
		else if (w->ray.insect == 2 && find_side_num(w) == 2)
			w->s1 = w->s[6];
		else if (w->ray.insect == 2 && find_side_num(w) == 3)
			w->s1 = w->s[7];
		else if (w->ray.insect == 2 && find_side_num(w) == 4)
			w->s1 = w->s[8];
		else if (w->ray.insect == 3 && find_side_num(w) == 1)
			w->s1 = w->s[6];
		else if (w->ray.insect == 3 && find_side_num(w) == 2)
			w->s1 = w->s[7];
		else if (w->ray.insect == 3 && find_side_num(w) == 3)
			w->s1 = w->s[8];
		else if (w->ray.insect == 3 && find_side_num(w) == 4)
			w->s1 = w->s[9];
		else if (w->ray.insect == 5 && find_side_num(w) == 1)
			w->s1 = w->s[12];
		else if (w->ray.insect == 5 && find_side_num(w) == 2)
			w->s1 = w->s[13];
		else if (w->ray.insect == 5 && find_side_num(w) == 3)
			w->s1 = w->s[14];
		else if (w->ray.insect == 5 && find_side_num(w) == 4)
			w->s1 = w->s[15];
		else if (w->ray.insect == 9)
			w->s1 = w->s[11];
		else if (w->ray.insect == 4)
			w->s1 = w->s[0];
		else if (w->ray.insect == 5)
			w->s1 = w->s[12];
		else if (w->ray.insect == 6 && find_side_num(w) == 1)
			w->s1 = w->s[11];
		else if (w->ray.insect == 6 && find_side_num(w) == 2)
			w->s1 = w->s[0];
		else if (w->ray.insect == 6 && find_side_num(w) == 3)
			w->s1 = w->s[6];
		else if (w->ray.insect == 6 && find_side_num(w) == 4)
			w->s1 = w->s[7];
		else if (w->ray.insect == 8)
		{
			w->s1 = w->s[10];
			if (find_side_num(w) == 4)
				w->floor = w->floor1;
		}
		else if (w->ray.insect == 7)
		{
			w->s1 = w->s[16];
			w->floor = w->floor1;
		}
		else if (w->ray.insect == 10)
		{
			w->s1 = w->s[17];
			w->floor = w->floor1;
		}
		else if (w->ray.insect == 11)
		{
			w->s1 = w->s[17];
			if (find_side_num(w) == 2 || find_side_num(w) == 4)
				w->floor = w->floor1;
		}
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
		ft_ray_cast_1(w, x);
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

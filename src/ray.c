/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 21:00:40 by lseema            #+#    #+#             */
/*   Updated: 2021/05/15 22:17:19 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static double	hypotenuse(double adj, double opp)
{
	return (sqrt(pow(adj, 2) + pow(opp, 2)));
}

static double	raytrace_x(t_w *w, t_vec2 *r, t_map *map, double dir)
{
	double	len;
	double	sn;
	char	one;

	sn = sin(dir);
	r->x = w->player_x;
	r->y = w->player_y;
	if (sn > 0.001 || sn < -0.001)
	{
		if (w->map.z[(int)w->player_y][(int)w->player_x])
			return (0);
		one = 0;
		if (sn < 0.0F)
			one = 1;
		r->y = (int)w->player_y + one;
		r->x = w->player_x - (r->y - w->player_y) / tan(dir);
		len = (1.0 + 2.0 * -(double)one) / tan(dir);
		while (r->x < map->sizex - 1 && r->x > 1 && \
			r->y < map->sizey && r->y > 0)
		{
			if ((map->z[(int)r->y - !one][(int)r->x]))
				return (hypotenuse(r->x - w->player_x, r->y - w->player_x));
			r->y += -1.0 + 2.0 * (double)one;
			r->x += len;
		}
	}
	return ((double)(map->sizex * map->sizey));
}

static double	raytrace_y(t_w *w, t_vec2 *r, t_map *map, double dir)
{
	double	len;
	double	cn;
	char	one;

	cn = cos(dir);
	r->x = w->player_x;
	r->y = w->player_y;
	if (cn > 0.001 || cn < -0.001)
	{
		if (map->z[(int)w->player_y][(int)w->player_x])
			return (0);
		one = 0;
		if (cn > 0.0F)
			one = 1;
		r->x = (int)w->player_x + one;
		r->y = w->player_y - (r->x - w->player_x) * tan(dir);
		len = (1.0 + 2.0 * -(double)one) * tan(dir);
		while (r->y < map->sizey - 1 && r->y > 1 && \
			r->x < map->sizex && r->x > 0)
		{
			if (map->z[(int)r->y][(int)r->x - !one])
				return (hypotenuse(r->x - w->player_x, r->y - w->player_y));
			r->x += -1.0 + 2.0 * (double)one;
			r->y += len;
		}
	}
	return ((double)(map->sizex * map->sizey));
}

void	raytrace(t_w *w, double dir)
{
	t_vec2	x;
	t_vec2	y;
	double	dist_x;
	double	dist_y;

	dist_x = raytrace_x(w, &x, &w->map, dir);
	dist_y = raytrace_y(w, &y, &w->map, dir);
	if (dist_x < dist_y)
	{
		w->ray = (t_ray){
			.point0 = x,
			.dist = dist_x,
			.block = w->map.z[(int)x.y - (sin(dir) > 0.0)][(int)x.x]
		};
		w->ray.side = 3;
		if (sin(dir) < 0.0)
			w->ray.side = 1;
	}
	else
	{
		w->ray = (t_ray){
			.point0 = y,
			.dist = dist_y,
			.block = w->map.z[(int)y.y][(int)y.x - (cos(dir) < 0.0)]
		};
		w->ray.side = 4;
		if (cos(dir) > 0.0)
			w->ray.side = 2;
	}
}

void	ft_ray_cast(t_w *w)
{
	const double	fov = M_PI / 2.3;
	const double	step = fov / WIDTH;
	int32_t			i;
	double			angle;
	t_ray			ray;

	i = 0;
	while (i < WIDTH)
	{
		angle = w->player_angle + fov / 2 - step * i;
		raytrace(w, angle);
		w->ray.dist *= cos(fov / 2 - step * i);
		if (ray.dist > 0)
			w->ray.h = (int)(HEIGHT / w->ray.dist);
		else
			w->ray.h = 10000;
		draw_wall(w, i, w->ray.dist);
		i++;
	}
}

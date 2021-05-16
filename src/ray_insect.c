/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_insect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 03:28:56 by lseema            #+#    #+#             */
/*   Updated: 2021/05/16 03:29:10 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	manage_ray_insect3(t_w *w)
{
	if (w->ray.insect == 6 && find_side_num(w) == 4)
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
}

void	manage_ray_insect2(t_w *w)
{
	if (w->ray.insect == 3 && find_side_num(w) == 4)
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
	else
		manage_ray_insect3(w);
}

void	manage_ray_insect(t_w *w)
{
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
	else
		manage_ray_insect2(w);
}

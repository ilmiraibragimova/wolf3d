/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 17:19:21 by ilmira            #+#    #+#             */
/*   Updated: 2021/05/16 07:46:20 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	up(t_w *w)
{
	if (!(w->map.z[(int)(w->player_x + w->cam.dir.x * .7)][(int)(w->player_y)]))
		w->player_x = w->player_x + w->cam.dir.x * .07;
	if (!(w->map.z[(int)(w->player_x)] \
		[(int)(w->player_y + w->cam.dir.y * .05)]))
		w->player_y = w->player_y + w->cam.dir.y * .07;
	if ((int)w->player_y != 12 || ((int)w->player_x < 8 ||\
		(int)w->player_x > 10))
		w->map.z[9][12] = 9;
	if ((int)w->player_y != 3 || ((int)w->player_x < 7 ||\
		w->player_x > 9.9))
		w->map.z[8][3] = 8;
}

void	down(t_w *w)
{
	if (!(w->map.z[(int)(w->player_x - w->cam.dir.x * 1)][(int)w->player_y]))
		w->player_x = w->player_x - w->cam.dir.x * .05;
	if (!(w->map.z[(int)w->player_x][(int)(w->player_y - w->cam.dir.y * 1)]))
		w->player_y = w->player_y - w->cam.dir.y * .05;
	if ((int)w->player_y != 12 || ((int)w->player_x < 8 ||\
		(int)w->player_x > 10))
		w->map.z[9][12] = 9;
	if ((int)w->player_y != 3 || ((int)w->player_x < 7 ||\
		w->player_x > 9.9))
		w->map.z[8][3] = 8;
}

void	vec_rotate(t_vec2 *v, float theta)
{
	t_vec2	t;

	theta *= M_PI / 180;
	t.x = v->x * cos(theta) + v->y * -sin(theta);
	t.y = v->x * sin(theta) + v->y * cos(theta);
	v->x = t.x;
	v->y = t.y;
}

void	rotate_cam(t_w *w, const uint8_t *keys)
{
	if (keys[SDL_SCANCODE_LEFT])
	{
		vec_rotate(&w->cam.dir, 0.5);
		vec_rotate(&w->cam.pln, 0.5);
		w->ray.sky_x -= 5;
	}
	if (keys[SDL_SCANCODE_RIGHT])
	{
		vec_rotate(&w->cam.dir, -0.5);
		vec_rotate(&w->cam.pln, -0.5);
		w->ray.sky_x += 5;
	}
	if (keys[SDL_SCANCODE_UP])
		up(w);
	if (keys[SDL_SCANCODE_DOWN])
		down(w);
	if (keys[SDL_SCANCODE_O])
	{
		if (w->map.z[9][12] == 9 && (int)w->player_y == 12 && \
			((int)w->player_x == 10 || (int)w->player_x == 8))
			w->map.z[9][12] = 0;
		else if (w->map.z[8][3] == 8 && (int)w->player_y == 3 && ((w->player_x \
			>= 9.6 && w->player_x <= 9.9) || (int)w->player_x == 7))
			w->map.z[8][3] = 0;
	}
}

void	for_keys(t_w *w, const uint8_t *keys)
{
	rotate_cam(w, keys);
	audio_handle(w, keys);
	ft_ray_cast(w);
	w->texture = SDL_CreateTextureFromSurface(w->ren, w->screen);
	SDL_FreeSurface(w->screen);
	SDL_RenderCopy(w->ren, w->texture, NULL, NULL);
	SDL_DestroyTexture(w->texture);
	SDL_RenderPresent(w->ren);
	SDL_RenderClear(w->ren);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmira <ilmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 17:19:21 by ilmira            #+#    #+#             */
/*   Updated: 2021/05/15 17:02:43 by ilmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	vec_rotate(t_vec2 *v, float theta)
{
	t_vec2	t;

	theta *= M_PI / 180;
	t.x = v->x * cos(theta) + v->y * -sin(theta);
	t.y = v->x * sin(theta) + v->y * cos(theta);
	v->x = t.x;
	v->y = t.y;
}

/*void	key(t_rt *r, const uint8_t *keys)
{
	if (keys[SDL_SCANCODE_S])
		screenshot(r);
	if (keys[SDL_SCANCODE_Z])
		r->filter = r->filter < 4 ? r->filter + 1 : 0;
	if (keys[SDL_SCANCODE_B])
		r->blur = r->blur < 1 ? r->blur + 1 : 0;
	if (keys[SDL_SCANCODE_P])
		r->stereoscopy = r->stereoscopy < 1 ? r->stereoscopy + 1 : 0;
	if (keys[SDL_SCANCODE_M])
		r->menu = r->menu < 1 ? r->menu + 1 : 0;
}*/

void	rotate_cam(t_w *w, const uint8_t *keys)
{
	if (keys[SDL_SCANCODE_LEFT]) {
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
	if (keys[SDL_SCANCODE_UP]) //|| keys[SDL_SCANCODE_DOWN])
	{
		if (!(w->map.z[(int)(w->player_x + w->cam.dir.x * 0.7)][(int)(w->player_y)])) {
			w->player_x = w->player_x + w->cam.dir.x * .07;
			//printf("x%f y%f\n", w->player_x, w->player_y);
			//printf("map%d ", (w->map.z[(int)(w->player_x + w->cam.dir.x * .5)][(int) w->player_y]));
		}
		if (!(w->map.z[(int)(w->player_x)][(int)(w->player_y + w->cam.dir.y * 0.05)]))
		w->player_y = w->player_y + w->cam.dir.y * .07;
		if ((int)w->player_y != 12 || ((int)w->player_x < 8 ||\
		(int)w->player_x > 10))
		w->map.z[9][12] = 9;
		//	w->map.z[9][11] = 7;}
		if ((int)w->player_y != 3 || ((int)w->player_x < 7 ||\
		w->player_x > 9.9))
			w->map.z[8][3] = 8;

	}
	if (keys[SDL_SCANCODE_DOWN]) //|| keys[SDL_SCANCODE_DOWN])
	{
		if (!(w->map.z[(int)(w->player_x -  w->cam.dir.x * 1)][(int)w->player_y]))// &&\
		//(w->player_x -  w->cam.dir.x * .5) > 0 &&\
		//(w->player_x -  w->cam.dir.x * .5) < w->map.sizey - 1)
		{
			w->player_x = w->player_x - w->cam.dir.x * .05;
			//printf("x%f y%f\n", w->player_x, w->player_y);
			//printf("map%d ",(w->map.z[(int) (w->player_x - w->cam.dir.x * .5)][(int) w->player_y]));
		}
		//if ((w->player_y -  w->cam.dir.y * .5) < (w->map.sizex - 1) &&\
		//(w->player_y -  w->cam.dir.y * .5) > 0 &&
		if (!(w->map.z[(int)w->player_x][(int)(w->player_y -  w->cam.dir.y * 1)])) {
			w->player_y = w->player_y - w->cam.dir.y * .05;
			//printf("x%f y%f\n", w->player_x, w->player_y);
			//printf("map%d ", (w->map.z[(int)w->player_x][(int) (w->player_y - w->cam.dir.y * .5)]));
		}
		if ((int)w->player_y != 12 || ((int)w->player_x < 8 ||\
		(int)w->player_x > 10))
			w->map.z[9][12] = 9;
		//	w->map.z[9][11] = 7;}
		if ((int)w->player_y != 3 || ((int)w->player_x < 7 ||\
		w->player_x > 9.9))
			w->map.z[8][3] = 8;
	}
	if  (keys[SDL_SCANCODE_O])
	{
		printf("x%f y%f\n", w->player_x, w->player_y);
		printf("map%d ", (w->map.z[(int)w->player_x][(int) (w->player_y - w->cam.dir.y * .5)]));
		if (w->map.z[9][12] == 9 && ((int)w->player_x == 10 || (int)w->player_x == 8) && (int)w->player_y == 12)
			w->map.z[9][12] = 0;
			//w->map.z[9][11] = 9;}
		else if (w->map.z[8][3] == 8 && ((w->player_x >= 9.6 && w->player_x <=9.9) || (int)w->player_x == 7) && (int)w->player_y == 3)
			 	w->map.z[8][3] = 0;
	}

		//w->plaey_x = keys[SDL_SCANCODE_UP] ? \
		//w->plaey_x - 1 : w->plaey_x + 1;
		//w->plaey_x += (w->plaey_x * 0.01);
		//w->plaey_x = 11.5;
				//printf("plx%f", w->plaey_x);
		//w->plaey_y += w->plaey_y * 0.01;


	//}
	//if (keys[SDL_SCANCODE_Q] || keys[SDL_SCANCODE_W])
	//{
		//w->cam.point.z = keys[SDL_SCANCODE_Q] ? \
		//w->cam.point.z - 0.5 : r->cam.point.z + 0.5;

	//}
	//key(r, keys);
}

void	for_keys(t_w *w, const uint8_t *keys, SDL_Event event)
{
	//if (event.type == SDL_KEYUP){
	rotate_cam(w, keys);
	//printf("x%f y%f\n", w->player_x, w->player_y);
	//printf("map%d ", (w->map.z[(int)w->player_x][(int) (w->player_y - w->cam.dir.y * .5)]));
	ft_ray_cast(w);
	//if (r->menu)
		//menu(r);
	//else

	{
		//for_menu(r);
		w->texture = SDL_CreateTextureFromSurface(w->ren, w->screen);
		SDL_FreeSurface(w->screen);
		SDL_RenderCopy(w->ren, w->texture, NULL, NULL);
		SDL_DestroyTexture(w->texture);
	}
	SDL_RenderPresent(w->ren);
	SDL_RenderClear(w->ren);
}

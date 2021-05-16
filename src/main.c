/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 20:44:42 by lseema            #+#    #+#             */
/*   Updated: 2021/05/16 07:46:00 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_init(t_w *w)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		w->win = SDL_CreateWindow("RT", SDL_WINDOWPOS_UNDEFINED, \
			SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
		if (w->win)
		{
			w->ren = SDL_CreateRenderer(w->win, -1, SDL_RENDERER_SOFTWARE);
			if (w->ren)
			{
				w->screen = SDL_GetWindowSurface(w->win);
				if (w->screen && init_audio(w))
					return ;
			}
		}
	}
	ft_putendl(SDL_GetError());
	exit(1);
}

void	init_cam(t_w *w)
{
	w->cam.dir = (t_vec2){-1, 0};
	w->cam.pln = (t_vec2){0, 0.9};
	w->ray.side = 0;
}

void	clean_s(t_w *w)
{
	int	i;

	i = -1;
	while (++i < 6)
		SDL_FreeSurface(w->s[i]);
}

void	loop_for_image(t_w *w)
{
	SDL_Event		event;
	const uint8_t	*keys;

	keys = SDL_GetKeyboardState(NULL);
	while (1)
	{
		SDL_PollEvent(&event);
		if ((SDL_QUIT == event.type) || (SDL_KEYDOWN == event.type && \
		SDL_SCANCODE_ESCAPE == event.key.keysym.scancode))
		{
			free_audio(w);
			SDL_FreeSurface(w->floor);
			clean_s(w);
			free(w->s);
			SDL_FreeSurface(w->sky);
			SDL_FreeSurface(w->screen);
			SDL_DestroyWindow(w->win);
			SDL_Quit();
			exit(0);
		}
		if ((keys[SDL_SCANCODE_LEFT] || keys[SDL_SCANCODE_RIGHT] ||\
			keys[SDL_SCANCODE_UP] || keys[SDL_SCANCODE_DOWN] ||\
			keys[SDL_SCANCODE_O]) && SDL_KEYDOWN == event.type)
			for_keys(w, keys);
	}
}

int	main(int argc, char **argv)
{
	t_w	*w;

	if (argc != 2)
		ft_usage(1);
	w = (t_w *) malloc(sizeof(t_w));
	if (!w)
		ft_usage(5);
	if (!(ft_read_wolf(argv[1], w)))
		ft_usage(2);
	ft_init(w);
	init_cam(w);
	w->ray.sky_x = 0;
	load_textures(w);
	ft_ray_cast(w);
	w->texture = SDL_CreateTextureFromSurface(w->ren, w->screen);
	SDL_RenderCopy(w->ren, w->texture, NULL, NULL);
	SDL_RenderPresent(w->ren);
	SDL_DestroyTexture(w->texture);
	loop_for_image(w);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 20:44:42 by lseema            #+#    #+#             */
/*   Updated: 2021/05/15 22:27:58 by lseema           ###   ########.fr       */
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
				if (w->screen)
					return ;
			}
		}
	}
	ft_putendl(SDL_GetError());
	exit(1);
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

void	ft_usage(int a)
{
	if (a == 1)
		write(1, "usage: wolf3d input_file\n", 22);
	if (a == 2)
		write(1, "error in reading input", 22);
	if (a == 3)
		write(1, "error opening file", 18);
	if (a == 4)
		write(1, "not a valid file", 16);
	if (a == 5)
		write(1, "error allocating memory", 23);
	if (a == 6)
		write(1, "error closing file", 18);
	exit(0);
}

void	ft_put_error(char *s)
{
	write(1, s, ft_strlen(s));
	write(1, "\n", 1);
	exit(1);
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

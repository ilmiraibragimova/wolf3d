/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 19:41:06 by lseema            #+#    #+#             */
/*   Updated: 2021/05/15 22:17:27 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	put_pixel(SDL_Surface *s, const int x, const int y, int color)
{
	Uint32		*pixels;

	pixels = (Uint32 *)s->pixels;
	if (x >= 0 && y >= 0 && x < s->w && y < s->h)
		pixels[y * s->w + x] = color;
}

Uint32	read_pixel(SDL_Surface *s, const int x, const int y)
{
	int		bpp;
	uint8_t	*p;

	bpp = s->format->BytesPerPixel;
	p = (uint8_t *)s->pixels + y * s->pitch + x * bpp;
	if (bpp == 1)
		return (*p);
	if (bpp == 2)
		return (*(uint16_t *)p);
	if (bpp == 3)
	{
		if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
			return (p[0] << 16 | p[1] << 8 | p[2]);
		else
			return (p[0] | p[1] << 8 | p[2] << 16);
	}
	if (bpp == 4)
		return (*(uint32_t *)p);
	return (0);
}

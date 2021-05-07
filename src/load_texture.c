#include "wolf.h"

SDL_Surface *load_tex(char *path, t_w *w)
{
	SDL_Surface	*s;
	SDL_Surface	*tex;

	if ((s = SDL_LoadBMP(path)) == NULL)
		ft_put_error("Loading texture error");
	tex = SDL_ConvertSurfaceFormat(s, w->screen->format->format, 0);
	SDL_FreeSurface(s);
	return (tex);
}
void load_textures(t_w *w)
{
	int i = 0;
	w->s = malloc(sizeof(SDL_Surface) * 6);
	w->s[0] = load_tex("textures/panelka2.bmp", w);
	printf("%p\n",w->s[0]);
	w->s[1] = load_tex("textures/5c0f7953603cc.bmp", w);
	w->s[2] = load_tex("textures/metal_floor_normal.bmp", w);
	w->s[3] = load_tex("textures/beton.bmp", w);
	w->s[4] = load_tex("textures/highriseresidential0136-h.bmp", w);
	w->s[5] = load_tex("textures/5d7e976b797ea.bmp", w);
	w->floor = load_tex("textures/brick_base.bmp", w);
	w->sky = load_tex("textures/sky-5980.bmp", w);
	printf("%p",w->s[1]);
}


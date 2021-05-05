#include "wolf.h"

SDL_Surface *load_tex(SDL_Surface	*tex, char *path, t_w *w)
{
	SDL_Surface	*s;
	if ((s = SDL_LoadBMP(path)) == NULL)
		ft_put_error("Loading texture error");
	tex = SDL_ConvertSurfaceFormat(s, w->screen->format->format, 0);
	SDL_FreeSurface(s);
	return (tex);
}
void load_textures(t_w *w) {

	w->s = load_tex(w->s, "textures/panelka2.bmp", w);
	w->s1 = load_tex(w->s, "textures/brick_base.bmp", w);
	w->s2 = load_tex(w->s, "textures/metal_floor_normal.bmp", w);
	w->floor = load_tex(w->floor, "textures/bamboo_base.bmp", w);
	w->sky = load_tex(w->sky, "textures/sky-5980.bmp", w);
}


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
void load_textures(t_w *w)
{

	w->s = load_tex(w->s, "textures/panelka2.bmp", w);
	w->s1 = load_tex(w->s1, "textures/5c0f7953603cc.bmp", w);
	w->s2 = load_tex(w->s2, "textures/metal_floor_normal.bmp", w);
	w->s3 = load_tex(w->s3, "textures/beton.bmp", w);
	w->s4 = load_tex(w->s4,"textures/highriseresidential0136-h.bmp", w);
	w->floor = load_tex(w->floor, "textures/brick_base.bmp", w);
	w->sky = load_tex(w->sky, "textures/sky-5980.bmp", w);
}


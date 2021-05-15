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
	w->s = malloc(sizeof(SDL_Surface) * 18);
	w->s[7] = load_tex("textures/01.bmp", w);
	w->s[1] = load_tex("textures/5c0f7953603cc.bmp", w);
	w->s[2] = load_tex("textures/bamboo_base.bmp", w);
	w->s[3] = load_tex("textures/harshbricks_base.bmp", w);
	w->s[4] = load_tex("textures/brick_base.bmp", w);
	w->s[5] = load_tex("textures/DSC_8389.bmp", w);
	w->s[6] = load_tex("textures/DSC_8346.bmp", w);
	w->s[0] = load_tex("textures/DSC_8374.bmp", w);
	w->s[8] = load_tex("textures/DSC_8439.bmp", w);
	w->s[9] = load_tex("textures/DSC_8490.bmp", w);
	w->s[10] = load_tex("textures/2018-06-21-21-00-24.bmp", w);
	w->s[11] = load_tex("textures/2018-06-21-21-00-24.bmp", w);
	w->s[12] = load_tex("textures/banksy8.bmp", w);
	w->s[13] = load_tex("textures/banksy5.bmp", w);
	w->s[14] = load_tex("textures/benksy2.bmp", w);
	w->s[15] = load_tex("textures/banksy6.bmp", w);
	w->s[16] = load_tex("textures/hastle.bmp", w);
	//w->s[17] = load_tex("textures/highriseresidential0136-h.bmp", w);
	w->floor = load_tex("textures/brus.bmp", w);
	w->sky = load_tex("textures/sky-5980.bmp", w);
	printf("%p",w->s[1]);
}


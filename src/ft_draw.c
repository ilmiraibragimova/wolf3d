#include "wolf.h"


 void		draw_wall(t_w *w, int x, int start, int end)
{
	int		y;
	double 	tex_y;

	y = start;
	/*if (w->ray.insect == 1 && find_side_num(w) == 1)
		wall = w->s[1];
	else if (w->ray.insect == 1 && find_side_num(w) == 2)
		wall = w->s[5];
	else if (w->ray.insect == 2)
		wall = w->s[2];
	else if (w->ray.insect == 3)
		wall = w->s[3];
	else if (w->ray.insect == 4)
		wall = w->s[4];
	else
		wall = w->s[0];*/
	while (y < end) {
		//printf("w%d h%d", w->s->w, w->s->h);
		//printf("x=%d y=%d\n",(int)w->ray.tex_x,(int)tex_y);
		int d = y * w->s1->h - HEIGHT *  w->s1->h/2 + w->ray.h * w->s1->h/2;
		tex_y = ((d * (double)w->s1->h/4) / w->ray.h) / w->s1->h;
		//put_pixel(w->screen, x, y,
					 // read_pixel(wall, w->ray.tex_x, tex_y));
		//(int)(((y + HEIGHT / 2 - w->ray.h / 2) * w->s->h) /(int)w->ray.h);
		((int *)(w->screen->pixels))[y * WIDTH + x] = \
         ((int *)(w->s1->pixels))[(int)tex_y * w->s1->pitch + (int)w->ray.tex_x * w->s1->format->BytesPerPixel];
		y++;
	}
}
static void	find_wall(t_w *w)
{
	if ((w->ray.side == 0 ) && w->ray.dir.x > 0)
	{
		w->floor_x = w->ray.mx;
		w->floor_y = w->ray.my + w->wall_x;
	}
	 else if (w->ray.side == 0 && w->ray.dir.x < 0)
	{
		w->floor_x = w->ray.mx + 1;
		w->floor_y = w->ray.my + w->wall_x;
	}
	else if (w->ray.side == 1 && w->ray.dir.y > 0)
	{
		w->floor_x = w->ray.mx + w->wall_x;
		w->floor_y = w->ray.my;
	}
	else
	{
		w->floor_x = w->ray.mx + w->wall_x;
		w->floor_y = w->ray.my + 1.0;
	}
}

void		draw_floor(t_w *w, int x, int start, int end)
{
	find_wall(w);
	int y;
	y = end;
	int tex_y;
	while (y < HEIGHT)
	{
		double dist_floor = HEIGHT / (2.0 * y - HEIGHT);
		double floor_part = dist_floor / w->ray.dist;
		if (floor_part > 1)
			floor_part = 1;

		double floorx = floor_part * w->floor_x +
							  (1.0 - floor_part) * w->player_x;
		double floory = floor_part * w->floor_y +
							  (1.0 - floor_part) * w->player_y;

		w->ray.tex_x = (int)(floorx * (double)w->floor->w) %  w->floor->w;
		tex_y = (int)(floory * (double)w->floor->h) %  w->floor->h;
		//static int k = 0;
		//if ( w->ray.tex_x< 0 || tex_y < 0){
		//	printf("x= %d y= %d\n", w->ray.tex_x, tex_y);
		//	printf("wei%f %f %f\n",floor_part,w->floor_y,w->player_y);
			//printf("dist%f ", w->ray.dist);
			//k++;
		//}
		put_pixel(w->screen, x, y, (read_pixel(w->floor, (int)w->ray.tex_x, (int)tex_y)));
		y++;
	}

}

void draw_sky(t_w *w)
{
		int x = 0;
		while (x < WIDTH)
		{
			int y = 0;
			while (y < HEIGHT / 2)
			{
				//printf("%p ",w->sky);
				put_pixel(w->screen, x, y,
							   read_pixel(w->sky, (int)(x + w->ray.sky_x) % w->sky->w, (int)(y) % w->sky->h));
				//((int *)(w->screen->pixels))[y * WIDTH + x] = \
				//((int *)(w->sky->pixels))[(int)((y % 200) * w->sky->pitch) + (x % 200) * w->sky->format->BytesPerPixel];
				y++;
			}
			x++;
		}
}
#include "wolf.h"

int ft_checkline(char *line)
{
	while (*line)
	{
		if ((*line >= '0' && *line <= '9') || *line == ' ')
			line++;
		else
			return (0);
	}
	return (1);
}

int ft_countnum(char *line)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while(line[i])
	{
		if (line[i] >= '0' && line[i] <= '9')
			count++;
		i++;
	}
	return (count);

}

int ft_check(int fd, char **line, t_w *w) {
	int	count;
	int	countrow;

	count = 0;
	countrow = 0;
	while (get_next_line(fd, line))
	{
		if (*line[0] == '\0')
			break;
		if (!(ft_checkline(*line)))
			ft_usage(6);
		count = ft_countnum(*line);
		countrow++;
		ft_strdel(line);
	}
	if (count == 0)
		ft_usage(4);
	w->map.sizex = count;
	w->map.sizey = countrow - 1;
	return (1);
}

void ft_getz(int fd, char *line, t_w *w) {
	int i;
	int j;
	char **box;

	get_next_line(fd, &line);
	box = ft_strsplit(line, ' ');
	free(line);
	w->player_x = ft_atoi(box[0]) + 0.;
	w->player_y = ft_atoi(box[1]) + 0.;
	//printf("my%d\n",w->player_y);
	free(box[0]);
	free(box[1]);
	free(box);
	i = 0;
	if (!(w->map.z = (int **)malloc(sizeof(int *) * (w->map.sizey))))
		ft_usage(5);
	while (i < w->map.sizey)
	{
		j = 0;
		get_next_line(fd, &line);
		if (!(w->map.z[i] = (int *)malloc(sizeof(int) * w->map.sizex)))
			ft_usage(5);
		box = ft_strsplit(line, ' ');
		free(line);
		while (j < w->map.sizex)
		{
			w->map.z[i][j] = ft_atoi(box[j]);
			printf("%d ", w->map.z[i][j]);
			free(box[j]);
			box[j] = NULL;
			j++;

		}
		printf("\n");
		free(box);
		i++;
	}
	//free(line);
}

int	ft_read_wolf(char *argv, t_w *w)
{
	char *line;
	int fd;

	line = NULL;
	if ((fd = open(argv, O_RDWR)) < 0)
		ft_usage(3);
	if(!(ft_check(fd, &line, w)))
		ft_usage(1);
	if (close(fd) < 0)
		ft_usage (6);
	if (line != NULL)
		free(line);
	if (!(fd = open(argv, O_RDONLY)))
		ft_usage(3);
	ft_getz(fd, line, w);
	if (close(fd) < 0)
		ft_usage(6);
	return (1);
}

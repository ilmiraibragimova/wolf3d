/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 20:17:54 by lseema            #+#    #+#             */
/*   Updated: 2021/05/15 22:17:00 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int	ft_checkline(char *line)
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

int	ft_countnum(char *line)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (line[i + 1])
	{
		if (line[i] == ' ' && line[i + 1] >= '0' && line[i + 1] <= '9')
			count++;
		i++;
	}
	return (count + 1);
}

int	ft_check(int fd, char **line, t_w *w)
{
	int	count;
	int	countrow;
	int	count_prev;

	count = 0;
	countrow = 0;
	count_prev = 0;
	while (get_next_line(fd, line))
	{
		if (!(ft_checkline(*line)))
			ft_put_error("Map data is incorrect");
		count = ft_countnum(*line);
		if (count_prev != count && countrow > 1)
			ft_put_error("Map data is incorrect");
		countrow++;
		count_prev = count;
		ft_strdel(line);
	}
	if (count == 0)
		ft_usage(4);
	w->map.sizex = count;
	w->map.sizey = countrow - 1;
	return (1);
}

void	ft_getz(int fd, char **line, t_w *w)
{
	int		i;
	int		j;
	char	**box;

	get_next_line(fd, line);
	box = ft_strsplit(*line, ' ');
	free(*line);
	w->player_x = ft_atoi(box[0]) + 0.;
	w->player_y = ft_atoi(box[1]) + 0.;
	free(box[0]);
	free(box[1]);
	free(box);
	i = 0;
	w->map.z = (int **)malloc(sizeof(int *) * (w->map.sizey));
	if (!(w->map.z))
		ft_usage(5);
	while (i < w->map.sizey)
	{
		j = 0;
		get_next_line(fd, line);
		w->map.z[i] = (int *)malloc(sizeof(int) * w->map.sizex);
		if (!(w->map.z[i]))
			ft_usage(5);
		box = ft_strsplit(*line, ' ');
		free(*line);
		while (j < w->map.sizex)
		{
			w->map.z[i][j] = ft_atoi(box[j]);
			free(box[j]);
			box[j] = NULL;
			j++;
		}
		free(box);
		i++;
	}
}

int	ft_read_wolf(char *argv, t_w *w)
{
	char	*line;
	char	*line1;
	int		fd;

	line = NULL;
	line1 = NULL;
	fd = open(argv, O_RDWR);
	if (fd < 0)
		ft_usage(3);
	if (!(ft_check(fd, &line, w)))
		ft_usage(1);
	if (close(fd) < 0)
		ft_usage (6);
	if (line != NULL)
	{
		free(line);
		line = NULL;
	}
	fd = open(argv, O_RDONLY);
	if (!(fd))
		ft_usage(3);
	ft_getz(fd, &line1, w);
	if (close(fd) < 0)
		ft_usage(6);
	return (1);
}

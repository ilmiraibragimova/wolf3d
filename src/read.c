/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 20:17:54 by lseema            #+#    #+#             */
/*   Updated: 2021/05/16 02:32:21 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	parse_map(int fd, t_w *w)
{
	char	*line;
	char	**box;
	int		i;
	int		j;

	i = 0;
	while (i < w->map.sizey)
	{
		j = 0;
		get_next_line(fd, &line);
		w->map.z[i] = (int *)malloc(sizeof(int) * w->map.sizex);
		if (!(w->map.z[i]))
			ft_usage(5);
		box = ft_strsplit(line, ' ');
		free(line);
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

void	ft_getz(int fd, char **line, t_w *w)
{
	char	**box;

	get_next_line(fd, line);
	box = ft_strsplit(*line, ' ');
	free(*line);
	w->player_x = ft_atoi(box[0]) + 0.;
	w->player_y = ft_atoi(box[1]) + 0.;
	free(box[0]);
	free(box[1]);
	free(box);
	w->map.z = (int **)malloc(sizeof(int *) * (w->map.sizey));
	if (!(w->map.z))
		ft_usage(5);
	parse_map(fd, w);
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

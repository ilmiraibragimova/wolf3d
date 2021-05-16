/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 02:30:10 by lseema            #+#    #+#             */
/*   Updated: 2021/05/16 02:30:38 by lseema           ###   ########.fr       */
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hholly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:27:47 by hholly            #+#    #+#             */
/*   Updated: 2019/11/18 15:22:45 by hholly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_findn(char **line, char **s, int fd)
{
	char			*temp1;
	size_t			len;

	len = 0;
	while (s[fd][len] != '\n' && s[fd][len] != '\0')
		len++;
	if (s[fd][len] == '\n')
	{
		*line = ft_strsub(s[fd], 0, len);
		temp1 = ft_strdup(&(s[fd][len + 1]));
		free(s[fd]);
		s[fd] = temp1;
		if (s[fd][0] == '\0')
			ft_strdel(&(s[fd]));
	}
	else
	{
		*line = ft_strdup(s[fd]);
		ft_strdel(&(s[fd]));
	}
	return (1);
}

int			ftout(int ret, char **line, char *s[], int fd)
{
	if (ret < 0)
		return (-1);
	if (ret == 0 && (s[fd] == NULL || s[fd][0] == '\0'))
		return (0);
	return (ft_findn(line, s, fd));
}

int			get_next_line(const int fd, char **line)
{
	static char	*s[OPEN_MAX];
	char		buff[BUFF_SIZE + 1];
	int			ret;
	char		*temp;

	if (fd < 0 || fd > OPEN_MAX || line == NULL)
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strdup(buff);
		else
		{
			temp = ft_strjoin(s[fd], buff);
			free(s[fd]);
			s[fd] = temp;
		}
		if (ft_strchr(s[fd], '\n'))
			break ;
	}
	return (ftout(ret, line, s, fd));
}

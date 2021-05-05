/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hholly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 14:03:48 by hholly            #+#    #+#             */
/*   Updated: 2019/09/22 21:02:38 by hholly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(char const *s1, char c)
{
	size_t	count;

	count = 0;
	while (*s1)
	{
		while (*s1 == c)
			s1++;
		if (*s1)
		{
			count++;
			while (*s1 && *s1 != c)
				s1++;
		}
	}
	return (count);
}

static size_t	ft_countword(char const *s1, char c)
{
	size_t len;

	len = 0;
	while (*s1 && *s1 == c)
		s1++;
	while (*s1 && *s1 != c)
	{
		len++;
		s1++;
	}
	return (len);
}

static	char	**ft_del(char **s0, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		free(s0[i]);
		i++;
	}
	free(s0);
	return (0);
}

static char		**ft_fill(char **s0, char const *s, size_t count, char c)
{
	size_t i;
	size_t j;
	size_t len;

	i = 0;
	while (i < count)
	{
		j = 0;
		len = ft_countword(s, c);
		if (!(s0[i] = (char*)malloc((len + 1) * sizeof(char))))
			ft_del(s0, i);
		while (*s && j < len)
		{
			if (*s != c)
				s0[i][j++] = *s;
			s++;
		}
		s0[i][j] = 0;
		i++;
	}
	s0[i] = NULL;
	return (s0);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**s0;
	size_t	count;

	if (!s)
		return (NULL);
	count = ft_count(s, c);
	if (!(s0 = (char**)malloc(sizeof(char*) * (count + 1))))
		return (NULL);
	return (ft_fill(s0, s, count, c));
}

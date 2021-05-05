/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hholly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 19:10:50 by hholly            #+#    #+#             */
/*   Updated: 2019/09/22 20:28:42 by hholly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	c1;
	size_t	len;
	size_t	i;

	c1 = (char)c;
	len = ft_strlen(s);
	i = 0;
	while (i++ <= len)
	{
		if (*s == c1)
			return ((char*)s);
		s++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hholly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:28:18 by hholly            #+#    #+#             */
/*   Updated: 2019/09/22 18:43:14 by hholly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*s1;
	unsigned char		c1;
	size_t				i;

	s1 = (const unsigned char*)s;
	c1 = (unsigned char)c;
	i = 0;
	while (i++ < n)
	{
		if (*s1 == c1)
		{
			return ((void*)s);
		}
		s++;
		s1++;
	}
	return (NULL);
}

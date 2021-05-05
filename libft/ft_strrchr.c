/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hholly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 19:32:03 by hholly            #+#    #+#             */
/*   Updated: 2019/09/22 19:33:44 by hholly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	c1;
	size_t	len;
	char	*s1;

	c1 = (char)c;
	len = ft_strlen(s);
	s1 = (char*)s + len;
	while (s1 >= s)
	{
		if (*s1 == c1)
			return (s1);
		s1--;
	}
	return (NULL);
}

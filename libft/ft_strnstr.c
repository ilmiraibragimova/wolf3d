/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hholly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 19:03:48 by hholly            #+#    #+#             */
/*   Updated: 2019/09/23 19:20:25 by hholly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	lens2;
	int		i;

	lens2 = ft_strlen(s2);
	if (lens2 == 0)
		return ((char*)s1);
	i = 0;
	while (s1[i] != '\0' && i <= (int)(n - lens2))
	{
		if (!ft_strncmp(s1 + i, s2, lens2))
			return ((char*)(s1 + i));
		i++;
	}
	return (NULL);
}

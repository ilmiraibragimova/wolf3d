/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hholly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 19:23:05 by hholly            #+#    #+#             */
/*   Updated: 2019/09/22 19:23:28 by hholly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t len1;
	size_t len2;
	size_t i;
	size_t j;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = len1;
	j = 0;
	while (j < n && s2[j])
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}

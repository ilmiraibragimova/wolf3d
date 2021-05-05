/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hholly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 17:57:15 by hholly            #+#    #+#             */
/*   Updated: 2019/09/22 20:41:49 by hholly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	const char *s11;
	const char *s21;

	if (*s2 == '\0')
		return ((char*)s1);
	while (*s1)
	{
		s11 = s1;
		s21 = s2;
		while (*s21 && *s21 == *s11)
		{
			s11++;
			s21++;
		}
		if (*s21 == '\0')
			return ((char*)s1);
		else
			s1++;
	}
	return (NULL);
}

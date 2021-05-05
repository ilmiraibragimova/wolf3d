/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hholly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:58:37 by hholly            #+#    #+#             */
/*   Updated: 2019/09/22 18:40:39 by hholly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s11;
	const unsigned char	*s21;
	size_t				i;

	s11 = (const unsigned char*)s1;
	s21 = (const unsigned char*)s2;
	i = 0;
	while (i++ < n)
	{
		if (*s11 == *s21)
		{
			s11++;
			s21++;
		}
		else
			return (*s11 - *s21);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hholly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 16:02:04 by hholly            #+#    #+#             */
/*   Updated: 2019/09/23 15:25:47 by hholly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s11;
	unsigned char	*s22;

	s11 = (unsigned char*)s1;
	s22 = (unsigned char*)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (*s11 == *s22 && *s11)
	{
		if (i == n - 1)
			return (*s11 - *s22);
		s11++;
		s22++;
		i++;
	}
	return (*s11 - *s22);
}

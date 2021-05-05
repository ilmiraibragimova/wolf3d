/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hholly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 14:52:41 by hholly            #+#    #+#             */
/*   Updated: 2019/09/22 18:38:18 by hholly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dst1;
	unsigned char	*src1;
	unsigned char	c1;

	i = 0;
	c1 = (unsigned char)c;
	dst1 = (unsigned char*)dst;
	src1 = (unsigned char*)src;
	while (i < n)
	{
		if (*src1 == c1)
		{
			*dst1 = *src1;
			dst1++;
			return ((void*)dst1);
		}
		*dst1 = *src1;
		dst1++;
		src1++;
		i++;
	}
	return (NULL);
}

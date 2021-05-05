/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hholly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 19:29:18 by hholly            #+#    #+#             */
/*   Updated: 2019/09/22 18:57:17 by hholly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst1;
	unsigned char	*src1;
	size_t			i;

	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst1 <= src1)
	{
		while (i < len)
		{
			dst1[i] = src1[i];
			i++;
		}
	}
	else
	{
		while (len-- != 0)
			dst1[len] = src1[len];
	}
	return (dst);
}

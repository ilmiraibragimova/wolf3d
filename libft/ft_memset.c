/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hholly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 17:02:05 by hholly            #+#    #+#             */
/*   Updated: 2019/09/22 20:28:06 by hholly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	c1;
	unsigned char	*b1;
	size_t			i;

	c1 = (unsigned char)c;
	b1 = (unsigned char*)b;
	i = 0;
	while (i++ < len)
	{
		*b1 = c1;
		b1++;
	}
	return (b);
}

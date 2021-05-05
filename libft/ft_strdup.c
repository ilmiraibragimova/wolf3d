/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hholly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 19:18:29 by hholly            #+#    #+#             */
/*   Updated: 2019/09/08 14:50:20 by hholly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *scr)
{
	int		i;
	int		len;
	char	*dest;

	i = 0;
	len = 0;
	while (scr[len])
	{
		len++;
	}
	dest = (char *)malloc(sizeof(*dest) * (len + 1));
	if (dest == NULL)
		return (NULL);
	while (i < len)
	{
		dest[i] = scr[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

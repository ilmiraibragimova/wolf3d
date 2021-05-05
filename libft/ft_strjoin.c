/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hholly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 19:20:37 by hholly            #+#    #+#             */
/*   Updated: 2019/09/22 20:31:11 by hholly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*s3;
	size_t	i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = 0;
	if (!(s3 = (char*)malloc(sizeof(char) * (len1 + len2 + 1))))
		return (NULL);
	while (i < len1)
	{
		s3[i] = s1[i];
		i++;
	}
	while (i < len1 + len2)
	{
		s3[i] = s2[i - len1];
		i++;
	}
	s3[i] = '\0';
	return (s3);
}

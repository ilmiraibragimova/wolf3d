/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hholly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 19:23:46 by hholly            #+#    #+#             */
/*   Updated: 2019/09/22 19:25:07 by hholly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*new;
	size_t			len;
	char			*s1;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	if (!(new = (char*)malloc((len + 1) * sizeof(char))))
		return (NULL);
	s1 = (char *)s;
	i = 0;
	while (s1[i])
	{
		new[i] = f(s1[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hholly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 20:05:01 by hholly            #+#    #+#             */
/*   Updated: 2019/09/23 17:25:54 by hholly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_trim(const char *s, size_t start, size_t i)
{
	char *new;

	if (!(new = (char*)malloc(sizeof(char) * (i - start + 2))))
		return (NULL);
	ft_strncpy(new, &s[start], i - start + 1);
	new[i - start + 1] = '\0';
	return (new);
}

char		*ft_strtrim(char const *s)
{
	size_t len;
	size_t start;
	size_t i;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	if (i == len)
		return (ft_strnew(0));
	start = i;
	i = len - 1;
	while (i > 0 && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i--;
	return (ft_trim(s, start, i));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hholly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 17:53:57 by hholly            #+#    #+#             */
/*   Updated: 2019/09/22 18:19:41 by hholly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int n)
{
	int		count;

	count = 0;
	if (n < 0)
		n = -n;
	while (n >= 10)
	{
		count++;
		n = n / 10;
	}
	return (count + 1);
}

char		*ft_itoa(int n)
{
	char	*s;
	int		count;
	int		sign;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = 0;
	if (n < 0)
		sign = 1;
	count = ft_count(n) + 1 + sign;
	if (!(s = ft_strnew(count - 1)))
		return (NULL);
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
		n = -n;
	s[count--] = '\0';
	while (n)
	{
		s[--count] = n % 10 + '0';
		n = n / 10;
	}
	if (sign == 1)
		s[--count] = '-';
	return (s);
}

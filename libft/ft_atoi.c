/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hholly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 16:29:04 by hholly            #+#    #+#             */
/*   Updated: 2019/09/23 15:10:44 by hholly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long long	num;
	int					k;

	num = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	k = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			k = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = (unsigned long long)(num * 10 + (*str - '0'));
		if (num > 9223372036854775807 && k == 1)
			return (-1);
		if (num > 9223372036854775807 && k == -1)
			return (0);
		str++;
	}
	return ((int)(num) * k);
}

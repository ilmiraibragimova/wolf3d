/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 03:31:57 by lseema            #+#    #+#             */
/*   Updated: 2021/05/16 03:32:30 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_usage(int a)
{
	if (a == 1)
		write(1, "usage: wolf3d input_file\n", 22);
	if (a == 2)
		write(1, "error in reading input", 22);
	if (a == 3)
		write(1, "error opening file", 18);
	if (a == 4)
		write(1, "not a valid file", 16);
	if (a == 5)
		write(1, "error allocating memory", 23);
	if (a == 6)
		write(1, "error closing file", 18);
	exit(0);
}

void	ft_put_error(char *s)
{
	write(1, s, ft_strlen(s));
	write(1, "\n", 1);
	exit(1);
}

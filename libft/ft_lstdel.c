/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hholly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 18:27:30 by hholly            #+#    #+#             */
/*   Updated: 2019/09/22 18:59:13 by hholly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *al;
	t_list *temp;

	al = *alst;
	while (al)
	{
		temp = al->next;
		del(al->content, al->content_size);
		free(al);
		al = temp;
	}
	*alst = NULL;
}

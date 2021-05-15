/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hholly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 14:00:19 by hholly            #+#    #+#             */
/*   Updated: 2021/05/15 23:01:31 by ilmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*listnew;

	listnew = (t_list *)malloc(sizeof(t_list));
	if (!listnew)
		return (NULL);
	if (!content)
	{
		listnew->content = NULL;
		listnew->content_size = 0;
	}
	else
	{
		listnew->content = malloc(content_size);
		if (!listnew->content)
		{
			free(listnew);
			return (NULL);
		}
		ft_memmove(listnew->content, content, content_size);
		listnew->content_size = content_size;
	}
	listnew->next = NULL;
	return (listnew);
}

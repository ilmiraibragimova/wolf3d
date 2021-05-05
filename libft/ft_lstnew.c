/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hholly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 14:00:19 by hholly            #+#    #+#             */
/*   Updated: 2019/09/22 20:38:34 by hholly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *listnew;

	if (!(listnew = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		listnew->content = NULL;
		listnew->content_size = 0;
	}
	else
	{
		if (!(listnew->content = malloc(content_size)))
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hholly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 14:03:28 by hholly            #+#    #+#             */
/*   Updated: 2019/09/22 18:33:18 by hholly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	clean(t_list *lst)
{
	t_list	*val;

	while (lst)
	{
		val = lst->next;
		ft_memdel((void**)&lst);
		lst = val;
	}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*val;
	t_list	*newlist;
	t_list	*temp;

	if (lst == NULL)
		return (NULL);
	temp = f(lst);
	newlist = ft_lstnew(temp->content, temp->content_size);
	if (newlist == NULL)
		return (NULL);
	val = newlist;
	while (lst->next)
	{
		lst = lst->next;
		temp = f(lst);
		val->next = ft_lstnew(temp->content, temp->content_size);
		if (val->next == NULL)
		{
			clean(newlist);
			return (NULL);
		}
		val = val->next;
	}
	return (newlist);
}

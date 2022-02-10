/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 14:43:47 by sdiez-ga          #+#    #+#             */
/*   Updated: 2021/09/27 17:59:46 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_list_first;

	if (!lst || !f)
		return (0);
	new_list = ft_lstnew((f)(lst->content));
	new_list_first = new_list;
	lst = lst->next;
	while (lst)
	{
		new_list->next = ft_lstnew((f)(lst->content));
		if (!new_list->next)
		{
			if (del)
				ft_lstclear(&new_list_first, del);
			return (0);
		}
		new_list = new_list->next;
		lst = lst->next;
	}
	new_list->next = 0;
	return (new_list_first);
}

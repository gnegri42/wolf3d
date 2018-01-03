/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnegri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:31:14 by gnegri            #+#    #+#             */
/*   Updated: 2017/11/14 17:48:23 by gnegri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*first;
	t_list	*list;

	first = (f)(lst);
	list = first;
	while (lst->next != NULL)
	{
		first->next = (f)(lst->next);
		first = first->next;
		lst = lst->next;
	}
	return (list);
}

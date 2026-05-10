/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecoelho <pecoelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 17:21:51 by pecoelho          #+#    #+#             */
/*   Updated: 2026/04/14 14:14:00 by pecoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*p1;
	t_list	*new;
	t_list	*res;

	if (!lst || !f || !del)
		return (NULL);
	p1 = lst;
	res = NULL;
	while (p1)
	{
		new = (ft_lstnew(f(p1->content)));
		if (!new)
		{
			ft_lstclear(&res, del);
			return (NULL);
		}
		ft_lstadd_back(&res, new);
		p1 = p1->next;
	}
	return (res);
}

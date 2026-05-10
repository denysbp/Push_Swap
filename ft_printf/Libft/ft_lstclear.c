/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecoelho <pecoelho@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 13:20:39 by pecoelho          #+#    #+#             */
/*   Updated: 2026/04/01 12:53:21 by pecoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*p1;
	t_list	*temp;

	if (!lst || !del)
		return ;
	p1 = *lst;
	while (p1)
	{
		del(p1->content);
		temp = p1->next;
		free(p1);
		p1 = temp;
	}
	*lst = NULL;
}

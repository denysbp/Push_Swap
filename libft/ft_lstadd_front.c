/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 23:14:12 by deferrei          #+#    #+#             */
/*   Updated: 2026/04/14 13:57:47 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
	{
		return ;
	}
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	new -> next = *lst;
	*lst = new;
}

/* int main()
{
	t_list	*head = NULL;
	t_list *nova = ft_lstnew(ft_strdup("IM SCARED"));
    ft_lstadd_front(&head, nova);
	printf("%s", (char *)head ->content);
	free(nova);
} */
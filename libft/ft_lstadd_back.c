/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 23:14:09 by deferrei          #+#    #+#             */
/*   Updated: 2026/04/14 13:58:10 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*new_one;

	if (!new)
	{
		return ;
	}
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	new_one = ft_lstlast(*lst);
	new_one -> next = new;
}

/* int main()
{
	t_list	*head = NULL;
	t_list *nova = ft_lstnew(ft_strdup("IM SCARED"));
    ft_lstadd_back(&head, nova);
	printf("%s", (char *)head ->content);
	free(nova);
} */
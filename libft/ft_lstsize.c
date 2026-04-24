/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 23:14:47 by deferrei          #+#    #+#             */
/*   Updated: 2026/04/14 14:26:48 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst -> next;
	}
	return (count);
}

/* int main()
{
	t_list	*head = NULL;
	t_list *nova = ft_lstnew(ft_strdup("IM SCARED\n"));
	t_list	*nv = ft_lstnew(ft_strdup("IM NOT A ZEN ANYMORE"));
    ft_lstadd_front(&head, nova);
	ft_lstadd_back(&head, nv);
	
    int n = ft_lstsize(head);
	printf("%d", n);
	free(nova);
	free(nv);
} */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 23:14:32 by deferrei          #+#    #+#             */
/*   Updated: 2026/04/14 14:49:49 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst)
	{
		return ;
	}
	while (lst)
	{
		f(lst -> content);
		lst = lst -> next;
	}
}

/* void del_func(void *content)
{
    free(content);
}
void print_content(void *content)
{
    puts((char *)content);
}
int main()
{
	t_list    *head = ft_lstnew(ft_strdup("A"));
    t_list *b = ft_lstnew(ft_strdup("B"));
    ft_lstadd_back(&head, b);
    ft_lstiter(head, print_content);
	ft_lstclear(&head, del_func);
} */
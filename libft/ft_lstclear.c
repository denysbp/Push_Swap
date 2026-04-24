/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 23:14:17 by deferrei          #+#    #+#             */
/*   Updated: 2026/04/14 14:33:14 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Deletes and frees the given node and all its
successors, using the function ’del’ and free(3).
Finally, set the pointer to the list to NULL.
*/

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next_one;

	if (!lst || !del)
	{
		return ;
	}
	while (*lst)
	{
		next_one = (*lst)-> next;
		ft_lstdelone(*lst, del);
		*lst = next_one;
	}
	*lst = NULL;
}

/* void del_func(void *content)
{
    free(content);
}
int main()
{
	t_list	*head = NULL;
	t_list *nova = ft_lstnew(ft_strdup("IM SCARED\n"));
	t_list	*nv = ft_lstnew(ft_strdup("IM NOT A ZEN ANYMORE"));
    ft_lstadd_front(&head, nova);
	ft_lstadd_back(&head, nv);
	ft_lstclear(&nova, del_func);
} */

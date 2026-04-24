/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 23:14:38 by deferrei          #+#    #+#             */
/*   Updated: 2026/04/14 15:08:00 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	/*DESCRIPTION :
	The function ft_lstmap creates a new list from a given list  by
	applying the function passed as parameter to the original list. If
	the memory allocation fails for any node in the new list, the new list
	will be deleted with the function passed as parameter and its memory
	will be freed.

	RETURN VALUE :
	The new list containing the new values if a functon was provided.
	A new copy of the list if no function was provided.
	NULL if the memory allocation failed.*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*node;

	new_list = NULL;
	while (lst)
	{
		node = ft_lstnew(f(lst -> content));
		if (! node)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, node);
		lst = lst -> next;
	}
	return (new_list);
}

/* void *map_func(void *content)
{
    char *str = (char *)content;
    char *new = malloc(strlen(str) + 2);
    if (!new) return NULL;
    strcpy(new, str);
    strcat(new, "!");
    return new;
}
void del_func(void *content)
{
    free(content);
}
int main()
{
	t_list *lista;
    lista = malloc(sizeof(t_list));
    lista ->content = ft_strdup("A");
    lista -> next = NULL;

    // list com 2 nos
    lista ->next = malloc(sizeof(t_list));
    lista ->next->content = ft_strdup("B");
    lista ->next->next = NULL;

    t_list *mapped = ft_lstmap(lista, map_func, del_func);
	printf("%s", (char *)mapped->next->content);
	ft_lstclear(&lista, del_func);
	ft_lstclear(&mapped, del_func);
	
} */
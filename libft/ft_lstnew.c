/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 23:14:41 by deferrei          #+#    #+#             */
/*   Updated: 2026/04/15 23:02:10 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_list;

	new_list = malloc(sizeof(t_list));
	if (!new_list)
	{
		return (NULL);
	}
	new_list -> content = content;
	new_list -> next = NULL;
	return (new_list);
}

/* int main()
{
	t_list *nova = ft_lstnew(ft_strdup("IM SCARED"));

	printf("%s", (char *)nova ->content);
	free(nova);
} */
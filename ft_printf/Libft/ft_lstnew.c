/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecoelho <pecoelho@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 23:14:46 by pecoelho          #+#    #+#             */
/*   Updated: 2026/03/29 00:48:12 by pecoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*p1;

	p1 = malloc(sizeof(t_list));
	if (!p1)
		return (NULL);
	p1->content = content;
	p1->next = NULL;
	return (p1);
}

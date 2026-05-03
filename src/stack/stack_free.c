/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:06:16 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/01 19:47:51 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_clear(t_stack **lst)
{
	t_stack	*next_one;

	if (!lst)
	{
		return ;
	}
	while (*lst)
	{
		next_one = (*lst)-> next;
		stack_delone(*lst);
		*lst = next_one;
	}
	*lst = NULL;
}

void	stack_delone(t_stack *lst)
{
	if (!lst)
		return ;
	free(lst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecoelho <pecoelho@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 11:25:35 by pecoelho          #+#    #+#             */
/*   Updated: 2026/05/03 11:25:40 by pecoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*first_stack(t_stack *lst)
{
	while (lst && lst -> prev)
		lst = lst ->prev;
	return (lst);
}

void	stack_clear(t_stack **stack)
{
	t_stack	*p1;
	t_stack	*temp;

	if (!stack)
		return ;
	p1 = *stack;
	while (p1)
	{
		p1->prev = NULL;
		p1->value = 0;
		p1->index = 0;
		temp = p1->next;
		free(p1);
		p1 = temp;
	}
	*stack = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecoelho <pecoelho@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:05:59 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/03 13:36:09 by pecoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_indexing(t_stack **stack)
{
	t_stack	*head;
	int		i;

	if (!stack)
		return ;
	head = *stack;
	i = 0;
	while (*stack)
	{
		(*stack)->index = i;
		*stack = (*stack)->next;
		i++;
	}
	*stack = head;
}

void	radix_rank(t_stack **stack)
{
	t_stack	*head;
	t_stack	*cur;
	int		swapped;

	head = *stack;
	stack_indexing(stack);
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		cur = head;
		while (cur && cur->next)
		{
			if (cur->value > cur->next->value)
			{
				ft_swap(&cur->index, &cur->next->index);
				swapped = 1;
			}
			cur = cur->next;
		}
	}
	*stack = head;
}

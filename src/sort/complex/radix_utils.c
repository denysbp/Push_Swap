/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecoelho <pecoelho@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:05:59 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/05 00:14:17 by pecoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_stack *stack)
{
	t_stack	*cur;
	t_stack	*cmp;
	int		index;

	cur = stack;
	while (cur)
	{
		index = 0;
		cmp = stack;
		while (cmp)
		{
			if (cmp->value < cur->value)
				index++;
			cmp = cmp->next;
		}
		cur->index = index;
		cur = cur->next;
	}
}

void	radix(t_stack **stack_a, t_stack **b)
{
	t_stack	*temp;
	int		op_count;

	if (!stack_a)
		return ;
	op_count = 0;
	while (stack_a)
	{
		temp = (*stack_a)->next;
		if (!((*stack_a)->index & 1))
			op_push(stack_a, *stack_a);
		else if ((*stack_a)->index & 1)
			op_rot_stack(stack_a);
		op_count += 1;
		*stack_a = temp;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecoelho <pecoelho@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:05:59 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/05 00:17:18 by pecoelho         ###   ########.fr       */
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

void	radix(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	int		op_count;

	if (!a)
		return ;
	op_count = 0;
	while (a)
	{
		temp = (*a)->next;
		if (!((*a)->index & 1))
			pb(a, b);
		else if ((*a)->index & 1)
			op_rot_stack(a);
		op_count += 1;
		*a = temp;
	}
}

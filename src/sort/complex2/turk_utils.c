/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecoelho <pecoelho@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 11:12:48 by pecoelho          #+#    #+#             */
/*   Updated: 2026/05/06 19:49:23 by pecoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_cost(t_stack **stack, int index)
{
	t_stack	*temp;
	int		position;
	int		costt;
	int		costb;

	temp = *stack;
	position = 0;
	while (temp && temp->index < index)
	{
		position++;
		temp = temp->next;
	}
	return (position);
}

int	precise_b_insertion(t_stack **a, t_stack **b, t_bench_mark *bench)
{
	int	count_op;
	int	size;
	int	pos;

	pos = find_cost(a, (*b)->index);
	size = stack_size(*a);
	count_op = 0;
	if (pos <= size - pos)
	{
		while (pos-- > 0)
			count_op += ra(a, bench);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			count_op += rra(a, bench);
	}
	count_op +=pa(b, a, bench);
	return (count_op);
}

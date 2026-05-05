/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:07:33 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/05 23:07:47 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	op_rev_stack(t_stack **stack)
{
	t_stack	*current;
	int		temp;
	int		itemp;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	current = last_stack(*stack);
	while (current->prev)
	{
		temp = current->value;
		current->value = current->prev->value;
		current->prev->value = temp;
		itemp = current->index;
		current->index = current->prev->index;
		current->prev->index = itemp;
		current = current->prev;
	}
	return (1);
}

int	rra(t_stack **a, t_bench_mark *bench)
{
	int	i;

	i = op_rev_stack(a);
	if (!i)
		return (0);
	bench->rra++;
	ft_printf("rra\n");
	return (1);
}

int	rrb(t_stack **b, t_bench_mark *bench)
{
	int	i;

	i = op_rev_stack(b);
	if (!i)
		return (0);
	bench->rrb++;
	ft_printf("rrb\n");
	return (1);
}

int	op_rev_both(t_stack **s1, t_stack **s2, t_bench_mark *bench)
{
	int	check1;
	int	check2;

	check1 = op_rev_stack(s1);
	check2 = op_rev_stack(s2);
	bench->rra--;
	bench->rrb--;
	if (!check1 || !check2)
		return (0);
	bench->rrr++;
	ft_printf("rrr\n");
	return (1);
}

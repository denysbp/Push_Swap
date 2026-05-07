/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecoelho <pecoelho@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:07:39 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/07 17:01:21 by pecoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	op_swap_stack(t_stack **stack)
{
	int	temp;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	temp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	((*stack)->next)->value = temp;
	temp = (*stack)->index;
	(*stack)->index = (*stack)->next->index;
	((*stack)->next)->index = temp;
	return (1);
}

int	sa(t_stack **a, t_bench_mark *bench)
{
	int	i;

	i = op_swap_stack(a);
	if (!i)
		return (0);
	bench->sa++;
	return (i);
}

int	sb(t_stack **b, t_bench_mark *bench)
{
	int	i;

	i = op_swap_stack(b);
	if (!i)
		return (0);
	bench->sb++;
	return (i);
}

int	op_swap_both(t_stack **s1, t_stack **s2, t_bench_mark *bench)
{
	int	check;

	if (!s1 || !s2 || !*s1 || !*s2)
		return (0);
	check = op_swap_stack(s1);
	bench->sa--;
	if (!check)
		return (0);
	check = op_swap_stack(s2);
	bench->sb--;
	bench->ss++;
	if (!check)
		return (0);
	return (1);
}

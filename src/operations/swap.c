/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:07:39 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/05 19:59:38 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sa(t_stack **a, bench_mark bench)
{
	op_swap_stack(a);
	bench.sa++;
}

void	sb(t_stack **b, bench_mark bench)
{
	op_swap_stack(b);
	bench.sb++;
}

int	op_swap_both(t_stack **s1, t_stack **s2, bench_mark bench)
{
	int	check;

	if (!s1 || !s2 || !*s1 || !*s2)
		return (0);
	check = op_swap_stack(s1);
	bench.sa--;
	if (!check)
		return (0);
	check = op_swap_stack(s2);
	bench.sb--;
	bench.ss++;
	if (!check)
		return (0);
	return (1);
}

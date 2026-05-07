/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecoelho <pecoelho@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:07:39 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/07 21:49:59 by pecoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	op_swap_stack(t_stack **stack)
{
	int	temp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	temp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	((*stack)->next)->value = temp;
	temp = (*stack)->index;
	(*stack)->index = (*stack)->next->index;
	((*stack)->next)->index = temp;
}

void	sa(t_stack **a, t_bench_mark *bench)
{
	op_swap_stack(a);
	bench->sa++;
}

void	sb(t_stack **b, t_bench_mark *bench)
{
	op_swap_stack(b);
	bench->sb++;
}

void	ss(t_stack **a, t_stack **b, t_bench_mark *bench)
{
	if (!a || !b || !*a || !*b)
		return ;
	sa(a, bench);
	sb(b, bench);
	bench->sa--;
	bench->sb--;
	bench->ss++;
}

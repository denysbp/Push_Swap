/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:07:39 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/10 13:14:24 by deferrei         ###   ########.fr       */
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
	ft_printf("sa\n");
}

void	sb(t_stack **b, t_bench_mark *bench)
{
	op_swap_stack(b);
	bench->sb++;
	ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b, t_bench_mark *bench)
{
	if (!a || !b || !*a || !*b)
		return ;
	op_swap_stack(a);
	op_swap_stack(b);
	bench->ss++;
	ft_printf("ss\n");
}

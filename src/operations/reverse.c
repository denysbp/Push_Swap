/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecoelho <pecoelho@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:07:33 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/07 21:37:47 by pecoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	op_rev_stack(t_stack **stack)
{
	t_stack	*current;
	int		temp;
	int		itemp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
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
}

void	rra(t_stack **a, t_bench_mark *bench)
{
	op_rev_stack(a);
	bench->rra++;
	ft_printf("rra\n");
}

void	rrb(t_stack **b, t_bench_mark *bench)
{
	op_rev_stack(b);
	bench->rrb++;
	ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b, t_bench_mark *bench)
{
	rra(a, bench);
	rrb(b, bench);
	bench->rra--;
	bench->rrb--;
	bench->rrr++;
	ft_printf("rrr\n");
}

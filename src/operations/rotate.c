/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecoelho <pecoelho@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:07:36 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/07 21:50:45 by pecoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	op_rot_stack(t_stack **stack)
{
	t_stack	*cur;
	int		temp;
	int		itemp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	cur = *stack;
	while (cur->next)
	{
		temp = cur->value;
		cur->value = cur->next->value;
		cur->next->value = temp;
		itemp = cur->index;
		cur->index = cur->next->index;
		cur->next->index = itemp;
		cur = cur->next;
	}
}

void	ra(t_stack **a, t_bench_mark *bench)
{
	op_rot_stack(a);
	bench->ra += 1;
	ft_printf("ra\n");
}

void	rb(t_stack **b, t_bench_mark *bench)
{
	op_rot_stack(b);
	bench->rb += 1;
	ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b, t_bench_mark *bench)
{
	if (!a || !b || !*a || !*b)
		return ;
	ra(a, bench);
	rb(b, bench);
	bench->ra--;
	bench->rb--;
	bench->rr++;
}

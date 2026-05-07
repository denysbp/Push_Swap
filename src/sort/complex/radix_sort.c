/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecoelho <pecoelho@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:05:55 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/07 21:07:03 by pecoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	radix(t_stack **a, t_stack **b, t_bench_mark *bench)
{
	size_t	n;
	size_t	checkpoint;
	int		mask;

	if (!a)
		return ;
	assign_index(a);
	mask = 1;
	checkpoint = stack_size(*a);
	while (disorder_rate(*a))
	{
		n = checkpoint;
		while (n)
		{
			stack_selection(a, b, mask, bench);
			n--;
		}
		stackb_cleanup(a, b, bench);
		mask = mask << 1;
	}
}

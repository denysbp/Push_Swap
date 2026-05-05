/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:05:55 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/05 21:15:03 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	radix(t_stack **a, t_bench_mark bench)
{
	t_stack	*b;
	size_t	n;
	size_t	checkpoint;
	int		op_count;
	int		mask;

	if (!a)
		return (0);
	b = NULL;
	op_count = 0;
	mask = 1;
	checkpoint = stack_size(*a) + 1;
	while (disorder_rate(*a))
	{
		n = checkpoint;
		while (n--)
			op_count += stack_selection(a, &b, mask, bench);
		op_count += stackb_cleanup(a, &b, bench);
		mask = mask << 1;
	}
	return (op_count);
}

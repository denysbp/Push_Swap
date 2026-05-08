/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:06:05 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/08 02:48:08 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	chunck_sort(t_stack	**stack, t_stack **b, t_bench_mark *bench)
{
	size_t	chunk_size;
	size_t	size;

	size = stack_size(*stack);
	chunk_size = ft_sqrt(size);
	if (disorder_rate(*stack) == 0)
		return ;
	if (size > 100)
		chunk_size += size / 20;
	push_chunks(stack, b, chunk_size, bench);
	push_back_sorted(stack, b, bench);
}

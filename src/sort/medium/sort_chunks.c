/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:06:05 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/05 21:15:03 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	chunck_sort(t_stack	**stack, t_bench_mark bench)
{
	t_stack	*b;
	size_t	chunk_size;
	size_t	size;

	b = NULL;
	size = stack_size(*stack);
	chunk_size = ft_sqrt(size);
	if (size > 100)
		chunk_size += size / 20;
	push_chunks(stack, &b, chunk_size, bench);
	push_back_sorted(stack, &b, bench);
}
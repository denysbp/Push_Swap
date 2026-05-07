/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecoelho <pecoelho@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 13:17:05 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/07 19:58:27 by pecoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_choose(t_stack **stack, t_bench_mark *bench)
{
	float	disorder;
	size_t	size;

	size = stack_size(stack);
	disorder = disorder_rate(*stack);
	if (size > 1 && size <= 5)
	{
		tiny_sort(stack, bench);
	}
	if (disorder < 0.2)
	{
		selection_min(stack, bench);
	}
	else if (disorder <= 0.2 || disorder < 0.5)
	{
		chunck_sort(stack, bench);
	}
	else if (disorder >= 0.5)
	{
		radix(stack, bench);
	}
}

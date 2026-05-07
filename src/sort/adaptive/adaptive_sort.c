/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecoelho <pecoelho@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 13:17:05 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/07 21:09:44 by pecoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_choose(t_stack **a, t_stack **b, t_bench_mark *bench)
{
	float	disorder;
	size_t	size;

	size = stack_size(*a);
	disorder = disorder_rate(*a);
	if (size > 1 && size <= 5)
	{
		tiny_sort(a, b, bench);
	}
	if (disorder < 0.2)
	{
		selection_min(a, b, bench);
	}
	else if (disorder <= 0.2 || disorder < 0.5)
	{
		chunck_sort(a, b, bench);
	}
	else if (disorder >= 0.5)
	{
		radix(a, b, bench);
	}
}

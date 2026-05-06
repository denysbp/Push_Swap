/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 13:17:05 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/06 13:14:02 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_choose(t_stack **stack, t_bench_mark *bench)
{
	float	disorder;

	disorder = disorder_rate(*stack);
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

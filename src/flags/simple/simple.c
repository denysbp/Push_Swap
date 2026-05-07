/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 12:21:42 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/07 16:59:22 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	simple_flag(t_stack **a, t_bench_mark *bench, char **argv, int i)
{
	bench->strategy = 0;
	if (run_strategy(a, argv, i + 1) < 0)
		return (-1);
	if (run_strategy(a, argv, i) == 2)
		return (2);
	assign_index(a);
	bench->disorder = disorder_rate(*a);
	selection_min(a, bench);
	return (1);
}

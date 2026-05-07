/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 12:25:38 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/07 17:00:14 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	adaptive_flags(t_stack **a, t_bench_mark *bench, char **argv, int i)
{
	bench->strategy = 3;
	if (run_strategy(a, argv, i + 1) < 0)
		return (-1);
	if (run_strategy(a, argv, i) == 2)
		return (2);
	bench->disorder = disorder_rate(*a);
	assign_index(a);
	sort_choose(a, bench);
	return (1);
}
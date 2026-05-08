/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 12:21:42 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/08 02:48:08 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	simple_flag(t_stack **a, t_stack **b, t_bench_mark *bench,
	t_parse_ctx input)
{
	bench->strategy = 0;
	if (run_strategy(a, input) < 0)
		return (-1);
	assign_index(a);
	bench->disorder = disorder_rate(*a);
	selection_min(a, b, bench);
	return (1);
}

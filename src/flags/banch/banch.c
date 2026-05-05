/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   banch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 12:27:19 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/05 17:56:46 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		strategy(bench_mark bench)
{
	if (bench.strategy == 0)
	{
		write(2, "simple O(n²)", 13);
		return (13);
	}
	else if (bench.strategy == 1)
	{
		write(2, "medium O(n√n)", 15);
		return (15);
	}
	else if (bench.strategy == 2)
	{
		write(2, "complex O(n log n)", 18);
		return (18);
	}
}

void	print_bench(bench_mark bench)
{
	write(2, "[bench] disorder:  ", 19);
	write(2, "23,4", 4);
	write(2, "[bench] strategy:  ", 19);
	write(2, &bench.strategy, 1);
	ft_printf("[bench] total_ops:  %d", bench.total);
	ft_printf("[bench] sa: %d  sb: %d  pa: %d  pb: %d ", bench.sa, bench.sb, bench.pa, bench.pb);
	ft_printf("[bench] ra: %d  rb: %d  rr: %d  rra: %d  rrb: %d   rrr: %d", bench.ra, bench.rb, bench.rr, bench.rra, bench.rrb, bench.rrr);
}
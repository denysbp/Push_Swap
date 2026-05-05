/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   banch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 12:27:19 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/05 20:22:06 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t		strategy(bench_mark bench)
{
	if (bench.strategy == 0)
	{
		write(2, "simple O(n²)\n", 13);
		return (13);
	}
	else if (bench.strategy == 1)
	{
		write(2, "medium O(n√n)\n", 15);
		return (15);
	}
	else if (bench.strategy == 2)
	{
		write(2, "complex O(n log n)\n", 18);
		return (18);
	}
	else if (bench.strategy == 3)
	{
		write(2, "adaptive\n", 10);
		return (18);
	}
	return (0);
}

void	print_bench(bench_mark bench)
{
	write(2, "[bench] disorder:  ", 19);
	write(2, "23,4", 4);
	write(2, "[bench] strategy:  ", 19);
	strategy(bench);
	write(2, "[bench] total_ops:  %d\n", bench.total);
	write(2, "[bench] sa:  ", 14);
	write(2, &bench.sa, 4);
	write(2, "[bench] sb:  ", 14);
	write(2, &bench.sb, 4);
	write(2, "[bench] ss:  ", 14);
	write(2, &bench.ss, 4);
	write(2, "[bench] pa:  ", 14);
	write(2, &bench.pa, 4);
	write(2, "[bench] pb:  \n", 14);
	write(2, &bench.pb, 4);
	write(2, "[bench] ra:  ", 14);
	write(2, &bench.ra, 4);
	write(2, "[bench] rb:  ", 14);
	write(2, &bench.rb, 4);
	write(2, "[bench] rr:  ", 14);
	write(2, &bench.rr, 4);
	write(2, "[bench] rra:  ", 15);
	write(2, &bench.rra, 4);
	write(2, "[bench] rrb:  ", 15);
	write(2, &bench.rrb, 4);
	write(2, "[bench] rrr:  \n", 15);
	write(2, &bench.rrr, 4);
}

bench_mark	init_bench(bench_mark bench)
{
	bench.display = false;
	bench.pa = 0;
	bench.pb = 0;
	bench.ra = 0;
	bench.rb = 0;
	bench.rr = 0;
	bench.rra = 0;
	bench.rrb = 0;
	bench.rrr = 0;
	bench.sa = 0;
	bench.sb = 0;
	bench.ss = 0;
	bench.strategy = -1;
	bench.total = 0;
	return (bench);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   banch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 12:27:19 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/07 14:19:39 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t		strategy(t_bench_mark *bench)
{
	if (bench->strategy == 0)
	{
		write(2, "simple O(n²)", 13);
		return (13);
	}
	else if (bench->strategy == 1)
	{
		write(2, "medium O(n√n)", 15);
		return (15);
	}
	else if (bench->strategy == 2)
	{
		write(2, "complex O(n log n)", 18);
		return (18);
	}
	else if (bench->strategy == 3)
	{
		write(2, "adaptive", 9);
		return (18);
	}
	return (0);
}

void	print_bench(t_bench_mark *bench)
{
	bench->total = bench->sa + bench->sb + bench->ss + bench->pa + bench->pb
		+ bench->ra + bench->rb + bench->rr + bench->rra + bench->rrb
		+ bench->rrr;
	write(2, "[bench] disorder:  ", 19);
	print_float(bench->disorder);
	write(2, "\n[bench] strategy:  ", 19);
	strategy(bench);
	write(2, "\n[bench] total_ops:  ", 21);
	ft_putnbr_fd(bench->total, 2);
	write(2, "\n[bench] sa:  ", 14);
	ft_putnbr_fd(bench->sa, 2);
	write(2, " sb:  ", 7);
	ft_putnbr_fd(bench->sb, 2);
	write(2, " ss:  ", 7);
	ft_putnbr_fd(bench->ss, 2);
	write(2, " pa:  ", 7);
	ft_putnbr_fd(bench->pa, 2);
	write(2, " pb:  ", 7);
	ft_putnbr_fd(bench->pb, 2);
	write(2, "\n[bench] ra:  ", 14);
	ft_putnbr_fd(bench->ra, 2);
	write(2, " rb:  ", 7);
	ft_putnbr_fd(bench->rb, 2);
	write(2, " rr:  ", 7);
	ft_putnbr_fd(bench->rr, 2);
	write(2, " rra:  ", 8);
	ft_putnbr_fd(bench->rra, 2);
	write(2, " rrb:  ", 8);
	ft_putnbr_fd(bench->rrb, 2);
	write(2, " rrr:  ", 8);
	ft_putnbr_fd(bench->rrr, 2);
	write(2, "\n", 1);
}

t_bench_mark	init_bench(t_bench_mark bench)
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
	bench.disorder = 0;
	return (bench);
}

void	pf_edgecase(float ds)
{
	if (ds == 1.00)
		write(2, "100.00%", 8);
}
void	free_char(char * unit, char *dec)
{
	free(unit);
	free(dec);
}
void	print_float(float ds)
{
	char	*unit;
	char	*dec;
	int		total;

	if (ds < 0 || ds >= 1)
	{
		pf_edgecase(ds);
		return ;
	}
	total = (int)((ds - (int)ds) * 10000 + 0.5);
	unit = ft_itoa(total / 100);
	dec = ft_itoa(total % 100);
	if (!unit || !dec)
	{
		if (!unit)
			free(dec);
		else
			free(unit);
		return ;
	}
	write(2, unit, ft_strlen(unit));
	write(2, ".", 1);
	write(2, dec, ft_strlen(dec));
	write(2, "%", 2);
	free_char(unit, dec);
}

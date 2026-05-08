/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 02:30:00 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/08 02:48:08 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

size_t	strategy(t_bench_mark *bench)
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
		write(2, "adaptive", 8);
		return (8);
	}
	return (0);
}

static void	pf_edgecase(float ds)
{
	if (ds == 1.00)
		write(2, "100.00%", 7);
}

static void	free_char(char *unit, char *dec)
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
	write(2, "%", 1);
	free_char(unit, dec);
}

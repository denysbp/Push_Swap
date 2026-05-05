/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:06:42 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/05 19:32:23 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (-1);
	t_stack		*a;
	bench_mark	bench;

	a = NULL;
	bench = init_bench(bench);
	if (parse_flags(&a, argv, bench) < 0)
	{
		error();
		return (-1);
	}
	if (bench.display)
	{
		print_bench(bench);
	}
	stack_clear(&a);
	return (0);
}

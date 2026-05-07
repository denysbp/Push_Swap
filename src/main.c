/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecoelho <pecoelho@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:06:42 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/07 17:01:21 by pecoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (-1);
	t_stack		*a;
	t_bench_mark	bench;

	a = NULL;
	bench = init_bench(bench);
	if (ft_strncmp(argv[1], "--bench", 9) == 0)
		bench.display = true;
	if (parse_flags(&a, argv, &bench, 1) < 0)
	{
		error();
		return (-1);
	}
	if (bench.display)
	{
		print_bench(&bench);
	}
	stack_clear(&a);
	return (0);
}

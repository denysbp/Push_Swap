/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:06:42 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/08 00:50:20 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (-1);
	t_stack		*a;
	t_stack		*b;
	t_bench_mark	bench;

	if (only_null(argv) == -1)
	{
		error();
		return (-1);
	}
	a = NULL;
	b = NULL;
	bench = init_bench(bench);
	if (ft_strncmp(argv[1], "--bench", 9) == 0)
		bench.display = true;
	if (parse_flags(&a, &b, argv, &bench, 1) < 0)
	{
		error();
		return (-1);
	}
	if (parse_flags(&a, &b, argv, &bench, 1) == 2)
		return (-1);
	if (bench.display)
	{
		print_bench(&bench);
	}
	stack_clear(&a);
	return (0);
}

int	only_null(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i][0] == '\0')
			return (-1);
		i++;
	}
	return (1);
}
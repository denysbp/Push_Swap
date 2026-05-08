/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:06:42 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/08 14:10:07 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	finish_main(int result, t_stack **a, t_bench_mark *bench)
{
	if (result < 0)
	{
		error();
		return (-1);
	}
	if (result == 2)
		return (0);
	if (bench->display)
		print_bench(bench);
	stack_clear(a);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack			*a;
	t_stack			*b;
	t_bench_mark	bench;
	int				result;

	if (argc == 1)
		return (-1);
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
	result = parse_flags(&a, &b, &bench, (t_parse_ctx){argv, 1, 3});
	return (finish_main(result, &a, &bench));
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

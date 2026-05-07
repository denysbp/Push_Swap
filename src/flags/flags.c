/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecoelho <pecoelho@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 18:21:34 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/07 21:25:23 by pecoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static char	**build_argv_view(char **argv, int start)
{
	char	**view;
	size_t	count;
	size_t	index;

	count = 0;
	while (argv[start + count])
		count++;
	view = ft_calloc(count + 2, sizeof(char *));
	if (!view)
		return (NULL);
	view[0] = argv[0];
	index = 0;
	while (index < count)
	{
		view[index + 1] = argv[start + index];
		index++;
	}
	return (view);
}

static int	run_strategy(t_stack **stack, char **argv, int start)
{
	char	**view;
	int		result;

	view = build_argv_view(argv, start);
	if (!view)
		return (-1);
	result = parsing_vaidations(stack, view);
	free(view);
	if (result < 0)
		return (-1);
	return (0);
}

int		parse_flags(t_stack **a, t_stack **b, char **argv, t_bench_mark *bench, int i)
{
	if (!argv[i])
		return (-1);
	if (ft_strncmp("--bench", argv[i], 9) == 0)
	{
		bench->display = true;
		if (parse_flags(a, b, argv, bench, i + 1) < 0)
			return (-1);
	}
	else if (ft_strncmp("--simple", argv[i], 10) == 0)
	{
		bench->strategy = 0;
		if (run_strategy(a, argv, i + 1) < 0)
			return (-1);
		assign_index(a);
		bench->disorder = disorder_rate(*a);
		selection_min(a, b, bench);
		return (1);
	}
	else if (ft_strncmp("--medium", argv[i], 10) == 0)
	{
		bench->strategy = 1;
		if (run_strategy(a, argv, i + 1) < 0)
			return (-1);
		assign_index(a);
		bench->disorder = disorder_rate(*a);
		chunck_sort(a, b, bench);
		return (1);
	}
	else if (ft_strncmp("--complex", argv[i], 10) == 0)
	{
		bench->strategy = 2;
		if (run_strategy(a, argv, i + 1) < 0)
			return (-1);
		bench->disorder = disorder_rate(*a);
		radix(a, b, bench);
		return (1);
	}
	else if (ft_strncmp("--adaptive", argv[i], 11) == 0)
	{
		bench->strategy = 3;
		if (run_strategy(a, argv, i + 1) < 0)
			return (-1);
		bench->disorder = disorder_rate(*a);
		sort_choose(a, b, bench);
		return (1);
	}
	else
	{
		bench->strategy = 3;
		if (run_strategy(a, argv, i) < 0)
			return (-1);
		bench->disorder = disorder_rate(*a);
		assign_index(a);
		sort_choose(a, b, bench);
		return (1);
	}
	return (0);
}

int		parsing_vaidations(t_stack **stack, char **argv)
{
	if (!validate_args(argv))
	{
		return (-1);
	}
	*stack = parsing(argv);
	if (!*stack)
	{
		stack_clear(stack);
		return (-1);
	}
	if (is_duplicate(*stack))
	{
		stack_clear(stack);
		return (-1);
	}
	float d = disorder_rate(*stack);
	if (d == 0)
		return (0);
	return (0);
}

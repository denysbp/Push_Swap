/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 18:21:34 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/05 21:23:32 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		parse_flags(t_stack **stack, char **argv, t_bench_mark bench, int i)
{
	if (ft_strncmp("--bench", argv[i], 9))
	{
		i++;;
		argv++;
		bench.display = true;
		if (parse_flags(stack, argv, bench, i) < 0)
			return (-1);
	}
	else if (ft_strncmp("--simple", argv[i], 10))
	{
		i++;
		argv = argv + i;
		bench.strategy = 0;
		if (parsing_vaidations(stack, argv) < 0)
		{
			return (-1);
		}
		selection_min(stack, bench);
		return (1);
	}
	else if (ft_strncmp("--medium", argv[i], 10))
	{
		argv = argv + i;
		bench.strategy = 1;
		if (parsing_vaidations(stack, argv) < 0)
		{
			return (-1);
		}
		chunck_sort(stack, bench);
		return (1);
	}
	else if (ft_strncmp("--complex", argv[i], 10))
	{
		argv = argv + i;
		bench.strategy = 2;
		if (parsing_vaidations(stack, argv) < 0)
		{
			return (-1);
		}
		radix(stack, bench);
		return (1);
	}
	else if (ft_strncmp("--adaptive", argv[i], 11))
	{
		argv = argv + i;
		bench.strategy = 3;
		if (parsing_vaidations(stack, argv) < 0)
		{
			return (-1);
		}
		sort_choose(stack, bench);
		return (1);
	}
	else
	{
		bench.strategy = 3;
		if (parsing_vaidations(stack, argv) < 0)
		{
			return (-1);
		}
		sort_choose(stack, bench);
		return (-1);
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
	if (!stack)
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
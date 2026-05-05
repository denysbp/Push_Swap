/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 18:21:34 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/05 19:09:24 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		parse_flags(t_stack **stack, char **argv, bench_mark bench)
{
	if (ft_strncmp("--bench", argv[1], 9))
	{
		argv++;

		bench.display = true;
		if (parse_flags(stack, argv, bench) < 0)
			return (-1);
	}
	else if (ft_strncmp("--simple", argv[1], 10))
	{
		argv++;
		bench.strategy = 0;
		*stack = parsing(argv);
		if (parsing_vaidations(stack, argv) < 0)
		{
			return (-1);
		}
		selection_min(stack, bench);
		return (1);
	}
	else if (ft_strncmp("--medium", argv[1], 10))
	{
		argv++;
		bench.strategy = 1;
		*stack = parsing(argv);
		if (parsing_vaidations(stack, argv) < 0)
		{
			return (-1);
		}
		chunck_sort(stack, bench);
		return (1);
	}
	else if (ft_strncmp("--complex", argv[1], 10))
	{
		argv++;
		bench.strategy = 2;
		*stack = parsing(argv);
		if (parsing_vaidations(stack, argv) < 0)
		{
			return (-1);
		}
		radix(stack, bench);
		return (1);
	}
	else if (ft_strncmp("--adaptive", argv[1], 11))
	{
		argv++;
		bench.strategy = 3;
		*stack = parsing(argv);
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
		*stack = parsing(argv);
		if (parsing_vaidations(stack, argv) < 0)
		{
			return (-1);
		}
		sort_choose(stack, bench);
		return (-1);
	}
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
}
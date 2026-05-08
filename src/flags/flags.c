/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 18:21:34 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/08 03:12:45 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	missing_values(char **argv, int i)
{
	if (!argv[i + 1])
		return (2);
	return (0);
}

static int	handle_mode(t_stack **a, t_stack **b, t_bench_mark *bench,
	t_parse_ctx input)
{
	if (missing_values(input.argv, input.start) == 2)
		return (2);
	input.start++;
	if (input.mode == 0)
		return (simple_flag(a, b, bench, input));
	if (input.mode == 1)
		return (medium_flags(a, b, bench, input));
	if (input.mode == 2)
		return (complex_flags(a, b, bench, input));
	return (adaptive_flags(a, b, bench, input));
}

static int	dispatch_flag(t_stack **a, t_stack **b, t_bench_mark *bench,
	t_parse_ctx input)
{
	if (ft_strncmp("--simple", input.argv[input.start], 10) == 0)
	{
		input.mode = 0;
		return (handle_mode(a, b, bench, input));
	}
	if (ft_strncmp("--medium", input.argv[input.start], 10) == 0)
	{
		input.mode = 1;
		return (handle_mode(a, b, bench, input));
	}
	if (ft_strncmp("--complex", input.argv[input.start], 10) == 0)
	{
		input.mode = 2;
		return (handle_mode(a, b, bench, input));
	}
	if (ft_strncmp("--adaptive", input.argv[input.start], 11) == 0)
	{
		input.mode = 3;
		return (handle_mode(a, b, bench, input));
	}
	return (adaptive_flags(a, b, bench, input));
}

int	parse_flags(t_stack **a, t_stack **b, t_bench_mark *bench,
					t_parse_ctx input)
{
	if (!input.argv[input.start])
		return (2);
	if (ft_strncmp("--bench", input.argv[input.start], 9) == 0)
	{
		if (missing_values(input.argv, input.start) == 2)
			return (2);
		input.start++;
		return (parse_flags(a, b, bench, input));
	}
	return (dispatch_flag(a, b, bench, input));
	return (1);
}

int	parsing_vaidations(t_stack **stack, char **argv)
{
	if (!validate_args(argv))
		return (-1);
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
	if (disorder_rate(*stack) == 0.00)
		return (2);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 18:21:34 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/07 17:17:01 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**build_argv_view(char **argv, int start)
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

int	run_strategy(t_stack **stack, char **argv, int start)
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
	else if (result == 2)
		return (2);
	return (0);
}

int		parse_flags(t_stack **stack, char **argv, t_bench_mark *bench, int i)
{
	if (!argv[i])
		return (-1);
	if (ft_strncmp("--bench", argv[i], 9) == 0)
	{
		bench->display = true;
		if (parse_flags(stack, argv, bench, i + 1) < 0)
			return (-1);
	}
	else if (ft_strncmp("--simple", argv[i], 10) == 0)
		return (simple_flag(stack, bench, argv, i));
	else if (ft_strncmp("--medium", argv[i], 10) == 0)
		return (medium_flags(stack, bench, argv, i));
	else if (ft_strncmp("--complex", argv[i], 10) == 0)
		return (complex_flags(stack, bench, argv, i));
	else if (ft_strncmp("--adaptive", argv[i], 11) == 0)
		return (adaptive_flags(stack, bench, argv, i));
	else
	{
		return (adaptive_flags(stack, bench, argv, i));
	}
	return (1);
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
		return (2);
	return (0);
}

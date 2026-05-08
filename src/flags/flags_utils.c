/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 01:58:04 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/08 02:48:08 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

int	run_strategy(t_stack **stack, t_parse_ctx input)
{
	char	**view;
	int		result;

	view = build_argv_view(input.argv, input.start);
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

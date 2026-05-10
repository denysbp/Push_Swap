/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:07:22 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/10 17:25:26 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	create_numbers(t_stack **a, char *split)
{
	if (valide_signal(split))
	{
		if (a)
			stack_clear(a);
		return (0);
	}
	if (string_overflow(split))
	{
		if (a)
			stack_clear(a);
		return (0);
	}
	stack_add_back(a, new_stack(ft_atoi(split)));
	return (1);
}

t_stack	*parsing(char **argv)
{
	char	**split;
	int		i;
	int		j;
	t_stack	*a;

	i = 1;
	a = NULL;
	while (argv[i])
	{
		split = ft_split(argv[i], ' ');
		j = 0;
		while (split[j])
		{
			if (!create_numbers(&a, split[j]))
			{
				free_split(split);
				return (NULL);
			}
			j++;
		}
		free_split(split);
		i++;
	}
	return (a);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

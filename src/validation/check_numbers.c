/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:06:29 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/03 11:00:18 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_numbers(char *string)
{
	while (*string)
	{
		if (ft_isalpha(*string))
		{
			return (false);
		}
		string++;
	}
	return (true);
}

bool	is_signal(char string)
{
	if (string == '+' || string == '-')
	{
		return (true);
	}
	return (false);
}

bool	valide_signal(char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (is_signal(string[i])
			&& is_signal(string[i + 1]))
		{
			return (true);
		}
		else if (ft_isdigit(string[i]) && is_signal(string[i + 1]))
		{
			return (true);
		}
		else if (is_signal(string[i]) && string[i + 1] == '\0')
			return (true);
		i++;
	}
	return (false);
}

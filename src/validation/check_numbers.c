/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:06:29 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/01 19:03:44 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_numbers(char *string)
{
	while (*string)
	{
		if (*string != 32 && !ft_isdigit(*string) && !is_signal(*string))
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
		if ((string[i] == '+' || string[i] == '-')
			&& (string[i + 1] == '+' || string[i + 1] ==  '-'))
		{
			return (true);
		}
		else if (ft_isdigit(string[i]) && is_signal(string[i + 1]))
		{
			return (true);
		}
		else if (is_signal(string[i]) && ft_isdigit(string[i + 1]))
		{
			return (false);
		}
		else if ((string[i] == '+' || string[i] == '-') && string[i + 1] == '\0')
			return (true);
		i++;
	}
	return (false);
}

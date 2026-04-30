/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:06:29 by deferrei          #+#    #+#             */
/*   Updated: 2026/04/30 01:13:10 by deferrei         ###   ########.fr       */
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
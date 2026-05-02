/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_overflow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:06:32 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/01 20:26:40 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	string_overflow(char *string)
{
	long	number;

	if (ft_strlen(string) >= 13)
	{
		return (true);
	}
	number = ft_atoi_safe(string);
	if (number > INT_MAX || number < INT_MIN)
	{
		return (true);
	}
	return (false);
}

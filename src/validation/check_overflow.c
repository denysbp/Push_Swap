/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_overflow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:06:32 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/01 19:20:08 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	string_overflow(char *string)
{
	long	number;

	
	number = ft_atoi_safe(string);
	if (number > INT_MAX || number < INT_MIN)
	{
		return (true);
	}
	else
	{
		return (false);
	}
}

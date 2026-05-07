/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_safe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecoelho <pecoelho@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:07:16 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/07 17:01:21 by pecoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	ft_atoi_safe(const char *str)
{
	int		i;
	long	resultado;
	int		signal;

	i = 0;
	resultado = 0;
	signal = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			signal *= -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		resultado = (resultado * 10) + (str[i] - '0');
		i++;
	}
	return (resultado * signal);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecoelho <pecoelho@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:05:59 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/02 12:06:20 by pecoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	radix_sorts(char **nb)
{
	int		sorts;
	int		temp;
	int		i;

	i = 0;
	sorts = 0;
	while (nb[i])
	{
		temp = sorts;
		sorts = ft_strlen(nb[i]);
		if (temp >= sorts)
			sorts = temp;
		i++;
	}
	return (sorts);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecoelho <pecoelho@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 13:28:45 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/07 17:01:21 by pecoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

float	disorder_rate(t_stack *stack)
{
	size_t	elementos;
	int		disorder_elements;
	float	total_pairs;
	t_stack	*i;
	t_stack	*j;

	elementos = stack_size(stack);
	if (!stack || elementos <= 1)
		return (0);
	disorder_elements = 0;
	total_pairs = elementos * (elementos - 1) / 2;
	i = stack;
	while (i)
	{
		j = i -> next;
		while (j)
		{
			if (i -> value > j -> value)
				disorder_elements += 1;
			j = j -> next;
		}
		i = i ->next;
	}
	return ((float)disorder_elements / total_pairs);
}

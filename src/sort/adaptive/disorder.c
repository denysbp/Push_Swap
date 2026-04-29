/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 13:28:45 by deferrei          #+#    #+#             */
/*   Updated: 2026/04/29 13:43:17 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	disorder_rate(t_stack *stack)
{
	size_t	elementos;
	float	disorder;
	int		disorder_elements;

	elementos = stack_size(stack);
	disorder_elements = 0;
	if (!stack || elementos <= 1)
		return (0);
	while (stack -> next)
	{
		if (stack ->value > stack ->next->value)
		{
			disorder_elements += 1;
		}
		stack = stack ->next;
	}
	disorder = (float)disorder_elements / (elementos - 1);
	return (disorder);
}

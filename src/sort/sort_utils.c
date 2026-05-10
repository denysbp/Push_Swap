/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:06:12 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/10 13:55:49 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*find_max(t_stack *a)
{
	t_stack	*max;

	max = a;
	while (a)
	{
		if (a -> index > max -> index)
		{
			max = a;
		}
		a = a -> next;
	}
	return (max);
}

t_stack	*find_min(t_stack *a)
{
	t_stack	*min;

	min = a;
	while (a)
	{
		if (a -> index < min -> index)
		{
			min = a;
		}
		a = a -> next;
	}
	return (min);
}

size_t	get_position(t_stack *stack, t_stack *target)
{
	size_t	pos;

	pos = 0;
	while (stack)
	{
		if (stack == target)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:06:12 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/02 15:30:34 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_max(t_stack *a)
{
	t_stack	*max;

	max = a;
	while (a)
	{
		if (a -> value > max -> value)
		{
			max = a;;
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
		if (a -> value < min -> value)
		{
			min = a;
		}
		a = a -> next;
	}
	return (min);
}
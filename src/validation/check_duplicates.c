/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:06:26 by deferrei          #+#    #+#             */
/*   Updated: 2026/04/30 01:08:27 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_duplicate(t_stack *stack)
{
	t_stack	*temp_stack;

	temp_stack = stack;
	while (stack -> next)
	{
		while (temp_stack -> next)
		{
			if (stack -> value == temp_stack -> next ->value)
			{
				return (true);
			}
			temp_stack = temp_stack -> next;
		}
		stack = stack -> next;
	}
	return (false);
}

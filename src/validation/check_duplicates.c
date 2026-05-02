/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:06:26 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/01 20:09:30 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_duplicate(t_stack *stack)
{
	t_stack	*temp_stack;

	while (stack)
	{
		temp_stack = stack -> next;
		while (temp_stack)
		{
			if (stack -> value == temp_stack ->value)
			{
				return (true);
			}
			temp_stack = temp_stack -> next;
		}
		stack = stack -> next;
	}
	return (false);
}

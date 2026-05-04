/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:05:59 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/04 22:06:47 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_stack *stack)
{
	t_stack	*cur;
	t_stack	*cmp;
	int		index;

	cur = stack;
	while (cur)
	{
		index = 0;
		cmp = stack;
		while (cmp)
		{
			if (cmp->value < cur->value)
				index++;
			cmp = cmp->next;
		}
		cur->index = index;
		cur = cur->next;
	}
}
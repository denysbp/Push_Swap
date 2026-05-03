/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecoelho <pecoelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:07:33 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/02 21:43:14 by pecoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	op_rev_stack(t_stack **stack)
{
	int		temp;
	int		itemp;

	*stack = last_stack(*stack);
	if (!stack || !*stack || !(*stack)->prev)
		return (0);
	while ((*stack)->prev)
	{
		temp = (*stack)->value;
		(*stack)->value = (*stack)->prev->value;
		(*stack)->prev->value = temp;
		itemp = (*stack)->index;
		(*stack)->index = (*stack)->prev->value;
		(*stack)->prev->index = itemp;
		*stack = (*stack)->prev;
	}
	return (1);
}

int	op_rot_both(t_stack **s1, t_stack **s2)
{
	int	check;

	if (!s1 || !s2 || !*s1 || !*s2)
		return (0);
	*s1 = last_stack(*s1);
	check = op_rev_stack(s1);
	if (!check)
		return (0);
	*s2 = last_stack(*s2);
	check = op_rev_stack(s2);
		if (!check)
			return (0);
	return (1);
}

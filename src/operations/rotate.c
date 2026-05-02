/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecoelho <pecoelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:07:36 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/02 21:42:06 by pecoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	op_rot_stack(t_stack **stack)
{
	int		temp;
	int		itemp;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	while ((*stack)->next)
	{
		temp = (*stack)->value;
		(*stack)->value = (*stack)->next->value;
		(*stack)->next->value = temp;
		itemp = (*stack)->index;
		(*stack)->index = (*stack)->next->value;
		(*stack)->next->index = itemp;
		*stack = (*stack)->next;
	}
	return (1);
}

int	op_rot_both(t_stack **s1, t_stack **s2)
{
	int	check;

	if (!s1 || !s2 || !*s1 || !*s2)
		return (0);
	check = op_rot_stack(s1);
	if (!check)
		return (0);
	check = op_rot_stack(s2);
		if (!check)
			return (0);
	return (1);
}

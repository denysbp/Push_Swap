/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecoelho <pecoelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:07:39 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/02 21:41:54 by pecoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	op_swap_stack(t_stack **stack)
{
	int	temp;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	temp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	((*stack)->next)->value = temp;
	temp = (*stack)->index;
	(*stack)->index = (*stack)->next->index;
	((*stack)->next)->index = temp;
	return (1);
}

int	op_swap_both(t_stack **s1, t_stack **s2)
{
	int	check;

	if (!s1 || !s2 || !*s1 || !*s2)
		return (0);
	check = op_swap_stack(s1);
	if (!check)
		return (0);
	check = op_swap_stack(s2);
	if (!check)
		return (0);
	return (1);
}

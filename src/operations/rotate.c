/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:07:36 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/04 15:57:14 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	op_rot_stack(t_stack **stack)
{
	t_stack	*cur;
	int		temp;
	int		itemp;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	cur = *stack;
	while (cur->next)
	{
		temp = cur->value;
		cur->value = cur->next->value;
		cur->next->value = temp;

		itemp = cur->index;
		cur->index = cur->next->index;
		cur->next->index = itemp;
		cur = cur->next;
	}
	return (1);
}

void	ra(t_stack **a)
{
	op_rot_stack(a);
	ft_printf("ra\n");
}

void	rb(t_stack **b)
{
	op_rot_stack(b);
	ft_printf("ra\n");
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

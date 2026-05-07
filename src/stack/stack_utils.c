/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecoelho <pecoelho@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 20:44:33 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/07 17:01:21 by pecoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*new_stack(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new ->value = content;
	new ->index = 0;
	new ->prev = NULL;
	new ->next = NULL;
	return (new);
}

t_stack	*last_stack(t_stack *lst)
{
	while (lst && lst -> next)
	{
		lst = lst ->next;
	}
	return (lst);
}

void	stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!*stack)
	{
		*stack = new;
		return ;
	}
	last = last_stack(*stack);
	last ->next = new;
	new ->prev = last;
}

size_t	stack_size(t_stack *stack)
{
	size_t	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack ->next;
	}
	return (i);
}

void	stack_add_front(t_stack **stack, t_stack *new)
{
	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	new ->next = *stack;
	(*stack)->prev = new;
	new ->prev = NULL;
	*stack = new;
}

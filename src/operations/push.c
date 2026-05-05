/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:07:30 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/05 21:15:03 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_stack **src, t_stack **dest)
{
	t_stack	*node;

	if (!src || !*src || !dest)
		return (0);
	node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node->next = *dest;
	if (*dest)
		(*dest)->prev = node;
	node->prev = NULL;
	*dest = node;
	return (1);
}

int	pa(t_stack **b, t_stack **a, t_bench_mark bench)
{
	int	i;

	i = push(b, a);
	if (!i)
		return (0);
	bench.pa++;
	ft_printf("pa\n");
	return (i);
}

int	pb(t_stack **a, t_stack **b, t_bench_mark bench)
{
	int	i;

	i = push(a, b);
	if (!i)
		return (0);
	bench.pb++;
	ft_printf("pb\n");
	return (i);
}

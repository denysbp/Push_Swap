/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecoelho <pecoelho@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:07:30 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/07 21:30:26 by pecoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_stack **src, t_stack **dest)
{
	t_stack	*node;

	if (!src || !*src || !dest)
		return ;
	node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node->next = *dest;
	if (*dest)
		(*dest)->prev = node;
	node->prev = NULL;
	*dest = node;
}

void	pa(t_stack **b, t_stack **a, t_bench_mark *bench)
{
	push(b, a);
	bench->pa++;
	ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b, t_bench_mark *bench)
{
	push(a, b);
	bench->pb++;
	ft_printf("pb\n");
}

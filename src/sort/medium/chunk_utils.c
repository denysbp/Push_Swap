/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecoelho <pecoelho@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:05:47 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/07 17:01:21 by pecoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/push_swap.h"

size_t	ft_sqrt(size_t chuncks)
{
	size_t	i;

	i = 0;
	while (i * i < chuncks)
	{
		i++;
	}
	return (i);
}

void	push_chunks(t_stack **a, t_stack **b, size_t chunck_size, t_bench_mark *bench)
{
	size_t	i;
	size_t	limit;

	i = 0;
	limit = chunck_size;
	while (*a)
	{
		if ((size_t)(*a)->index < i)
		{
			pb(a,b, bench);
			rb(b, bench);
			i++;
		}
		else if ((size_t)(*a)->index < limit)
		{
			pb(a,b, bench);
			i++;
		}
		else
			ra(a, bench);
		if (i == limit)
			limit += chunck_size;
	}
}

void	push_back_sorted(t_stack **a,t_stack **b, t_bench_mark *bench)
{
	size_t	max_pos;
	size_t	size;
	size_t	count;

	count = 0;
	while (*b)
	{
		max_pos = get_position(*b, find_max(*b));
		size = stack_size(*b);
		if (max_pos <= size / 2)
		{
			while (max_pos--)
			{
				rb(b, bench);
			}
		}
		else
		{
			count = size - max_pos;
			while (count--)
				rrb(b, bench);
		}
		pa(b,a, bench);
	}
}

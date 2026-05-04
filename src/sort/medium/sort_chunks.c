/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:06:05 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/04 18:01:58 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	chunck_sort(t_stack	**stack)
{
	t_stack	*b;

	b = NULL;
	size_t chunck_size;
	chunck_size = ft_sqrt(stack_size(*stack));
	push_chunks(stack, &b, chunck_size);
	push_back_sorted(stack, &b);
}
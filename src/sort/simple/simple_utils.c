/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 20:30:53 by deferrei          #+#    #+#             */
/*   Updated: 2026/04/29 02:02:28 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	bubble_sort(t_stack **stack)
{
	int	troca;
	t_stack	*atual;

	troca = 1;
	while (troca)
	{
		troca = 0;
		atual = *stack;
		while (atual && atual ->next)
		{
			if (atual ->value > atual ->next->value)
			{
				swap(&atual ->value, &atual ->next->value);
				troca = 1;
			}
			atual = atual ->next;
		}
	}
}

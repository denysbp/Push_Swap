/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 13:17:05 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/04 18:04:23 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_choose(t_stack **stack)
{
	float	disorder;

	disorder = disorder_rate(*stack);
	if (disorder <= 0.2 || disorder < 0.5)
	{
		chunck_sort(stack);
	}
	if (disorder < 0.2)
	{
		selection_min(stack);
	}
}

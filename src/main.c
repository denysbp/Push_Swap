/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:06:42 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/04 22:13:32 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (-1);
	t_stack *a;;
	if (!validate_args(argv))
	{
		error();
		return (-1);
	}
	a = parsing(argv);
	if (!a)
	{
		error();
		stack_clear(&a);
		return (-1);
	}
	if (is_duplicate(a))
	{
		error();
		stack_clear(&a);
		return (-1);
	}
	float d = disorder_rate(a);
	if (d == 0)
		return (0);
	// printf("disordem: %.2f\n", d);
	assign_index(a);
	sort_choose(&a);
	// size_t s = stack_size(a);
	// printf("stack size: %lu<\n", s);
	// t_stack *temp = a;
	// while (s != 0)
	// {
	// 	printf(">%d<\n", temp ->value);
	// 	temp = temp-> next;
	// 	s--;
	// }
	stack_clear(&a);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:06:42 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/03 11:04:09 by deferrei         ###   ########.fr       */
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
	// t_stack *ta = find_max(a);
	// t_stack *tas = find_min(a);
	// printf("max = %d", ta->value);
	// printf("min = %d", tas->value);
	if (is_duplicate(a))
	{
		error();
		stack_clear(&a);
		return (-1);
	}
	float d = disorder_rate(a);
	if (d == 0)
		return (0);
	printf("disordem: %.2f\n", d);
	sort_choose(&a);
	int s = stack_size(a);
	printf("stack size: %u<\n", s);
	t_stack *temp = a;
	while (s != 0)
	{
		error();
		return (-1);
	}
	if (string_overflow(argv[1]))
	{
		error();
		return (-1);
	}
	printf("Tamanho: %zu\n", stack_size(a));
	printf("disorder: %.2f\n",disorder_rate(a));

	sort_choose(&a);
	int s = stack_size(a);
	printf("stack size: %u<\n", s);
	t_stack *temp = a;
	while (s != 0)
	{
		printf(">%d<\n", temp ->value);
		temp = temp-> next;
		s--;
	}
	stack_clear(&a);
	return (0);
}

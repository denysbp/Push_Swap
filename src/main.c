/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:06:42 by deferrei          #+#    #+#             */
/*   Updated: 2026/04/29 19:06:43 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

//teste das funções pedrooooo
int	main()
{
	t_stack *a = NULL;

	stack_add_back(&a, new_stack(3));
	stack_add_back(&a, new_stack(7));
	stack_add_back(&a, new_stack(1));
	stack_add_back(&a, new_stack(5));
	stack_add_back(&a, new_stack(8));
	stack_add_back(&a, new_stack(22));
	stack_add_back(&a, new_stack(4));

	printf("Tamanho: %zu\n", stack_size(a));
	printf("disorder: %.2f\n",disorder_rate(a));

	sort_choose(&a);
	int i = 0;
	int d = stack_size(a);
	while(i < d)
	{
		printf("%d\n", a->value);
		a = a->next;
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecoelho <pecoelho@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:07:48 by deferrei          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/05/03 11:02:37 by deferrei         ###   ########.fr       */
=======
/*   Updated: 2026/05/03 11:45:59 by pecoelho         ###   ########.fr       */
>>>>>>> pedro
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdbool.h>
# include "ft_printf.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

void	stack_clear(t_stack **stack);
void	swap(int *a, int *b);
void	stack_add_back(t_stack **stack, t_stack *new);
void	free_split(char **split);
void	stack_add_front(t_stack **stack, t_stack *new);
void	stack_clear(t_stack **lst);
void	stack_delone(t_stack *lst);
void	bubble_sort(t_stack **stack);
void	sort_choose(t_stack **stack);
void	error();
bool	is_duplicate(t_stack *stack);
bool	string_overflow(char *string);
bool	valide_signal(char *string);
bool	is_signal(char string);
bool	check_numbers(char *string);
bool	validate_args(char **argv);
int 	op_swap_stack(t_stack **name);
int		op_rot_stack(t_stack **stack);
int		op_rev_stack(t_stack **stack);
int		op_swap_both(t_stack **s1, t_stack **s2);
int		op_rot_both(t_stack **s1, t_stack **s2);
int		op_rev_both(t_stack **s1, t_stack **s2);
int		radix_sorts(char **nb);
long	ft_atoi_safe(const char *str);
size_t	stack_size(t_stack *stack);
float	disorder_rate(t_stack *stack);
t_stack	*last_stack(t_stack *lst);
t_stack	*new_stack(int content);
t_stack	*find_max(t_stack *a);
t_stack	*first_stack(t_stack *lst);
t_stack	*parsing(char **argv);
t_stack	*find_min(t_stack *a);


#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:07:48 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/06 23:58:53 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdbool.h>
# include "ft_printf.h"

typedef struct struct_bench
{
	bool	display;
	int		sa;
	int		sb;
	int		pa;
	int		pb;
	int		ss;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	int		strategy;
	int		total;
	float	disorder;
}	t_bench_mark;

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

void			print_float(float ds);
void			stack_clear(t_stack **stack);
void			swap(int *a, int *b);
void			stack_add_back(t_stack **stack, t_stack *new);
void			free_split(char **split);
void			stack_add_front(t_stack **stack, t_stack *new);
void			stack_clear(t_stack **lst);
void			stack_delone(t_stack *lst);
void			sort_choose(t_stack **stack, t_bench_mark *bench);
void			error(void);
void			selection_min(t_stack **stack, t_bench_mark *bench);
void			push_chunks(t_stack **a, t_stack **b, size_t chunck_size,\
	t_bench_mark *bench);
void			push_back_sorted(t_stack **a, t_stack **b, t_bench_mark *bench);
void			chunck_sort(t_stack	**stack, t_bench_mark *bench);
void			assign_index(t_stack **stack);
void			print_bench(t_bench_mark *bench);
void			adaptive_flags(t_stack **stack, t_bench_mark *bench);
void			complex_flags(t_stack **stack, t_bench_mark *bench);
void			medium_flags(t_stack **stack, t_bench_mark *bench);
void			simple_flag(t_stack **stack, t_bench_mark *bench);
bool			is_duplicate(t_stack *stack);
bool			string_overflow(char *string);
bool			valide_signal(char *string);
bool			is_signal(char string);
bool			check_numbers(char *string);
bool			validate_args(char **argv);
int				parse_flags(t_stack **stack, char **argv,\
	t_bench_mark *bench, int i);
int				parsing_vaidations(t_stack **stack, char **argv);
int				op_swap_stack(t_stack **name);
int				sa(t_stack **a, t_bench_mark *bench);
int				sb(t_stack **b, t_bench_mark *bench);
int				op_rot_stack(t_stack **stack);
int				op_rev_stack(t_stack **stack);
int				op_swap_both(t_stack **s1, t_stack **s2, t_bench_mark *bench);
int				op_rot_both(t_stack **s1, t_stack **s2, t_bench_mark *bench);
int				op_rev_both(t_stack **s1, t_stack **s2, t_bench_mark *bench);
int				push(t_stack **src, t_stack **dest);
int				pa(t_stack **b, t_stack **a, t_bench_mark *bench);
int				pb(t_stack **a, t_stack **b, t_bench_mark *bench);
int				rra(t_stack **a, t_bench_mark *bench);
int				rrb(t_stack **b, t_bench_mark *bench);
int				ra(t_stack **a, t_bench_mark *bench);
int				rb(t_stack **b, t_bench_mark *bench);
int				stackb_cleanup(t_stack **a, t_stack **b, t_bench_mark *bench);
int				stack_selection(t_stack **a, t_stack **b, int mask,\
	t_bench_mark *bench);
int				radix(t_stack **a, t_bench_mark *bench);
long			ft_atoi_safe(const char *str);
size_t			stack_size(t_stack *stack);
size_t			get_position(t_stack *stack, t_stack *target);
size_t			ft_sqrt(size_t chuncks);
size_t			strategy(t_bench_mark *bench);
float			disorder_rate(t_stack *stack);
t_stack			*last_stack(t_stack *lst);
t_stack			*new_stack(int content);
t_stack			*find_max(t_stack *a);
t_stack			*parsing(char **argv);
t_stack			*find_min(t_stack *a);
t_bench_mark	init_bench(t_bench_mark bench);

#endif
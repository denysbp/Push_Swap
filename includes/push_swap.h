/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:07:48 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/08 02:48:08 by deferrei         ###   ########.fr       */
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

typedef struct s_parse_ctx
{
	char	**argv;
	int		start;
	int		mode;
}	t_parse_ctx;

void			print_float(float ds);
void			stack_clear(t_stack **stack);
void			swap(int *a, int *b);
void			stack_add_back(t_stack **stack, t_stack *new);
void			free_split(char **split);
void			stack_add_front(t_stack **stack, t_stack *new);
void			stack_clear(t_stack **lst);
void			stack_delone(t_stack *lst);
void			sort_choose(t_stack **a, t_stack **b, t_bench_mark *bench);
void			error(void);
void			selection_min(t_stack **a, t_stack **b, t_bench_mark *bench);
void			push_chunks(t_stack **a, t_stack **b, size_t chunck_size,\
	t_bench_mark *bench);
void			push_back_sorted(t_stack **a, t_stack **b, t_bench_mark *bench);
void			chunck_sort(t_stack	**stack, t_stack **b, t_bench_mark *bench);
void			radix(t_stack **a, t_stack **b, t_bench_mark *bench);
void			assign_index(t_stack **stack);
void			print_bench(t_bench_mark *bench);
size_t			strategy(t_bench_mark *bench);
void			print_bench_2(t_bench_mark *bench);
int				adaptive_flags(t_stack **a, t_stack **b, t_bench_mark *bench,
					t_parse_ctx input);
int				complex_flags(t_stack **a, t_stack **b, t_bench_mark *bench,
					t_parse_ctx input);
int				medium_flags(t_stack **a, t_stack **b, t_bench_mark *bench,
					t_parse_ctx input);
int				simple_flag(t_stack **a, t_stack **b, t_bench_mark *bench,
					t_parse_ctx input);
int				finish_main(int result, t_stack **a, t_bench_mark *bench);
void			sort_three(t_stack **a, t_bench_mark *bench);
void			sort_four(t_stack **a, t_stack **b, t_bench_mark *bench);
void			sort_five(t_stack **a, t_stack **b, t_bench_mark *bench);
void			tiny_sort(t_stack **a, t_stack **b, t_bench_mark *bench);
bool			is_duplicate(t_stack *stack);
bool			string_overflow(char *string);
bool			valide_signal(char *string);
bool			is_signal(char string);
bool			check_numbers(char *string);
bool			validate_args(char **argv);
int				parse_flags(t_stack **a, t_stack **b, t_bench_mark *bench,
					t_parse_ctx input);
int				parsing_vaidations(t_stack **stack, char **argv);
int				only_null(char **argv);
int				handle_bench(t_stack **a, t_stack **b, t_bench_mark *bench,
					t_parse_ctx input);
int				handle_strategy(t_stack **a, t_stack **b, t_bench_mark *bench,
					t_parse_ctx input);
void			op_swap_stack(t_stack **name);
void			sa(t_stack **a, t_bench_mark *bench);
void			sb(t_stack **b, t_bench_mark *bench);
void			op_rot_stack(t_stack **stack);
void			op_rev_stack(t_stack **stack);
void			ss(t_stack **s1, t_stack **s2, t_bench_mark *bench);
void			rr(t_stack **a, t_stack **b, t_bench_mark *bench);
void			rrr(t_stack **a, t_stack **b, t_bench_mark *bench);
void			push(t_stack **src, t_stack **dest);
void			pa(t_stack **b, t_stack **a, t_bench_mark *bench);
void			pb(t_stack **a, t_stack **b, t_bench_mark *bench);
void			rra(t_stack **a, t_bench_mark *bench);
void			rrb(t_stack **b, t_bench_mark *bench);
void			ra(t_stack **a, t_bench_mark *bench);
void			rb(t_stack **b, t_bench_mark *bench);
void			stackb_cleanup(t_stack **a, t_stack **b, t_bench_mark *bench);
void			stack_selection(t_stack **a, t_stack **b, int mask,\
	t_bench_mark *bench);

long			ft_atoi_safe(const char *str);
size_t			is_above_median(t_stack **stack, t_stack *node);
size_t			stack_size(t_stack *stack);
size_t			get_position(t_stack *stack, t_stack *target);
size_t			ft_sqrt(size_t chuncks);
float			disorder_rate(t_stack *stack);
t_stack			*last_stack(t_stack *lst);
t_stack			*new_stack(int content);
t_stack			*find_max(t_stack *a);
t_stack			*parsing(char **argv);
t_stack			*find_min(t_stack *a);
t_bench_mark	init_bench(t_bench_mark bench);
char			**build_argv_view(char **argv, int start);
int				run_strategy(t_stack **stack, t_parse_ctx input);

#endif
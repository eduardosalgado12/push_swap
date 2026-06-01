/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khooftma <khooftma@://42porto.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 15:21:04 by khooftma          #+#    #+#             */
/*   Updated: 2026/06/01 16:56:46 by khooftma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef enum e_strategy
{
	STRAT_ADAPTIVE,
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX
}					t_strategy;

// stack_init
int					stack_init(int argc, char **argv, t_stack **a,
						t_strategy *strat);

// errors
int					errors_syntax(char *str);
int					errors_duplicate(t_stack *a, int n);
void				free_errors(t_stack **a);
void				free_stack(t_stack **stack);
long				ft_atol(const char *nptr);

// split
char				**ft_split(char const *s, char c);

// commands
void				sa(t_stack **a);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);

void				ra(t_stack **a);
void				rra(t_stack **a);
void				rb(t_stack **b);
void				rrb(t_stack **b);
void				rr(t_stack **a, t_stack **b);
void				rrr(t_stack **a, t_stack **b);

void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);

// utils
int					ft_lstsize(t_stack *lst);
bool				stack_sorted(t_stack *a);
int					ft_sqrt(int number);
void				assign_indices(t_stack *stack);
double				disorder_metric(t_stack *a);

// utils stack init
int					ft_strcmp(const char *s1, const char *s2);
void				free_matrix(char **matrix);

// algorithms
void				sort_three(t_stack **a);

// simple
void				selection_sort(t_stack **stack_a, t_stack **stack_b);

// utils simple
void				push_min_to_b(t_stack **stack_a, t_stack **stack_b);
void				rotate_and_push_a(t_stack **stack_a, t_stack **stack_b,
						int pos);
int					get_min_pos_local(t_stack *stack);
int					get_closest_in_range(t_stack *stack, int limit);
void				rotate_and_push_b(t_stack **stack_a, t_stack **stack_b,
						int max_pos);

// medium
void				chunk_sort(t_stack **stack_a, t_stack **stack_b);

// complex
void	quick_sort_a(t_stack **a, t_stack **b, int size);

// adaptive
void				adaptive_sort(t_stack **a, t_stack **b, double disorder);

// optimizer
void				write_op(char *op);
void				flush_op(void);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khooftma <khooftma@://42porto.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 15:21:04 by khooftma          #+#    #+#             */
/*   Updated: 2026/06/09 14:28:21 by khooftma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include "ft_printf/ft_printf.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

typedef enum e_strategy
{
	STRAT_ADAPTIVE,
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX
}					t_strategy;

typedef struct s_bench
{
	bool			is_checker;
	bool			active;
	bool			count_only;
	int				sa;
	int				sb;
	int				ss;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	int				total_ops;
	double			disorder;
	t_strategy		strat;
}					t_bench;


// stack_init
int					stack_init(int argc, char **argv, t_stack **a,
						t_bench *bench);

// errors
int					errors_syntax(char *str);
int					errors_duplicate(t_stack *a, int n);
void				free_stack(t_stack **stack);
long				ft_atol(const char *nptr);

// split
char				**ft_split(char const *s, char c);

// commands
void				sa(t_stack **a, t_bench *bench);
void				sb(t_stack **b, t_bench *bench);
void				ss(t_stack **a, t_stack **b, t_bench *bench);

void				ra(t_stack **a, t_bench *bench);
void				rra(t_stack **a, t_bench *bench);
void				rb(t_stack **b, t_bench *bench);
void				rrb(t_stack **b, t_bench *bench);
void				rr(t_stack **a, t_stack **b, t_bench *bench);
void				rrr(t_stack **a, t_stack **b, t_bench *bench);

void				pa(t_stack **a, t_stack **b, t_bench *bench);
void				pb(t_stack **a, t_stack **b, t_bench *bench);

// utils
int					ft_lstsize(t_stack *lst);
bool				stack_sorted(t_stack *a);
int					ft_sqrt(int number);
void				assign_indices(t_stack *stack);
double				disorder_metric(t_stack *a);

// utils 2
int					ft_strcmp(const char *s1, const char *s2);
void				free_matrix(char **matrix);
void				ft_bzero(void *s, size_t n);
void				ft_swap(int *a, int *b);
t_stack				*find_last(t_stack *stack);

// algorithms
void				sort_two_or_three(t_stack **a, t_bench *bench);
void 				sort_five(t_stack **a,t_stack **b, t_bench *bench);
// Voeg deze regels toe aan push_swap.h:
// simple
void				selection_sort(t_stack **stack_a, t_stack **stack_b,
						t_bench *bench);

// utils simple
void				push_min_to_b(t_stack **stack_a, t_stack **stack_b,
						t_bench *bench);
void				rotate_and_push_a(t_stack **stack_a, t_stack **stack_b,
						int pos, t_bench *bench);
int					get_min_pos_local(t_stack *stack);
int					get_closest_in_range(t_stack *stack, int limit);
void				rotate_and_push_b(t_stack **stack_a, t_stack **stack_b,
						int max_pos, t_bench *bench);

// utils complex

bool				sorted_asc(t_stack *a, int size);
bool				sorted_desc(t_stack *b, int size);
int					get_median(t_stack *stack, int size);
void				sort_small_a(t_stack **a, int size, t_bench *bench);


// medium
void				chunk_sort(t_stack **stack_a, t_stack **stack_b,
						t_bench *bench);

// complex
void				quick_sort_a(t_stack **a, t_stack **b, int size,
						t_bench *bench);

// adaptive
void				adaptive_sort(t_stack **a, t_stack **b, double disorder,
						t_bench *bench);

// optimizer
void				write_op(char *op);
void				flush_op(void);

//checker get_next_line
char				*get_next_line(int fd);

//get_next_line_utils
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif
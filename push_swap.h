/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khooftma <khooftma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 15:21:04 by khooftma          #+#    #+#             */
/*   Updated: 2026/05/26 14:35:19 by khooftma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

//stack_init
void	stack_init(t_stack **a, char **argv);

//errors
int		errors_syntax(char *str);
int		errors_duplicate(t_stack *a, int n);
void	free_errors(t_stack	**a);

// split
char	**ft_split(char const *s, char c);

//commands
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

void	ra(t_stack **a);
void	rra(t_stack **a);
void 	rb(t_stack **b);
void 	rrb(t_stack **b);
void 	rr(t_stack **a, t_stack **b);
void 	rrr(t_stack **a, t_stack **b);

void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

// utils
int		ft_lstsize(t_stack *lst);
bool	stack_sorted(t_stack *a);

//disorder
double disorder_metric(t_stack *a);

// algorithms
void	sort_three(t_stack **a);

// simple
void	selection_sort(t_stack **stack_a, t_stack **stack_b);

// medium
void	chunk_sort(t_stack **stack_a, t_stack **stack_b);

#endif
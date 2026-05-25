/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khooftma <khooftma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 15:21:04 by khooftma          #+#    #+#             */
/*   Updated: 2026/05/25 12:16:29 by khooftma         ###   ########.fr       */
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
    int             value;       // O número original recebido por parâmetro
    int             index;       // A posição dele se estivesse ordenado (0 a N-1)
    struct s_stack  *next;       // Ponteiro para o próximo nó abaixo na pilha
    struct s_stack  *prev;       // Ponteiro para o nó anterior acima na pilha
}   t_stack;

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
int		stack_len(t_stack *a);

//disorder
double disorder_metric(t_stack *a);

// algorithms
void	sort_three(t_stack **a);

void	algo_simple(t_stack **a, t_stack **b);
void	algo_medium(t_stack **a, t_stack **b);
void	algo_complex(t_stack **a, t_stack **b);
void	algo_adaptive(t_stack **a, t_stack **b);

// simple

int	find_min_value(t_stack *stack);
void	selection_sort(t_stack **a, t_stack **b);

#endif
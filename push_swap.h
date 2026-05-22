/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khooftma <khooftma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 15:21:04 by khooftma          #+#    #+#             */
/*   Updated: 2026/05/22 17:01:20 by khooftma         ###   ########.fr       */
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
void	sa(t_stack **a, int print);
bool	stack_sorted(t_stack *a);
int		stack_len(t_stack *a);
void	swap(t_stack **stack);
void	rotate(t_stack **stack);
void 	reverse_rotate(t_stack **stack);
void	push(t_stack **dst, t_stack **src);
void	ra(t_stack **a, int print);
void	rra(t_stack **a, int print);

// utils
int		ft_lstsize(t_stack *lst);

//disorder
double disorder_metric(t_stack *a);


// algorithms
void	sort_three(t_stack **a);

void	algo_simple(t_stack **a, t_stack **b);
void	algo_medium(t_stack **a, t_stack **b);
void	algo_complex(t_stack **a, t_stack **b);
void	algo_adaptive(t_stack **a, t_stack **b);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khooftma <khooftma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 15:21:04 by khooftma          #+#    #+#             */
/*   Updated: 2026/05/22 11:50:55 by khooftma         ###   ########.fr       */
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

void	stack_init(t_stack **a, char **argv);

int		errors_syntax(char *str);
int		errors_duplicate(t_stack *a, int n);
void	free_errors(t_stack	**a);

char	**ft_split(char const *s, char c);

void	swap_a(t_stack **sa);
bool	stack_sorted(t_stack *sa);
int		stack_len(t_stack *sa);
void	swap(t_stack **stack);


void	rotate(t_stack **stack);
void 	reverse_rotate(t_stack **stack);

void	push(t_stack **dst, t_stack **src);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edsalgad <edsalgad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 15:21:04 by khooftma          #+#    #+#             */
/*   Updated: 2026/05/20 16:18:49 by edsalgad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>

typedef struct s_stack
{
    int             value;       // O número original recebido por parâmetro
    int             index;       // A posição dele se estivesse ordenado (0 a N-1)
    struct s_stack  *next;       // Ponteiro para o próximo nó abaixo na pilha
    struct s_stack  *prev;       // Ponteiro para o nó anterior acima na pilha
}   t_stack;

int	    ft_lstsize(t_stack *lst);
void	stack_init_a(t_stack **a, char **argv);

#endif
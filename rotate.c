/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khooftma <khooftma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 10:36:18 by khooftma          #+#    #+#             */
/*   Updated: 2026/05/22 16:21:32 by khooftma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;
	
	if (!stack || !*stack || !(*stack)->next)
		return ;
	
	first = *stack;
	last = *stack;
	
	while (last->next)
		last = last->next;
	*stack = first->next;
	(*stack)->prev = NULL;
	last->next = first;
	first->next = NULL;
	first->prev = last;
}

void reverse_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;
	
	if (!stack || !*stack || !(*stack)->next)
		return ;
	
	first = *stack;
	last = *stack;
	
	while (last->next)
		last = last->next;
		
	last->prev->next = NULL;
	last->next = first;
	first->prev = last;
	*stack = last;
	last->prev = NULL;
}

void ra(t_stack **a, int print)
{
	rotate(a);
	if (print == 1)
		write(1, "ra\n", 3);
}

void rra(t_stack **a, int print)
{
	reverse_rotate(a);
	if (print == 1)
		write(1, "rra\n", 3);
}
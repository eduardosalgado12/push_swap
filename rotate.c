/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khooftma <khooftma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 10:36:18 by khooftma          #+#    #+#             */
/*   Updated: 2026/05/25 14:42:30 by khooftma         ###   ########.fr       */
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
	first->prev = last;
	first->next = NULL;
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

void ra(t_stack **a)
{
	rotate(a);
		write(1, "ra\n", 3);
}

void rra(t_stack **a)
{
	reverse_rotate(a);
		write(1, "rra\n", 4);
}

void rb(t_stack **b)
{
	rotate(b);
		write(1, "rb\n", 3);
}

void rrb(t_stack **b)
{
	reverse_rotate(b);
		write(1, "rrb\n", 4);
}

void rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
		write(1, "rr\n", 3);
}

void rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
		write(1, "rrr\n", 4);
}

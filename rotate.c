/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khooftma <khooftma@://42porto.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 10:36:18 by khooftma          #+#    #+#             */
/*   Updated: 2026/05/29 15:27:07 by khooftma         ###   ########.fr       */
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
	last->next = first;
	first->next = NULL;
}

void	ra(t_stack **a)
{
	rotate(a);
	write_op("ra");
}

void	rb(t_stack **b)
{
	rotate(b);
	write_op("rb");
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write_op("rr");
}

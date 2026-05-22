/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khooftma <khooftma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:46:26 by khooftma          #+#    #+#             */
/*   Updated: 2026/05/22 16:17:29 by khooftma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack *a)
{
	int	count;

	count = 0;
	while (a)
	{
		count++;
		a = a->next;
	}
	return (count);
}

bool	stack_sorted(t_stack *a)
{
	if (!a)
		return (true);
	while (a->next)
	{
		if (a->value > a->next->value)
			return (false);
		a = a->next;
	}
	return (true);
}

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;

	first = *stack;
	second = first->next;
	
	first->next = second->next;
	
	if (second->next)
		second->next->prev = first;
	
	second->prev = first->prev;
	second->next = first;
	first->prev = second;
	*stack = second;
}

void	sa(t_stack **a, int print)
{
	swap(a);
	if (print == 1)
		write(1, "sa\n", 3);
}
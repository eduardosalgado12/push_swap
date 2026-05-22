/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khooftma <khooftma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:46:26 by khooftma          #+#    #+#             */
/*   Updated: 2026/05/22 10:21:54 by khooftma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack *sa)
{
	int	count;

	count = 0;
	while (sa)
	{
		count++;
		sa = sa->next;
	}
	return (count);
}

bool	stack_sorted(t_stack *sa)
{
	if (!sa)
		return (true);
	while (sa->next)
	{
		if (sa->value > sa->next->value)
			return (false);
		sa = sa->next;
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

void	swap_a(t_stack **sa)
{
	swap(sa);
	write(1, "sa\n", 3);
}


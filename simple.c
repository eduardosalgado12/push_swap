/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khooftma <khooftma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 09:31:16 by khooftma          #+#    #+#             */
/*   Updated: 2026/05/25 15:08:41 by khooftma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_value(t_stack *stack)
{
	int	min;
	
	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}


void	selection_sort(t_stack **a, t_stack **b)
{
	int	i;
	int min;

	i = 0;
	while (*a)
	{
		min = find_min_value(*a);
		while ((*a)->value != min)
			ra(a);
		pb(a, b);
		i++;
	}
	while (i > 0)
	{
		pa(a, b);
		i--;
	}	
}
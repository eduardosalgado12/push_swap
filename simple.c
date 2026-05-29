/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khooftma <khooftma@://42porto.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 15:11:23 by khooftma          #+#    #+#             */
/*   Updated: 2026/05/29 15:11:26 by khooftma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min_pos_local(t_stack *stack)
{
	int	min_val;
	int	min_pos;
	int	i;

	if (!stack)
		return (0);
	min_val = stack->value;
	min_pos = 0;
	i = 0;
	while (stack)
	{
		if (stack->value < min_val)
		{
			min_val = stack->value;
			min_pos = i;
		}
		stack = stack->next;
		i++;
	}
	return (min_pos);
}

void	selection_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	pos;
	int	size;

	while (ft_lstsize(*stack_a) > 3)
	{
		pos = get_min_pos_local(*stack_a);
		size = ft_lstsize(*stack_a);
		if (pos <= size / 2)
		{
			while (pos-- > 0)
				ra(stack_a);
		}
		else
		{
			while (pos++ < size)
				rra(stack_a);
		}
		pb(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}

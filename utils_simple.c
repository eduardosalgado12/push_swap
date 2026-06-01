/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_simple.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khooftma <khooftma@://42porto.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 15:24:05 by khooftma          #+#    #+#             */
/*   Updated: 2026/06/01 15:25:10 by khooftma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_min_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int	pos;
	int	size;

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

void	rotate_and_push_a(t_stack **stack_a, t_stack **stack_b, int pos)
{
	if (pos <= ft_lstsize(*stack_a) / 2)
	{
		while (pos-- > 0)
			ra(stack_a);
	}
	else
	{
		while (pos++ < ft_lstsize(*stack_a))
			rra(stack_a);
	}
	pb(stack_a, stack_b);
}

int	get_min_pos_local(t_stack *stack)
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

int	get_closest_in_range(t_stack *stack, int limit)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->index < limit)
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1);
}

void	rotate_and_push_b(t_stack **stack_a, t_stack **stack_b, int max_pos)
{
	int	size;

	size = ft_lstsize(*stack_b);
	if (max_pos <= size / 2)
	{
		while (max_pos-- > 0)
			rb(stack_b);
	}
	else
	{
		while (max_pos++ < size)
			rrb(stack_b);
	}
	pa(stack_a, stack_b);
}
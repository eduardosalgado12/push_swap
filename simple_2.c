/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edsalgad <edsalgad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 11:48:40 by edsalgad          #+#    #+#             */
/*   Updated: 2026/05/25 15:16:13 by edsalgad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_stack_size(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack != NULL)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

int	get_min_pos(t_stack *stack)
{
	t_stack	*current;
	int		min_value;
	int		min_pos;
	int		i;

	current = stack;
	min_value = current->value;
	min_pos = 0;
	i = 0;
	while (current)
	{
		if (current->value < min_value)
		{
			min_value = current->value;
			min_pos = i;
		}
		current = current->next;
		i++;
	}
	return (min_pos);
}

void	simple(t_stack **stack_a, t_stack **stack_b)
{
	int	pos;
	int	size;


	while (*stack_a)
	{
		pos = get_min_pos(*stack_a);
		size = get_stack_size(*stack_a);
		if (pos <= size / 2)
			while (pos-- > 0)
				ra(stack_a);
		else
			while (pos++ < size)
				rra(stack_a);
				
		pb(stack_a, stack_b);
	}
	while (*stack_b)
		pa(stack_a, stack_b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khooftma <khooftma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 09:31:16 by khooftma          #+#    #+#             */
/*   Updated: 2026/05/27 15:24:14 by khooftma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	selection_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	pos;
	int	size;

	while (ft_lstsize(*stack_a) > 3)
	{
		pos = get_min_pos(*stack_a);
		size = ft_lstsize(*stack_a);
		if (pos <= size / 2)
			while (pos-- > 0)
				ra(stack_a);
		else
			while (pos++ < size)
				rra(stack_a);
		pb(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}

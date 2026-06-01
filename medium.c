/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khooftma <khooftma@://42porto.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 11:08:10 by khooftma          #+#    #+#             */
/*   Updated: 2026/06/01 16:11:06 by khooftma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_pos(t_stack *stack)
{
	t_stack	*current;
	int		max_value;
	int		max_pos;
	int		i;

	if (!stack)
		return (-1);
	current = stack;
	max_value = current->value;
	max_pos = 0;
	i = 0;
	while (current)
	{
		if (current->value > max_value)
		{
			max_value = current->value;
			max_pos = i;
		}
		current = current->next;
		i++;
	}
	return (max_pos);
}

static int	get_chunk_pos(t_stack *stack, int max_val)
{
	t_stack	*current;
	int		i;

	current = stack;
	i = 0;
	while (current)
	{
		if (current->index < max_val)
			return (i);
		current = current->next;
		i++;
	}
	return (-1);
}

void	chunk_sort_b(t_stack **stack_a, t_stack **stack_b)
{
	int	pos;

	while (*stack_b)
	{
		pos = get_max_pos(*stack_b);
		if (pos == -1)
			break ;
		if (pos <= ft_lstsize(*stack_b) / 2)
			while (pos-- > 0)
				rb(stack_b);
		else
			while (pos++ < ft_lstsize(*stack_b))
				rrb(stack_b);
		pa(stack_a, stack_b);
	}
}

double chunk_size_factor(t_stack **stack_a)
{
	double factor;

	if(ft_lstsize(*stack_a) <= 100)
		factor = 1.8;
	else if (ft_lstsize(*stack_a) > 100 && ft_lstsize(*stack_a) <= 300 )
		factor = 2.0;
	else if (ft_lstsize(*stack_a) > 300)
		factor = 2.2;
	return(factor);
}

void	chunk_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	chunk_size;
	int	max_val;
	int	pos;

	assign_indices(*stack_a);
	chunk_size = (int)ft_sqrt(ft_lstsize(*stack_a))*chunk_size_factor(stack_a);
	max_val = chunk_size;
	while (*stack_a)
	{
		pos = get_chunk_pos(*stack_a, max_val);
		if (pos == -1)
			max_val += chunk_size;
		else
		{
			if (pos <= ft_lstsize(*stack_a) / 2)
				while (pos-- > 0)
					ra(stack_a);
			else
				while (pos++ < ft_lstsize(*stack_a))
					rra(stack_a);
			pb(stack_a, stack_b);
		}
	}
	chunk_sort_b(stack_a, stack_b);
}


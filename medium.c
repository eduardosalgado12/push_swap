/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khooftma <khooftma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 11:08:10 by khooftma          #+#    #+#             */
/*   Updated: 2026/05/26 14:48:20 by khooftma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sqrt(int number)
{
	int	i;

	i = 1;
	while (i * i <= number)
		i++;
	return (i - 1);
}

static void	assign_indices(t_stack *stack)
{
	t_stack	*current;
	t_stack	*compare;
	int		*temp_values;
	int		size;
	int		i;

	size = ft_lstsize(stack);
	temp_values = (int *)malloc(size * sizeof(int));
	if (!temp_values)
		return ;
	current = stack;
	i = 0;
	while (current)
	{
		temp_values[i] = 0;
		compare = stack;
		while (compare)
		{
			if (compare->value < current->value)
				temp_values[i]++;
			compare = compare->next;
		}
		current = current->next;
		i++;
	}
	// Nu pas overschrijven we de waardes veilig in de stack
	current = stack;
	i = 0;
	while (current)
	{
		current->index = temp_values[i++];
		current = current->next;
	}
	free(temp_values);
}

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
	while(current)
	{
		if (current->index <= max_val)
			return (i);
		current = current->next;
		i++;
	}
	return (-1);
}

void	chunk_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	chunk_size;
	int	max_val;
	int	pos;

	assign_indices(*stack_a);
	size = ft_lstsize(*stack_a);
	chunk_size = (int)ft_sqrt(size) * 1.8;
	if (chunk_size < 1)
		chunk_size = 1;
	max_val = chunk_size;

	while (*stack_a)
	{
		pos = get_chunk_pos(*stack_a, max_val);
		
		if (pos == -1)
		{
			max_val += chunk_size;
			continue ;
		}
		size = ft_lstsize(*stack_a);
		if (pos <= size / 2)
			while (pos-- > 0)
				ra(stack_a);
		else
			while (pos++ < size)
				rra(stack_a);
					pb(stack_a, stack_b);
	}
	while (*stack_b)
	{
		pos = get_max_pos(*stack_b);
		if (pos == -1)
			break ;
		size = ft_lstsize(*stack_b);
		
		if (pos <= size / 2)
			while (pos-- > 0)
				rb(stack_b);
		else
			while (pos++ < size)
				rrb(stack_b);
		pa(stack_a, stack_b);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khooftma <khooftma@://42porto.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 15:24:23 by khooftma          #+#    #+#             */
/*   Updated: 2026/06/01 15:30:24 by khooftma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pull_max_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		max_idx;
	int		max_pos;
	int		curr;

	while (*stack_b)
	{
		max_idx = (*stack_b)->index;
		max_pos = 0;
		curr = 0;
		tmp = *stack_b;
		while (tmp)
		{
			if (tmp->index >= max_idx)
			{
				max_idx = tmp->index;
				max_pos = curr;
			}
			tmp = tmp->next;
			curr++;
		}
		rotate_and_push_b(stack_a, stack_b, max_pos);
	}
}

void	selection_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	tot;
	int	chunks;
	int	i;
	int	pos;

	tot = ft_lstsize(*stack_a);
	chunks = 1;
	if (tot > 100)
		chunks = 5;
	i = 0;
	while (++i < chunks)
	{
		while (1)
		{
			pos = get_closest_in_range(*stack_a, (tot / chunks) * i);
			if (pos == -1)
				break ;
			rotate_and_push_a(stack_a, stack_b, pos);
		}
	}
	while (ft_lstsize(*stack_a) > 3)
		push_min_to_b(stack_a, stack_b);
	sort_three(stack_a);
	pull_max_to_a(stack_a, stack_b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khooftma <khooftma@://42porto.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 12:01:41 by edsalgad          #+#    #+#             */
/*   Updated: 2026/05/29 12:55:14 by khooftma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort_a(t_stack **a, t_stack **b, int size);
void	quick_sort_b(t_stack **a, t_stack **b, int size);

static int	is_sorted_b_range(t_stack *b, int size)
{
	if (!b || size <= 1)
		return (1);
	while (size > 1 && b->next)
	{
		if (b->index < b->next->index)
			return (0);
		b = b->next;
		size--;
	}
	return (1);
}

static int	get_median(t_stack *stack, int size)
{
	int		*arr;
	int		i;
	int		j;
	int		swap;
	int		median;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (0);
	i = 0;
	while (i < size && stack)
	{
		arr[i] = stack->index;
		stack = stack->next;
		i++;
	}
	i = -1;
	while (++i < size - 1)
	{
		j = -1;
		while (++j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				swap = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = swap;
			}
		}
	}
	median = arr[size / 2];
	free(arr);
	return (median);
}

static void	sort_small_a(t_stack **a, t_stack **b, int size)
{
	if (size == 2)
	{
		if ((*a)->index > (*a)->next->index)
			sa(a);
	}
	else if (size == 3)
	{
		if ((*a)->index > (*a)->next->index)
			sa(a);
		pb(a, b);
		if ((*a)->index > (*a)->next->index)
			sa(a);
		pa(a, b);
		if ((*a)->index > (*a)->next->index)
			sa(a);
	}
}

void	quick_sort_a(t_stack **a, t_stack **b, int size)
{
	int	median;
	int	pushed;
	int	rotated;
	int	i;

	if (size <= 1 || stack_sorted_range(*a, size))
		return ;
	if (size <= 3)
	{
		sort_small_a(a, b, size);
		return ;
	}
	median = get_median(*a, size);
	pushed = 0;
	rotated = 0;
	i = 0;
	while (i < size)
	{
		if ((*a)->index < median)
		{
			pb(a, b);
			pushed++;
		}
		else
		{
			ra(a);
			rotated++;
		}
		i++;
	}
	// THE BENCHMARK WINNER FOR A: Sla het terugdraaien over bij de hoofd-lus!
	if (ft_lstsize(*a) != rotated)
	{
		i = 0;
		while (i < rotated)
		{
			rra(a);
			i++;
		}
	}
	quick_sort_a(a, b, size - pushed);
	quick_sort_b(a, b, pushed);
}

void	quick_sort_b(t_stack **a, t_stack **b, int size)
{
	int	median;
	int	pushed;
	int	rotated;
	int	i;

	if (size <= 0 || !*b || is_sorted_b_range(*b, size))
	{
		i = 0;
		while (i++ < size)
			pa(a, b);
		return ;
	}
	median = get_median(*b, size);
	pushed = 0;
	rotated = 0;
	i = 0;
	while (i < size)
	{
		if ((*b)->index >= median)
		{
			pa(a, b);
			pushed++;
		}
		else
		{
			rb(b);
			rotated++;
		}
		i++;
	}
	quick_sort_a(a, b, pushed);
	// SLIM HERSTEL VOOR B: Draai alleen terug als er al data onder ligt
	if (ft_lstsize(*b) != rotated)
	{
		i = 0;
		while (i < rotated)
		{
			rrb(b);
			i++;
		}
	}
	quick_sort_b(a, b, size - pushed);
}

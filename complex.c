/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khooftma <khooftma@://42porto.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 12:01:41 by edsalgad          #+#    #+#             */
/*   Updated: 2026/06/01 16:50:12 by khooftma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort_a(t_stack **a, t_stack **b, int size);
void	quick_sort_b(t_stack **a, t_stack **b, int size);

static int	is_sorted__range(t_stack *a, int size)
{
	if (!a || size <= 1)
		return (1);
	while (size > 1 && a->next)
	{
		if (a->index < a->next->index)
			return (0);
		a = a->next;
		size--;
	}
	return (1);
}

bool	stack_sorted_range(t_stack *a, int size)
{
	if (!a || size <= 1)
		return (true);
	// Loop door totdat de size op is EN er een volgende node is
	while (size > 1 && a->next)
	{
		if (a->value > a->next->value)
			return (false);
		a = a->next;
		size--; // Telkens eentje aftrekken van het bereik
	}
	return (true);
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

	if (size <= 1 || is_sorted__range(*a, size))
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
	if (ft_lstsize(*a) != rotated)
	{
		i = 0;
		while (i++ < rotated)
			rra(a);
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

	if (size <= 0 || !*b || is_sorted__range(*b, size))
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
	if (ft_lstsize(*b) != rotated)
	{
		i = 0;
		while (i++ < rotated)
			rrb(b);
	}
	quick_sort_b(a, b, size - pushed);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_complex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khooftma <khooftma@://42porto.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 15:51:12 by khooftma          #+#    #+#             */
/*   Updated: 2026/06/06 15:45:19 by khooftma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	sorted_asc(t_stack *a, int size)
{
	if (!a || size <= 1)
		return (true);
	while (size > 1 && a->next)
	{
		if (a->index > a->next->index)
			return (false);
		a = a->next;
		size--;
	}
	return (true);
}

bool	sorted_desc(t_stack *b, int size)
{
	if (!b || size <= 1)
		return (true);
	while (size > 1 && b->next)
	{
		if (b->index < b->next->index)
			return (false);
		b = b->next;
		size--;
	}
	return (true);
}

int	get_median(t_stack *stack, int size)
{
	int	*arr;
	int	i;
	int	j;
	int	swap;

	arr = malloc(sizeof(int) * size);
	if (size <= 0 || !stack || !(arr))
		return (0);
	i = 0;
	while (i < size && stack)
	{
		arr[i++] = stack->index;
		stack = stack->next;
	}
	size = i;
	while (--i > 0)
	{
		j = -1;
		while (++j < i)
			if (arr[j] > arr[j + 1])
				ft_swap(&arr[j], &arr[j + 1]);
	}
	swap = arr[size / 2];
	return (free(arr), swap);
}

void	sort_small_a(t_stack **a, t_stack **b, int size, t_bench *bench)
{
	(void)b;
	if (size == 2 && (*a)->index > (*a)->next->index)
		sa(a, bench);
	else if (size == 3)
	{
		if ((*a)->index > (*a)->next->index
			&& (*a)->index > (*a)->next->next->index)
			sa(a, bench);
		if ((*a)->next->index > (*a)->index
			&& (*a)->next->index > (*a)->next->next->index)
		{
			ra(a, bench);
			sa(a, bench);
			rra(a, bench);
		}
		if ((*a)->index > (*a)->next->index)
			sa(a, bench);
	}
}

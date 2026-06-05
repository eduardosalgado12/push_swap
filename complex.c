/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khooftma <khooftma@://42porto.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 12:01:41 by edsalgad          #+#    #+#             */
/*   Updated: 2026/06/05 17:21:36 by khooftma         ###   ########.fr       */
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

static int	get_median(t_stack *stack, int size)
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

static void	sort_small_a(t_stack **a, t_stack **b, int size, t_bench *bench)
{
	(void)b;
	if (size == 2 && (*a)->index > (*a)->next->index)
		sa(a, bench);
	else if (size == 3)
	{
		if ((*a)->index > (*a)->next->index && (*a)->index > (*a)->next->next->index)
			sa(a, bench);
		if ((*a)->next->index > (*a)->index && (*a)->next->index > (*a)->next->next->index)
		{
			ra(a, bench);
			sa(a, bench);
			rra(a, bench);
		}
		if ((*a)->index > (*a)->next->index)
			sa(a, bench);
	}
}
void	quick_sort_b(t_stack **a, t_stack **b, int size, t_bench *bench)
{
	int	med;
	int	push;
	int	rot;

	if (size <= 0)
		return ;
	if (sorted_desc(*b, size))
	{
		while (size-- > 0)
			pa(a, b, bench);
		return ;
	}
	med = get_median(*b, size);
	push = 0;
	rot = 0;
	while (push < (size + 1) / 2 && push + rot < size)
	{
		if ((*b)->index >= med && ++push)
			pa(a, b, bench);
		else if (++rot)
			rb(b, bench);
	}
	quick_sort_a(a, b, push, bench);
	if (ft_lstsize(*b) != rot)
		while (rot--)
			rrb(b, bench);
	quick_sort_b(a, b, size - push, bench);
}
void	quick_sort_a(t_stack **a, t_stack **b, int size, t_bench *bench)
{
	int	median;
	int	push;
	int	rot;

	if (size <= 1 || sorted_asc(*a, size))
		return ;
	if (size <= 3)
		return (sort_small_a(a, b, size, bench));
	median = get_median(*a, size);
	push = 0;
	rot = 0;
	while (push + rot < size)
	{
		if ((*a)->index < median && ++push)
			pb(a, b, bench);
		else if (++rot)
			ra(a, bench);
	}
	if (ft_lstsize(*a) != rot)
		while (rot--)
			rra(a, bench);
	quick_sort_a(a, b, size - push, bench);
	quick_sort_b(a, b, push, bench);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khooftma <khooftma@://42porto.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 12:01:41 by edsalgad          #+#    #+#             */
/*   Updated: 2026/06/08 16:16:59 by khooftma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort_b(t_stack **a, t_stack **b, int size, t_bench *bench)
{
	int	median;
	int	push;
	int	rot;

	if (sorted_desc(*b, size))
	{
		while (size-- > 0)
			pa(a, b, bench);
		return ;
	}
	median = get_median(*b, size);
	push = 0;
	rot = 0;
	while (push < (size + 1) / 2)
	{
		if ((*b)->index >= median && ++push)
			pa(a, b, bench);
		else if (++rot)
			rb(b, bench);
	}
	quick_sort_a(a, b, push, bench);
	if (ft_lstsize(*b) > rot)
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
		return (sort_small_a(a, size, bench), (void)0);
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


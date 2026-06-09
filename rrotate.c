/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khooftma <khooftma@://42porto.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 16:19:57 by khooftma          #+#    #+#             */
/*   Updated: 2026/06/09 11:27:44 by khooftma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*before_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	before_last = NULL;
	while (last->next)
	{
		before_last = last;
		last = last->next;
	}
	before_last->next = NULL;
	last->next = first;
	*stack = last;
}

void	rra(t_stack **a, t_bench *bench)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
	if (bench && bench->active)
	{
		bench->rra++;
		bench->total_ops++;
	}
}

void	rrb(t_stack **b, t_bench *bench)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
	if (bench && bench->active)
	{
		bench->rrb++;
		bench->total_ops++;
	}
}

void	rrr(t_stack **a, t_stack **b, t_bench *bench)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
	if (bench && bench->active)
	{
		bench->rrr++;
		bench->total_ops++;
	}
}


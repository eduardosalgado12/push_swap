/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edsalgad <edsalgad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 10:36:18 by khooftma          #+#    #+#             */
/*   Updated: 2026/06/09 15:52:18 by edsalgad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	last->next = first;
	first->next = NULL;
}

void	ra(t_stack **a, t_bench *bench)
{
	rotate(a);
	if (!bench->is_checker)
		write(1, "ra\n", 3);
	if (bench && bench->active)
	{
		bench->ra++;
		bench->total_ops++;
	}
}

void	rb(t_stack **b, t_bench *bench)
{
	rotate(b);
	if (!bench->is_checker)
		write(1, "rb\n", 3);
	if (bench && bench->active)
	{
		bench->rb++;
		bench->total_ops++;
	}
}

void	rr(t_stack **a, t_stack **b, t_bench *bench)
{
	rotate(a);
	rotate(b);
	if (!bench->is_checker)
		write(1, "rr\n", 3);
	if (bench && bench->active)
	{
		bench->rr++;
		bench->total_ops++;
	}
}

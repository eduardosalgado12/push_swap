/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edsalgad <edsalgad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:46:26 by khooftma          #+#    #+#             */
/*   Updated: 2026/06/02 11:36:57 by edsalgad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_stack **a, t_bench *bench)
{
	swap(a);
	write(1, "sa\n", 3);
	if (bench && bench->active)
	{
		bench->sa++;
		bench->total_ops++;
	}
}

void	sb(t_stack **b, t_bench *bench)
{
	swap(b);
	write(1, "sb\n", 3);
	if (bench && bench->active)
	{
		bench->ra++;
		bench->total_ops++;
	}
}

void	ss(t_stack **a, t_stack **b, t_bench *bench)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
	if (bench && bench->active)
	{
		bench->ss++;
		bench->total_ops++;
	}
}

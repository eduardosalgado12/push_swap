/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khooftma <khooftma@://42porto.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:46:26 by khooftma          #+#    #+#             */
/*   Updated: 2026/06/06 15:35:15 by khooftma         ###   ########.fr       */
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
	// Print ALTIJD de operatie, BEHALVE als dit de checker is!
	if (!bench || !bench->is_checker)
		write(1, "sa\n", 3);
	// Tel de statistieken ALLEEN op als --bench is meegegeven
	if (bench && bench->active)
	{
		bench->sa++;
		bench->total_ops++;
	}
}

void	sb(t_stack **b, t_bench *bench)
{
	swap(b);
	// Print ALTIJD de operatie, BEHALVE als dit de checker is!
	if (!bench || !bench->is_checker)
		write(1, "sb\n", 3);
	// Tel de statistieken ALLEEN op als --bench is meegegeven
	if (bench && bench->active)
	{
		bench->sb++; // Gecorrigeerd van ra naar sb!
		bench->total_ops++;
	}
}

void	ss(t_stack **a, t_stack **b, t_bench *bench)
{
	swap(a);
	swap(b);
	// Print ALTIJD de operatie, BEHALVE als dit de checker is!
	if (!bench || !bench->is_checker)
		write(1, "ss\n", 3);
	// Tel de statistieken ALLEEN op als --bench is meegegeven
	if (bench && bench->active)
	{
		bench->ss++;
		bench->total_ops++;
	}
}


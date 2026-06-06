/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khooftma <khooftma@://42porto.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 15:52:46 by khooftma          #+#    #+#             */
/*   Updated: 2026/06/06 15:33:44 by khooftma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **dst, t_stack **src)
{
	t_stack	*to_push;

	if (!src || !*src)
		return ;
	to_push = *src;
	*src = (*src)->next;
	to_push->next = *dst;
	*dst = to_push;
}

void	pa(t_stack **a, t_stack **b, t_bench *bench)
{
	push(a, b);
	// Schrijf ALTIJD de operatie, BEHALVE als dit de checker is!
	if (!bench || !bench->is_checker)
		write(1, "pa\n", 3);
	
	// Tel de statistieken ALLEEN op als de gebruiker --bench heeft meegegeven
	if (bench && bench->active)
	{
		bench->pa++;
		bench->total_ops++;
	}
}


void	pb(t_stack **a, t_stack **b, t_bench *bench)
{
	push(b, a);
	// Print ALTIJD de operatie, BEHALVE als dit de checker is!
	if (!bench || !bench->is_checker)
		write(1, "pb\n", 3);
	// Tel de statistieken ALLEEN op als --bench is meegegeven
	if (bench && bench->active)
	{
		bench->pb++;
		bench->total_ops++;
	}
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edsalgad <edsalgad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 15:52:46 by khooftma          #+#    #+#             */
/*   Updated: 2026/06/02 13:02:11 by edsalgad         ###   ########.fr       */
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
	write (1, "pa\n", 3);
	if (bench && bench->active)
	{
		bench->pa++;
		bench->total_ops++;
	}
}

void	pb(t_stack **a, t_stack **b, t_bench *bench)
{
	push(b, a);
	write (1, "pb\n", 3);
	if (bench && bench->active)
	{
		bench->pb++;
		bench->total_ops++;
	}
}

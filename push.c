/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khooftma <khooftma@://42porto.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 15:52:46 by khooftma          #+#    #+#             */
/*   Updated: 2026/05/29 15:23:14 by khooftma         ###   ########.fr       */
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

void	pa(t_stack **a, t_stack **b)
{
	push(a, b);
	write_op("pa");
}

void	pb(t_stack **a, t_stack **b)
{
	push(b, a);
	write_op("pb");
}

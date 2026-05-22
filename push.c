/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khooftma <khooftma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 15:52:46 by khooftma          #+#    #+#             */
/*   Updated: 2026/05/22 12:15:29 by khooftma         ###   ########.fr       */
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
		
	if (*src)
		(*src)->prev = NULL;

	to_push->prev = NULL;
	to_push->next = *dst;
	if (*dst) 
		(*dst)->prev = to_push;
	*dst = to_push;
}
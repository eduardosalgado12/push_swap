/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khooftma <khooftma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 16:05:35 by edsalgad          #+#    #+#             */
/*   Updated: 2026/05/25 15:43:53 by khooftma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	ft_lstsize(t_stack *lst)
{
	int	c;
  
	c = 0;
	while (lst)
	{
		c++;
		lst = lst->next;
	}
	return (c);
}

bool	stack_sorted(t_stack *a)
{
	if (!a)
		return (true);
	while (a->next)
	{
		if (a->value > a->next->value)
			return (false);
		a = a->next;
	}
	return (true);
}

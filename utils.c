/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khooftma <khooftma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 16:05:35 by edsalgad          #+#    #+#             */
/*   Updated: 2026/05/22 16:13:18 by khooftma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	ft_lstsize(t_stack *lst)
{
	int	c;

    // if (NULL == stack)
	// return (0);
	c = 0;
	while (lst)
	{
		c++;
		lst = lst->next;
	}
	return (c);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edsalgad <edsalgad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 16:05:35 by edsalgad          #+#    #+#             */
/*   Updated: 2026/05/20 16:07:52 by edsalgad         ###   ########.fr       */
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khooftma <khooftma@://42porto.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 15:45:10 by khooftma          #+#    #+#             */
/*   Updated: 2026/06/05 16:23:30 by khooftma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	sort_two_or_three(t_stack **a, t_bench *bench)
{
	if (ft_lstsize(*a) == 2)
	{
		if ((*a)->index > (*a)->next->index)
			sa(a, bench);
		return ;
	}
	// Se o primeiro é o maior de todos
	if ((*a)->index > (*a)->next->index && (*a)->index > (*a)->next->next->index)
		ra(a, bench);
	// Se o segundo é o maior de todos
	else if ((*a)->next->index > (*a)->index && (*a)->next->index > (*a)->next->next->index)
		rra(a, bench);
	// No fim, resta apenas verificar se os dois primeiros estão trocados
	if ((*a)->index > (*a)->next->index)
		sa(a, bench);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khooftma <khooftma@://42porto.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 15:45:10 by khooftma          #+#    #+#             */
/*   Updated: 2026/06/08 16:53:18 by khooftma         ###   ########.fr       */
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
	if ((*a)->index > (*a)->next->index && (*a)->index > (*a)->next->next->index)
		ra(a, bench);
	else if ((*a)->next->index > (*a)->index && (*a)->next->index > (*a)->next->next->index)
		rra(a, bench);
	if ((*a)->index > (*a)->next->index)
		sa(a, bench);
	
}

void sort_five(t_stack **a,t_stack **b, t_bench *bench)
{
	int i;
	int size;

	i = 0;
	size = ft_lstsize(*a);
	while(i < size -3)
	{
		push_min_to_b(a,b,bench);
		i++;
	}
	sort_two_or_three(a, bench);
	while(i > 0)
	{
		pa(a, b, bench);
		i--;
	}
}
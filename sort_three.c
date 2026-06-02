/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edsalgad <edsalgad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 15:45:10 by khooftma          #+#    #+#             */
/*   Updated: 2026/06/02 13:13:12 by edsalgad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a, t_bench *bench)
{
	int	second;
	int	third;

	if (!a || !*a || !(*a)->next || !(*a)->next->next)
		return ;
	if (ft_lstsize(*a) == 2)
		sa(a, bench);
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if ((*a)->value > second && second < third && (*a)->value < third)
		sa(a, bench);
	else if ((*a)->value > second && second > third && (*a)->value > third)
	{
		sa(a, bench);
		rra(a, bench);
	}
	else if ((*a)->value > second && second < third && (*a)->value > third)
		ra(a, bench);
	else if ((*a)->value < second && second > third && (*a)->value < third)
	{
		sa(a, bench);
		ra(a, bench);
	}
	else if ((*a)->value < second && second > third && (*a)->value > third)
		rra(a, bench);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edsalgad <edsalgad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 16:57:22 by khooftma          #+#    #+#             */
/*   Updated: 2026/06/09 15:51:22 by edsalgad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_sort(t_stack **a, t_stack **b, double disorder, t_bench *bench)
{
	int	size;

	size = ft_lstsize(*a);
	if (size <= 3)
	{
		sort_two_or_three(a, bench);
		return ;
	}
	if (size == 4 || size == 5)
	{
		sort_five(a, b, bench);
		return ;
	}
	if (disorder < 0.2)
		selection_sort(a, b, bench);
	else if (disorder < 0.5)
		chunk_sort(a, b, bench);
	else
		quick_sort_a(a, b, size, bench);
}

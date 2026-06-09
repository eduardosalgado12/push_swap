/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khooftma <khooftma@://42porto.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 16:57:22 by khooftma          #+#    #+#             */
/*   Updated: 2026/06/08 16:24:33 by khooftma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_sort(t_stack **a, t_stack **b, double disorder, t_bench *bench)
{
	if (disorder < 0.2)
		if (ft_lstsize(*a) <= 3)
			sort_two_or_three(a, bench);
		else
			selection_sort(a, b, bench);
	else if (disorder >= 0.2 && disorder < 0.5)
		if (ft_lstsize(*a) <= 3)
			sort_two_or_three(a, bench);
		else
			chunk_sort(a, b, bench);
	else
		if (ft_lstsize(*a) <= 3)
			sort_two_or_three(a, bench);
		else
			quick_sort_a(a, b, ft_lstsize(*a), bench);
}

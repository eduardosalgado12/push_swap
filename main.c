/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khooftma <khooftma@://42porto.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 15:26:18 by edsalgad          #+#    #+#             */
/*   Updated: 2026/06/01 16:16:49 by khooftma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_strategy	strat;

	a = NULL;
	b = NULL;
	if (!stack_init(argc, argv, &a, &strat) || !a)
		return (write(2, "Error\n", 6), 1);
	if (!stack_sorted(a))
	{
		if (ft_lstsize(a) == 2 || ft_lstsize(a) == 3)
			sort_three(&a);
		assign_indices(a);
		if (strat == STRAT_SIMPLE)
			selection_sort(&a, &b);
		else if (strat == STRAT_MEDIUM)
			chunk_sort(&a, &b);
		else if (strat == STRAT_COMPLEX)
			quick_sort_a(&a, &b, ft_lstsize(a));
		else
			adaptive_sort(&a, &b, disorder_metric(a));
	}
	return (free_stack(&a), 0);
}

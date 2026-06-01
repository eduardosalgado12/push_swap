/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edsalgad <edsalgad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 15:26:18 by edsalgad          #+#    #+#             */
/*   Updated: 2026/06/01 14:25:21 by edsalgad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_strategy(char *arg, t_strategy *strat)
{
	if (ft_strcmp(arg, "--simple") == 0)
		return (*strat = STRAT_SIMPLE, 1);
	if (ft_strcmp(arg, "--medium") == 0)
		return (*strat = STRAT_MEDIUM, 1);
	if (ft_strcmp(arg, "--complex") == 0)
		return (*strat = STRAT_COMPLEX, 1);
	if (ft_strcmp(arg, "--adaptive") == 0)
		return (*strat = STRAT_ADAPTIVE, 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	int     strat;

	a = NULL;
	b = NULL;
  	if (!stack_init(argc, argv, &a, &strat) || !a)
    {
        write(2, "Error\n", 6);
        return (1);
    }
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
        	adaptive_sort(&a, &b);
	}
	flush_op();
	free_stack(&a);
	return (0);
}
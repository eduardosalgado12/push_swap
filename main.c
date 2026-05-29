/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khooftma <khooftma@://42porto.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 15:26:18 by edsalgad          #+#    #+#             */
/*   Updated: 2026/05/29 14:46:42 by khooftma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> // Voor printf (verwijderen voor uiteindelijke evaluatie!)

// Helper om te kijken of een string een geldige vlag is en de enum te setten
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
	t_strategy	strat;
	int			args_start;

	a = NULL;
	b = NULL;
	strat = STRAT_ADAPTIVE;
	args_start = 1;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (1);
	
	// Controleer of het eerste argument een vlag is
	if (get_strategy(argv[1], &strat))
	{
		args_start = 2;
		if (argc == 2 || (argc == 3 && !argv[2][0]))
			return (1);
	}

	// Splitsen als er maar 1 argument-string met getallen overblijft
	if ((args_start == 1 && argc == 2) || (args_start == 2 && argc == 3))
	{
		argv = ft_split(argv[args_start], ' ');
		stack_init(&a, argv, 0); // ft_split resultaat begint altijd bij index 0!
		// Vergeet hier eventueel je free_matrix(argv) niet als je die hebt
	}
	else
	{
		stack_init(&a, argv, args_start); // Normale argumenten beginnen bij index 1 of 2
	}

	if (!stack_sorted(a))
	{
		if (ft_lstsize(a) == 2)
			sa(&a);
		else if (ft_lstsize(a) == 3)
			sort_three(&a);
		else
		{
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
	}
	return (0);
}

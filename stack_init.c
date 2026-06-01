/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khooftma <khooftma@://42porto.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 17:20:28 by khooftma          #+#    #+#             */
/*   Updated: 2026/06/01 15:07:04 by khooftma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*find_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

static void	append_node(t_stack **stack, int n)
{
	t_stack	*new_node;
	t_stack	*last_node;

	if (!stack)
		return ;
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->value = n;
	new_node->next = NULL;
	if (!(*stack))
		*stack = new_node;
	else
	{
		last_node = find_last(*stack);
		last_node->next = new_node;
	}
}

void	stack_fill(t_stack **a, char **argv, int start_index)
{
	long	n;
	int		i;

	i = start_index;
	while (argv[i])
	{
		if (errors_syntax(argv[i]))
			free_errors(a);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(a);
		if (errors_duplicate(*a, (int)n))
			free_errors(a);
		append_node(a, (int)n);
		i++;
	}
}

int	get_strategy(char *arg, t_strategy *strat)
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

int	stack_init(int argc, char **argv, t_stack **a, t_strategy *strat)
{
	int args_start;
	char **split_argv;

	*strat = STRAT_ADAPTIVE;
	args_start = 1;
	if (argc < 2 || (argc == 2 && !argv))
		return (0);

	if (get_strategy(argv[1], strat))
	{
		args_start = 2;
		if (argc == 2 || (argc == 3 && !argv))
			return (0);
	}
	if ((args_start == 1 && argc == 2) || (args_start == 2 && argc == 3))
	{
		split_argv = ft_split(argv[args_start], ' ');
		if (!split_argv)
			return (0);
		stack_fill(a, split_argv, 0);
		free_matrix(split_argv);
	}
	else
		stack_fill(a, argv, args_start);
	return (1);
}
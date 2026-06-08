/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edsalgad <edsalgad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 17:20:28 by khooftma          #+#    #+#             */
/*   Updated: 2026/06/05 13:13:10 by edsalgad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	stack_fill(t_stack **a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (errors_syntax(argv[i]))
			return (0);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			return (0);
		if (errors_duplicate(*a, (int)n))
			return (0);
		append_node(a, (int)n);
		i++;
	}
	return (1);
}


static int	parse_flags(int argc, char **argv, t_bench *bench)
{
	int	args_start;

	args_start = 1;
	while (args_start < argc)
	{
		if (ft_strcmp(argv[args_start], "--bench") == 0)
			bench->active = true;
		else if (ft_strcmp(argv[args_start], "--simple") == 0)
			bench->strat = STRAT_SIMPLE;
		else if (ft_strcmp(argv[args_start], "--medium") == 0)
			bench->strat = STRAT_MEDIUM;
		else if (ft_strcmp(argv[args_start], "--complex") == 0)
			bench->strat = STRAT_COMPLEX;
		else if (ft_strcmp(argv[args_start], "--adaptive") == 0)
			bench->strat = STRAT_ADAPTIVE;
		else
			break ;
		args_start++;
	}
	return (args_start);
}


int	stack_init(int argc, char **argv, t_stack **a, t_bench *bench)
{
	int		args_start;
	char	**split_argv;

	bench->strat = STRAT_ADAPTIVE;
	bench->active = false;
	if (argc < 2)
		return (0);
	args_start = parse_flags(argc, argv, bench);
	if (args_start == argc)
		return (0);
	while (args_start < argc)
	{
		if (argv[args_start][0] == '\0')
			return (free_stack(a), 0);
		split_argv = ft_split(argv[args_start], ' ');
		if (!split_argv)
			return (free_stack(a), 0);
		if (!stack_fill(a, split_argv))
			return (free_matrix(split_argv), free_stack(a), 0);
		free_matrix(split_argv);
		args_start++;
	}
	return (1);
}


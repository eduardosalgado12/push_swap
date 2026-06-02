/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edsalgad <edsalgad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 17:20:28 by khooftma          #+#    #+#             */
/*   Updated: 2026/06/02 13:31:46 by edsalgad         ###   ########.fr       */
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

int	get_strategy(char *arg, t_bench *bench)
{
	if (ft_strcmp(arg, "--simple") == 0)
		return (bench->strat = STRAT_SIMPLE, 1);
	if (ft_strcmp(arg, "--medium") == 0)
		return (bench->strat = STRAT_MEDIUM, 1);
	if (ft_strcmp(arg, "--complex") == 0)
		return (bench->strat = STRAT_COMPLEX, 1);
	if (ft_strcmp(arg, "--adaptive") == 0)
		return (bench->strat = STRAT_ADAPTIVE, 1);
	return (0);
}

static int	parse_flags(int argc, char **argv, t_bench *bench)
{
	int	args_start;

	args_start = 1;
	while (args_start < argc)
	{
		if (ft_strcmp(argv[args_start], "--bench") == 0)
		{
			bench->active = true;
			args_start++;
		}
		else if (get_strategy(argv[args_start], bench))
			args_start++;
		else
			break ;
	}
	return (args_start);
}

int	stack_init(int argc, char **argv, t_stack **a, t_bench *bench)
{
	int		args_start;
	char	**split_argv;

	bench->strat = STRAT_ADAPTIVE;
	bench->active = false;
	if (argc < 2 || (argc == 2 && !argv[1]))
		return (0);
	args_start = parse_flags(argc, argv, bench);
	if (args_start >= argc || (args_start == argc - 1 && !argv[args_start][0]))
		return (0);
	if (args_start == argc - 1)
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

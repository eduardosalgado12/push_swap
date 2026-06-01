/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edsalgad <edsalgad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 17:20:28 by khooftma          #+#    #+#             */
/*   Updated: 2026/06/01 14:20:14 by edsalgad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *nptr)
{
	int		sign;
	long	res;

	sign = 1;
	res = 0;
	while (*nptr == ' ' || ((*nptr >= 9) && (*nptr <= 13)))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = (res * 10) + (*nptr - '0');
		nptr++;
	}
	return (res * sign);
}

t_stack	*find_last(t_stack *stack)
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

static stack_fill(t_stack **a, char **argv, int start_index)
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

int stack_init(int argc, char **argv, t_stack **a, int *strat)
{
    int     args_start;
    char    **split_argv;

    *strat = STRAT_ADAPTIVE;
    args_start = 1;
    if (argc < 2 || (argc == 2 && !argv))
        return (0);
    
    if (get_strategy(argv, strat))
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

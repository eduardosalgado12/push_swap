/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khooftma <khooftma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 17:20:28 by khooftma          #+#    #+#             */
/*   Updated: 2026/05/25 15:41:24 by khooftma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *nptr)
{
	int	sign;
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

void append_node(t_stack **stack, int n)
{
	t_stack *new_node;
	t_stack	*last_node;

	if (!stack)
		return ;
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return;
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

void	stack_init(t_stack **a, char **argv)
{
	long	n;
	int		i;

	i = 1;
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

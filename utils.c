/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khooftma <khooftma@://42porto.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 16:05:35 by edsalgad          #+#    #+#             */
/*   Updated: 2026/05/29 11:02:16 by khooftma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_stack *lst)
{
	int	c;

	c = 0;
	while (lst)
	{
		c++;
		lst = lst->next;
	}
	return (c);
}

bool	stack_sorted(t_stack *a)
{
	if (!a)
		return (true);
	while (a->next)
	{
		if (a->value > a->next->value)
			return (false);
		a = a->next;
	}
	return (true);
}

bool	stack_sorted_range(t_stack *a, int size)
{
	if (!a || size <= 1)
		return (true);
	// Loop door totdat de size op is EN er een volgende node is
	while (size > 1 && a->next)
	{
		if (a->value > a->next->value)
			return (false);
		a = a->next;
		size--; // Telkens eentje aftrekken van het bereik
	}
	return (true);
}

int	ft_sqrt(int number)
{
	int	i;

	i = 1;
	while (i * i <= number)
		i++;
	return (i - 1);

}

void	assign_indices(t_stack *stack)
{
	t_stack	*compare;
	t_stack	*start;

	start = stack;
	while (stack)
	{
		stack->index = 0;
		compare = start;
		while (compare)
		{
			if (compare->value < stack->value)
				stack->index++;
			compare = compare->next;
		}
		stack = stack->next;
	}
}

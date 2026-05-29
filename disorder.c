/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khooftma <khooftma@://42porto.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 16:57:22 by khooftma          #+#    #+#             */
/*   Updated: 2026/05/29 14:35:21 by khooftma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	disorder_metric(t_stack *a)
{
	long	mistakes;
	long	total_pairs;
	t_stack	*i;
	t_stack	*j;

	mistakes = 0;
	total_pairs = 0;
	if (!a || !a->next)
		return (0.0);
	i = a;
	while (i != NULL)
	{
		j = i->next;
		while (j != NULL)
		{
			total_pairs++;
			if (i->value > j->value)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((double)mistakes / (double)total_pairs);
}

void    adaptive_sort(t_stack **a, t_stack **b)
{
    double  disorder;
    int     size;

    disorder = disorder_metric(*a);
    size = ft_lstsize(*a);

    // Voorbeeld van adaptieve logica op basis van de disorder-score
    if (disorder < 0.15)
    {
        // De stack is al bijna gesorteerd! 
        // Selection sort of een simpele insertion is hier vaak het snelst.
        selection_sort(a, b);
    }
    else if (size <= 100)
    {
        // Middelgrote stack met veel wanorde
        chunk_sort(a, b);
    }
    else
    {
        // Grote stack met veel wanorde
        quick_sort_a(a, b, size);
    }
}

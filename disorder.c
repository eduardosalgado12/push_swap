/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khooftma <khooftma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 16:57:22 by khooftma          #+#    #+#             */
/*   Updated: 2026/05/22 16:57:47 by khooftma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double disorder_metric(t_stack *a)
{
    long    mistakes;
    long    total_pairs;
    t_stack *i;
    t_stack *j;

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
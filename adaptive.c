/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khooftma <khooftma@://42porto.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 16:57:22 by khooftma          #+#    #+#             */
/*   Updated: 2026/06/01 16:55:05 by khooftma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    adaptive_sort(t_stack **a, t_stack **b, double disorder)
{
    int     size;

    size = ft_lstsize(*a);
    if (disorder < 0.2)
        selection_sort(a, b);
    else if (disorder >= 0.2 && disorder < 0.5)
        chunk_sort(a, b);
    else
        quick_sort_a(a, b, size);
}

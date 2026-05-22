/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khooftma <khooftma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 15:45:10 by khooftma          #+#    #+#             */
/*   Updated: 2026/05/22 16:05:22 by khooftma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three(t_stack **a)
{
	int first;
    int second;
    int third;

    if (!a || !*a || !(*a)->next || !(*a)->next->next)
        return ;
	
	first = (*a)->value;
	second = (*a)->next->value;
	third = 

}
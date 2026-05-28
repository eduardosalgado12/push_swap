/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edsalgad <edsalgad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 12:01:41 by edsalgad          #+#    #+#             */
/*   Updated: 2026/05/28 12:22:50 by edsalgad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_pivot_average(t_stack *stack, int size)
{
    long long   sum;
    int         count;
    t_stack      *tmp;

    if (!stack || size <= 0)
        return (0);
    sum = 0;
    count = size;
    tmp = stack;
    while (count-- && tmp)
    {
        sum += tmp->value;
        tmp = tmp->next;
    }
    return ((int)(sum / size));
}

int is_stack_sorted_descending(t_stack *stack, int size)
{
    if (!stack || size <= 1)
        return (1);
    while (--size && stack->next)
    {
        // Se o de cima for menor que o de baixo, não está em ordem decrescente
        if (stack->index < stack->next->index)
            return (0);
        stack = stack->next;
    }
    return (1);
}


void quicksort_b(t_stack **a, t_stack **b, int size)
{
    int pivot;
    int push_a = 0;
    int rotate_b = 0;
    int count = size;

    if (is_stack_sorted_descending(*b, size))
    {
        while (size--)
            pa(a, b);
        return ;
    }
    // Base Case: B needs to be sorted in descending order before pushing to A
    if (size <= 2)
    {
        if (size == 2 && (*b)->value < (*b)->next->value)
            sb(b);
        while (size--)
            pa(a, b);
        return ;
    }
    pivot = get_pivot_average(*b, size); // pivot is the median
    while (count--)
    {
        if ((*b)->value > pivot) // 
        {
            pa(a, b);
            push_a++;
        }
        else
        {
            rb(b);
            rotate_b++;
        }
    }
    // Restore Stack B: Bring rotated elements back to the top
    int r = rotate_b;
    while (r--)
        rrb(b);
    // Mutual Pure Recursion
    quicksort_a(a, b, push_a);   // Sort the larger half pushed to A
    quicksort_b(a, b, rotate_b); // Sort the smaller half remaining in B
}

void quicksort_a(t_stack **a, t_stack **b, int size)
{
    int pivot;
    int push_b = 0;
    int rotate_a = 0;
    int count = size;

    // if (is_stack_sorted_descending(*b, size))
    // {
    //     while (size--)
    //         pa(a, b);
    //     return ;
    // }
    // Base Case: Hardcoded optimal sorts for small sizes
    if (size <= 2)
    {
        if (size == 2 && (*a)->value > (*a)->next->value)
            sa(a); // Swap if out of order
        return ;
    }

    pivot = get_pivot_average(*a, size); // pivot is the median
    while (count--)
    {
        if ((*a)->value < pivot)
        {
            pb(a, b);
            push_b++;
        }
        else
        {
            ra(a);
            rotate_a++;
        }
    }

    // Restore Stack A: Bring rotated elements back to the top
    int r = rotate_a;
    while (r--)
        rra(a);

    // Mutual Pure Recursion: O(n log n)
    quicksort_a(a, b, rotate_a); // Recursively sort the larger half remaining in A
    quicksort_b(a, b, push_b);   // Recursively sort the smaller half now in B
}

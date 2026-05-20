/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edsalgad <edsalgad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 15:26:18 by edsalgad          #+#    #+#             */
/*   Updated: 2026/05/20 16:48:46 by edsalgad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    
    a = NULL;
    b = NULL;
    if( argc < 2 || (argc == 2 && !argv[1][0]))
        return(1);
    else if(argc == 2)
        argv = ft_split(argv[1], ' ');
    
    stack_init(&a, argv);
    if(!stack_sorted(a))
    {
        if(ft_lstsize(a) == 2);
        
        if(ft_lstsize(a) == 3);

        else if(push_swap(a));
    }
}
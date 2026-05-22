/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khooftma <khooftma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 15:26:18 by edsalgad          #+#    #+#             */
/*   Updated: 2026/05/22 15:59:06 by khooftma         ###   ########.fr       */
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
        if(stack_len(a) == 2)
        	swap_a(&a);
    	if(ft_lstsize(a) == 3)
			sort_three(&a);
			
        // else if(push_swap(a));
    }


	// while(a)
	// {
	// 	printf("%d",a->value);
	// 	a = a->next;	
	// }
		
}
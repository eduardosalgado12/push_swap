/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khooftma <khooftma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 15:26:18 by edsalgad          #+#    #+#             */
/*   Updated: 2026/05/21 15:40:49 by khooftma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *sa;
    t_stack *sb;
    
    sa = NULL;
    sb = NULL;
    if( argc < 2 || (argc == 2 && !argv[1][0]))
        return(1);
    else if(argc == 2)
        argv = ft_split(argv[1], ' ');
    
    stack_init(&sa, argv);
    if(!stack_sorted(sa))
    {
        if(stack_len(sa) == 2)
        	swap_a(&sa);
        // if(ft_lstsize(a) == 3);

        // else if(push_swap(a));
    }


	// while(sa)
	// {
	// 	printf("%d",sa->value);
	// 	sa = sa->next;	
	// }
		
}
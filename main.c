/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khooftma <khooftma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 15:26:18 by edsalgad          #+#    #+#             */
/*   Updated: 2026/05/26 12:30:27 by khooftma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
	double	disorder;
    
    a = NULL;
    b = NULL;
    if( argc < 2 || (argc == 2 && !argv[1][0]))
        return(1);
    else if(argc == 2)
        argv = ft_split(argv[1], ' ');
    
    stack_init(&a, argv);
	disorder = disorder_metric(a);
    if(!stack_sorted(a))
    {
        if(ft_lstsize(a) == 2)
        	sa(&a);
    	else if(ft_lstsize(a) == 3)
			sort_three(&a);
		else
			chunk_sort(&a, &b);
			//selection_sort(&a, &b);
    }

	
	while(a)
	{
		printf("%d ," ,a->value);
		a = a->next;	
	}
	printf("Disorder: '%f", disorder);
		
}
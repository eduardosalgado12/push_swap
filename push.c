/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khooftma <khooftma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 15:52:46 by khooftma          #+#    #+#             */
/*   Updated: 2026/05/21 17:06:46 by khooftma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **dst, t_stack **src) // push a top node from one stack to another
{
	t_stack	*temp;
	
	// If the source stack is empty, there is nothing to push.
	if (!*src)
		return ;

	temp = *src;

	// Disconnect the node and move the source head pointer to the next node, this becomes the next top .
	*src = (*src)->next;
	
	// Check if current node exists	
	if (*src)
		(*src)->prev = NULL; // set current node as head of stack

	// Detach node to push from stack
	temp->prev = NULL; 
	if (!*dst) // check if empty
	{
		*dst = temp; // if empy, assign as first node of stack
		temp->next = NULL; // also ensure it is last node
	}
	else
	{
		temp->next = *dst; // aasign node to push to top of current top node of stack
		temp->next->prev = temp; // aasign to seconde node's prev attribute
		*dst = temp; // complete appending the node. the pointer to top node is nowe pointing to the recenly pushed node.
	}
}
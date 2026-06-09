/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khooftma <khooftma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 17:30:50 by khooftma          #+#    #+#             */
/*   Updated: 2026/05/13 11:33:44 by khooftma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	unsigned long	p;
	int				count;

	count = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	p = (unsigned long)ptr;
	count += ft_putstr("0x");
	count += ft_puthex(p, "0123456789abcdef");
	return (count);
}

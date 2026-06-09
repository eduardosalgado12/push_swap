/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edsalgad <edsalgad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 15:10:01 by edsalgad          #+#    #+#             */
/*   Updated: 2026/06/09 16:05:31 by edsalgad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *str, int fd)
{
	if (str)
		write(fd, str, ft_strlen(str));
}

void	ft_putnbr_fd(int n, int fd)
{
	long	num;
	char	c;

	num = n;
	if (num < 0)
	{
		write(fd, "-", 1);
		num = -num;
	}
	if (num >= 10)
		ft_putnbr_fd(num / 10, fd);
	c = (num % 10) + '0';
	write(fd, &c, 1);
}

void	ft_putfloat_fd(double num, int fd)
{
	int	int_part;
	int	dec_part;

	if (num < 0)
	{
		write(fd, "-", 1);
		num = -num;
	}
	num += 0.005;
	int_part = (int)num;
	dec_part = (int)((num - int_part) * 100);
	ft_putnbr_fd(int_part, fd);
	ft_putchar_fd('.', fd);
	if (dec_part < 10)
		ft_putchar_fd('0', fd);
	ft_putnbr_fd(dec_part, fd);
}

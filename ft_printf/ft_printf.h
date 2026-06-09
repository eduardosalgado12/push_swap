/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khooftma <khooftma@://42porto.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 16:35:49 by khooftma          #+#    #+#             */
/*   Updated: 2026/06/09 14:53:46 by khooftma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *format, ...);
int		ft_putchar(int c);
void	ft_putstr_fd(const char *s, int fd);
int		ft_puthex(unsigned long n, char *base);
void	ft_putnbr_fd(long n, int fd);
int		ft_putnbr(long n);
int		ft_putunbr(unsigned long n);

#endif
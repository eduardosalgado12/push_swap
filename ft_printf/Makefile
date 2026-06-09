# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khooftma <khooftma@://42porto.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/07 15:40:07 by khooftma          #+#    #+#              #
#    Updated: 2026/06/09 14:52:55 by khooftma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_printf.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
SRCS	= ft_printf.c ft_putchar.c ft_putstr.c ft_puthex.c ft_putptr.c ft_putnbr.c ft_putunbr.c
OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
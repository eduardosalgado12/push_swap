# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khooftma <khooftma@://42porto.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/29 14:13:21 by khooftma          #+#    #+#              #
#    Updated: 2026/05/29 15:20:26 by khooftma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = push_swap
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror

SRC     = push.c rotate.c rrotate.c complex.c simple.c sort_three.c \
          split.c stack_init.c swap.c utils.c errors.c \
          disorder.c main.c medium.c utils_main.c optimizer.c
          
OBJS    = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

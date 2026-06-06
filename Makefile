# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khooftma <khooftma@://42porto.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/29 14:13:21 by khooftma          #+#    #+#              #
#    Updated: 2026/06/06 15:49:47 by khooftma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
NAME_BONUS	= checker
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

# main.c is hieronder weggehaald zodat bronbestanden niet dubbel linken!
SHARED_SRC	= push.c rotate.c rrotate.c complex.c simple.c sort_three.c \
				split.c stack_init.c swap.c utils.c errors.c \
				adaptive.c medium.c utils_2.c  utils_complex.c \
				utils_simple.c get_next_line.c get_next_line_utils.c \

SRC 		= main.c $(SHARED_SRC)
SRC_BONUS 	= checker.c $(SHARED_SRC) 

OBJS		= $(SRC:.c=.o)
OBJS_BONUS	= $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all bonus clean fclean re

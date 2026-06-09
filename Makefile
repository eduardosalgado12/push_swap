# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edsalgad <edsalgad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/29 14:13:21 by khooftma          #+#    #+#              #
#    Updated: 2026/06/09 15:50:56 by edsalgad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap
BONUS_NAME  = checker
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror

COMMON_SRC  = push.c rotate.c rrotate.c swap.c stack_init.c \
            errors.c split.c utils.c utils_2.c \
            utils_print.c get_next_line.c get_next_line_utils.c

MAND_SRC    = main.c adaptive.c complex.c medium.c simple.c sort_three.c \
			utils_complex.c utils_simple.c

BONUS_SRC   = checker.c

SRC         = $(COMMON_SRC) $(MAND_SRC)
SRC_BONUS   = $(COMMON_SRC) $(BONUS_SRC)

OBJS        = $(SRC:.c=.o)
OBJS_BONUS  = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(BONUS_NAME)

clean:
	rm -f $(OBJS) $(BONUS_SRC:.c=.o)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus

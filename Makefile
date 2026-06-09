# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khooftma <khooftma@://42porto.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/29 14:13:21 by khooftma          #+#    #+#              #
#    Updated: 2026/06/09 14:44:13 by khooftma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
NAME_BONUS	= checker
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

PRINTF_DIR  = ft_printf
PRINTF      = $(PRINTF_DIR)/ft_printf.a

SHARED_SRC	= push.c rotate.c rrotate.c complex.c simple.c sort_three.c \
				split.c stack_init.c swap.c utils.c errors.c \
				adaptive.c medium.c utils_2.c utils_complex.c \
				utils_simple.c get_next_line.c get_next_line_utils.c \

SRC 		= main.c $(SHARED_SRC)
SRC_BONUS 	= checker.c $(SHARED_SRC) 

OBJS		= $(SRC:.c=.o)
OBJS_BONUS	= $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) -o $(NAME)

$(PRINTF):
	make -C $(PRINTF_DIR)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)
	make -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re

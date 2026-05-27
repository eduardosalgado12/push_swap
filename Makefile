NAME = push_swap.a

SRC 		= push.c rotate.c simple.c sort_three.c \
			  split.c stack_init.c swap.c utils.c errors.c \
			  disorder.c main.c medium.c

all: $(NAME)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRC:.c=.o)

$(NAME): $(OBJS)
	ar rcs ${NAME} ${OBJS}

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
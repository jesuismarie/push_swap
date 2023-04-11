NAME = push_swap

SRCS = $(wildcard src/*.c)

OBJS = $(SRCS:.c=.o)

INCS = -I

HEADER = ./includes/push_swap.h

FLAGS = -Wall -Wextra -Werror -g -fsanitize=address

LIBFT = -LLibft -lft

CC = cc

all: lib $(NAME)

%.o: %.c $(HEADER) Makefile
	$(CC) $(FLAGS) $(INCS)includes -c $< -o $@

${NAME}: ${OBJS}
	$(CC) $(FLAGS) $(OBJS) $(INCS)includes -o ${NAME} $(LIBFT)

lib:
	@make -C Libft

clean:
	rm -f $(OBJS)
	@make clean -C Libft

fclean: clean
	rm -f ${NAME}
	@make fclean -C Libft

re: 	fclean all

.PHONY: all clean fclean re

NAME 			= push_swap

BONUS			= checker

BUILD			= ./build

SRC				= ./src

SRC_B			= ./bonus_src

SRCS 			= $(shell find $(SRC) -name '*.c')

SRCS_BONUS		= $(shell find $(SRC_B) -name '*.c')

OBJS 			= $(patsubst $(SRC)/%.c, $(BUILD)/%.o, $(SRCS))

OBJS_BONUS		= $(patsubst $(SRC_B)/%.c, $(BUILD)/%.o, $(SRCS_BONUS))

INCS 			= -I./includes -I./Libft

INCS_B			= -I./bonus_includes -I./Libft

HEADER			= ./includes/push_swap.h

HEADER_BONUS	= ./bonus_includes/checker.h

FLAGS			= -Wall -Wextra -Werror# -fsanitize=address -g

LIBFT			= -LLibft -lft

CC				= cc

all: 			$(BUILD) lib $(NAME)

$(BUILD)/%.o:	$(SRC)/%.c $(HEADER) Makefile
		$(CC) $(FLAGS) $(INCS) -c $< -o $@

$(BUILD)/%.o:	$(SRC_B)/%.c $(HEADER_BONUS) Makefile
		$(CC) $(FLAGS) $(INCS_B) -c $< -o $@

${NAME}:		${OBJS}
		$(CC) $(FLAGS) $(OBJS) $(INCS) -o ${NAME} $(LIBFT)

${BONUS}:		${OBJS_BONUS}
		$(CC) $(FLAGS) $(OBJS_BONUS) $(INCS_B) -o ${BONUS} $(LIBFT)

$(BUILD):
		@mkdir -p $(BUILD)

lib:
		@make -C Libft

clean:
		rm -rf $(BUILD)
		@make clean -C Libft

fclean:		clean
		rm -f ${NAME} ${BONUS}
		@make fclean -C Libft

re:			fclean all

bonus:		$(BUILD) lib $(BONUS)

.PHONY:		all clean fclean re bonus

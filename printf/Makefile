CC = cc
CFLAGS = -Wall -Wextra -Werror -I./libft -I. -I./utils -I./prints -ggdb -O0 -fsanitize=address
SRCS = ft_printf.c ./input_handler/flag_is_valid.c ./input_handler/get_flags_and_format.c \
        ./prints/print_char.c ./prints/print_string.c ./prints/print_pointer.c ./prints/print_decimal.c \
        ./prints/print_unsigned_decimal.c ./prints/print_hex.c ./prints/helper_print.c \
        ./prints/set_unset_flags.c ./utils/utils.c

NAME = a.out
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
OBJ_DIR = object_files
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

all: $(OBJ_DIR) $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

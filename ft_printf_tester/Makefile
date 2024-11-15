CC = cc
CFLAGS = -Wall -Wextra -Werror -I./libft -I. -I./utils -I./prints -ggdb -O0 -fsanitize=address

SRCS = ft_printf.c get_flags_and_format.c ./prints/print_char.c ./prints/print_string.c\
       ./prints/print_pointer.c ./prints/print_decimal.c \
       ./prints/print_unsigned_decimal.c ./prints/print_hex.c ./prints/helper_print.c \
       ./prints/print_util.c ./utils/utils.c

NAME = a.out 
LIBFT = ./libft/libft.a
OBJ_DIR = object_files

# Object files from your project sources
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

# Combine the object files from libft.a and your own source files

all: $(OBJ_DIR) $(NAME)

$(NAME):$(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L ./libft -lft -o $(NAME)

# Make sure the libft.a is built first
$(LIBFT):
	make -C ./libft

# Compile your own source files into object files in OBJ_DIR
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)  # Ensure the object directory exists
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Clean up the object files
clean:
	rm -rf $(OBJ_DIR)

# Clean up and remove the final library
fclean: clean
	rm -f $(NAME)

# Rebuild everything from scratch
re: fclean all

.PHONY: all clean fclean re


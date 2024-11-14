CC = cc
#CFLAGS = -Wall -Wextra -Werror -I./libft -I. -I./utils -I./prints -ggdb -O0 -fsanitize=address
CFLAGS = -Wall -Wextra -Werror -I./libft -I. -I./utils -I./prints

SRCS = ft_printf.c get_flags_and_format.c ./prints/print_char.c ./prints/print_string.c\
       ./prints/print_pointer.c ./prints/print_decimal.c \
       ./prints/print_unsigned_decimal.c ./prints/print_hex.c ./prints/helper_print.c \
       ./prints/print_util.c ./utils/utils.c

NAME = libftprintf.a
LIBFT = ./libft/libft.a
OBJ_DIR = object_files

# Extract the object files from libft.a and store them in OBJ_DIR
LIBFT_OBJS = $(addprefix $(OBJ_DIR)/, $(shell ar t $(LIBFT) | grep '\.o$$'))

# Object files from your project sources
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

# Combine the object files from libft.a and your own source files
ALL_OBJS = $(LIBFT_OBJS) $(OBJS)

all: $(OBJ_DIR) $(NAME)

# Create the final static library libftprintf.a from all object files
# $(NAME): $(ALL_OBJS)
#	ar rcs $@ $^

$(NAME):$(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT) -lft -o $(NAME)
# Make sure the libft.a is built first
$(LIBFT):
	make -C $(LIBFT_DIR)

# Compile your own source files into object files in OBJ_DIR
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)  # Ensure the object directory exists
	$(CC) $(CFLAGS) -c $< -o $@

# Extract object files from libft.a into OBJ_DIR
$(OBJ_DIR)/%.o: $(LIBFT)
	@mkdir -p $(OBJ_DIR)  # Ensure OBJ_DIR exists
	ar x $(LIBFT) $@
	mv $(@F) $(OBJ_DIR)/$(@F)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BONUS): $(ALL)

# Clean up the object files
clean:
	rm -rf $(OBJ_DIR)

# Clean up and remove the final library
fclean: clean
	rm -f $(NAME)

# Rebuild everything from scratch
re: fclean all

.PHONY: all clean fclean re


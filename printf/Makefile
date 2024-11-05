CC = cc

CFLAGS = -Wall -Wextra -Werror -I./libft -I. -I./utils -I./prints -ggdb -O0 -fsanitize=address

SRCS = ft_printf.c ./input_handler/flag_is_valid.c ./input_handler/get_flags_and_format.c ./prints/print_char.c ./prints/print_string.c ./prints/print_pointer.c ./utils/utils.c \

#NAME = libftprint.a 
NAME = a.out

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a  # Full path to the library
OBJS = $(SRCS:.c=.o)

all: $(NAME)

# This is the linkder phase, put togheter all unit files
$(NAME): $(LIBFT) $(OBJS) 
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft

#$(NAME): $(LIBFT) $(OBJS) 
#	ar rcs $(NAME) $(LIFT) $(OBJS)
$(LIBFT):
	make -C $(LIBFT_DIR)

# This is the compiler phase - generate object files
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(OBJS)

re: fclean all

.PHONY: all clean fclean re


CC = cc

CFLAGS = -Wall -Wextra -Werror -I./libft -I. -ggdb -O0

SRCS = ft_printf.c ft_flags_delimiter_parser.c ft_handle_args.c

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


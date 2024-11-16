CC = cc
CFLAGS = -Wall -Wextra -Werror -I./libft -I. -I./utils -I./prints -ggdb -O0 -fsanitize=address
#CFLAGS = -Wall -Wextra -Werror -I./libft -I. -I./utils -I./prints

SRCS = ft_printf.c get_flags_and_format.c ./prints/print_char.c ./prints/print_string.c\
       ./prints/print_pointer.c ./prints/print_decimal.c \
       ./prints/print_unsigned_decimal.c ./prints/print_hex.c ./prints/helper_print.c \
       ./prints/print_util.c ./utils/utils.c

SRCS_BONUS = ft_printf_bonus.c get_flags_and_format_bonus.c prints/print_char_bonus.c prints/print_string_bonus.c\
       prints/print_pointer_bonus.c prints/print_decimal_bonus.c \
       prints/print_unsigned_decimal_bonus.c prints/print_hex_bonus.c prints/helper_print_bonus.c \
       prints/print_util_bonus.c utils/utils_bonus.c

NAME = libftprintf.a
OUT  = a.out

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
OBJ_DIR = object_files

OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)
OBJ_BONUS = $(SRCS_BONUS:%.c=$(OBJ_DIR)/%.o)
LIBFT_OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(shell ar t $(LIBFT))))

all: $(OUT)

$(NAME): $(LIBFT) $(OBJS)
	@mkdir -p $(OBJ_DIR)
	@(cd $(OBJ_DIR) && ar x ../$(LIBFT))
	ar rcs $@ $(OBJS) $(LIBFT_OBJS)

bonus: $(LIBFT) $(OBJ_BONUS)
	@mkdir -p $(OBJ_DIR)
	@(cd $(OBJ_DIR) && ar x ../$(LIBFT))
	ar rcs $(NAME) $(OBJ_BONUS) $(LIBFT_OBJS)

$(OUT): $(LIBFT) $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -L. -L$(LIBFT_DIR) -lft -o $(OUT)
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(OUT)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

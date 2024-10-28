NAME = libftprintf.a

CC = cc

DEP = libft.a

CFLAGS = -Wall -Wextra -Werror -I

SRCS = ft_printf.c

BONUS = 

OBJS = $(SRCS:.c=.o)

BONUS_OBJ = $(BONUS:.c=.o)

all: $(DEP) $(NAME)

$(DEP):
	make -C ./libfg

$(NAME): $(OBJS) $(DEP)
	
	ar rcs $(NAME) $(OBJS)

bonus: $(NAME) 
	ar rcs $(NAME) $(OBJS) $(BONUS_OBJ)

clean:
	rm -f $(OBJS) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus

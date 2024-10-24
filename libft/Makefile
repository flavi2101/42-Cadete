# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Library name
NAME = libft.a

# Source files
SRC = ft_atoi.c     ft_isalpha.c  ft_isdigit.c  ft_memset.c  ft_strdup.c \
	ft_strlcpy.c  ft_strncmp.c  ft_strrchr.c  ft_toupper.c  main.c \
	ft_isalnum.c  ft_isascii.c  ft_isprint.c  ft_strchr.c \
	ft_strlcat.c  ft_strlen.c   ft_strnstr.c  ft_tolower.c ft_bzero.c \
	ft_memmove.c  ft_memcpy.c   ft_memchr.c   ft_calloc.c ft_itoa.c \
	ft_itoa.c ft_substr.c 	ft_strjoin.c	ft_strtrim.c	ft_split.c \
	ft_strmapi.c	ft_striteri.c	ft_putchar_fd.c	ft_putstr_fd.c \
	ft_putendl_fd.c		ft_putnbr_fd.c	ft_memcmp.c
# Bonus Sourc
BONUS = ft_lstnew.c	ft_lstadd_front.c	ft_lstsize.c	ft_lstlast.c \
	ft_lstadd_back.c	ft_lstdelone.c	ft_lstclear.c	ft_lstiter.c \
	ft_lstmap.c

# Object files
OBJ = $(SRC:.c=.o) $(BONUS:.c=.o)

# Header files
HEADERS = libft.h

# The default rule that builds the library
all: $(NAME)

# Rule to create object files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to build the static library
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# Rule to clean object files
clean:
	rm -f $(OBJ)

# Rule to clean object files and the library
fclean: clean
	rm -f $(NAME)

# Rule to recompile everything from scratch
re: fclean all

bonus:	$(OBJ)
	ar rcs $(NAME) $(OBJ)
.PHONY: all clean fclean re exec


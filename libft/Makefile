# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Library name
NAME = libft.a

# Source files
SRC = ft_atoi.c     ft_isalpha.c  ft_isdigit.c  ft_memset.c  ft_strdup.c \
      ft_strlcpy.c  ft_strncmp.c  ft_strrchr.c  ft_toupper.c  main.c \
      ft_isalnum.c  ft_isascii.c  ft_isprint.c  ft_strchr.c \
      ft_strlcat.c  ft_strlen.c   ft_strnstr.c  ft_tolower.c

# Object files
OBJ = $(SRC:.c=.o)

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

# Rule to generate an executable (optional, depends on main.c)
exec: $(NAME)
	$(CC) $(CFLAGS) -o exec main.c -L. -lft

.PHONY: all clean fclean re exec


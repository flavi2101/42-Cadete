NAME=libft
BINARY=a.out
LIBRARY=libft.a
CURRDIR=.
CC=cc
OPT=-O0
DEBUG=-ggdb
DEPFLAGS=-MP -MD
MEMORY=-fsanitize=address
CFLAGS=-Wall -Wextra -Werror $(DEBUG) $(OPT) $(DEPFLAGS) $(MEMORY)

CFILES=$(foreach D, $(CURRDIR),$(wildcard $(D)/*.c))
OBJECTS=$(patsubst %.c,%.o,$(CFILES))
DEPFILES=$(patsubst %.c,%.d,$(CFILES))

# Create the static library
all: $(LIBRARY) $(BINARY)

$(LIBRARY): $(OBJECTS)
	ar rcs $@ $^

$(BINARY): $(OBJECTS)
	$(CC) -o $@ $^ -L. -lft -lasan

# Only want the .c file dependency here, thus $< instead of $^.
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf *.o

fclean: clean
	rm -f $(BINARY) $(LIBRARY) $(DEPFILES)

re: fclean all

.PHONY: all clean fclean re

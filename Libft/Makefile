BINARY=a.out
LIBRARY=libft.a
CURRDIR=.
CC=gcc
OPT=-O0
DEBUG=-ggdb
DEPFLAGS=-MP -MD
CFLAGS=-Wall -Wextra -Werror $(DEBUG) $(OPT) $(DEPFLAGS)

CFILES=$(foreach D, $(CURRDIR),$(wildcard $(D)/*.c))
OBJECTS=$(patsubst %.c,%.o,$(CFILES))
DEPFILES=$(patsubst %.c,%.d,$(CFILES))

# Create the static library
all: $(LIBRARY) $(BINARY)

$(LIBRARY): $(OBJECTS)
	ar rcs $@ $^

$(BINARY): $(OBJECTS)
	$(CC) -o $@ $^ -L. -lft

# Only want the .c file dependency here, thus $< instead of $^.
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf *.o

fclean: clean
	rm -f $(BINARY) $(LIBRARY) $(DEPFILES)

re: fclean all


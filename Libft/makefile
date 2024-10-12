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

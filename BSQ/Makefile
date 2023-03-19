CC = gcc
CFLAGS = -Wall -Wextra -Werror
INC = includes/*.h
SOURCES = srcs/*.c
OBJECTS = $(SOURCES:.c=.o)
NAME = bsq

.PHONY = clean fclean re all

all: $(NAME)

$(NAME): $(SOURCES)
	$(CC) $(CFLAGS) $^ -o $@ -I includes

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all


CC = cc
CFLAG = -Wall -Werror -Wextra -c
NAME = libft.a
SRCS = ./srcs/ft_putchar.c ./srcs/ft_putstr.c ./srcs/ft_strcmp.c ./srcs/ft_strlen.c ./srcs/ft_swap.c
OBJS = $(SRCS:.c=.o)
INCS = ./includes

all : $(NAME)

$(NAME) : $(OBJS)
		  ar -rcs libft.a $(OBJS)

%.o : %.c
	 $(CC) $(CFLAG) $^ -o $@ -I$(INCS) 

clean : 
		rm -rf $(OBJS)

fclean : clean 
	     rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re

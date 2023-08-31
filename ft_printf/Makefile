NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c ft_putpointer.c ft_puthexa.c ft_puthexa_up.c ft_putstr_n.c ft_putuns.c ft_putnbr.c
OBJS =	$(SRCS:.c=.o)

$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJS)
all :	$(NAME)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
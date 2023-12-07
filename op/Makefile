
NAME = libftprintf.a
SRC = ft_putnbr.c ft_putnbr_base.c ft_putchr.c ft_printf.c  ft_putstr.c ft_strchr.c 
OBJ = ${SRC:.c=.o}
CC = cc
FLAGS = -Wall -Wextra -Werror

all : ${NAME}

$(NAME) : $(OBJ)

.c.o:
	$(CC) $(FLAGS) -c $< -o $@
	ar -rc $(NAME) $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re: fclean all
.SECONDARY : $(OBJ)

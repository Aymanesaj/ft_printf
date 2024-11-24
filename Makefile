CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRC = ft_printf.c ft_putnbr.c ft_putstr.c ft_numsizet.c ft_putchar.c ft_putnbr_base.c ft_address.c
OBJ = $(SRC:.c=.o)
HEADER = libftprintf.h

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)
re : fclean all

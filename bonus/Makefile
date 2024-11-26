CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRC = ft_printf.c ft_putnbr.c ft_putstr.c ft_numsizet.c ft_putchar.c ft_putnbr_base.c ft_address.c ft_bonus_flags.c ft_addnum.c ft_isdigit.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

bonus : $(OBJ)
	ar rcs $(NAME) $(OBJ)

fclean : clean
	rm -rf $(NAME)
re : fclean all

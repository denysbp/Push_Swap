NAME =	libftprintf.a

LIBFT = Libft/libft.a

SRCS =	ft_printf.c	ft_printf_chr.c	ft_printf_num.c

OBJ =	$(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I.

all: $(NAME)

$(LIBFT):
	make -C Libft

$(NAME): $(OBJ) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	make clean -C Libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C Libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
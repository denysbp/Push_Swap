NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes

NAME = push_swap

LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a

SRC = \
	src/main.c \
	src/parsing/parse_args.c \
	src/parsing/split_args.c \
	src/parsing/atoi_safe.c \
	src/validation/check_numbers.c \
	src/validation/check_duplicates.c \
	src/validation/check_overflow.c \
	src/stack/stack_init.c \
	src/stack/stack_utils.c \
	src/stack/stack_free.c \
	src/operations/swap.c \
	src/operations/push.c \
	src/operations/rotate.c \
	src/operations/reverse.c \
	src/sort/small/sort_three.c \
	src/sort/small/sort_five.c \
	src/sort/adaptive/adaptive_sort.c \
	src/sort/adaptive/disorder.c \
	src/sort/complex/radix_sort.c \
	src/sort/complex/radix_utils.c \
	src/sort/medium/sort_chunks.c \
	src/sort/medium/chunk_utils.c \
	src/sort/simple/sort_simple.c \
	src/sort/simple/simple_utils.c \
	src/sort/sort_utils.c \
	src/output/print_ops.c\
	src/flags/adaptive/adaptive.c\
	src/flags/banch/banch.c\
	src/flags/complex/complex.c\
	src/flags/medium/medium.c\
	src/flags/simple/simple.c
	src/flags/flags.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	make -C ft_printf
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)

clean:
	make clean -C libft
	make clean -C ft_printf
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	make fclean -C ft_printf
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re $(NAME)
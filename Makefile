NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes

NAME = push_swap

PRINTF = ft_printf/libftprintf.a

SRC = \
	src/main.c \
	src/parsing/parse_args.c \
	src/parsing/split_args.c \
	src/parsing/atoi_safe.c \
	src/validation/check_numbers.c \
	src/validation/check_duplicates.c \
	src/validation/check_overflow.c \
	src/stack/stack_utils.c \
	src/stack/stack_free.c \
	src/operations/swap.c \
	src/operations/push.c \
	src/operations/rotate.c \
	src/operations/reverse.c \
	src/sort/small/tiny_sort.c \
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
	src/flags/flags.c\
	src/flags/flags_utils.c\
	src/flags/adaptive/adaptive.c\
	src/flags/banch/banch.c\
	src/flags/banch/bench_utils.c\
	src/flags/complex/complex.c\
	src/flags/medium/medium.c\
	src/flags/simple/simple.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(PRINTF):
	make -C ft_printf

$(NAME): $(OBJ)
	make -C ft_printf
	$(CC) $(CFLAGS) $(OBJ) $(PRINTF) -o $(NAME)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	make clean -C ft_printf
	rm -f $(OBJ)

fclean: clean
	make fclean -C ft_printf
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
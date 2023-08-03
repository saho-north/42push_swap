NAME        = push_swap
BONUS_NAME  = test_checker
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I./includes

SRCS_PUSH_SWAP = do_rotate.c exit_with_error.c ft_isdigit.c partition_b.c ft_strtol.c is_sorted.c sort_small.c compaction.c ft_strlen.c do_reverse_rotate.c sort.c partition_a.c do_push.c ft_putendl_fd.c is_valid_arg.c parse_input.c ft_issign.c create_empty_stack.c push_swap.c ft_isdigsig.c do_swap.c multi_rrr.c is_reverse_sorted.c

SRCS_COMMON = do_rotate.c exit_with_error.c ft_isdigit.c partition_b.c ft_strtol.c is_sorted.c sort_small.c compaction.c ft_strlen.c do_reverse_rotate.c sort.c partition_a.c do_push.c ft_putendl_fd.c is_valid_arg.c parse_input.c ft_issign.c create_empty_stack.c push_swap.c ft_isdigsig.c do_swap.c multi_rrr.c is_reverse_sorted.c

#今は全てのファイルが列挙されているが、ボーナスcheckerに使用されるファイルのみをコンパイルするようにあとで変更する
SRCS_CHECKER  = checker.c get_next_line.c get_next_line_utils.c

OBJS_COMMON    = $(addprefix srcs/, $(SRCS_COMMON:.c=.o))
OBJS_PUSH_SWAP = $(OBJS_COMMON) $(addprefix srcs/, $(SRCS_PUSH_SWAP:.c=.o))
OBJS_CHECKER   = $(OBJS_COMMON) $(addprefix srcs/, $(SRCS_CHECKER:.c=.o))

$(NAME): $(OBJS_PUSH_SWAP)
	$(CC) $(CFLAGS) $^ -o $@

$(BONUS_NAME): $(OBJS_CHECKER)
	$(CC) $(CFLAGS) $^ -o $@

all: $(NAME)

bonus: $(BONUS_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS_PUSH_SWAP) $(OBJS_CHECKER)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

test: $(NAME) clean
	./$(NAME) 85 42 97 83 51 43 48 7 21 6 27 57 74 79 67 16 23 73 68 95 59 44 45 9 91 15 93 47 37 29 33 90 86 1 28 58 69 61 77 24 71 18 4 14 40 84 41 82 56 10 50 36 22 8 81 78 64 3 52 53 88 30 75 49 46 76 32 2 99 0 70 92 39 25 89 80 94 17 54 60 31 26 87 72 38 35 12 62 66 55 63 20 96 13 19 11 65 98 5 34


error0: $(NAME)
	./$(NAME) "1 2 3 "

error1: $(NAME)
	./$(NAME) " 1 2 3"

error2: $(NAME)
	./$(NAME) "1- 2 3"

error3: $(NAME)
	./$(NAME) "1 -2- 3"

error4: $(NAME)
	./$(NAME) "- 1 2 3"

error5: $(NAME)
	./$(NAME) "1 2 3-"

.PHONY: all clean fclean re test error0 error1 error2 error3 error4 error5 bonus

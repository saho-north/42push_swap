NAME           = push_swap
BONUS_NAME     = test_checker
CC             = cc
CFLAGS         = -Wall -Wextra -Werror -I./includes

SRCS_PUSH_SWAP = push_swap.c do_swap.c do_push.c do_rotate.c do_reverse_rotate.c sort.c sort_small.c compaction.c partition_a.c partition_b.c

SRCS_COMMON = is_valid_arg.c parse_input.c create_empty_stack.c push_swap_utils.c exit_with_error.c ft_strtol.c do_command.c is_sorted_utils.c

SRCS_CHECKER  = checker_bonus.c checker_gnl_bonus.c checker_utils_bonus.c do_swap_bonus.c do_push_bonus.c do_rotate_bonus.c do_reverse_rotate_bonus.c

OBJS_COMMON    = $(addprefix srcs/common/, $(SRCS_COMMON:.c=.o))
OBJS_PUSH_SWAP = $(OBJS_COMMON) $(addprefix srcs/push_swap/, $(SRCS_PUSH_SWAP:.c=.o))
OBJS_CHECKER   = $(OBJS_COMMON) $(addprefix srcs/checker/, $(SRCS_CHECKER:.c=.o))

$(NAME): $(OBJS_PUSH_SWAP)
	$(CC) $(CFLAGS) $^ -o $@

$(BONUS_NAME): $(OBJS_CHECKER)
	$(CC) $(CFLAGS) $^ -o $@

all: $(NAME)

bonus: $(BONUS_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS_COMMON) $(OBJS_PUSH_SWAP) $(OBJS_CHECKER)

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

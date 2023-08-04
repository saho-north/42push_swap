NAME			= push_swap
BONUS_NAME		= checker

CC				= cc
CFLAGS			= -Wall -Wextra -Werror
LIBRARY			= -L$(LIBFT_DIR) -lft
INCLUDE			= -I$(HDR_DIR) -I$(LIBFT_HDR)

LIBFT			= $(LIBFT_DIR)libft.a
LIBFT_DIR		= ./libft/
LIBFT_HDR		= $(LIBFT_DIR)libft.h

HDR_LIST		= push_swap_common.h push_swap.h checker_bonus.h
HDR_DIR			= ./includes/
HDR				= $(addprefix $(HDR_DIR), $(HDR_LIST))

SRCS_DIR		= ./srcs/
SRCS_DIR_COMMON = $(SRCS_DIR)/common/
SRCS_DIR_PUSH_SWAP = $(SRCS_DIR)/push_swap/
SRCS_DIR_CHECKER = $(SRCS_DIR)/checker/

SRCS_COMMON    = create_empty_stack.c do_command.c exit_with_error.c ft_strtol.c is_sorted.c is_valid_arg.c parse_input.c push_swap_utils.c
SRCS_PUSH_SWAP = do_push.c do_reverse_rotate.c do_rotate.c do_swap.c is_reverse_sorted.c partition_a.c partition_b.c sort.c sort_small.c push_swap.c
SRCS_CHECKER  = checker_bonus.c checker_gnl_bonus.c do_push_bonus.c do_swap_bonus.c do_rotate_bonus.c do_reverse_rotate_bonus.c

OBJS_COMMON    = $(addprefix $(SRCS_DIR_COMMON), $(SRCS_COMMON:.c=.o))
OBJS_PUSH_SWAP = $(OBJS_COMMON) $(addprefix $(SRCS_DIR_PUSH_SWAP), $(SRCS_PUSH_SWAP:.c=.o))
OBJS_CHECKER   = $(OBJS_COMMON) $(addprefix $(SRCS_DIR_CHECKER), $(SRCS_CHECKER:.c=.o))

$(NAME): $(OBJS_PUSH_SWAP) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBRARY)

$(BONUS_NAME): $(OBJS_CHECKER) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBRARY)

$(LIBFT):
	make -C $(LIBFT_DIR)

all: $(NAME)

bonus: $(BONUS_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS_PUSH_SWAP) $(OBJS_CHECKER)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(BONUS_NAME) $(LIBFT)
	make -C $(LIBFT_DIR) fclean

re: fclean all

test: $(NAME) clean
	./$(NAME) 85 42 97 83 51 43 48 7 21 6 27 57 74 79 67 16 23 73 68 95 59 44 45 9 91 15 93 47 37 29 33 90 86 1 28 58 69 61 77 24 71 18 4 14 40 84 41 82 56 10 50 36 22 8 81 78 64 3 52 53 88 30 75 49 46 76 32 2 99 0 70 92 39 25 89 80 94 17 54 60 31 26 87 72 38 35 12 62 66 55 63 20 96 13 19 11 65 98 5 34

test2: $(NAME) $(BONUS_NAME) clean
	./$(NAME) 85 42 97 83 51 43 48 7 21 6 27 57 74 79 67 16 23 73 68 95 59 44 45 9 91 15 93 47 37 29 33 90 86 1 28 58 69 61 77 24 71 18 4 14 40 84 41 82 56 10 50 36 22 8 81 78 64 3 52 53 88 30 75 49 46 76 32 2 99 0 70 92 39 25 89 80 94 17 54 60 31 26 87 72 38 35 12 62 66 55 63 20 96 13 19 11 65 98 5 34 | ./$(BONUS_NAME) 85 42 97 83 51 43 48 7 21 6 27 57 74 79 67 16 23 73 68 95 59 44 45 9 91 15 93 47 37 29 33 90 86 1 28 58 69 61 77 24 71 18 4 14 40 84 41 82 56 10 50 36 22 8 81 78 64 3 52 53 88 30 75 49 46 76 32 2 99 0 70 92 39 25 89 80 94 17 54 60 31 26 87 72 38 35 12 62 66 55 63 20 96 13 19 11 65 98 5 34


.PHONY: all clean fclean re test test2 bonus

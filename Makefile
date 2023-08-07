NAME			= push_swap
BONUS_NAME		= checker_bonus

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
	rm -f $(OBJS_PUSH_SWAP) $(OBJS_CHECKER) $(TMP_FILE)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(BONUS_NAME) $(LIBFT)
	make -C $(LIBFT_DIR) fclean

test: $(NAME)
	./$(NAME) 82 38 84 91 41 30 48 57 25 19 43 66 33 64 52 28 63 61 90 59 35 10 8 87 11 21 29 88 42 47 74 6 79 98 76 72 71 26 54 78 2 32 20 34 16 77 44 9 3 51 73 4 85 97 49 31 12 5 55 0 36 81 23 14 89 60 94 17 99 40 83 13 1 92 69 68 7 39 58 70 93 86 96 45 37 80 53 95 75 62 67 50 56 27 65 46 22 24 15 18

re: fclean all

.PHONY: all clean fclean re bonus

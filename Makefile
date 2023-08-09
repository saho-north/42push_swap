NAME       = push_swap
BONUS_NAME = checker_bonus

CC         = cc
CFLAGS     = -Wall -Wextra -Werror
LIBRARY    = -L$(LIBFT_DIR) -lft
INCLUDE    = -I$(HDR_DIR) -I$(LIBFT_HDR)

LIBFT      = $(LIBFT_DIR)libft.a
LIBFT_DIR  = ./libft/
LIBFT_HDR  = $(LIBFT_DIR)libft.h

HDR_LIST   = push_swap_common.h push_swap.h checker_bonus.h
HDR_DIR    = ./includes/
HDR        = $(addprefix $(HDR_DIR), $(HDR_LIST))

SRCS_DIR           = ./srcs/
SRCS_DIR_COMMON    = $(SRCS_DIR)/common/
SRCS_DIR_PUSH_SWAP = $(SRCS_DIR)/push_swap/
SRCS_DIR_CHECKER   = $(SRCS_DIR)/checker/

SRCS_COMMON    = create_empty_stack.c do_command.c exit_with_error.c ft_strtol.c is_sorted.c is_valid_arg.c parse_input.c push_swap_utils.c
SRCS_PUSH_SWAP = compaction.c do_push.c do_reverse_rotate.c do_rotate.c do_swap.c is_reverse_sorted.c partition_a.c partition_b.c sort.c sort_small.c push_swap.c
SRCS_CHECKER   = checker_bonus.c checker_gnl_bonus.c do_push_bonus.c do_swap_bonus.c do_rotate_bonus.c do_reverse_rotate_bonus.c

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

re: fclean all

.PHONY: all bonus clean fclean re

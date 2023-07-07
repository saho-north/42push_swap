CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I.
DEBUG		= -fsanitize=address -g
NAME		= push_swap
SRCS		= *.c
OBJS 		= $(SRCS:.c=.o)
INCS		= push_swap.h
BONUS_SRCS	= push_swap_bonus.c \
			  push_swap_utils_bonus.c \
			  main.c
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)
BONUS_INCS	= push_swap_bonus.h

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(BONUS_OBJS)
	$(CC) $(CFLAGS) $^ -o $@

test:
	cc *.c -o push_swap
	./push_swap 2 1 3 6 5 8 7 4
	#./push_swap 0 one 2 3
	./push_swap 0 1 2 3 4 5 6 7 8 9
	./push_swap 0 1 2 3 4 5 6 7 8 9 10

test_bonus: $(BONUS_OBJS)
	$(CC) $(CFLAGS)  $^ -o a.out
	./a.out

.PHONY: all clean fclean re bonus test

CC       = cc
CFLAGS   = -Wall -Wextra -Werror -I.
DEBUG    = -fsanitize=address -g
NAME     = push_swap
SRCS     = $(wildcard *.c)
OBJS     = $(SRCS:.c=.o)
INCS     = push_swap.h

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

all: $(NAME)

%.o: %.c $(INCS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

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

.PHONY: all clean fclean re test error0 error1 error2 error3 error4 error5

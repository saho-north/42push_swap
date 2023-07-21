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
	./$(NAME) 93 66 95 74 69 22 77 52 37 76 3 58 80 83 49 96 64 18 17 33 84 35 98 19 89 23 4 13 81 67 27 34 65 55 60 85 48 94 44 92 86 61 87 38 10 36 30 63 90 97 24 42 73 5 91 29 39 56 75 40 51 20 45 32 72 47 50 0 71 7 88 99 79 31 2 41 54 70 1 57 21 15 12 62 53 78 59 8 28 6 9 43 26 68 16 25 46 11 14 82

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

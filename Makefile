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
	./$(NAME) 2 1 3 6 5 8 7 4
	./$(NAME) 0 1 2 3 4 5 6 7 8 9
	./$(NAME) 1 5 2 4 3
	./$(NAME) "6 3 1 5 2 4"
	./$(NAME) 1 2 3 4 5
	./$(NAME) "1 2 3 4 5"
	./$(NAME) "-1 -2 -3 -4 -5"
	./$(NAME) "1 2 3" 4 5
	./$(NAME) "1 2" "3 4" "5"
	./$(NAME) 1 3 5 +9 20 -4 50 60 04 08

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

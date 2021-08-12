.PHONY : all clean fclean norme re

NAME = philo

CC = gcc

CFLAGS = -g -Wall -Wextra -Werror

HEAD = include

SRCS = $(addprefix srcs/, main.c status.c time.c utils.c)

OBJC = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJC) $(HEAD)
	$(CC) $(OBJC) -o $(NAME) -lpthread $(CFLAGS) -I $(HEAD)

%.o: %.c $(HEAD)/*.h Makefile
	$(CC) -c $< -o $@ $(CFLAGS) -I $(HEAD)

clean:
	rm -f $(OBJC)

fclean: clean
	rm -f $(NAME)

norme:
	norminette $(SRCS) $(HEAD)

re: fclean all
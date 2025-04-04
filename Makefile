##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## makefile
##

NAME	= palindrome

CC	= gcc

CFLAGS = -g

RM	= rm -f

SRCS	=	palindrome.c		\

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C src/lib/
	gcc -o $(NAME) $(OBJS) -L./src/lib/ -lmy $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	make fclean -C src/lib

re: fclean all

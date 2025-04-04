##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## lib's makefile
##


SRC 	=	my_putchar.c	\
	        my_putstr.c 	\
	        my_strcmp.c 	\
                my_strlen.c     \

OBJ	= 	$(SRC:.c=.o)

NAME 	=	libmy.a

all: 	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re:     fclean all

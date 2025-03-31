##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## lib's makefile
##


SRC 	=	my_putchar.c	\
		my_put_nbr.c 	\
		my_putstr.c 	\
		my_atoi.c		\
		my_getnbr.c 	\
		my_strcmp.c 	\
		my_str_to_word_array.c	\
		my_isalnum.c 	\
		my_strcat.c 	\
		my_strlen.c 	\
		my_strcspn.c	\
		my_strcpy.c 	\
		free_array.c 	\

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

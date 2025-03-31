##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## minishell1 makefile
##


NAME	= mysh

CC	= gcc

CFLAGS = -g

RM	= rm -f

SRCS	=	src/mini_shell1.c	\
			src/cd_command.c 	\
			src/execute_command.c 		\
			src/env_commands.c 			\
			src/bin_commands.c	\
			src/my_getenv.c 	\
			src/my_getenv_int.c 	\

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

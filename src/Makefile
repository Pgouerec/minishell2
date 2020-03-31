##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## my super duper makefile
##

SRC		=		main.c								\
				global/read_cmd.c					\
				shell/printsh.c						\
				global/exec.c						\
				global/args.c						\
				global/detect_cmd.c					\
				global/file_exist.c					\
				global/count_double_array.c			\
				exit/exit.c							\
				signal/signal_handler.c				\
				change_directory/cd.c				\
				env/read_env.c						\
				env/edit_env.c						\
				env/get_env.c						\
				env/read_path.c						\
				env/set_env.c						\
				env/unset_env.c						\
				env/print_env.c						\
				global/my_arrlen.c

OBJ		=		$(SRC:.c=.o)

NAME	=		mysh

CFLAGS	=		-L../lib/my/ -lmy -I../include

all:			$(NAME)

$(NAME):		$(OBJ)
		make -C ../lib/my
		gcc -o $(NAME) $(OBJ) $(CFLAGS)
		make -C . clean

clean:
		make -C ../lib/my clean
		rm -f $(OBJ)

fclean:	clean
		make -C ../lib/my fclean
		rm -f $(NAME)

re:		fclean all
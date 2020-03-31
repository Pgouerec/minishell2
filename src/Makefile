##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## my super duper makefile
##

SRC		=		main.c								\

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
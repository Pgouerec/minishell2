##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## my super duper makefile
##

all:
		make -C ./lib/my
		make -C src/
		cp src/mysh .

clean:
		make -C ./lib/my clean
		make -C src/ clean
		rm -f $(OBJ)

fclean:	clean
		make -C ./lib/my fclean
		make -C src/ fclean
		rm -f $(NAME)

re:		fclean all
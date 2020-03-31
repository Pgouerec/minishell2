##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## my super duper makefile
##

CFLAGS	=		-L./lib/my/ -lmy -I./include

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

TEST    =       tests/standard_test.c

tests_run: re
				rm -f *.gcda
				rm -f *.gcno
				gcc -o unit_tests $(TEST) $(CFLAGS) --coverage -lcriterion
				-./unit_tests

cover: re tests_run
				gcovr --exclude ./tests/